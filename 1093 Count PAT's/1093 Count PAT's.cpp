#include <iostream>
#include <cstdlib>

using namespace std;

int main(void)
{
    string a;
    int p = 0, pa = 0, pat = 0;
    //freopen("in.txt", "r", stdin);
    cin>>a;
    for(int i = 0; i < a.size(); ++i){
        if(a[i] == 'P') p++;
        else if (a[i] == 'A') pa += p;
        else if (a[i] == 'T') pat += pa;
        if(pat > 1000000007)
            pat = pat % 1000000007;
    }
    cout<<pat<<endl;
    return 0;
}