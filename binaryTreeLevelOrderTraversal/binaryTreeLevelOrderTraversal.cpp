/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
void printVal(const T& val)
{
	cout << val << " ";
}

template <typename T>
void printRow(const vector<T>& row)
{
	for_each(row.begin(), row.end(), printVal<T>);
	cout << endl;
}

template <typename T>
void printMatrix(const vector< vector<T> >& matrix)
{
	for_each(matrix.begin(), matrix.end(), printRow<T>);
	cout << endl;
}

struct BTreeNode
{
	int val;
	BTreeNode * left;
	BTreeNode * right;
	BTreeNode(int v): val(v), left(0), right(0) {}
};

void binaryTreeLevelOrderTraversalHelper(BTreeNode * root, int level, vector< vector<int> >& results)
{
	if (root == 0)
	{
		return;
	}

	if (results.size() == level)
	{
		vector<int> v;
		v.push_back(root->val);
		results.push_back(v);
	}
	else
	{
		results[level].push_back(root->val);
	}

	binaryTreeLevelOrderTraversalHelper(root->left, level + 1, results);

	binaryTreeLevelOrderTraversalHelper(root->right, level + 1, results);
}

vector< vector<int> > binaryTreeLevelOrderTraversal(BTreeNode * root)
{
	vector< vector<int> > results;

	binaryTreeLevelOrderTraversalHelper(root, 0, results);

	return results;
}

int main(int argc, char ** argv)
{
	vector< vector<int> > results;

	BTreeNode root(3);
	BTreeNode	n1(9);
	BTreeNode	n2(20);
	BTreeNode	n3(15);
	BTreeNode	n4(7);

	root.left = &n1;
	root.right = &n2;
	n2.left = &n3;
	n2.right = & n4;

	results = binaryTreeLevelOrderTraversal(&root);

	printMatrix(results);

	return 0;
}
