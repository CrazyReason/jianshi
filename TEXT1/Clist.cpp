#include "stdafx.h"
#include "Clist.h"

template<typename T>
int Clist<T>::insert(size_t x, T &tdata)
{
	if (x > iSize)
	{
		return -1;
	}
	NODE * pHode = NODE(tdata);   //����һ���ڵ�
	//ͷ������
	if (x == 0)
	{
		pHead = pHode;
		iSize = 1;
		return 0;
	}
	//��Ϊͷ����ʱ�򣬲�������
	size_t i = 0;
	//��ֵ���ҽڵ�
	NODE * pTmpNote = pHead;
	while (++i < x)
	{
		pTmpNote = pTmpNote->pNext;
	}
	pHode->pNext = pTmpNote->pNext;
	pTmpNote->pNext = pHode;
	iSize++;
	return 0;
}

template<typename T>
int Clist<T>::erase(size_t x)
{
	return 0;
}

template<typename T>
int Clist<T>::modify(size_t x, T & tdata)
{
	return 0;
}

template<typename T>
T & Clist<T>::getValue(size_t x)
{
	// TODO: �ڴ˴����� return ���
}

template<typename T>
void Clist<T>::clear()
{
}

template<typename T>
void Clist<T>::reverse()
{
}

template<typename T>
void Clist<T>::print()
{
	size_t i = 0;
	for (; i < iSize; i++)
	{
		std::cout << "��" << i << "����" << pHead->data << std::endl;
	}

}

template<typename T>
size_t Clist<T>::size()
{
	return size_t();
}

//template <typename T>
//Clist<T>::Clist()
//	:pHead(NULL), iSize(0)
//{
//}
//
//template<typename T>
//Clist<T>::Clist(T & tdata)
//{
//	NODE *pHexd = new NODE(tdata);
//	pHead = pHexd;
//	iSize = 1;
//}

//template <typename T>
//Clist<T>::~Clist()
//{
//	clear();
//}
