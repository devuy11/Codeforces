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
int find(int s,int e)
{
	return s+rand()%(e-s+1);
}

int main()
{
	int N=601,Q=30123,x=2;
	pi(N);pe();
	For(i,1,N)	pi(find(1,N)),ps();
	pe();
	pi(Q);pe();
	For(i,1,Q){
		if (find(0,1))	pi(x-1),ps(),pi(find(1,N)),ps(),pi(find(1,N)),pe();
		else	pi(x),ps(),pi(find(1,N)),ps(),pi(find(1,N)),ps(),pi(find(1,N)),pe();
	}
	return 0;
}
