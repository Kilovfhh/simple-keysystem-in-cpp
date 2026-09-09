#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;
struct ActiveMembers {
    int id;
    bool vip;
};

int main() {
    // Grabbing local user
    char username[256];
    DWORD size = sizeof(username);

    if (GetUserNameA(username, &size)) {
        system("cls");
    }
    else {
        cerr << "Loading NexOP.exe" << endl;
    }

    ifstream FileName("NexKey.txt");
    int data;

    ActiveMembers members[] = {
        {39475924, true},
        {43262354, false},
    };

    bool ActiveKey = false;
    int KeyLicense;
    bool found = false;

    bool FIlE_FOUND = false;

    // Login part 
    if (FileName.is_open()) { // Checking if this file exsits by opening it
        // If file is able to open will set FILE_FOUND to true
        FIlE_FOUND = true;
        while (FileName >> data) {
            break;
        }
    }
    else {
        FIlE_FOUND = false;
    }


    if (FIlE_FOUND == true) {
        found = true;
        cout << "Welcome back "<< username << "!" << endl;
        for (ActiveMembers members : members) {
            if (data == members.id) {
                cout << "We located your old account. Checking status for login!" << endl;
                if (members.vip == true) {
                    cout << "Account is active!" << endl;
                    cout << "Signing in for you~" << endl;
                    this_thread::sleep_for(chrono::seconds(5));
                    break;
                }
                else {
                    cout << "Account seem's to be deactivated/banned!" << endl;
                    cout << "----------------------------------------" << endl;
                    cout << "Contact @itzoxy for more help!" << endl;
                    cout << "Closing Application..." << endl;
                    this_thread::sleep_for(chrono::seconds(5));
                    exit(0);
                }
            }
        }
        
    }
    else {
        cout << "Welcome to NexOP | Undectected Since 2026 | Made By: Nexa" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "Enter your key license: ";
        std::cin >> KeyLicense;


        for (ActiveMembers members : members) {
            if (KeyLicense == members.id) {
                found = true;
                cout << "Key valid. Checking status..." << endl;
                this_thread::sleep_for(chrono::seconds(3));
                if (members.vip == false) {
                    cout << "Key never used. Activiating it!" << endl;
                    this_thread::sleep_for(chrono::seconds(3));
                    members.vip = true; // Once active well create file saving there key so next time they auto login

                    
                    ofstream filename("NexKey.txt");
                    filename << KeyLicense;
                    filename.close();
                }
                break;
            }
        }
    }





    system("cls");


    if (!found) {
        cout << "We were unable to located this key. Please contact @itzoxy for help!" << endl;
        cout << "Closing this exe.";
        this_thread::sleep_for(chrono::seconds(5));
        exit(0);
    }

    // Calling Function
     


    // Closing Program
    cout << "Press any key to exit." << endl;
    std::cin.ignore();
    std::cin.get();
    return 0;
}
