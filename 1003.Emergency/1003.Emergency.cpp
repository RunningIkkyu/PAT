#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int n, m, c1, c2;
    int team_number[510];
    fill(team_number, team_number+510, 0);
    cin>>n>>m>>c1>>c2;
    for(int i = 0; i < m; i++) cin>>team_number[i];
    return 0;
}