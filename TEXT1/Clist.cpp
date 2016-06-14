#include "stdafx.h"
#include "Clist.h"

template<typename T>
int Clist<T>::insert(size_t x, T &tdata)
{
	if (x > iSize)
	{
		return -1;
	}
	NODE * pHode = NODE(tdata);   //创建一个节点
	//头结点插入
	if (x == 0)
	{
		pHead = pHode;
		iSize = 1;
		return 0;
	}
	//不为头结点的时候，插入点后移
	size_t i = 0;
	//赋值查找节点
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
	// TODO: 在此处插入 return 语句
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
		std::cout << "第" << i << "个：" << pHead->data << std::endl;
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
