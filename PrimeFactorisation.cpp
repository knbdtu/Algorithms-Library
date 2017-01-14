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
#define MAXN 10000008
#define LIM 10000000
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

LL power(LL A,LL B)
{
	LL X=1LL;
	while(B)
	{
		if(B&1)
		{
			X=(X*A);
		}
		A=(A*A);
		B/=2LL;
	}
	return X;
}

LL lowerBaseLimit(LL N, LL E)
{
	LL low=2LL;
	LL high=1000000000000LL;

	while(low<=high)
	{
		LL mid=(low+high)/2LL;
		if((N-power(mid,E))>=0 && (N-power(mid+1,E))<=0)
		{
			return mid;
		}

		else if((N-power(mid,E))>=0 && (N-power(mid+1,E))>=0)
		{
			low=mid;
		}
		else
		{
			high=mid;
		}
	}
	return mid;
}

int main()
{
    //std::clock_t start;
    //double duration;
    //start = std::clock();
    //freopen("input.in","r",stdin);//redirects standard input
    //freopen("output.out","w",stdout);//redirects standard output
    //cout<<"yo\n";
    int T;
    scanf("%d",&T);
    while(T--)
    {
        LL N;
        scanf("%lld",&N);
        LL sol=0LL;
        printf("\n%lld\n",sol);
    }
    //duration=(clock()-start)/(double)CLOCKS_PER_SEC;
    //printf("\n\nDuration :- %0.9lf s",duration);
    return 0;
} 