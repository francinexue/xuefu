//
// Created by kyle on 17-5-18.
//

#ifndef PYCTP_BASE_H
#define PYCTP_BASE_H

#include <boost/python.hpp>
#include <boost/any.hpp>
#include <boost/thread.hpp>
#include <queue>

class DepositGIL {
public:
    inline DepositGIL() {
        state = PyEval_SaveThread();
    }

    inline ~DepositGIL() {
        PyEval_RestoreThread(state);
    }
private:
    PyThreadState *state;
};

class WithdrawGIL {
public:
    inline WithdrawGIL() {
        state = PyGILState_Ensure();
    }

    inline ~WithdrawGIL() {
        PyGILState_Release(state);
    }
private:
    PyGILState_STATE state;
};

class Task {
public:
    Task():payload(boost::any()), resp(boost::any()) {}
    int name; 
    boost::any payload; 
    boost::any resp; 
    int num;    
    bool final; 
};


template<typename Data>
class ConcurrentQueue {
private:
    std::queue<Data> _queue;
    mutable boost::mutex _mutex;
    boost::condition_variable _condition_variable;

public:
    
    void push(Data const &data) {
        boost::mutex::scoped_lock lock(_mutex);
        _queue.push(data);
        lock.unlock();
        _condition_variable.notify_one();
    }

   
    bool empty() const {
        boost::mutex::scoped_lock lock(_mutex);
        return _queue.empty();
    }

    
    Data wait_and_pop() {
        boost::mutex::scoped_lock lock(_mutex);
        while (_queue.empty()) {
            _condition_variable.wait(lock);
        }
        Data value = _queue.front();
        _queue.pop();
        return value;
    }
};

#endif //PYCTP_BASE_H
