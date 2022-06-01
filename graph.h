#pragma once
#include "Nodo.h"

class graph
{
private:
	map<string, Nodo<string> > G;
	int cortes;
public:
	graph();
	~graph();
	map<string, Nodo<string> >& getgraph();
	void leerArchivo(string nom);
	void mostrar();
	void reiniciargraph(string nom);
	void obtenerVertAleatorio(string& v1, string& v2);
	void contraer(string v1, string v2, map<string, Nodo<string> >& graphs);
	void eliminarAutociclos(map<string, Nodo<string> >& graphs);
	int minCut(map<string, Nodo<string> >& G);
};

graph::graph()
{
	cortes = 0;
}
graph::~graph()
{
}
map<string, Nodo<string> >& graph::getgraph()
{
	return G;
}
void graph::leerArchivo(string nom)
{
	ifstream arch;
	string v1, v2;
	int count = 0;
	arch.open(nom);
	while (!arch.eof())
	{
		arch >> v1;
		arch >> v2;
		count = 0;
		while (v1 != "-1" && v2 != "-1")
		{
			G[v1].getLista()->insertarFinal(v2);
			//G[v2].getLista()->insertarFinal(v1);
			arch >> v2;
			count++;
		}
		G[v1].setCont(count);
		//	G[v2].setCounter(count);
		cortes += 2;
	}
}
void graph::mostrar()
{
	cout << "size: " << G.size() << endl;
	map<string, Nodo<string> >::iterator it;
	for (it = G.begin(); it != G.end(); ++it)
	{
		cout << it->first << " -> " << " " << it->second.getCont();
		it->second.getLista()->mostrarLista();
	}
}
void graph::obtenerVertAleatorio(string& v1, string& v2)
{
	srand(time(NULL));
	int r1, r2, cont = 1;
	r1 = 1 + rand() % G.size();
	map<string, Nodo<string> >::iterator it;
	for (it = G.begin(); it != G.end(); ++it)
	{
		if (cont == r1)
			{
				v1 = it->first;
				r2 = 1 + rand() % it->second.getCont();
				v2 = it->second.getLista()->buscarPos(r2);
			}
			cont++;
	}
}
void graph::contraer(string v1, string v2, map<string, Nodo<string> >& graphs)
{
	G[v2].getLista()->eliminarElementoDado(v1);
	G[v1].getLista()->eliminarElementoDado(v2);
	G[v1].setCont(G[v1].getCont() - 1);
	G[v2].setCont(G[v2].getCont() - 1);
	cortes = cortes - 2;
	Par<string>* caminante = G[v2].getLista()->getPrimer();
	while (caminante != NULL)
	{
		G[v1].getLista()->insertarFinal(caminante->getElem());
		G[v1].setCont(G[v1].getCont() + 1);
		G[caminante->getElem()].getLista()->eliminarElementoDado(v2);
		G[v1].setCont(G[v1].getCont() - 1);
		G[caminante->getElem()].getLista()->insertarFinal(v1);
		G[v1].setCont(G[v1].getCont() + 1);
		caminante = caminante->getSig();
	}
	G.erase(v2);
	cortes--;
}
int graph::minCut(map<string, Nodo<string> >& G)
{
	int a = 0;
	string v1, v2;
	
	while (G.size() > 2)
	{
		obtenerVertAleatorio(v1, v2);
		contraer(v1, v2, G);
		eliminarAutociclos(G);
		a++;
	}
	return a;
}
void graph::eliminarAutociclos(map<string, Nodo<string> >& G)
{
	int tam = G.size();
	map<string, Nodo<string> >::iterator it;
	for (it=G.begin();it!=G.end();it++)
	{
		Par<string>* aux = G[it->first].getLista()->getPrimer();
		while (aux != NULL)
		{

			if (aux->getElem() == it->first)
			{
				Par<string>* next= aux->getSig();
				G[it->first].getLista()->eliminarElementoDado(aux->getElem());
				//G[it->first].setCont(G[aux->ge() - 1]);
				G[it->first].setCont(G[it->first].getCont() - 1);
				aux = next;
				cortes--;
			}
			else
				aux = aux->getSig();
		}
	}
}
void graph::reiniciargraph(string nom)
{
	map<string, Nodo<string> >::iterator it;
	for (it = G.begin(); it != G.end(); it++)
	{
		G[it->first].getLista()->eliminarTodo();
	}
	leerArchivo(nom);
}