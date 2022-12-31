#include <iostream>
#include <string.h>
#include <iomanip>
#include <stdio.h>
#include <fstream>
using namespace std;
int numberOfEmployees = 300;
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
}RawData[1000];
void MainMenu();
void Display(Employee Data[ ]);//displays the content of our data base 
void DisplaySearch(Employee result);
void SwapEmpoyee( Employee *x, Employee *y);//used to swap employees
void Search();//has two choice linear and bubble // searches: ID,PNum,AccNum, only
char searchUsing();//searchs using ID,PNum,AccNum,
int searchAlgorithm();//chooses from linear ,binary
void LinearSearch( Employee Data[ ], char searchUsing);
void BinarySearch( Employee Data[ ], char searchUsing);
void Sort();// has two choices ascending and descending // sorts based on: Salary,Dep,& Fname
char sortUsing();//chooses from salary,dep,fname
int sortAlgorithm();//chooses which algorithm to take
int sortArrangment();//chooses from ascending or descending
void ascending_selection( Employee Data[ ], char sortUsing);
void descending_selection( Employee Data[ ], char sortUsing);
void ascending_bubble( Employee Data[ ], char sortUsing);
void descending_bubble( Employee Data[ ], char sortUsing);
void Add();// adds new data into our database
void remove();//removes searched data from our databse 
void Read();
//Linked List struct will be applied after next week to save time and reduce complexity *DELETE THIS LINE ON PRODUCTION*
int main() {
	Read();
	MainMenu();
	return 0;
}
void Display(Employee Data[ ]){ 
	//cout<<setfill('_')<<setw(155);
	cout << "\n|" << setw ( 12 ) << "ID" << "|"<< setw ( 10 )  << "First Name" << "|" << setw ( 12 ) << "Last Name" << setw ( 1 )<< "|" << "Gender"  <<"|" << setw ( 14 )<< "Phone Number"  << "|" << setw ( 35 )<< "Email"  << "|" << setw ( 25 ) << "Department" << "|" << setw ( 20 )<< "Account Number"  << "|"  << setw ( 10 ) << "Salary"<< "|\n";
	for ( int i = 0; i < numberOfEmployees; i++){
		cout << "|"  << setw ( 12 )<< Data[ i ].ID << "|"  << setw ( 10 ) << Data[ i ].FName<< "|" << setw ( 12 ) << Data[ i ].LName << "|"  << setw ( 6 )<< Data[ i ].Gender << "|"<< setw ( 13 ) << Data[ i ].PNum  << "|"<< setw ( 35 ) << Data[ i ].Email  << "|"<< setw ( 25 )<<Data[ i ].Dep  << "|"<< setw ( 20 ) << Data[ i ].AccNum  << "|"  << setw ( 10 )<< Data[ i ].Salary << "|\n";
	}
}
void DisplaySearch(Employee result){
	system("cls");
	cout << "-------------------------" << "--------" << setw ( 10 ) << "------------------" << setw ( 10 ) << "-------------------------\n\n";
	cout<<"\n\t\tEmployee\n";
	cout<<"\t\tName: "<<result.FName<<" "<<result.LName<<endl;
	cout<<"\t\tId: "<<result.ID<<endl;
	cout<<"\t\tGender: "<<result.Gender<<endl;
	cout<<"\t\tEmail: "<<result.Email<<endl;
	cout<<"\t\tPhone Number: "<<result.PNum<<endl;
	cout<<"\t\tDepartment: "<<result.Dep<<endl;
	cout<<"\t\tAccount Number:"<<result.AccNum<<endl;
	cout<<"\t\tSalary: "<<result.Salary<<endl;
	cout<< "-------------------------" << "--------" << setw ( 10 ) << "------------------" << setw ( 10 ) << "-------------------------\n\n";
 MainMenu();
 }
