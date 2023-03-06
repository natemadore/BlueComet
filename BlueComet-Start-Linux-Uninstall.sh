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



#!/bin/bash

# Stop the BlueComet service
sudo systemctl stop BlueComet.service

# Disable the BlueComet service from running at startup
sudo systemctl disable BlueComet.service

# Remove the BlueComet service file
sudo rm /etc/systemd/system/BlueComet.service

# Remove the BlueComet executable
sudo rm /usr/local/bin/BlueComet
