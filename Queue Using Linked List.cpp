#include<iostream>
using namespace std;
struct node{
	node* next;
	int data;
};
class queue{
	node* front=NULL;
	node* rear=NULL;
	bool isEmpty(){
		if(front==NULL){
			return true;
		}
		return false;
	}
	public:
		void enqueue(int data){
			node* newnode=new node();
			newnode->data=data;
			newnode->next=NULL;
			if(isEmpty()){
				front=newnode;
				rear=newnode;
			}else{
				rear->next=newnode;
				rear=newnode;
			}
			cout<<"Enqueue successful."<<endl;
		}
		void dequeue(){
			if(isEmpty()){
				cout<<"Empty queue."<<endl;
			}else{
				node* temp=front;
				front=front->next;
				cout<<temp->data<<" has been dequeued."<<endl;
				delete temp;
			}
		}
		void display(){
			if(isEmpty()){
				cout<<"Empty queue."<<endl;
			}else{
				node* temp=front;
				cout<<"The queue is: "<<endl;
				while(temp!=NULL){
					cout<<temp->data<<endl;
					temp=temp->next;
				}
			}
		}
};
int main(){
	queue q;
	int choice;
	do{
		cout<<endl<<"1. Enqueue an element."<<endl;
		cout<<"2. Dequeue an element."<<endl;
		cout<<"3. Display the queue."<<endl;
		cout<<"4. Exit."<<endl;
		cout<<"Choice: ";
		cin>>choice;
		switch(choice){
			case 1:
				int element;
				cout<<"Enter the element: ";
				cin>>element;
				q.enqueue(element);
				break;
			case 2:
				q.dequeue();
				break;
			case 3:
				q.display();
				break;
			case 4:
				cout<<"Exited.";
				break;
			default:
				cout<<"Enter your choice from 1 to 4."<<endl;
				break;
		}
	}while(choice!=4);
	return 0;
}
