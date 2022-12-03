#include <iostream>

void Display();//displays the content of our data base 

void Search();//has two choice linear and bubble // searches: ID,PNum,AccNum,& Fname only
	void LinearSearch();
	void BinarySearch();
void Sort();// has two choices ascending and descending // sorts based on: Salary,Dep,& Fname
	void ascending_bubble();
	void descending_bubble();
	void ascending_selection();
	void descending_selection();
void Add();// adds new data into our database
void remove();//removes searched data from our databse 
struct employee{
	//None of them have size upto how much they can store because we dont know max limit *DELETE THIS LINE ON PRODUCTION*
	string ID;//string because it contains "-"
	string FName;//Full name of the employee
	string LName;//Last name of the employee
	char Gender[7];//takes only values M or F||male or female
	string PNum;//string because it contains "-"
	string Email;//string because contains different values
	string Dep;//Holds department
	string AccNum;//String because account number contains "-"
	double Salary;//takes values from 5000.00 - 50000.00
};// create your own employee objects as u see fit for ur functions
//Linked List struct will be applied after next week to save time and reduce complexity *DELETE THIS LINE ON PRODUCTION*
int main() {
	MainMenu();
	return 0;
}
void Display(){
//Create a table with all contents of out database here
}
void Search(){
//here just try to make two options: 1.linear search and 2.binary search
}	
void LinearSearch(){
	//write Linear search algorithm here
	 
}
void BinarySearch(){
	//write Binary search algorithm here
}
void Sort(){
//here try to make two options first bubble and seletcion and on both say ascending and descending order
}
void ascending_bubble(){
//write ascending bubble search algorithm here	
}
void descending_bubble(){
// write descending bubble search algorithm here
}
void ascending_selection(){
// write ascending bubble selection algorithm here
}	
void descending_selection(){
// write descending selection algorithm here
}
void Add(){
// write the add algorithm here
}
void remove(){
// write the remove algorithm here
}
void MainMenu(){
	//Main Menu
	 cout << "-------------------------"
         << "Pay Roll" << setw ( 10 );
         << " Management System" << setw ( 10 );
         << "-------------------------\n\n";
  
    cout << "Available Options:\n\n";
    	cout << "\n 1. Display" << setw ( 20 ) << endl;
		cout << "\n 2. Search" << setw ( 20 ) << endl;
		cout << "\n 3. Sort" << setw ( 20 ) << endl;
		cout << "\n 4. Add" << setw ( 20 ) << endl;
		cout << "\n 5. Remove" << setw ( 20 ) << endl;
        cout << "\n 6. Exit" << setw ( 20 ) << endl;
  
    int option;
  
    // Input Options
    cin >> option;
    
    // Call function on the bases of the
    // above option
    
    if (option == 1) {
       Display();
    }
    else if (option == 2) {
        Search();
    }
    else if (option == 3) {
        Sort();
    }
    else if (option == 4) {
        Add();
    }
    else if (option == 5) {
        remove();
    }
    else if (option == 6){
    	return;
	}
    else {
        cout << "Expected Options"
             << " are 1/2/3/4/5/6";
         MainMenu();
    }
}

void Search(){ //Implements the Search menu
	int menu;
	do{
		cout<<"1. Linear search"<<endl;
		cout<<"2. Binary search"<<endl;
		cout<<"3. Exit"<<endl;
		cout<<"Choose menu"<<endl;
		cin<<menu;
		
		switch(menu){
			case 1: 
			LinearSearch();
			break;
			case 2: 
			BinarySearch();
			break;
			case 3: 
			MainMenu();
			break;
			default:
				cout<<"Enter a valid value"<<endl;
				MainMenu();
				break;
		}
	}while(menu>3);//Executes the code once and checks if it should do it again if the value is greater than 3

}
