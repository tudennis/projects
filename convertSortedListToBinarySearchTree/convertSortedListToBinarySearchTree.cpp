/*
 Given a singly linked list where elements are sorted in ascending order,
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

struct ListNode
{
	int val;
	ListNode * next;
	ListNode(int v) : val(v), next(0) {}
};

void printList(ListNode * head)
{
	ListNode * itr(head);
	while (itr != 0)
	{
		cout << itr->val << " ";
		itr = itr->next;
	}
	cout << endl;
}

BTreeNode * helper(ListNode *& head, int low, int high)
{
	if (low > high || head == 0)
	{
		return 0;
	}

	int mid = low + (high - low) / 2;

	BTreeNode * left = helper(head, low, mid - 1);
	BTreeNode * root = new BTreeNode(head->val);
	root->left = left;
	head = head->next;
	root->right = helper(head, mid + 1, high);

	return root;
}

BTreeNode * convertSortedListTobalancedBinaryTree(ListNode * head)
{
	int len(0);
	ListNode * itr(head);

	while (itr != 0)
	{
		len ++;
		itr = itr->next;
	}

	itr = head;

	return helper(itr, 0, len - 1);
}

int main(int argc, char ** argv)
{
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(3);
	ListNode n4(4);
	ListNode n5(5);
	ListNode n6(6);
	ListNode n7(7);
	ListNode n8(8);
	ListNode n9(9);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = &n6;
	n6.next = &n7;
	n7.next = &n8;
	n8.next = &n9;

	printList(&n1);

	BTreeNode * root = convertSortedListTobalancedBinaryTree(&n1);

	printBTree(root);

	return 0;
}
