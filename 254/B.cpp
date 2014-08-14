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
#define MaxM 50*50*4
#define MaxN 100

vector<int> graph[MaxN];
int visited[MaxM],counter=0;

void dfs(int root)
{
	counter++;
	visited[root]= 1;
        for(vector<int>::iterator it = graph[root].begin();it!=graph[root].end();it++){
                if( visited[*it] )
                        continue;
                else{
                        dfs((*it));
                }
        }
}
void solve()
{
	ll answer = 1;
	ll pow[60];
	pow[0]= 1;
	for(int i=1;i<=60;i++)	pow[i] = pow[i-1]*2;
	int x,y,n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	memset(visited,0,sizeof(visited));
	for(int i=1;i<=n;i++){
		if(visited[i]==0){
			counter =0 ;
			dfs(i);
			answer = answer * pow[counter-1];
		}
	}
	printf("%lld\n",answer);
}

int main()
{
	solve();
	return 0;
}
