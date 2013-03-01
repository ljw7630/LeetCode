#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <stack>
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

/// very careful !!!!
/// if the 'left' is NULL
/// if the left already have correct "right" node
class Solution {
public:
    void flatten(TreeNode *root) {
		flattenHelper(root);
    }

	TreeNode * flattenHelper(TreeNode *node)
	{
		if(node == NULL)
			return NULL;

		TreeNode *left = flattenHelper(node->left);
		TreeNode *right = flattenHelper(node->right);
		if(left == NULL)
		{
			node->right = right;
		}
		else
		{			
			node->right = left;
			TreeNode * last = node->right;
			while(last->right)
			{
				last = last->right;
			}
			last->right = right;
			
		}
		node->left = NULL;
		

		return node;
	}
};

//int main()
//{
//	TreeNode *n1 = new TreeNode(1);
//	TreeNode *n2 = new TreeNode(2);
//	TreeNode *n3 = new TreeNode(3);
//	n1->left = n2;
//	n2->left = n3;
//	Solution().flatten(n1);
//	return 0;
//}