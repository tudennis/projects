/*
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }

Populate each next pointer to point to its next right node.
If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
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
	BTreeNode * next;
	BTreeNode(int v): val(v), left(0), right(0), next(0) {}
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


// Recursive
void populateNextPointerRecursive(BTreeNode * root)
{
	if (!root)
	{
		return;
	}

	if (root->left && root->right)
	{
		root->left->next = root->right;
	}

	if (root->next && root->right)
	{
		root->right->next = root->next->left;
	}

	populateNextPointerRecursive(root->left);
	populateNextPointerRecursive(root->right);
}

// constant space
// key point: we can use `next` pointer to represent
//      the buffering queue of level order traversal.

int main(int argc, char ** argv)
{
	BTreeNode root(1);
	BTreeNode n2(2);
	BTreeNode n3(3);
	BTreeNode n4(4);
	BTreeNode n5(5);
	BTreeNode n6(6);
	BTreeNode n7(7);

	root.left = &n2;
	root.right = &n3;

	n2.left = &n4;
	n2.right = &n5;

	n3.left = &n6;
	n3.right = &n7;

	printBTree(&root);

	populateNextPointerRecursive(&root);

	return 0;
}
