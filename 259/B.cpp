#include<stdio.h>
#include<string.h>
#include<bitset>
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

/******************Slow Sieve******************/
#define upto 200
int slow_a[upto+1],prime[upto+1],counter;
void slow_sieve()
{	
	counter=0;
	memset(slow_a,1,sizeof(slow_a));			//initially say all are prime numbers
	for(int i=2;i<=upto;i++){
		if(slow_a[i]){						//if it is prime
			prime[counter]=i;				//save it
			counter++;
			if((ll)i*(ll)i>upto){			//start from i*i upto range
				continue;
			}
			for(int j=i*i;j<=upto;j+=i)
				slow_a[j]=0;
		}
	}
}
/****************End of Slow Sieve***********/
struct node{	
	int v,ind;
	bool operator < (const node &x) const{
		if ( v< x.v)	return true;
		else	return false;
	}
}in[101];
int N,where = 0,debug;
ll mini,ind ;
vector<int> all_solns[100];
void make_solution (int zeros , int j)
{
	where++;
	all_solns[where].clear();
	for(int k=1;k<=zeros;k++)	all_solns[where].push_back(1);
	if ( all_solns[where].size() == N)	return;
	for(int k=0;k<10;k++){
		if ( (j<<k)&1){
			all_solns[where].push_back(prime[k]);
			if ( all_solns[where].size() == N)	return;
		}
	}
	int s = 10;
	for(int k=all_solns[where].size();k<N;k++){
		all_solns[where].push_back(prime[s]);
		s++;
	}
}
void complete_solution()
{
	ll sum =0;
	for(int i=0;i<N;i++){
		sum += abs(all_solns[where][i] - in[i+1].v);
	}
	//if (debug ) {
		//for(int j=0;j<N;j++)	printf("%d ",all_solns[where][j]);
//		debug=0;
//	}
	if( sum < mini ){
		mini  = sum ;
 		ind = where;
		if(where>10){	
			swap(all_solns[where], all_solns[where-1]);
			where--;
 			ind = where;
		}
	}
	else{
		where--;
	}
}
void get(int i)
{
	if ( i==5)
	debug = 1;
		for(int j=0;j<1024;j++){
			make_solution( i - 1, j );
			complete_solution();
		}
}
int main()
{
	mini  = 1<<30;;
	mini = mini*mini;
	slow_sieve();
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d",&in[i].v);
		in[i].ind = i;
	}
	sort(in+1,in+N+1);
	where = 0;
	for(int i=0;i<=N;i++){
		get(i+1);
		//printf("%lld is mini\n",mini);
	}
	int B[101];
	for(int i=0;i<N;i++){	
		B[in[i+1].ind] = all_solns[ind][i];
		printf("%d ",all_solns[ind][i]);
	}
	printf("\n");
	for(int i=1;i<=N;i++)	printf("%d ",B[i]);
	printf("\n");
	return 0;
}
