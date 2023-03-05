/* 
Library Management System: Create a program that manages a library of books. The program should 
allow users to add new books, search for books by title or author, and check out and return books.

to add : 
Files
user class
full library 
*/

#include<fstream>
#include<iostream>
#include<string.h>
#include<stdbool.h>
#include<sstream>
#include<vector>

   using namespace std;

   class Books
   {
      string title,Author;

      public:

    Books(string title="",string Author="")
    {
       this->title = title;
       this->Author = Author;
    }
      
    
   void Display()
   {
    cout << "Title : " << title <<endl;
    cout << "Author : "<< Author << endl;
   }

   //geter 
   string getTitle(){return title;}
  string getAuthor(){return Author;}

   };

   void Menu()
   {
    cout << "1-ADD BOOK" << endl;
    cout << "2-Search For A book " << endl;
    cout << "3-Display Books" << endl;
    cout << "4-Delete a book" << endl;
     cout << "5-Exit" << endl;
     cout  << "6-Save the Current Books " <<endl;
   }
  
   void Add_Book(vector <Books> &Book)
   { 
    string title,book;
        cout << "ADD A BOOK "<<endl;
           cout << "TITLE : " ; cin>>title;
           cout << "AUTHOR : "; cin>>book;

        Book.emplace_back(title,book);
      

   }

   int Search_Book(vector<Books> &Book, string Title) {
    int found = -1;

    for (int i = 0; i < Book.size(); i++) {
        if (Title == Book[i].getTitle()) {
            found = i;
            break;
        }
    }

    return found;
}

  
 void Delete_Book(vector<Books> &Book)
 {
  int found = -1;
    string title; 
      cout << " Give the title for the book you want to delete : "; cin >> title;
   
     for (int i = 0 ; i<Book.size() ; i++)
     {
       if (title == Book[i].getTitle())
       {
         cout << " The Follwing Book Will be Deleted \n";
           Book[i].Display();
           found = i;
           break;
       }
     }
       if (found != -1)
       {
        Book.erase(Book.begin()+found);
       }
       else 
       {
         cout << "No Book with the title ' "<< title <<"' found "<<endl;
       }
 }
  void Load_Books(vector<Books>& Book) {
    ifstream infile("Books.txt");

    if (!infile.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    string line;
    while (getline(infile, line)) {
        stringstream ss(line);
        string title, author;
        getline(ss, title, ',');
        getline(ss, author);

        Book.emplace_back(title, author);
    }

    infile.close();
}

   void SaveBooks(vector<Books> &Book) {
    ofstream outfile("books.txt",ios::app);

    if (outfile.is_open()) {
        for (int i = 0; i < Book.size(); i++) {
            outfile << Book[i].getTitle() << "," << Book[i].getAuthor() << endl;
        }

        outfile.close();
        cout << "Books saved to file: " <<  "Books.txt"<< endl;
    } else {
        cout << "Unable to open file for writing: " << "Books.txt" << endl;
    }
}

int main()
{ 
vector <Books> Book;
Load_Books(Book);
    while (1)
    {
       string name,input;
int option;

Menu(); 

while (true) {
    cout << "Enter an option (1-5): ";
    getline(cin, input);
    stringstream ss(input);

    if (ss >> option && option >= 1 && option <= 6) {
        break;
    }

    cout << "Invalid option. Please try again." << endl;
}

  system("clear");
        switch (option)
        {
          
        case 1:
            Add_Book(Book);
        break;

    case 2: 
  
    cout <<"Give a title to search :  "; cin>> name;
            if( Search_Book(Book,name) != -1 )cout << " ** Book Exist **  "<<endl;
            else cout << "** Book Not found **"<< endl; 
    break;
        case 3:
        cout << "Size : " << Book.size() <<endl;
        for (int i = 0 ; i < Book.size();i++)
        {
        Book[i].Display();         
        }
        break;
        case 4: 
          Delete_Book(Book);
        break;
    case 5 : 
exit(0);
    break;

    case 6:
    SaveBooks(Book); 
    break;


        }

    }
    

}