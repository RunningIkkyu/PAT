#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node{
    int poptime, endtime;
    queue<int> q;
}
int main(void){
    // variable defination.
    int n, m, k, q, index = 1;
    cin>>n>>m>>k>>q;
    vector<int> time(k+1), result(k+1)
    vector<node> window(n+1);
    vector<bool> sorry(k+1, false);
    // input
    for(int i = 1; i <= k; i++) cin>>time[i];
    for(int ind = 1; ind <= k; ind++) {
        cin>>time[ind];
        if(ind <= m*n){
            // window number.
            int i = (ind-1)%3+1;
            // j means the j-th people in one line.
            int j = (ind-1)/3;
            window[i].q.push(time[ind]);
            if(window[i].endtime > 540) sorry[index] = true;
            window[i].endtime += time[i];
            if(ind == 1)
                window[i].poptime = window[i].endtime;
            result[ind] = window[i].endtime;
        }
        else
            index = ind;
    }
    /*
    // put back all people with index not above n*m.
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(index <= k){
                window[j].q.push(time[index]);
                // mark the people should output sorry.
                if(window[j].endtime >= 540)
                    sorry[index] = true;
                // update endtime.
                window[j].endtime += time[index];
                // if there's only one people in the queue.
                if(i == 1) 
                    window[j].poptime = window[j].endtime;
                // save the endtime of every people.
                result[index] = window[j].endtime;
                index++;
            }//if
        }//for
    }//for
    */

    while(index <= k){
        int tempmin = window[1].poptime;
        int tempwindow = -1;
        for(int i = 2; i <= n; i++){
            if(window[i].poptime < tempmin){
                tempwindow = i;
                tempmin = window[i].poptime;
            }
        }

    }

    return 0;
}