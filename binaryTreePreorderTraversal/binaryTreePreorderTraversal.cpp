/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].
*/


#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct BTreeNode
{
    int val;
    BTreeNode * left;
    BTreeNode * right;
    BTreeNode(int v): val(v), left(0), right(0) {}
};

void printVector(vector<BTreeNode *>& vec)
{
    for(int i = 0; i < vec.size(); ++ i)
    {
        cout << vec[i]->val << " ";
    }
    cout << endl;
}

void preorderRecursiveHelper(BTreeNode * root, vector<BTreeNode *>& result)
{
    if (root == 0)
    {
        return;
    }

    result.push_back(root);
    preorderRecursiveHelper(root->left, result);
    preorderRecursiveHelper(root->right, result);
}

vector<BTreeNode *> preorderRecursive(BTreeNode * root)
{
    vector<BTreeNode *> result;

    preorderRecursiveHelper(root, result);

    return result;
}

vector<BTreeNode *> preorderIterative(BTreeNode * root)
{
    vector<BTreeNode *> result;

    queue<BTreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        BTreeNode * current = q.front();
        q.pop();

        if (current != 0)
        {
            result.push_back(current);
            q.push(current->left);
            q.push(current->right);
        }
    }

    return result;
}

int main(int argc, char ** argv)
{
    BTreeNode root(1);
    BTreeNode   n1(2);
    BTreeNode   n2(3);

    root.right = &n1;
    n1.left = &n2;

    vector<BTreeNode *> result = preorderRecursive(&root);
    printVector(result);

    result.clear();
    result = preorderIterative(&root);
    printVector(result);

    return 0;
}

