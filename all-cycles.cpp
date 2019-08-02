#include "stdio.h"
#include "queue"
#include "iostream"
#define maxSize 10
#define inf 9999
#define white 0
#define gray 1
#define black 2
#include<algorithm>
using namespace std;

int color[maxSize];
int parent[maxSize];
int time,v,e;
int discoverTime[maxSize], finishingTime[maxSize];
struct vertex{
int n;
int index;
string name;
}s[100];
void dfsVisit(int grid[maxSize][maxSize], int u){
    int i,j;
    color[u] = gray;
    discoverTime[u] = ++time;
    for(i=0; i<v; i++){
        if(grid[u][i]!=0  ){
            if(color[i]==white){
                parent[i]=u;
                dfsVisit(grid, i);
            }
            if(color[i]==gray && parent[u]!=i ){
                int piv=u;
                while(piv!=i){
                    cout<<piv<<" ";
                    piv=parent[piv];
                }
                cout<<piv<<" ";
                cout<<"Cycle"<<endl;
            }

        }
    }
    color[u] = black;
    finishingTime[u]=++time;
    printf("%d\n",u);
}

void dfs(int grid[maxSize][maxSize]){
    //initialization
    int i,j;

    for(i=0; i<v; i++){
        parent[i]=-1;
        color[i]=white;
    }
    int time=0;
    for(i=0; i<v; i++){
        if(color[i] == white){
            dfsVisit(grid, i);
        }
    }
}

int main(){
    //  freopen("input.txt","r",stdin);

    int grid[maxSize][maxSize];
    int i,j,x,y;

    printf("Enter number of vertex: ");
    scanf("%d",&v);
    printf("Enter number of edge: ");
    scanf("%d",&e);

    //input
    for(i=0; i<v; i++)
        for(j=0; j<v; j++)
            grid[i][j]=0;

    printf("Enter edges (u v): ");
    for(i=0; i<e; i++){
        scanf("%d %d",&x,&y);
        grid[x][y]=1;
        grid[y][x]=1;

    }

    //output
    printf("\nInput Graph:\n");
    for(i=0; i<v; i++){
        for(j=0; j<v; j++){
            printf("%d\t",grid[i][j]);
        }
        printf("\n");
    }

    printf("\n\nDFS\n");
    dfs(grid);
    cout<<endl;
   for(int i=0;i<v;i++){
    s[i].index=i;
    s[i].n=finishingTime[i];
   }
   string A[]={"socks","shoes","short","pant","belt","jacket","shirt","tie","watch"};
   for(int i=0;i<v;i++){
    s[i].name=A[i];
   }
   for(int i=0;i<v;i++){
    for(int j=i+1;j<v;j++){
        if(s[i].n>s[j].n){
            swap(s[i].n,s[j].n);
            swap(s[i].index,s[j].index);
            swap(s[i].name,s[j].name);
        }
    }
   }
   cout<<endl;
  for(int i=v-1;i>=0;i--){
    cout<<s[i].name<<" ";
  }
    return 0;
}

