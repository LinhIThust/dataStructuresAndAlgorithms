#include<bits/stdc++.h>
using namespace std;

struct Node{
	int value;
	Node* pre;
};
Node* top;

//put the data into the stack
Node* PUSH(int x,Node*t){
	Node* p = new Node;
	p->value =x;
	p->pre =t;
	t= p;
}

//Get data out of the stack
void POP(){
	if(!top) return;
	Node* q = new Node;
	//int popData= top->value;
	q=top;
	top=top->pre;
	delete q;
	//return popData;
}
//Accesses the element at the top of the stack
int TOP(Node*t){
	if(!t) return -1;
	return t->value;
}
//Check empty Stack?
bool EMPTY(Node*t){
	if(!t) return true;
	return false;
}
void displayStack(Node*t){
	Node* p = t;
	if(!p) cout<<-1;
	while(p){
		cout<<p->value;
		p=p->pre;
	}
	cout<<endl;
}
int main(){
	for(int  i = 0;i<10;i++)
		top=PUSH(i,top);
	displayStack(top);
	for(int i=0;i<7;i++)
		POP();
	displayStack(top);
	cout<<TOP(top);
}