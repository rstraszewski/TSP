#pragma once
#include "aGraph.h"
class aTspProblem
{
	aGraph* _graph;
	vector<int> CreateRandomPath();
	vector<int> CreateNeigbourSolution(vector<int> path);
	int CalculatePathCost(vector<int> path);
public:
	aTspProblem();
	~aTspProblem();
	int CalculateDistance(int firstCityIndex, int secondCityIndex);
	vector<int> Path;
	int Cost;
	aTspProblem(aGraph * graph);
	vector<int> Solve();
};

