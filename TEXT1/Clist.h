#pragma once
#include "stdafx.h"
template <typename T>
class Clist
{
public:
	int insert(size_t x, const T &tdata);      //���뺯��
	int erase(size_t x);                       //ɾ�������ڵ�
	int modify(size_t x, const T &tdata);      //�޸�ĳ���ڵ�
	T&  getValue(size_t x);                    //��ȡĳ���ڵ��ֵ
	void clear();                              //�������Ԫ��
	void reverse();                            //��������
	void print();                              //��ӡ����
	size_t size();                             //����������

	Clist();                                   //Ĭ�ϳ�ʼ��
	Clist(const T &data);                      //���γ�ʼ��
	~Clist();                                  //��������

private:
	//������Ԫ��
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
	//������
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
			//��++�������ƶ�֮ǰ�ĵ���������
			iterator itTmp = *this; //����ƫ��ǰ�Ķ���
			pIndex = pIndex->pNext;   //����
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
	NODE * pHode = new NODE(tdata);   //����һ���ڵ�
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
	if (x >= iSize)return -1;
	//ɾ������һ���ڵ�
	NODE * pTmpHed = pHead;
	//��ɾ���ڵ�
	NODE * pTmpDel;
	if (x == 0)
	{
		pHead = pHead->pNext;
		//ɾ���ڵ�
		delete pTmpHed;
	}
	else
	{
		for (size_t i = 1; i < x; i++)
		{
			pTmpHed = pTmpHed->pNext;
		}
		//��ȡɾ���ڵ��λ��
		pTmpDel = pTmpHed->pNext;
		//�ѵ�ǰ�ڵ����һ���ڵ�ָ�����¸��ڵ㸳ֵ
		if (x != iSize - 1)
			pTmpHed->pNext = pTmpDel->pNext;
		else
			pTmpHed->pNext = NULL;
		//ɾ���ڵ�
		delete pTmpDel;
	}
	//������һ
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
	// TODO: �ڴ˴����� return ���
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
	//�жϵ�ǰ�ڵ�ָ�����һ���ڵ��Ƿ�Ϊ�գ�Ϊ�������
	while (PTmp)
	{
		//ת��ǰ��������һ���ڵ�
		pTmpEnd = PTmp->pNext;
		//ָ�뷭ת
		PTmp->pNext = pTmpHead;
		//��һ���ڵ���ƣ���Ϊָ�뷽��ı䣬��˲�����->��ֻ��������ǰ�ҵ�����һ�ڵ㣬����λ��
		pTmpHead = PTmp;
		//��ǰָ�����
		PTmp = pTmpEnd;

	}
	//��ԭͷ�ڵ�ָ��NULL����ĩβ�ڵ�
	pHead->pNext = NULL;
	//��ֵ�µ�ͷ�ڵ�
	pHead = pTmpHead;
}

template<typename T>
void Clist<T>::print()
{
	NODE * pTmpHed = pHead;
	for (size_t i = 0; i < iSize; i++)
	{
		std::cout << "��" << i << "����" << pTmpHed->data << std::endl;
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
