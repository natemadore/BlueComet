#!/bin/bash



#==================================================
#=  ====  =====  =====       =====    ======    ===
#=  ===  =====    ====  ====  ===  ==  ====  ==  ==
#=  ==  =====  ==  ===  ====  ==  ====  ==  ====  =
#=  =  =====  ====  ==  ====  ==  ====  ==  ====  =
#=     =====  ====  ==       ===  ====  ==  ====  =
#=  ==  ====        ==  ========  ====  ==  ====  =
#=  ===  ===  ====  ==  ========  ====  ==  ====  =
#=  ====  ==  ====  ==  =========  ==  ====  ==  ==
#=  ====  ==  ====  ==  ==========    ======    ===
#==================================================




# Stop the running memory leak program
sudo pkill memory_leak

# Remove the memory_leak executable
sudo rm /usr/local/bin/memory_leak

# Remove the systemd service file
sudo rm /etc/systemd/system/memory_leak.service

# Reload the systemd daemon
sudo systemctl daemon-reload

# Disable the service from running at startup
sudo systemctl disable memory_leak.service

echo "BlueComet has been stopped."
