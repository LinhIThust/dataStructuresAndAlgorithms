#include <stdio.h>

struct Node{
	int key;
	Node* left;
	Node* right;
};

Node * root;



Node* makeNode(int x){
	Node*p = new Node;
	p->key = x;
	p->left=NULL;
	p->right=NULL;
	return p;
}

Node* insertTree(Node*r,int x){
	if(r==NULL)
		return r=makeNode(x);




}

int main(){
}