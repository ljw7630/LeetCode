#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include "ListNode.h"
#include "AlgorithmImpl.h"

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode *root = NULL;
		ListNode *current = NULL;
		while( l1 || l2 ){
			ListNode * node = NULL;

			if( l1 == NULL){
				node = l2;
			}
			else if(l2 == NULL) {
				node = l1;
			}
			else{
				if( l1->val <= l2->val ){
					node=l1;
				}
				else{
					node = l2;
				}
			}
			if( !root ){
				root = node;
				current = root;
			}
			else{
				current->next = node;
				current = current->next;
			}
			if( node == l1 ){
				l1=l1->next;
			}
			else{
				l2=l2->next;
			}
		}

		return root;
    }
};

//int main(){
//	ListNode * n1 = new ListNode(1);
//	ListNode * n2 = new ListNode(2);
//	ListNode * n3 = new ListNode(4);
//	n1->next = n2;
//	n2->next = n3;
//	Solution().mergeTwoLists(NULL, n1);
//	getchar();
//	return 0;
//}