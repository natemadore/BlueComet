# BlueComet

EDUCATIONAL PURPOSES ONLY: Proof of concept for memory leak ransomware. This software will add itself to local startup creating a 1MB memory leak until password "P@thf1nder" is entered. Removal requires deleting 'BlueComet' from registry. After testing this on an i7 11th gen computer with 16 gigabytes of ram. This code will take 4.5 hours approximately to fill up the ram of a system at about 1 Mbps. BlueComet is an exploit that works most compatible with Windows but will also run with a few modifications on Linux devices. Currently at this time there is no support for Mac OS although it is theoritically possible to work there as well. 

WINDOWS: TO INSTALL COMPILE BLUECOMET.CPP AS EXECUTABLE AND RUN WITH ADMINISTRATOR RIGHTS
TO UNINSTALL: ENTER PASSWORD FOUND IN SOURCE CODE. RUN BLUECOMET-UNINSTALL.CPP AS EXECUTABLE

LINUX: RUN BLUECOMET-LINUX.CPP WITH G++. EXECUTE BASH SCRIPT WITH SUDO COMMAND BLUECOMET-START-LINUX.SH (YOU MAY NEED TO ADJUST PERMISSIONS) 
TO STOP: RUN BLUECOMET-LINUX-STOP.SH TO STOP THE MEMORY LEAK. THEN RUN BLUECOMET-START-LINUX-UNINSTALL TO REMOVE THIS FROM STARTUP. 

