#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include "AlgorithmImpl.h"

using namespace std;
using namespace AlgorithmImpl;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

/***
 *  for not perfect tree, discover the right sub-tree first
 */

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

class Solution {
public:
  //  void connect(TreeLinkNode *root) {
		//if( !root ){
		//	return;
		//}

		//if( root->left ){
		//	root->left->next = root->right;
		//	if( root->next ){
		//		root->right->next = root->next->left;
		//	}
		//}
		//connect(root->left);
		//connect(root->right);
  //  }

    void connect(TreeLinkNode *root) {
		if( !root ){
			return;
		}
		
		if( root->left ){
			if( root->right ){
				root->left->next = root->right;
			}
			else{
				TreeLinkNode *node = root->next;
				while( node ){
					if(node->left ){
						root->left->next = node->left;
						break;
					}
					else if( node->right ){
						root->left->next = node->right;
						break;
					}
					else{
						node = node->next;
					}
				}
			}
		}

		if( root->right ){
			TreeLinkNode *node = root->next;
			while( node ){
				if( node->left ){
					root->right->next = node->left;
					break;
				}
				else if( node->right ){
					root->right->next = node->right;
					break;
				}
				else{
					node = node->next;
				}
			}
		}

		connect(root->right);
		connect(root->left);
    }
};