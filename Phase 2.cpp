#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

 const int MAX_BOOK_ID = 13, DATE_SIZE = 11, MAX_COPY_NUMBER = 17, MAX_BOOKS = 200, MAX_CAEGORIES = 30, MAX_BOOK_NAME = 60, MAX_CATEGORY_NAME = 20, MAX_CATEGORY_NUMBER = 4, MAX_STUDENTS = 100, MAX_REGISTRATION_NUMBER = 12, MAX_STUDENT_NAME = 60;
 int x = 0, x1 = 0, x2 = 0, x3 = 0;
 ofstream fout, fout1, fout2, fout3;
 struct Category{
    char Id[MAX_CATEGORY_NUMBER];
    char Name[MAX_CATEGORY_NAME];
 };
 struct Book{
    char Id[MAX_BOOK_ID];
    char Name[MAX_BOOK_NAME];
    int Edition;
 };
 struct Date{
    int Day;
    int Month;
    int Year;
 };
 struct BookCopy{
    char Id[MAX_COPY_NUMBER];
    Date PurchaseDate;
 };
 struct Student{
    char RegistrationNo[MAX_REGISTRATION_NUMBER];
    char name[MAX_STUDENT_NAME];
    int Session;
    Date AdmissionDate;
 };
 
 void saveStudents(Student arr[], int arraySize){
 	int s, d;
 	fout3.open("students.csv");
 	for(s = 1; s < x3; s = s + 2){
 		for(d= 0; d < MAX_REGISTRATION_NUMBER; d++){
 			if(arr[s].RegistrationNo[d] != '@'){
 				fout3 << arr[s].RegistrationNo[d];
			 }
 		    
		}
		fout3 << ",";
		for(d = 0; d < MAX_STUDENTS and arr[s].name[d] != '\O'; d++){
			if(arr[s].name[d] >= 'A' and arr[s].name[d] <= 'Z' or arr[s].name[d] >= 'a' and arr[s].name[d] <= 'z' and arr[s].name[d] != '@'){
				fout3 << arr[s].name[d];
			}
		}
		if(arr[s].Session != 0 and arr[s].AdmissionDate.Day != 0){
			fout3 << "," << arr[s].Session << ",";
	    	fout3 << arr[s].AdmissionDate.Day << "-" << arr[s].AdmissionDate.Month << "-" << arr[s].AdmissionDate.Year << endl;
		}
	}
	fout3.close();
 }
 
 bool editStudent(Student arr[], int arraySize, char regNo[], Student newData){
 	int s, d, flag;
	for(s = 1; s < x3; s = s + 2){
		while(d < MAX_REGISTRATION_NUMBER){
			if(regNo[d] == arr[s].RegistrationNo[d] and regNo[d + 1] == arr[s].RegistrationNo[d + 1] and regNo[d + 2] == arr[s].RegistrationNo[d + 2] and regNo[d + 3] == arr[s].RegistrationNo[d + 3] and regNo[d + 4] == arr[s].RegistrationNo[d + 4] and regNo[d + 5] == arr[s].RegistrationNo[d + 5] and regNo[d + 6] == arr[s].RegistrationNo[d + 6] and regNo[d + 7] == arr[s].RegistrationNo[d + 7] and regNo[d + 8] == arr[s].RegistrationNo[d + 8] and regNo[d + 9] == arr[s].RegistrationNo[d + 9] and regNo[d + 10] == arr[s].RegistrationNo[d + 10]){
				flag = 1;
				break;
			}
			else{
				flag = 0;
				break;
			}
		}
		if(flag == 1){
			break;
	    }
	}
	if(flag == 0){
		return false;
	}
	for(d = 0; d < MAX_REGISTRATION_NUMBER; d++){
		arr[s].RegistrationNo[d] = newData.RegistrationNo[d];
	}
	for(d = 0; d < MAX_STUDENT_NAME; d++){
		arr[s].name[d] = newData.name[d];
	}
	arr[s].Session = newData.Session;
	arr[s].AdmissionDate.Day = newData.AdmissionDate.Day;
	arr[s].AdmissionDate.Month = newData.AdmissionDate.Month;
	arr[s].AdmissionDate.Year = newData.AdmissionDate.Year;
	
	return true;
 }
 
 bool deleteStudent(Student arr[], int arraySize, char regNo[]){
 	int s, d, flag;
	for(s = 1; s < x3; s = s + 2){
		while(d < MAX_BOOK_ID){
			if(regNo[d] == arr[s].RegistrationNo[d] and regNo[d + 1] == arr[s].RegistrationNo[d + 1] and regNo[d + 2] == arr[s].RegistrationNo[d + 2] and regNo[d + 3] == arr[s].RegistrationNo[d + 3] and regNo[d + 4] == arr[s].RegistrationNo[d + 4] and regNo[d + 5] == arr[s].RegistrationNo[d + 5] and regNo[d + 6] == arr[s].RegistrationNo[d + 6] and regNo[d + 7] == arr[s].RegistrationNo[d + 7] and regNo[d + 8] == arr[s].RegistrationNo[d + 8] and regNo[d + 9] == arr[s].RegistrationNo[d + 9] and regNo[d + 10] == arr[s].RegistrationNo[d + 10]){
				flag = 1;
				break;
			}
			else{
				flag = 0;
				break;
			}
		}
		if(flag == 1){
			break;
	    }
	}
	if(flag == 0){
		return false;
	}
	for(d = 0; d < MAX_BOOK_ID; d++){
		arr[s].RegistrationNo[d] = '@';
	}
	for(d = 0; d < MAX_BOOK_NAME; d++){
		arr[s].name[d] = '@';
	}
	arr[s].Session = 0;
	arr[s].AdmissionDate.Day = 0;
	arr[s].AdmissionDate.Month = 0;
	arr[s].AdmissionDate.Year = 0;
	
	return true;
 }
 
 void printStudents(Student arr[], int arraySize){
 	int s, d;
 	for(s = 1; s < x3; s = s + 2){
 		for(d= 0; d < MAX_REGISTRATION_NUMBER; d++){
 			if(arr[s].RegistrationNo[d] != '@'){
 				cout << arr[s].RegistrationNo[d];
			 }
 		    
		}
		cout << "\t";
		for(d = 0; d < MAX_STUDENTS and arr[s].name[d] != '\O'; d++){
			if(arr[s].name[d] >= 'A' and arr[s].name[d] <= 'Z' or arr[s].name[d] >= 'a' and arr[s].name[d] <= 'z' and arr[s].name[d] != '@'){
				cout << arr[s].name[d];
			}
		}
		if(arr[s].Session != 0 and arr[s].AdmissionDate.Day != 0){
			cout << "\t" << arr[s].Session << "\t";
	    	cout << arr[s].AdmissionDate.Day << "-" << arr[s].AdmissionDate.Month << "-" << arr[s].AdmissionDate.Year << endl;
		}
	}
 }
 
 bool saveBookCopies(BookCopy arr[], int arraySize){
 	int s, d, z;
 	fout2.open("bookcopies.csv");
	for(s = 0; s < x2; s++){
		for(d = 0; d < MAX_COPY_NUMBER - 1; d++){
			if(arr[s].Id[d] != '@'){
				fout2 << arr[s].Id[d];
			}
		}
		fout2 << ",";
		if(arr[s].PurchaseDate.Day != 0){
			fout2 << arr[s].PurchaseDate.Day;
			fout2 << "-";
			fout2 << arr[s].PurchaseDate.Month;
			fout2 << "-";
			fout2 << arr[s].PurchaseDate.Year;
		}
		fout2 << endl;
    }
    fout2.close();
 }
 
 bool addBookCopy(BookCopy arr[], int arraySize, BookCopy newBookCopy){
    static int s = 0;
    int d;
    for(d = 0; d < MAX_COPY_NUMBER; d++){
		arr[s].Id[d] = newBookCopy.Id[d];
	}
	arr[s].PurchaseDate.Day = newBookCopy.PurchaseDate.Day;
	arr[s].PurchaseDate.Month = newBookCopy.PurchaseDate.Month;
	arr[s].PurchaseDate.Year = newBookCopy.PurchaseDate.Year;
	s++;
	x2++;
	return true;
 }
 
 bool isValidCopyNumber(char bookCopy[]){
    int s = 0, flag = 0;
	while(bookCopy[s] != 0){
		if(s >= 0 and s <= 2 and bookCopy[s] >= '0' and bookCopy[s] <= '9'){
			flag = 1;
			s++;
			continue;
		}
		else if(s == 3 or s == 6 and bookCopy[s] == '-'){
			flag = 1;
			s++;
			continue;
		}
		else if(s == 4 or s == 5 and bookCopy[s] >= 'A' and bookCopy[s] <= 'Z'){
			flag = 1;
			s++;
			continue;
		}
		else if(s >= 7  and s <= 11 and bookCopy[s] >= '0' and bookCopy[s] <= '9'){
			flag = 1;
			s++;
			continue;
		}
		else if(s == 12 and bookCopy[s] == '#'){
			flag = 1;
			s++;
			continue;
		}
		else if(s == 13 and bookCopy[s] == '0'){
			flag = 1;
			s++;
			continue;
		}
		else if(s == 14 and bookCopy[s] == '0' and bookCopy[s + 1] >= '1' and bookCopy[s + 1] <= '9'){
			flag = 1;
			s = s + 2;
			continue;
		}
		else if(s == 14 and bookCopy[s] == '1' and bookCopy[s + 1] >= '0' and bookCopy[s + 1] <= '7'){
			flag = 1;
			s = s + 2;
			continue;
		}
		else{
			flag = 0;
			break;
		}
	}
	if(flag == 1){
		return true;
	}
	else{
		return false;
	}
 }
 
 void printBookCopy(BookCopy arr[], int arraySize){
 	int s, d, z;
	cout << "\tCopy Id\t\t\tPurchase Date\n";
	for(s = 0; s < x2; s++){
		cout << "\t";
		for(d = 0; d < MAX_COPY_NUMBER - 1; d++){
			if(arr[s].Id[d] != '@'){
				cout << arr[s].Id[d];
			}
		}
		cout << "\t";
		if(arr[s].PurchaseDate.Day != 0){
			cout << arr[s].PurchaseDate.Day << "-" << arr[s].PurchaseDate.Month << "-" << arr[s].PurchaseDate.Year;
		}
		cout << endl;
    }
 }
 
 bool deleteBookCopy(BookCopy arr[], int arraySize, char bookCopy[]){
 	int s, d, flag;
	for(s = 0; s < x2; s++){
		while(d < MAX_COPY_NUMBER){
			if(bookCopy[d] == arr[s].Id[d] and bookCopy[d + 1] == arr[s].Id[d + 1] and bookCopy[d + 2] == arr[s].Id[d + 2] and bookCopy[d + 3] == arr[s].Id[d + 3] and bookCopy[d + 4] == arr[s].Id[d + 4] and bookCopy[d + 5] == arr[s].Id[d + 5] and bookCopy[d + 6] == arr[s].Id[d + 6] and bookCopy[d + 7] == arr[s].Id[d + 7] and bookCopy[d + 8] == arr[s].Id[d + 8] and bookCopy[d + 9] == arr[s].Id[d + 9] and bookCopy[d + 10] == arr[s].Id[d + 10] and bookCopy[d + 11] == arr[s].Id[d + 11] and bookCopy[d + 12] == arr[s].Id[d + 12] and bookCopy[d + 13] == arr[s].Id[d + 13] and bookCopy[d + 14] == arr[s].Id[d + 14] and bookCopy[d + 15] == arr[s].Id[d + 15]){
				flag = 1;
				break;
			}
			else{
				flag = 0;
				break;
			}
		}
		if(flag == 1){
			break;
	    }
	}
	if(flag == 0){
		return false;
	}
	for(d = 0; d < MAX_COPY_NUMBER; d++){
		arr[s].Id[d] = '@';
	}
	arr[s].PurchaseDate.Day = 0;
	arr[s].PurchaseDate.Month = 0;
	arr[s].PurchaseDate.Year = 0;
	
	return true;
 }
 
 bool editBookCopy(BookCopy arr[], int arraySize, char bookCopy[], BookCopy newData){
 	int s, d, flag;
	for(s = 0; s < x1; s++){
		while(d < MAX_COPY_NUMBER){
			if(bookCopy[d] == arr[s].Id[d] and bookCopy[d + 1] == arr[s].Id[d + 1] and bookCopy[d + 2] == arr[s].Id[d + 2] and bookCopy[d + 3] == arr[s].Id[d + 3] and bookCopy[d + 4] == arr[s].Id[d + 4] and bookCopy[d + 5] == arr[s].Id[d + 5] and bookCopy[d + 6] == arr[s].Id[d + 6] and bookCopy[d + 7] == arr[s].Id[d + 7] and bookCopy[d + 8] == arr[s].Id[d + 8] and bookCopy[d + 9] == arr[s].Id[d + 9] and bookCopy[d + 10] == arr[s].Id[d + 10] and bookCopy[d + 11] == arr[s].Id[d + 11] and bookCopy[d + 12] == arr[s].Id[d + 12] and bookCopy[d + 13] == arr[s].Id[d + 13] and bookCopy[d + 14] == arr[s].Id[d + 14] and bookCopy[d + 15] == arr[s].Id[d + 15]){
				flag = 1;
				break;
			}
			else{
				flag = 0;
				break;
			}
		}
		if(flag == 1){
			break;
	    }
	}
	if(flag == 0){
		return false;
	}
	for(d = 0; d <MAX_COPY_NUMBER; d++){
		arr[s].Id[d] = newData.Id[d];
	}
	arr[s].PurchaseDate.Day = newData.PurchaseDate.Day;
	arr[s].PurchaseDate.Month = newData.PurchaseDate.Month;
	arr[s].PurchaseDate.Year = newData.PurchaseDate.Year;
	
	return true;
 }
 
 bool addStudent(Student arr[], int arraySize, Student newStudent){
    static int s = 0;
	int d;
	for(d = 0; d < MAX_REGISTRATION_NUMBER; d++){
		arr[s].RegistrationNo[d] = newStudent.RegistrationNo[d];
	}
	for(d = 0; d < MAX_STUDENT_NAME and newStudent.name[d] != 0; d++){
		arr[s].name[d] = newStudent.name[d];
	}
	arr[s].Session = newStudent.Session;
	arr[s].AdmissionDate.Day = newStudent.AdmissionDate.Day;
	arr[s].AdmissionDate.Month = newStudent.AdmissionDate.Month;
	arr[s].AdmissionDate.Year = newStudent.AdmissionDate.Year;
	s++;
	x3++;
	return true;
 }
 
 bool isValidRegistrationNo(char regNo[]){
    int s = 0, flag;
    while(regNo[s] != 0){
    	if(s >= 0 and s <= 3 and regNo[s] >= '0' and regNo[s] <= '9'){
    		flag = 1;
    		s++;
		}
		else if(s == 4 or s == 7 and regNo[s] >= '-' and regNo[s] <= '-'){
			flag = 1;
			s++;
		}
		else if(s == 5 or s == 6 and regNo[s] >= 'A' and regNo[s] <= 'Z'){
			flag = 1;
			s++;
		}
		else if(s >= 8 and s <= 10 and regNo[s] >= '0' and regNo[s] <= '9'){
			flag = 1;
			s++;
		}
		else{
			flag = 0;
			break;
		}
	}
	if(flag == 1 and s >= 9 and s <= 11){
		return true;
	}
	else{
		return false;
	}
	
 }
 
 bool isValidStudentName(char stdName[]){
    int s = 0, flag;
    while(stdName[s] != 0){
    	if(stdName[s] >= 'a' and stdName[s] <= 'z' or stdName[s] >= 'A' and stdName[s] <= 'Z'){
    		flag = 1;
    		s++;
		}
		else{
			flag = 0;
			break;
		}
	}
	if(flag == 1){
		return true;
	}
	else{
		return false;
	}
 }
 
  bool isValidDate(Date date){
    int flag;
	if(date.Year > 2000 and date.Year < 2021 and date.Month > 0 and date.Month < 13 and date.Day > 0 and date.Day < 32 or date.Month == 2 and date.Day <= 30){
		flag = 1;
	}
	if(flag == 1){
		return true;
	}
	else{
		return false;
	}
 }
 
 bool isExist(Category arr[], int arraySize, char catId[]){
    int s, d, flag;
	for(s = 0; s < x; s++){
		while(d < MAX_CATEGORY_NUMBER){
			if(catId[d] == arr[s].Id[d] and catId[d + 1] == arr[s].Id[d + 1] and catId[d + 2] == arr[s].Id[d + 2]){
				flag = 0;
				break;
			}
			else{
				flag = 1;
			}
		}
		if(flag == 0){
			break;
	    }
	}
	if(flag == 0){
		return false;
	}
	else{
		return true;
	}
 }
 
 bool UpdateBook(Book arr[], int ArraySize, char bookId[], Book newData){
	int s, d, flag;
	for(s = 0; s < x1; s++){
		while(d < MAX_BOOK_ID){
			if(bookId[d] == arr[s].Id[d] and bookId[d + 1] == arr[s].Id[d + 1] and bookId[d + 2] == arr[s].Id[d + 2] and bookId[d + 3] == arr[s].Id[d + 3] and bookId[d + 4] == arr[s].Id[d + 4] and bookId[d + 5] == arr[s].Id[d + 5] and bookId[d + 6] == arr[s].Id[d + 6] and bookId[d + 7] == arr[s].Id[d + 7] and bookId[d + 8] == arr[s].Id[d + 8] and bookId[d + 9] == arr[s].Id[d + 9] and bookId[d + 10] == arr[s].Id[d + 10] and bookId[d + 11] == arr[s].Id[d + 11]){
				flag = 1;
				break;
			}
			else{
				flag = 0;
				break;
			}
		}
		if(flag == 1){
			break;
	    }
	}
	if(flag == 0){
		return false;
	}
	for(d = 0; d < MAX_BOOK_ID; d++){
		arr[s].Id[d] = newData.Id[d];
	}
	for(d = 0; d < MAX_BOOK_NAME; d++){
		arr[s].Name[d] = newData.Name[d];
	}
	arr[s].Edition = newData.Edition;
	
	return true;
 }
 
 bool deleteBook(Book arr[], int ArraySize, char bookId[]){
	int s, d, flag;
	for(s = 0; s < x1; s++){
		while(d < MAX_BOOK_ID){
			if(bookId[d] == arr[s].Id[d] and bookId[d + 1] == arr[s].Id[d + 1] and bookId[d + 2] == arr[s].Id[d + 2] and bookId[d + 3] == arr[s].Id[d + 3] and bookId[d + 4] == arr[s].Id[d + 4] and bookId[d + 5] == arr[s].Id[d + 5] and bookId[d + 6] == arr[s].Id[d + 6] and bookId[d + 7] == arr[s].Id[d + 7] and bookId[d + 8] == arr[s].Id[d + 8] and bookId[d + 9] == arr[s].Id[d + 9] and bookId[d + 10] == arr[s].Id[d + 10] and bookId[d + 11] == arr[s].Id[d + 11]){
				flag = 1;
				break;
			}
			else{
				flag = 0;
				break;
			}
		}
		if(flag == 1){
			break;
	    }
	}
	if(flag == 0){
		return false;
	}
	for(d = 0; d < MAX_BOOK_ID; d++){
		arr[s].Id[d] = '#';
	}
	for(d = 0; d < MAX_BOOK_NAME; d++){
		arr[s].Name[d] = '#';
	}
	arr[s].Edition = 0;
	
	return true;
 }
 
 void PrintBooks(Book arr[], int ArraySize){
	int s, d, z;
	cout << "\tBook Id\t\t Name\t\tEdition\n";
	for(s = 0; s < x1; s++){
		cout << "\t";
		for(d = 0; d < MAX_BOOK_ID - 1; d++){
			if(arr[s].Id[d] != '#'){
				cout << arr[s].Id[d];
			}	
		}
		cout << "\t";
		for(z = 0; z < MAX_BOOK_NAME and arr[s].Name[z] != '\O'; z++){
			if(arr[s].Name[z] >= 'A' and arr[s].Name[z] <= 'Z' or arr[s].Name[z] >= 'a' and arr[s].Name[z] <= 'z' or arr[s].Name[z] == ' ' or arr[s].Name[z] == '+' or arr[s].Name[z] == ',' or arr[s].Name[z] == ':' and arr[s].Name[z] != '#'){
				cout << arr[s].Name[z];
			}
		}
		cout << "\t\t";
		if(arr[s].Edition == 1){
			cout << arr[s].Edition << "st";
		}
		else if(arr[s].Edition == 2){
			cout << arr[s].Edition << "nd";
		}
		else if(arr[s].Edition == 3){
			cout << arr[s].Edition << "rd";
		}
		else if(arr[s].Edition != 0){
			cout << arr[s].Edition << "th";
		}
		cout << endl;
    }
}

