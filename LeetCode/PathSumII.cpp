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

class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
		vector<vector<int> > resultSet;
		if( !root ){
			return resultSet;
		}
		vector<int> result;
		pathSumHelper( root, sum, result, resultSet);
		return resultSet;
    }

	void pathSumHelper(TreeNode* node, int sum, vector<int> &result, vector<vector<int> > &resultSet){
		if( !node->left && !node->right ){
			if( node->val == sum ){
				result.push_back( node->val);
				resultSet.push_back(result);
				result.pop_back();
			}
			return;
		}

		if( node->left ){
			result.push_back( node->val );
			pathSumHelper(node->left, sum - node->val,  result, resultSet);
			result.pop_back();
		}
		if( node->right ){
			result.push_back( node->val );
			pathSumHelper( node->right, sum - node->val, result, resultSet);
			result.pop_back();
		}
	}
};