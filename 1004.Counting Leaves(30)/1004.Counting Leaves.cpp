#include <iostream>
#include <algorithm>
using namespace std;

int tree[105];          // tree[i] saves node-i's parents.
int visited[105];       // nonleaf node marked 1, leafnode markded zero.
int level_cnt[100];     // level_cnt[i] indicates the number of leaf node in i level.
int max_level = -1;     // save the max level of this tree.

// calculate the level where the leaf-node id located.
void cal_level(int id, int depth)
{
    // almost forget this statement.
    visited[id] = 1;
    // exit of recusion, when current node is root, end this calculation up.
    if(id == 1){
        level_cnt[depth]++;
        // update max_level
        max_level = max(max_level, depth);
        return;
    }
    // calculate the depth of [id]'s parents by recursion.
    cal_level(tree[id], depth+1);
}

// what we supposed to do is finding the level of leaf node, and see how many
// of these node in every level. From given input, We can figure out which part 
// is non-leaf node, and the other nodes in the input is leaf nodes. So what we
// gonna to do is count these nodes' level and save number of leaf node in each
// level.
int main(void)
{
    int n, m, id_tmp, k, tmp;

    // initial array.
    fill(tree, tree+105, -1);
    fill(visited, visited+105, -1);
    fill(level_cnt, level_cnt+100, 0);

    // Input handling
    cin>>n>>m;

    // In case that there's only root node. 
    // The code cannot passes third test point without this statement.
    if (m==0) visited[1] = 0;

    // Input handling
    for(int i = 0; i < m; i++){
        cin>>id_tmp>>k;
        // marked non-leaf node.
        visited[id_tmp] = 1;
        while(k--){
            cin>>tmp;
            // if node-tmp do not have children, then marked as leaf node.
            if(visited[tmp] != 1) visited[tmp] = 0;
            // tree[tmp] point to their parents.
            tree[tmp] = id_tmp;
        }
    }

    for(int i = 0; i < 100; i++){
        // for each leaf node, calculate its depth and add to level_cnt.
        if(visited[i] == 0) 
            cal_level(i, 0);
    }

    // in case that there's only root node in the tree.
    if (max_level == -1) max_level = 0;

    // print level_cnt from first level  to maximum level.
    for(int i = 0; i <= max_level; i++){
        if(i != 0) cout<<" ";
        cout<<level_cnt[i];
    }
    return 0;
}