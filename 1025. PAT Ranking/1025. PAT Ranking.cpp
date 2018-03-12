#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
    string id;
    int score;
    int final_rank;
    int local_number;
    int local_rank;
};

// t is temp variable to save each region students.
vector<node> t;
// l is the list of all students.
vector<node> l;

// compare function for sort. 
bool compare(node a, node b){
    if(a.score == b.score) return a.id < b.id;
    return a.score > b.score;
}

int main(void){
    int n, k;
    cin>>n;
    for(int j = 1; j <= n; j++){
        cin>>k;
        if(k == 0) continue;
        t.clear();
        // input of each region and save to vector t.
        for(int i = 1; i <= k; i++){
            node temp;
            cin>>temp.id>>temp.score;
            temp.local_number = j;
            t.push_back(temp);
        }
        // sort this region be their score.
        sort(t.begin(), t.end(), compare);

        // the part below is to calculate the local_rank of each student in this region.
        t[0].local_rank = 1;
        // t[o]'s local rank has been known, so added it to the final list.
        l.push_back(t[0]);  
        for(int i = 1 ; i < t.size(); i++){
            if(t[i].score == t[i-1].score) t[i].local_rank = t[i-1].local_rank;
            else t[i].local_rank = i+1;
            l.push_back(t[i]);  // add each student to the final list.
        }
    }
    // sort the finnal list by their score.
    sort(l.begin(), l.end(), compare);
    // get final rank of all students. and output result by the way.
    l[0].final_rank = 1;
    cout<<l.size()<<endl;
    cout<<l[0].id<<" "<<l[0].final_rank<<" "<<l[0].local_number<<" "<<l[0].local_rank<<endl;
    for(int i = 1 ; i < l.size(); i++){
        if(l[i].score == l[i-1].score) l[i].final_rank = l[i-1].final_rank;
        else l[i].final_rank = i+1;
        cout<<l[i].id<<" "<<l[i].final_rank<<" "<<l[i].local_number<<" "<<l[i].local_rank<<endl;
    }
    return 0;
}