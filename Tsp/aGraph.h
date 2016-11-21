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

	aGraph();
	~aGraph();
	void Load();
	void Split(const std::string& s, char delim, std::vector<std::string>& elems);
};

