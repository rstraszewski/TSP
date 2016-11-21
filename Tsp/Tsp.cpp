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
	auto gl = new Graph();

	gl->Load();
	auto problem = new TspProblem(gl);
	start();
	auto result = problem->Solve();
	getTime();
	cout << problem->Cost << endl;
	
	auto agl = new aGraph();
	agl->Load();
	
	auto aproblem = new aTspProblem(agl);
	start();
	auto aresult = aproblem->Solve();
	getTime();
	cout << aproblem->Cost << endl;
	char c;
	cin >> c;


	return 0;
}

