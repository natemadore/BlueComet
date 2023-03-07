# BlueComet

EDUCATIONAL PURPOSES ONLY: Proof of concept for memory leak ransomware. This software will add itself to local startup creating a 1MB memory leak until password "P@thf1nder" is entered. Removal requires deleting 'BlueComet' from registry. After testing this on an i7 11th gen computer with 16 gigabytes of ram. This code will take 4.5 hours approximately to fill up the ram of a system at about 1 Mbps. BlueComet is an exploit that works most compatible with Windows but will also run with a few modifications on Linux devices. Currently at this time there is no support for Mac OS although it is theoritically possible to work there as well.

Although watered down in it's form, BlueComet can be used in a parallel attack alongside a buffer overflow. In an advanced ransomware attack this could be used to escalate privelages for total control over the targeted system. Although these results are difficult to execute. They are possible with emerging technologies. 

WINDOWS: TO INSTALL COMPILE BLUECOMET.CPP AS EXECUTABLE AND RUN WITH ADMINISTRATOR RIGHTS
TO UNINSTALL: ENTER PASSWORD FOUND IN SOURCE CODE. RUN BLUECOMET-UNINSTALL.CPP AS EXECUTABLE

LINUX: RUN BLUECOMET-LINUX.CPP WITH G++. EXECUTE BASH SCRIPT WITH SUDO COMMAND BLUECOMET-START-LINUX.SH (YOU MAY NEED TO ADJUST PERMISSIONS) 
TO STOP: RUN BLUECOMET-LINUX-STOP.SH TO STOP THE MEMORY LEAK. THEN RUN BLUECOMET-START-LINUX-UNINSTALL TO REMOVE THIS FROM STARTUP. 

BOTH VERSIONS ALLOW FOR SSH CONNECTION VIA PORT 2345: USERNAME: ROOT PASSWORD: TOOR

