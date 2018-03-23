#include <stdio.h>

int n;
int M;
int x[100];
int S;
int count;
void printSolution(){
    count++;
    printf("configuration %d: ",count);
    for(int i = 1; i <= n; i++) printf("%d ",x[i]);
    printf("\n");
}
void TRY(int i){
    int v;
    for(v = 1; v <= M; v++){
        x[i] = v;
        S += x[i];// update incrementally
        if(i == n){
            if(S == M) printSolution();
        }else{
            TRY(i+1);
        }
        S -= x[i];// recover trang thai

    }
}

void newTry(int m, int n){
    int i;
    if(n == 1){
        x[n] = m;
        printSolution();
    }else{
        for(i = 1; i <= m-n+1; i++){
            x[n] = i;
            newTry(m-i,n-1);
        }
    }
}

int main(){
    M = 10;
    n = 3;
    S = 0;
    count = 0;
    //TRY(1);
    newTry(M,n);
}
