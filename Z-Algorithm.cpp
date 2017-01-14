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
#define MAXN 2*100005
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

vector<int> ZAlgorithm(string str,int N)
{
	int L=0,R=0;
	vector<int> Z(N,0);
	for(int i=1;i<N;i++)
	{
		if(i>R)
		{
			L=R=i;
			while(R<N&&str[R-L]==str[R])
			{
				++R;
			}
			Z[i]=R-L;
			--R;
		}
		else
		{
			int K=i-L;
			if(Z[K]<R-i+1)
			{
				Z[i]=Z[K];
			}
			else
			{
				L=i;
				while(R<N&&str[R-L]==str[R])
				{
					++R;
				}
				Z[i]=R-L;
				--R;
			}
		}
	}
	return Z;
}

int main()
{
	int T;
	cin>>T;
	for(int test=1;test<=T;test++)
	{
		string str;
		cin>>str;
		LL sol;
		int N=str.length();
		vector<int> Z=ZAlgorithm(str,N);
		for(int i=0;i<N;i++)
		{
			if(Z1[i]==N-i)
			{
				sol=max(sol,(LL)Z1[i]);
			}
		}
		if(sol==0)
		{
			sol=-1;
		}
		cout<<"Case "<<test<<":"<<sol<<endl;
	}
	return 0;
}