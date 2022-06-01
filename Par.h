#pragma once
#include <iostream>
using namespace std;
template <class T>
class Par
{
private:
	Par<T>* siguiente;
	T elemento;
public:
	Par(Par<T>* siguiente, T elemento);
	~Par();
	Par* getSig();
	T getElem();
	void setSig(Par<T>* siguiente);
	void setElem(T elemento);
};
template <class T>
Par<T>::Par(Par<T>* siguiente, T elemento)
{
	this->siguiente = siguiente;
	this->elemento = elemento;
}
template <class T>
Par<T>::~Par()
{
}
template <class T>
Par<T>* Par<T>::getSig()
{
	return siguiente;
}

template <class T>
T Par<T>::getElem()
{
	return elemento;
}

template <class T>
void Par<T>::setSig(Par<T>* siguiente)
{
	this->siguiente = siguiente;
}

template <class T>
void Par<T>::setElem(T elemento)
{
	this->elemento = elemento;
}
