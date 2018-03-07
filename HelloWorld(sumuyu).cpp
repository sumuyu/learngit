#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 10000
typedef struct{
	int key;
}RecordType;
typedef struct{
	RecordType R[MAXSIZE+1];
	int length;
}SqList; 
int a[10000];
int m,n;
void ShellInsertB(SqList &L,int incr){
	int i,j;
	for(i=incr+1;i<L.length;i++)
	if(L.R[i].key<L.R[i-incr].key){
		L.R[0]=L.R[i];
		for(j=i-incr;j>0&&L.R[0].key<L.R[j].key;j-=incr)
		L.R[j+incr]=L.R[j];
		L.R[j+incr]=L.R[0];
	}
}
void ShellSortA(SqList &L){
	int i,j;
	for(i=0;i<n;i++){
	ShellInsertB(L,a[i]);
	for(j=1;j<=m;j++)
	printf("%d ",L.R[j].key);
	printf("\n");
	}
}

int main(){
	scanf("%d %d",&m,&n);
	int i,j;
	SqList L;
	L.length=m+1;
	for(i=1;i<=m;i++)
	scanf("%d",&L.R[i].key);
	for(j=0;j<n;j++)
	scanf("%d",&a[j]);
	ShellSortA(L);
}
