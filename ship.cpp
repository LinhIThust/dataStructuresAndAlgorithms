#include <stdio.h>

#define MAX 100

int c[MAX][MAX];
int n;

int x[MAX];
bool mark[MAX];
int f;// tong do dai ca lo trinh

// luu thong tin cua lo trinh tot nhat
int x_best[MAX];
int f_best;

void readData(char* fn){
    FILE* f = fopen(fn,"r");
    fscanf(f,"%d",&n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            fscanf(f,"%d",&c[i][j]);
    }
    fclose(f);
}

bool check(int v, int i){
    return !mark[v];
}
void updateSolution(){
    printf("lo trinh hien tai: ");
    for(int i = 0; i < n; i++)
        printf("%d ",x[i]);
    printf(", khoang cach = %d\n",f + c[x[n-1]][x[0]]);

    if(f + c[x[n-1]][x[0]] < f_best){
        f_best = f + c[x[n-1]][x[0]];
        for(int i = 0; i < n; i++)
            x_best[i] = x[i];
    }
}
void TRY(int i){// thu gia tri cua x[i]
    int v;
    for(v = 1; v <= n-1; v++){
        if(check(v,i)){
            x[i] = v;
            mark[v] = true;
            f = f + c[x[i-1]][x[i]];
            if(i == n-1){
                updateSolution();
            }else{
                TRY(i+1);
            }
            f = f - c[x[i-1]][x[i]];
            mark[v] = false;
        }
    }
}
void printSolution(){
    for(int i = 0; i < n; i++){
        printf("%d -> ",x_best[i]);
    }
    printf("%d ",x_best[0]);
    printf(", khoang cach = %d\n",f_best);
}
int main(){
    readData("ship.txt");
    x[0] = 0;
    mark[x[0]] = true;
    f = 0;
    f_best = 999999999;
    for(int v = 1; v <= n-1; v++)
        mark[v] = false;
    TRY(1);
    printSolution();
}
