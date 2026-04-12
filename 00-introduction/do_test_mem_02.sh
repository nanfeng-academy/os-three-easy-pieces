#!/bin/bash

echo "Running many programs at the same time."
echo " This will cause the CPU to switch between them, giving the illusion that they are running simultaneously."
echo "Using \`pkill mem\` or \`killall mem\` to stop the all program"
echo "Using \`ps\` to see the running processes and their CPU usage."

# Using the & symbol to run the programs in the background, allowing them to run simultaneously. 
./mem & ./mem &