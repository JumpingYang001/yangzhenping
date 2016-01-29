#include "stdio.h"
#define N 10  
using namespace std; 
int a[N][N]; 
int  b[3][N*N];  
int  enter(int m)//输入网格中被占用的格子的信息
{
  int i,j,k,n,flag;  

  cout<<"请输入N*N的网格的N值"<<endl;//输入网格额外大小
  cin>>n;  
  for(k=1;k<=m;k++) 
  {    
     flag=1;  
     cout<<"输入网络第"<<k<<"个被占用所在行和列(小于等于N):"<<endl; 
     cin>>i>>j;  
     if(i>=n||j>=n||i<0||j<0)
     {   
       cout<<"!!!!ERROR!!!!"<<endl; 
       cout<<"坐标越界"<<endl; 
       flag=0; 
    }  

   if(flag==1) 
      a[i][j]=1; 
   else  
      k--; 
  }  
  return n; 
}  

int  empty(int &h,int &l,int n)//判断网格是否为空
{  
  for(h=0;h<n;h++) 
   for(l=0;l<n;l++) 
     if(a[h][l]!=0)  
       return 1;//非空返回
  return 0;//空则返回
}  

void visit(int h,int l,int count,int &num,int n)//递归搜索一组
{  
 if(a[h][l]==1)//若方格被占用则把它赋值为0并访问它四周的四个方格
 {    
 a[h][l]=0;  
 b[0][num]=h; 
 b[1][num]=l; 
 b[2][num]=count; 
 num++; 
 if(h+1<n)  
   visit(h+1,l,count,num,n);  
 if(l+1<n)  
   visit(h,l+1,count,num,n);  
 if(h-1>=0)  
   visit(h-1,l,count,num,n);  
 if(l-1>=0)  
   visit(h,l-1,count,num,n);  
 } 
}  

int search(int m,int n)//查询某一方格的组数
{
  int i,j,k;  
  cout<<"输入网络要查询的方格所在行和列(小于等于N):"<<endl; 
  cin>>i>>j;  
  if(i>=n||j>=n||i<0||j<0) 
  {   
     cout<<"!!!!ERROR!!!!"<<endl; 
     cout<<"坐标越界"<<endl; 
  }   

  for(k=0;k<m;k++) 
  {  
   if(b[0][k]==i&&b[1][k]==j) 
    return b[2][k]; 
  }  
  return 0;  
}  

void display(int count,int m,int n)//显示每组的具体信息
{   
 int i,j,c[N*N/2]={0}; 
 count--;  
 cout<<"一共有"<<count<<"个组."<<endl; 
 for(j=1;j<=count;j++) 
  for(i=0;i<m;i++) 
   if(b[2][i]==j)  
     c[j]++; 
 
 for(j=1;j<=count;j++) 
 {  
  cout<<"第"<<j<<"组包含"<<c[j]<<"个点,他们分别是:"<<endl;  
  cout<<"i"<<'\t'<<"j"<<'\t'<<endl; 
  for(i=0;i<m;i++) 
   if(b[2][i]==j) 
    cout<<b[0][i]<<'\t'<<b[1][i]<<'\t'<<endl; 
  cout<<endl<<endl; 
 }  

 while(1) 
 {
   i=search(m,n); 
   if(i==0)  
      cout<<"该格子未被占用。"<<endl; 
   else   
     cout<<"该格子位于第"<<i<<"组，该组共用"<<c[i]<<"个格子"<<endl; 
 }  
}  

int main() 
{  
    int  n,m,h,l,count=1,num=0,i,j; 
    for(i=0;i<N;i++) 
     for(j=0;j<N;j++) 
      a[i][j]=0;  
   cout<<"请输入N*N的网格被占用格子总数:"<<endl;//输入占用方格的数量
   cin>>m;  
   n=enter(m);  
   while(empty(h,l,n)==1) 
   {  
     visit( h,l,count,num,n); 
     count++; 
   }  

   display( count,m,n); 
   return 0; 
} 
