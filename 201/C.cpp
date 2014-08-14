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

int gcd(int a,int b)
{
	if(b==0)	return a;
	return gcd(b,a%b);
}

void solve()
{
	int g =0 , m=0;
	int N,A[101];
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d",&A[i]);
		m = max(m,A[i]);
		g = gcd(g, A[i]);
	}
	int steps = (m/g) - N;
	if( steps & 1){
		printf("Alice\n");
	}
	else{
		printf("Bob\n");
	}
}

int main()
{
	solve();
	return 0;
}
