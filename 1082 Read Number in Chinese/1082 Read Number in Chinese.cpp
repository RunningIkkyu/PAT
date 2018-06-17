#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

char digitname[][10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main(void)
{
     char s[11];
     char sign;
     int digitlen = 0;
     int pos;
     int flag = 0;  //zero flag
     scanf("%s", s);
     if(s[0] == '-') 
     {
         printf("Fu ");
         for(int i=0; i<strlen(s);i++)
            s[i] = s[i+1];
     }
     digitlen = strlen(s);
     if(strcmp(s, "0") == 0){
          printf("ling");return 0;
          
     }
     for(int i=0; i<strlen(s); i++)
     {
         
          pos = strlen(s) - i -1;
          if(s[i] == '0') 
          {
              flag ++;  // if find zero change flag
              
          }
          else{
              if(pos == 3 || pos == 7) flag = 0;
              if(flag > 0) // check if there is zero before
              { 
          
                  printf(" ling");
                  flag = 0;
              }
              flag = 0;
              if(i != 0) printf(" ");
              printf("%s", digitname[s[i]-'0']);
              if(pos%4 == 1) printf(" Shi");
              else if(pos%4 == 2) printf(" Bai");
              else if(pos%4 == 3) printf(" Qian"); 
          }
          if(pos/4 == 2 &&pos%4 == 0) printf(" Yi");   
          else if(pos/4 == 1 && pos%4 == 0 && flag != 4) printf(" Wan");
     } 
     
     
     //system("pause");
     return 0;
}