#include <cstdio>
#include <algorithm>
#include <cstring>
#define N 30
using namespace std;

int digit[100];
char a[N];
int main(void){
    fill(digit, digit + 10, 0);
    scanf("%s", &a);
    int l = strlen(a), carry = 0;
    for(int i = l-1; i >= 0; i--){
        digit[a[i]]++;
        int t = a[i] - '0';
        a[i] = (t * 2 + carry) % 10 + '0';
        carry = (t * 2 + carry) / 10;
        digit[a[i]]--;
    }
    bool flag = true;
    for(int i = 0; i < 100; i++) if(digit[i] != 0) flag = false;
    if(carry != 0) flag == false;
    printf("%s", flag?"Yes\n":"No\n");
    if(carry) printf("%c", carry+'0');
    printf("%s\n", a);
    return 0;
}