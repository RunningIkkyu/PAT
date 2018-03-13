#include <cstdio>
#include <cmath>
#define N 100010
using namespace std;

struct node {
    char data;
    int next;
    bool flag;
}l[N];

int main(void){
    int s1, s2, n;
    int a, c; char b;
    scanf("%d %d %d", &s1, &s2, &n);
    for(int i = 0; i < n; i++){
        scanf("%d %c %d", &a, &b, &c);
        l[a] = {b, c, false};
    }
    for(int i = s1; i != -1; i = l[i].next)
        l[i].flag = true;

    for(int i = s2; i != -1; i = l[i].next){
        if(l[i].flag == true) {
            printf("%05d", i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}