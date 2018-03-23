#include <stdio.h>
#define MAX 100

int x[MAX];// modelling
int n;

bool check(int v, int k){
    for(int i = 1; i <= k-1; i++){
        if(x[i] == v) return false;
        if(x[i] + i == v + k) return false;
        if(x[i] - i == v - k) return false;
    }
    return true;
}
void printSolution(){
    FILE* f = fopen("queen.html","w");
    fprintf(f,"<table border=1>");
    for(int i = 1; i <= n; i++){
        fprintf(f,"<tr>");
        for(int j = 1; j <= n; j++){
            if(i == x[j])
                fprintf(f,"<td width=20 height=20 bgcolor='red'></td>");
            else
                fprintf(f,"<td width=20 height=20 bgcolor='blue'></td>");
        }
        fprintf(f,"</tr>");
    }
    fprintf(f,"</table>");
    fclose(f);
}
void TRY(int k){// thu gia tri cho x[k] khj da biet x[1,..,k-1]
    int v;
    for(v = 1; v <= n; v++){
        if(check(v,k)){
            x[k] = v;
            if(k == n){
                printSolution();
            }else{
                TRY(k+1);
            }
        }
    }
}

int main(){
    n = 5;
    TRY(1);
}
