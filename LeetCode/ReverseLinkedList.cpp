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

ListNode * reverseLinkedListHelper(ListNode * node, ListNode **newHead);

ListNode * reverseLinkedList(ListNode *head){
	if(head == NULL){
		return NULL;
	}
	ListNode * node;
	reverseLinkedListHelper(head, &node);

	return node;
}

ListNode * reverseLinkedListHelper(ListNode * node, ListNode **newHead){
	if( node->next == NULL ){
		*newHead = node;
		(*newHead)->next = NULL;
		return *newHead;
	}
	ListNode * pre = reverseLinkedListHelper(node->next, newHead);
	pre->next = node;
	node->next = NULL;
	return node;
}

//ListNode * reverseLinkedList(ListNode *head)
//{
//	ListNode *tmpNode = head;
//	ListNode *pre = NULL;
//	if( head == NULL || head->next == NULL)
//		return head;
//	while( head )
//	{
//		tmpNode = head->next;
//		head->next = pre;
//		pre = head;
//		head = tmpNode;
//	}
//
//	return pre;
//}

//int main()
//{
//	ListNode *n1 = new ListNode(1);
//	ListNode *n2 = new ListNode(2);
//	ListNode *n3 = new ListNode(3);
//	ListNode *n4 = new ListNode(4);
//	ListNode *n5 = new ListNode(5);
//	ListNode *n6 = new ListNode(6);
//	ListNode *n7 = new ListNode(7);
//	n1->next = n2;
//	n2->next = n3;
//	n3->next = n4;
//	n4->next = n5;
//	n5->next = n6;
//	n6->next = n7;
//	n7->next = NULL;
//	ListNode * node = reverseLinkedList(NULL);
//	printList(node);
//	getchar();
//	return 0;
//}