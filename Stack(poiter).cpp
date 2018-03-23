#include <iostream>
#define f(i,a,b) for(int i=a; i<=b; i++)
using namespace std;
struct Node{
	int v;
	Node* pre;
};

Node* top ;

void PUSH(int x){
	Node* p = new Node;
	p->v = x;
	p->pre = top;
	top =p;
}

int POP() {
	if (top == NULL) return -1;
	int x = top->v;
	Node* tmp = top;
	top = top->pre;
	delete(tmp);
	return x;
}


int main(){
    f(i,1,10)
		PUSH(i);

	f(i,1,11)
		cout << POP() << endl;
}