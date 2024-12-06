#include<bits/stdc++.h>
using namespace std;
float fracknap(vector<float> &profit ,vector<float> &weight,int w)
{
    vector<pair<float,int>> p;
    vector<pair<int ,float>> items;
    float ans=0;
    for(int i=0;i<profit.size();i++)
    {
       p.push_back({profit[i]/weight[i],i});
    }
    sort(p.begin(),p.end(),[](pair<float,int> &a,pair<float,int> b){
    return a.first>b.first;});
   for(auto it:p)
   {
      int index=it.second;
      if(weight[index]<=w)
      {
         ans+=profit[index];
         w-=weight[index];
         items.push_back({index+1,1});
      }
      else
      {
        ans+=(w/weight[index])*profit[index];
        items.push_back({index+1,w/weight[index]});
        break;
       }
    }
    for(auto it:items)
    {
      cout<<"item no. :"<<it.first<<" "<<it.second<<endl;
   }
    return ans;
}
int main() {
    int capacity = 17;
   vector<float> profit={5,10,15,7,8,9,4};
   vector<float>weight={1,3,5,4,1,3,2};

    float maxTotalValue = fracknap(profit,weight,capacity);
    cout << "Maximum total value: " << maxTotalValue << endl;

    return 0;
}