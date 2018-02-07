#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    int n;
    int cur_level = 0;
    int pre_level = 0;
    int step =  0;
    int time = 0;
    cin>>n;
    while(n--){
        cin>>cur_level;
        step = cur_level - pre_level;
        if(step > 0) time +=  step*6;
        else time += abs(step) *4;
        time += 5;
        pre_level = cur_level;
    }
    cout<<time<<endl;
    return 0;
}