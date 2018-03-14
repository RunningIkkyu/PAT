#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct node{
    string id;
    char sex;
    string name;
    int grade;
};

vector<node> male;
vector<node> female;

int main(void){
    int n;
    int flag = false;
    cin>>n;
    for(int i = 0; i < n; i++){
        node x;
        cin>>x.name>>x.sex>>x.id>>x.grade;
        if(x.sex == 'M') male.push_back(x);
        else female.push_back(x);
    }
    sort(male.begin(), male.end(), [](node a, node b){return a.grade < b.grade; });
    sort(female.begin(), female.end(), [](node a, node b){return a.grade > b.grade; });
    if(female.empty()){
        cout<<"Absent"<<endl;
        flag = 1;
    }else
        cout<<female[0].name<<" "<<female[0].id<<endl;
    if(male.empty()){
        cout<<"Absent"<<endl;
        flag = 1;
    }else
        cout<<male[0].name<<" "<<male[0].id<<endl;
    if(flag == false)  cout<<female[0].grade - male[0].grade<<endl;
    else cout<<"NA"<<endl;
    return 0;
}