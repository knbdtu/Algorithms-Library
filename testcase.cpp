#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define LD long double
#define gc getchar_unlocked
#define pc putchar_unlocked
#define MOD 1000000007
#define MAXN 100005
#define bitcount _builtin_popcount
#define INF 2000000000
#define EPS 1e-9

template<typename T>T absll(T X)
{
    if(X<0)
        return -1*X;
    else
        return X;
}

int main()
{
	int N,M,C;
	scanf("%d %d %d",&N,&M,&C);
	vector<LL> LH(1001,0);
	vector<LL> UH(1001,0);
	vector<LL> S(1001,0LL);
	int X;
	for(int i=0;i<N;i++)
	{
		scanf("%d",&X);
		UH[X]+=1;
	}
	
	for(int i=0;i<M;i++)
	{
		scanf("%d",&X);
		LH[X]+=1;
	}
	
	for(int i=1;i<1001;i++)
	{
		S[i]=LH[i]*UH[i];
	}
	
	
	return 0;
}