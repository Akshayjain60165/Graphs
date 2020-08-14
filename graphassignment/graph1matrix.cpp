//adjacency matrix
#include<iostream>
using namespace std;

int main(){
         cout<<"Enter the number of nodes: ";
         int r;               //r=5, as given in questiom
         cin>>r;
         cout<<"\n";
         int as[7][2];    //number of edges
         int i,j;
         cout<<"Enter edges separated by a comma: ";
          int asd[r][r];
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
 cout<<"Given a vertex, compute out-degree/in-degree of a vertex. \n";
         cout<<"Enter the vertex: ";
         int n;
         cin>>n;
         cout<<"\n";
         i=0;
          int in=0,out=0;
         while(i<r){
                if(i!=(n-1)){
                     if(asd[i][n-1]==1){
                    in++;
                   }
                 }
                 else{
                    j=0;
                    while(j<r){
                        if(asd[i][j]==1){
                            out++;
                        }
                        j++;
                    }
                 }
                 i++;
         }
          cout<<" Indegree: "<<in<<"\n"<<" Outdegree: "<<out<<"\n";
          cout<<"Given a graph G, compute $G^T$, where $G^T$ has all the edges in G but reversed. "<<"\n"<<" Reversed Graph is: ";

            for(i=0;i<r;i++){
            for(j=0;j<r;j++){

                    if(asd[i][j]!=0){
                        cout<<j+1<<" "<<i+1<<", ";
                    }
            }
         }
         cout<<"\nGiven a vertex, list down all the neighbours of a graph.\n";

           cout<<"Input a vertex:";
           int g;
           cin>>g;
          cout<<"\nThe neighbour of"<<g<<"are";

            j=0;
                    while(j<r){
                        if(asd[g-1][j]==1){
                          cout<<j+1<<" ";
                        }
                        j++;
                    }
           cout<<"/nInput a vertex:";
           int f;
           cin>>f;
          cout<<"\nThe neighbour of"<<f<<"are";
           j=0;
                    while(j<r){
                        if(asd[f-1][j]==1){
                          cout<<j+1<<" ";
                        }
                        j++;
                    }

          }

