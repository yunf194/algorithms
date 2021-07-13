#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include <iomanip> 
#include <exception>
#include <typeinfo>
#include <string.h>
using namespace std;
template <typename T>
class MAT {
	unique_ptr<T[]>e;							//ָ���������;���Ԫ�ص�ָ��
	const int row, column;							//�������r����c��С
public:
	MAT(int, int);						//������
	MAT(const MAT& a);				//�������
	MAT(MAT&& a)noexcept;			//�ƶ�����
	virtual ~MAT()noexcept;
	virtual T* const operator[ ](int r);//ȡ����r�еĵ�һ��Ԫ�ص�ַ��rԽ�����쳣
	virtual MAT operator+(const MAT& a)const;	//����ӷ������ܼ����쳣
	virtual MAT operator-(const MAT& a)const;	//������������ܼ����쳣
	virtual MAT operator*(const MAT& a)const;	//����˷������ܳ����쳣
	virtual MAT operator~()const;					//����ת��
	virtual MAT& operator=(const MAT& a);		//�����ֵ����
	virtual MAT& operator=(MAT&& a)noexcept;	//�ƶ���ֵ����
	virtual MAT& operator+=(const MAT& a);		//��+=������
	virtual MAT& operator-=(const MAT& a);		//��-=������
	virtual MAT& operator*=(const MAT& a);		//��*=������
//print�����s������s�����ÿո���������ûس�����
	virtual char* print(char* s)const noexcept;
};
template <typename T>
MAT<T>::MAT(int r, int c) :row(r), colum(c) {e(new T[r*c])};
template <typename T>
MAT<T>::MAT(const MAT& a) :row(a.row), column(a.column) {
	e(new T[a.row * a.colum]);
	for (int i = 0;i < a.column * a.row;i++)
		this->e[i] = a.e[i];
};
template <typename T>
MAT<T>::MAT(MAT&& a)
{

}