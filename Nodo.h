#pragma once
#include "Lista7.h"
#include "stdc++.h"
template <class T>
class Nodo
{
private:
	Lista7<T>* lista;
	int cont;
public:
	Nodo();
	~Nodo();
	int getCont();
	Lista7<T>* getLista();
	void setLista(Lista7<string>* lista);
	void setCont(int cont);
};
template <class T>
Nodo<T>::Nodo()
{
	this->lista = new Lista7<T>();
	this->cont = 0;
}
template <class T>
Nodo<T>::~Nodo()
{
	delete lista;
}
template <class T>
Lista7<T>* Nodo<T>::getLista()
{
	return lista;
}
template <class T>
int Nodo<T>::getCont()
{
	return cont;
}
template <class T>
void Nodo<T>::setLista(Lista7<string>* lista)
{
	this->lista = lista;
}
template <class T>
void Nodo<T>::setCont(int cont)
{
	this->cont = cont;
}