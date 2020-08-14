#include<iostream>
using namespace std;



void mst(int asd[][6],int r,int j)
{
    int par[r],vis[r],cas[r];
    int i;
    for(i=0;i<r;i++)
    {
        par[i]=-1;
        vis[i]=0;
        cas[i]=1;
    }
    vis[j-1]=1;
    for(int t=0;t<r;t++)
    {
       for(i=0;i<r;i++)
       {
           if(vis[i]==1&&cas[i]==1)
           {
               for(int h=0;h<r;h++)
               {
                   if(asd[i][h]==1&&vis[h]==0)
                   {
                       par[h]=i;

                       vis[h]=1;
                   }
               }
               cas[i]=2;
           }
       }
    }
    for(i=0;i<r;i++)
    {
        if(par[i]!=-1)
        {
            cout<<par[i]+1<<" "<<i+1<<",";
        }
    }
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
              asd[as[i][1]-1][as[i][0]-1]=1;
         }
mst(asd, r,5);
}
