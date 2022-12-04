#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;
struct Employee{
	//None of them have size upto how much they can store because we dont know max limit *DELETE THIS LINE ON PRODUCTION*
	string ID;//string because it contains "-"
	string FName;//Full name of the employee
	string LName;//Last name of the employee
	char Gender;//takes only values M or F||male or female
	string PNum;//string because it contains "-"
	string Email;//string because contains different values
	string Dep;//Holds department
	string AccNum;//String because account number contains "-"
	double Salary;//takes values from 5000.00 - 50000.00
}RawData[3] = {
	{"870-61-4378","Dalia","Ring",'F',"6-170-430-8208","Dalia_Ring2491@famism.biz","Human Resources","0423-6118-4778-8105",46438.55},
	{"802-06-0038","Fred","Khan",'M',"3-000-503-2640","Fred_Khan19@deons.tech","Management","3677-5870-0123-1767",24657.11},
	{"153-76-1046","Melania","Roberts",'F',"2-835-251-1573","Melania_Roberts114@bulaffy.com","Sales","1855-7088-8687-0554",7717.11}
};
void MainMenu();
void Display(Employee Data[], int numberOfEmployee);//displays the content of our data base 
void SwapEmpoyee();//used to swap employees
void Search();//has two choice linear and bubble // searches: ID,PNum,AccNum,& Fname only
	int searchType();
	char searchkey();
		void LinearSearch();
		void BinarySearch();
void Sort();// has two choices ascending and descending // sorts based on: Salary,Dep,& Fname
	char sortUsing();
	int sortAlgorithm();
	int sortArrangment();
		void ascending_selection(Employee Data[],int numberOfEmployees,char sortUsing);
		void descending_selection(Employee Data[],int numberOfEmployees,char sortUsing);
		void ascending_bubble();
		void descending_bubble();
