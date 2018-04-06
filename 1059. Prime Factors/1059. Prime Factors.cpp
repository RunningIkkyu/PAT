#include <cstdio>
#define N 1000000
using namespace std;

int prime[N], cnt = 0;
int factors[N];
bool p[N];

// get prime number char by using the Sieve of Eratosthenes algorithm. 
void FindPrime(){
    for(int i = 2; i < N; i++){
        if(p[i] == false){
            prime[cnt++] = i;
            for(int j = i + i; j < N; j += i)
                p[j] = true;
        }//if
    }//for
}

int main(void){
    int n;
    bool flag = true;
    scanf("%d", &n);
    FindPrime();
    printf("%d=", n);
    // test point 3.
    if(n == 1) {printf("1\n"); return 0;}
    for(int i = 0; i < cnt; i++){
        while(n % prime[i] == 0){
            factors[prime[i]]++;
            n = n / prime[i];
        }
        if(n == 1) break;
    }
    for(int i = 0; i < N; i++){
        if(factors[i] > 0){
            printf("%s%d", flag==false?"*":"", i);
            if(factors[i] > 1) printf("^%d", factors[i]);
            flag = false;
        } 
    }
    if(n > 2) printf("*%d\n", n);
    return 0;
}