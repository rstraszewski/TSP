#pragma once

class Graph
{
private:
	ifstream file;
public:
	vector<float> GraphX;
	vector<float> GraphY;
	string Name;
	string Type;
	string Comment;
	int Dimension;
	string EdgeWeightType;

	Graph();
	~Graph();
	void Load();
	void Split(const std::string& s, char delim, std::vector<std::string>& elems);
};

