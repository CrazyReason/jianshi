#pragma once
#include "stdafx.h"
template <typename T>
class Clist
{
public:
	int insert(size_t x, T &tdata);             //���뺯��
	int erase(size_t x);                       //ɾ�������ڵ�
	int modify(size_t x, T &tdata);             //�޸�ĳ���ڵ�
	T&  getValue(size_t x);                    //��ȡĳ���ڵ��ֵ
	void clear();                              //�������Ԫ��
	void reverse();                            //��������
	void print();                              //��ӡ����
	size_t size();                             //����������

	Clist();                                   //Ĭ�ϳ�ʼ��
	Clist(T &data);                            //���γ�ʼ��
//	~Clist();                                  //��������

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