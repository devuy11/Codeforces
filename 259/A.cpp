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
double binpow(double x,int N)
{	
	double answer =1;
	while(N!=0){
		if ( N&1){
			answer = answer*x;
			N--;
		}
		else{
			x=x*x;
			N>>=1;
		}
	}
	return answer;
}

int main()
{
	int M,N;
	scanf("%d%d",&M,&N);
	double answer = M;
	for(int i=1;i<M;i++){
		answer = answer - binpow( (double)i/M , N);
	}
	printf("%lf\n",answer);
	return 0;
}
