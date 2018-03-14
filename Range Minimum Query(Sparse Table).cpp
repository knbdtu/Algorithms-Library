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
#define MAXN 10000005
#define bitcount __builtin_popcount
#define INF 2000000000
#define EPS 1e-9

template<typename T>T absll(T X)
{
    if(X<0)
        return -1*X;
    else
        return X;
}

LL logT[MAXN];
LL rmq[33][MAXN];
LL PTwo[33];
LL A[MAXN];

void RMQSparseTable(LL N)
{
	logT[1]=0;
	PTwo[0]=1;
	for(LL i=1;i<30;i++)
	{
		PTwo[i]=PTwo[i-1]*2;
	}
	for(LL i=2;i<=N;i++)
	{
		logT[i]=logT[i>>1]+1;
	}
	
	for(LL i=0;i<N;i++)
	{
		rmq[0][i]=i;
	}
	
	for(LL k=1;PTwo[k]<N;k++)
	{
		for(LL i=0;i+PTwo[k]<=N;i++)
		{
			LL X=rmq[k-1][i];
			LL Y=rmq[k-1][i+PTwo[k-1]];
			rmq[k][i]=(A[X]<=A[Y]?X:Y);
		}
	}
}

LL RMQQuery(LL i,LL j)
{
	LL k=logT[j-i];
	LL x=rmq[k][i];
	LL y=rmq[k][j-PTwo[k]+1];
	return A[x]<=A[y]?x:y;
}