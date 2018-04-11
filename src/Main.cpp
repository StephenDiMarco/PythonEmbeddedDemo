#include "PythonWrapper.hpp"

void reprint(PyObject *obj) {
    PyObject* repr = PyObject_Repr(obj);
    PyObject* str = PyUnicode_AsEncodedString(repr, "utf-8", "~E~");
    const char *bytes = PyBytes_AS_STRING(str);

    printf("%s\n", bytes);

    Py_XDECREF(repr);
    Py_XDECREF(str);
}

int main(int argc, char *argv[])
{
	setenv("PYTHONPATH", ".", 1);

    Py_Initialize();
    PythonWrapper pythonWrapper;	
    PyObject *pModule = pythonWrapper.import_python_module("channel_mapper");
	PyObject *pChannelMapper = pythonWrapper.instantiate_python_class("ChannelMapper", pModule, NULL);
   	PyObject *pArgs = PyTuple_Pack(1,PyUnicode_FromString("CBC"));
	PyObject *resource = pythonWrapper.call_method_on_object("get_channel_address_by_name", pChannelMapper, pArgs);
	reprint(resource);
    Py_Finalize();
	
    return 0;
}