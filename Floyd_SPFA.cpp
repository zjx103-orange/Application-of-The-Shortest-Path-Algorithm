#include<bits/stdc++.h>
#define IO ios::sync_with_stdio(false);\cin.tie(0);\cout.tie(0);
#define inf 0x3f3f3f
using namespace std;
typedef long long LL;
const int maxn = 5e2+10;

int n,m;
LL G[maxn][maxn];
LL G2[maxn][maxn];
LL dist[maxn];
LL dist2[maxn];
bool vis[maxn];

void floyd()
{
    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++)
            for(int k=1; k<=n; k++)
                G2[i][j] = min(G2[i][j],G2[i][k]+G2[k][j]);
}

void init()
{
    memset(dist,inf,sizeof(dist));
    memset(dist2,inf,sizeof(dist2));
    memset(vis,false,sizeof(vis));
    memset(G,inf,sizeof(G));
    memset(G2,inf,sizeof(G2));
}

void spfa(int st,int ed)
{
    queue<int> sk;
    dist[st] = dist2[st] = 0;
    vis[st] = true;
    sk.push(st);
    while(!sk.empty())
    {
        int u = sk.front();
        sk.pop();
        vis[u] = false;
        for(int i=1; i<=n; i++)
        {
            int xlen = min(dist[u],dist2[u]);
            bool flag = false;
            if(dist[i] > xlen + G[u][i])
            {
                dist[i] = xlen + G[u][i];
                flag = true;
            }
            if(G2[u][i]!=4557430888798830399LL)
            {
                if(dist2[i] > dist[u] + G2[u][i] * G2[u][i])
                {
                    dist2[i] = dist[u] + G2[u][i] * G2[u][i];
                    flag = true;
                }
            }
            if(flag && !vis[i])
            {
                vis[i] = true;
                sk.push(i);
            }
        }
    }
}

int main()
{
    IO;
    init();
    cin>>n>>m;
    for (int i = 0; i < m ; i++)
    {
        LL t,a,b,c;
        cin>>t>>a>>b>>c;
        if(t)
            G2[a][b] = G2[b][a] = min(G2[a][b],c);
        else
            G[a][b] = G[b][a] = min(G[a][b],c);
    }
    floyd();
    spfa(1,n);
    cout<<min(dist[n],dist2[n])<<endl;
    return 0;
}

