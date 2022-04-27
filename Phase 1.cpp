#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

 const int MAX_BOOK_ID = 13, DATE_SIZE = 11, MAX_COPY_NUMBER = 17, MAX_BOOKS = 200, MAX_CAEGORIES = 30, MAX_BOOK_NAME = 60, MAX_CATEGORY_NAME = 20, MAX_CATEGORY_NUMBER = 4;
 int x = 0, x1 = 0, x2 = 0;
 
 bool SaveBookSample(char CopyId[][MAX_COPY_NUMBER], char PulishedDates[][DATE_SIZE], int ArraySize){
	ofstream fout;
	fout.open("Books Copy");
	int s, d, z;
	fout << "\tCopy Id\t\t\tPurchase Date\n";
	for(s = 0; s < x2; s++){
		fout << "\t";
		for(d = 0; d < MAX_COPY_NUMBER - 1; d++){
			if(CopyId[s][d] != '@'){
				fout << CopyId[s][d];
			}
		}
		fout << "\t";
		for(z = 0; z < DATE_SIZE; z++){
			if(PulishedDates[s][z] != '@'){
				fout << PulishedDates[s][z];
			}
		}
    	fout << endl;
    }
    fout.close();
 }
 
 bool SaveBooks(char bookId[][MAX_BOOK_ID], char CategoryName[][MAX_BOOK_NAME], int Editions[], int ArraySize){
	ofstream fout;
	fout.open("Books.txt");
	int s, d, z;
	fout << "\tBook Id\t\t Name\n";
	for(s = 0; s < x1; s++){
		fout << "\t";
		for(d = 0; d < MAX_BOOK_ID - 1; d++){
			if(CategoryName[s][z] != '#'){
				fout << bookId[s][d];
			}	
		}
		fout << "\t";
		for(z = 0; z < MAX_BOOK_NAME and CategoryName[s][z] != '\O'; z++){
			if(CategoryName[s][z] >= 'A' and CategoryName[s][z] <= 'Z' or CategoryName[s][z] >= 'a' and CategoryName[s][z] <= 'z' or CategoryName[s][z] == ' ' or CategoryName[s][z] == '+' or CategoryName[s][z] == ',' or CategoryName[s][z] == ':' and CategoryName[s][z] != '#'){
				fout << CategoryName[s][z];
			}
		}
		
		fout << endl;
    }
	fout.close();
 }
 
 bool SaveCategories(char CatergoryNo[][MAX_CATEGORY_NUMBER], char CatergoryName[][MAX_CATEGORY_NAME], int ArraySize){
	ofstream fout;
	fout.open("Categories.txt");
	int s, d, z;
	fout << "\tCategory Id\t Name\n";
	for(s = 0; s < x; s++){
		fout << "\t";
		for(d = 0; d < MAX_CATEGORY_NUMBER - 1; d++){
			if(CatergoryNo[s][d] != '@'){
				fout << CatergoryNo[s][d];
			}
		}
		fout << "\t\t";
		for(z = 0; z < MAX_CATEGORY_NAME; z++){
			if(CatergoryName[s][z] >= 'A' and CatergoryName[s][z] <= 'Z' or CatergoryName[s][z] >= 'a' and CatergoryName[s][z] <= 'z' and CatergoryName[s][z] != '@'){
				fout << CatergoryName[s][z];
			}
		}
		fout << endl;
	}
	fout.close();
 }
 
 bool DeleteBookSample(char copyId[][MAX_COPY_NUMBER], char PulishedDates[][DATE_SIZE], int ArraySize, char CopyId[]){
	int s, d, flag;
	for(s = 0; s < x2; s++){
		while(d < MAX_COPY_NUMBER){
			if(CopyId[d] == copyId[s][d] and CopyId[d + 1] == copyId[s][d + 1] and CopyId[d + 2] == copyId[s][d + 2] and CopyId[d + 3] == copyId[s][d + 3] and CopyId[d + 4] == copyId[s][d + 4] and CopyId[d + 5] == copyId[s][d + 5] and CopyId[d + 6] == copyId[s][d + 6] and CopyId[d + 7] == copyId[s][d + 7] and CopyId[d + 8] == copyId[s][d + 8] and CopyId[d + 9] == copyId[s][d + 9] and CopyId[d + 10] == copyId[s][d + 10] and CopyId[d + 11] == copyId[s][d + 11] and CopyId[d + 12] == copyId[s][d + 12] and CopyId[d + 13] == copyId[s][d + 13] and CopyId[d + 14] == copyId[s][d + 14] and CopyId[d + 15] == copyId[s][d + 15]){
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
		copyId[s][d] = '@';
	}
	for(d = 0; d < DATE_SIZE; d++){
		PulishedDates[s][d] = '@';
	}
	
	return true;
 }
 
 bool UpdateBookSample(char CopyId[][MAX_COPY_NUMBER], char PulishedDates[][DATE_SIZE], int ArraySize, char prevCopyId[], char newCopyId[], char newPublishDate[]){
	int s, d, flag;
	for(s = 0; s < x2; s++){
		while(d < MAX_COPY_NUMBER){
			if(prevCopyId[d] == CopyId[s][d] and prevCopyId[d + 1] == CopyId[s][d + 1] and prevCopyId[d + 2] == CopyId[s][d + 2] and prevCopyId[d + 3] == CopyId[s][d + 3] and prevCopyId[d + 4] == CopyId[s][d + 4] and prevCopyId[d + 5] == CopyId[s][d + 5] and prevCopyId[d + 6] == CopyId[s][d + 6] and prevCopyId[d + 7] == CopyId[s][d + 7] and prevCopyId[d + 8] == CopyId[s][d + 8] and prevCopyId[d + 9] == CopyId[s][d + 9] and prevCopyId[d + 10] == CopyId[s][d + 10] and prevCopyId[d + 11] == CopyId[s][d + 11] and prevCopyId[d + 12] == CopyId[s][d + 12] and prevCopyId[d + 13] == CopyId[s][d + 13] and prevCopyId[d + 14] == CopyId[s][d + 14] and prevCopyId[d + 15] == CopyId[s][d + 15]){
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
		CopyId[s][d] = newCopyId[d];
	}
	for(d = 0; d < DATE_SIZE; d++){
		PulishedDates[s][d] = newPublishDate[d];
	}
	
	return true;
 }
 
 bool DeleteBook(char bookId[][MAX_BOOK_ID], char CategoryName[][MAX_BOOK_NAME], int Editions[], int ArraySize, char BookId[]){
 	int s, d, flag;
	for(s = 0; s < x1; s++){
		while(d < MAX_BOOK_ID){
			if(BookId[d] == bookId[s][d] and BookId[d + 1] == bookId[s][d + 1] and BookId[d + 2] == bookId[s][d + 2] and BookId[d + 3] == bookId[s][d + 3] and BookId[d + 4] == bookId[s][d + 4] and BookId[d + 5] == bookId[s][d + 5] and BookId[d + 6] == bookId[s][d + 6] and BookId[d + 7] == bookId[s][d + 7] and BookId[d + 8] == bookId[s][d + 8] and BookId[d + 9] == bookId[s][d + 9] and BookId[d + 10] == bookId[s][d + 10] and BookId[d + 11] == bookId[s][d + 11]){
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
		bookId[s][d] = '#';
	}
	for(d = 0; d < MAX_BOOK_NAME; d++){
		CategoryName[s][d] = '#';
	}
	Editions[s] = 0;
	
	return true;
 }
 
 bool UpdateBook(char bookId[][MAX_BOOK_ID], char CategoryName[][MAX_BOOK_NAME], int Editions[], int ArraySize, char prevBookId[], char newBookId[], char newBookName[], int edition){
	int s, d, flag;
	for(s = 0; s < x1; s++){
		while(d < MAX_BOOK_ID){
			if(prevBookId[d] == bookId[s][d] and prevBookId[d + 1] == bookId[s][d + 1] and prevBookId[d + 2] == bookId[s][d + 2] and prevBookId[d + 3] == bookId[s][d + 3] and prevBookId[d + 4] == bookId[s][d + 4] and prevBookId[d + 5] == bookId[s][d + 5] and prevBookId[d + 6] == bookId[s][d + 6] and prevBookId[d + 7] == bookId[s][d + 7] and prevBookId[d + 8] == bookId[s][d + 8] and prevBookId[d + 9] == bookId[s][d + 9] and prevBookId[d + 10] == bookId[s][d + 10] and prevBookId[d + 11] == bookId[s][d + 11]){
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
		bookId[s][d] = newBookId[d];
	}
	for(d = 0; d < MAX_BOOK_NAME; d++){
		CategoryName[s][d] = newBookName[d];
	}
	Editions[s] = edition;
	
	return true;
 }
 
 // this function adds book copy ID & the dates in there respective 2D arrays
 bool AddBookSample(char CopyId[][MAX_COPY_NUMBER], char PulishedDates[][DATE_SIZE], int ArraySize, char newCopyId[], char newPublishDate[]){
	static int s = 0;
	int d;
	for(d = 0; d < MAX_COPY_NUMBER; d++){
		CopyId[s][d] = newCopyId[d];
	}
	for(d = 0; d < DATE_SIZE; d++){
		PulishedDates[s][d] = newPublishDate[d];
	}
	s++;
	x2++;
 }
 
 // this function prints the list on the screen of the number of copys and there purchase date
 void PrintBookSample(char CopyId[][MAX_COPY_NUMBER], char PulishedDates[][DATE_SIZE], int ArraySize){
	int s, d, z;
	cout << "\tCopy Id\t\t\tPurchase Date\n";
	for(s = 0; s < x2; s++){
		cout << "\t";
		for(d = 0; d < MAX_COPY_NUMBER - 1; d++){
			if(CopyId[s][d] != '@'){
				cout << CopyId[s][d];
			}
		}
		cout << "\t";
		for(z = 0; z < DATE_SIZE; z++){
			if(PulishedDates[s][z] != '@'){
				cout << PulishedDates[s][z];
			}
		}
		cout << endl;
    }
}
 
// this function valid checks the book copy ID
bool isValidBookCopy(char bookCopy[]){
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
 
 // this function valid checks the date input
 bool isValidDate(char date[]){
	int s = 0, flag = 0;
	while(date[s] != 0){
		if(s == 0 and date[s] == '0' and date[s + 1] >= '1' and date[s + 1] <= '9'){
			flag = 1;
			s = s + 2;
		}
		else if(s == 0 and date[s] == '1' or date[s] == '2' and date[s + 1] >= '0' and date[s + 1] <= '9'){
			flag = 1;
			s = s + 2;
		}
		else if(s == 0 and date[s] == '3' and date[s + 1] == '0' or date[s + 1] == '1'){
			flag = 1;
			s = s + 2;
		}
		else if(s == 2 or s == 5 and date[s] == '-'){
			flag = 1;
			s++;
		}
		else if(s == 3 and date[s] == '0' and date[s + 1] >= '1' and date[s + 1] <= '9'){
			flag = 1;
			s = s + 2;
		}
		else if(s == 3 and date[s] == '1' and date[s + 1] == '0' or date[s + 1] <= '1' or date[s + 1] == '2'){
			flag = 1;
			s = s + 2;
		}
		else if(s >= 6 and s <= 8 and date[s] >= '0' and date[s] <= '9'){
			flag = 1;
			s++;
		}
		else if(s == 9 and date[s] >= '1' and date[s] <= '9'){
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
 
 //This functions checks for valid edition and then store data in its respective 2D array
 bool AddBook(char bookId[][MAX_BOOK_ID], char CategoryName[][MAX_BOOK_NAME], int Editions[], int ArraySize, char newBookId[], char newBookName[], int edition){
	static int s = 0;
	int d;
	if(edition > 0 and edition <= 15){
		for(d = 0; d < MAX_BOOK_ID; d++){
			bookId[s][d] = newBookId[d];
		}
		for(d = 0; d < MAX_BOOK_NAME; d++){
			CategoryName[s][d] = newBookName[d];
		}
		Editions[s] = edition;
		s++;
		x1++;
	}
	else{
		return false;
	}
	return true;
 }
 
 //this function prints the list on the screen of the book ID, name and edition that have been added 
 void PrintBooks(char bookId[][MAX_BOOK_ID], char CategoryName[][MAX_BOOK_NAME], int Editions[], int ArraySize){
	int s, d, z;
	cout << "\tBook Id\t\t Name\t\tEdition\n";
	for(s = 0; s < x1; s++){
		cout << "\t";
		for(d = 0; d < MAX_BOOK_ID - 1; d++){
			if(CategoryName[s][z] != '#'){
				cout << bookId[s][d];
			}	
		}
		cout << "\t";
		for(z = 0; z < MAX_BOOK_NAME and CategoryName[s][z] != '\O'; z++){
			if(CategoryName[s][z] >= 'A' and CategoryName[s][z] <= 'Z' or CategoryName[s][z] >= 'a' and CategoryName[s][z] <= 'z' or CategoryName[s][z] == ' ' or CategoryName[s][z] == '+' or CategoryName[s][z] == ',' or CategoryName[s][z] == ':' and CategoryName[s][z] != '#'){
				cout << CategoryName[s][z];
			}
		}
		cout << "\t\t";
		if(Editions[s] == 1){
			cout << Editions[s] << "st";
		}
		else if(Editions[s] == 2){
			cout << Editions[s] << "nd";
		}
		else if(Editions[s] == 3){
			cout << Editions[s] << "rd";
		}
		else if(Editions[s] != 0){
			cout << Editions[s] << "th";
		}
		cout << endl;
    }
}
 
 
 //This function checks the book ID of 12 characters
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
 
 //This function checks the book name os that it only has alphabats more ove ':', ',' & ' ' only once
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
 
 // this function add the category ID & name that the user input into the two respective 2D arrays
 bool AddCategory(char CatergoryNo[][MAX_CATEGORY_NUMBER], char CatergoryName[][MAX_CATEGORY_NAME], int ArraySize, char newCategoryId[], char newCategoryName[]){ 
	static int s1 = 0;
	int d;
	for(d = 0; d < MAX_CATEGORY_NUMBER; d++){
		CatergoryNo[s1][d] = newCategoryId[d];
	}
	for(d = 0; d < MAX_CATEGORY_NAME or newCategoryName[d] != 0; d++){
		CatergoryName[s1][d] = newCategoryName[d];
	}
	s1++;
	x++;
	return true;
 }
 
 // this function updates the category ID that the user input into the two respective 2D arrays
 bool UpdateCategory(char CatergoryNo[][MAX_CATEGORY_NUMBER], char CatergoryName[][MAX_CATEGORY_NAME], int ArraySize, char prevCategoryId[], char newCategoryId[], char newCategoryName[]){
	int s, d, flag;
	for(s = 0; s < x; s++){
		while(d < MAX_CATEGORY_NUMBER){
			if(prevCategoryId[d] == CatergoryNo[s][d] and prevCategoryId[d + 1] == CatergoryNo[s][d + 1] and prevCategoryId[d + 2] == CatergoryNo[s][d + 2]){
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
		CatergoryNo[s][d] = newCategoryId[d];
	}
	for(d = 0; d < MAX_CATEGORY_NAME; d++){
		CatergoryName[s][d] = newCategoryName[d];
	}
	return true;
 }
 
 // this function deletes the category ID that the user input from the 2D array and its respective category name too
 bool DeleteCategory(char CatergoryNo[][MAX_CATEGORY_NUMBER], char CatergoryName[][MAX_CATEGORY_NAME], int ArraySize, char newCategoryId[]){
	int s, d, flag;
	for(s = 0; s < x; s++){
		while(d < MAX_CATEGORY_NUMBER){
			if(newCategoryId[d] == CatergoryNo[s][d] and newCategoryId[d + 1] == CatergoryNo[s][d + 1] and newCategoryId[d + 2] == CatergoryNo[s][d + 2]){
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
		CatergoryNo[s][d] = '@';
	}
	for(d = 0; d < MAX_CATEGORY_NAME; d++){
		CatergoryName[s][d] = '@';
	}
	return true;
 }
 
 //this function prints the list on the screen of the category ID and name that have been added 
 void PrintCategories(char CatergoryNo[][MAX_CATEGORY_NUMBER], char CatergoryName[][MAX_CATEGORY_NAME], int ArraySize){
	int s, d, z;
	cout << "\tCategory Id\t Name\n";
	for(s = 0; s < x; s++){
		cout << "\t";
		for(d = 0; d < MAX_CATEGORY_NUMBER - 1; d++){
			if(CatergoryNo[s][d] != '@'){
				cout << CatergoryNo[s][d];
			}
		}
		cout << "\t\t";
		for(z = 0; z < MAX_CATEGORY_NAME; z++){
			if(CatergoryName[s][z] >= 'A' and CatergoryName[s][z] <= 'Z' or CatergoryName[s][z] >= 'a' and CatergoryName[s][z] <= 'z' and CatergoryName[s][z] != '@'){
				cout << CatergoryName[s][z];
			}
		}
		cout << endl;
	}
	
 }
 
 //this functions checks the category name that is stricky consisting of alphabets to be valid
 bool isValidCategoryName(char bookCategory[]){
	int s = 0, flag = 0;
	while(bookCategory[s] != 0){
		if(bookCategory[s] >= 'a' and bookCategory[s] <= 'z' or bookCategory[s] >= 'A' and bookCategory[s] <= 'Z'){
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
 
 //this function checks the 3 digit category code to be valid
 bool isValidCategoryNumber(char bookCategory[]){ 
	int s = 0, flag = 0;
	while(bookCategory[s] != 0){
		if(s < 3 and bookCategory[s] >= '0' and bookCategory[s] <= '9'){
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
 
 // this is the only function that thats the inputs
 void TakeMenuInput(char& mainOption, char& subOption){
	int ed[20], edi;
	bool resp, resp1;
	char x[MAX_CAEGORIES][MAX_CATEGORY_NUMBER], y[MAX_CAEGORIES][MAX_CATEGORY_NAME], x1[MAX_BOOKS][MAX_BOOK_ID], y1[MAX_BOOKS][MAX_BOOK_NAME], x2[MAX_COPY_NUMBER][MAX_COPY_NUMBER], y2[MAX_COPY_NUMBER][DATE_SIZE];
	int s;
	
	char id[20], name[30], newid[20];
    if(mainOption == '1'){
    	if(subOption == 'A'){
    		cout << "Enter the details of the category(Id Name) : ";
    		cin >> id;
			cin >> name;
    		
    		resp = isValidCategoryNumber(id);
    		resp1 = isValidCategoryName(name);
    			if(resp == true and resp1 == true){
    				resp = AddCategory(x, y, MAX_CAEGORIES, id, name);
    				if(resp == true){
    					cout << "category has been added successfully\n"; 
					}
					else{
				    	cout << "category cannot be added successfully\n";
					}
		    	}
	    		else{
	    			cout << "You entered an invalid category Id or Name\n";
	 			
	     		}
    		
		}
		else if(subOption == 'E'){
			cout << "Enter the category Id to edit: ";
			cin >> id;
			resp = isValidCategoryNumber(id);
		    	if(resp == true){
			    	cout << "Enter the new details of the category: ";
			    	cin >> newid >> name;
			    	resp = isValidCategoryNumber(newid);
			    	resp1 = isValidCategoryName(name);
			    	if(resp == true and resp1 == true){
			    		resp = UpdateCategory(x, y, MAX_CAEGORIES, id, newid, name);
			        	if(resp == true){
			        		cout << "Category has been editied successfully\n";
			        	}
			        	else{
			        		cout << "Category cannot be edited\n";
				    	}
					}
					else{
						cout << "You entered invalid Id or name\n";
					}
			    	
		    	}
	    		else{
	    			cout << "You entered an invalid category Id or Name\n";
	 			
	     		}
		}
		else if(subOption == 'L'){
			PrintCategories(x, y, MAX_CAEGORIES);
		}
		else if(subOption == 'D'){
			cout << "Enter the category Id to delete: ";
			cin >> id;
			resp = isValidCategoryNumber(id);
		    	if(resp == true){
		    		resp = DeleteCategory(x, y, MAX_CAEGORIES, id);
		    		if(resp == true){
		    			cout << "Category has been deleted successfully\n";
					}
					else{
						cout << "Category cannot be deleted successfully\n";
					}
		    	}
	    		else{
	    			cout << "You entered an invalid category Id or Name\n";
	 			
	        	}
		}
		else{
			cout << "You entered invalid sub option\n";
			
		
		}
	}
	else if(mainOption == '2'){
    	if(subOption == 'A'){
    		for(int e = 0; e < 30; e++){
    			name[e] = '\O';
			}
    		cout << "Enter the details of the book(Id Edition Name) : ";
    		cin >> id; 
			cin >> edi;
			cin >> name;
    		resp = isValidBookId(id);
    		resp1 = isValidBookName(name);
    		if(resp == true and resp1 == true){
    			resp = AddBook(x1, y1, ed, MAX_BOOKS, id, name, edi);
    			if(resp == true){
    				cout << "The book has been added successfully in category ";
    				for(s = 0; s < 3; s++){
    					cout << id[s];
					}
					cout << endl;
				}
				else{
					cout << "The book cannot be added\n";
				}
			}
			else{
				cout << "You entered invalid Book Id or Book name\n";
			}
		}
		else if(subOption == 'E'){
			cout << "Enter the Book Id to edit: ";
			cin >> id;
			resp = isValidBookId(id);
			if(resp == true){
				cout << "Enter the new details of the Book : ";
				cin >> newid;
				cin >> edi;
				cin >> name;
				resp = isValidBookId(newid);
				resp1 = isValidBookName(name);
				if(resp == true and resp1 == true and edi > 0 and edi <= 15){
					resp = UpdateBook(x1, y1, ed, MAX_BOOKS, id, newid, name, edi);
					if(resp == true){
						cout << "Book has been added edited successfully\n";
					}
					else{
						cout << "Id cannot be found\n";
					}
				}
				else{
					cout << "You entered invalid Id, Edition or name\n";
				}
				
			}
			else{
				cout << "You entered invalid Book Id or Book name\n";
			}
		}
		else if(subOption == 'L'){
			PrintBooks(x1, y1, ed, MAX_BOOKS);
		}
		else if(subOption == 'D'){
			cout << "Enter the Book Id to delete: ";
			cin >> id;
			resp = isValidBookId(id);
			if(resp == true){
				resp = DeleteBook(x1, y1, ed, MAX_BOOKS, id);
				if(resp == true){
					cout << "Book has been deleted successfully\n";
				}
				else{
					cout << "Book Id was not found\n";
				}
			}
			else{
				cout << "You have entered invalid book Id\n";
			}
		}
		else{
			cout << "You entered invalid sub option\n";
		}
	}
	else if(mainOption == '3'){
    	if(subOption == 'A'){
    		cout << "Enter the details of the simple(Id Date-of-Purchase): ";
    		cin >> id >> name;
    		resp = isValidBookCopy(id);
    		resp1 = isValidDate(name);
    		if(resp == true and resp1 == true){
    			resp = AddBookSample(x2, y2, MAX_COPY_NUMBER, id, name);
    			if(resp == true){
    				cout << "Book copy has been edited successfully\n";
				}
			}
		}
		else if(subOption == 'E'){
			cout << "Enter the Book copy to edit: ";
			cin >> id;
			resp = isValidBookCopy(id);
			if(resp == true){
				cout << "Enter the new details of the Book copy: ";
				cin >> newid;
				cin >> name;
				resp = isValidBookCopy(id);
    	    	resp1 = isValidDate(name);
    	    	if(resp == true and resp1 == true){
    	    		resp = UpdateBookSample(x2, y2, MAX_COPY_NUMBER, id, newid, name);
			    	if(resp == true){
			    		cout << "Book copy has been edited successfully\n";
			    	}
			    	else{
			    		cout << "Book copy not found\n";
			    	}
				}
				else{
					cout << "You entered invalid Book copy\n";
				}
			}
			else{
				cout << "You entered invalid Book copy\n";
			}
		}
		else if(subOption == 'L'){
			PrintBookSample(x2, y2, MAX_COPY_NUMBER);
		}
		else if(subOption == 'D'){
			cout << "Enter the book copy to edit: ";
			cin >> id;
			resp = isValidBookCopy(id);
			if(resp == true){
				resp = DeleteBookSample(x2, y2, MAX_COPY_NUMBER, id);
				if(resp == true){
					cout << "Book copy has been deleted successfully\n";
				}
				else{
					cout << "Book copy not found\n";
				}
			}
			else{
				cout << "You entered invalid book copy\n";
			}
		}
		else{
			cout << "You entered invalid sub option\n";
		}
	}
	else if(mainOption == '0' and subOption == 'E'){
		SaveCategories(x, y, MAX_CAEGORIES);
		SaveBooks(x1, y1, ed, MAX_BOOKS);
		SaveBookSample(x2, y2, MAX_COPY_NUMBER);
	}
	else{
		cout << "You entered invalid main option\n";
	}
}

// this function prints the menu
void printMenu(){
	char x[2];
	cout << "** Welcome to University Library Management System **";
	while(true){
    	cout << "\nChoose the following option\n";
    	cout << "1     Category Management(A,E,L,D)\n";
    	cout << "2     Book Management(A,E,L,D)\n";
    	cout << "3     Book Copies Management(A,E,L,D)\n";             
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
