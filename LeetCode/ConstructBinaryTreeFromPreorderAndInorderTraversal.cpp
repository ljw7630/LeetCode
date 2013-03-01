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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		int index = 0;
		return buildTreeHelper(index, 0, preorder.size()-1, preorder, inorder);
    }

	TreeNode * buildTreeHelper(int &index, int start, int end, vector<int> &preorder, vector<int> &inorder){
		if( start > end )
			return NULL;
		int indexInOrder = search(inorder, preorder[index], start, end);
		TreeNode * node = new TreeNode(preorder[index]);
		index++;
		node->left = buildTreeHelper(index, start, indexInOrder - 1, preorder, inorder);
		node->right = buildTreeHelper(index, indexInOrder+1, end, preorder, inorder);

		return node;
	}

	int search(const vector<int>& inorder, int value, int start, int end){
		
		for(int i = start; i<=end;++i)
		{
			if(inorder[i] == value)
				return i;
		}
		return -1;
	}
};

//int main()
//{
//	int arr1 [] = {1,2};
//	int arr2 [] = {2,1};
//	vector<int> vec1 = AlgorithmImpl::Utility::createVector(arr1,2);
//	vector<int> vec2 = AlgorithmImpl::Utility::createVector(arr2,2);
//
//	TreeNode *node = Solution().buildTree(vec1, vec2);
//
//	return 0;
//}