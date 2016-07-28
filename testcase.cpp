#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define LD double
#define gc getchar_unlocked
#define pc putchar_unlocked
#define MOD 1000000007LL
#define MAXN 123456
#define bitcount __builtin_popcount
#define INF 2000000000
#define EPS 1e-9
#define PI 3.14159265359
#define DEBUG 1
#define read(X) scanf("%lld",&X)
#define write(X) printf("%lld\n",&X)

template<typename T>T absll(T X)
{
    if(X<0)
        return -1*X;
    else
        return X;
}

LL modPow(LL A,LL B,LL C)
{
	LL X=1LL;
	while(B)
	{
		if(B&1)
		{
			X=(X*A)%C;
		}
		A=(A*A)%C;
		B/=2LL;
	}
	return X;
}

vector<vector<LL> > hashe(26,vector<LL>(1234567,0LL));

int main()
{
	LL sol=0LL;
	string str;

	cin>>str;


	for(int i=0;i<str.length();i++)
	{
        for(int j=0;j<26;j++)
        {
            if(i==0)
            {
                if(j==(str[i]-'a'))
                {
                    hashe[j][i]=1;
                }
                else
                {
                    hashe[j][i]=0;
                }
            }
            else
            {
                if(j==(str[i]-'a'))
                {
                    hashe[j][i]=hashe[j][i-1]+1;
                }
                else
                {
                    hashe[j][i]=hashe[j][i-1];
                }
            }
        }
	}
	//Calculating solo pairs

	for(int i=0;i<26;i++)
	{
		LL term=hashe[i][str.length()-1];

		if(term>=4)
		{
			LL cont=term;
			term-=1;
			cont*=term;
			cont%=MOD;
			term-=1;
			cont*=term;
			cont%=MOD;
			term-=1;
			cont*=term;
			cont%=MOD;
			cont*=modPow(24LL,MOD-2,MOD);
			cont%=MOD;

			if(sol>=MOD)
			{
				sol%=MOD;
			}
		}
	}
	cout<<sol<<endl;
	//Calculate pairwise-letters
	vector<string> P;

	for(char i='a';i<='z';i++)
	{
		for(char j=i+1;j<='z';j++)
		{
			string tmp="";
			tmp+=i;
			tmp+=j;
			P.pb(tmp);
		}
	}

	for(int i=0;i<P.size();i++)
	{

	}

	return 0;
}
