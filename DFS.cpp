#include<stdio.h>
#include<iostream>
#define white 1
#define gray 2
#define black 3
using namespace std;
int node, edge;
int ar[100][100];
int color[100];


void visitdfs(int x){
    color[x] = gray;
    printf(" %d",x);
    for(int i = 0; i < node; i++){
        if(ar[x][i] == 1){
            if(color[i] == white){
                visitdfs(i);
            }
        }
    }
    color[x] = black;
}


void dfs(){
    for(int i = 0; i < node; i++){
        color[i] = white;
    }
    for(int i = 0; i < node; i++){
        if(color[i] == white){
            visitdfs(i);
        }
    }
}


int main()
{
freopen("text.txt","r",stdin);
scanf(" %d %d",&edge,&node);
int n1,n2,i;
for(i = 0; i < edge; i++){
    scanf("%d%d",&n1,&n2);
    ar[n1][n2] = 1;
    ar[n2][n1] = 1;
}

dfs();
return 0;
}

