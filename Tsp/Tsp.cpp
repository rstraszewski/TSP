// Tsp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Graph.h"
#include "TspProblem.h"
#include "aGraph.h"
#include "aTspProblem.h"

int main()
{
	auto gl = new Graph();

	gl->Load();
	auto problem = new TspProblem(gl);
	auto result = problem->Solve();

	cout << problem->Cost << endl;
	auto agl = new aGraph();
	agl->Load();
	auto aproblem = new aTspProblem(agl);
	auto aresult = aproblem->Solve();
	cout << aproblem->Cost << endl;
	char c;
	cin >> c;


	return 0;
}

