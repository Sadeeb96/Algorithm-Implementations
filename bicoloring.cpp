#include<bits/stdc++.h>
using namespace std;
int main()
{
    while(true)
    {
        int nodes;
        int edges;
        cin>>nodes;
        if(nodes==0)
            break;
        cin>>edges;
        int A[nodes][nodes];
        memset(A,0,sizeof(A));
        for(int i=0; i<edges; i++)
        {
            int x,y;
            cin>>x>>y;
            A[x][y]=1;
            A[y][x]=1;
        }
        int color[nodes];
        memset(color,-1,sizeof(color));
        int src=0;
        color[src]=1;
        queue<int> q;
        q.push(src);
        bool bic=true;
        while(!q.empty())
        {
            int head = q.front();
            q.pop();
            for(int i=0; i<nodes; i++)
            {
                if((A[head][i]==1 || A[i][head]==1) && color[i]==-1)
                {
                    color[i]=1-color[head];
                    q.push(i);
                }
                else if((A[head][i]==1 || A[i][head]==1) && color[i]==color[head])
                {
                    bic=false;
                }
            }
        }
        if(bic)
        {
            cout<<"BICOLORABLE."<<endl;
        }
        else
        {
            cout<<"NOT BICOLORABLE."<<endl;
        }
    }
}
