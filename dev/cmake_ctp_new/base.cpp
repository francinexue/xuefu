//
// Created by kyle on 2017/12/2.
//
#include <boost/python.hpp>

using namespace boost::python;
boost::python::object greet() {
    char *agd = new char[7];
    agd[0] = '\xbb';
    agd[1] = '\xb6';
    agd[2] = '\xd3';
    agd[3] = '\xad';
    agd[4] = '\xc4';
    agd[5] = '\xfa';
    agd[6] = '\0';
#if PY_MAJOR_VERSION >= 3
    PyObject *bytes = PyBytes_FromString(agd);
    PyObject *str = PyUnicode_FromEncodedObject(bytes, "gbk", "strict");
    delete[] agd;
    return boost::python::object(boost::python::handle<>(unicode));
#else
    PyObject *str = PyString_FromString(agd);
    delete[] agd;
#endif
    return boost::python::object(boost::python::handle<>(str));
}

void setGreet(boost::python::str& str) {
#if PY_MAJOR_VERSION >= 3
    PyObject *bytes = PyUnicode_AsASCIIString(str.ptr());
    char *content = PyBytes_AsString(bytes);
    printf("%s", content);
//    delete []content; 这个是不可以删除的
#else
    char * content = PyString_AsString(str.ptr());
    printf("%s", content);
//    delete []content; 这个是不可以删除的
#endif
}


BOOST_PYTHON_MODULE(ctp)
{
//    if (!PyEval_ThreadsInitialized())
//        PyEval_InitThreads();	//导入时运行，保证先创建GIL
    def("greet", greet);
    def("setGreet", setGreet);
}