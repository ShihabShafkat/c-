#include<bits/stdc++.h>
using namespace std;
int vertex,edge;
int G[100][100];
int parent[100];
int dist[100];
bool visited[100];
int MIN(int dist[], bool visited[])
{

   int minm= INT_MAX, num;

   for (int i = 0; i < vertex; i++)
     if (visited[i] == false && dist[i] < minm)
         minm = dist[i], num = i;

   return num;
}

void relax(int u, int v, int w){
    if(dist[v] > dist[u] + w){
        dist[v] = dist[u] + w;
        parent[v] = u;
    }
}

void dijkstra(int graph[100][100], int s)
{
     for (int i = 0; i < vertex; i++)
        dist[i] = INT_MAX, visited[i] = false;


     dist[s] = 0;
     parent[0] = -1;

     for (int j = 0; j < vertex; j++)
     {

        int u = MIN(dist, visited);

        visited[u] = true;

        for (int v = 0; v < vertex; v++){
                int w = graph[u][v];
                relax(u, v, w);
        }

    }
}

void printPath(int parent[], int j)
{
    // Base Case : If j is source
    if (parent[j]==-1)
        return;

    printPath(parent, parent[j]);

    cout<<j<<endl;
}

int main()
{
   cout<<"Enter Vertex & Edge: "<<endl;
   cin>>vertex>>edge;

   for(int i=0;i<edge;i++){
        int a,b,c;
        cin>>a>>b>>c;
        G[a][b]=c;
        G[b][a]=c;
   }
    dijkstra(G, 0);

   for (int i = 0; i < vertex; i++){
      cout<<i<<" "<<dist[i];
      printPath(parent, i);
   }
   return 0;


}


