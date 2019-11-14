#include <bits/stdc++.h> 
using namespace std;  
class Queue 
{ 
	public: 
	int front, rear, size; 
	unsigned capacity; 
	int* array; 
}; 
Queue* createQueue(unsigned capacity) 
{ 
	Queue* queue = new Queue(); 
	queue->capacity = capacity; 
	queue->front = queue->size = 0; 
	queue->rear = capacity - 1;
	queue->array = new int[(queue->capacity * sizeof(int))]; 
	return queue; 
}
int isFull(Queue* queue) 
{ return (queue->size == queue->capacity); } 
int isEmpty(Queue* queue) 
{ return (queue->size == 0); }
void enqueue(Queue* queue, int item) 
{ 
	if (isFull(queue)) 
		return; 
	queue->rear = (queue->rear + 1) % queue->capacity; 
	queue->array[queue->rear] = item; 
	queue->size = queue->size + 1; 
	cout << item << " enqueued to queue\n"; 
}
int dequeue(Queue* queue) 
{ 
	if (isEmpty(queue)) 
		return INT_MIN; 
	int item = queue->array[queue->front]; 
	queue->front = (queue->front + 1) % queue->capacity; 
	queue->size = queue->size - 1; 
	return item; 
}
int front(Queue* queue) 
{ 
	if (isEmpty(queue)) 
		return INT_MIN; 
	return queue->array[queue->front]; 
}
int rear(Queue* queue) 
{ 
	if (isEmpty(queue)) 
		return INT_MIN; 
	return queue->array[queue->rear]; 
} 
int main() 
{ 
	Queue* queue = createQueue(1000);
	int i;
	cout<<"choose 1 to enqueue\nchoose 2 to dequeue\nchoose 3 to print first\nchoose 4 to print rear\nchoose 0 to terminate\n choise:";
        cin>>i;
        int a;
	while(i!=0)
	{
	 if(i==1){
            if(isFull(queue))
              return 0;
            cout<<"enter a number to enqueue:";
            cin>>a;
            enqueue(queue,a);
            }
         else if(i==2)
            {if(isEmpty(queue))
              return 0;
	cout<<dequeue(queue)<<" dequeued from queue\n";}
        else if(i==3)
	cout << "Front item is " << front(queue) << endl;
	else if(i==4)
	cout << "Rear item is " << rear(queue) << endl;
        cout<<endl<<"choose 1 to enqueue\nchoose 2 to dequeue\nchoose 3 to print first\nchoose 4 to print rear\nchoose 0 to terminate\n choise:";
        cin>>i;
	}
	return 0; 
}
