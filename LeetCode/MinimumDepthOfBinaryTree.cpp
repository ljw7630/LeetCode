#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <stack>
#include <queue>

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
    int minDepth(TreeNode *root) {
		if( root == NULL){
			return 0;
		}
		
		int v1 = minDepth(root->left);
		int v2 = minDepth(root->right);
		int result = 0;
		if( v1 == 0 )
			return 1+v2;
		if( v2 == 0 )
			return 1+v1;
		else
			return 1+min(v1,v2);
	}
};