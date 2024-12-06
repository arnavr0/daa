#include<bits/stdc++.h>
using namespace std;
float actsel(vector<float> s,vector<float>e)
{
    vector<pair<float,float>> items;
    float ans=0;
    for(int i=0;i<s.size();i++)
    {
       items.push_back({s[i],e[i]});
    }
    sort(items.begin(),items.end(),[](pair<float,float> &a,pair<float,float> b){
    return a.second<b.second;});
    int i=0;
    float cnt=1;
    cout<<items[i].first<<" "<<items[i].second<<endl;
    for(int j=1;j<s.size();j++)
    {
       if(items[j].first>=items[i].second)
       {
           cout<<items[j].first<<" "<<items[j].second<<endl;
           cnt++;
           i=j;
       }
    }
    return cnt;
}
int main() {
   vector<float> s={1,3,0,5,3,5,6,8,8,2,12};
   vector<float> e={4,5,6,7,8,9,10,11,12,13,14};

    float maxTotalValue = actsel(s,e);
    cout << "Maximum total value: " << maxTotalValue << endl;

    return 0;
}
