#include <iostream>
using namespace std;

struct node{
    string s;
    struct node *left;
    struct node *right;
};

int main(void){
    int n, l, r;
    string t;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>t>>l>>r;
    }
    return 0;
}