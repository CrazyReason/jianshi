#include "stdafx.h"
#include "Init.h"


HDC hdc = NULL;							//2��DC
HDC dcTemp = NULL;						//3��DC
HBITMAP hBitmapBack = NULL;
HBITMAP hBitmapTaiYangHua = NULL;

void Init(HWND hWnd)
{
	hdc = CreateCompatibleDC(GetDC(hWnd));
	RECT rect;
	GetClientRect(hWnd, &rect);
	//��������
	HBITMAP hBitmapTem = CreateCompatibleBitmap(GetDC(hWnd), rect.right - rect.left, rect.bottom - rect.top);
	SelectObject(hdc, hBitmapTem);


	//���Ʊ���
	hBitmapBack = (HBITMAP)LoadImage(NULL, L"images/map.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	dcTemp = CreateCompatibleDC(hdc);
	SelectObject(dcTemp, hBitmapBack);
	BITMAP bitInfo;
	GetObject(hBitmapBack, sizeof(BITMAP), &bitInfo);
	BitBlt(hdc, 0, 0, bitInfo.bmWidth, bitInfo.bmHeight, dcTemp, 0, 0, SRCCOPY);

	//���ڴ�DC-��hDc�ϵ�����ȫһ���Ի��Ƶ�����DC
	BitBlt(GetDC(hWnd), 0, 0, rect.right - rect.left, rect.bottom - rect.top, hdc, 0, 0, SRCCOPY);

	DeleteObject(hBitmapTem);
}

void Game_HuiZhi(HWND hWnd)
{
	hBitmapTaiYangHua = (HBITMAP)LoadImage(NULL, L"images/flower.BMP", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

}

void Game_Once(HWND hWnd)
{
	DeleteObject(hdc);
	DeleteObject(dcTemp);
	DeleteObject(hBitmapBack);
}