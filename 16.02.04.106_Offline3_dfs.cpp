#include<bits/stdc++.h>
#define white 1
#define gray 2
#define black 3
using namespace std;
int node,edge;
vector<int>ar[100];
int color[100];
void visitdfs(int i){
    color[i] = gray;
    cout<<" "<<i;
    int sz = ar[i].size();
     for(int j =0;j<sz;j++){
        if(ar[i][j] == 1){
            if(color[j] == white){
                visitdfs(j);
            }
        }
     }
    color[i] = black;

}
void dfs(){
    for(int i =0;i<node;i++)
        color[i] = white;
    for(int i =0;i<node;i++){
            if(color[i] == white){
                visitdfs(i);
            }
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
    dfs();
    return 0;
}
