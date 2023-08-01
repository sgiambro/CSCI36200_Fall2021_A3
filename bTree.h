//bTree.h

#ifndef BTREE_H_EXISTS
#define BTREE_H_EXISTS

#include <iostream>
#include <string>

class BTreeNode {
	
	public:
		int *values;
		int numKeys;
		BTreeNode **child;
		bool leaf;
		
		int* sort(int *arr , int size);
		
		
};

class BTree {
	
		
	public:
		BTreeNode* root;
	
		BTree();
		void insert(BTreeNode* root , int number);
		//void insert(BTreeNode* node , int number);
		void printBTree(BTreeNode* node);
		
};


/** The grave of all my hopes and dreams

if(root->leaf == true && root->numKeys < 5){
		
		root->values[root->numKeys] = number;
		root->numKeys++;
		
		root->values = root->sort(root->values , root->numKeys);
		
		if(root->numKeys == 5){
			root->leaf = false;
			root->numKeys = 1;
			int mid = root->values[2];
			
			BTreeNode* leftNode;
			leftNode->values[0] = root->values[0];
			leftNode->values[1] = root->values[1];
			leftNode->numKeys = 2;
			leftNode->leaf = true;
			leftNode->child = new BTreeNode *[6];
			
			root->child[0] = leftNode;
			
			BTreeNode* rightNode;
			rightNode->values[3] = root->values[3];
			rightNode->values[4] = root->values[4];
			rightNode->numKeys = 2;
			rightNode->leaf = true;
			rightNode->child = new BTreeNode *[6];
			
			root->child[1] = rightNode;
			
			for(int i=0; i<6; i++){
				root->values[i] = NULL;
			}
			
			root->values[0] = mid;
			
		}
		
	}
	
	else if(root->leaf == false){
		
		cout << "Leaf false" << endl;
		
	}
	
**/


#endif
