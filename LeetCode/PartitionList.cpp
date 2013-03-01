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
    ListNode *partition(ListNode *head, int x) {
		if(head == NULL)
			return head;
		ListNode *headOfInsertPre = NULL;
		ListNode *headOfInsert = head;
		ListNode *newHead = head;
		while(headOfInsert->val < x){
			headOfInsertPre = headOfInsert;
			headOfInsert = headOfInsert->next;
			
			if(headOfInsert == NULL){
				return head;
			}
		}
		
		ListNode *currentPre = headOfInsert;
		ListNode *current = headOfInsert->next;
		while( current ){
			if(current->val < x){
				if(headOfInsertPre == NULL){
					newHead = current;
					headOfInsertPre = current;
					currentPre->next = current->next;
					current->next = headOfInsert;										
				}
				else{
					headOfInsertPre->next = current;
					headOfInsertPre = headOfInsertPre->next;

					currentPre->next = current->next;
					current->next = headOfInsert;		
				}
				currentPre = current;
				current = current->next;
			}
			else{
				currentPre = current;
				current = current->next;
			}
		}

		return newHead;
	}
};

//int main(){
//	ListNode * n1 = new ListNode(5);
//	ListNode * n2 = new ListNode(4);
//	ListNode * n3 = new ListNode(3);
//	ListNode * n4 = new ListNode(2);
//	ListNode * n5 = new ListNode(5);
//	ListNode * n6 = new ListNode(2);
//	n1->next = n2;
//	n2->next = n3;
//	n3->next = n4;
//	n4->next = n5;
//	n5->next = n6;
//	AlgorithmImpl::Utility::printList(Solution().partition(n1, 3));
//	getchar();
//	return 0;
//}