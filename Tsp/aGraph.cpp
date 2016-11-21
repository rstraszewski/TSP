#include "stdafx.h"
#include "aGraph.h"


aGraph::aGraph()
{
	file.open("TSPLIB95/atsp/br17.atsp");
	if (!file.good())
		throw new exception("File not found");
}

void aGraph::Load()
{
	string temp;

	while (true)
	{
		getline(file, temp, ':');


		if (temp.find("NAME") != string::npos)
		{
			getline(file, Name);
		}
		if (temp.find("TYPE") != string::npos)
		{
			getline(file, Type);
		}
		if (temp.find("COMMENT") != string::npos)
		{
			getline(file, Comment);
		}
		if (temp.find("DIMENSION") != string::npos)
		{
			file >> Dimension;
		}
		if (temp.find("EDGE_WEIGHT_TYPE") != string::npos)
		{
			getline(file, EdgeWeightType);
			getline(file, temp);
			getline(file, temp);
			break;
		}
	}

	for (auto i = 0; i < Dimension; i++)
	{
		for (auto j = 0; j < Dimension; j++)
		{
			int distance;
			file >> distance;
			Distances[i].push_back(j);
		}
	}
}

aGraph::~aGraph()
{
	file.close();
}
