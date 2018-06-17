#include <cstdio>
#include <cctype>
using namespace std;


int key[105];           

int main(void)
{
    //freopen("in.txt", "r", stdin);
    char a[85];       // save correct string.
    char b[85];       // save broken string.
    int i = 0;

    scanf("%s%s", a, b);
    for(int i = 0; b[i] != '\0'; i++)
    {
        b[i] = toupper(b[i]);
        key[b[i]] = 1;
    }
    for(int i = 0; a[i] != '\0'; i++)
    {
        a[i] = toupper(a[i]);
        if(key[a[i]] == 0)
        {
            printf("%c", a[i]);
            key[a[i]] = 1;
        }
    }
    return 0;
}