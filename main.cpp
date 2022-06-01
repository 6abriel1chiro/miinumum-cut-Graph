#include "graph.h"
int main()
{
	graph graph;
	string error;
	int min = 100000;
	int res;
	int total = 0;
	int opcion;
	do
	{
		system("cls");
		cout << "Menu" << endl;
		cout << "1 Insertar Archivo" << endl;
		cout << "2 Mostrar" << endl;
		cout << "3 Mincut" << endl;
		cout << "4 reset graph" << endl;
		cout << "5 Salir" << endl;
		cout << " Ingrese la opcion: ";
		cin >> opcion;
		system("cls");
		switch (opcion)
		{
		case 1:
			graph.leerArchivo("test.txt");
			break;
		case 2:
			graph.mostrar();
			break;
		case 3:
			try 
			{
				res = graph.minCut(graph.getgraph());
				if (res < min)
					min = res;
				cout << "cuts: " << min << endl;
			}
			catch (exception& e)
			{
				error = e.what();
				cout << "please run the program again" << endl;
			}
			break;
		case 4:
			graph.reiniciargraph("test.txt");
			break;
		}
		system("pause");
	} while (opcion != 5);
}
