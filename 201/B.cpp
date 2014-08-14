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

#define For(i,s,e) for(int i=(s);i<=(e);i++)
#define mp(a,b)	make_pair((a),(b))

void solve()
{
	int A[100002],N;
	scanf("%d",&N);
	int answer = 0;
	for(int i=0;i<N;i++){
		scanf("%d",&A[i]);
		if(A[i]==i)	answer++;
	}
	int i;
	for(i=0;i<N;i++){
		if(A[i]!=i){
			if(A[A[i]] == i){
				answer += 2;
				break;
			}
		}
	}
	if(i==N && answer!=N)	answer ++ ;
	printf("%d\n",answer);
}

int main()
{
	solve();
	return 0;
}
