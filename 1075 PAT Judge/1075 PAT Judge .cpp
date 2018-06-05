#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;

struct User
{
    int id;
    int grade[8];
    int perfect;
    int total;
    bool submit;
}stu[10010];

int score[7];

bool complare(struct User a, struct User b)
{
    // if they are equal in total score.
    if(a.total == b.total) 
    {
        // if their perfect problem nubmer is equal too, sort in increasing 
        // order of their id.
        if(a.perfect == b.perfect) 
            return a.id < b.id;
        // if their total score is not equal, sort in non-increasing according
        // to the order of the perfectly sorted problems.
        return a.perfect > b.perfect; 
    }
    return a.total > b.total;
}

int main(void)
{
    int n;              //the total number of users.
    int k;              //the total number of problems.
    int m;              //the total number of submittions.
    int s = 1;              //the continued same score when ranked;
    int uid, pid, pscore;  //the id of user, id of problem, score of problem
    // input number of users, number of problems, number of submittions.
    scanf("%d %d %d", &n, &k, &m);
    for(int i = 1; i <= n; i++) 
    {
        memset(stu[i].grade, -1, sizeof(stu[i].grade));
        stu[i].id = i;
        stu[i].perfect = 0;
        stu[i].total = 0;
        stu[i].submit = false;
        
    } 
    for(int i = 1; i <= k; i++)
        scanf("%d", &score[i]);
    for(int i = 1; i <= m; i++)
    {
        // input : submittion's id, problem_id and the score of problem.
        scanf("%d %d %d", &uid, &pid, &pscore);   
        
        if(pscore == -1 && stu[uid].grade[pid] == -1)
            stu[uid].grade[pid] = 0; 
        // if the score is higher than before, then update.
        if( pscore > stu[uid].grade[pid] )
        {
            // update grade[i].
            stu[uid].grade[pid] = pscore;
            if(pscore == score[pid]) 
                stu[uid].perfect += 1;
            stu[uid].submit = true;
        }//if
    }//for
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            if(stu[i].grade[j] != -1)
                stu[i].total += stu[i].grade[j]; 
        }
    } 
    sort(stu+1, stu+n+1, complare);
    int skip = 0;
    for(int i = 1; i <= n; i++)
    {
        if(i != 1 && stu[i].total != stu[i-1].total) s = i;
        if(stu[i].submit == true)
        {
            printf("%d %05d %d", s-skip, stu[i].id, stu[i].total);
            for(int j = 1; j < k+1; j++)
            {
                if(stu[i].grade[j] == -1) 
                    printf(" -");
                else
                    printf(" %d", stu[i].grade[j]);           
            }

            printf("\n");
        }
        else skip += 1;
    }//for
    //system("pause");
    return 0;
}