void SwapEmployee( Employee *x, Employee *y){
	Employee temp = *x;
	*x = *y;
	*y = temp;
}
void Search(){ //Implements the Search menu
	char use = searchUsing();
	int algo = searchAlgorithm();
	if ( algo == 1 ) LinearSearch( RawData, use);
	else BinarySearch( RawData, use);		
}
char searchUsing(){
	system("cls");
	use:
	int op;
	int s;
	cout << "\tAvailable Options:\n\n";
	cout << "-------------------------" << "--------" << setw ( 10 ) << "------------------" << setw ( 10 ) << "-------------------------\n\n";
	cout << "\n\t 1. Based on ID" << setw ( 20 ) << endl;
	cout << "\n\t 2. Based on Phone Number" << setw ( 20 ) << endl;
	cout << "\n\t 3. Based on Account Number" << setw ( 20 ) << endl;
	cout << "\n\t 4. Exit" << setw ( 20 ) << endl;
	cin >> op;
	switch ( op ){
		case 1: s = 'I'; break;
		case 2: s = 'P'; break;
		case 3: s = 'A'; break;
		case 4: system( "cls" );MainMenu(); break;
		default: 
			cout << "Enter a valid option";
			goto use;
	} 
	return s;
}
int searchAlgorithm(){
	system("cls");
	use:
	int r;
	cout << "\tAvailable Options:\n\n";
	cout << "-------------------------" << "--------" << setw ( 10 ) << "------------------" << setw ( 10 ) << "-------------------------\n\n";
	cout << "\n\t 1. Linear Search" << setw ( 20 ) << endl;
	cout << "\n\t 2. Binary Search" << setw ( 20 ) << endl;
	cout << "\n\t 3. Exit" << setw ( 20 ) << endl;
	cout << "-------------------------" << "--------" << setw ( 10 ) << "------------------" << setw ( 10 ) << "-------------------------\n\n";
	cin >> r;
	if ( r != 1 && r != 2 && r != 3){
		cout << "Enter a valid option";
		goto use;
	}
	if ( r== 3) {
		system( "cls" ); 
		searchUsing();
	}
	return r;
}	
void LinearSearch( Employee Data[ ], char searchUsing){	
// write linear search algorithm here
	system("cls");
	string key;
	bool found = false;
	cout << "\n\t\t\tEnter the ID/PhoneNumber/AccountNumber of the Employee you want to be searched?\n";
	cin>> key;
	for ( int i = 0; i < numberOfEmployees; i++){
		if(searchUsing=='I'&& Data[ i ].ID == key){
			found = true; 
			DisplaySearch(Data[i]);
		}else if(searchUsing=='P' && Data[ i ].PNum == key){
			found = true; 
			DisplaySearch(Data[i]);
		}else if(searchUsing=='A' && Data[ i ].AccNum == key){
			found = true; 
			DisplaySearch(Data[i]);
		}
	}
	if(!found) {
		system("cls");
		cout << "-------------------------" << "--------" << setw ( 10 ) << "------------------" << setw ( 10 ) << "-------------------------\n\n";
		cout<<"\t\t\tThe data u have entered is incorrect \n\t\t\tTry to input acorrect";
		if (searchUsing == 'I') cout<<" ID Number.";
		else if(searchUsing == 'P') cout<<" Phone Number.";
		else cout<<" Account Number.";
		Search();
	}
}
void BinarySearch(Employee Data[ ], char searchUsing){
//write the binary search algorithm here
	system("cls");
	string key;
	bool found = false;
	int low = 0;
	int mid;
	int high = numberOfEmployees-1;
	cout << "\n\t\t\tEnter the ID/PhoneNumber/AccountNumber of the Employee you want to be searched?\n";
	cin>> key;
	for(int i=0;i<numberOfEmployees-1;i++){// going up the list 
		int imin =i;
		for(int j=i+1;j<numberOfEmployees;j++){//looking for the smallest value to swap it for the current value
			if(Data[j].ID<Data[imin].ID) imin = j;
		}
  		if(imin != i) SwapEmployee(&Data[i],&Data[imin]);
	}
	while(low <= high){
		mid = ( high + low)/2;
		switch(searchUsing){
			case 'I':
				if(key == Data[mid].ID) {
					DisplaySearch(Data[mid]);
					found = true;
				}
				else if( key < Data[mid].ID) high = mid -1;
				else low = mid +1;
				break;
			case 'P':
				if(key == Data[mid].PNum) {
					DisplaySearch(Data[mid]);
					found = true;
				}
				else if( key < Data[mid].PNum) high = mid -1;
				else low = mid +1;
				break;
			case 'A':
				if(key == Data[mid].AccNum) {
					DisplaySearch(Data[mid]);
					found = true;
				}
				else if( key < Data[mid].AccNum) high = mid -1;
				else low = mid +1;
				break;
		} 
	}
    if(!found) {
		system("cls");
		cout << "-------------------------" << "--------" << setw ( 10 ) << "------------------" << setw ( 10 ) << "-------------------------\n\n";
		cout<<"\t\t\tThe data u have entered is incorrect \n\t\t\tTry to input acorrect";
		if (searchUsing == 'I') cout<<" ID Number.";
		else if(searchUsing == 'P') cout<<" Phone Number.";
		else cout<<" Account Number.";
		Search();
	}
}
void Sort(){
	//here try to make two options first bubble and seletcion and on both say ascending and descending order
	char use = sortUsing();
	int algo = sortAlgorithm(), arr = sortArrangment();
	if ( algo == 1 && arr == 1) ascending_selection( RawData, use);
	else if ( algo == 1 && arr == 2) descending_selection(RawData, use);
	else if ( algo ==2 && arr ==1) ascending_bubble( RawData, use);		
	else descending_bubble( RawData, use);
}		
char sortUsing(){
	system ("cls" );
	use:
	int k;
	cout << "-------------------------" << "--------" << setw ( 10 ) << "------------------" << setw ( 10 ) << "-------------------------\n\n";
	cout << "Available Options:\n\n";
	cout << "\n\t1.based on Salary" << setw ( 20 ) << endl;
	cout << "\n\t2.based on First name" << setw ( 20 ) << endl;
	cout << "\n\t3.based on Department" << setw ( 15) << endl;
	cout << "\n\t4. Exit" << setw ( 20 ) << endl;
	cout << "-------------------------" << "--------" << setw ( 10 ) << "------------------" << setw ( 10 ) << "-------------------------\n\n";
	cout << "\t\t your choice?" << endl;
	cin >> k;
	char s;
	switch( k ){
		case 1: s = 'S'; break;
		case 2: s = 'N'; break;
		case 3: s = 'D'; break;
		case 4: system( "cls" );MainMenu(); break;
		default: 
			cout << "Enter a valid option";
			goto use;
	} 
	return s;
}
int sortAlgorithm(){
	system( "cls" );
	use:
	int n; 
	cout << "-------------------------" << "--------" << setw ( 10 ) << "------------------" << setw ( 10 ) << "-------------------------\n\n";;
	cout << "Available Options:\n\n";
	cout << "\n\t 1.Selection" << setw ( 15 ) << endl;
	cout << "\n\t 2.Bubble" << setw ( 15 ) << endl;
	cout << "\n\t 3. Exit" << setw ( 20 ) << endl;
	cout << "-------------------------" << "--------" << setw ( 10 ) << "------------------" << setw ( 10 ) << "-------------------------\n\n";
	cout << "\t\t your choice?" << endl;
	cin >> n;
	if ( n != 1 && n != 2 && n != 3) {
		cout << "Enter a valid option";
		goto use;
	} else if ( n == 3 ) {
		system( "cls" );
	   	Sort();	
	}
	return n;
}
int sortArrangment(){
	system("cls");
	use:
	int p;
	cout << "-------------------------" << "--------" << setw ( 10 ) << "------------------" << setw ( 10 ) << "-------------------------\n\n";
	cout << "Available Options:\n\n";
	cout << "\n\t1.Ascending" << setw ( 20 ) << endl;
	cout << "\n\t2.Descending" << setw ( 20 ) << endl;
	cout << "\n\t3. Exit" << setw ( 20 ) << endl;
	cout << "-------------------------" << "--------" << setw ( 10 ) << "------------------" << setw ( 10 ) << "-------------------------\n\n";
	cout << "\t\t your choice?" << endl; 
	cin >> p;
	if ( p != 1 && p != 2 && p != 3){
		cout << "Enter a valid option";
		goto use;
	}
	if ( p == 3) {
		system( " cls "); 
		Sort();
	}
	return p;
	}
