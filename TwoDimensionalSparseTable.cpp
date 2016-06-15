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

int PT[10];

struct P
{
    int first;
    int second;
    
    P()
    {
        first=0;
        second=0;
    }
    
}pre[1001][1001][11][11];

int dp[1001][1001];
int A[1000][1000];

P get_max(P C,P D)
{
    int el1=A[C.first][C.second];
    int el2=A[D.first][D.second];

    if(el1>=el2)
    {
        return C;
    }
    else
    {
        return D;
    }
}

void TwoDimensionSparseTable(int N,int M)
{
    for(int i=0;PT[i]<=N;i++)
    {
        for(int j=0;PT[j]<=M;j++)
        {
            for(int x=0;x+PT[i]-1<N;x++)
            {
                for(int y=0;y+PT[j]-1<M;y++)
                {
                    if(i==0&&j==0)
                    {
                        pre[x][y][i][j].first=x;
                        pre[x][y][i][j].second=y;
                    }
                    else if(i==0)
                    {
                        pre[x][y][i][j]=get_max(pre[x][y][i][j-1],pre[x][y+PT[j-1]][i][j-1]);
                    }
                    else if(j==0)
                    {
                        pre[x][y][i][j]=get_max(pre[x][y][i-1][j],pre[x+PT[i-1]][y][i-1][j]);
                    }
                    else
                    {
                        pre[x][y][i][j]=get_max(get_max(pre[x][y][i-1][j-1],pre[x+PT[i-1]][y][i-1][j-1]),get_max(pre[x][y+PT[j-1]][i-1][j-1],pre[x+PT[i-1]][y+PT[j-1]][i-1][j-1]));
                    }
                }
            }
        }
    }
}

P get_range_max_query(int X,int Y,int X1,int Y1)
{
    int K=log(X1-X+1);
    int L=log(Y1-Y+1);
    P sol=get_max(get_max(pre[X][Y][K][L],pre[X1-PT[K]+1][Y][K][L]),get_max(pre[X][Y1-PT[L]+1][K][L],pre[X1-PT[K]+1][Y1-PT[L]+1][K][L]));
    return sol;
}