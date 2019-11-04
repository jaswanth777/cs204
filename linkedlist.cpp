#include <iostream>

using namespace std;

typedef struct node{
  int data;
  node *ptr;
}node;

 node *createnode()
{
 node *temp=(node *)malloc(sizeof(node));
 temp->ptr=NULL;
 return temp;
 }

int length(node *start)
{
 int count=0;
 node *temp;
 temp=start;
 while(temp != NULL)
     {
      count++;
      temp = temp->ptr;
      }
 return count;
}

void Search(node *start,int data)
{
 node *temp;
 temp=start;
 while(temp!=NULL)
      {
       if(temp->data==data)
         break;
       else temp=temp->ptr;
      }
 if(temp==NULL)
    cout<<data<<" does not exists"<<endl;
 else 
    cout<<data<<" exists"<<endl;
}

void printlist(node *start)
{
 node *temp;
 temp=start;
 while(temp!=NULL)
     {
      cout<<temp->data<<endl;
      temp=temp->ptr;
      }
}

void addstart(node **start,int data)
{
 node *temp;
 temp=createnode();
 if(temp==NULL)
   cout<<"problem creating node"<<endl;
 else
     {
      temp->data=data;
      temp->ptr=*start;
      *start=temp;
      }
}

void deletestart(node **start)
{
 node *temp;
 if(*start==NULL)
   {
    cout<<"no linked list"<<endl;
    }
 else{
      temp=*start;
      *start=(*start)->ptr;
      free(temp);
      }
}

void deleteend(node **start)
{
 node *temp,*prev;
 temp=*start;prev=NULL;
 if(temp==NULL) return;
 while(temp->ptr!=NULL)
      {
       prev=temp;temp=temp->ptr;
       }
 free(temp);
 if(prev!=NULL)
   {prev->ptr=NULL;}
 else 
   {*start=NULL;}
}


int main(){

    node *start=NULL;
    int choice=1,x;
    while(choice){
        cout << "1. Insert at start\n";
        cout << "2. Delete at start\n";
        cout << "3. Delete at tail\n";
        cout << "4. Length of Linked List\n";
        cout << "5. Print Linked List\n";
        cout << "6. Search for a value in linked list\n";
        cout << "0.Exit\n";
        cout << "enter your choice\n";
        cin >> choice;

        switch(choice){
        case 0:
            break;
        case 1:
            cout << "enter a value to insert";
            cin >> x;
            addstart(&start,x);
            break;
        case 2:
            deletestart(&start);
        
        case 3:
            deleteend(&start);
            break;
        case 4:
            cout << length(&start) << '\n';
            break;
        case 5:
            printlist(start);
            break;
        case 6:
            cout << "enter a value to search\n";
            cin >> x;
            Search(start,x);
            break;
        default:
            cout << "enter a valid choice\n";

        }
        cout << '\n';

    }

return 0;

}