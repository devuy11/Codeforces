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
#define MaxN 100006

struct node
{
	map<int,int> mymap;
	int clean;
}dhinwa[(1<<18)];

int level , pow[23];
void constant()
{
	pow[0]=1;
	for(int i=1;i<=22;i++)	pow[i]=pow[i-1]*2;
	level =0;
}
void obtain(int N)
{
	while(N!=0){
		N/=2;
		level++;
	}
	if(pow[level]!=N)	level++;
}
map<int,int> merge (int node)
{
	map<int,int> dmap,umap;
	dmap = dhinwa[ node*2 ].mymap;
	umap = dhinwa[node*2+1].mymap;
	int x,y;
	for(map<int,int> ::iterator it = umap.begin();it!=umap.end();it++){
		x= *it;
		y = umap[ *it ] ;
		if ( dmap.count(x) ){
			dmap[x] += y;
		}
		else{
			dmap[x] = y;
		}
	}
	return dmap;
}
void init(int s,int e,int node)
{
	if(s==e){
		dhinwa[s].mymap[s] =1;
		return ;
	}
	init(s,(s+e)/2 , node*2);
	init(((s+e)/2)+1,e, node*2+1);
	dhinwa[node].mymap = merge(node);
}
void solve()
{
	ll c;
	int l,r;
	int n,m,x;
	scanf("%d%d",&n,&m);
	init(1,power[level-1]);
	for(int i=1;i<=m;i++){
		scanf("%d",&x);
		if(x==1){
			scanf("%d%d%lld",&l,&r,&c);
			Update(1,power[level-1],l,r,1);
		}
		else{
			scanf("%d%d",&l,&r);
			
		}
	}
}

int main()
{
	solve();
	return 0;
}
