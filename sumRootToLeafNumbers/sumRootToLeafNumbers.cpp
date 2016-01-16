/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3

The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
*/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int v) : val(v), left(0), right(0) {}
};

int convertPath(const vector<int>& path)
{
	int sum = 0;
	for (int i = 0; i < path.size(); ++ i)
	{
		sum = sum * 10 + path[i];
	}
	return sum;
}

void dfs(TreeNode const* root, vector<int> path, int& result)
{
	if (root == 0)
	{
		return;
	}

	path.push_back(root->val);
	if (root->left == 0 && root->right == 0)
	{
		int newVal = convertPath(path);
		result += newVal;
		return;
	}
	dfs(root->left, path, result);
	dfs(root->right, path, result);
}

int sumRootToLeafNumbers(TreeNode const * root)
{
	int result(0);
	vector<int> path;

	dfs(root, path, result);

	return result;
}

int main(int argc, char ** argv)
{
	TreeNode n1(1);
	TreeNode n2(2);
	TreeNode n3(3);

	n1.left = &n2;
	n1.right = &n3;

	cout << sumRootToLeafNumbers(&n1) << endl;

	return 0;
}
