#include<iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define N 40
using namespace std;

struct node {
	int v;
	struct node *l;
	struct node *r;
};

queue<node * > q;
vector<node * > v;
vector <node *> level[30];

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


void getlevelorder(node *root){
	if(root == NULL) return;
	node *sp = NULL;
	q.push(root);
	q.push(sp);
	int ind = 0;
	while(q.size() > 1){
		node *x = q.front();
		q.pop();
		if(x == NULL){
			ind++;
			q.push(sp);
			continue;
		}
		else{
			level[ind].push_back(x);
		}
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
	getlevelorder(root);
	bool flag = false;
	for(int i = 0; i < 30; i++){
		if(level[i].size() == 0) break;
		if(i%2 == 0)
			reverse(level[i].begin(), level[i].end());
		for(int j = 0; j < level[i].size(); j++){
			if(flag == true) cout<<" ";
			cout<<level[i][j]->v;
			flag = true;
		}
	}
	return 0;
}