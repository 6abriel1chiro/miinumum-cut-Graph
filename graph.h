#pragma once
#include "Nodo.h"
#include <map>
#include <fstream>
#include<time.h>

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