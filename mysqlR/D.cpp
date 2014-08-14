#include<stdio.h>
#include<queue>
using namespace std;
int main()
{
	int answer,k,n1,n2,n3,t1,t2,t3;
	scanf("%d%d%d%d%d%d%d",&k,&n1,&n2,&n3,&t1,&t2,&t3);
	queue<int> F,S,T;
	int t=0;
	for(int i=1;i<=k;i++){
			while(!F.empty())	if(F.front() >= t)	F.pop();
			while(!S.empty())	if(S.front() >= t)	S.pop();
			while(!T.empty())	if(T.front() >= t)	T.pop();
			if ( 
	}

	return 0;
}
