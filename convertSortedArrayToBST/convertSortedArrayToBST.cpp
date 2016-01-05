/*
 Given an array where elements are sorted in ascending order,
 convert it to a height balanced BST.
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

BTreeNode * convertToBSTHelper(vector<int>& input, int low, int high)
{
	if (low > high)
	{
		return 0;
	}

	int mid = low + (high - low)/2;
	BTreeNode * n = new BTreeNode(input[mid]);

	n->left = convertToBSTHelper(input, low, mid - 1);
	n->right = convertToBSTHelper(input, mid + 1, high);

	return n;
}

BTreeNode * convertToBST(vector<int>& input)
{
	if (input.size() == 0)
	{
		return 0;
	}

	int low(0), high(input.size() - 1);

	BTreeNode * n = convertToBSTHelper(input, low, high);

	return n;
}

int main(int argc, char ** argv)
{
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	a.push_back(6);
	a.push_back(7);
	a.push_back(8);
	a.push_back(9);
	a.push_back(10);
	a.push_back(11);
	a.push_back(12);
	a.push_back(13);
	a.push_back(14);
	a.push_back(15);
	a.push_back(16);
	a.push_back(17);

	BTreeNode * root = convertToBST(a);

	printBTree(root);

	return 0;
}
