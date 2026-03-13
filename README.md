 # Medicine Reminder System

 Console-based C++ app to help people stay on top of their prescriptions. Each user gets their own account, profile, medicine list, and history. All data lives in plain text files beside the program—no database setup needed.

 ## Highlights
 - Account login + password change (stored in `accounts.txt`).
 - Personal profile: name, age, gender, conditions, emergency contact.
 - Medicine dashboard: add, edit, delete, search, sort, and view schedules.
 - Track doses as Taken or Missed; stock auto-decrements and warns when low.
 - History and simple reports per user.

 ## Project layout
 - `MedicineReminder.cpp` — main source.
 - `MedicineReminder.exe` — prebuilt Windows binary (local build).
 - `accounts.txt` — credential store.
 - `<username>_profile.txt` — profile data.
 - `<username>_medicines.txt` — medicines and stock.
 - `<username>_history.txt` — dose history.
 - `Flowchart.txt` — design/flow notes.
 - `Project Flowchart diagram.png` — quick visual of the flow.

 ## Build
 Requires a C++17 compiler (MinGW g++, MSVC, or clang).

 ```bash
 g++ -std=c++17 MedicineReminder.cpp -o MedicineReminder.exe
 ```

 ## Run
 From the project folder:

 ```bash
 ./MedicineReminder.exe
 ```

 Follow the menu to create an account, add medicines, and manage schedules. Data persists in the text files listed above.

 ## Why it's simple
 - No external libraries or DB.
 - Works offline.
 - Files are human-readable for quick backup or edits.
