// TEXT1.cpp : �������̨Ӧ�ó������ڵ㡣
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
	cout << "Clist���룺" << endl;
	for (int i = 0; i < 10; i++)
		clist.insert(i, i * 100);
	clist.print();

	cout << "Clist������"<< clist.size() << endl;

	cout << "Clist����" << endl;
	clist.reverse();
	clist.print();

	cout << "Clistɾ����" << endl;
	clist.erase(9);
	clist.print();

	cout << "Clist�滻��" << endl;
	clist.modify(2,1000);
	clist.print();

	cout << "Clistȡֵ��" << endl;
	cout << clist.getValue(2) << endl;

	cout << "Clist������" << endl;
	Clist<int>::iterator Clistit;
	for (Clistit = clist.begin(); Clistit != clist.end(); Clistit++)
	{
		cout << *Clistit << endl;
	}

	cout << "Clist��գ�" << endl;
	clist.clear();
	clist.print();

	system("pause");
//	system("ping 127.0.0.1");
	//ASS<int> a;
	//Compare<int> a(1, 3);
	//Compare<int> v;
	return 0;
}




