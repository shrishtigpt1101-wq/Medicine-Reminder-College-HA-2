# Medicine Reminder (C++ console)

Console-based medicine manager where each user creates an account, keeps a health profile, schedules medicines, and tracks doses taken or missed. Data is stored in simple text files next to the program—no external database required.

## Features
- Login and account creation with per-user storage.
- Profile sheet: age, gender, conditions, emergency contact.
- Medicine dashboard: add, edit, delete, search, sort, and view schedules.
- Mark doses as taken or missed; stock count drops automatically and warns when low.
- History and reports to review past actions.
- Password change flow inside Settings.

## Project structure
- `MedicineReminder.cpp` - main source file.
- `MedicineReminder.exe` - prebuilt Windows binary (built locally).
- `accounts.txt` - user credentials store.
- `<username>_profile.txt`, `<username>_medicines.txt`, `<username>_history.txt` - data saved per user at runtime.
- `Flowchart.txt` - quick design/flow notes.

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

Follow the prompts to create an account, add medicines, and manage your schedule. Data persists in the text files listed above.

## Notes
- No external libraries are needed.
- If you rebuild, replace `MedicineReminder.exe` with your new build.
