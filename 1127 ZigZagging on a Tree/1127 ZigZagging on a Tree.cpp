#include<iostream>
#include <queue>
#include <vector>
#include <stack>
#define N 40
using namespace std;

struct node {
	int v;
	struct node *l;
	struct node *r;
};

queue<node * > q;
stack<node * > stk;
vector<node * > v;

node *ipcreate(int *in, int *post, int len){
	if(len == 0) return NULL;
	node *root = new node;
	int r = post[len-1];
	int ind = 0;
	for(;in[ind] != r; ind++);
	root->v = r;
	root->l = ipcreate(in, post, ind);
	root->r = ipcreate(in+ind+1, post+ind, len-ind-1);
	return root;
}


void sblevelorder(node *root){
	if(root == NULL) return;
	bool flag = true;
	node *sp = NULL;
	q.push(root);
	q.push(sp);
	while(q.size() != 1){
		node *x = q.front();
		if(x == NULL){
			q.pop();
			flag = !flag;
			while(stk.size() > 0){
				v.push_back(stk.top());
				stk.pop();
			}
			q.push(sp);
			continue;
		}
		if(flag == true){
			stk.push(x);
		}else{
			v.push_back(x);
		}
		q.pop();
		if(x->l) q.push(x->l);
		if(x->r) q.push(x->r);
	}
}

int main(void){
	int n;
	cin>>n;
	int in[N], post[N];
	for(int i = 0; i < n; i++) cin>>in[i];
	for(int i = 0; i < n; i++) cin>>post[i];
	node *root = ipcreate(in, post, n);
	sblevelorder(root);

	for(int i = 0 ; i < v.size(); i++) {
		if(i != 0) cout<<" ";
		cout<<v[i]->v;
	} cout<<endl;
	return 0;
}