#include <cstdio>
using namespace std;
int num[1000];

int main(void)
{
    long a, b;
    int cnt;
    bool flag = true;
    scanf("%d%d", &a, &b);
    if(a == 0){
        printf("Yes\n");
        printf("0\n");
        return 0;
    }
    for(cnt = 0; a != 0; a /= b){
        num[cnt++]  = a % b;
    }
    for(int i = 0; i <= cnt/2; i++){
        if(num[i] != num[cnt-1-i])
            flag = false;
    }
    if(flag)
        printf("Yes\n");
    else
        printf("No\n");
    for(int i = cnt-1; i >= 0; i--) {
        if(i != cnt-1) printf(" ");
        printf("%d", num[i]);
    }
    return 0;
}