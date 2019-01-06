#include<bits/stdc++.h>
using namespace std;
struct node
{
    int root;
    int child;
    int cost;
};
int vertex, edge, u, v, w;
int parent[100];
int dist[100];
void relax(int u, int v, int w)
{

    if(dist[v] > dist[u] + w)
    {
        dist[v] = dist[u] + w;
        parent[v] = u;
    }
}
bool BellmanFord(node G[100], int s)
{
    for(int i = 0; i<vertex; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[s] = 0;
    parent[s] = -1;
    for(int i = 0; i<vertex; i++)
    {
        for(int j = 0; j<edge; j++)
        {
            u = G[j].root;
            v = G[j].child;
            w = G[j].cost;
            relax(u,v,w);
        }
    }
    for(int j = 0; j<edge; j++)
    {
        u = G[j].root;
        v = G[j].child;
        w = G[j].cost;
        if(dist[v] > dist[u]+w)
        {
            return false;
        }
    }
    return true;
}
void printPath(int parent[], int j){
    if(parent[j] == -1)
        return;
    printPath(parent,parent[j]);
    cout<<" "<<j;
}

int main()
{
    cout<<"Vertex: ";
    cin>>vertex;
    cout<<"Edge: ";
    cin>>edge;
    node G[edge], temp;
    for(int i = 0; i < edge; i++)
    {
        cout<<"Enter source, destination & cost: ";
        cin>>G[i].root>>G[i].child>>G[i].cost;
    }
    bool flag = BellmanFord(G,0);
    if(flag == false)
    {
        cout<<"Negative Cycle"<<endl;
    }
    else
    {
        cout<<"Node\tDistance\tpath"<<endl;
        for(int i = 0; i<vertex; i++)
        {
            cout<<i<<"  "<<dist[i];
            printPath(parent,i);
            cout<<endl;
        }
    }
    return 0;
}

