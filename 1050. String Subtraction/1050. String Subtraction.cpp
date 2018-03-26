#include <cstdio>
#include <cstring>
#include <iostream>
#define N 100010
using namespace std;

bool a[256];
char s1[N], s2[N];

int main(void){
    int n;
    cin.getline(s1, N);
    cin.getline(s2, N);
    int l1 = strlen(s1), l2 = strlen(s2);
    for(int i = 0; i < l2; i++) a[s2[i]] = true;
    for(int i = 0; i < l1; i++) 
        if(a[int(s1[i])] == false) 
            printf("%c", s1[i]);
    printf("\n");
    return 0;
}