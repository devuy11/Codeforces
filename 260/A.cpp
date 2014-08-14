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

ll S[100003];
ll dp[100003];
ll max_s(int i,int j)
{
	//printf("%d %d\n",i,j);
	int s = j-i;
	//for(int k=0;k<=s;k++)	dp[k] = 0;
	dp[s+1] = 0 ;
	dp[s] = S[j]*(ll)j;
	ll answer = dp[s];
	for(int k=s-1;k>=0;k--){
		dp[k] = max(dp[k+1] , S[k+i]*(ll)(i+k) + dp[k+2]);
	}
	return dp[0];
}
int main()
{
	memset(S,0,sizeof(S));
	int N,x,st=12019219;
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d",&x);
		st = min ( st, x);
		S[x] ++;
	}
	ll answer =0;
	int s = st;
	for(int i=st;i<=100001;i++){
		if ( S[i] == 0 ){
			answer = answer + max_s (st,i-1);
			while(S[i] == 0){
				i++;
			}
			st = i;
			i--;
		}
	}
	printf("%lld\n",answer);
	return 0;
}
