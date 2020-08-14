#include<iostream>
using namespace std;
class queue
{
    public:
    int head, tail;
    int capacity;
    int* array;
};


queue* createqueue(int capacity)
{
    queue* queuee = new queue();
    queuee->capacity = capacity;
    queuee->head = 0;
    queuee->tail = 0;
    queuee->array = new int[(queuee->capacity * sizeof(int))];
    return queuee;
}

void ins(queue* queuee,int v)
{
         queuee->array[queuee->tail]=v;
         queuee->tail=queuee->tail+1;

}

void del(queue* queuee)
{
   queuee->head++;
}
int emp(queue* queuee)
{
      if(queuee->tail<=queuee->head)
        {
              return 0;
        }
       else
        {
             return 1;
        }
}

int processArr(int r,int j,int asd[][6],int chec[],int b,int bc[]) {

    int i;
   int check[r];
         for(i=0;i<r;i++){
              check[i]=0;
         }
    queue* queuee= createqueue(r);
         ins( queuee, j-1);
         check[j-1]=1;
         chec[j-1]=1;
         int c,n=0,m=0;
         bc[j-1]=m;
                  while(emp(queuee)!=0)
                    {

                       i=0;
                       c= queuee->array[queuee->head];

                       while(i<r)
                        {

                            if(asd[c][i]==1 & check[i]!=1 & chec[i]!=1)
                            {
                                ins( queuee, i);
                                     check[i]=1;
                                     chec[i]=1;
                                     bc[i]=bc[c]+1;
                            }
                            i++;
                        }
                        if(b==c+1){
                            n=1;
                        }

                         del( queuee);
                  }
                  return n;
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
int z=0;
int check[r],bc[r];
   cout<<"Given two vertices u and v, check whether there exists a path between u and v or not. ";
while(z<2)
{

   for(i=0;i<r;i++){
              check[i]=0;
              bc[i]=0;
         }

   int u,v;
   cout<<"\nEnter two vertices: ";
   cin>>u>>v;
   int n=processArr( r, u, asd, check, v,bc);

   if(n==1){
    cout<<" \nThere exists a path between"<<u<<" and "<<v;
   }
   else{
    cout<<"\nThere does not exist a path between"<<u<<" and "<<v;
   }
   z++;
}
int u,v;
   for(i=0;i<r;i++){
              check[i]=0;
              bc[i]=0;
         }

    cout<<"\nWrite a program to compute shortest distance between two vertices u and v. "<<"\nEnter two vertices: ";
    cin>>u>>v;
    int n=processArr( r, u, asd, check, v,bc);
    cout<<"\nShortest path between "<<u<<" and " <<v <<" is of length "<< bc[v-1];
}
