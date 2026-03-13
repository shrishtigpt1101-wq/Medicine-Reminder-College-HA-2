Medicine Reminder System 
--------------------------

A console-based medicine management system developed in C++ that allows users to create accounts, manage their health profile, schedule medicines, and track medication intake.
The system stores all data in simple text files, so no external database is required. Each user has their own separate records for profile, medicines, and history.

Key Features:
-------------

1. User Account Management:

Users can create an account and log in securely.
Credentials are stored in accounts.txt.
Users can also change their password from the Settings menu.

3. Health Profile Management:
   
Each user maintains a personal health profile including:
    Age
    Gender
    Medical conditions
Emergency contact information

The profile is saved in:    <username>_profile.txt

3. Medicine Management Dashboard:
 
Users can manage medicines through a dashboard where they can:
    Add new medicines
    Edit existing medicines
    Delete medicines
    View medicine schedules
    Search for medicines
    Sort medicines
Medicine data is stored in:     <username>_medicines.txt

4. Medicine Schedule Tracking:

Each medicine includes dosage information and scheduled intake times such as Morning, Afternoon, or Night.
This helps users follow a daily medication routine.

5. Medicine Status Tracking:
   
Users can track their medication by marking it as:
    Taken
    Missed
Every action is recorded for monitoring adherence.

6. Automatic Stock Management:

The system automatically:
    Reduces medicine stock when marked as taken
    Displays low stock warnings when medicine quantity becomes low
This helps users refill medicines on time.

7. Medicine History and Reports:

All medicine activities are stored in a history file:   <username>_history.txt

This allows users to review:
Past medicine intake
Missed doses
Medicine updates

Project Structure:
-------------------

MedicineReminder/
│
├── MedicineReminder.cpp        # Main program source code
├── MedicineReminder.exe        # Compiled executable
├── accounts.txt                # Stores user login credentials
│
├── <username>_profile.txt      # User health profile
├── <username>_medicines.txt    # User medicine records
├── <username>_history.txt      # User medicine history
│
└── Flowchart.txt               # System flow and design notes


Compilation:
-------------

The program requires a C++17 compatible compiler such as:
MinGW g++
Microsoft Visual C++
Clang

Compile using:
g++ -std=c++17 MedicineReminder.cpp -o MedicineReminder.exe
Running the Program

Navigate to the project directory and run:
./MedicineReminder.exe

Follow the on-screen menu to:
    Create an account
    Login
    Add medicines
    Manage medicine schedules
All user data will be automatically stored in the respective text files.

Advantages of the System:
-------------------------

No external database required
Simple file-based storage
Easy to run on any computer with a C++ compiler
Helps users maintain regular medication habits

