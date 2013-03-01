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
    TreeNode *sortedArrayToBST(vector<int> &num) {
		return sortedArrayToBSTHelper(num, 0, num.size()-1);
    }

	TreeNode * sortedArrayToBSTHelper(const vector<int> &num,
					int left, int right)
	{
		if(left > right)
		{
			return NULL;
		}
		int mid = left + (right-left)/2;
		TreeNode *node = new TreeNode(num[mid]);

		node->left = sortedArrayToBSTHelper(num, left, mid-1);
		node->right = sortedArrayToBSTHelper(num, mid+1, right);

		return node;
	}
};