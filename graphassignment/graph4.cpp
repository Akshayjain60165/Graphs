#include<iostream>
using namespace std;
void dfs(int asd[][6],int v,int arr[],int r)
{
    cout<<v<<" ";
    arr[v-1]=1;


    for(int i=0;i<r;i++)
    {
        if(arr[i]!=1&asd[v-1][i]!=0)
        {
            dfs(asd,i+1,arr,r);

        }
    }
}
void dfss(int asd[][6],int v,int r)
{
    int arr[r];
    for(int i=0;i<r;i++)
    {
        arr[i]=0;
    }
    dfs(asd,v,arr,r);
}
int main() {
    cout<<"Enter the number of nodes: ";
         int r;               //r=5, as given in questiom
         cin>>r;
         cout<<"\n";
         int as[7][2];    //number of edges
         int i,j;
         cout<<"Enter edges separated by a comma: ";
          int asd[6][6];
         for(i=0;i<r;i++){
            for(j=0;j<r;j++){
                    asd[i][j]=0;
            }
         }
         for(i=0;i<7;i++){
            for(j=0;j<2;j++){
                cin>>as[i][j];

            }

             asd[as[i][0]-1][as[i][1]-1]=1;
         }
         dfss(asd,5,r);
}
