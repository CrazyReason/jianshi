#pragma once
#include "stdafx.h"
template <typename T>
class Clist
{
public:
	int insert(size_t x, T &tdata);             //插入函数
	int erase(size_t x);                       //删除单个节点
	int modify(size_t x, T &tdata);             //修改某个节点
	T&  getValue(size_t x);                    //获取某个节点的值
	void clear();                              //清空所有元素
	void reverse();                            //链表逆序
	void print();                              //打印链表
	size_t size();                             //返回链表长度

	Clist();                                   //默认初始化
	Clist(T &data);                            //带参初始化
//	~Clist();                                  //析构链表

private:
	class NODE
	{
	public:
		T data;
		NODE * pNext;

		NODE(T &tdata);
		~NODE();
	};

	NODE * pHead;
	size_t iSize;
};

template<typename T>
inline Clist<T>::NODE::NODE(T & tdata)
	:pNext(NULL),data(tdata)
{
}


template<typename T>
inline Clist<T>::NODE::~NODE()
{
	delete pHead;
	delete data;
}



template <typename T>
Clist<T>::Clist()
	:pHead(NULL), iSize(0)
{
}

template<typename T>
Clist<T>::Clist(T & tdata)
{
	NODE *pHexd = new NODE(tdata);
	pHead = pHexd;
	iSize = 1;
}