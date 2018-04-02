#include <cstdio>
using namespace std;

long a[4];
long b[4];
int r[4] = {10000000, 17, 29, 0};
int main(void){
    int carry = 0;
    scanf("%ld.%ld.%ld", &a[0], &a[1], &a[2]);
    scanf("%ld.%ld.%ld", &b[0], &b[1], &b[2]);
    for(int i = 2; i >= 0; i--){
        long t = carry + a[i] + b[i];
        a[i] = t % r[i];
        if(i == 0) a[i] = t;
        carry = t / r[i];
    }
    printf("%ld.%ld.%ld\n", a[0], a[1], a[2]);
    return 0;
}