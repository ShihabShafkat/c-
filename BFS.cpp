#include<stdio.h>
#include<math.h>
#include<iostream>
#include<queue>
#define white 1
#define gray 2
#define black 3
using namespace std;
int node, edge;
int ar[100][100];
int color[100];
int parent[100];
int dis[100];

void bfs(int startingnode){
    for(int i = 0; i<node;i++){
        color[i] = white;
        dis[i] = -2471;
        parent[i] = -1;
    }
    dis[startingnode] = 0;
    parent[startingnode] = -1;
    queue<int>q;
    q.push(startingnode);
    while(!q.empty()){
        int x;
        x = q.front();
        q.pop();
        color[x] = gray;
        printf(" %d",x);
        for(int i =0; i<node;i++){
            if(ar[x][i] ==1){
                if(color[i] == white){
                    dis[i] = dis[x] + 1;
                    parent[i] = x;
                    q.push(i);
                }
            }
        }

        color[x] = black;
    }
}

int main()
{
freopen("text1.txt","r",stdin);
scanf(" %d %d",&edge,&node);
int n1,n2,i;
for(i = 0; i < edge; i++){
    scanf("%d%d",&n1,&n2);
    ar[n1][n2] = 1;
    ar[n2][n1] = 1;
}

bfs(0);
return 0;
}
