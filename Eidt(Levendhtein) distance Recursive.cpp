#include<bits/stdc++.h>
using namespace std;
int minv(int a,int b,int c)
{
    if(a<=b&&a<=c) return a;
    else if(b<=a&&b<=c) return b;
    else if(c<=a&&c<=b) return c;
}
int Edit_Distance(string str1,string str2,int n,int m)
{
    if(m==0)
    {
        return n;
    }
    if(n==0)
    {
        return m;
    }
    if(str1[n-1]==str2[m-1])
    {
        return Edit_Distance(str1,str2,n-1,m-1);
    }
    else
    {
        int k=1+minv(Edit_Distance(str1,str2,n-1,m-1),Edit_Distance(str1,str2,n,m-1),Edit_Distance(str1,str2,n-1,m));
        return k;
    } ///n-1,m-1 replace;
    ///n,m-1 insert;
    ///n-1,m  deleted;
}
vector<string> sequance(string str1,string str2)
{
    vector<string> seq;
    string str3;
    int n,m;
    n=str1.length();
    m=str2.length();
    int k;
    while(n>0&& m>0)
    {
        k=minv(Edit_Distance(str1,str2,n-1,m-1),Edit_Distance(str1,str2,n,m-1),Edit_Distance(str1,str2,n-1,m));
        if(str1[n-1]==str2[m-1])
        {
            n--;
            m--;
        }
        else if(k==Edit_Distance(str1,str2,n-1,m-1))
        {
            str3=str3+"replace ";
            str3=str3+str1[n-1];
            str3=str3+" with ";
            str3=str3+str2[m-1];
            seq.push_back(str3);
            m--;
            n--;
            str3="";
        }
        else if(k==Edit_Distance(str1,str2,n-1,m))
        {
            str3=str3+"Delete ";
            str3=str3+str1[n-1];
            seq.push_back(str3);
            n--;
            str3="";
        }
        else if(k==Edit_Distance(str1,str2,n,m-1))
        {
            str3=str3+"Insert ";
            str3=str3+str2[m-1];
            seq.push_back(str3);
            m--;
            str3="";
        }
    }
    while(n>0)
    {
        str3=str3+"Delete ";
        str3=str3+str1[n-1];
        seq.push_back(str3);
        n--;
        str3="";
    }
    while(m>0)
    {
        str3=str3+"Insert ";
        str3=str3+str2[m-1];
        seq.push_back(str3);
        m--;
        str3="";
    }
    return seq;

}
int main()
{
    string str1,str2;
    int i,j;
    cin>>str1>>str2;
    cout<<"Edit Distance:"<<Edit_Distance(str1,str2,str1.length(),str2.length())<<endl;
    vector<string> seq;
    seq=sequance(str1,str2);
    int b=seq.size();
    for(int k=b-1,i=1; k>=0; k--,i++)
    {
        cout<<i<<"."<<seq[k]<<endl;
    }
    return 0;
}
