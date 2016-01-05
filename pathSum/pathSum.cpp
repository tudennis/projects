/*
 * Path sum I
Given a binary tree and a sum, determine if the tree has a root-to-leaf
path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

*/

/*
Path sum II

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]

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

	// printMatrix<int>(results);

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

void pathSumIIHelper(BTreeNode * root, int target, int sum, vector< vector<int> >& results, vector<int> v)
{
	if (root == 0)					// Check here will cause result being double
	{
		if (sum == target)
		{
			results.push_back(v);
		}
		return;
	}


	v.push_back(root->val);

	pathSumIIHelper(root->left, target, sum + root->val, results, v);
	pathSumIIHelper(root->right, target, sum + root->val, results, v);
}

vector< vector<int> > pathSumII(BTreeNode * root, int target)
{
	vector< vector<int> > results;
	if (root == 0)
	{
		return results;
	}

	int sum(0);
	vector<int> v;

	pathSumIIHelper(root, target, sum, results, v);

	return results;
}


bool pathSumHelper(BTreeNode * root, int target, int sum)
{
	if (root == 0)
	{
		if (target == sum)
			return true;
		else
			return false;
	}

	return pathSumHelper(root->left, target, sum + root->val) || pathSumHelper(root->right, target, sum + root->val);
}

bool pathSum(BTreeNode * root, int target)
{
	int sum(0);

	return pathSumHelper(root, target, sum);
}

int main(int argc, char ** argv)
{
	BTreeNode root(5);
	BTreeNode	n1(4);
	BTreeNode	n2(8);
	root.left = &n1;
	root.right = &n2;

	BTreeNode	n3(11);
	n1.left = &n3;

	BTreeNode	n4(13);
	BTreeNode	n5(4);
	n2.left = &n4;
	n2.right = &n5;

	BTreeNode	n6(7);
	BTreeNode	n7(2);
	n3.left = &n6;
	n3.right = &n7;

	BTreeNode	n8(5);
	BTreeNode	n9(1);
	n5.left = &n8;
	n5.right = &n9;

	printBTree(&root);

	int sum(22);

	cout << "Is there path that sum equals: " << sum << ". "
			<< (pathSum(&root, sum) ? "Yes" : "No") << endl;

	cout << "All the paths that equal to sum " << sum << " are: " << endl;
	vector< vector<int> > results = pathSumII(&root, sum);
	printMatrix(results);

	return 0;
}
