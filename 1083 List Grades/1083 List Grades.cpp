#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAX = 0x3f3f3f;

struct Stu
{
    char name[11];
    char id[11];
    int grade;
}stu[MAX];

bool complare(struct Stu a, struct Stu b)
{
    return a.grade >= b.grade;
}

int main(void)
{
    int n, low, high;
    int cnt = 0;
    scanf("%d", &n); 
    for(int i = 0; i < n; i++)
        scanf("%s %s %d", stu[i].name, stu[i].id, &stu[i].grade); 
    scanf("%d %d", &low, &high);
    sort(stu, stu+n, complare);
    for(int i = 0; i < n; i++)
    {
        if(stu[i].grade >= low && stu[i].grade <= high)
        {
            printf("%s %s\n", stu[i].name, stu[i].id);
            cnt++;
        }
    }
    if(cnt == 0)
        printf("NONE");
    
    //system("pause");
    return 0;
} 