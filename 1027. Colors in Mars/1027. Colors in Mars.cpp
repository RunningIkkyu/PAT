// gread idea from liuchuo.
#include <cstdio>
using namespace std;

int main(void){
    char c[14] = {"0123456789ABC"};
    printf("#");
    for(int i = 0; i < 3; i++){
        int num;
        scanf("%d", &num);
        printf("%c%c", c[num/13], c[num%13]);
    }
}