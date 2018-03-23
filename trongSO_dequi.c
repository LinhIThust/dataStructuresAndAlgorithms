#include<stdio.h>
#define MAX 1000000
int a[MAX],i,j,n,sum=0,maxSum=-11111111,k,m;
int max(int a,int b,int c){
	int max = a;
	if (b>max) max =b;
	if( c>max) max = c;
return max;
}
 int maxLeft (int a[MAX] , int i , int j) {
	for( k= j;k>= i;k--){
		sum =sum + a[k] ;
		if( sum >maxSum) maxSum = sum;
	}
return maxSum;
 }
 int maxRight(int a[MAX] , int i , int j) {
	for( k= i;k< j;k++){
		sum =sum + a[k] ;
		if( sum >maxSum) maxSum = sum;
	}
return maxSum;
 }
 int maxSub(int a[MAX] , int i , int j){
 	int x4;
	if(i=j) return a[i];
	else{
		m = (i+j)/2;
		int x1= maxSub(a,i,m);
		int x2 = maxSub(a,m+1,j);
		int x3 = maxLeft(a,i,m)+maxRight(a,m+1,j);
		 x4= max(x1,x2,x3);
	}
return x4;

 }
int main()
{

	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int x5 =maxSub(a,0,n);
	printf("trong so la : %d",x5);
return 0;


}