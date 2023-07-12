#include<iostream>
#include<assert.h>
#include<algorithm>
using namespace std;
struct book
{
    int id;
    string name;
    int quan;
    int borrow = 0;

    void add_book() {
        cout << "Enter book info: ID & NAME & QUANTITY\n";
        cin >> id >> name >> quan;
    }
    void print() {
        cout << "ID: " << id << " NAME: " << name << " QUANTITY: " << quan << endl;

    }
    bool search(string search) {
        for (int i = 0; i < search.size(); i++)
        {
            if (name[i] != search[i])
                return false;
        }
        return true;
    }
    bool borrow_book(int user_id) {
        if (quan - borrow == 0)
            return false;
        ++borrow;
        return true;
    }
    void return_copy() {
        assert(borrow > 0);
        borrow;
    }


};

int sort_by_id(book e, book s) {
    return e.id < s.id;
}
int sort_by_name(book e, book s) {
    return e.name < s.name;
}


struct user
{
    int id;
    string name;
    int borrow[10];
    int len = 0;
    void add_user() {
        cout << "Enter your name and natoinal id \n";
        cin >> name >> id;
    }
    void borrow_user(int book_id) {
        borrow[len++] = book_id;
    }
    void return_copy(int book_id) {
        bool removed = false;
        for (int i = 0; i < len; ++i) {
            if (borrow[i] == book_id) {
                for (int j = i + 1; j < len; ++j)
                    borrow[j - 1] = borrow[j];
                removed = true;
                --len;
                break;
            }
        }
    }

    bool is_borrowed(int book_id) {
        for (int i = 0; i < len; ++i) {
            if (book_id == borrow[i])
                return true;
        }
        return false;
    }

    void print() {
        cout << "USER: " << name << " ID: " << id;
        for (int i = 0; i < len; i++)
            cout << " BORROWDED: " << borrow[i] << endl;
    }

};



struct System
{
    book books[10];
    user users[10];
    int add = 0;
    int len = 0;


    int menu() {
        int choice{ -1 };
        while (choice == -1)
        {
            cout << "\nLibrary system\n";
            cout << "1) Add book\n";
            cout << "2) Search for book by prefix\n";
            cout << "4) Print the book by name\n";
            cout << "5) Print the book by id \n";
            cout << "6) Add user\n";
            cout << "7) User borrow book\n";
            cout << "9) Print users\n";
            cout << "-------------------------------\n";
            cout << "Enter your choice\n";
            cin >> choice;

        }
        return choice;
    }

    void run() {

        while (true)
        {
            int choice = menu();
            if (choice == 1)
                add_book();
            else if (choice == 2)
                search();
            else if (choice == 4)
                print_book_by_name();
            else if (choice == 5)
                print_book_by_id();
            else if (choice == 6)
                add_users();
            else if (choice == 7)
                user_borrow_book();
            else if (choice == 9)
                print_user();

        }
    }
    void add_book() {
        books[add++].add_book();
    }

    void print_book_by_id() {
        sort(books, books + add, sort_by_id);
        for (int i = 0; i < add; i++)
            books[i].print();


    }

    void print_book_by_name() {
        sort(books, books + add, sort_by_name);
        for (int i = 0; i < add; i++)
            books[i].print();
    }

    void search() {
        cout << "Enter the prefix of the book\n";
        string search;
        cin >> search;
        for (int i = 0; i < add; i++)
        {
            if (books[i].search(search)) {
                cout << "------------------------\n";
                cout << books[i].name << endl;
            }
        }
    }

    void add_users() {
        users[len++].add_user();
    }

    void print_user() {
        for (int i = 0; i < len; i++)
            users[i].print();
    }

    int find_book_indx(string s) {
        for (int i = 0; i < add; i++)
        {
            if (s == books[i].name)
                return i;
        }
        return -1;
    }

    int find_user_indx(string s) {
        for (int i = 0; i < add; i++)
        {
            if (s == users[i].name)
                return i;
        }
        return -1;
    }

    bool read_username_bookname(int &user_idx, int &book_idx, int tail = 3) {
        string n;
        string nb;
        while (tail--)
        {
            cout << "Enter your name and book name\n";
            cin >> n >> nb;
            user_idx = find_user_indx(n);
            book_idx = find_book_indx(nb);
            return true;
        }
    }
    void user_borrow_book() {
        int user_idx,book_indx;
        if (!read_username_bookname(user_idx, book_indx))
            return;

        int user_id = users[user_idx].id;
        int book_id = books[book_indx].id;
        if (!books[book_indx].borrow_book(user_id))
            cout << "NO more copies\n";
        else
            users[user_idx].borrow_user(book_id);
    }
    void user_return_book() {
        int user_idx, book_idx;

        if (!read_username_bookname(user_idx, book_idx))
            return;

        int book_id = books[book_idx].id;
        books[book_idx].return_copy();
        users[user_idx].return_copy(book_id);
    }



    void print_who_borrowed_book_by_name() {
        string book_name;
        cout << "Enter book name: ";
        cin >> book_name;

        int book_idx = find_book_indx(book_name);

        if (book_idx == -1) {
            cout << "Invalid book name.\n";
            return;
        }
        int book_id = books[book_idx].id;

        if (books[book_idx].borrow == 0) {
            cout << "No borrowed copies\n";
            return;
        }

        for (int i = 0; i < len; ++i) {
            if (users[i].is_borrowed(book_id))
                cout << users[i].name << "\n";
        }
    }

};



int main() {
    System e;
    e.run();
    return 0;
}