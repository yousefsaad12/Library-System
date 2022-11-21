#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Book{

private:
    int id {};
    string name {};
    int quantity {};
    int borrow {};
public:

    Book(): id{0} , name{"0"} , quantity{0} , borrow {0} {}

    Book(int i , string nm , int quan ): id(i),name(nm),quantity(quan){}

    void Set_Id(int & i){

       this->id = i;
    }

    void Set_Name(string & nm){

       this->name = nm;
    }

    void Set_Quantity(int & q){

       this->quantity = q;
    }

    int const Get_Id() const {

        return id;
    }

    string const Get_Name() const {

        return name;
    }

    int const Get_Quantity() const {

        return quantity;
    }

    int const Get_Borrow() const {

        return borrow;
    }

    void increase_borrow(){

        borrow++;
    }

    void decrease_borrow(){

        borrow--;
    }

    void decrese_Quantity(){

        quantity--;
    }

    void incerese_Quantity(){

        quantity++;
    }

    void Add_Book() {

        int temp_id , temp_quan;
        string temp_name;

        cout << "Enter Book info: id & name & total quantity: ";
        cin >> temp_id >> temp_name >> temp_quan;

        Set_Id(temp_id);
        Set_Name(temp_name);
        Set_Quantity(temp_quan);

        cout << endl;

    }


};

/////////////////////////////////////////////////////

bool Sort_by_id(Book  a , Book  b){

        if(a.Get_Id() < b.Get_Id())
            return true;

        return false;
    }

bool Sort_by_name(Book & a ,  Book & b){

        if(a.Get_Name() < b.Get_Name())
            return true;

        return false;
    }

////////////////////////////////////////////////////

class User{

private:
    int id {};
    string name {};
    int borrow {};
    vector<Book>My_books;
public:

    User(): id(0) , name("0"){}

    User(int i , string nm): id(i) , name(nm){}

    void Set_Id(int & i){

        this->id = i;
    }

    void Set_Name(string & nm){

        this->name = nm;
    }

     int Get_Id() const {

        return id;
    }

    string Get_Name() const {

        return name;
    }

    int Get_borrow() const {

        return borrow;
    }

    void increase_borrow(){

        borrow++;
    }

    void decrease_borrow(){

        borrow--;
    }

    void Set_book(Book const e){

        My_books.push_back(e);
    }

    void Add_User(){

        int temp_id;
        string temp_name;

        cout << "Enter your name & national id: ";
        cin >> temp_name >> temp_id;

        Set_Id(temp_id);
        Set_Name(temp_name);

    }

    void print_users()
    {
        cout << "Name: " << Get_Name() ;
        cout << " | Id: " << Get_Id();
        cout << " | Borrowed Books Ids: ";

        for(int i = 0; i < Return_numberbook(); i++)
            cout << My_books[i].Get_Id() << " ";

        cout << " | Books that You borrow: " << Get_borrow() << endl;
    }

    int const Return_numberbook() const{

        return (int) My_books.size();
    }


    string const Return_book_name(int index) const {

        return My_books[index].Get_Name();
    }


    void Return_book(int index){

        My_books.erase(My_books.begin() + index);
    }

};


class Library_System{

private:

    vector<User>users;
    vector<Book>books;

public:

    void Menu(){


        system("cls");
        system("Color 3");

        cout << "\n\t\t\t\t\t Library Menu. \n\n" << endl;
        cout << "\t\t\t\t\t 1) Add Book. " << endl;
        cout << "\t\t\t\t\t 2) Search For Book By Prefix. " << endl;
        cout << "\t\t\t\t\t 3) Print Who Borrowed Book By Name. " << endl;
        cout << "\t\t\t\t\t 4) Print Library By Id. " << endl;
        cout << "\t\t\t\t\t 5) Print Library By Name. " << endl;
        cout << "\t\t\t\t\t 6) Add User. " << endl;
        cout << "\t\t\t\t\t 7) User Borrow Book. " << endl;
        cout << "\t\t\t\t\t 8) User Return Book. " << endl;
        cout << "\t\t\t\t\t 9) Print Users. " << endl;
        cout << "\t\t\t\t\t 10) Exit. \n" << endl;


    }

