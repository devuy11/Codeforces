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

int main()
{
	string s[] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
	int N,i,T;
	string t;
	scanf("%d",&T);
	cin>>t;
	for(i=0;i<8;i++){
		if ( s[i].size()==T){
			int j;
			for(j = 0;j<T;j++){
				if ( t[j]=='.')	continue;
				if ( t[j] == s[i][j])	continue;
				else	break;
			}
			if( j== T){
				cout<<s[i]<<endl;
				break;
			}
		}
	}
	return 0;
}
