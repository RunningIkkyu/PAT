#include <iostream>
#include <algorithm>
#define N 505
#define INF 0x3f3f3f3f
using namespace std;


// Utility funtion to find the vertex with minimum distance value from
// the set of vertices not yet included in the shortest path.
int minDis(int dis[], bool sptSet[], int n){
    int min = INF, min_ind;
    for(int i = 0; i < n; i++)
        if(sptSet[i] == false && dis[i] < min)
        {
            min = dis[i]; 
            min_ind = i;
        }
    return min_ind;
}

int main(void)
{
    int n, m, c1, c2;   // number of citys, number of roads, start city, end city.
    int t1, t2, t3;     // tmp variable.
    int team_number[N]; // number of teams of each city.
    int roads[N][N];    // adjacent matrix of city, each element in the matrix is distance between cities. 
    int num[N];         // num[i] indacates the number of paths from c1 to i.
    int dis[N];         // dis[i] will hold the shortest distance from c1 to i.
    int gathered[N];    // gathered meant teams we have gathered from start nodes to i.
    bool sptSet[N];     // shortest path set, sptSet[i] is true indacates i is in sptSet.

    // Init arrays.
    fill(team_number, team_number+N, 0);
    fill(roads[0], roads[0]+N*N, INF);
    fill(dis, dis+N, INF);
    fill(sptSet, sptSet+N, 0);

    // Input handling.
    cin>>n>>m>>c1>>c2;
    for(int i = 0; i < n; i++) 
        cin>>team_number[i];
    for(int i = 0; i < m; i++) 
    {
        cin>>t1>>t2>>t3;
        roads[t2][t1] = roads[t1][t2] = t3;
    }

    // Initialization after input
    dis[c1] = 0;        // make sure the source vertex is picked first.
    num[c1] = 1;        // initial num[c1] with 1.
    gathered[c1] = team_number[c1];

    // Dijkstra's algorithm
    // iterate n-1 times to make sure every nodes has been added into sptSet.
    for(int count = 0; count < n-1; count++){
        // pick a vertex u with minimum distance which is not in sptSet.
        int u = minDis(dis, sptSet, n);
        // add u to sptSet
        sptSet[u] = true;
        for(int v=0; v<n; v++){
            // iterate every adjacent nodes of u which is not in sptSet.
            if(sptSet[v] == false && roads[u][v] != INF){
                // if dis[v] can be shrink by node u. 
                if(dis[u] + roads[u][v] < dis[v]){
                    // update the value of dis[v] with the smaller value.
                    dis[v] = dis[u] + roads[u][v];
                    // update the number of paths of v.
                    num[v] = num[u];
                    // update the team we can gathered.
                    gathered[v] = team_number[v] + gathered[u];
                }
                // else if these two way have the same distance, a
                else if(dis[u] + roads[u][v] == dis[v]){
                    num[v] = num[u] + num[v];
                    if(gathered[v] < gathered[u] + team_number[v])
                        gathered[v] = gathered[u] + team_number[v];
                }//elif
            }//if
        }//for
    }//for
    cout<<num[c2]<<" "<<gathered[c2]<<endl;
    return 0;
}