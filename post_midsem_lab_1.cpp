#include<bits/stdc++.h>
using namespace std;
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int partition(int arr[], int l, int r, int x)
{
    int i;
    for (i=l; i<r; i++)
        if (arr[i] == x)
           break;
    swap(&arr[i], &arr[r]);
    i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}
int Median(int arr[],int n)
{
  insertionSort(arr,n);
  return arr[(n+1)/2];
}
int blumselection(int arr[],int p,int r,int i)
{
  if(i>0 && i<=r-p+1)
  {
    int n=r-p+1;
    int j,med[(n+4)/5];
    for(j=0;j<n/5;j++)
    {
      med[j]=Median(arr+p+j*5,5);
    }
    if(j*5<n)
    {
      med[j]=Median(arr+p+j*5,n%5);
      j++;
    }
    int medofmed;
    if(j<=5)medofmed=med[(j+1)/2];
    else
    {
      medofmed=blumselection(med,0,j-1,j/2);
    }
    int pos=partition(arr,p,r,medofmed);
    if(pos-p==i-1)return arr[pos];
    if (pos-p > i-1)
           return blumselection(arr, p, pos-1, i);
       return blumselection(arr, pos+1, r, i-pos+p-1);

  }
  else
  {return -1;}
}
int main()
{
  int q;
  cin>>q;
  while(q--)
  {
    int n;
    cin>>n;
    int d[n];
    for(int i=0;i<n;i++)
    {
    int x,y;
    cin>>x>>y;
    d[i]=x*x+y*y;
    }
    cout<<sqrt(blumselection(d,0,n-1,(n+1)/2))<<endl;
  }
  return 0;
}
