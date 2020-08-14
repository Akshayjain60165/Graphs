#include<iostream>
using namespace std;
class queue
{
    public:
    int head, tail;
    int capacity;
    int* array;
};
int r=6,l=1;

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

void processArr(int r,int j,int asd[][6],int chec[]) {

    int i;
   int check[r];
         for(i=0;i<r;i++){
              check[i]=0;
         }
    queue* queuee= createqueue(r);
         ins( queuee, j-1);
         check[j-1]=1;
         chec[j-1]=1;
         int c;

                  while(emp(queuee)!=0){

                       i=0;
                       c= queuee->array[queuee->head];

                       while(i<r)
                        {

                            if(asd[c][i]==1 & check[i]!=1 & chec[i]!=1)
                            {
                                ins( queuee, i);
                                     check[i]=1;
                                     chec[i]=1;
                            }
                            i++;
                        }
                        cout<<c+1<<" ";

                         del( queuee);
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
         }

int check[r];
for(i=0;i<r;i++){
              check[i]=0;
         }
   processArr(r,1,asd,check);
   for(i=0;i<r;i++){
              if(check[i]==0)
              {
                   processArr(r,i+1,asd,check);
              }
         }
   return 0;
}
