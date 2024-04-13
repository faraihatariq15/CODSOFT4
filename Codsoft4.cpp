#include<iostream>
#include<fstream>
using namespace std;

class temp{
	string id, name, author, search;
	fstream file;
	public:
	void addbook();
	void showall();
	void extractbook();
};

int main(){
	temp obj; 
	char choice;
	cout<<"----------------------------"<<endl;
	cout<<"1- Show all books"<<endl;
	cout<<"2- Extract books"<<endl;
	cout<<"3- Add books"<<endl;
	cout<<"4- Terminate"<<endl;
	cout<<"Enter your choice: "<<endl;
	cin>>choice;
	cout<<"----------------------------"<<endl;
	switch(choice){
		case '1':
			cin.ignore();
			obj.showall();
		    break;
		case '2':
			cin.ignore();
			obj.extractbook(); 
		    break;
    	case '3':
    		cin.ignore();
			obj.addbook();
		    break;
	    case '4':
	    	return 0;
	     	break;
	    default:
	    	cout<<"Oops! Invalid choice"<<endl;
	
	}
	return 0;
}

void temp :: addbook(){
	cout<<"Enter Book ID :: ";
	getline(cin,id);
	cout<<"Enter Book Name :: ";
	getline(cin,name);
	cout<<"Enter Book Author :: ";
	getline(cin,author);
	file.open("bookData.txt",ios::out | ios::app);
	file<<id<<"*"<<name<<"*"<<author<<endl;
	file.close();
}

void temp :: showall(){
	file.open("bookData.txt",ios::in);
	cout<<"\n\n";
	cout<<"\t\t Book ID \t\t\t Book Name \t\t\t Author's Name"<<endl;
	while(getline(file,id,'*') && getline(file,name,'*') && getline(file,author,'\n')){
		cout<<"\t\t "<<id<< "\t\t\t" <<name<< " \t\t\t "<<author<<endl;
	}
	file.close();
}

void temp :: extractbook(){
	showall();
	cout<<"Enter bookID : "<<endl;
	cin.ignore(); 
	getline(cin, search);
	file.open("bookData.txt",ios::in);
	cout<<"\n\n";
	cout<<"\t\t Book ID \t\t\t Book Name \t\t\t Author's Name"<<endl;
	bool found = false;
	while(getline(file,id,'*') && getline(file,name,'*') && getline(file,author,'\n')){
		if(search == id){
			cout<<" \t\t "<<id<< "\t\t "<<name<<" \t\t\t "<<author<<endl;
			found = true;
		}
	}
	file.close();
	if(!found)
		cout << "Book not found!" << endl;
}

