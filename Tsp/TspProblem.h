#pragma once
#include "Graph.h"

class TspProblem
{
private:
	Graph* _graph;
	vector<int> CreateRandomPath();
	vector<int> CreateNeigbourSolution(vector<int> path);
	float CalculatePathCost(vector<int> path);
	
public:
	float CalculateDistance(int firstCityIndex, int secondCityIndex);
	vector<int> Path;
	float Cost;
	TspProblem(Graph * graph);
	vector<int> Solve();
	~TspProblem();
};

