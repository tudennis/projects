/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
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

void preOrder(BTreeNode * root, vector<BTreeNode *>& pre)
{
	if (root == 0)
		return;

	pre.push_back(root);
	preOrder(root->left, pre);
	preOrder(root->right, pre);
}

void flattenBTreeToList(BTreeNode * root)
{
	vector<BTreeNode *> pre;

	preOrder(root, pre);

	for (int i = 0; i < pre.size() - 1; ++i)
	{
		pre[i]->left = 0;
		pre[i]->right = pre[i + 1];
	}

	pre[pre.size() - 1]->left = pre[pre.size() - 1]->right = 0;
}

int main(int argc, char ** argv)
{
	BTreeNode root(1);
	BTreeNode	n2(2);
	BTreeNode	n3(3);
	BTreeNode	n4(4);
	BTreeNode	n5(5);
	BTreeNode	n6(6);

	root.left = &n2;
	root.right = &n5;
	n2.left = &n3;
	n2.right = &n4;
	n5.right = &n6;

	printBTree(&root);

	flattenBTreeToList(&root);

	printBTree(&root);

	return 0;
}
