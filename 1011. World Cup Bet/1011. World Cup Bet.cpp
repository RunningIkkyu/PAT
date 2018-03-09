#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

int main(void)
{
    double odds[3][3];
    double production = 1.0;
    map<int, char> getIndex;
    getIndex[0] = 'W';
    getIndex[1] = 'T';
    getIndex[2] = 'L';

    for(int i = 0; i < 3; i++){
        int max = 0;    // save the index of max number of each line.
        for (int j = 0; j < 3; j++){
            cin>>odds[i][j];
            // get the index of the maximum number in each line.
            if(odds[i][j] > odds[i][max])
                max = j;
        }
        if(i != 0) cout<<" ";
        // print the column of maxium index
        cout<<getIndex[max];
        // calculate the production of all selected odds.
        production *= odds[i][max];
    }
    cout<<" "<<setiosflags(ios::fixed)<<setprecision(2)<<(production*0.65-1)*2.0 + 0.001<<endl;
    return 0;
}