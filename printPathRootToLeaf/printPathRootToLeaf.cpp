/*
 Give a binary tree, print out all path from root to leaves.  Use iterative way
*/

#include <set>
#include <vector>
#include <algorithm>
#include <iostream>

struct Node
{
	char value;
	Node * left;
	Node * right;

	Node(char v): value(v), left(0), right(0)
		{};
};

void printValue(const Node& node)
{
	std::cout << node.value << " ";
}

void print(const std::vector<Node>& path)
{
	std::for_each(path.begin(), path.end(), printValue);
	std::cout << std::endl;
}

/// Recursive
void printPathRecursiveHelper(const Node& node, std::vector<Node>& path)
{
	path.push_back(node);

	if (node.left == 0
			&& node.right == 0)
	{
		print(path);
		return;
	}

	if (node.left != 0)
	{
		printPathRecursiveHelper(*(node.left), path);
		path.pop_back();
	}

	if (node.right != 0)
	{
		printPathRecursiveHelper(*(node.right), path);
		path.pop_back();
	}

}

void printPathRootToLeafRecursive(const Node & root)
{
	std::vector<Node> path;

	printPathRecursiveHelper(root, path);

}

/// Iterative
void printPathRootToLeafIterative(const Node& root)
{
	std::set<Node> visited;
	visited.insert(root);

	std::vector<Node> visiting;
	visiting.push_back(root);

	while (visiting.size() > 0)
	{
		Node n = visiting.erase(visiting.begin());

		if (visited.find(n) != visited.end())
		{
			continue;
		}
		else
		{
			visited.insert(n);
			if (n.left == 0
					&& n.right == 0)
			{
				// Leaf, print path
			}
			else
			{

			}
		}
	}
}

int main(int argc, char ** argv)
{
	Node root('a');
	Node n1('b');
	Node n2('c');
	Node n3('d');
	Node n4('e');

	root.left = &n1;
	root.right = &n2;

	n2.left = &n3;
	n3.right = &n4;

	///
	std::cout << "Recursive result: " << std::endl;
	printPathRootToLeafRecursive(root);

	///
	std::cout << "Iterative result: " << std::endl;
	printPathRootToLeafIterative(root);

	return 0;
}
