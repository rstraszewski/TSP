#pragma once
class aGraph
{
private:
	ifstream file;
public:
	vector <vector < int > > Distances;
	
	string Name;
	string Type;
	string Comment;
	int Dimension;
	string EdgeWeightType;

	aGraph(string s);
	~aGraph();
	void Load();
};

