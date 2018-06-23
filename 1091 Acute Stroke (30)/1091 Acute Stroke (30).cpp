#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int matrix[1286][128][60];
int xx[6] = {1,-1,0,0,0,0};
int yy[6] = {0,0,1,-1,0,0};
int zz[6] = {0,0,0,0,1,-1};

struct node{
	int x, y, z;
	node(int _x, int _y, int _z){
		x=_x; y=_y; z=_z;
	}
};
int M,N,L,T,total=0;
void bfs(int x, int y, int z){
	queue<node> que;
	que.push(node(x,y,z));
	matrix[x][y][z] = 0;
	int cnt = 1;
	while(!que.empty()){
		node n = que.front();
		for(int i=0; i<6; i++){
			int tx = n.x+xx[i];
			int ty = n.y+yy[i];
			int tz = n.z+zz[i];
			if((tz<L && tz>=0 && tx<M && tx>=0 && ty<N && ty>=0) && matrix[tx][ty][tz]==1){
				matrix[tx][ty][tz] = 0;
				cnt++;
				que.push(node(tx,ty,tz));
			}
		}
		que.pop();		
	}	
	if(cnt>=T)
		total += cnt;
}

int main(int argc, char** argv) {
    //freopen("in.txt", "r", stdin);
	scanf("%d%d%d%d",&M,&N,&L,&T);
	int i, j, k;
	for(i=0; i<L; i++){
		for(j=0; j<M; j++)
			for(k=0; k<N; k++)
				scanf("%d",&matrix[j][k][i]);
	}
	
	for(i=0; i<L; i++){
		for(j=0; j<M; j++)
			for(k=0; k<N; k++)
				if(matrix[j][k][i]==1)
				  bfs(j,k,i);
	}
	cout<<total<<endl;
	return 0;
}

