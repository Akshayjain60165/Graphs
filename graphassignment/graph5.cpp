#include<iostream>
#include <stack>

#include<bits/stdc++.h>
using namespace std;
void dfs(int asd[][6],int v,int arr[],int r,stack<int> &Stack)
{

    arr[v-1]=1;

    Stack.push(v);

    for(int i=0;i<r;i++)
    {
        if(arr[i]!=1&asd[v-1][i]!=0)
        {
            dfs(asd,i+1,arr,r,Stack);

        }
    }


}
void df(int asd[][6],int v,int arr[],int r,int t)
{

    arr[v-1]=1;

    t++;

    for(int i=0;i<r;i++)
    {
        if(arr[i]!=1&asd[v-1][i]!=0)
        {
            df(asd,i+1,arr,r,t);

        }
    }


}
int fun(int arr[],int r)
{
    int t=0;
    for(int i=0;i<r;i++)
    {
        if(arr[i]==0)
        {
            t=1;
        }
    }
    return t;
}
int dfss(int asd[][6],int opp[][6],int v,int r)
{
    int arr[r];
    for(int j=0;j<r;j++)
    {
        arr[j]=0;
    }
    stack<int> Stack;
    int t=0;
    dfs(asd,v,arr,r,Stack);
    int arr1[r];
    for(int i=0;i<r;i++)
    {
        arr1[i]=0;
        if(arr[i]==0)
        {
           dfs(asd,i+1,arr,r,Stack);
        }
    }
    stack<int> st;

    while(!Stack.empty())
    {
        int n=Stack.top();
        Stack.pop();

     t++;
        if(fun(arr1,r)==0)
        {
            break;
        }
        if(arr1[n-1]==0)
            dfs(opp,n,arr1,r,st);



    }

    return t;
}
//yha se shuru karna hai

void dffs(int asd[][6],int v,int arr[],int r,stack<int> &Stack,int par[])
{

    arr[v-1]=0;

    Stack.push(v);

    for(int i=0;i<r;i++)
    {
        if(arr[i]==-1&asd[v-1][i]!=0)
        {
            par[i]=v-1;

            dffs(asd,i+1,arr,r,Stack,par);

        }
    }


}

void detect(int asd[][6],int v,int r)
{
    int arr[r],par[r],f=0;
    for(int j=0;j<r;j++)
    {
        arr[j]=-1;
        par[j]=-1;
    }
    stack<int> Stack;
    int t=0;
    dffs(asd,v,arr,r,Stack,par);

   /* for(int i=0;i<r;i++)
    {

        if(arr[i]==-1)
        {
           dffs(asd,i+1,arr,r,Stack,par);
        }
    }*/
    while(!Stack.empty())
    {

        int n=Stack.top();
        Stack.pop();

       arr[n-1]=1;
        for(int u=0;u<r;u++)
        {
            if(asd[n-1][u]!=0&arr[u]==0)
            {
             f++;
             cout<<"\nGraph has a cycle with vertices ";
               cout<<n<<" ";
             int d=par[n-1]+1;

             while(d!=u+1)
             {

                 cout<<d<<" ";
                 if(d==0)
                 {
                     break;
                 }
                 d=par[d-1]+1;
             }
              cout<<d;
            }
        }
    }
    for(int i=0;i<r;i++)
    {

        if(arr[i]==-1)
        {

        for(int j=0;j<r;j++)
        {
            arr[j]=-1;
             par[j]=-1;
       }
        stack<int> Stack;
         int t=0;
           dffs(asd,i+1,arr,r,Stack,par);
        }
    }
    if(f==0)
    {
        cout<<"no cycle detected";
    }
}
int main()
{
    cout<<"Enter the number of nodes: ";
         int r;               //r=5, as given in questiom
         cin>>r;
         cout<<"\n";
         int as[7][2];    //number of edges
         int i,j;
         cout<<"Enter edges separated by a comma: ";
          int asd[6][6];
          int opp[6][6];
         for(i=0;i<r;i++){
            for(j=0;j<r;j++){
                    asd[i][j]=0;
                    opp[i][j]=0;
            }
         }
         for(i=0;i<7;i++){
            for(j=0;j<2;j++){
                cin>>as[i][j];

            }

             asd[as[i][0]-1][as[i][1]-1]=1;
            opp[as[i][1]-1][as[i][0]-1]=1;
         }
   cout<<"1) For a given directed/undirect graph, write a program to check whether there is a cycle or not by checking if there exists a back edge. ";
  detect(asd,1,r);
  int t=0;
  int arr[r];
  for(int d=0;d<r;d++)
  {
      arr[d]=0;
  }
   df(asd,1,arr,r,t);
   cout<<"\n2) Write a program that check whether a given graph is strongly connected or not ";
   if(t==6)
   {
       cout<<" \n The graph is  strongly connected ";
   }
   else
   {
       cout<<"\n The graph is not strongly connected ";
   }
    int n=dfss(asd, opp, 1, r);
    cout<<"\n3) Write a program that finds number of strongly connected components in the graph. ";

    cout<<" \nThe number of strongly connected components are  "<<n;
}

