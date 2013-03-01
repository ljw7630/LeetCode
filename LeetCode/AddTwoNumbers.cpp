#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include "AlgorithmImpl.h"
#include "ListNode.h"

using namespace std;
using namespace AlgorithmImpl;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		if(l1==NULL && l2 == NULL)
			return NULL;
		if(l1== NULL)
			return l2;
		else if(l2 == NULL)		
			return l1;
		
		ListNode *root = NULL, *cur = NULL;
		
		int carry = 0;
        while(l1 != NULL && l2!=NULL)
		{
			int tmp = l1->val + l2->val + carry;
			carry = tmp/10;
			if(root == NULL)
			{			
				root = new ListNode(tmp%10);
				cur = root;
			}
			else
			{
				cur->next = new ListNode(tmp%10);
				cur = cur->next;
			}

			l1 = l1->next;
			l2 = l2->next;
		}
        ListNode *availableList = NULL;
		l1 == NULL?availableList=l2:availableList=l1;

		while(availableList!=NULL)
		{
			int tmp = availableList->val+carry;
			carry = tmp/10;
			cur->next = new ListNode(tmp%10);
			cur = cur->next;
			availableList = availableList->next;
		}

		if (carry)
		{
			cur->next = new ListNode(carry);
		}

		return root;
    }
};

//int main()
//{
//	ListNode n1(2);
//	ListNode n2(4);
//	ListNode n3(3);
//	n1.next = &n2; n2.next = &n3;
//
//	ListNode n4(5);
//	ListNode n5(6);
//	ListNode n6(8);
//	ListNode n7(8);
//	n4.next = &n5; n5.next = &n6; n6.next=&n7;
//
//	ListNode *node = Solution().addTwoNumbers(&n1, &n4);
//
//	while(node)
//	{
//		cout << node->val << endl;
//		node = node->next;
//	}
//	getchar();
//	return 0;
//}