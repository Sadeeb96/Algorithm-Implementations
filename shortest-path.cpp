#include <iostream>
#include<queue>
using namespace std;
int main() {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    int N;
	    cin>>N;
	    int M[N][N];
	    bool vis[N][N];
	    int sx,sy,dex,dey;
	    for(int i=0;i<N;i++){
	        for(int j=0;j<N;j++){
	            vis[i][j]=false;
	            cin>>M[i][j];
	            if(M[i][j]==1){
	                sx=i;
	                sy=j;
	            }
	            if(M[i][j]==2){
	                dex=i;
	                dey=j;
	            }

	        }
	    }

	    int dx[4] ={1,0,-1,0};
	    int dy[4] ={0,1,0,-1};
	    queue<int> q;
	    q.push(sx);
	    q.push(sy);
	    while(!q.empty())
	    {
	        int x=q.front();
	        q.pop();
	        int y=q.front();
	        q.pop();
	        vis[x][y]=true;
	        for(int i=0;i<4;i++){
	            if(x+dx[i]>=0 && x+dx[i]<N && y+dy[i]>=0 && y+dy[i]<N && (M[x+dx[i]][y+dy[i]]==3 ||M[x+dx[i]][y+dy[i]]==2) && !vis[x+dx[i]][y+dy[i]])
	            {
	                q.push(x+dx[i]);
	                q.push(y+dy[i]);
	            }
	        }
	    }
	    cout<<vis[dex][dey]<<endl;
	}

	return 0;
}
