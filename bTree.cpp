#include <iostream>
#include <cstdlib>

using namespace std;

class BTreeNode {
	
	public:
		int *values;
		int minDegree;
		int numKeys;
		BTreeNode **child;
		bool leaf;
		
		BTreeNode(int md , bool l);
		void insertAvalable(int number);
		void split(int childIndex , BTreeNode* node);
		bool search(int find); 
		void printBTree();
		
		
};

class BTree {
	
		
	public:
		BTreeNode *root;
		int minDegree;
	
		BTree(int md){
			root = NULL; 
			minDegree = md; 
		}
		
		void insert(int number);
		
		bool search(int find){
			return root->search(find);
		}
		
		void printBTree(){
			if(root != NULL){  
				root->printBTree();
			}
		}
		
};


BTreeNode::BTreeNode(int md , bool l){
	
	minDegree = md;
	leaf = l;
	
	values = new int[2*minDegree-1];
	child = new BTreeNode *[2*minDegree];
	
	numKeys = 0;
		
}

void BTree::insert(int number){
	
	if(root == NULL){
		root = new BTreeNode(minDegree , true);
		root->values[0] = number;
		root->numKeys = 1;
	}
	
	else if(root != NULL){
		
		if(root->numKeys == 2*minDegree-1){
			
			BTreeNode *node = new BTreeNode(minDegree , false);
			node->child[0] = root;
			node->split(0 , root);
			
			int index = 0;
			if(node->values[0] < number){
				index++;
			}
			
			node->child[index]->insertAvalable(number);
			
			root = node;
						
		}
		
		else{
			
			root->insertAvalable(number);
		
		}
		
	}

}



void BTreeNode::insertAvalable(int number){
	
	int index = numKeys-1;
	
	if(leaf == true){
		
		while(index >= 0 && values[index] > number){
		
			values[index+1] = values[index];
			index--;
			
		}
		
		values[index+1] = number;
		numKeys++;
			
	}
	
	else if(leaf == false){
			
		while(index >= 0 && values[index] > number){
			index--;	
		}
		
		if(child[index+1]->numKeys == 2*minDegree-1){
			
			split(index+1 , child[index+1]);
			
			if(values[index+1] < number){
				index++;
			}
			
		}
		
		child[index+1]->insertAvalable(number);
		
	}
	
}


void BTreeNode::split(int childIndex , BTreeNode *node){
	
	BTreeNode *node2 = new BTreeNode(node->minDegree , node->leaf);
	node2->numKeys = minDegree-1;
	
	for(int i=0; i<minDegree-1; i++){
		node2->values[i] = node->values[i+minDegree];
	}
	
	if(node->leaf == false){
		for(int i=0; i<minDegree; i++){
			node2->child[i] = node->child[i+minDegree];
		}
	}
	
	node->numKeys = minDegree-1;
	
	for(int i=numKeys; i>=childIndex+1; i--){
		child[i+1] = child[i];
	}
	
	child[childIndex+1] = node2;
	
	for(int i=numKeys-1; i>=childIndex; i--){
		values[i+1] = values[i];
	}
	
	values[childIndex] = node->values[minDegree-1];
	
	numKeys++;
	
}


bool BTreeNode::search(int find){

	int index = 0;
	while(index < numKeys && find > values[index]){
		index++;
	}
	
	if(values[index] == find){
		return true;
	}
	
	else if(leaf == true){
		return false;
	}
	
	return child[index]->search(find);
	
}


void BTreeNode::printBTree(){
	
	int i;
	
	cout << endl;
	
	for(i=0; i < numKeys; i++){
		if(leaf == false){
			child[i]->printBTree();
		}
		
		cout << " " << values[i];
		
	}
	
	if(leaf == false){
		child[i]->printBTree();
	}
	
	cout << endl;
		
}





int main(){
	
	BTree bTree(3);
	int elements = 0;
	int c = 0;


	while(elements < 400){
		cout << "Enter number of elements you want in the B-Tree (400+):  ";
		cin >> elements;
	}
	
	for(int i=0; i<elements; i++){
		bTree.insert( (rand() % (elements*3)) + 1 );
	}
	
	
	//prints the B-Tree & search results
	cout << "---------------------------B-TREE OF " << elements << " ELEMENTS--------------------------- " << endl;
	bTree.printBTree();
	
	cout << "---------------------------SEARCH FROM " << elements << " TO " << (elements*2) << "--------------------------- " << endl;
	for(int i=elements; i<(elements*2); i++){
		if(bTree.search(i) == true){
			cout << i << " ";
			c++;
		}
		
		if(c == 10){
			cout << endl;
			c = 0;
		}
	}
	
	cout << endl;
	
	
}