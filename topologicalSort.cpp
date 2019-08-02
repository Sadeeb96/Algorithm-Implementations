#include<bits/stdc++.h>
using namespace std;
bool complete(bool A[],int s)
{
    for(int i=1;i<=s;i++){
        if(!A[i])return false;
    }
    return true;
}
int main()
{
    while(true){
    int n;
    cin>>n;
    int e;
    cin>>e;
    if(n==0 && e==0)break;
    int grid[n+1][n+1];
    int degree[n+1];
    bool vis[n+1];
    memset(vis,false,sizeof(vis));
    int m=0;
    int mi=0;
    memset(grid,0,sizeof(grid));
    memset(degree,0,sizeof(degree));
    for(int i=0; i<e; i++)
    {
        int x,y;
        cin>>x>>y;
        grid[x][y]=1;
        degree[y]++;
    }
    while(!complete(vis,n))
    {
      //  cout<<1<<"\n";
      //  for(int i=1;i<=n;i++)cout<<degree[i]<<" ";
        //cout<<endl;
        for(int i=1;i<=n;i++){
            if(!vis[i] && degree[i]==0){
                vis[i]=true;
                cout<<i<<" ";
                for(int j=1;j<=n;j++){
                    if(grid[i][j]==1 && degree[j]>0){
              //          cout<<j<<" reduced"<<endl;
                        degree[j]--;
                    }
                }
            }
        }
    }
    cout<<endl;
    }

}
/*
6
8
0 2
1 2
2 3
2 4
2 5
3 4
5 4
5 2
*/
