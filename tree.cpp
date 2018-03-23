#include <stdio.h>
#include <stack>

using namespace std;

struct Node{
    int id;
    Node* leftMostChild;
    Node* rightSibling;
};

Node* root;

Node* find(Node* r, int v){
    if(r == NULL) return NULL;
    if(r->id == v) return r;
    Node* p = r->leftMostChild;
    while(p != NULL){
        Node* h = find(p,v);
        if(h != NULL) return h;
        p = p->rightSibling;
    }
}

Node* makeNode(int v){
    Node* p = new Node;
    p->id = v;
    p->leftMostChild = NULL;
    p->rightSibling = NULL;
    return p;
}
void printTree(Node* r){
    if(r == NULL) return;
    printf("Nut %d: ",r->id);
    Node* p = r->leftMostChild;
    while(p != NULL){
        printf("%d ",p->id);
        p = p->rightSibling;
    }
    printf("\n");

    p = r->leftMostChild;
    while(p != NULL){
        printTree(p);
        p = p->rightSibling;
    }
}

void insertLast(Node* p, int id){
    //TODO
    Node* q = p->leftMostChild;
    if(q == NULL){
        p->leftMostChild = makeNode(id);
        return;
    }
    while(q->rightSibling != NULL)
        q = q->rightSibling;
    q->rightSibling = makeNode(id);
}

int count(Node* r){
    if(r == NULL) return 0;
    int c = 1;
    Node* p = r->leftMostChild;
    while(p != NULL){
        c = c + count(p);
        p = p->rightSibling;
    }
    return c;
}
int countLeaves(Node* r){
    if(r == NULL) return 0;
    int c = 0;
    Node* p = r->leftMostChild;
    if(p == NULL) return 1;
    while(p != NULL){
        c = c + countLeaves(p);
        p = p->rightSibling;
    }
    return c;
}
void preOrder(Node* r){
    if(r ==  NULL) return;
    printf("%d, ",r->id);
    Node* p = r->leftMostChild;
    while(p != NULL){
        preOrder(p);
        p = p->rightSibling;
    }
}
void inOrder(Node* r){
    if(r == NULL) return;
    Node* p = r->leftMostChild;

    inOrder(p);
    printf("%d, ",r->id);
    if(p == NULL) return;
    p = p->rightSibling;
    while(p != NULL){
        inOrder(p);
        p = p->rightSibling;
    }

}
void postOrder(Node* r){
    if(r == NULL) return;
    Node* p = r->leftMostChild;
    while(p != NULL){
        postOrder(p);
        p = p->rightSibling;
    }
    printf("%d, ",r->id);
}
int height(Node* r, Node* p){
    int m = 0;
    if(p == NULL) return 0;
    Node* q = p->leftMostChild;
    while(q != NULL){
        int h = height(r, q);
        if(h > m) m = h;
        q = q->rightSibling;
    }
    return m+1;
}

int depth(Node* r, Node* p){
    if (r == NULL) return -1;
    if (p == r) return 0;
    Node * x = r->leftMostChild;
    while(x != NULL)
    {
        int d = depth(x,p);
        if(d>=0) return d+1;
        x = x->rightSibling;
    }
    return -1;
}
Node* parent(Node* r, Node* p){
    if(r == NULL) return NULL;
    if(p == r) return NULL;
    Node* q = r->leftMostChild;
    while(q != NULL){
        if(q == p) return r;
        Node* pp = parent(q,p);
        if(pp != NULL) return pp;
        q = q->rightSibling;
    }
    return NULL;
}

void printPath(Node* r, Node* p){
    if(p == NULL || r == NULL){
        printf("KHONG CO DUONG DI\n");
        return;
    }
    stack<Node*> S;
    S.push(p);
    //if(p != r)
        while(1){
        p = parent(r,p);
        if(p != NULL) S.push(p);
        if(p == r) break;
    }
    while(!S.empty()){
        Node* q = S.top(); S.pop();
        printf("%d ",q->id);
    }
}
int main(){
    root = makeNode(10);
    insertLast(root,11);
    insertLast(root,1);
    insertLast(root,3);
    Node* p = find(root,11);
    insertLast(p,5);
    insertLast(p,4);

    p = find(root,3);
    insertLast(p,8);
    insertLast(p,2);
    insertLast(p,7);

    p = find(root,4);
    insertLast(p,6);
    insertLast(p,9);

    printTree(root);
    printf("So nut tren cay la %d\n",countLeaves(root));
    printf("Thu tu sau: ");postOrder(root);

    printf("\n");
    p = find(root,100);
    printf("Do cao = %d\n",depth(root,p));

    Node* pp = parent(root,p);
    if(pp == NULL) printf("KHONG TIM THAY NUT CHA\n");
    else printf("Nut cha la %d\n",pp->id);

    printPath(root,p);
}
