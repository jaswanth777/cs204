#include <bits/stdc++.h>
using namespace std;

struct node{
	int x;
	struct node* next;
};

void AddFirst(int a,struct node** start){
	if(*start == NULL){
		*start = new node();
		(*start)->x = a;
		(*start)->next = NULL;
	}
	else{
		node* temp = new node();
		temp->x =a;
		temp->next = *start;
		*start = temp;
	}

}

void Addlast(int a,struct node** start){
        node* temp= *start;
        while(temp->next!=NULL)
             {
              temp=temp->next;
              }
        node* fresh= new node();
        temp->next=fresh;
        fresh->next=NULL;
        fresh->x=a;
	}

void DelFirst(struct node** start){
	if(*start == NULL){
		cout<<"-1"<<"\n";
	}
	else{
		node* temp = *start;
    	*start = temp->next;
    	free(temp);
	}
} 

void Dellast(struct node** start){
        node* temp= *start;
        node* prev= NULL;
        while(temp->next!=NULL)
             {
              prev=temp;
              temp=temp->next;
              }
        prev->next=NULL;
        free(temp);
}

void Del(int a,struct node** start){
	node* temp = *start;
	node* prev = NULL; 
	int flag =0;
	while(temp!=NULL){
		if(temp->x==a&&prev!=NULL){
			prev->next = temp->next;
			free(temp);
			flag =1;
		}
		else if(prev == NULL&&temp->x==a){
			DelFirst(start);
			flag =1;
		}
		else{
			prev = temp;
			temp = temp->next;
	}
	}
		if(flag ==0){
			cout<<a<<" not found"<<endl;
		}
}
void search(int a ,struct node** start){
	node* temp = *start;
	int flag = 0;
	while(temp!= NULL){
		if(temp->x==a){
			flag =1;
			break; 
		}
		else{
			temp = temp->next;
		}
	}
	if(flag==1){
		cout<<a<<" exists"<<endl;
	}
	else{
		cout<<a<<" doesnot exists"<<endl;
	}
}

void print(struct node** start)
{
node* temp=*start;
while(temp!=NULL)
{
cout<<temp->x<<" ";
temp=temp->next;
}
}

void insert(int a, int b, node** start)
{
        node* temp = *start;
	int flag = 0;
	while(temp!= NULL){
		if(temp->x==a){
			flag =1;
			break; 
		}
		else{
			temp = temp->next;
		}
	}
if(flag==1){
		node* fresh= new node();
                fresh->x=b;
                fresh->next=temp->next;
	        temp->next=fresh;
            }
	else{
		cout<<a<<" not found"<<endl;
	}
}

void length(node** start){
         node* temp = *start;
         int count=0;
         while(temp!=NULL)
             {
              count=count+1;
              }
         cout<<count<<endl;
}
int main(){
	node* start = NULL;
	int condition;
	int T;
	cin>>T;
	while(T--){
		cin>>condition;
		if(condition==1){
			int a;
			cin>>a;
			AddFirst(a,&start);
		}
		else if(condition ==2){
			int a;
			cin>>a;
			Addlast(a,&start);
		}
		else if(condition == 3){
                        DelFirst(&start);
		}
		else if(condition==4){
                        Dellast(&start);
		}
                else if(condition==5){
			int a;
			cin>>a;
                        Del(a,&start);
                }
                else if(condition==6){
			int a;
			cin>>a;
                        search(a,&start);
                }
                else if(condition==6){
                        print(&start);
                }
                else if(condition==7){
                        int a,b;
                        cin>>a;
                        cin>>b;
                        insert(a,b,&start);
                }
                else if(condition==8){
                        length(&start);
                }
                else cout<<"invalid"<<endl;
                       
	}
	return 0;
}
