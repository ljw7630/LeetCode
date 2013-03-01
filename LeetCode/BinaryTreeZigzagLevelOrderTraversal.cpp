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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;

		if(root == NULL)
			return result;

		stack<TreeNode *> stacks[2];
		stacks[0] = stack<TreeNode *>();
		stacks[1] = stack<TreeNode *>();
		int index = 1;
		stacks[index].push(root);
		vector<int> res;
		while(!stacks[0].empty() || !stacks[1].empty())
		{			
			TreeNode * node = stacks[index].top();
			stacks[index].pop();
			res.push_back(node->val);

			if( index%2 )
			{
				if(node->left != NULL)
				{
					stacks[nextPos(index)].push(node->left);
				}
				if(node->right != NULL)
				{
					stacks[nextPos(index)].push(node->right);
				}
			}
			else
			{
				if(node->right != NULL)
				{
					stacks[nextPos(index)].push(node->right);
				}
				if(node->left != NULL)
				{
					stacks[nextPos(index)].push(node->left);
				}
			}

			if(stacks[index].empty())
			{
				index = nextPos(index);
				result.push_back(res);
				res = vector<int>();
			}
		}

		return result;
    }

	inline int nextPos(int index)
	{
		return (index+1)%2;
	}
};

//int main()
//{
//	TreeNode node0(0);
//	TreeNode node1(2);
//	TreeNode node2(4);
//	TreeNode node3(1);
//	// TreeNode node4();
//	TreeNode node5(3);
//	TreeNode node6(-1);
//	TreeNode node7(5);
//	TreeNode node8(1);
//	// TreeNode node9(0);
//	TreeNode node10(6);
//	// TreeNode node11(0);
//	TreeNode node12(8);
//	node0.left = &node1;
//	node0.right = &node2;
//	node1.left = &node3;
//	node2.left = &node5;
//	node2.right = &node6;
//	node3.left = &node7;
//	node3.right = &node8;
//	node5.right = &node10;
//	node6.right = &node12;
//	Solution().zigzagLevelOrder(&node0);
//	return 0;
//}