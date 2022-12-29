#include <iostream>
#include <string>
using namespace std;

const int MAX_CAPACITY = 5;
int size = 0;
void menu();
struct Student{
	int age;
	string ID;
	string Fname;
	string Lname;
	char sex; 
}s;

struct node{
	Student data;
	node *next;
}*temp,*del,*head=NULL,*cur,*bef;

int isEmpty(){
	if(head == NULL) return 1;
	return 0;
}

int isFull(){
	if(size == MAX_CAPACITY) return 1;
	return 0;
}

void push(Student s){
	if(isFull()==1){
		cout<<"\t\t==========================\n";
		cout<<"Stack is Full!!!"<<endl;
		cout<<"\t\t==========================\n";
		return;
	}
	if(head == NULL){
		temp = new node;
		temp->data = s;
		temp->next = NULL;
		head = temp;
		cur = head;
		size++;
	} else{
		temp = new node;
		temp->data = s;
		temp->next = NULL;
		cur->next = temp;
		cur = cur->next;
		size++;
	}	
}
void pop(){
 	if(isEmpty() == 1){
		cout<<"Stack underflow!!!"<<endl;	 	
	 	return;
	}
	if(head->next == NULL){//if only the head node exists
		cout<<"\t\t==========================\n";
		cout<< head->data.Fname <<" has been deleted!!!"<<endl;
		head = NULL;
		size--;
		cout<<"\t\t==========================\n";
	} else {	
	 	del = head;
	 	while(del->next!=NULL){
	 		bef = del;
	 		del = del->next; 
	    }
		bef->next = NULL;
		cout<<"\t\t==========================\n";
		cout<< s.Fname <<" has been deleted!!!"<<endl;
		cout<<"\t\t==========================\n";
		delete del;
		size--;
	}
} 

void display(){
	if(isEmpty() == 1) {
		cout<<"\t\t==========================\n";
		cout<<"\t\t\tStack is Empty!!!"<<endl;
		cout<<"\t\t==========================\n";
		return;
	}
    bef = new node;
    bef->next = NULL;
    temp = head;
    bef->next = temp;
	cout<<"\t\t==========================\n";
 	while(bef->next!=NULL){
 		cout<<"\t\t\tID NUMBER:"<<temp->data.ID<<endl;
 		cout<<"\t\t\tFIRST NAME:"<<temp->data.Fname<<endl;
 		cout<<"\t\t\tLAST NAME:"<<temp->data.Lname<<endl;
 		cout<<"\t\t\tSEX:"<<temp->data.sex<<endl;
 		cout<<"\t\t\tAGE:"<<temp->data.age<<endl;
 		cout<<"\t\t==========================\n";
 		if(temp->next != NULL) {
		 	temp = temp->next;
	 	}
		bef = bef->next;	
	 }
    cout<<"\t\t==========================\n";
}

void menu(){
	int choice;
	do{ 
		system("pause");
		system("cls");
		cout<<"\t\t==========================\n";
		cout<<"\t\t\t1. PUSH"<<endl;
		cout<<"\t\t\t2. POP"<<endl;
		cout<<"\t\t\t3. DISPLAY"<<endl;
		cout<<"\t\t\t4. EXIT"<<endl;
		cout<<"\t\t==========================\n";
		cin>>choice;
		
		switch(choice){
			case 1: 
				system("cls");
				cout<<"\t\t==========================\n";
				cout<<"\t\tEnter Student First name: ";
				cin>>s.Fname;
				cout<<"\t\tEnter Student Last name: ";
				cin>>s.Lname;
				cout<<"\t\tEnter Student Age: ";
				cin>>s.age;
				cout<<"\t\tEnter Student ID: ";
				cin>>s.ID;
				cout<<"\t\tEnter Student sex: ";
				cin>>s.sex;
				cout<<"\t\t==========================\n";
				push(s);
				break;		
			case 2: 
				pop();
				break;
			case 3: 
				system("cls");
				display();
				break;
			case 4:
				exit(0);
				break;
			default:
				cout<<"\t\t==========================\n";
				cout<<"Enter a valid choice!!!"<<endl;
				cout<<"\t\t==========================\n";
				break;			
		}	
	}while(true);
}

int main() {
	menu();
	return 0;
}
