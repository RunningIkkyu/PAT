#include<iostream> 
#include<string.h>
#include<string>
#include<vector> 
#include<algorithm> 
using namespace std;  
struct carslist
{
  char plate[9];
  int time;
  bool in;
};
void readln(vector<carslist>*cars, int N)
{
  int hh, mm, ss;
  char in_out[5];
  int index; 
  for (index = 0; index < N; index++)
  { 
    scanf("%s%d:%d:%d%s", (*cars)[index].plate, &hh, &mm, &ss,in_out);  
    //cin >> (*cars)[index].plate >> hh >> in_out[0] >> mm >> in_out[0] >> ss >> in_out; 
    (*cars)[index].time = hh * 3600 + mm * 60 + ss;
    (*cars)[index].in = in_out[0] == 'i' ? true : false; 
  }
}
bool everycarsTimecmp(const carslist&A, const carslist&B)
{
  if (strcmp(A.plate,B.plate)==0)return A.time < B.time;
  else return strcmp(A.plate, B.plate)<0;
}
bool TotalTimesort(const carslist&A, const carslist&B)
{
  return A.time < B.time;
}
int KickWrong_Addlongest(vector<carslist>*cars, vector<string>*staylongest)
{
  int maxTime = 0,ThecarmaxT=0;
  string Precar=(*cars)[0].plate;
  for (vector<carslist>::iterator iter = (*cars).begin(); iter != (*cars).end(); )
  {
    if (iter->in&&iter + 1 != (*cars).end() && strcmp(iter->plate, (iter + 1)->plate)== 0 && !(iter + 1)->in) /*in_out一定成对存在，题目要求*/
    {

      if (Precar == iter->plate) 
          ThecarmaxT += (iter + 1)->time - iter->time;/*累记一整天的停车时长*/ 
      else
      {
        Precar = iter->plate;
        ThecarmaxT = (iter + 1)->time - iter->time; 
      }
      if (maxTime < ThecarmaxT)
      {
        (*staylongest).clear();
        (*staylongest).push_back(Precar);
        maxTime = ThecarmaxT;
      }
      else if (maxTime == ThecarmaxT)
        (*staylongest).push_back(Precar);
      iter += 2;
    }
    else iter = (*cars).erase(iter); 
  }
  return maxTime;
} 
void read_ans(int K, vector<carslist>*cars)
{
  int hh, mm, ss,firstindex=0,cnt=0; 
  while (K--)
  {
    //cin >> hh >>maohao>> mm>>maohao >> ss;
    scanf("%d:%d:%d", &hh, &mm, &ss); 
    hh=hh*3600+mm*60+ss;
    for (; firstindex< (*cars).size()&&(*cars)[firstindex].time<=hh;firstindex++)  
      if ((*cars)[firstindex].in)
         cnt++; 
           else cnt--;   
      printf("%d\n",cnt);
  }
} 
int main()
{  
  int N, K;
  scanf("%d%d", &N, &K); 
  vector<carslist>cars(N);
  readln(&cars, N); 
  sort(cars.begin(), cars.end(), everycarsTimecmp);  
  vector<string>staylongest;
  N=KickWrong_Addlongest(&cars,&staylongest);
  sort(cars.begin(), cars.end(), TotalTimesort);   
  read_ans(K, &cars);
  for (vector<string>::iterator iter = staylongest.begin(); iter != staylongest.end(); iter++)
     printf("%s ", (*iter).c_str());
  printf("%02d:%02d:%02d\n", N / 3600, N % 3600 / 60, N % 60); 
  //system("pause");
  return 0;
}