#include<iostream>
#include<vector>
#include<string>
using namespace std;

class directedGraph
{
protected:
	class vertex {
	public:
		string data;
		vertex*predecesor;
		vector<vertex*>neighbours;
		vertex(string x)
		{
			data = x;
		}
	};
	vector<vertex*>vertices;

	vertex* find(string s)
	{
		for (int x = 0; x < vertices.size(); x++)
			if (vertices[x]->data == s)
				return vertices[x];
		return NULL;
	}
public:
	
	void addVertex(string x)
	{
		vertices.push_back(new vertex(x));
	}
	void addDirectedEdge(string x, string y)
	{
		vertex* first = find(x);
		vertex* second = find(y);
		if (first == NULL || second == NULL)
			cout << "Error... Wrong name for a vertex." << endl;
		else
			first->neighbours.push_back(second);
	}

	void display()
	{
		for (int x = 0; x < vertices.size(); x++)
		{
			cout << vertices[x]->data << ": ";
			for (int y = 0; y < vertices[x]->neighbours.size(); y++)
			{
				cout << vertices[x]->neighbours[y]->data << ", ";
			}
			cout << endl;
		}
	}
	
	void addEdge(string x, string y)
	{
		vertex* first = find(x);
		vertex* second = find(y);
		if (first == NULL || second == NULL)
			cout << "Error... Wrong name for a vertex." << endl;
		else {
			first->neighbours.push_back(second);
			second->neighbours.push_back(first);
		}
	}
};