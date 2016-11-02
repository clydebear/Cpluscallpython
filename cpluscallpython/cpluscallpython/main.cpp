
#include "Python.h"
#include <iostream>
using namespace std;

//int main()
//
//{
//
//	int nRet = -1;
//
//
//
//	PyObject* pName = NULL;
//
//	PyObject* pModule = NULL;
//
//	PyObject* pDict = NULL;
//
//	PyObject* pFunc = NULL;
//
//	PyObject* pArgs = NULL;
//
//	PyObject* pRet = NULL;
//
//	do
//
//	{
//
//		// 初始化Python
//
//		// 在使用Python系统前，必须使用Py_Initialize对其
//
//		// 进行初始化。它会载入Python的内建模块并添加系统路
//
//		// 径到模块搜索路径中。这个函数没有返回值，检查系统
//
//		// 是否初始化成功需要使用Py_IsInitialized。
//
//		Py_Initialize();
//
//
//
//		// 检查初始化是否成功
//
//		if (!Py_IsInitialized())
//
//		{
//
//			break;
//
//		}
//
//
//
//		// 添加当前路径
//
//		// 把输入的字符串作为Python代码直接运行，返回
//
//		// 表示成功，-1表示有错。大多时候错误都是因为字符串
//
//		// 中有语法错误。
//
//		PyRun_SimpleString("importsys");
//
//		PyRun_SimpleString("sys.path.append('./pyfile/')");
//
//
//
//		// 载入名为PyPlugin的脚本
//
//		pName = PyString_FromString("PyPlugin");
//
//		pModule = PyImport_Import(pName);
//
//		if (!pModule)
//
//		{
//
//			printf("can't findPyPlugin.py\n");
//
//			break;
//
//		}
//
//
//
//		pDict = PyModule_GetDict(pModule);
//
//		if (!pDict)
//
//		{
//
//			break;
//
//		}
//
//
//
//		// 找出函数名为AddMult的函数
//
//		pFunc = PyDict_GetItemString(pDict, "AddMult");
//
//		if (!pFunc || !PyCallable_Check(pFunc))
//
//		{
//
//			printf("can't findfunction [AddMult]\n");
//
//			break;
//
//		}
//
//
//
//		pArgs = Py_BuildValue("ii", 12, 14);
//
//		PyObject* pRet = PyEval_CallObject(pFunc, pArgs);
//
//		int a = 0;
//
//		int b = 0;
//
//		if (pRet && PyArg_ParseTuple(pRet, "ii", &a, &b))
//
//		{
//
//			printf("Function[AddMult] call successful a + b = %d, a * b = %d\n", a, b);
//
//			nRet = 0;
//
//		}
//
//
//
//		if (pArgs)
//
//			Py_DECREF(pArgs);
//
//		if (pFunc)
//
//			Py_DECREF(pFunc);
//
//		// 找出函数名为HelloWorld的函数
//
//		pFunc = PyDict_GetItemString(pDict, "HelloWorld");
//
//		if (!pFunc || !PyCallable_Check(pFunc))
//
//		{
//
//			printf("can't findfunction [HelloWorld]\n");
//
//			break;
//
//		}
//
//		pArgs = Py_BuildValue("(s)", "magictong");
//
//		PyEval_CallObject(pFunc, pArgs);
//
//	} while (0);
//
//
//
//	if (pRet)
//
//		Py_DECREF(pRet);
//
//	if (pArgs)
//
//		Py_DECREF(pArgs);
//
//	if (pFunc)
//
//		Py_DECREF(pFunc);
//
//	if (pDict)
//
//		Py_DECREF(pDict);
//
//	if (pModule)
//
//		Py_DECREF(pModule);
//
//	if (pName)
//
//		Py_DECREF(pName);
//
//	Py_Finalize();
//
//
//
//	return 0;
//
//}
int main()
{
	Py_Initialize();
	if (!Py_IsInitialized())
	{
		return -1;
	}
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("import os");
	PyRun_SimpleString("sys.path.append('./pyfile/')");
	PyRun_SimpleString("print sys.path");

	PyObject *pModule = NULL;
	pModule = PyImport_ImportModule("PyPligin");  //得到文件hello.py
	if (!pModule)
	{
		printf("not found .py file\n");
	}

	PyObject *pFunc = NULL;
	PyObject *pValue = NULL;

	//pValue = PyObject_CallMethod(pModule, "add", "ii", 10, 20);   //通过上面得到的模块直接访问模块里面的函数add(a,b)
	//															  //注意这里的"ii"事实上相当于C中的"%d%d"的功能，请参考文档
	//cout << PyLong_AsLong(pValue) << endl;            //将得到的pValue值转换为C中的long型


	pValue = PyObject_CallMethod(pModule, "update", "");
	cout << PyLong_AsLong(pValue) << endl;


	//pFunc = PyObject_GetAttrString(pModule, "add");  //也可以使用该函数得到函数对象
	//pValue = PyObject_CallFunction(pFunc, "ii", 1, 2);    //通过函数对象执行函数
	//cout << PyLong_AsLong(pValue) << endl;


	printf("success!\n");
	Py_Finalize(); /* 结束Python解释器，释放资源 */

	int i = 0;
	cin >> i;
	return 0;
}