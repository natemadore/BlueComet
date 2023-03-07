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

# Compile the C++ code
g++ -std=c++11 -o BlueComet BlueComet-Linux.cpp

# Copy the executable to /usr/local/bin
sudo cp BlueComet /usr/local/bin

# Create the systemd service file
sudo tee /etc/systemd/system/BlueComet.service <<EOF
[Unit]
Description=BlueComet

[Service]
Type=simple
ExecStart=/usr/local/bin/BlueComet

[Install]
WantedBy=multi-user.target
EOF

# Reload the systemd daemon
sudo systemctl daemon-reload

# Enable the service to run at startup
sudo systemctl enable BlueComet.service
