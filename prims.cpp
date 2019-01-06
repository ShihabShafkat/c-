#include<bits/stdc++.h>
using namespace std;
struct nodes{
    int number;
    int weight = INT_MAX;
    int parent = -1;
    bool operator < (const nodes &a)const{
        return weight > a.weight;
    }
};
int connection[100][100];
int main(){
    int vertex, edge, cost = 0, x, y, z;
    cout<<"Vertex: ";
    cin>>vertex;
    cout<<"Edge: ";
    cin>>edge;
    priority_queue <nodes> pq;
    nodes prims[100];
    for(int i = 0; i < edge; i++){
        cout<<"Enter source, destination & cost: ";
        cin>>x>>y>>z;
        connection[x][y] = z;
    }
    prims[1].number = 0;
    prims[1].weight = 0;
    prims[1].parent = 0;
    for(int i =1; i < vertex; i++){
        prims[i].number = i;
        pq.push(prims[i]);
    }
    while(!pq.empty()){
        nodes u = pq.top();
        pq.pop();
        for(int v =1; v < vertex; v++){
            if(connection[u.number][v] != 0){
                if(connection[u.number][v] < prims[v].weight){
                    prims[v].parent = u.number;
                    prims[v].weight = connection[u.number][v];
                }
            }
        }

    }
    cout<<endl;
    for(int i = 2; i < vertex; i++){
        cout<<prims[i].number<<" "<<prims[i].parent<<" "<<prims[i].weight<<endl;
        cost += prims[i].weight;
    }
    cout<<"Total cost: "<<cost;
    return 0;


}
