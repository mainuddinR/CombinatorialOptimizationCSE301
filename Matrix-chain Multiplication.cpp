#include<bits/stdc++.h>
using namespace std;
int n=5;
int m[100][100];
vector<int> Matrix_Multiply(vector<int>A[],vector<int>B[],int a,int b,int p,int q)
{
    if(b!=p){
            printf("Incompatinle dimensions");
             vector<int>G;
            G.push_back(-1);
        return G;
    }
    vector<int>c[q];
    for(int i=0;i<a;i++){
        for(int j=0;j<q;j++){
            c[i][j]=0;
            for(int k=0;k<p;k++){
                c[i][j]=c[i][j]+A[i][k]*B[k][j];
            }
        }
    }
    return *c;
}
int RMC(int p[],int i,int j)
{
    if(i==j) return 0;
    int k;
    int minv=INT_MAX;
    for(k=i;k<j;k++){
        int q=RMC(p,i,k)+RMC(p,k+1,j)+p[i-1]*p[k]*p[j];
        minv=min(q,minv);
    }
    return minv;
}
int Matrix_chain_order(int p[],int n)
{

    int m[n][n];
    int i, j, k, L, q;

    for (i=1; i<n; i++)
        m[i][i] = 0;    //number of multiplications are 0(zero) when there is only one matrix

    //Here L is chain length. It varies from length 2 to length n.
    for (L=2; L<n; L++)
    {
        for (i=1; i<n-L+1; i++)
        {
            j = i+L-1;
            m[i][j] = INT_MAX;  //assigning to maximum value

            for (k=i; k<=j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;    //if number of multiplications found less that number will be updated.
                }
            }
        }
    }

    return m[1][n-1];
}
int main()
{
    //int n,m,q;

   int p[]={1,2,3,4};
   memset(m,-1,sizeof m);

   int n=sizeof(p)/sizeof(p[0]);
   int value=Matrix_chain_order(p,n);
    m[0][0]=0;
   cout<<"Minimum number of multiplications is :"<<value<<endl;
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++){
            cout<<m[i][j]<<" ";
       }
       cout<<endl;
   }
   return 0;

}
