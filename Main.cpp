#include <iostream>
#include <string>
using namespace std;

struct bankmanagement {
    int accno;
    string name, address;
    char actype;
    float amount;

    bool checkavailabilty();
    bool searchaccount(int);
    void newaccount();
    void deposit();
    void withdraw();
    void check_account();
    void modifyaccount();
    void deleteaccount();

    bankmanagement() {
        accno = 0;
        name = "";
        address = "";
        actype = '\0';
        amount = 0.0;
    }
};

int main() {
    bankmanagement b[5];
    int x, an;
    bool check;

    while (true) {
        system("CLS");
        cout << "             =================              \n";
        cout << "             |   Bank Menu   |              \n";
        cout << "==========================================\n";
        cout << " 1. Create a new account\n 2. Deposit\n 3. Withdraw\n";
        cout << " 4. Check account\n 5. Modify\n 6. Delete\n";
        cout << " 7. Show all accounts\n 8. Exit\n";
        cout << "==========================================\n";
        cout << " Enter choice no: ";
        cin >> x;

        switch (x) {
            case 1: {
                check = false;
                for (int i = 0; i < 5; i++) {
                    if (b[i].checkavailabilty()) {
                        check = true;
                        b[i].newaccount();
                        break;
                    }
                }
                if (!check)
                    cout << "Accounts exceeded.";
                break;
            }
            case 2: {
                check = false;
                cout << "Enter account no.: ";
                cin >> an;
                for (int i = 0; i < 5; i++) {
                    if (b[i].searchaccount(an)) {
                        check = true;
                        b[i].deposit();
                        break;
                    }
                }
                if (!check)
                    cout << "No account found.";
                break;
            }
            case 3: {
                check = false;
                cout << "Enter account no.: ";
                cin >> an;
                for (int i = 0; i < 5; i++) {
                    if (b[i].searchaccount(an)) {
                        check = true;
                        b[i].withdraw();
                        break;
                    }
                }
                if (!check)
                    cout << "No account found.";
                break;
            }
            case 4: {
                check = false;
                cout << "Enter account no.: ";
                cin >> an;
                for (int i = 0; i < 5; i++) {
                    if (b[i].searchaccount(an)) {
                        check = true;
                        b[i].check_account();
                        break;
                    }
                }
                if (!check)
                    cout << "No account found.";
                break;
            }
            case 5: {
                check = false;
                cout << "Enter account no.: ";
                cin >> an;
                for (int i = 0; i < 5; i++) {
                    if (b[i].searchaccount(an)) {
                        check = true;
                        b[i].modifyaccount();
                        break;
                    }
                }
                if (!check)
                    cout << "No account found.";
                break;
            }
            case 6: {
                check = false;
                cout << "Enter account no.: ";
                cin >> an;
                for (int i = 0; i < 5; i++) {
                    if (b[i].searchaccount(an)) {
                        check = true;
                        b[i].deleteaccount();
                        break;
                    }
                }
                if (!check)
                    cout << "No account found.";
                break;
            }
            case 7: {
                check = false;
                for (int i = 0; i < 5; i++) {
                    if (!b[i].checkavailabilty()) {
                        check = true;
                        cout << "\nAccount details of " << i + 1 << ":\n";
                        b[i].check_account();
                        cout << "\n==========================================\n";
                    }
                }
                if (!check)
                    cout << "No account found.";
                break;
            }
            case 8:
                exit(0);
        }
        cin.ignore();
        cin.get(); // Pause the program
    }

    return 0;
}

bool bankmanagement::checkavailabilty() {
    return accno == 0 && name == "" && address == "" && actype == '\0' && amount == 0.0;
}

bool bankmanagement::searchaccount(int a) {
    return accno == a;
}

void bankmanagement::newaccount() {
    cout << "Enter your account no: ";
    cin >> accno;
    cin.ignore();
    cout << "Enter your full name: ";
    getline(cin, name);
    cout << "Enter your address: ";
    getline(cin, address);
    cout << "What type of account you want to open saving(s) or Current(c): ";
    cin >> actype;
    cout << "Enter how much money you want to deposit: ";
    cin >> amount;
    cout << "Account Created Successfully...";
}

void bankmanagement::deposit() {
    float d;
    cout << "Enter amount to Deposit: ";
    cin >> d;
    amount += d;
    cout << "Updated. New Amount = " << amount;
}

void bankmanagement::withdraw() {
    float wd;
    cout << "Enter amount to withdraw: ";
    cin >> wd;
    if (wd <= amount) {
        amount -= wd;
        cout << "Amount withdrawn.";
    } else {
        cout << "Insufficient balance.";
    }
    cout << "Remaining amount: " << amount;
}

void bankmanagement::check_account() {
    cout << "Your name: " << name;
    cout << "\nYour address: " << address;
    cout << "\nAccount type: " << actype;
    cout << "\nAmount: " << amount;
}

void bankmanagement::modifyaccount() {
    cout << "Account No.: " << accno;
    cin.ignore();
    cout << "\nModify Account Holder Name: ";
    getline(cin, name);
    cout << "Modify your address: ";
    getline(cin, address);
    cout << "Modify Type of Account: saving (s) or Current (c): ";
    cin >> actype;
    cout << "Account is modified.";
}

void bankmanagement::deleteaccount() {
    accno = 0;
    name = "";
    address = "";
    actype = '\0';
    amount = 0.0;
    cout << "Successfully deleted.";
}