void Add();// adds new data into our database
void remove();//removes searched data from our databse 
//Linked List struct will be applied after next week to save time and reduce complexity *DELETE THIS LINE ON PRODUCTION*
int main() {
	MainMenu();
	return 0;
}
void Display(Employee Data[], int numberOfEmployee){ 
	for(int i = 0; i<numberOfEmployee;i++){
cout<<"|"<<"ID"<<setw(12)<<"|"<<"First Name"<<setw(20)<<"|"<<"Last Name"<<setw(20)<<"|"<<"Gender"<<setw(1)<<"|"<<"Phone Number"<<setw(13)<<"|"<<"Email"<<setw(25)<<"|"<<"Department"<<setw(15)<<"|"<<"Account Number"<<setw(20)<<"|"<<"Salary"<<setw(10)<<"|\n";
cout<<"|"<<Data[i].ID<<setw(12)<<"|"<<Data[i].FName<<setw(20)<<"|"<<Data[i].LName<<setw(20)<<"|"<<Data[i].Gender<<setw(1)<<"|"<<Data[i].PNum<<setw(13)<<"|"<<Data[i].Email<<setw(25)<<"|"<<Data[i].Dep<<setw(15)<<"|"<<Data[i].AccNum<<setw(20)<<"|"<<Data[i].Salary<<setw(10)<<"|\n";
	}
}
void SwapEmployee(Employee *x,Employee *y){
	Employee temp = *x;
	*x = *y;
	*y = temp;
}
void Search(){ //Implements the Search menu
	int menu;
	system("pause");
	system("cls");
	do{
		cout << "-------------------------"<< "--------" << setw ( 10 )<< "------------------" << setw ( 10 ) << "-------------------------\n\n";
		cout<<"\n\t1. Linear search"<<setw(15)<<endl;
		cout<<"\n\t2. Binary search"<<setw(15)<<endl;
		cout<<"\n\t3. Exit"<<setw(15)<<endl;
		cout << "-------------------------"<< "--------" << setw ( 10 )<< "------------------" << setw ( 10 ) << "-------------------------\n\n";
		cout<<"\n\tyour choice"<<endl;
		cin>>menu;
		switch(menu){
			case 1: LinearSearch();break;
			case 2: BinarySearch();break;
			case 3: MainMenu();break;
			default:
				cout<<"Enter a valid value"<<endl;
				MainMenu();
				break;
		}
	}while(menu>3);//Executes the code once and checks if it should do it again if the value is greater than 3
}
int searchType(){
    cout << "\tAvailable Options:\n\n";
    	cout << "-------------------------"<< "--------" << setw ( 10 )<< "------------------" << setw ( 10 ) << "-------------------------\n\n";
    	cout << "\n\t 1. Based on ID" << setw ( 20 ) << endl;
		cout << "\n\t 2. Based on Phone Number" << setw ( 20 ) << endl;
		cout << "\n\t 3. Based on Account Number" << setw ( 20 ) << endl;
        cout << "\n\t 4. Exit" << setw ( 20 ) << endl;
    int option;
}
char searchkey(){
}
void LinearSearch(){
	//write Linear search algorithm here 
	int use = searchType();
	char key = searchkey();
	if(key == 1) LinearSearch();
	else  BinarySearch();
}
void BinarySearch(){
	//write Binary search algorithm here
}
void Sort(){
//here try to make two options first bubble and seletcion and on both say ascending and descending order
	char use = sortUsing();
	int algo = sortAlgorithm(), arr = sortArrangment();
	if(algo == 1 && arr == 1) ascending_selection(RawData,3,use);
	else if(algo == 1 && arr == 2) descending_selection(RawData,3,use);
	else if(algo==2 && arr ==1) ascending_bubble();		
	else ascending_bubble();
}
char sortUsing(){
	system("pause");
	system("cls");
	use:
	int k;
	cout << "-------------------------"<< "--------" << setw ( 10 )<< "------------------" << setw ( 10 ) << "-------------------------\n\n";
	cout << "Available Options:\n\n";
   	cout << "\n\t1.based on Salary" << setw ( 20 ) << endl;
	cout << "\n\t2.based on First name" << setw ( 20 ) << endl;
    cout << "\n\t3.based on Department" << setw ( 15) << endl;
	cout << "\n\t4. Exit" << setw ( 20 ) << endl;
	cout << "-------------------------"<< "--------" << setw ( 10 )<< "------------------" << setw ( 10 ) << "-------------------------\n\n";
	cout<<"\t\t your choice?"<<endl;
	cin>>k;
	char s;
	switch(k) {
		case 1: s = 'S'; break;
		case 2: s = 'F'; break;
		case 3: s = 'D'; break;
		case 4: system("cls");MainMenu(); break;
		default: 
			cout<<"Enter a valid option";
			goto use;
	} 
	return s;
}
int sortAlgorithm(){
	system("pause");
	system("cls");
	use:
	int n; 
	cout << "-------------------------"<< "--------" << setw ( 10 )<< "------------------" << setw ( 10 ) << "-------------------------\n\n";
	cout << "Available Options:\n\n";
	cout << "\n\t 1.Selection" << setw ( 15 ) << endl;
	cout << "\n\t 2.Bubble" << setw ( 15 ) << endl;
	cout << "\n\t 3. Exit" << setw ( 20 ) << endl;
	cout << "-------------------------"<< "--------" << setw ( 10 )<< "------------------" << setw ( 10 ) << "-------------------------\n\n";
	cout<<"\t\t your choice?"<<endl;
	cin>>n;
	if(n!= 1 && n!=2 && n!=3) {
		cout<<"Enter a valid option";
		goto use;
	}
	if(n == 3) system("cls");MainMenu();
	return n;
}
int sortArrangment(){
	use:
	int p;
	cout << "-------------------------"<< "--------" << setw ( 10 )<< "------------------" << setw ( 10 ) << "-------------------------\n\n";
	cout << "Available Options:\n\n";
	cout << "\n\t1.Ascending" << setw ( 20 ) << endl;
	cout << "\n\t2.Descending" << setw ( 20 ) << endl;
	cout << "\n\t3. Exit" << setw ( 20 ) << endl;
	cout << "-------------------------"<< "--------" << setw ( 10 )<< "------------------" << setw ( 10 ) << "-------------------------\n\n";
	cout<<"\t\t your choice?"<<endl; 
	cin>> p;
	if(p!= 1 && p!=2 && p!=3) {
		cout<<"Enter a valid option";
		goto use;
	}
	if(p == 3) system("cls");MainMenu();
	return p;
}
void ascending_bubble(){
//write ascending bubble search algorithm here	
}
void descending_bubble(){
// write descending bubble search algorithm here
}
void ascending_selection(Employee Data[],int numberOfEmployees,char sortUsing){
	switch(sortUsing){
		case 'S'://using salary 	
			for(int i=0;i<numberOfEmployees-1;i++){// going up the list 
				int imin =i;
				for(int j=i+1;j<numberOfEmployees;j++){//looking for the smallest value to swap it for the current value
					if(Data[j].Salary<Data[imin].Salary) imin = j;
				}
				if(imin != i) {
					SwapEmployee(&Data[i],&Data[imin]);
				}
			}
			break;
		case 'D'://using department
			for(int i=0;i<numberOfEmployees-1;i++){// going up the list 
				int imin =i;

				for(int j=i+1;j<numberOfEmployees;j++){//looking for the smallest value to swap it for the current value
					if(Data[j].Dep<Data[imin].Dep) imin = j;
				}
				if(imin != i) {
					SwapEmployee(&Data[i],&Data[imin]);
				}
			}
			break;
		case 'N'://using name
			for(int i=0;i<numberOfEmployees-1;i++){// going up the list 
				int imin =i;
				for(int j=i+1;j<numberOfEmployees;j++){//looking for the smallest value to swap it for the current value
					if(Data[j].FName<Data[imin].FName) imin = j;
				}
				if(imin != i) {
					SwapEmployee(&Data[i],&Data[imin]);
				}
			}
			break;
	}
	Display(Data, numberOfEmployees);
}	
void descending_selection(Employee Data[],int numberOfEmployees,char sortUsing){
	switch(sortUsing){
		case 'S'://using salary 	
			for(int i=0;i<numberOfEmployees-1;i++){// going up the list 
				int imin =i;
				for(int j=i+1;j<numberOfEmployees;j++){//looking for the smallest value to swap it for the current value
					if(Data[j].Salary>Data[imin].Salary) imin = j;
				}
				if(imin != i) {
					SwapEmployee(&Data[i],&Data[imin]);
				}
			}
			break;
		case 'D'://using department
			for(int i=0;i<numberOfEmployees-1;i++){// going up the list 
				int imin =i;

				for(int j=i+1;j<numberOfEmployees;j++){//looking for the smallest value to swap it for the current value
					if(Data[j].Dep>Data[imin].Dep) imin = j;
				}
				if(imin != i) {
					SwapEmployee(&Data[i],&Data[imin]);
				}
			}
			break;
		case 'N'://using name
			for(int i=0;i<numberOfEmployees-1;i++){// going up the list 
				int imin =i;
				for(int j=i+1;j<numberOfEmployees;j++){//looking for the smallest value to swap it for the current value
					if(Data[j].FName>Data[imin].FName) imin = j;
				}
				if(imin != i) {
					SwapEmployee(&Data[i],&Data[imin]);
				}
			}
			break;
	}
	Display(Data, numberOfEmployees);
}
void Add(){
// write the add algorithm here
	cout << "-------------------------"<< "--------" << setw ( 10 )<< "------------------" << setw ( 10 ) << "-------------------------\n\n";
	cout<<"\n\t How many data you want to add?"<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
		char c;
			cout << "-------------------------"<< "--------" << setw ( 10 )<< "------------------" << setw ( 10 ) << "-------------------------\n\n";
		cout<<"\n\tEnter each value respectively"<<endl;
		cout<<"ID";
		cout<<"First Name";
		cout<<"Last Name";
		cout<<"Gender";
		cout<<"Phone Number";
		cout<<"Email";
		cout<<"Department";
		cout<<"Account Number";
		cout<<"Salary";
		cout<<"is the data correctly added?\n \t\t(Y/N)yes or no = ";
		cin>>c;
		if(c=='N'||'n'){
		}
	}
	for(int i=0;i<n;i++){
		cout<<"The added data is ";
		cout<<"ID = ";
		cout<<"First Name = ";
		cout<<"Last Name = ";
		cout<<"Gender = ";
		cout<<"Phone Number = ";
		cout<<"Email = ";
		cout<<"Department = ";
		cout<<"Account Number = ";
		cout<<"Salary = ";
	}
}
void remove(){
// write the remove algorithm here
}
void MainMenu(){
	//Main Menu
	Menu :
	 cout << "-------------------------"
         << "Pay Roll" << setw ( 10 )
         << " Management System" << setw ( 10 )
         << "-------------------------\n\n";
  
    cout << "\tAvailable Options:\n\n";
    	cout << "-------------------------"<< "--------" << setw ( 10 )<< "------------------" << setw ( 10 ) << "-------------------------\n\n";
    	cout << "\n\t 1. Display" << setw ( 20 ) << endl;
		cout << "\n\t 2. Search" << setw ( 20 ) << endl;
		cout << "\n\t 3. Sort" << setw ( 20 ) << endl;
		cout << "\n\t 4. Add" << setw ( 20 ) << endl;
		cout << "\n\t 5. Remove" << setw ( 20 ) << endl;
        cout << "\n\t 6. Exit" << setw ( 20 ) << endl;
    int option;
    // Input Options
    cin >> option;
    // Call function on the bases of the
    // above option
    if (option == 1) Display(RawData,3);
    else if (option == 2) Search();
    else if (option == 3) Sort();
    else if (option == 4) Add();
    else if (option == 5) remove();
    else if (option == 6) exit(0);
	else {
        cout << "Expected Options"<< " are 1/2/3/4/5/6";
        MainMenu();
    }
}

