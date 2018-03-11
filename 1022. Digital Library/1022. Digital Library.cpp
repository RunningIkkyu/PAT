#include <iostream>
#include <cstdio>
#include <set>
#include <map>
using namespace std;
map<string, set<int>> query[6];
int main(void){
    int n, m, num, id;
    string t;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>id;
        for(int j = 0; j < 6; j++){
            if(j != 3){
                getline(cin, t);
                query[j][t].insert(id);
            }//if
            else{
                while(cin>>t){
                    query[j][t].insert(id);
                    char c = getchar();
                    if(c == '\n') break;
                }//while
            }//else
        }//for
    }//for
    cin>>m;
    for(int i = 0; i < m; i++){
        scanf("%d", &num);
        getchar();getchar();
        getline(cin, t);
        cout<<num<<": "<<t<<endl;
        if(query[num].find(t) != query[num].end())
            for(auto it = query[num][t].begin(); it != query[num][t].end(); it++)
                printf("%07d\n", *it);
        else
            printf("Not Found\n");
    }
    return 0;
}