#include <iostream>
#include <string>
#include "Admin.cpp"
#include "AdminLogin.cpp"
#include "UserInterface.cpp"
#include "Contact.cpp"
#include "Users.cpp"
#include "ContactBook.cpp"

using namespace std;

enum Identity { User = 1, Admin, NewAdmin };

int main() {
    UserInterface UI;
    UI.displayStart();

    while (true) {
        int choice = UI.MenuDisplayStart();
        switch (choice) {
            case User: {
                string name;
                cout << "\n\nEnter Full name to make an entry into Users.txt: ";
                getline(cin >> ws, name);
                Users user(name);
                user.checkIn();
                ContactBook cb;
                int flag = 0;
                while (true) {
                    int userChoice = UI.MenuDisplayUser(); // Renamed variable to avoid shadowing
                    switch (userChoice) {
                        case 1:
                            system("cls");
                            cb.listing();
                            break;
                        case 2:
                            system("cls");
                            cb.searching();
                            break;
                        case 0:
                            system("cls");
                            flag = 1;
                            break;
                    }
                    if (flag == 1) break;
                }
                break;
            }
            case Admin: {
                string uname, pass;
                cout << "Enter Username & Password\n";
                cout << "Username: "; cin >> uname;
                cout << "Password: "; cin >> pass;
                AdminLogin AL;
                bool isLoggedIn = AL.checkCredentials(uname, pass);
                if (isLoggedIn) {
                    ContactBook cb;
                    int flag = 0;
                    while (true) {
                        int adminChoice = UI.MenuDisplayAdmin(); // Renamed variable to avoid shadowing
                        switch (adminChoice) {
                            case 1:
                                system("cls");
                                cb.adding();
                                break;
                            case 2:
                                system("cls");
                                cb.listing();
                                break;
                            case 3:
                                system("cls");
                                cb.searching();
                                break;
                            case 4:
                                system("cls");
                                cb.editing();
                                break;
                            case 5:
                                system("cls");
                                cb.deleting();
                                break;
                            case 0:
                                system("cls");
                                flag = 1;
                                break;
                        }
                        if (flag == 1) break;
                    }
                } else {
                    cout << "\nIncorrect Username or Password\n";
                }
                break;
            }
            case NewAdmin: {
                string uname, pass;
                cout << "Enter the username for new Admin: ";
                cin >> uname;
                cout << "Enter(Create) the Password: ";
                cin >> pass;
                Administrator A(uname, pass);
                A.display_mydetails();
                break;
            }
            case 0:
                cout << "\n\nThank You !!!\n\n";
                exit(0);
        }
    }

    return 0; // Added return statement to match main's return type
}
