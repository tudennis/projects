/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
*/

#include <vector>
#include <iostream>
#include <algorithm>
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

void postorderRecursiveHelper(BTreeNode * root, vector<BTreeNode *>& result)
{
    if (root == 0)
    {
        return;
    }

    postorderRecursiveHelper(root->left, result);
    postorderRecursiveHelper(root->right, result);
    result.push_back(root);
}

vector<BTreeNode *> postorderRecursive(BTreeNode * root)
{
    vector<BTreeNode *> result;

    postorderRecursiveHelper(root, result);

    return result;
}

vector<BTreeNode *> postorderIterative(BTreeNode * root)
{
    vector<BTreeNode *> result;

    vector<BTreeNode *> s;
    if (root != 0)
        s.push_back(root);

    while (!s.empty())
    {
        BTreeNode * current = s.back();
        s.pop_back();
        result.push_back(current);

        if (current->left)
            s.push_back(current->left);
        if (current->right)
            s.push_back(current->right);
    }

    std::reverse(result.begin(), result.end());

    return result;
}

int main(int argc, char ** argv)
{
    BTreeNode root(1);
    BTreeNode   n1(2);
    BTreeNode   n2(3);

    root.right = &n1;
    n1.left = &n2;

    vector<BTreeNode *> result = postorderRecursive(&root);
    printVector(result);

    result.clear();
    result = postorderIterative(&root);
    printVector(result);

    return 0;
}
