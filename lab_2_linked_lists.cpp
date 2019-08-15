#include<bits/stdc++.h>
#include<math.h>
using namespace std;

class point
           {
            private:
             int x;
             int y;
            public:
             void set_value(int a,int b)
                       {
                        x=a;
                        y=b;
                        }
             void print()
                       {
                        cout<<" ("<<x<<","<<y<<") ";
                        }
             int getx()
                      {
                       return x;
                       }
             int gety()
                      {
                       return y;
                       }
             int compare_with_a_pt(point p)
                      {
                       if((x==p.getx())&&(y==p.gety()))
                          return 1;
                       else return 0;
                       }
             double distance_from_origin()
                      {
                       double d;
                       d=sqrt((x)*(x)+(y)*(y));
                       return d;
                       }
             
            };
struct node{
            point p;
            struct node *ptr;
            };
class linked_list
                {
                 private:
                  struct node *head; 
                 public:
                  linked_list()
                           {
                            head=NULL;
                            }
                  void AddFirst(int x,int y)
                            {
                             struct node *temp=new (struct node);
                             (temp->p).set_value(x,y);
                             temp->ptr=head;
                             head=temp;
                             }
                  void DelFirst()
                            {
                             if(head==NULL)
                               cout<<"-1"<<endl;
                             else{
                                  struct node *temp;
                                  temp=head;
                                  head=head->ptr;
                                  free(temp);
                                  }
                             }
                  void Del(int x,int y)
                            {
                             point a;
                             a.set_value(x,y);
                             struct node *temp,*prev;
                             temp=head;
                             prev=NULL;
                             while(temp!=NULL)
                                  {
                                   if(a.compare_with_a_pt(temp->p)==1)
                                      break;
                                      prev=temp;
                                      temp=temp->ptr;
                                   }
                             if(temp==NULL)
                                cout<<"-1"<<endl;
                             else if(prev==NULL)
                                   {
                                    head=head->ptr;
                                    free(temp);
                                    }
                             else{
                                  prev->ptr=temp->ptr;
                                  free(temp);
                                  }
                             }
                  void Search(float d)
                            {
                             struct node *temp;
                             temp=head;
			     int count=0;
                             while(temp!=NULL)
                                  {
                        	   if((temp->p).distance_from_origin()<=d)
                                      count=count+1;
                                   temp=temp->ptr;
				   }
			     if(count==0)
			       {
			        cout<<"-1"<<endl;
			        }
			      else
			      {
			       cout<<count<<endl;
			       }
                             }
                  void Search(int x,int y)
                            {
                             point a;
                             a.set_value(x,y);
                             int count=0;
                             struct node *temp;
                             temp=head;
                             while(temp!=NULL)
                                  {
                                   if(a.compare_with_a_pt(temp->p)==1)
                                     count=count+1;
                                   temp=temp->ptr;
                                   }
			      if(count==0)
			        {
			         cout<<"false"<<endl;
			         }
			       else
			         {
			           cout<<"true"<<endl;
			          }
                             }
                  int Length()
                            {
                             int count=0;
                             struct node *temp;
                             temp=head;
                             while(temp!=NULL)
                                  {
                                   count=count+1;
                                   temp=temp->ptr;
                                   }
                             return count;
                             }
                 };
int main()
        {
         int t;
         cin>>t;
         int s[t][3];
         linked_list l;
         cout<<endl;
         for(int i=0;i<t;i++)
            {
             cin>>s[i][0];
             if(s[i][0]==4)
               {
                cin>>s[i][1];
                cout<<endl;
                }
             else if(s[i][0]==1||s[i][0]==3||s[i][0]==5)
                {
                 cin>>s[i][1];
                 cin>>s[i][2];
                 cout<<endl;
                 }
             else if(s[i][0]==2||s[i][0]==6)
                 {
                  cout<<endl;
                  }
             else{
                  cout<<"invalid input"<<endl;
                  }
             }
         for(int i=0;i<t;i++)
            {
             if(s[i][0]==1)
               {
                l.AddFirst(s[i][1],s[i][2]);
                }
             else if(s[i][0]==2)
                {
                 l.DelFirst();
                 }
             else if(s[i][0]==3)
                {
                 l.Del(s[i][1],s[i][2]);
                 }
             else if(s[i][0]==4)
                 {
                  l.Search(s[i][1]);
                  }
             else if(s[i][0]==5)
                {
                 l.Search(s[i][1],s[i][2]);
                 }
             else{
                  cout<<l.Length()<<endl;
                  }
             }
         return 0;
         }
