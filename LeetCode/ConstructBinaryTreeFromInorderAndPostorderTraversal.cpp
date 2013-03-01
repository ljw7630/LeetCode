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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		int index = postorder.size()-1;

		return buildTreeHelper(index, 0, postorder.size()-1, inorder, postorder);
	}

	TreeNode *buildTreeHelper(int &index, int start, int end, 
				vector<int> &inorder, vector<int> & postorder){
		if(start > end)
			return NULL;
		int inorderIndex = search(inorder, postorder[index], start, end);
		TreeNode * node = new TreeNode(postorder[index]);
		index--;
		node->right = buildTreeHelper(index, inorderIndex+1, end, inorder, postorder);
		node->left = buildTreeHelper(index, start, inorderIndex-1, inorder, postorder);		

		return node;
	}

	int search(vector<int> &inorder, int value, int start, int end){
		for(int i=start;i<=end;++i){
			if(inorder[i]==value){
				return i;
			}
		}
		return -1;
	}
};

//int main()
//{
//	int arr1[] = {1,2, 3, 4};
//	int arr2[] = {2, 1, 4, 3};
//	vector<int> vec1 = AlgorithmImpl::Utility::createVector(arr1,4);
//	vector<int> vec2 = AlgorithmImpl::Utility::createVector(arr2,4);
//	Solution().buildTree(vec1, vec2);
//
//	return 0;
//}