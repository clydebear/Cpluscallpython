
#include "Python.h"
#include <iostream>
using namespace std;


int main()
{
	Py_Initialize();
	if (!Py_IsInitialized())
	{
		return -1;
	}

	PyObject *pModule = NULL;
	pModule = PyImport_ImportModule("hello");  //得到文件hello.py
	if (!pModule)
	{
		printf("not found .py file\n");
	}

	PyObject *pFunc = NULL;
	PyObject *pValue = NULL;

	pValue = PyObject_CallMethod(pModule, "add", "ii", 10, 20);   //通过上面得到的模块直接访问模块里面的函数add(a,b)
																  //注意这里的"ii"事实上相当于C中的"%d%d"的功能，请参考文档
	cout << PyLong_AsLong(pValue) << endl;            //将得到的pValue值转换为C中的long型

	pFunc = PyObject_GetAttrString(pModule, "add");  //也可以使用该函数得到函数对象
	pValue = PyObject_CallFunction(pFunc, "ii", 1, 2);    //通过函数对象执行函数
	cout << PyLong_AsLong(pValue) << endl;


	printf("success!\n");
	Py_Finalize(); /* 结束Python解释器，释放资源 */

	int i = 0;
	cin >> i;
	return 0;
}