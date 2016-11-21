#include "stdafx.h"
#include "aTspProblem.h"


aTspProblem::aTspProblem(aGraph * graph)
{
	_graph = graph;
}

vector<int> aTspProblem::Solve(double a)
{
	const double EulerConstant = std::exp(1.0);

	Path = CreateRandomPath();
	Cost = CalculatePathCost(Path);

	double t = 100;
	double tMin = 0.00001;
	double alpha = a;

	while (t > tMin)
	{
		auto newPath = CreateNeigbourSolution(Path);
		auto newCost = CalculatePathCost(newPath);

		auto delta = Cost - newCost;
		auto acc = pow(EulerConstant, delta / t);
		auto p = (double)rand() / (double)RAND_MAX;

		if (p < acc)
		{
			Cost = newCost;
			Path = newPath;
		}

		t = alpha * t;
	}
	return Path;
}

int aTspProblem::CalculateDistance(int firstCityIndex, int secondCityIndex)
{
	int dist = _graph->Distances[firstCityIndex].at(secondCityIndex);
	//cout << firstCityX << " " << firstCityIndex<< " " << firstCityY << " " << firstCityIndex << " " << secondCityX << " " << secondCityIndex<< " " << secondCityY << " " << secondCityIndex << " \n";
	return dist;
}

int aTspProblem::CalculatePathCost(vector<int> path)
{
	int cost = 0;

	for (int i = 1; i < _graph->Dimension; ++i)
	{
		auto firstCity = path[i - 1];
		auto secondCity = path[i];
		//cout <<"koszt"<< cost << endl;
		cost += CalculateDistance(firstCity, secondCity);
	}
	//cout << "przed:" << cost << endl;
	cost += CalculateDistance(path.back(), path.front());
	//cout << "po" << cost << endl;
	return cost;
}

vector<int> aTspProblem::CreateRandomPath()
{
	vector<int> path;
	for (int i = 0; i < _graph->Dimension; ++i) path.push_back(i);

	random_shuffle(path.begin(), path.end());

	return path;
}

vector<int> aTspProblem::CreateNeigbourSolution(vector<int> path)
{
	vector<int> neigbourPath(path);

	int first = -1;
	int second = -1;

	while (first == second)
	{
		first = (rand() % (int)(_graph->Dimension));
		second = (rand() % (int)(_graph->Dimension));
	}

	iter_swap(neigbourPath.begin() + first, neigbourPath.begin() + second);

	return neigbourPath;
}

aTspProblem::~aTspProblem()
{

}
