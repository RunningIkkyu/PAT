#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int n;
stack<int> sta;
vector<int> preorder;
vector<int> inorder;
vector<int> postorder;

void getpostorder(int root_in_preorder, int start_in_inorder, int end_in_inorder){
    if(start_in_inorder > end_in_inorder) return;
    int i = start_in_inorder;
    while(i < end_in_inorder && inorder[i] != preorder[root_in_preorder]) i++;
    getpostorder(root_in_preorder+1, start_in_inorder, i-1);
    getpostorder(root_in_preorder+1 + i - start_in_inorder, i+1, end_in_inorder);
    postorder.push_back(preorder[root_in_preorder]);
}
 
int main(void){
    string s;
    int t;
    cin>>n;
    for(int i = 0; i < 2*n; i++){
        cin>>s;
        if(s == "Push"){
            cin>>t;
            sta.push(t);
            preorder.push_back(t);
        }
        else{
            t = sta.top();
            sta.pop();
            inorder.push_back(t);
        }
    }
    getpostorder(0, 0, n-1);
    cout<<postorder[0];
    for(int i = 1; i < n; i++){
        cout<<" "<<postorder[i];
    }
    cout<<endl;
    return 0;

}
