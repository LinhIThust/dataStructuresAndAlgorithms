//liet ke to hop
//ham check
#include<stdio.h>
int n,count;
int m;
int a[100];

void printfList(){
	count++;
	printf("hoan vi thu %d:",count);
	for(int i=1;i<=m;i++){
		printf("%3d",a[i]);
	}
	printf("\n");
}


bool check(int i,int v){
	if(a[i-1]<v) return true;
		else return false;
}

void backTracking(int k){
	int i;
	//for(int i=a[k-1]+1;i<=n-m+k;i++){
	for(i=1;i<=n;i++){
		if(check(k,i)){
			a[k] =i;
			if(k==m) {
					printfList();
			}else{
				backTracking(k+1);
			}
		}
	}
}


int main(){
n=14;
m=7;
count=0;
backTracking(1);

}
