/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

OJ's undirected graph serialization:

Nodes are labeled uniquely.
We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.

As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

    First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
    Second node is labeled as 1. Connect node 1 to node 2.
    Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.

Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/

*/

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct UndirectedGraphNode
{
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

UndirectedGraphNode * cloneGraph(UndirectedGraphNode * node)
{
	if (node == 0)
	{
		return 0;
	}

	map<UndirectedGraphNode*, UndirectedGraphNode*> cloneMap;	// Original node to newly created node map

	queue<UndirectedGraphNode*> q;	// Breadth first search queue
	q.push(node);

	UndirectedGraphNode * newNode = new UndirectedGraphNode(node->label);	// Clone node
	cloneMap[node] = newNode;

	while (!q.empty())
	{
		UndirectedGraphNode *current = q.front();
		q.pop();

		for (int i  = 0; i < current->neighbors.size(); ++ i)
		{
			if (cloneMap.find(current->neighbors[i]) != cloneMap.end())
			{
				cloneMap[current]->neighbors.push_back(cloneMap[current->neighbors[i]]);
			}
			else
			{
				UndirectedGraphNode * newCurrent = new UndirectedGraphNode(current->label);
				cloneMap[current] = newCurrent;
				cloneMap[current]->neighbors.push_back(newCurrent);
				q.push(current);
			}
		}
	}

	return newNode;
}

int main(int argc, char ** argv)
{
	return 0;
}
