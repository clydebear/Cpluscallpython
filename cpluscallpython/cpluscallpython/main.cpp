
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
	pModule = PyImport_ImportModule("hello");  //�õ��ļ�hello.py
	if (!pModule)
	{
		printf("not found .py file\n");
	}

	PyObject *pFunc = NULL;
	PyObject *pValue = NULL;

	pValue = PyObject_CallMethod(pModule, "add", "ii", 10, 20);   //ͨ������õ���ģ��ֱ�ӷ���ģ������ĺ���add(a,b)
																  //ע�������"ii"��ʵ���൱��C�е�"%d%d"�Ĺ��ܣ���ο��ĵ�
	cout << PyLong_AsLong(pValue) << endl;            //���õ���pValueֵת��ΪC�е�long��

	pFunc = PyObject_GetAttrString(pModule, "add");  //Ҳ����ʹ�øú����õ���������
	pValue = PyObject_CallFunction(pFunc, "ii", 1, 2);    //ͨ����������ִ�к���
	cout << PyLong_AsLong(pValue) << endl;


	printf("success!\n");
	Py_Finalize(); /* ����Python���������ͷ���Դ */

	int i = 0;
	cin >> i;
	return 0;
}