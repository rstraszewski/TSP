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
	//cout << "Operacja zajela: " << (li.QuadPart - licznik) / PCFreq << " milisekund" << endl;
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
	fstream file;
	file.open("test.txt");
	string names[8];
	double time[5] = { 0, 0, 0, 0, 0 };
	names[0] = "berlin52.tsp";
	names[1] = "pr76.tsp";
	names[2] = "eil101.tsp";
	names[3] = "pr152.tsp";
	names[4] = "a280.tsp";
	names[5] = "lin318.tsp";
	names[6] = "pr439.tsp";
	names[7] = "att532.tsp";
	double solves[5] = { 0.9, 0.95, 0.99, 0.995, 0.999 };
	for (int i = 0; i < 8; i++)
	{
		//symetryczny
		auto gl = new Graph(names[i]);
		gl->Load();
		auto problem = new TspProblem(gl);
		file << names[i] << endl;
		for (int j = 0; j < 5; j++)
		{
			start();
			auto result1 = problem->Solve(solves[0]);
			time[0] += getTime();
		
			start();
			auto result2 = problem->Solve(solves[1]);
			time[1] += getTime();

			start();
			auto result3 = problem->Solve(solves[2]);
			time[2] += getTime();

			start();
			auto result4 = problem->Solve(solves[3]);
			time[3] += getTime();

			start();
			auto result5 = problem->Solve(solves[4]);
			time[4] += getTime();
		}
	}
	system("pause");
	return 0;
}

