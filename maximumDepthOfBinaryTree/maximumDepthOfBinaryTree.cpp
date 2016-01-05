/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.


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

int maximumDepthOfBinaryTree(BTreeNode * root)
{
	if (root == 0)
	{
		return 0;
	}
	int left = maximumDepthOfBinaryTree(root->left) + 1;
	int right = maximumDepthOfBinaryTree(root->right) + 1;
	return max(left, right);
}

int main(int argc, char ** argv)
{
	BTreeNode root(3);
	BTreeNode	n1(9);
	BTreeNode	n2(20);
	BTreeNode	n3(15);
	BTreeNode	n4(7);

	root.left = &n1;
	root.right = &n2;
	n2.left = &n3;
	n2.right = & n4;

	cout << "Maximum depth is : " << maximumDepthOfBinaryTree(&root) << endl;

	return 0;
}
