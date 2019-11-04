#include <bits/stdc++.h>

using namespace std;

struct node{
   int p;
    int s;
};

vector <node> r;

int find_(int i){
    if(r[i].p!=i)
        r[i].p=find_(r[i].p);
  return r[i].p;
}

void union_(int x,int y){
    if(x==y)
       return;
    int x_root=find_(x);
    int y_root=find_(y);
    if(r[x_root].s < r[y_root].s){
        r[x_root].p=y_root;
        r[y_root].s+=r[x_root].s;
    }
    else{
        r[y_root].p=x_root;
        r[x_root].s+=r[y_root].s;
    }
}

int main()
{
    int i,n,m;
    cin >>n >>m;

    r.clear();
    r.resize(n+1);
    for(i=1;i<=n;i++){
        r[i].p=i;
        r[i].s=1;
    }

    for(i=1;i<=m;i++){
        int p,q;
        cin>>p>>q;
        union_(find_(p),find_(q));
    }
    for(i=1;i<=n;i++){
        cout<< r[find_(i)].s-1 <<" ";
    }

    return 0;
}

