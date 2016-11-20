// Tsp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Graph.h"
#include "TspProblem.h"

int main()
{
	auto gl = new Graph();

	gl->Load();

	auto problem = new TspProblem(gl);
	auto result = problem->Solve();

	cout << problem->Cost;

	char c;
	cin >> c;

	return 0;
}

