#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>

using namespace std;

int shop[200];          // each color she needs.
int eva[200];          // each color she needs.
int diff[200];          // the mount of shop's bread minus eva's needs.

int main(void)
{
    //freopen("in.txt", "r", stdin);
    char c;       // beads belong to shop
    char a[1000 + 10];
    char b[1000 + 10];
    bool flag = true;
    int miss = 0;
    int more = 0;
    memset(shop, 0, sizeof(shop));
    memset(eva, 0, sizeof(eva));
    memset(diff, 0, sizeof(diff));

    scanf("%s%s", a, b);
    for(int i = 0; a[i] != '\0'; i++)
        shop[a[i]]++;
    for(int i = 0; b[i] != '\0'; i++)
        eva[b[i]]++;
    for(int i =0; i < 200; i++)
    {
        diff[i] = shop[i] - eva[i];
        if(diff[i] < 0)
            miss += diff[i];
        else if(diff[i] > 0)
            more += diff[i];
    }
    if(miss != 0)
        printf("No %d", -miss);
    else
        printf("Yes %d", more);
    

}