void ascending_bubble( Employee Data[ ], char sortUsing){
	for(int i=0;i<numberOfEmployees-1;i++){//goes through the list
			int flag = 0;
		for(int j=0;j<numberOfEmployees-(i+1);j++){//starts comparing up the list
			if (sortUsing=='S'&&Data[j].Salary>Data[j+1].Salary)SwapEmployee( &Data[ j ], &Data[ j+1 ]); flag = 1;	
			if(sortUsing=='D'&&Data[j].Dep>Data[j+1].Dep)SwapEmployee( &Data[ j ], &Data[ j+1 ]); flag = 1;	
			if(sortUsing=='N'&&Data[j].FName>Data[j+1].FName)SwapEmployee( &Data[ j ], &Data[ j+1 ]); flag = 1;
		}
	}
	if(sortUsing == 'S')cout<<"\t\t\t***************this is sorted(Salary) using bubble sort ascending order***************"<<endl;
	else if(sortUsing == 'D')cout<<"\t\t\t***************this is sorted(Department) using bubble sort ascending order***************"<<endl;
	else cout<<"\t\t\t***************this is sorted(First Name) using bubble sort ascending order***************"<<endl;
	Display(Data);
}
void descending_bubble( Employee Data[ ], char sortUsing){
	for(int i=0;i<numberOfEmployees-1;i++){//goes through the list
			int flag = 0;
		for(int j=0;j<numberOfEmployees-(i+1);j++){//starts comparing up the list
			if(sortUsing=='S'&&Data[j].Salary<Data[j+1].Salary)SwapEmployee( &Data[ j ], &Data[ j+1 ]); flag = 1;	
			if(sortUsing=='D'&&Data[j].Dep<Data[j+1].Dep)SwapEmployee( &Data[ j ], &Data[ j+1 ]); flag = 1;	
			if(sortUsing=='N'&&Data[j].FName<Data[j+1].FName)SwapEmployee( &Data[ j ], &Data[ j+1 ]); flag = 1;
		}
	}
	if(sortUsing == 'S')cout<<"\t\t\t***************this is sorted(Salary) using bubble sort ascending order***************"<<endl;
	else if(sortUsing == 'D')cout<<"\t\t\t***************this is sorted(Department) using bubble sort ascending order***************"<<endl;
	else cout<<"\t\t\t***************this is sorted(First Name) using bubble sort ascending order***************"<<endl;
	Display(Data);
}		
void ascending_selection(Employee Data[], char sortUsing){
	for(int i=0;i<numberOfEmployees-1;i++){
		int imin =i;
	for(int j=i+1;j<numberOfEmployees;j++){
		if(sortUsing=='S'&& Data[j].Salary<Data[imin].Salary) imin = j;
		if(sortUsing=='D'&&Data[j].Dep<Data[imin].Dep)imin = j;
		if(sortUsing=='N'&&Data[j].FName<Data[imin].FName) imin = j; 
	}
		if(imin != i) SwapEmployee(&Data[i],&Data[imin]);	
	}
	if(sortUsing == 'S') cout<<"\t\t\t***************this is sorted(Salary) using selection sort ascending order***************"<<endl;
	else if(sortUsing == 'D') cout<<"\t\t\t***************this is sorted(Department) using selection sort ascending order***************"<<endl;
	else cout<<"\t\t\t***************this is sorted(First Name) using selection sort ascending order***************"<<endl;
	Display(Data);
}	
void descending_selection(Employee Data[], char sortUsing){
	for(int i=0;i<numberOfEmployees-1;i++){
		int imin =i;
	for(int j=i+1;j<numberOfEmployees;j++){
		if(sortUsing=='S'&& Data[j].Salary>Data[imin].Salary) imin = j;
		if(sortUsing=='D'&&Data[j].Dep>Data[imin].Dep)imin = j;
		if(sortUsing=='N'&&Data[j].FName>Data[imin].FName) imin = j; 
	}
		if(imin != i) SwapEmployee(&Data[i],&Data[imin]);	
	}
	if(sortUsing == 'S') cout<<"\t\t\t***************this is sorted(Salary) using selection sort descending order***************"<<endl;
	else if(sortUsing == 'D') cout<<"\t\t\t***************this is sorted(Department) using selection sort descending order***************"<<endl;
	else cout<<"\t\t\t***************this is sorted(First Name) using bubble selection descending order***************"<<endl;
	Display(Data);
}
void MainMenu(){
	int option;
	do{
		system("pause");
		system("cls");
		cout << "-------------------------"
		<< "Pay Roll" << setw ( 10 )
		<< " Management System" << setw ( 10 )
		<< "-------------------------\n\n";
		cout << "\tAvailable Options:\n\n";
		cout << "-------------------------" << "--------" << setw ( 10 ) << "------------------" << setw ( 10 ) << "-------------------------\n\n";
		cout << "\n\t 1. Display" << setw ( 20 ) << endl;
		cout << "\n\t 2. Search" << setw ( 20 ) << endl;
		cout << "\n\t 3. Sort" << setw ( 20 ) << endl;
		cout << "\n\t 4. Add" << setw ( 20 ) << endl;
		cout << "\n\t 5. Remove" << setw ( 20 ) << endl;
		cout << "\n\t 6. Exit" << setw ( 20 ) << endl;
		// Input Options
		cin >> option;
		cout<<endl;
		// Call function on the bases of the
		// above option
		if ( option == 1) Display( RawData);
		else if ( option == 2) Search();
		else if ( option == 3) Sort();
		else if ( option == 4) Add();
		else if ( option == 5) remove();
		else if ( option == 6){
		char f;
		system("cls");
		cout<<"\n\n\n\n\t\t\tDo you want to exit the app?\n\t\t\tif yes press Y or not press any key?"<<endl;
		cin>>f;
		if( 'y'||'Y'==f)exit(0);
		}
		else{
			cout << "Expected Options"<< " are 1/2/3/4/5/6";
		}
	} while(option!=6);
}
void remove(){
}
void Add(){
}
void Read(){
	ifstream File; File.open("DB.txt");
	for(int i=0; i<300; i++){
		File>>RawData[i].ID;
		File>>RawData[i].FName;
		File>>RawData[i].LName;
		File>>RawData[i].Gender;
		File>>RawData[i].PNum;
		File>>RawData[i].Email;
		File>>RawData[i].Dep;
		File>>RawData[i].AccNum;
		File>>RawData[i].Salary;
	}
	File.close();
}
