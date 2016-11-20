#include "stdafx.h"
#include "Graph.h"


Graph::Graph()
{
	file.open("TSPLIB95/tsp/a280.tsp");
	if (!file.good())
		throw new exception("File not found");
}

void Graph::Load()
{
	string temp;
	
	while(true)
	{
		getline(file, temp, ':');

		
		if(temp.find("NAME") != string::npos)
		{
			getline(file, Name);
		}
		if(temp.find("TYPE") != string::npos)
		{
			getline(file, Type);
		}
		if(temp.find("COMMENT") != string::npos)
		{
			getline(file, Comment);
		}
		if(temp.find("DIMENSION") != string::npos)
		{
			file >> Dimension;
		}
		if(temp.find("EDGE_WEIGHT_TYPE") != string::npos)
		{
			getline(file, EdgeWeightType);
			getline(file, temp);
			break;
		}
	}

	for(auto i = 0; i < Dimension; i++)
	{
		int rowNumber;
		float x;
		float y;

		file >> rowNumber >> x >> y;

		GraphX.push_back(x);
		GraphY.push_back(y);
	}
}

void split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss;
	ss.str(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
}


Graph::~Graph()
{
	file.close();
}
