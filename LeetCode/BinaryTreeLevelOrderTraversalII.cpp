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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
		
		vector<vector<int> > vec = levelOrder(root);

		reverse(vec.begin(), vec.end());

		return vec;
    }

	vector<vector<int> > levelOrder(TreeNode *root) {
		queue<pair<TreeNode *,int> > nodeQueue;
		vector<vector<int> > result;
		if(root != NULL)
		{
			nodeQueue.push(make_pair(root, 0));
			int previousLevel = -1;
			
			while(!nodeQueue.empty())
			{
				pair<TreeNode *,int> nodeAndLevel = nodeQueue.front();
				nodeQueue.pop();
				if(nodeAndLevel.second != previousLevel)
				{
					result.push_back(vector<int>());
					previousLevel++;
				}
				result[result.size()-1].push_back(nodeAndLevel.first->val);

				if( nodeAndLevel.first->left != NULL)
				{
					nodeQueue.push(make_pair(nodeAndLevel.first->left, nodeAndLevel.second+1) );
				}
				if( nodeAndLevel.first->right != NULL )
				{
					nodeQueue.push(make_pair(nodeAndLevel.first->right, nodeAndLevel.second+1) );
				}
			}
		}

		return result;
    }
};