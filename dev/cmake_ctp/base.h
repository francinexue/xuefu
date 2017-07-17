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
    // 放弃GIL锁，允许python的其他线程执行
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
    // 在某个函数方法中创建和修改python对象时，获取GIL锁
    inline WithdrawGIL() {
        state = PyGILState_Ensure();
    }

    inline ~WithdrawGIL() {
        PyGILState_Release(state);
    }
private:
    PyGILState_STATE state;
};

//任务结构体
class Task {
public:
    Task():payload(boost::any()), resp(boost::any()) {}
    int name; //回调函数名称对应的常量
    boost::any payload; //数据结构体
    boost::any resp; //响应／错误结构体
    int num;    //请求id或数字参数
    bool final; //是否是最后返回
};

// 线程安全的队列
template<typename Data>
class ConcurrentQueue {
private:
    std::queue<Data> _queue;
    mutable boost::mutex _mutex;
    boost::condition_variable _condition_variable;

public:
    // 存入新的任务
    void push(Data const &data) {
        boost::mutex::scoped_lock lock(_mutex);
        _queue.push(data);
        lock.unlock();
        _condition_variable.notify_one();
    }

    //检查队列是否为空
    bool empty() const {
        boost::mutex::scoped_lock lock(_mutex);
        return _queue.empty();
    }

    //取出
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
