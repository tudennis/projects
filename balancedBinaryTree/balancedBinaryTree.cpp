/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which
the depth of the two subtrees of every node never differ by more than 1.
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
	if (results.size() == level)
	{
		vector<int> v;
		v.push_back(root == 0 ? -9999 : root->val);
		results.push_back(v);
	}
	else
	{
		results[level].push_back(root == 0 ? -9999 : root->val);
	}

	if (root != 0)
	{
		binaryTreeLevelOrderTraversalHelper(root->left, level + 1, results);

		binaryTreeLevelOrderTraversalHelper(root->right, level + 1, results);
	}
}

vector< vector<int> > binaryTreeLevelOrderTraversal(BTreeNode * root)
{
	vector< vector<int> > results;

	binaryTreeLevelOrderTraversalHelper(root, 0, results);

	return results;
}

void printBTree(BTreeNode * root)
{
	// 1. Generate level by level vector
	vector< vector<int> > results = binaryTreeLevelOrderTraversal(root);

	printMatrix<int>(results);

	// 2. Print in pretty style
	int levels = results.size();

	for (int i = 0; i < levels; ++i)
	{
		int spaces = pow(2, levels - i);
		for (int j = 0; j < results[i].size(); ++j)
		{
			for (int k = 0; k < (j == 0 ? spaces : 2 * spaces - 1); ++k)
			{
				cout << " ";
			}
			if (results[i][j] == -9999)
				cout << " ";
			else
				cout << results[i][j];
		}
		cout << endl;
	}
}

bool isBalancedBTHelper(BTreeNode * root, int& height)
{
	if (root == 0)
	{
		height = 0;
		return true;
	}

	int lh, rh;
	bool l(false), r(false);

	l = isBalancedBTHelper(root->left, lh);
	r = isBalancedBTHelper(root->right, rh);

	height = max(lh, rh) + 1;	// Always populate the height

	// Any subtree is not balanced
	if (!l || !r)
	{
		return false;
	}
	else if (abs(lh - rh) > 1) // Left/right differ by more than 1
	{
		return false;
	}

	return true;

}

bool isBalancedBT(BTreeNode * root)
{
	int height(0);

	return isBalancedBTHelper(root, height);
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
	n3.right = & n4;

	printBTree(&root);

	cout << "Is it balanced : " << (isBalancedBT(& root) ? "Yes" : "No") << endl;

	return 0;
}
