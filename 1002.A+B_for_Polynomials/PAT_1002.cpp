#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

// 1005 is to make sure the coefficients array is big enough
float coefficients[1005];

int main(void)
{
    int k, ex;
    float co; 

    // init coefficients array by zero.
    memset(coefficients, 0, sizeof(coefficients));  // init coefficients with zero.

    // handle input.
        cin>>k;
        while(k--){
            cin>>ex>>co;
            coefficients[ex] += co;
        }
        cin>>k;
        while(k--){
            cin>>ex>>co;
            coefficients[ex] += co;
        }
    // record mounts of nonzero terms.
    int count = 0;
    for(int i = 0; i < 1002; i++) if(coefficients[i]) count += 1;
    cout<<count;

    // output each nonzero terms from large to small.
    for(int i = 1004; i >= 0; i--){
        if(coefficients[i]) cout<<" "<<i<<" "<<setiosflags(ios::fixed)<<setprecision(1)<<coefficients[i];
    }
    cout<<endl;
    return 0;
}
