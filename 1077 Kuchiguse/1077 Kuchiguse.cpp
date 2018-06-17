#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(void)
{
    int minlen = 257, num;
    string s[105];
    string sufix = "";
    bool endmark = false;
    char cur;
    cin>>num;getchar();
    for(int i=0; i<num; i++)
        getline(cin, s[i]);
    
     for(int i=0; i<num; i++) {
     if(s[i].length() < minlen) minlen = s[i].length();
     }

    for(int i=0; i<minlen; i++)  // for each position
    {
        endmark == false;
        cur = s[0][s[0].length()-1-i];  // currrent position char
        for(int j = 1; j<num; j++)
        {
            if(cur != s[j][s[j].length()-1-i]){  // if jth string i position from end is not match
               endmark = true; 
               break;
            }
        }
        if (endmark == false) sufix += cur;
    }
    if(sufix == "") cout<<"nai";
    else{
        for(int i=sufix.length()-1; i>=0; i--)
        {
                cout<<sufix[i];
        }
    }
    return 0;
    
} 