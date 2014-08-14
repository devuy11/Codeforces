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
#include<deque>
using namespace std;

typedef long long int ll;

#define For(i,s,e) for(int i=(s);i<=(e);i++)
#define mp(a,b)	make_pair((a),(b))
#define pi(x) printf("%d",(x))
#define pe() printf("\n")
#define ps() printf(" ")
#define si(x) scanf("%d",&(x))
#define pii pair<int,int> 
#define MaxN 300*335
#define csize 300
#define tb MaxN/csize

deque<int> A[tb];
int out[tb];
int arr[tb][100001];
int N,Q,a[MaxN];
void init()
{
	int t=1;
	For(i,1,N){
		A[t].clear();
		for(int j=1;j<=csize;j++){
			A[t].push_back(a[i]);
			arr[t][a[i]]++;
			i++;
		}
		t++;
		i--;
	}
}
int process_bk(int s,int e,int k,int p)
{
	int answer = 0;
	deque<int> bk = A[p];
	e = e - s +1;
	int st = 1;
	while( st!=s ) bk.pop_front(),st++;
	st=0;
	while(st!=e){
		if ( bk.front() == k ) answer++;
		bk.pop_front();
		st++;
	}
	return answer;
}
int query(int l,int r,int k)
{
	int s= (l-1)/csize+2 , e = (r-1)/csize,answer=0;
	for(int i=s;i<=e;i++)	answer += arr[i][k];
	if ( (l-1)/csize == (r-1)/csize ){
		answer = answer + process_bk(l-((l-1)/csize)*csize , r-((r-1)/csize)*csize ,k , (l-1)/csize+1);
	}
	else{
		answer = answer + process_bk(l-((l-1)/csize)*csize , csize ,k , (l-1)/csize+1);
		answer = answer + process_bk(1, r-((r-1)/csize)*csize ,k , (r-1)/csize+1);
	}
	return answer;
}
void ppp(deque<int> a3)
{
	deque<int> a2 = a3;
    while(!a2.empty())  pi(a2.front()),ps(),a2.pop_front();
	pe();
}
int mergeM(int p1,int p2,int s1,int e1)
{
	deque<int> x,y;
	int s=1;
	while(s!=s1){
		x.push_back(A[p1].front());
		A[p1].pop_front();
		s++;
	}
	int e=csize;
	while(e!=e1){
		y.push_front(A[p2].back());
		A[p2].pop_back();
		e--;
	}
	int ret = A[p2].back();
	if ( p1 == p2 ){
		A[p1].push_front(ret);
		A[p1].pop_back();
		while(!A[p1].empty()){
			x.push_back(A[p1].front());
			A[p1].pop_front();
		}
		while(!y.empty()){
			x.push_back(y.front());
			y.pop_front();
		}
		A[p1]= x;
		return ret;
	}
	A[p1].push_front(ret);
	A[p2].pop_back();
	A[p2].push_front(out[p2-1]);
	A[p1].pop_back();
	while(!A[p1].empty()){
		x.push_back(A[p1].front());
		A[p1].pop_front();
	}
	while(!A[p2].empty()){
		y.push_front(A[p2].back());
        A[p2].pop_back();
	}
	A[p1] = x,A[p2] = y;
	return ret;
}
void update(int l,int r)
{
	int s= (l-1)/csize+2 , e = (r-1)/csize;
	out[s-1] = A[s-1].back();
	for(int i=s;i<=e;i++){
		out[i] = A[i].back();
		A[i].push_front(out[i-1]);
		A[i].pop_back();
	}
	out[e+1] = mergeM((l-1)/csize+1 , (r-1)/csize+1 ,l-((l-1)/csize)*csize, r-((r-1)/csize)*csize);//p1,p2,s1,e1
	for(int i=s-1;i<=e+1;i++){
		assert(out[i]>=0);
		arr[i][out[i]]--;
	}
	out[s-2] = out[e+1];	
	for(int i=s-1;i<=e+1;i++){
		arr[i][out[i-1]]++;
	}
}
int main()
{
	memset(arr,0,sizeof(arr));
	si(N);
	int ON = N;
	For(i,1,N){
		si(a[i]);
	}
	if ( N%csize !=0 ){
		for( int i = N+1 ;i<=(((N-1)/csize)+1)*csize ;i++)	a[i] = 0;
		N = (((N-1)/csize)+1)*csize;
	}
	init();
	int Q,x,l,r,k=0,ans=0;
	si(Q);
	For(i,1,Q){
		si(x);si(l);si(r);
		if ( x==2 )	si(k);

		l = ((l+ans-1)%ON)+1;
		r = ((r+ans-1)%ON)+1;
		k = ((k+ans-1)%ON)+1;

		if (l>r)	swap(l,r);
		if ( x==1)	update(l,r);
		else{
			ans=query(l,r,k);
			pi(ans);pe();
		}
	}
	return 0;
}
