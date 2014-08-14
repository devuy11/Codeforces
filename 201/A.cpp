#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<assert.h>
#include<utility>
using namespace std;

typedef long long int ll;

#define For(i,s,e) for(int i=(s);i<(e);i++)
#define mp(a,b)	make_pair((a),(b))

int main()
{
	int A[100001];
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d",&A[i]);
	}
	sort(A+1,A+N+1);
	swap(A[1],A[N]);
	for(int i=1;i<=N;i++){
		printf("%d ",A[i]);
	}
	printf("\n");
	return 0;
}
