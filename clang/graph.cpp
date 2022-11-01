#include<bits/stdc++.h>
using namespace std;

int adjmat_D[5][5] = { //adjacency matrix direct graph
    {0,1,0,0,1},
    {0,0,1,1,0},
    {0,0,0,0,0},
    {0,0,1,0,0},
    {0,1,0,1,0}
};
int adjmat_D2[7][7] ={
    {0,1,0,0,0,0,0},
    {0,0,1,0,1,1,0},
    {0,1,0,0,0,0,0},
    {0,0,1,0,0,0,0},
    {0,1,0,1,0,0,0},
    {0,0,0,0,0,0,1},
    {0,0,0,0,0,0,0}
};

int adjlist_D[5][5] = { //adjcency list direct graph
    {1,2,5},
    {2,4,3},
    {3},
    {4,3},
    {5,2,4}
};

// int adjmat_D2[7][7]={1};
// adjmat_D2[0][1],adjmat_D2[1][2],adjmat_D2[1][4],adjmat_D2[1][5],adjmat_D2[3][1],adjmat_D2[3][2],adjmat_D2[4][1],adjmat_D2[4][3],adjmat_D2[5][6] = 1;

// SO,FXXX YOU C++
// void list_to_matrix_D(int mat[][5]){
//     int V = static_cast<int>(sqrt(sizeof(adjlist_D)/sizeof(int)));

//     int i,j;
//     for( i = 0;i<V;i++)
//     {
//         for(j = 1;j<V;j++)
//         {
//             int index = adjlist_D[i][j];
//             if(index)
//             {
//                 mat[i][index] = 1;
//             }
//         }
//     }

// }
void matBFS(int start,int V);
void matDFS(int start,int V);
void _matDFS(int start,int V,int visited[]);
void shortestPath(int start,int end,int V);
void printPath(int prev[],int start,int end);



void matBFS(int start,int V)
{
    queue<int>q;
    q.push(start);
    int visited[V];
    while(!q.empty())
    {
        int tmp = q.front();
        q.pop();
        printf("%c",tmp+65);//ASCII number to letter

        for(int i=0;i<V;i++)
        {
            if(adjmat_D[tmp][i]&&!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }

}

void shortestPath(int start,int end,int V)
{
    // declare
    queue<int>q;
    int visited[V];
    int dist[V];
    int prev[V];
    // init
    for(int k = 0;k<V;k++)
    {
        visited[k] = 0;
        dist[k] = -1;
        prev[k] = -1;
    }

    q.push(start);
    visited[start] = 1;
    dist[start] = 0;
    while(!visited[end]&&!q.empty())
    {
        int tmp = q.front();q.pop();
        for(int i=0;i<V;i++)
        {
            if(adjmat_D2[tmp][i] && !visited[i])
            {
                q.push(i);
                visited[i] = 1;
                dist[i] = dist[tmp]+1;
                prev[i] = tmp;
            }
        }
    }
    printf("from %c to %c's distance is %d\n",start+65,end+65,dist[end]);
    printf("the path is ");
    printPath(prev,start,end);
}

void printPath(int prev[],int start,int end)
{
    if(prev[end]== -1)
    {
        printf("%c",start+65);
        return;
    }
    printPath(prev,start,prev[end]);
    printf("%c",end+65);
}

void matDFS(int start,int V)
{
    int visited[V] = {0};
    _matDFS(start,V,visited);
    printf("\n");
}
void _matDFS(int start,int V,int visited[])
{
    if(visited[start])
    {
        return;
    }
    visited[start] = 1;
    printf("%c",start+65);
    for(int i=0;i<V;i++)
    {
        if(adjmat_D2[start][i]) // !visited[i]可省略。因为即便已访问的节点执行递归也会直接return
        {
            _matDFS(i,V,visited);
        }
    }
}

int main(){
    // matBFS(0,5);
    // printf("\n");
    // matDFS(0,5);
    matDFS(0,7);
    shortestPath(3,6,7);
}