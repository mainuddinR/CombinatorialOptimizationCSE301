#include<bits/stdc++.h>
using namespace std;
int main()
{
    int value[4]= {12,10,20,15};
    int w[4]= {2,1,3,2};
    int item[4]= {1,2,3,4};
    int P[5][5+1];

    for(int i=0;i<5;i++){
        P[i][0]=0;
    }
    for(int i=0; i<=5; i++)
    {
        P[0][i]=0;
    }

    for(int i=1; i<=4; i++)
    {
        for(int j=0; j<=5; j++)
        {
            if(j<w[i-1])
            {
                P[i][j]=P[i-1][j];

            }
            else
            {
                P[i][j]=max(P[i-1][j],(P[i-1][(j-(w[i-1]))]+value[i-1]));
            }
        }
    }
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<=5; j++)
        {
            cout<<P[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Maximum prodit:"<<P[4][5]<<endl;
    vector<int>it;
    int a,b;
    a=4;
    b=5;
    cout<<"Selected item: ";

   while (a >=0 && b >= 0) {
        if (P[a][b] != P[a - 1][b]) {
                it.push_back(item[a-1]);
           // cout << item[a-1] << " ";
            //cout<<w[1]<<endl;
           // cout<<w[a-1]<<" "<<endl;
            b -= w[a - 1];
        }
        a--;
    }

    for(int i=it.size()-2;i>=0;i--){ //(-2) because first value 0 .
        cout<<it[i]<<" ";
    }
    cout << endl;
    return 0;
}
