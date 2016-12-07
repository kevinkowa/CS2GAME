#include<iostream>
#include<string>
#include<queue>
#include "directedGraph.h"
using namespace std;
class gameGraph : public directedGraph
{
private:
	vertex * playerVertex; 

public:
	void testDisplay()
	{
		display();
		cout << endl;
	}
	void setPlayerLocation(string s)
	{
		playerVertex= find(s);
	}
	string getPlayerLocation()
	{
		return playerVertex->data;
	}
	string getPlayerLocationExits()
	{
		string paths="";
		if (playerVertex->neighbours.size() == 0)
			return "There aint none";
		for (int x = 0; x < playerVertex->neighbours.size()-1; x++)
		{
			paths+= playerVertex->neighbours[x]->data+", ";
		}
		paths += playerVertex->neighbours[playerVertex->neighbours.size() - 1]->data + ".";
		return paths;
	}
	bool travelTo(string s)
	{
		bool found = false;
		for (int x = 0; x < playerVertex->neighbours.size(); x++)
		{
			if (playerVertex->neighbours[x]->data == s)
			{
				playerVertex = playerVertex->neighbours[x];
				found = true;
				break;
			}
		}
		return found;
	}

	void BFS()
	{
		vertex*castle = find("saurons tower");
		if (castle == playerVertex)
		{
			cout << "You are already at Sauron's Castle.." << endl;
			return;
		}
		string path = "";
		queue<vertex*>vec;
		vector<vertex*>visited;
		vec.push(playerVertex);
		visited.push_back(playerVertex);
		while (!vec.empty())
		{
			vertex*curr = vec.front();
			vec.pop();
		
			for (int x=0;x<curr->neighbours.size();x++)
			{		
				vertex*next = curr->neighbours[x];
				if (std::find(visited.begin(), visited.end(), next) == visited.end())
				{
					
					next->predecesor = curr;
					curr->neighbours[x] = next;
					vec.push(next);
					visited.push_back(next);
				}
			}	
		}
		

		path = castle->data + ".";
		castle = castle->predecesor;
		while (castle->data != playerVertex->data)
		{
			path = castle->data + ", " + path;
			castle = castle->predecesor;
		}
		cout << "The shortest route to Sauron's castle is " << endl;
		cout << path << endl;

	}

};