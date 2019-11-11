#include <bits/stdc++.h> 

using namespace std; 

#define MAX 1000 

class Stack { 
	int top; 

public: 
	int a[MAX]; // Maximum size of Stack 

	Stack() { top = -1; } 
	bool push(int x); 
	int pop(); 
	int peak(); 
	bool isEmpty(); 
}; 

bool Stack::push(int x) 
{ 
	if (top >= (MAX - 1)) { 
		cout << "Stack Overflow"; 
		return false; 
	} 
	else { 
		a[++top] = x; 
		cout << x << " pushed into stack\n"; 
		return true; 
	} 
} 

int Stack::pop() 
{ 
	if (top < 0) { 
		cout << "Stack Underflow"; 
		return 0; 
	} 
	else { 
		int x = a[top--]; 
		return x; 
	} 
} 
int Stack::peak() 
{ 
	if (top < 0) { 
		cout << "Stack is Empty"; 
		return 0; 
	} 
	else { 
		int x = a[top]; 
		return x; 
	} 
} 

bool Stack::isEmpty() 
{ 
	return (top < 0); 
} 

// Driver program to test above functions 
int main() 
{ 
	class Stack s;
        int t,c; 
        cin>>t;
	for(int i=0;i<t;i++)
            {
             cin>>c;
             if(c==1)
              {
               int d;
               cin>>d;
               s.push(d);
              }
             else if(c==2)
               cout<<s.pop()<<" is poped out of sack"<<endl;
             else if(c==3)
               cout<<s.peak()<<" is the top element"<<endl;
             else if(c==4)
                 {
                  if(s.isEmpty())
                     cout<<"stack is empty"<<endl;
                  else cout<<"stack is not empty"<<endl;
                  }
             }
	return 0; 
} 
