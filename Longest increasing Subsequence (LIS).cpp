///time complexity O(n^2)
#include<bits/stdc++.h>
using namespace std;
vector<int>ls;
int longestIncresingSubsequence(int A[],int n)
{
    int temp[n+1];
    temp[0]=0;
    for(int i=1;i<n+1;i++) temp[i]=A[i-1];
    int L[n+1];///length
    L[0]=0;
    int prev[n+1];
    prev[0]=-1;
    int Max=L[0];
    for(int i=1;i<(n+1);i++){
        for(int j=0;j<i;j++){
            if(temp[j]<temp[i]){
                if(L[j]>=Max) Max=L[j];
                prev[i]=j;
            }
        }
        L[i]=1+Max;
        Max=0;
    }
    Max=0;
    int flag1,flag2;
    for(int i=0;i<(n+1);i++){
        if(L[i]>Max){
            Max=L[i];
            flag1=i;
            flag2=prev[i];

        }
    }
    int i=flag1;
    while(i>0){
        ls.push_back(temp[i]);
        i=prev[i];
    }
    return Max;
}
int main()
{
    int array[]={9,2,5,3,7,11,8,10,13,6};
    int n=sizeof(array)/sizeof(array[0]);
    int LIS;
    LIS=longestIncresingSubsequence(array,n);
    for(int i=ls.size()-1;i>=0;i--) cout<<ls[i]<<" ";
    cout<<endl;
    cout<<"LIS length:"<<LIS<<endl;
    return 0;
}
