#include <iostream>
#include <algorithm>
#include <cstring>
#define N 20100
using namespace std;

struct Stu{
    int id;
    int grade[4];
    int rank[4];
    int best;
}stu[N];

int ind[1000000];
int flag = 0;
bool compare(Stu a, Stu b){ return a.grade[flag] > b.grade[flag]; }

int main(void)
{
    int m, n, t;
    cin>>n>>m;
    // input
    for (int i = 0 ; i < n; i++){
        cin>>stu[i].id>>stu[i].grade[1]>>stu[i].grade[2]>>stu[i].grade[3];
        // calculate average score
        stu[i].grade[0] = (stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3])/3 + 0.5;
    }
    
    // get all student's ranks of subjects.
    for(flag = 0; flag < 4; flag++){
        sort(stu, stu+n, compare);
        stu[0].rank[flag] = 1;
        for (int i = 1; i < n ; i++){
            stu[i].rank[flag] = i + 1;
            if(stu[i].grade[flag] == stu[i-1].grade[flag]) 
                stu[i].rank[flag] = stu[i-1].rank[flag];
        }
    }

    // save the best rank.
    for(int i = 0; i < n ; i++){
        ind[stu[i].id] = i + 1;
        stu[i].best = 0;
        int minn = stu[i].rank[0];
        for(int j = 0; j < 4; j++){
            if(stu[i].rank[j] < minn){
                stu[i].best = j;
                minn = stu[i].rank[j];
            }
        }
    }

    // output results.
    string s = "ACME";
    for(int i = 0; i < m; i++){
        cin>>t;
        int x = ind[t];
        if(x){
            int best = stu[x-1].best;
            cout<<stu[x-1].rank[best]<<" "<<s[best]<<endl;
        }
        else
            cout<<"N/A"<<endl;
    }
    return 0;
}
