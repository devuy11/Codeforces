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

char flip(char a)
{
	if( a=='W')	return 'B';
	else	return 'W';
}
void solve()
{
	char in[101][101];
	char a,b='B';
	int n,m;
	scanf("%d%d",&n,&m);
	int sx=1,sy=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf(" %c",&a);	
			in[i][j] = a;
			if (a=='.'){
				sx  = i;
				sy = j;
			}
		}	
	}
//	printf(" %c is b\n",b);	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if( in[i][j] == '-'){
				printf("-");
				continue;
			}
			if( ( abs(i-sx) + abs(j-sy) ) & 1 ) {
				printf("%c",flip(b));
			}
			else	printf("%c",b);
		}
		printf("\n");
	}
}

int main()
{
	solve();
	return 0;
}
