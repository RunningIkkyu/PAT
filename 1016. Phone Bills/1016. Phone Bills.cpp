#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <cstdio>
using namespace std;

struct record{
    string name;
    int dd;
    int hh;
    int mm;
    int t;
    string flag;
}records[1010], temp;

vector<record> first;
vector<record> second;

int rates[25], n, month;
char c;
long daycost = 0;

// compare function for sort.
bool compare(record a, record b){
    if(a.name < b.name) return true;
    if(a.name == b.name) return a.t < b.t; 
    return false;
}

// accumulate function.
long acmlt(record x){
    long res = x.dd * daycost + rates[x.hh] * x.mm;
    for(int i = 0; i < x.hh; i++) res += rates[i] * 60;
    //cout<<"##"<<x.dd<<" "<<x.hh<<" "<<x.mm<<" "<<res<<endl;
    return res;
}

void show_time(record x){
    cout<<setw(2)<<setfill('0')<<x.dd<<":";
    cout<<setw(2)<<setfill('0')<<x.hh<<":";
    cout<<setw(2)<<setfill('0')<<x.mm;
}

int main(void)
{
    for(int i = 0; i < 24; i++) {
        cin>>rates[i];
        // calculate the cost of one day.
        daycost += rates[i]*60;
    }
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>records[i].name>>month>>c>>records[i].dd>>c>>records[i].hh>>c>>records[i].mm>>records[i].flag;
        // convert dd::hh:mm time to minute.
        records[i].t = records[i].mm + records[i].hh * 60  + records[i].dd * 60 * 24;
    }
    sort(records, records + n, compare);
    double total = 0.0, cost = 0.0;
    int cnt = 0;
    string prename = "";
    for(int i = 1; i < n; i++){
        // if get paired.
        if(records[i].name == records[i-1].name && records[i].flag == "off-line" 
        && records[i-1].flag == "on-line"){
            first.push_back(records[i-1]);
            second.push_back(records[i]);
            cnt++;
        }
    }
    for(int i = 0; i < cnt; i++){
        if(first[i].name != prename){
            if(prename != "") {
                cout<<"Total amount: $";
                printf("%.2f\n", total);
            }
            total = 0.0;
            prename = first[i].name;
            cout<<first[i].name<<" "<<setw(2)<<setfill('0')<<month<<endl;
        }
        show_time(first[i]);cout<<" ";show_time(second[i]);cout<<" ";
        cout<<second[i].t - first[i].t<<" ";
        cost = double(acmlt(second[i]) - acmlt(first[i])) / 100.0;
        total += cost;
        printf("$%.2f\n", cost);
    }
    cout<<"Total amount: $";printf("%.2f", total);
    return 0;
}