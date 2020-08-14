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
int maxx(int bc[],int r)
{
    int a=0;

    for(int t=0;t<r;t++)
    {
        if(a<bc[t]){
            a=bc[t];
        }
    }
    return a;
}
int processArr(int r,int j,int asd[][7],int chec[],int b,int bc[]) {

    int i;
   int check[r];
         for(i=0;i<r;i++){
              check[i]=0;
         }
    queue* queuee= createqueue(r);
         ins( queuee, j-1);
         check[j-1]=1;
         chec[j-1]=1;
         int c,m=0,n;
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

                  n = maxx(bc,r);
                         del( queuee);
                  }
                  return n;
}

int main() {
    cout<<"Enter the number of nodes: ";
         int r;               //r=5, as given in questiom
         cin>>r;
         cout<<"\n";
         int as[6][2];    //number of edges
         int i,j;
         cout<<"Enter edges separated by a comma: ";
          int asd[7][7];
         for(i=0;i<r;i++){
            for(j=0;j<r;j++){
                    asd[i][j]=0;
            }
         }
         for(i=0;i<6;i++){
            for(j=0;j<2;j++){
                cin>>as[i][j];

            }

             asd[as[i][0]-1][as[i][1]-1]=1;
             asd[as[i][1]-1][as[i][0]-1]=1;
         }
int z=0,check[r],bc[r],k=1;


          for(i=0;i<r;i++)
         {
              check[i]=0;
              bc[i]=0;
              int n=processArr( r, i+1, asd, check, z+1,bc);
               if(n>k)
            {
                k=n;
            }

         }
cout<<"The diameter of the tree is "<<k;
}
