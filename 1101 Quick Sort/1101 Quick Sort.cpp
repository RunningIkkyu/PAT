#include <cstdio>

bool left[100000 + 10];
int cnt = 0;
int a[100000 + 10];

int main(void)
{
    int n, j;
    int lmax = -1, rmin = 0x7fffffff;
    //freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        if(a[i] > lmax)
        {
            lmax = a[i];
            left[i] = true;
        }
        else
            left[i] = false;
    }
    for(int i = n - 1; i >= 0; i--){
        if(a[i] < rmin){
            rmin = a[i];
            if(left[i] == true) cnt++;
        }
        else
            left[i] = false;
    }
    printf("%d\n", cnt);

    bool flag = false;
    for(int i = 0; i < n; i++){
        if(left[i] == true){
            if(flag == true) printf(" ");
            printf("%d", a[i]);
            flag = true;
        }
    }
    printf("\n");

    return 0;
}