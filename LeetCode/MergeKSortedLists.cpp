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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
		ListNode * root = NULL;
		ListNode * current = NULL;
		priority_queue<ListNode *,vector<ListNode *>,Solution >heap;
		for(int i=0;i<lists.size();++i){
			if( lists[i] != NULL ){
				heap.push(lists[i]);				
			}			
		}
		while( heap.size() ){
			ListNode * node = heap.top();
			
			heap.pop();
			// ListNode * next = node->next;
			if(root == NULL){
				root = node;
				current = root;	
			}
			else{
				current->next = node;
				current = current->next;
			}

			if( node->next ){
				heap.push( node->next );
			}
		}

		return root;
	}

	bool operator() (const ListNode * a, const ListNode *b){
		return a->val > b->val;
	}
};

//int main()
//{
//	ListNode *n1 = new ListNode(1);
//	ListNode *n2 = new ListNode(0);
//	vector<ListNode *> vec;
//	vec.push_back(n1);
//	vec.push_back(n2);
//
//	Solution().mergeKLists(vec);
//	return 0;
//}