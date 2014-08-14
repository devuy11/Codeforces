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
#include <iomanip> 
#include<utility>
using namespace std;

typedef long long int ll;

#define FOR(i,s,e) for(int i=(s);i<(e);i++)
#define mp(a,b) make_pair((a),(b))
#define sint(a) scanf("%d",&(a))
#define sll(a)  scanf("%lld",&(a))
#define sd(a)   scanf("%lf",&(a))

void solve()
{
	int x,y,node[501],v;
	int n,m;
	scanf("%d%d",&n,&m);
	double answer = 0;
	for(int i=1;i<=n;i++)	scanf("%d",&node[i]);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&v);
		answer = max(answer , (double)(node[x]+node[y]) / (double)v);
	}
	cout << setprecision(12) << answer << '\n';
}

int main()
{
	solve();
	return 0;
}
