#include<stdio.h>
#include<bitset>
#include<string.h>
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
#define pi(x) printf("%d",(x))
#define pe() printf("\n")
#define ps() printf(" ")
#define si(x) scanf("%d",&(x))
#define MaxN 300009
#define Log 19
struct suff{
	int nr[2];
	int p;
}L[MaxN];
int P[Log][MaxN];
int cmp(suff a,suff b)
{
	return a.nr[0]==b.nr[0] ?(a.nr[1]<b.nr[1] ?1: 0): (a.nr[0]<b.nr[0] ?1: 0);
}
void suffix(string A)
{
	int l = A.size();
	for(int i=0;i<l;i++)	P[0][i] = A[i]-'a';
	for(int step=1,cnt=1;cnt<l;step++,cnt*=2){
		for(int i=0;i<l;i++)
		{
			L[i].nr[0] = P[step-1][i];
			L[i].nr[1] = i+cnt < l ? P[step-1][i+cnt]:-1;
			L[i].p = i;
		}
		sort(L,L+l,cmp);
		for(int i=0;i<l;i++)
			P[step][L[i].p]=i>0 && L[i].nr[0]==L[i-1].nr[0] && L[i].nr[1]==L[i-1].nr[1] ? P[step][L[i-1].p]:i;
	}
}
int power[30];
int FindLcp(int x,int y,int s)
{
	int answer = 0;
	for(int k = s;k>=0;k--){
		if (P[k][x] == P[k][y]){
			answer += power[k];
			x += power[k];
			y += power[k];
		}
	}
	return answer;
}
void solve(string A)
{
	power[0] = 1;
	for(int i=1;i<=24;i++)	power[i]=power[i-1]<<1;
	suffix(A);
	int l = A.size();
	int s=0,k=l;
	while(k!=0){
		k/=2;
		s++;
	}
	for(int i=0;i<l-1;i++){
		printf("%d ",FindLcp(L[i].p,L[i+1].p,s));
	}
	//for(int i=0;i<A.size();i++)	printf("%d ",L[i].p);
}
int main()
{
	string A,B,C;
	cin>>A>>B>>C;
	A = A+"{"+B+"|"+C;
	solve(A);
	return 0;
}
