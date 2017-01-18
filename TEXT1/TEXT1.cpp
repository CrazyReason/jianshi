// TEXT1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Clist.h"
#include <list>

int main()
{

	int a = 123456;
	Clist<int> clist;
	Clist<int> cist(a);
	cist.print();
	cout << "Clist插入：" << endl;
	for (int i = 0; i < 10; i++)
		clist.insert(i, i * 100);
	clist.print();

	cout << "Clist个数："<< clist.size() << endl;

	cout << "Clist逆序：" << endl;
	clist.reverse();
	clist.print();

	cout << "Clist删除：" << endl;
	clist.erase(9);
	clist.print();

	cout << "Clist替换：" << endl;
	clist.modify(2,1000);
	clist.print();

	cout << "Clist取值：" << endl;
	cout << clist.getValue(2) << endl;

	cout << "Clist遍历：" << endl;
	Clist<int>::iterator Clistit;
	for (Clistit = clist.begin(); Clistit != clist.end(); Clistit++)
	{
		cout << *Clistit << endl;
	}

	cout << "Clist清空：" << endl;
	clist.clear();
	clist.print();

	system("pause");
//	system("ping 127.0.0.1");
	//ASS<int> a;
	//Compare<int> a(1, 3);
	//Compare<int> v;
	return 0;
}




