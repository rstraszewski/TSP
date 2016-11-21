// Tsp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Graph.h"
#include "TspProblem.h"
#include "aGraph.h"
#include "aTspProblem.h"

double PCFreq = 0.0;
__int64 licznik = 0;


void start()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		cout << "Błąd!\n";

	PCFreq = double(li.QuadPart) / 1000.0;

	QueryPerformanceCounter(&li);
	licznik = li.QuadPart;
}
double getTime()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	cout << "Operacja zajela: " << (li.QuadPart - licznik) / PCFreq << " milisekund" << endl;
	return double((li.QuadPart - licznik) / PCFreq);
}

int main()
{
	//string s, t;
	//cout << "Podaj nazwe pliku.\n";
	//double a, b;
	//cin >> s;
	//auto gl = new Graph(s);
	//
	//
	//gl->Load();
	//auto problem = new TspProblem(gl);
	//cout << "Podaj wspolczynnik alfa.\n";
	//cin >> a;
	//start();
	//auto result = problem->Solve(a);
	//getTime();
	//cout <<"Koszt:" << problem->Cost << endl;
	//for (int i = 0; i < gl->Dimension; i++)
	//{
	//	cout << problem->Path.at(i) << "---";
	//}
	//cout << problem->Path.front();
	//cout << endl << endl;
	//cout << "Podaj nazwe pliku.\n";
	//cin >> t;
	//auto agl = new aGraph(t);
	//agl->Load();
	//
	//auto aproblem = new aTspProblem(agl);
	//cout << "Podaj wspolczynnik alfa.\n";
	//cin >> b;
	//start();
	//auto aresult = aproblem->Solve(b);
	//getTime();
	//cout << "Koszt:" << aproblem->Cost << endl;
	//for (int i = 0; i < agl->Dimension; i++)
	//{
	//	cout << aproblem->Path.at(i) << "---";
	//}
	//cout << aproblem->Path.front();
	//cout << endl << endl;
	//char c;
	//cin >> c;

	//do testow
	for (int i = 0; i < 5; i++)
	{
		//symetryczny
		auto gl = new Graph("TSPLIB95/tsp/burma14.tsp");
		gl->Load();
		auto problem = new TspProblem(gl);
		start();
		auto result1 = problem->Solve(0.9);
		getTime();
		start();
		auto result2 = problem->Solve(0.95);
		getTime();
		start();
		auto result3 = problem->Solve(0.99);
		getTime();
		start();
		auto result4 = problem->Solve(0.995);
		getTime();
		start();
		auto result5 = problem->Solve(0.999);
		getTime();
	}
	system("pause");
	return 0;
}

