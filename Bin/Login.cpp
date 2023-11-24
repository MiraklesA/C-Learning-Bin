//Basic login script, from a Youtube Video extremely basic and creates multiple TXT files to store login entries, extremely inefficient and can be improved in the future.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
bool LoggingIn() {
    string username, password, user, pass; 
    cout << "Enter Username: "; cin >> username; 
    cout << "Enter Password: "; cin >> password; 

    ifstream read(username + ".txt");
    getline(read, user);
    getline(read, pass);

    if (user == username & pass == password){
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int choice; 
    cout << "Sellect A Choice\n1: Register\n2: Login\n Your Choice: ";
    cin >> choice; 
    if (choice == 1) {
        string username, password;
        cout << "Select a username: "; cin >> username;
        cout << "Select a password: "; cin >> password; 

        ofstream file; 
        file.open (username + ".txt");
        file << username << endl << password; 
        file.close();

        main();

    }

    else if (choice == 2) {
        bool status = LoggingIn();
        if (!status)  {
            cout << "Invalid Credentials, Try Again!" << endl;
            system("PAUSE");
            return 0;
        }
        
        else {
            cout << "Login Successfull" << endl;
            system("PAUSE");
            return 1;
        }
    }
}
