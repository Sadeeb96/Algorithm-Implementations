#include<bits/stdc++.h>
using namespace std;
int v,e,grid[100][100];
int d[100];
int parent[100];
struct node
{
    int a;
    int cost;
    bool operator<(const node& otherNode) const
    {
        return cost < otherNode.cost;
    }
};
bool inMST[1000];
void primsMST(int so)
{
    int sum=10000;
    memset(parent,-1,sizeof(parent));
    memset(d,10000,sizeof(d));
    d[so]=0;
    priority_queue<node> q;
    /* for(int i=1;i<=v;i++){
      node curr;
      curr.a=i;
      curr.cost=d[i];
      q.push(curr);
     }*/
    node curr;
    curr.a=so;
    curr.cost=d[so];
    q.push(curr);
    while(!q.empty())
    {
        node u=q.top();
        q.pop();
        int x=u.a;
        inMST[x]=true;
        for(int i=1; i<=v; i++)
        {
            if(grid[x][i]!=0)
            {
                if(inMST[i]==false && d[i]>grid[x][i])
                {
                    //  sum=sum-d[i];
                    //cout<<]<<endl;
                    d[i]=grid[x][i];
                    //sum+=d[i];
                    // cout<<sum<<endl;
                    parent[i]=x;
                    cout<<"parent:"<<i<<"="<<x<<endl;
                    node n;
                    n.a=i;
                    n.cost=d[i];
                    q.push(n);
                }
            }
        }
    }
    // cout<<sum-1<<endl;
    int mcost=0;
    cout<<"The MST includes the following edges:\n";
    cout<<"From  to   weight\n";
    for (int i = 1; i <=v; ++i)
    {
        if(i==so)continue;
        printf("%d     %d     %d\n", parent[i], i,grid[parent[i]][i]);
        mcost+=grid[parent[i]][i];
    }
    cout<<"MST cost:"<<mcost<<endl;
}
int main()
{
    cout<<"Enter the number of vertices:";
    cin>>v;
    cout<<"Enter the number of edges:";
    cin>>e;
    cout<<"Enter the edges with their weight:\n";
    for(int i=1; i<=e; i++)
    {
        int x,y;
        cin>>x>>y;
        cin>>grid[x][y];
        grid[y][x]=grid[x][y];
    }
    cout<<"\n\nGrid:\n\n";
    for(int i=1; i<=v; i++)
    {
        for(int j=1; j<=v; j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    int so;
    cout<<"Enter the source:";
    cin>>so;
    primsMST(so);
//    printPath(so,v);

}
/*1 2 1
1 4 3
1 3 8
4 3 2
2 4 1*/
