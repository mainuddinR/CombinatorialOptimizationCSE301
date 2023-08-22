#include<bits/stdc++.h>
using namespace std;
void MaxSumInterval(int A[],int n)
{
    int prev[n+1];
    int sum[n];
    for(int i=0;i<n;i++) sum[i]=0;
    sum[0]=A[0];
    prev[0]=0;
    for(int i=1;i<n;i++){
        sum[i]=A[i]+sum[i-1];
         prev[i]=i-1;
        if(A[i]>sum[i]){
            sum[i]=A[i];
            prev[i]=0;
        }
    }
   // print_MaxSumInterval(prev,i)
   /*for(int i=0;i<n;i++){
    cout<<sum[i]<<" ";
   }
   cout<<endl;
    for(int i=0;i<n;i++){
    cout<<prev[i]<<" ";
   }
    cout<<endl;*/
   int m,pos,c=0;
   m=sum[0];
   int flag;
   for(int i=1;i<n;i++){
    if(sum[i]>m){
        m=sum[i];
        pos=prev[i];
         flag=i;
    }
   }
   for(int i=flag;i>=0;i--){
        c++;
        if(prev[i]==0)
        {
            flag=i;
         break;
        }
   }
   cout<<"Maximum sum Interval:"<<endl;
   for(int i=flag+1;i<(c+flag+1);i++)
    cout<<A[prev[i]]<<" ";
    cout<<endl;
    cout<<"with sum:"<<m<<endl;

}
int main()
{
    int Array[]={9,-3,1,7,-15,2,3,-4,2,-7,6,-2,8,4,-9};
    int n=sizeof(Array)/sizeof(Array[0]);
    MaxSumInterval(Array,n);
    return 0;
}
