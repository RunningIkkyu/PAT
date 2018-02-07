#include <iostream>

using namespace std;

int time2second(int h, int m, int s){return h*60*60 + m*60 + s;}

int main(void)
{
    int n, h, m, s;
    // eat ":"
    char t;
    int min_time = 90000, max_time = -1;
    string first_in, last_out, tmp;
    
    // input handling and solve the problem.
    cin>>n;
    while(n--){
        cin>>tmp;
        cin>>h>>t>>m>>t>>s;
        // if the time this stuff come is the earlist.
        if(time2second(h, m, s) < min_time){
            // marked him/her as the first_in people.
            first_in = tmp;
            // save the earlist time.
            min_time = time2second(h, m, s);
        }
        cin>>h>>t>>m>>t>>s;
        // if the time this stuff leave is the lastest.
        if(time2second(h, m, s) > max_time){
            // marked him/her as the last_out people.
            last_out = tmp;
            // save the lastest time.
            max_time = time2second(h, m, s);
        }
    }
    cout<<first_in<<" "<<last_out<<endl;
    return 0;
}