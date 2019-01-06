#include<bits/stdc++.h>
#define white 1
#define gray 2
#define black 3
using namespace std;
int node,edge;
vector<int>ar[100];
int color[100];
int parent[100];
int dis[100];
void bfs(int Startingnode){
    for(int i = 0; i<node; i++){
        color[i] = white;
        dis[i] = INT_MIN;
        parent[i] = -1;
    }
    dis[Startingnode] = 0;
    parent[Startingnode] = -1;
    queue<int>q;
    q.push(Startingnode);
    while(!q.empty()){
        int i;
        i = q.front();
        q.pop();
        color[i] = gray;
        cout<<" "<<i;
        for(int j = 0; j<ar[j].size(); j++){
            int c = ar[i][j];
                if(color[c] == white){
                    dis[c] = dis[i] + 1;
                    parent[c] = i;
                    q.push(c);
                }

        }

        color[i] = black;
    }
}
int main(){
    cout<<"Enter the number of node & edges: ";
    cin>>node>>edge;
    cout<<"Enter edges pair: ";
    for(int i=0;i<edge;i++){
        int x,y;
        cin>>x>>y;
        ar[x].push_back(y);
        ar[y].push_back(x);
    }
    cout<<"Traversed tree: ";
    bfs(0);
    return 0;
}
