#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include "AlgorithmImpl.h"
#include "ListNode.h"

using namespace std;
using namespace AlgorithmImpl;


 struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        return sortedListToBSTHelper(head, NULL);
    }

	TreeNode *sortedListToBSTHelper(
		ListNode *start, ListNode *end)
	{
		if(start == end)
		{
			return NULL;
		}
		ListNode *mid = findMiddle(start,end);
		TreeNode * node = new TreeNode(mid->val);

		node->left = sortedListToBSTHelper(start, mid);
		node->right = sortedListToBSTHelper(mid->next, end);

		return node;
	}

	ListNode* findMiddle(ListNode *head, ListNode *end)
	{
		ListNode *midNode;
		ListNode *faster = head;
		ListNode *slower = head;
		while(faster!=end)
		{
			if(faster->next != end)
			{
				slower = slower->next;
				faster = faster->next->next;
			}
			else
			{
				break;
			}
		}

		return slower;
	}
};