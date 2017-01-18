#pragma once
#include "stdafx.h"
template <typename T>
class Clist
{
public:
	int insert(size_t x, const T &tdata);      //插入函数
	int erase(size_t x);                       //删除单个节点
	int modify(size_t x, const T &tdata);      //修改某个节点
	T&  getValue(size_t x);                    //获取某个节点的值
	void clear();                              //清空所有元素
	void reverse();                            //链表逆序
	void print();                              //打印链表
	size_t size();                             //返回链表长度

	Clist();                                   //默认初始化
	Clist(const T &data);                      //带参初始化
	~Clist();                                  //析构链表

private:
	//链表单个元素
	class NODE
	{
	public:
		T data;
		NODE * pNext;

		NODE(const T &tdata);
		~NODE();
	};

	NODE * pHead;
	size_t iSize;

public:
	//迭代器
	class iterator
	{
	public:
		friend class Clist;
		iterator();
		~iterator();

		iterator operator++();
		bool operator==(iterator& obj);
		bool operator!=(iterator& obj);

		T& operator*();
		iterator operator++(int)
		{
			//后++，返回移动之前的迭代器对象
			iterator itTmp = *this; //保存偏移前的对象
			pIndex = pIndex->pNext;   //后移
			return itTmp;
		}
	private:
		iterator(NODE * ptmp);
		NODE * pIndex;
	};

	iterator begin() { return iterator(pHead); };
	iterator end() { return iterator(NULL); }
};

template<typename T>
inline Clist<T>::NODE::NODE(const T & tdata)
	:pNext(NULL),data(tdata)
{
}


template<typename T>
inline Clist<T>::NODE::~NODE()
{
//	delete pHead;
//	delete data;
}

template<typename T>
Clist<T>::iterator::iterator()
	:pIndex(NULL)
{
}

template<typename T>
Clist<T>::iterator::iterator(NODE * pTmp)
	: pIndex(pTmp)
{
}

template<typename T>
typename Clist<T>::iterator  Clist<T>::iterator::operator++()
{
	if(pIndex)
	   pIndex = pIndex->pNext;
	return *this;
}

template<typename T>
bool  Clist<T>::iterator::operator==(typename Clist<T>::iterator& obj)
{
	if (pIndex == obj.pIndex)
		return 1;
	else
		return 0;

}

template<typename T>
bool  Clist<T>::iterator::operator!=(typename Clist<T>::iterator& obj)
{
	if (pIndex != obj.pIndex)
		return 1;
	else
		return 0;

}
template<typename T>
T&  Clist<T>::iterator::operator*()
{
	return pIndex->data;
}

template<typename T>
Clist<T>::iterator::~iterator()
{
//	delete pIndex;
}

template<typename T>
int Clist<T>::insert(size_t x, const T &tdata)
{
	if (x > iSize)
	{
		return -1;
	}
	NODE * pHode = new NODE(tdata);   //创建一个节点
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
	if (x >= iSize)return -1;
	//删除的上一个节点
	NODE * pTmpHed = pHead;
	//待删除节点
	NODE * pTmpDel;
	if (x == 0)
	{
		pHead = pHead->pNext;
		//删除节点
		delete pTmpHed;
	}
	else
	{
		for (size_t i = 1; i < x; i++)
		{
			pTmpHed = pTmpHed->pNext;
		}
		//获取删除节点的位置
		pTmpDel = pTmpHed->pNext;
		//把当前节点的下一个节点指向下下个节点赋值
		if (x != iSize - 1)
			pTmpHed->pNext = pTmpDel->pNext;
		else
			pTmpHed->pNext = NULL;
		//删除节点
		delete pTmpDel;
	}
	//总数减一
	iSize--;
	return 0;
}

template<typename T>
int Clist<T>::modify(size_t x, const T & tdata)
{
	if (x >= iSize) return -1;

	NODE * pTmpHed = pHead;
	for (size_t i = 0; i < x; i++)
	{
		pTmpHed = pTmpHed->pNext;
	}
	pTmpHed->data = tdata;
	return 0;
}

template<typename T>
T & Clist<T>::getValue(size_t x)
{
	size_t i = 0;
	NODE * pTmpHed = pHead;
	while (i++ < x)
	{
		pTmpHed = pTmpHed->pNext;
	}
	return pTmpHed->data;
	// TODO: 在此处插入 return 语句
}

template<typename T>
void Clist<T>::clear()
{
	size_t i = 0;
	NODE * pTmpDed;
	while (i++ < iSize)
	{
		pTmpDed = pHead;
		pHead = pHead->pNext;
		delete pTmpDed;
	}
	iSize = 0;
	pHead = NULL;
}

template<typename T>
void Clist<T>::reverse()
{
	if (iSize < 2)
		return;
	NODE * pTmpHead = pHead;
	NODE * PTmp = pHead->pNext;
	NODE * pTmpEnd;
	//判断当前节点指向的下一个节点是否为空，为空则结束
	while (PTmp)
	{
		//转移前，保存下一个节点
		pTmpEnd = PTmp->pNext;
		//指针翻转
		PTmp->pNext = pTmpHead;
		//上一个节点后移，因为指针方向改变，因此不能用->，只能利用提前找到的下一节点，进行位移
		pTmpHead = PTmp;
		//当前指针后移
		PTmp = pTmpEnd;

	}
	//将原头节点指向NULL，即末尾节点
	pHead->pNext = NULL;
	//赋值新的头节点
	pHead = pTmpHead;
}

template<typename T>
void Clist<T>::print()
{
	NODE * pTmpHed = pHead;
	for (size_t i = 0; i < iSize; i++)
	{
		std::cout << "第" << i << "个：" << pTmpHed->data << std::endl;
		pTmpHed = pTmpHed->pNext;
	}

}

template<typename T>
size_t Clist<T>::size()
{
	return iSize;
}

template <typename T>
Clist<T>::Clist()
	:pHead(NULL), iSize(0)
{
}

template<typename T>
Clist<T>::Clist(const T & tdata)
{
	NODE *pHexd = new NODE(tdata);
	pHead = pHexd;
	iSize = 1;
}

template <typename T>
Clist<T>::~Clist()
{
	clear();
}
