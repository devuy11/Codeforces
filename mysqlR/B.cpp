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
#include<math.h>
using namespace std;

typedef long long int ll;

#define For(i,s,e) for(int i=(s);i<=(e);i++)
#define mp(a,b)	make_pair((a),(b))

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	if(n==0){
		printf("0 1\n");
		printf("0 %d\n",m);
		printf("0 0\n");
		printf("0 %d\n",m-1);
	}
	else if(m==0){
		printf("1 0\n");
		printf("%d 0\n",n);
		printf("0 0\n");
		printf("%d 0\n",n-1);
	}
	else if (n>=m){
		double E1 , E2 ;
		E1 = 2*sqrt(n*n + (m-1)*(m-1)) + sqrt(n*n + m*m);
		E2 = 2*sqrt(n*n + m*m ) + n ;
		if ( E1> E2){
			printf("0 1\n");
			printf("%d %d\n",n,m);
			printf("0 0\n");
			printf("%d %d\n",n,m-1);
		}
		else{
			printf("0 0\n");
			printf("%d %d\n",n,m);
			printf("0 %d\n",m);
			printf("%d 0\n",n);
		}
	}
	else{
		double E1 , E2 ;
		swap(n,m);
		E1 = 2*sqrt(n*n + (m-1)*(m-1)) + sqrt(n*n + m*m);
		E2 = 2*sqrt(n*n + m*m ) + n ;
		swap(n,m);
		if ( E1> E2){
			printf("1 0\n");
			printf("%d %d\n",n,m);
			printf("0 0\n");
			printf("%d %d\n",n-1,m);
		}
		else{
			printf("0 0\n");
			printf("%d %d\n",n,m);
			printf("%d 0\n",n);
			printf("0 %d\n",m);
		}
	}
	return 0;
}
