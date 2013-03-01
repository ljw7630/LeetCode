#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include "AlgorithmImpl.h"

using namespace std;
using namespace AlgorithmImpl;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if(root == NULL)
			return true;
		int res = getCount(root);
        if(res == -1)
			return false;
		else
		{
			return true;
		}
    }

	int getCount(TreeNode *node)
	{
		int leftCount = 1, rightCount = 1;
		if(node->left!=NULL)
		{
			leftCount = getCount(node->left);
			if(leftCount == -1)
				return -1;
		}
		if(node->right!=NULL)
		{
			rightCount = getCount(node->right);
			if(rightCount == -1)
				return -1;
		}

		if(abs(leftCount-rightCount) > 1)
			return -1;
		else
		{
			return max(leftCount,rightCount)+1;
		}
	}
};