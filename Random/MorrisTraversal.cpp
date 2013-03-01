#include "TreeNode.h"

using namespace std;

void morris_traversal(struct TreeNode *root){
	if( root == NULL )
		return;
	TreeNode *current = root, *pre;
	while( current != NULL ){
		if(current->left==NULL){
			printf("%d",current->val);
		}
		else{
			pre = current->left;
			while(pre->right!=NULL&&pre->right!=current){
				pre = pre->right;
			}
			if(pre->right==NULL){
				printf("%d", current->val);
				current = current->left;
			}
			else{
				pre->right = NULL;
				printf("%d", current->val);
				current = current->right;
			}
		}
	}
}