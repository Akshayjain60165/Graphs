//adjacency list
//agjacency list is better  for printing opposite graph and in and out degree and for neighbour too,this will remain unchanged
#include<iostream>
using namespace std;

class node{
  public :
         int a;                             //node formation
         node* next;
         node(){
             next= NULL;
         }

         };

class linklist{                      //linked list formation(insert)

   public :
         node* head= NULL;
         node* tail= NULL;

      void ins(int v){
           if(head==NULL){
               node* n= new node;
               n->a=v;
               head=n;
               tail=head;

           }
           else{
               node* n= new node;
               tail->next=n;
               n->a=v;
               tail=n;

           }
      }


};


int main(){
         cout<<"Enter the number of nodes: ";
         int r;               //r=5, as given in questiom
         cin>>r;
         cout<<"\n";
         int as[7][2];    //number of edges
         int i,j;
         cout<<"Enter edges separated by a comma: ";
         for(i=0;i<7;i++){
            for(j=0;j<2;j++){
                cin>>as[i][j];
            }

         }
         i=0;
         linklist arr[r];         //adjacency list
         while(i<r){
            arr[i].ins(i+1);

            i++;
         }
         i=0;
         while(i<7){
               arr[as[i][0]-1].ins(as[i][1]);
               i++;
         }
         cout<<"Given a vertex, compute out-degree/in-degree of a vertex. \n";
         cout<<"Enter the vertex: ";
         int n;
         cin>>n;
         cout<<"\n";
         i=0;
         int in=0,out=0;
         while(i<r){
                if((i+1)!=n){
                    node* temp=arr[i].head;
                    while(temp->next!=NULL){
                        temp=temp->next;
                        if(temp->a==n){
                            out=out+1;
                        }
                    }
                }
                else{
                   node* temp1=arr[i].head;
                    while(temp1->next!=NULL)
                        {
                         temp1=temp1->next;
                     in++;
                        }

                    }
         i++;
         }
         cout<<" Indegree: "<<in<<"\n"<<" Outdegree: "<<out<<"\n";


         cout<<"Given a graph G, compute $G^T$, where $G^T$ has all the edges in G but reversed. "<<"\n"<<" Reversed Graph is: ";
             i=0;

             while(i<r){

                node* temp2=arr[i].head;
             j=temp2->a;
                while(temp2->next!=NULL){
                   temp2=temp2->next;
                   cout<<temp2->a<<" "<<j<<", ";

                }

                i++;
             }

         cout<<"\nGiven a vertex, list down all the neighbours of a graph.\n";

           cout<<"Input a vertex:";
           int g;
           cin>>g;
          cout<<"\nThe neighbour of"<<g<<"are";
         node* temp=arr[g-1].head;
          while(temp->next!=NULL){
            temp=temp->next;
            cout<<temp->a<<" ";
          }
           cout<<"\nInput a vertex:";
           int f;
           cin>>f;
          cout<<"\nThe neighbour of"<<f<<"are";
          temp=arr[f-1].head;
          while(temp->next!=NULL){
            temp=temp->next;
            cout<<temp->a<<" ";
          }
}
