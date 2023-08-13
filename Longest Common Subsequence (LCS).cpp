#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str1,str2;
    cin>>str1>>str2;
    int i,j,n,m;
    n=str1.length();
    m=str2.length();
    int LCS[n+1][m+1];
    for(i=0;i<=n;i++){
        for(j=0;j<=m;j++){
            if(i==0||j==0){
                LCS[i][j]=0;
            }
            else{
                if(str1[i-1]==str2[j-1]){
                    LCS[i][j]=LCS[i-1][j-1]+1;
                }
                else{
                    LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
                }
            }
        }
    }
    for(i=0;i<=n;i++){
        for(j=0;j<=m;j++){
            cout<<LCS[i][j]<<"  ";
        }
        cout<<endl;
    }
    i=n;
    j=m;
    string lcs;
    cout<<n<<" "<<m<<endl;
    while(i>0&&j>0){
        if(str1[i-1]==str2[j-1]){
            lcs=str1[i-1]+lcs;
            i--;
            j--;
        }
        else if(LCS[i][j-1]>=LCS[i-1][j]){
            j--;
        }
        else{
            i--;
        }
    }
    cout<<"Longest Common Subsequence: "<<lcs<<endl<<"Max length:"<<LCS[n][m]<<endl;
    return 0;
}
