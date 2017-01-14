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

map<pair<int,int>,bool > hashEdges;
vector<int> BG[100005];
unordered_map<int,int> UG[100005];
vector<int> degree(100005,0);
vector<int> rdegree(100005,0);
vector<pair<int,int> > edges;
vector<int> finalPath;
map<pair<int,int>,bool> isPrinted;
map<pair<int,int>,bool> hasOccured;

bool checkUndirectedGraphConnectedness(int N)
{
    bool isUndirectedGraphConnected=true;
    //Check for connectedness in a bidirectional graph
    vector<bool> visited(N+1,false);
    stack<int> S;

    S.push(1);

    while(!S.empty())
    {
        int currentNode=S.top();
        S.pop();
        visited[currentNode]=true;

        int adjacencyListSize=BG[currentNode].size();
        for(int i=0;i<adjacencyListSize;i++)
        {
            if(!visited[BG[currentNode][i]])
            {
                S.push(BG[currentNode][i]);
            }
        }
    }
    
    for(int i=1;i<=N;i++)
    {
        if(!visited[i])
        {
            isUndirectedGraphConnected=false;
            break;
        }
    }
    return isUndirectedGraphConnected;
}

bool checkEulerGraphForUndirectedGraph(int N)
{
    bool isUndirectedGraphConnected=checkUndirectedGraphConnectedness(N);
    bool isEulerCircuit=false;

    if(isUndirectedGraphConnected==false)
    {
        return isEulerCircuit;
    }

    int oddDegreeVertices=0LL;

    for(int i=1;i<=N;i++)
    {
        if(BG[i].size() & 1LL)
        {
            ++oddDegreeVertices;
        }
    }

    if(oddDegreeVertices>2)
    {
        return isEulerCircuit;
    }

    //Euler circuit doesn't contain odd degree vertices
    if(oddDegreeVertices==0)
    {
        isEulerCircuit=true;
    }

    return isEulerCircuit;
}

//Hierholzer's Algorithm to find eulerian path
void findEulerCircuit(int source)
{
    if(rdegree[source]==0)
    {
        finalPath.pb(source);
    }
    else
    {
        while(!UG[source].empty())
        {
            unordered_map<int,int>::iterator it=UG[source].begin();
            LL neighbour=it->first;
            UG[source].erase(neighbour);
            UG[neighbour].erase(source);
            --rdegree[neighbour];
            --rdegree[source];
            findEulerCircuit(neighbour);
        }
        finalPath.pb(source);
    }   
}