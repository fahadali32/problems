#include<stdio.h>
void enqueue (int a);
int dequeue ();
int q[20],r,f;
int main()
{
int node,edge,a,b,s,u,v,des,count=0,S[20],x;
 int q[20];

 printf("Enter your node number :\n");
 scanf("%d",&node);
 int matrix[node][node];
 int c[node];
 int p[node];
 int d[node];
 int i,j;

 for(i=0;i<node;i++)
 {
 for(j=0;j<node;j++)
 {
 matrix[i][j]=0;

 }

 }

 printf("Enter your edge number :\n");
 scanf("%d",&edge);
 printf("Enter your edges :\n");


 for(i=0;i<edge;i++)
 {
 scanf("%d%d",&a,&b);

 matrix[a][b]=1;
 matrix[b][a]=1;


 }


 printf("Here is your graph representation :\n");

 for(i=0;i<node;i++)
 {
 for(j=0;j<node;j++)
 {
 printf("%d ",matrix[i][j]);

 }
 printf("\n");

 }

 printf("Enter your source : \n");
 scanf("%d",&s);
 for(u=0;u<node;u++)
 {
 c[u]=1;
 p[u]=-1;
 d[u]=-1;
 }
 c[s]=2;
 d[s]=0;
 p[s]=-1;
 f=0;
 r=0;
 enqueue(s);
 while(f!=r)
 {
 u=dequeue();
 for(v=0;v<node;v++)
 {
 if(matrix[u][v]==1 && c[v]==1 )
 {
 c[v]=2;
 d[v]=d[u]+1;
 p[v]=u;
 enqueue(v);
 }
 }
 c[u]=3;
 }

 printf("Enter your Destination node :\n");
 scanf("%d",&des);
 for(i=0;x!=s;i++)
 {
 x=des;
 S[i]=x;
 des=p[x];
 count++;

 }

 for(i=count-1;i>=0;i--)
 {
 printf("%d ",S[i]);

 }


 return 0;
 }

 void enqueue (int a)
 {
 q[r++]=a;
 }

int dequeue ()
{
int a;
a=q[f++];
return a;
}