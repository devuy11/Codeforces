//Correct code for E.
#include<stdio.h>
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
#define MaxVal 100008

struct TT{
	ll a,b;
	TT(ll x = 0 , ll y= 0){
		a = x;
		b = y;
	}
	TT operator + (const struct TT &m) const{
		return TT(a+m.a , b+m.b); 
	}
} tree[1<<18];

struct node{
	int l,r;
	ll x;
	node(int a = 0, int b=0 ,ll c=0){
		l = a;
		r = b;
		x = c;
	}
	bool operator < (const struct node &m ) const{
		return l<m.l;
	}
};

set<node> myset;
int n,m;

void init()
{
	myset.insert(node(0,0,0));
	myset.insert(node(n+2,0,0));
	for(int i=1;i<=n;i++){
		myset.insert(node(i,i,i));
	}
}
void print()
{
	for(set<node> :: iterator it = myset.begin();it!=myset.end();it++){
		printf("%d %d %lld\n",(*it).l,(*it).r, (*it).x);
	}
}

void updateT(int ind,ll v)
{
	//printf("%d is ind and %lld is v\n",ind,v);
	TT add = TT( (ll)(-ind+1)*v , (ll)v);
	while(ind<=MaxVal){
		tree[ind] = tree[ind] + add;
		ind+=(ind&-ind);
	}
}
void update(int l,int r,ll x)
{
	updateT(l,x);
	updateT(r+1,-x);
}
TT read(int ind)
{
	TT sum =0 ;
	//printf("%d is ind\n",ind);
	while(ind!=0){
		sum = sum + tree[ind];
		ind = ind - (ind&-ind);
	}
	//printf("%lld %lld\n",sum.a,sum.b);
	return sum;
}
void Update(int l,int r,ll x)
{
	node a[2];
	int yes[2]={0,0};;
	int counter = 0;
	set<node> :: iterator f1,f2,arr[2];
	f1 = myset.lower_bound(l);
	f2 = myset.lower_bound(r);
	f1--;
	f2++;
	int e1,e2;
	for(set<node> :: iterator it = f1;it!=f2;it++){
		if ( !( (*it).r < l  || (*it).l > r ) ){
			arr[counter] = it;
			if (counter==0)	counter=1;
			arr[counter] = it;
	                //printf("%d %d %lld\n",(*it).l,(*it).r, (*it).x);
			// bit update here please...
			if ( (*it).l >=l && (*it).l <= r)	e1= (*it).l;
			else{
				//yes[0]=1;
				//a[0] = node((*it).l , l-1, (*it).x);
				e1  = l;
			}
			if ((*it).r >=l && (*it).r <= r)       e2= (*it).r;
			else{	
				//yes[1]=1;
				//a[1] = node(r+1 ,(*it).r , (*it).x);
                                e2  = r;
			}
			if( (*it).l < l){
				yes[0]  = 1;
				a[0] = node( (*it).l , l-1, (*it).x);
			}
			if ( (*it).r > r){
				yes[1]= 1;
				a[1] = node(r+1 ,(*it).r , (*it).x);
			}
			//printf("%d is e1 and %d is e2\n",e1,e2);
			update(e1,e2,abs((*it).x-x));
			//myset.erase(it);
		}
        }
	arr[1]++;
	//assert(arr[1]>arr[0]);
	myset.erase(arr[0] , arr[1]);
	myset.insert(node(l,r,x));
	if(yes[0])	myset.insert(a[0]);
	if(yes[1])	myset.insert(a[1]);
}
ll getsum(TT a,int i)
{
	return a.a + (ll)i* a.b;
}
void solve()
{
	int type,l,r;
	scanf("%d%d",&n,&m);
	init();
	ll x;
	for(int i=1;i<=m;i++){
		scanf("%d",&type);
		if(type==1){
			scanf("%d%d%lld",&l,&r,&x);
			Update(l,r,x);
		}
		else{
			scanf("%d%d",&l,&r);
			printf("%lld\n",getsum(read(r),r)-getsum(read(l-1),l-1));
		}
	}
}

int main()
{
	solve();
	return 0;
}