    void Run(){


        Menu();

        int choice;

            while(true)
            {

                system("Color 3");
               cout << "\t\t\t\t\t Enter Your choice[1 - 10]: ";
               cin >> choice;

               if(choice == 1)
                  Add_book();

               else if(choice == 2)
                 Search_For_Books();

               else if(choice == 3)
                Print_who_borrow();

               else if(choice == 4)
                 Print_by_id();

               else if(choice == 5)
                 Print_by_name();

               else if(choice == 6)
                 Add_User();

               else if(choice == 7)
                User_borrow_book();

               else if(choice == 8)
                User_Return_book();

               else if(choice == 9)
                Print_users();

               else
                 break;
            }
    }


    void Add_User(){

        User u;
        u.Add_User();

        users.push_back(u);

    }

    void Add_book(){

        Book B;
        B.Add_Book();

        books.push_back(B);

    }

    void Search_For_Books(){

        string str;

        cout << "Enter book name prefix: ";
        cin >> str;



        for(int i = 0; i < books.size(); i++)
        {
            string temp = books[i].Get_Name();
            bool flag = true;

            for(int j = 0; j < str.size(); j++)
                if(str[j] != temp[j])
                    flag = false;

            if(flag)
            cout << books[i].Get_Name() << endl;
        }

    }


    void Print_by_id(){

         sort(books.begin() ,books.end() , Sort_by_id);

        for(int i = 0; i < books.size(); i++)
        {
            cout << "Id: " << books[i].Get_Id() ;
            cout << " | Name: " << books[i].Get_Name();
            cout << " | Total Quantity: " << books[i].Get_Quantity();
            cout << " | Total Borrowed " << books[i].Get_Borrow() << endl;

        }


         cout << endl ;
    }


    void Print_by_name(){

         sort(books.begin() ,books.end() , Sort_by_name);

        for(int i = 0; i < books.size(); i++)
        {
            cout << "Id: " << books[i].Get_Id() ;
            cout << " Name: " << books[i].Get_Name();
            cout << " Total Quantity: " << books[i].Get_Quantity();
            cout << " Total Borrowed " << books[i].Get_Borrow() << endl;

        }


         cout << endl ;
    }

    void User_borrow_book(){


        cout << "\nEnter username and book name: ";

        string str1 , str2;

        cin >> str1 >> str2;

        int counter1 = 0;
        int counter2 = 0;

        for(int i = 0; i < books.size(); i++)
        {
            if(str2 == books[i].Get_Name())
           {
                counter1 = i;
                books[i].increase_borrow();
                books[i].decrese_Quantity();
            }
        }

        for(int i = 0; i < users.size(); i++)
        {
            if(str1 == users[i].Get_Name())
           {
                users[i].increase_borrow();
                counter2 = i;
            }

        }

        users[counter2].Set_book(books[counter1]);

        cout << endl;

    }

    void Print_users(){

        for(int i = 0; i < users.size(); i++)
            users[i].print_users();
    }

    void Print_who_borrow(){

        string str;

        cout << "\nEnter book name: ";
        cin >> str;
        cout << endl;

        for(int i = 0; i < users.size(); i++)
        {
            bool flag = false;

            for(int j = 0; j < users[i].Return_numberbook(); j++)
            {
                if(str == users[i].Return_book_name(j))
                    flag = true;
            }

            if(flag)
                    cout << "Name: " <<users[i].Get_Name() << endl;
        }

    }

    void User_Return_book(){

        string str1,str2;
        cout <<"\nEnter username and book name: ";
        cin >> str1 >> str2;

        for(int i = 0; i < users.size(); i++)
        {
            if(str1 == users[i].Get_Name())
            {
                for(int j = 0; j < users[i].Return_numberbook(); j++)
                {
                    if(str2 == users[i].Return_book_name(j))
                    {
                        users[i].Return_book(j);
                        users[i].decrease_borrow();

                    }
                }
            }
        }


        for(int i = 0; i < books.size(); i++)
        {
            if(str2 == books[i].Get_Name())
            {
                books[i].decrease_borrow();
                books[i].incerese_Quantity();
            }

        }

    }


};


int main()
{

    Library_System test;
    test.Run();






}
