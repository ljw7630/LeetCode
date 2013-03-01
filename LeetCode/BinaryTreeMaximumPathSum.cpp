#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <stack>
#include <utility>
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


class Solution {
public:
    int maxPathSum(TreeNode *root) {
        
		int maxSum = INT_MIN;
		int current;
		maxPathSumHelper(root, current, maxSum);

		return maxSum;
    }

	void maxPathSumHelper(TreeNode *node, int &current, int &maxSum)
	{
		if(node == NULL)
		{
			current = 0;
			return;
		}

		int leftSum = 0, rightSum = 0;
		maxPathSumHelper(node->left, leftSum, maxSum);
		maxPathSumHelper(node->right, rightSum, maxSum);

		current = max(node->val, max(node->val + leftSum, node->val + rightSum));
		maxSum = max(maxSum, max( current, node->val + leftSum + rightSum) );

		return;
	}
};