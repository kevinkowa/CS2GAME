#include<iostream>
#include<string>
#include<queue>
#include "undirectedGraph.h"
using namespace std;
class Board : public undirectedGraph
{
private:
	vertex * playerVertex;
	vertex * Zombie;
	int points;
public:
	bool alive()
	{
		if (abs(Zombie->row - playerVertex->row) <= 1 && abs(Zombie->col - playerVertex->col) <= 1)
		{
			cout << "YOU LOST...";
			return false;
		}
		return true;
	}
	int getRow()
	{
		return playerVertex->row;
	}
	char getCol()
	{
		return playerVertex->col;
	}
	void setPlayerLocation(int num,char pos)
	{
		if(playerVertex!=NULL)
			playerVertex->pos = ' ';
		playerVertex = find(num,pos);
		playerVertex->pos = 'P';
		
	}
	void setZombieLocation(int num, char pos)
	{
		if (Zombie != NULL)
			Zombie->pos = ' ';
		Zombie = find(num, pos);
		Zombie->pos = 'Z';
	}
	
	string getPlayerLocation()
	{
		string location = to_string(playerVertex->row) + " " + playerVertex->col;
		return location;
	}
	string getPlayerLocationExits()
	{
		string paths = "";
		if (playerVertex->neighbours.size() == 0)
			return "There aint none";
		for (int x = 0; x < playerVertex->neighbours.size() - 1; x++)
		{
			paths +="("+to_string(playerVertex->neighbours[x]->row) + ", "+playerVertex->neighbours[x]->col+"), ";
		}
		paths += "("+to_string(playerVertex->neighbours[playerVertex->neighbours.size() - 1]->row)+", " + playerVertex->neighbours[playerVertex->neighbours.size() - 1]->col+ ").";
		return paths;
	}
	bool travelTo(int row,char col)
	{
		bool found = false;
		for (int x = 0; x < playerVertex->neighbours.size(); x++)
		{
			if (playerVertex->neighbours[x]->row == row && playerVertex->neighbours[x]->col==col)
			{
				if (playerVertex->neighbours[x]->pos == '*')
					points += 100;
				playerVertex->pos = ' ';
				playerVertex->neighbours[x]->pos = 'P';
				playerVertex = playerVertex->neighbours[x];
				playerVertex->pos = 'P';
				found = true;
				break;
			}
		}
		return found;
	}
	void Points()
	{
		cout << "You have: " << points << " points" << endl;
	}

	bool BFS()
	{
		vertex*target = playerVertex;
		if (target == Zombie)
		{
			cout << "You lost..." << endl;
			return false;
		}
		string path = "";
		queue<vertex*>vec;
		vector<vertex*>visited;
		vec.push(Zombie);
		visited.push_back(Zombie);
		while (!vec.empty())
		{
			vertex*curr = vec.front();
			vec.pop();

			for (int x = 0; x<curr->neighbours.size(); x++)
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
		while (target->predecesor != Zombie)
		{
			target = target->predecesor;
		}
		setZombieLocation(target->row, target->col);
		return true;
		
	}
	
};