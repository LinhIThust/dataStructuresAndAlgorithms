#include<stdio.h>
#include<math.h>
#define MAX 8
int n,count;
int a[10][10];

void printfList(){
	count++;
	printf("cau hinh thu %d:\n",count);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%4d",a[i][j]);
		printf("\n");
	}
}

bool check(int q,int p){
//q la toa do cot cua hau hang p
for(int j=0;j<=p;j++)
	if(a[q][p-j]==1||a[q-1][p-1]==1||a[q+1][p-1]==1)//ktra xem 2 con hau cung hang va duong cheo khong
		return false;
	return true;


}

void backTracking(int k){
	int i;
	for(i=1;i<=n;i++){
		if(check(i,k)){
			a[i][k]=1;
			if (k==n) printfList();
				else backTracking(k+1);
	}
	a[i][k]=0;
	}
}

int main(){
n=MAX;
count =0;
backTracking(1);
}
