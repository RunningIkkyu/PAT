#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;


char a[5], b[5];

int calmi(char a[], char b[]){ 
    int x = 0, y = 0;
    sscanf(a, "%d", &x);
    sscanf(b, "%d", &y);
    return x-y;
}

int main(void){
    int t;
    scanf("%s", &a);
    sscanf(a, "%d", &t);
    sprintf(a, "%04d", t);
    do{
        sort(a, a+4, [](char x, char y){return x > y;});
        strcpy(b, a);
        sort(b, b+4);
        t = calmi(a, b);
        printf("%04s - %04s = %04d\n", a, b, calmi(a, b));
        sprintf(a, "%04d", t);
    }while(t != 6174 && t != 0);
    return 0;
} 