void saveBooks(Book arr[], int ArraySize){
	fout1.open("books.csv");
	int s, d, z;
	for(s = 0; s < x1; s++){
		for(d = 0; d < MAX_BOOK_ID - 1; d++){
			if(arr[s].Id[d] != '#'){
				fout1 << arr[s].Id[d];
			}	
		}
		fout1 << ",";
		for(z = 0; z < MAX_BOOK_NAME and arr[s].Name[z] != '\O'; z++){
			if(arr[s].Name[z] >= 'A' and arr[s].Name[z] <= 'Z' or arr[s].Name[z] >= 'a' and arr[s].Name[z] <= 'z' or arr[s].Name[z] == ' ' or arr[s].Name[z] == '+' or arr[s].Name[z] == ',' or arr[s].Name[z] == ':' and arr[s].Name[z] != '#'){
				fout1 << arr[s].Name[z];
			}
		}
		fout1 << ",";
		if(arr[s].Edition != 0){
			fout1 << arr[s].Edition << "th";
		}
		fout1 << endl;
    }
    fout1.close();
}
 
 bool AddBook(Book arr[], int ArraySize, Book newBook){
	static int s = 0;
	int d;
	if(newBook.Edition > 0 and newBook.Edition <= 15){
		for(d = 0; d < MAX_BOOK_ID; d++){
			arr[s].Id[d] = newBook.Id[d];
		}
		for(d = 0; d < MAX_BOOK_NAME and newBook.Name[d] != 0; d++){
			arr[s].Name[d] = newBook.Name[d];
		}
		arr[s].Edition = newBook.Edition;
		s++;
		x1++;
	}
	else{
		return false;
	}
	return true;
 }
 
 bool isValidBookId(char bookId[]){
	int s = 0, flag = 0;
	while(bookId[s] != 0){
		if(s >= 0 and s <= 2 and bookId[s] >= '0' and bookId[s] <= '9'){
			flag = 1;
			s++;
			continue;
		}
		else if(s == 3 or s == 6 and bookId[s] == '-'){
			flag = 1;
			s++;
			continue;
		}
		else if(s == 4 or s == 5 and bookId[s] >= 'A' and bookId[s] <= 'Z'){
			flag = 1;
			s++;
			continue;
		}
		else if(s >= 7  and s <= 11 and bookId[s] >= '0' and bookId[s] <= '9'){
			flag = 1;
			s++;
			continue;
		}
		else{
			flag = 0;
			break;
		}
	}
	if(flag == 1){
		return true;
	}
	else{
		return false;
	}
 	
 }
 
 bool isValidBookName(char bookName[]){
	int s = 0, flag = 0;
	while(bookName[s] != 0){
		if(bookName[s] >= 'a' and bookName[s] <= 'z' or bookName[s] >= 'A' and bookName[s] <= 'Z' or bookName[s] == ' ' or bookName[s] == ',' or bookName[s] == ':'){
			if(bookName[s] == ',' and bookName[s + 1] == ',' or bookName[s] == ':' and bookName[s + 1] == ':'){
				flag = 0;
				break;
			}
			flag = 1;
			s++;
			continue;
		}
		else{
			flag = 0;
			break;
		}
	}
	if(flag == 1){
		return true;
	}
	else{
		return false;
	}
 	
 }
 
 bool SaveCategories(Category arr[], int ArraySize){
    fout.open("categories.csv");
    int s , d;
	for(s = 0; s < x; s++){
		for(d = 0; d < MAX_CATEGORY_NUMBER; d++){
			if(arr[s].Id[d] != '@'){
				fout << arr[s].Id[d];
			}
		}
	    fout << ",";
	    for(d = 0; d < MAX_CATEGORY_NAME and arr[s].Name[d] != 0; d++){
	    	if(arr[s].Name[d] >= 'A' and arr[s].Name[d] <= 'Z' or arr[s].Name[d] >= 'a' and arr[s].Name[d] <= 'z' and arr[s].Name[d] != '@'){
	    		fout << arr[s].Name[d];
			}
		}
		fout << endl;
	}
	fout.close();
    
 }
 
 bool deleteCategory(Category arr[], int ArraySize, char catId[]){
	int s, d, flag;
	for(s = 0; s < x; s++){
		while(d < MAX_CATEGORY_NUMBER){
			if(catId[d] == arr[s].Id[d] and catId[d + 1] == arr[s].Id[d + 1] and catId[d + 2] == arr[s].Id[d + 2]){
				flag = 1;
				break;
			}
			else{
				flag = 0;
				break;
			}
		}
		if(flag == 1){
			break;
	    }
	}
	if(flag == 0){
		return false;
	}
	for(d = 0; d < MAX_CATEGORY_NUMBER; d++){
		arr[s].Id[d] = '@';
	}
	for(d = 0; d < MAX_CATEGORY_NAME; d++){
		arr[s].Id[d] = '@';
	}
	return true;
 }
 
 bool UpdateCategory(Category arr[], int ArraySize, char catId[], Category newData){
	int s, d, flag;
	for(s = 0; s < x; s++){
		while(d < MAX_CATEGORY_NUMBER){
			if(catId[d] == arr[s].Id[d] and catId[d + 1] == arr[s].Id[d + 1] and catId[d + 2] == arr[s].Id[d + 2]){
				flag = 1;
				break;
			}
			else{
				flag = 0;
				break;
			}
		}
		if(flag == 1){
			break;
	    }
	}
	if(flag == 0){
		return false;
	}
	for(d = 0; d < MAX_CATEGORY_NUMBER; d++){
		arr[s].Id[d] = newData.Id[d];
	}
	for(d = 0; d < MAX_CATEGORY_NAME; d++){
		arr[s].Name[d] = newData.Name[d];
	}
	return true;
 }
 
 void PrintCategories(Category arr[], int ArraySize){
	int s , d;
	cout << "\tCategory Id\tName\n";
	for(s = 0; s < x; s++){
		cout << "\t";
		for(d = 0; d < MAX_CATEGORY_NUMBER; d++){
			if(arr[s].Id[d] != '@'){
				cout << arr[s].Id[d];
			}
		}
	    cout << "\t\t";
	    for(d = 0; d < MAX_CATEGORY_NAME and arr[s].Name[d] != 0; d++){
	    	if(arr[s].Name[d] >= 'A' and arr[s].Name[d] <= 'Z' or arr[s].Name[d] >= 'a' and arr[s].Name[d] <= 'z' and arr[s].Name[d] != '@'){
	    		cout << arr[s].Name[d];
			}
		}
		cout << endl;
	}
	
 }
 
 bool AddCategory(Category arr[], int ArraySize, Category newCategory){ 
	static int s = 0;
	int d;
	
	for(d = 0; d < MAX_CATEGORY_NUMBER; d++){
		arr[s].Id[d] = newCategory.Id[d];
	}
	for(d = 0; d < MAX_CATEGORY_NAME or newCategory.Name[d] != 0; d++){
		arr[s].Name[d] = newCategory.Name[d];
	}
	s++;
	x++;
	return true;
 }
 
 bool isValidCategoryName(char catName[]){
	int s = 0, flag = 0;
	while(catName[s] != 0){
		if(catName[s] >= 'a' and catName[s] <= 'z' or catName[s] >= 'A' and catName[s] <= 'Z'){
			flag = 1;
			s++;
			continue;
		}
		else{
			flag = 0;
			break;
		}
	}
	if(flag == 1){
		return true;
	}
	else{
		return false;
	}
 	
 }
 
  bool isValidCategoryNumber(char catNo[]){ 
	int s = 0, flag = 0;
	while(catNo[s] != 0){
		if(s < 3 and catNo[s] >= '0' and catNo[s] <= '9'){
			flag = 1;
			s++;
			continue;
		}
		else{
			flag = 0;
			break;
		}
	}
	if(flag == 1){
		return true;
	}
	else{
		return false;
	}
 	
 }
 
 void TakeMenuInput(char& mainOption, char& subOption){
    bool resp, resp1, resp2;
	char a[20], b[30];
	string dt;
	BookCopy q, x2[MAX_COPY_NUMBER];
	Student p, x3[MAX_STUDENTS];
	Category o, x[MAX_CAEGORIES];
	Book m, x1[MAX_BOOKS];
	Date n;
	int s;
	if(mainOption == '1'){
		if(subOption == 'A'){
			cout << "Enter the details of the category(Id Name) : ";
			cin >> o.Id;
			cin >> o.Name;
			resp = isValidCategoryNumber(o.Id);
			resp1 = isValidCategoryName(o.Name);
			if(resp == true and resp1 == true){
				resp = AddCategory(x, MAX_CAEGORIES, o);
				if(resp == true){
					cout << "category has been added successfully\n";
				}
				else{
					cout << "category cannot be added successfully\n";
				}
			}
			else{
				cout << "You entered invalid ID or Name\n";
			}
		}
		else if(subOption == 'L'){
			PrintCategories(x, MAX_CAEGORIES);
		}
		else if(subOption == 'E'){
			cout << "Enter the Category Id to edit: ";
			cin >> a;
			resp = isValidCategoryNumber(a);
			if(resp == true){
				cout << "Enter the new details of the category: ";
				cin >> o.Id;
				cin >> o.Name;
				resp = isValidCategoryNumber(o.Id);
		    	resp1 = isValidCategoryName(o.Name);
		    	if(resp == true and resp1 == true){
		    		resp = UpdateCategory(x, MAX_CAEGORIES, a, o);
		    		if(resp == true){
		    			cout << "Category has been updated successfully\n";
					}
				}
				else{
					cout << "Category cannot be edited\n";
				}
			}
			else{
				cout << "You entered invalid Id\n";
			}
		}
		else if(subOption == 'D'){
			cout << "Enter the category Id to delete: ";
			cin >> a;
			resp = isValidCategoryNumber(a);
			if(resp == true and resp1 == true){
				resp = deleteCategory(x, MAX_CAEGORIES, a);
				if(resp == true){
					cout << "Category has been deleted successfully\n";
				}
				else{
					cout << "Category cannot be deleted\n";
				}
			}
			else{
				cout << "You entered invalid Id\n";
			}
		}
		else{
			cout << "You entered an invalid sub option\n";
		}
	}
	else if(mainOption == '2'){
		if(subOption == 'A'){
			cout << "Enter the details of the book(Id Edition Name) : ";
    		cin >> m.Id; 
			cin >> m.Edition;
			cin >> m.Name;
    		resp = isValidBookId(m.Id);
    		resp1 = isValidBookName(m.Name);
    		if(resp == true and resp1 == true and m.Edition >= 1 or m.Edition <= 15){
    			resp = AddBook(x1, MAX_BOOKS, m);
    			if(resp == true){
    				cout << "Book has been added successfully to category ";
    				for(s = 0; s < 3; s++){
    					cout << m.Id[s];
					}
					cout << endl;
				}
				else{
					cout << "Book cannot be added successfully\n";
				}
			}
			else{
				cout << "You entered invalid Id, Edition or Name\n";
			}
		}
		else if(subOption == 'E'){
			cout << "Enter the Book Id to edit: ";
			cin >> a;
			resp = isValidBookId(a);
			if(resp == true){
				cout << "Enter the new details of the book: ";
				cin >> m.Id;
				cin >> m.Edition;
				cin >> m.Name;
				resp = isValidBookId(m.Id);
    	    	resp1 = isValidBookName(m.Name);
    	    	if(resp == true and resp1 == true and m.Edition >= 1 or m.Edition <= 15){
    	    		resp = UpdateBook(x1, MAX_BOOKS, a, m);
    	    		if(resp == true){
    	    			cout << "Book has been edited successfully\n";
					}
					else{
						cout << "Book cannot be updated\n";
					}
				}
				else{
					cout << "You entered invalid Id, Edition or Name\n";
				}
			}
			else{
				cout << "You entered invalid Id\n";
			}
		}
		else if(subOption == 'D'){
			cout << "Enter the Book Id to delete: ";
			cin >> a;
			resp = isValidBookId(a);
			if(resp == true){
				resp = deleteBook(x1, MAX_BOOKS, a);
				if(resp = true){
					cout << "Book has been deleted successfully\n";
				}
				else{
					cout << "Book not found\n";
				}
			}
			else{
				cout << "You entered invalid Id\n";
			}
		}
		else if(subOption == 'L'){
			PrintBooks(x1, MAX_BOOKS);
		}
		else{
			cout << "You entered an invalid sub option\n";
		}
	}
	else if(mainOption == '3'){
		if(subOption == 'A'){
			cout << "Enter the details of the sample(Id Date-of-Purchase): ";
			cin >> q.Id;
			cin >> q.PurchaseDate.Day;
			cin.ignore(q.PurchaseDate.Day, '-');
			cin >> q.PurchaseDate.Month;
			cin.ignore(q.PurchaseDate.Month, '-');
			cin >> q.PurchaseDate.Year;
			resp = isValidCopyNumber(q.Id);
			resp2 = isValidDate(q.PurchaseDate);
			if(resp == true and resp1 == true){
				resp = addBookCopy(x2, MAX_COPY_NUMBER, q);
				if(resp == true){
					cout << "Book Copy has been added successfully\n";
				}
				else{
					cout << "Book Copy cannot be added\n";
				}
			}
			else{
				cout << "You entered invalid Copy Id or date\n";
			}
		}
		else if(subOption == 'L'){
			printBookCopy(x2, MAX_COPY_NUMBER);
		}
		else if(subOption == 'D'){
			cout << "Enter the Book Copy Id to delete: ";
			cin >> a;
			resp = isValidCopyNumber(a);
			if(resp == true){
				resp = deleteBookCopy(x2, MAX_COPY_NUMBER, a);
				if(resp == true){
					cout << "Book Copy has been deleted successfully\n";
				}
				else{
					cout << "Book Copy not found\n";
				}
			}
			else{
				cout << "You entered invalid Book Copy Id\n";
			}
		}
		else if(subOption == 'E'){
			cout << "Enter the book copy to edit: ";
			cin >> a;
			resp = isValidCopyNumber(a);
			if(resp == true){
				cout << "Enter the new details of the book copy: ";
				cin >> q.Id;
				cin >> q.PurchaseDate.Day;
				cin >> q.PurchaseDate.Month;
				cin >> q.PurchaseDate.Year;
				resp = isValidCopyNumber(q.Id);
				resp2 = isValidDate(q.PurchaseDate);
				if(resp == true and resp1 == true){
					resp = editBookCopy(x2, MAX_COPY_NUMBER, a, q);
					if(resp == true){
						cout << "Book copy has been edited successfully\n";
					}
					else{
						cout << "Book copy Id not found\n";
					}
				}
				else{
					cout << "You entered wrong book copy Id or purchase date\n";
				}
				
			}
			else{
				cout << "You entered invalid book copy Id\n";
			}
			
		}
		else{
			cout << "You entered an invalid sub option\n";
		}
	}
	else if(mainOption == '4'){
		if(subOption == 'A'){
			cout << "Enter the details of the student(regNo session AdmissionDate Name): ";
			cin >> p.RegistrationNo;
			cin >> p.Session;
			cin >> p.AdmissionDate.Day;
			cin.ignore(p.AdmissionDate.Day, '-');
			cin >>  p.AdmissionDate.Month;
			cin.ignore(p.AdmissionDate.Month, '-');
			cin >>  p.AdmissionDate.Year;
			cin >> p.name;
			resp = isValidRegistrationNo(p.RegistrationNo);
			resp1 = isValidStudentName(p.name);
			resp2 = isValidDate(p.AdmissionDate);
			if(resp == true and resp1 == true and resp2 == true){
				resp = addStudent(x3, MAX_STUDENTS, p);
				if(resp == true){
					resp = addStudent(x3, MAX_STUDENTS,p);
					cout << "Student has been added successfully\n";
				}
				else{
					cout << "Student cannot be added\n";
				}
			}
			else{
				cout << "You entered wrong Student name, registration No or date\n";
			}	
		}
		else if(subOption == 'E'){
			cout << "Enter the student registration No to edit: ";
			cin >> a;
			resp = isValidRegistrationNo(a);
			if(resp == true){
				cout << "Enter the new details of the student: ";
				cin >> p.RegistrationNo;
				cin >> p.Session;
				cin >> p.AdmissionDate.Day;
				cin.ignore(p.AdmissionDate.Day, '-');
				cin >>  p.AdmissionDate.Month;
				cin.ignore(p.AdmissionDate.Month, '-');
				cin >>  p.AdmissionDate.Year;
				cin >> p.name;
				resp = isValidRegistrationNo(p.RegistrationNo);
		    	resp1 = isValidStudentName(p.name);
		    	resp2 = isValidDate(p.AdmissionDate);
		    	if(resp == true and resp1 == true and resp2 == true){
		    		resp = editStudent(x3, MAX_STUDENTS, a, p);
		    		if(resp == true){
		    			cout << "Student has been edited successfully\n";
					}
					else{
						cout << "Student cannot be edited\n";
					}
				}
				else{
					cout << "You entered wrong Student name, registration No or date\n";
				}
			}
			else{
				cout << "You have entered invalid Registration No\n";
			}
		}
		else if(subOption == 'D'){
			cout << "Enter the registration No. to delete: ";
			cin >> a;
			resp = isValidRegistrationNo(a);
			if(resp == true){
				resp = deleteStudent(x3, MAX_STUDENTS, a);
				if(resp == true){
					cout << "Student has been deleted successfully\n";
				}
				else{
					cout << "Student not found\n";
				}	
			}
			else{
				cout << "You entered invalid registration No\n";
			}
			
		}
		else if(subOption == 'L'){
			printStudents(x3, MAX_STUDENTS);
		}
	}
	else if(mainOption == '0' and subOption == 'E'){
		SaveCategories(x, MAX_CAEGORIES);
		saveBooks(x1, MAX_BOOKS);
		saveBookCopies(x2, MAX_COPY_NUMBER);
		saveStudents(x3, MAX_STUDENTS);
	}
	else{
		cout << "You entered an invalid main option\n";
	}
	
 }
 
 void printMenu(){
	char x[2];
	cout << "** Welcome to University Library Management System **";
	while(true){
    	cout << "\nChoose the following option\n";
    	cout << "1     Category Management(A,E,L,D)\n";
    	cout << "2     Book Management(A,E,L,D)\n";
    	cout << "3     Book Copies Management(A,E,L,D)\n";
		cout << "4     student Management(A,E,L,D)\n";            
    	cout << "0     Exit program(0E)\n\n";
    	cout << "Choose the option: ";
    	cin >> x;
    	if(x[0] == '0'and x[1] == 'E'){
    		TakeMenuInput(x[0], x[1]);
    		break;
    	}
    	else{
    		TakeMenuInput(x[0], x[1]);
    	}
	}
 }
 
 main(){
	printMenu();
}
