#pragma once
#include "Par.h"
template <class T>
class Lista7
{
private:
	Par<T>* primer;
	Par<T>* ultimo;
public:
	Lista7();
	~Lista7();
	void eliminarTodo();
	Par<T>* getPrimer();
	Par<T>* getUltimo();
	void setPrimer(Par<T>* primer);
	void setUltimo(Par<T>* ultimo);
	void insertarPrincipio(T elemento);
	bool eliminarPrincipio();
	void insertarFinal(T elemento);
	bool eliminarFinal();
	void mostrarLista();
	bool buscarNoRec(T elementoBuscar);
	T buscarPos(int posBuscar);
	bool eliminarElementoDado(T elemento);
	T sacarSiguienteAdyacente(T iesimo);
	bool estaVacio();
};
template <class T>
Lista7<T>::Lista7()
{
	primer = NULL;
	ultimo = NULL;
}

template <class T>
Lista7<T>::~Lista7()
{
}

template <class T>
Par<T>* Lista7<T>::getPrimer()
{
	return primer;
}

template <class T>
Par<T>* Lista7<T>::getUltimo()
{
	return ultimo;
}

template <class T>
void Lista7<T>::setPrimer(Par<T>* primer)
{
	this->primer = primer;
}

template <class T>
void Lista7<T>::setUltimo(Par<T>* ultimo)
{
	this->ultimo = ultimo;
}



template <class T>
void Lista7<T>::insertarPrincipio(T elemento)
{
	if (primer == NULL)
	{
		primer = new Par<T>(NULL, elemento);
		ultimo = primer;
	}
	else
	{
		Par<T>* aux = new Par<T>(primer, elemento);
		primer = aux;
	}
}

template <class T>
bool Lista7<T>::eliminarPrincipio()
{
	bool res;
	if (primer == NULL)
	{
		res = false;
	}
	else
	{
		res = true;
		if (primer == ultimo) //Solo uno
		{
			delete primer;
			primer = NULL;
			ultimo = NULL;
		}
		else
		{
			Par<T>* aux;
			aux = primer->getSig();
			delete primer;
			primer = aux;
		}
	}
	return res;
}

template <class T>
void Lista7<T>::insertarFinal(T elemento)
{
	if (ultimo == NULL)
	{
		primer = new Par<T>(NULL, elemento);
		ultimo = primer;
	}
	else
	{
		Par<T>* aux = new Par<T>(NULL, elemento);
		ultimo->setSig(aux);
		ultimo = aux;
	}
}

template <class T>
bool Lista7<T>::eliminarFinal()
{
	bool res;
	if (primer == NULL)
	{
		res = false;
	}
	else
	{
		res = true;
		if (primer == ultimo) //Solo uno
		{
			delete primer;
			primer = NULL;
			ultimo = NULL;
		}
		else
		{
			Par<T>* aux = primer;
			while (aux->getSig()->getSig() != NULL)
			{
				aux = aux->getSig();
			}
			delete ultimo;
			ultimo = aux;
			ultimo->setSig(NULL);
		}
	}
	return res;
}

template <class T>
void Lista7<T>::mostrarLista()
{
	if (primer == NULL)
	{
		cout << "Lista Vacia" << endl;
	}
	else
	{
		Par<T>* aux = primer;
		while (aux != NULL)
		{
			cout << aux->getElem();
			if (aux->getSig() != NULL)
			{
				cout << " | ";
			}
			aux = aux->getSig();
		}
		cout << endl;
	}
}

template <class T>
bool Lista7<T>::buscarNoRec(T elementoBuscar)
{
	bool encontro;
	if (primer == NULL)
	{
		encontro = false;
	}
	else
	{
		Par<T>* aux = primer;
		while (aux != NULL)
		{
			if (elementoBuscar == aux->getElem())
			{
				encontro = true;
				return encontro;
			}
			else
			{
				encontro = false;
			}
			aux = aux->getSig();
		}
	}
	return encontro;
}
template <class T>
void Lista7<T>::eliminarTodo()
{
	while (primer != NULL)
	{
		eliminarPrincipio();
	}
}
template <class T>
T Lista7<T>::buscarPos(int posBuscar)
{
	T encontro;
	int pos = 1;
	if (primer == NULL)
	{
		cout << "No hay" << endl;
	}
	else
	{
		Par<T>* aux = primer;
		while (aux != NULL)
		{
			if (posBuscar == pos)
			{
				encontro = aux->getElem();
			}
			aux = aux->getSig();
			pos++;
		}
	}
	return encontro;
}

template <class T>
bool Lista7<T>::eliminarElementoDado(T elemento)
{
	bool funciono = false;
	if (primer == NULL)
	{
		funciono = false;
	}
	else
	{
		if (primer->getElem() == elemento)
		{
			funciono = eliminarPrincipio();
		}
		else if (ultimo->getElem() == elemento)
		{
			funciono = eliminarFinal();
		}
		else
		{
			Par<T>* aux = primer;
			while (aux->getSig()->getElem() != elemento && aux->getSig() != ultimo)
			{
				aux = aux->getSig();
			}
			if (aux->getSig() == ultimo && aux->getSig()->getElem() == elemento)
			{
				delete aux->getSig();
				ultimo = aux;
				ultimo->setElem(NULL);
				funciono = true;
			}
			else
			{
				if (aux->getSig()->getElem() == elemento)
				{
					Par<T>* ayuda = aux->getSig()->getSig();
					delete aux->getSig();
					aux->setSig(ayuda);
					funciono = true;
				}
			}
		}
	}
	return funciono;
}
template<class T>
T Lista7<T>::sacarSiguienteAdyacente(T iesimo)
{
	bool bandera = false;
	int indice = 1;
	T elemento;
	Par<T>* aux;
	aux = primer;

	while (aux != NULL)
	{
		if (indice == iesimo)
		{
			elemento = aux->getElem();
			bandera = true;
			aux = NULL;
		}
		else
		{
			indice++;
			aux = aux->getSig();
		}
	}
	if (bandera == false)
	{
		elemento = NULL;
	}
	return elemento;
}
template<class T>
bool Lista7<T>::estaVacio()
{
	bool res;
	if (primer == NULL && ultimo == NULL)
	{
		res = true;
	}
	else
	{
		res = false;
	}
	return res;
}