PAYTRACK for Windows, version 1.0
Authors: Jarif Yasir, Ryan Irani, Aws Naser Alqaisi, Niveithan Parthipan

PAYTRACK is a software for windows, created using C++ and QT


To run the program, select open project in QT Creator and select every single file in this folder to run.
There are many excess files that are in the for reference/future use, however QT Creator should format the project directory to only list the actual files in use.

********************************************************IMPORTANT****************************************************************************************
File paths are currently hardcoded within the .cpp files, copy paste the right path accordingly at:

Line 32 in addname.cpp 
Line 36 and Line 60 in dialog.cpp 
Line 29 in loginwindow.cpp
Line 32 in removename.cpp 
Line 25, 42, and 57 in viewwindow.cpp

For simplicity, we suggest to keep the txt file names the same: "ids.txt", "emp_clock_in.txt" and "emp_clock_out.txt"

QT would detect that files exist within the project directory but not read from them (We tried every other possible method before resorting to hardcoding)
This will be taken care of in future versions of the PayTracker software

Easiest way to do this is by having the txt files in the desktop and simply changing the desktop username in the code
**********************************************************************************************************************************************************
INSTRUCTION TO USE:

Login:
PAYTRACK uses a secure login system using IDs from a txt file.
Manager mode: Use the login ID: mg3307 to log in as the manager (This id should also be in ids.txt)
Employee mode: The employee ID must be in the TXT document for a successful login


Employee:
Click clock in to clock in
Click clock out to clock out

Manager:
ADD/Remove Employees
View the crew IDs
View Clock in/ Clock out times
Assign pay rates and names to employee IDs (Coming soon)



PAYTRACK is still in development and new features are to be added in future versions of the application. 