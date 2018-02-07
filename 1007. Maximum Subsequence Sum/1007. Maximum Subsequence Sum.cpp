#include <iostream>
#define N 10010

using namespace std;

int main(void)
{
    // variable defination.
    int k; 
    int num[N];
    // max_i and max_j are the start and end index of the maximum sequence.
    int max_i = 0, max_j = 0;
    int max_sum = -1;   // save the sum of maxium sequence.
    int sum = 0;        // the sum of current sequence.
    int start = 0;      // the start index of current sequence.
    
    // input handling.
    cin>>k;
    for(int i = 0; i < k; i++) cin>>num[i];

    // for each element, add it into sum.
    for(int i = 0; i < k; i++){
        sum += num[i];
        // if the sum of current sequence is bigger than max_sum.
        // save the max value, start index and end index.
        if(sum > max_sum) {
            max_sum = sum;
            max_i = start;
            max_j = i;
        }
        // if current sum below zero, then drop it. 
        // and update start index and clear the value of sum.
        if(sum < 0) {
            start = i + 1;
            sum = 0;
        }
    }

    // if maxiumum sum below zero, that means all the numbers are negative.
    if(max_sum < 0){
        max_i = 0;
        max_j = k-1;
        max_sum = 0;
    }

    // output the result.
    cout<<max_sum<<" "<<num[max_i]<<" "<<num[max_j]<<endl;
    return 0;
}