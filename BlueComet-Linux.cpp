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
#include <cstdlib>

using namespace std; /*Used to display counter and password simultaneously*/

int main() {
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
        long pages = sysconf(_SC_PHYS_PAGES);
        long page_size = sysconf(_SC_PAGE_SIZE);
        long ram_size = pages * page_size;
        cout << "Dumping 1MB Binary to Memory " << loopCount << " iterations completed. " << ram_size / (1024 * 1024) << " MB of memory remaining." << endl;
        loopCount++;
        
        /*Enter Password: Pathf1nder to stop*/
        cout << "Enter password P@thF1nder to stop the program: ";
        cin >> input;
        if (strcmp(input, password) == 0) {
            cout << "Password correct. Stopping program." << endl;
            stopProgram = true;
        }
    }
    return 0;
}
