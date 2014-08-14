#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
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

#define FOR(i,s,e) for(int i=(s);i<(e);i++)
#define mp(a,b) make_pair((a),(b))
#define sint(a) scanf("%d",&(a))
#define sll(a)  scanf("%lld",&(a))
#define sd(a)   scanf("%lf",&(a))
#define MaxN 100008

ll a[MaxN],b[MaxN];
ll n,d,x;

ll getNextX() {
	x = (x * 37 + 10007) % 1000000007;
	return x;
}
void initAB() {
	int i;
	for(i = 0; i < n; i = i + 1){
		a[i] = i + 1;
	}
	for(i = 0; i < n; i = i + 1){
		swap(a[i], a[getNextX() % (i + 1)]);
	}
	for(i = 0; i < n; i = i + 1){
		if (i < d)
			b[i] = 1;
		else
			b[i] = 0;
	}
	for(i = 0; i < n; i = i + 1){
		swap(b[i], b[getNextX() % (i + 1)]);
	}
}
void printAB()
{
	for(int i=0;i<n;i++)    printf("%lld ",a[i]);
	printf("\n");
	for(int i=0;i<n;i++)    printf("%lld ",b[i]);
	printf("\n");
}
void solve()
{
	scanf("%lld%lld%lld",&n,&d,&x);
	initAB();
	printAB();
}

int main()
{
	solve();
	return 0;
}
