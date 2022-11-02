#include<bits/stdc++.h>

using namespace std;


int adjmat_W[7][7] = { //adjacency weight matrix
    {INT_MAX,2,INT_MAX,1,INT_MAX,INT_MAX,INT_MAX},
    {INT_MAX,INT_MAX,INT_MAX,3,10,INT_MAX,INT_MAX},
    {4,INT_MAX,INT_MAX,INT_MAX,INT_MAX,5,INT_MAX},
    {INT_MAX,INT_MAX,2,INT_MAX,2,8,4},
    {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,6},
    {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX},
    {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,1,INT_MAX}
};

int findMin(int d[],int v[],int V);
void showPath(int start,int end,int prev[]);
void dijkstra(int start,int end,int V);

void dijkstra(int start,int end,int V)
{
    int dist[V];
    int visited[V];
    int prevnode[V];

    // init lists
    for(int i=0;i<V;i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
        prevnode[i] = -1;
    }

    // start
    dist[start] = 0;
    while(!visited[end])
    {
        int tmp = findMin(dist,visited,V);
        visited[tmp] = 1;
        // relax
        for(int i=0;i<V;i++)
        {
            if(adjmat_W[tmp][i]!=INT_MAX && !visited[i] && dist[i]>dist[tmp]+adjmat_W[tmp][i])
            {
                dist[i] = dist[tmp]+adjmat_W[tmp][i];
                prevnode[i] = tmp;
            }
        }

    }
    showPath(start,end,prevnode);
}

int findMin(int d[],int v[],int V)
{
    int min = INT_MAX;
    int re = NULL;
    for(int i=0;i<V;i++)
    {
        if((min>d[i]) && !v[i])
        {
            min = d[i];
            re = i;
        }
    }
    return re;
}

void showPath(int start,int end,int prev[])
{
    if(end==start)
    {
        printf("%c ",start+65);
        return;
    }
    
    showPath(start,prev[end],prev);
    printf("%c ",end+65);
}

int main()
{
    dijkstra(2,4,7);
    return 0;
}