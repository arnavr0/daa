#include <iostream>
#include <vector>
#include <climits>
using namespace std;
vector<int> maxcrossingsubarray(vector<int> &A, int low, int mid, int high)
{
    int leftsum=INT_MIN;
    int sum=0;
    int maxleft, maxright;
    for (int i=mid; i>=low; i--)
    {
        sum=sum+A[i];
        if(sum>leftsum)
        {
            leftsum=sum;
            maxleft=i;
        }
    }
    int rightsum=INT_MIN;
    sum=0;
    for (int i=mid+1; i<=high; i++)
    {
        sum=sum+A[i];
        if(sum>rightsum)
        {
            rightsum=sum;
            maxright=i;
        }
    }
    vector<int> result;
    result.push_back(maxleft);
    result.push_back(maxright);
    result.push_back((leftsum+rightsum));
    return result;  
}
vector<int> maxsubarray(vector<int> &A, int low, int high)
{
   
    if (high==low)
    {
        vector<int> result1;
        result1.push_back(low);
        result1.push_back(high);
        result1.push_back(A[low]);
        return result1;
    }
    else
    {
       
        int mid=(low+high)/2;
        vector<int> ans1=maxsubarray(A,low,mid);

        int leftsum=ans1[2];
       

        vector<int> ans2=maxsubarray(A,mid+1,high);
     
        int rightsum=ans2[2];
       

        vector<int> ans3=maxcrossingsubarray(A, low, mid, high);
       
        int crosssum=ans3[2];
       

        if(leftsum>=rightsum && leftsum>=crosssum)
        {
            return ans1;
        }
        else if (rightsum>=leftsum && rightsum>=crosssum)
        {
            return ans2;
        }
        else
        {
            return ans3;
        }
    }
}
int main()
{
    vector<int> ans={2,-5,8,6,-2,5};
    int n=ans.size();
    vector<int> result=maxsubarray(ans,0,n-1);
    for (auto it:result)
    {
        cout<<it<<" ";
    }
    return 0;
}



