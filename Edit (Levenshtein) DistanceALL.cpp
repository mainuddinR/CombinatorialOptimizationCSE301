#include<bits/stdc++.h>
using namespace std;
int minv(int a,int b,int c)
{
    if(a<=b&&a<=c) return a;
    else if(b<=a&&b<=c) return b;
    else if(c<=a&&c<=b) return c;
}
int main()
{
    string str1,str2;
    cin>>str1>>str2;
    int i,j,m,n;
    n=str1.length();
    m=str2.length();
    int ED[n+1][m+1];
    for(i=0; i<=n; i++)
    {
        for(j=0; j<=m; j++)
        {
            if(i==0||j==0)
            {

                ED[i][j]=max(i,j);
            }
            else
            {
                if(str1[i-1]==str2[j-1])
                {
                    ED[i][j]=ED[i-1][j-1];
                }
                else
                {
                    ED[i][j]=minv(ED[i-1][j-1],ED[i-1][j],ED[i][j-1])+1;
                }
            }
        }
    }
    for(i=0; i<=n; i++)
    {
        for(j=0; j<=m; j++)
        {
            cout<<ED[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Edit distance:"<<ED[n][m]<<endl;
    vector<string> seq;
    i=n;
    j=m;
    string str3;
    while(i>0&&j>0)
    {

        int p=minv(ED[i-1][j-1],ED[i-1][j],ED[i][j-1]);
        if(str1[i-1]==str2[j-1])
        {
            i--;
            j--;
        }

        else if(p==ED[i-1][j-1])
        {
            str3=str3+"replace ";
            str3=str3+str1[i-1];
            str3=str3+" with ";
            str3=str3+str2[j-1];
            seq.push_back(str3);
            i--;
            j--;
            str3="";
        }
        else if(p==ED[i-1][j])
        {
            str3=str3+"Delete ";
            str3=str3+str1[i-1];
            seq.push_back(str3);
            i--;
            str3="";
        }
        else if(p==ED[i][j-1])
        {
            str3=str3+"Insert ";
            str3=str3+str2[j-1];
            seq.push_back(str3);
            j--;
            str3="";
        }
    }
    while(i>0){
        str3=str3+"Delete ";
        str3=str3+str1[i-1];
        seq.push_back(str3);
        i--;
        str3="";
    }
    while(j>0){
        str3=str3+"Insert ";
        str3=str3+str2[j-1];
        seq.push_back(str3);
        j--;
        str3="";
    }
    int b=seq.size();
    for(int k=b-1,i=1;k>=0;k--,i++){
        cout<<i<<"."<<seq[k]<<endl;
    }
    return 0;
}

