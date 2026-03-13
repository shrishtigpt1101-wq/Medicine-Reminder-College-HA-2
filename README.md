# Medicine Reminder (C++ console)

Console-based medicine manager that lets each user create an account, keep a health profile, schedule medicines, and track what was taken or missed. Data is saved to simple text files alongside the program so it runs without any external dependencies.

## Features
- Login & account creation with per-user storage.
- Profile sheet: age, gender, conditions, emergency contact.
- Medicine dashboard: add, edit, delete, search, sort, and view schedules.
- Mark doses as taken/missed; automatically decrements stock and warns when low.
- History and reports to review past actions.
- Password change flow inside Settings.

## Project structure
- `MedicineReminder.cpp` — main source file.
- `MedicineReminder.exe` — prebuilt Windows binary (built on local machine).
- `accounts.txt` — user credentials store.
- `<username>_profile.txt`, `<username>_medicines.txt`, `<username>_history.txt` — data saved per user at runtime.
- `Flowchart.txt` — quick design notes/flow.

## Build
Requires a C++17 compiler (e.g., MinGW g++, MSVC, or clang).

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
- Binaries are small; if you rebuild, replace `MedicineReminder.exe` with your new build.
