#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include "AlgorithmImpl.h"
#include "ListNode.h"
#include "TreeNode.h"

using namespace std;
using namespace AlgorithmImpl;

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
    bool hasPathSum(TreeNode *root, int sum) {
        if( root == NULL){
			return false;
		}
		return hasPathSumHelper(root, sum);
    }

	bool hasPathSumHelper(TreeNode * node, int sum){

		// leaf
		if( !node->left && !node->right ){
			if( node->val == sum ){
				return true;
			}
			return false;
		}

		bool leftResult = false, rightResult = false;
		if( node->left ){
			leftResult = hasPathSumHelper( node->left, sum - node->val);
		}
		if( node->right ){
			rightResult = hasPathSumHelper( node->right, sum - node->val);
		}

		return leftResult || rightResult;
	}
};