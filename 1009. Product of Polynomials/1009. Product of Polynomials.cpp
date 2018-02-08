#include <iostream>
#include <iomanip>
#include <cmath>        // stuck here once.
#include <algorithm>
#define N 3015          // stuct here once.
using namespace std;

int main(void)
{
    double coefficients_1[N], coefficients_2[N], co;
    int ex, k1, k2, cnt = 0;

    // init 
    fill(coefficients_1, coefficients_1+N, 0);
    fill(coefficients_2, coefficients_2+N, 0);

    // input handling
    cin>>k1;
    for(int i = 0; i < k1; i++){
        cin>>ex>>co;
        coefficients_1[ex] = co;
    }
    cin>>k2;
    for(int j = 0; j < k2; j++) {
        cin>>ex>>co;
        // stuck here once.
        for(int i = 0; i < N; i++)
            // coefficients_2 save the result.
            if(coefficients_1[i] > 1e-6)
                coefficients_2[ex+i] += co * coefficients_1[i];
    }

    // count the number of non-zero terms.
    for(int i = 0; i < N; i++) if(abs(coefficients_2[i]) > 1e-6) cnt++;

    // output
    cout<<cnt;
    for(int i = N-1; i >= 0 ; i--){
        if(abs(coefficients_2[i]) > 1e-6){
            cout<<" "<<i;
            cout<<setiosflags(ios::fixed)<<setprecision(1)<<" "<<coefficients_2[i];
        }
    }
    return 0;
}
