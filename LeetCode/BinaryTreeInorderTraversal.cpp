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
class Solution {
public:
	// iterative
  //  vector<int> inorderTraversal(TreeNode *root) {

		//stack<TreeNode *> nodeStack;
		//vector<int> result;
		//
		//TreeNode * node = root;
		//while(!nodeStack.empty() || node != NULL)
		//{
		//	if( node != NULL )
		//	{
		//		nodeStack.push(node);
		//		node = node->left;
		//	}
		//	else
		//	{
		//		node = nodeStack.top();
		//		nodeStack.pop();
		//		result.push_back(node->val);				
		//		node = node->right;
		//	}
		//}

		//return result;
  //  }

	// recursive
	vector<int> inorderTraversal(TreeNode *root) {
		vector<int> result;
		if(root != NULL)
			inorderTraversal(result, root);

		return result;
	}

	void inorderTraversal(vector<int> &result, TreeNode * node)
	{
		if(node->left!=NULL)
			inorderTraversal(result, node->left);
		result.push_back(node->val);
		if(node->right!=NULL)
			inorderTraversal(result, node->right);
	}
};