#include<bits/stdc++.h>
using namespace std;
struct node{
    int root;
    int child;
    int cost;
};
int parent[100];
int findset(int u){
    if(u != parent[u]){
        return findset(parent[u]);
    }else{
        return u;
    }
}
int main(){
    int vertex, edge, cost = 0;
    cout<<"Vertex: ";
    cin>>vertex;
    cout<<"Edge: ";
    cin>>edge;
    node krush[edge], temp;
    for(int i = 0; i < edge; i++){
        cout<<"Enter source, destination & cost: ";
        cin>>krush[i].root>>krush[i].child>>krush[i].cost;
    }
    for(int i = 0; i<edge; i++){
        for(int j = i+1; j<edge; j++){
            if(krush[i].cost > krush[j].cost){
                temp = krush[i];
                krush[i] = krush[j];
                krush[j] = temp;
            }
        }
    }
    for(int i = 0; i<vertex; i++){
        parent[i] = i;
    }
    cout<<endl;
    for(int i = 0; i < edge; i++){
        int u = krush[i].root;
        int v = krush[i].child;
        int w = krush[i].cost;
        int uroot = findset(u);
        int vroot = findset(v);
        if(uroot != vroot){
            parent[uroot] = vroot;
            cost = cost+w;
            cout<<u<<" "<<v<<" "<<w<<endl;
        }
    }
    cout<<"Total cost: "<<cost<<endl;
    return 0;
}

