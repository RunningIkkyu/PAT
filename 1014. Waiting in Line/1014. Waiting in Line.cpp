#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>
using namespace std;

struct node{
    int poptime, endtime;
    queue<int> q;
};

int main(void){
    // variable defination.
    int n, m, k, q, index = 1;
    cin>>n>>m>>k>>q;
    
    vector<int> time(k+1), result(k+1);
    vector<node> window(n+1);
    // save the people cannot get servered before 5:00pm. 
    // sorry[i] is true if we have to say sorry to the i-th people.
    vector<bool> sorry(k+1, false);

    // input
     for(int i = 1; i <= k; i++) cin>>time[i];
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

    for(;index <= k; index++){
        int tempmin = window[1].poptime;
        int tempwindow = 1;
        // find the front people in all queue with the minimum serving time.
        for(int i = 2; i <= n; i++){
            if(window[i].poptime < tempmin){
                tempwindow = i;
                tempmin = window[i].poptime;
            }
        }
        // pop the min people and push people from the waiting line.
        window[tempwindow].q.pop();
        window[tempwindow].q.push(time[index]);
        // update the poptime of this window.
        window[tempwindow].poptime += window[tempwindow].q.front();
        // if the new coming can not get his serve before 5:00pm.
        if(window[tempwindow].endtime >= 540)
            sorry[index] = true;
        // update endtime of the window.
        window[tempwindow].endtime += time[index];
        // save his finished time.
        result[index] = window[tempwindow].endtime;
    }

    // input query and output result.
    for(int i = 1; i <= q; i++){
        int query, minute;
        cin>>query;
        minute = result[query];
        if(sorry[query] == true) cout<<"Sorry"<<endl;
        else {
            cout<<setfill('0')<<setw(2)<<(minute + 480) / 60;
            cout<<":";
            cout<<setfill('0')<<setw(2)<<(minute + 480) % 60<<endl;
        }
    }

    return 0;
}