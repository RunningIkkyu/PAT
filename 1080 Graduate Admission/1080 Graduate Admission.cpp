#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Stu
{
    int id;
    int ge;
    int gi;
    int ave;
    int choice[6];
}stu[40000 + 10];

int quota[110];

vector<struct Stu> school[110];  // each school have a queue for student.

bool complare2(struct Stu a, struct Stu b)
{
    return a.id<b.id;
}
bool complare(struct Stu a, struct Stu b)
{
    if (a.ave == b.ave)
        return a.ge > b.ge;
    return a.ave > b.ave;
}

int main(void)
{
    // the total number of applicants, the total number of graduate schools,
    // the number of choices an applicant may have.
    int n, m, k;
    
    // input data
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; i++)
        scanf("%d", &quota[i]);
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &stu[i].ge, &stu[i].gi);
        stu[i].id = i;
        stu[i].ave = (stu[i].ge + stu[i].gi) / 2;
        for(int j = 0; j < k; j++)
            scanf("%d", &stu[i].choice[j]);
    }//for
    
    // sort student according to their average, if there is a tie, sort by ge.
    sort(stu, stu + n, complare);
    
    // for each student, allocated to school according to their choice.
    for(int i = 0; i < n; i++)
    {
        // for each choice of a student.
        for(int j = 0; j < k; j++)
        {
            int ch = stu[i].choice[j]; 
            // if this choice have quota.
            if(quota[ch] > 0)
            {
                school[ch].push_back(stu[i]); 
                quota[ch] -= 1;
                break;
            }// if 
            
            // if this choice have no quota but he has the same rank with the 
            // last student.
            else if(school[ch].size() != 0 &&school[ch][school[ch].size()-1].ge == stu[i].ge
                   && school[ch][school[ch].size()-1].ave == stu[i].ave)
            {
                school[ch].push_back(stu[i]); 
                break;
            }// else if 
        }// for2
    }// for1  
    
    for(int i = 0; i < m; i++)
    {
        sort(school[i].begin(), school[i].end(), complare2);
        int x = school[i].size();
        for(int j = 0; j < x; j++)
        {
            if(j != 0) printf(" ");
            printf("%d", school[i][j].id);
        }
        printf("\n");
    } 
    
    //system("pause");
    return 0;
    
    
} 