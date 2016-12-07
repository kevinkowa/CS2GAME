#include<iostream>
#include<vector>
#include<string>
using namespace std;

class undirectedGraph
{
protected:
	class vertex {
	public:
		int row;
		char col;
		char pos;
		vertex*predecesor;
		vector<vertex*>neighbours;
		vertex(int x,char y)
		{
			row = x;
			col = y;
			pos = '*';
		}
	};
	vector<vertex*>vertices;

	
public:
	vertex* find(int row,char col)
	{
		for (int x = 0; x < vertices.size(); x++)
			if (vertices[x]->row==row && vertices[x]->col==col)
				return vertices[x];
		
		return NULL;
	}
	void addVertex(int row,char col)
	{
		vertices.push_back(new vertex(row,col));
	}

	void addEdge(int x1,int y1,char x2,char y2)
	{
		vertex* first = find(x1,y1);
		vertex* second = find(x2,y2);
		if (first == NULL || second == NULL)
			cout << "Error... Wrong name for a vertex." << endl;
		else {
			first->neighbours.push_back(second);
			second->neighbours.push_back(first);
		}
	}
};