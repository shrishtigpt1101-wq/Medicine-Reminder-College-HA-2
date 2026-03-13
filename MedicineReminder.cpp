/*******************************************************
        MEDICINE REMINDER APPLICATION
--------------------------------------------------------
Language  : C++ (OOP)
Purpose   : Helps users manage medicines by providing
            reminders, dosage tracking, stock alerts,
            and medication history.

Features:
✔ User Account System
✔ Medicine Schedule Management
✔ Low Stock Warning System
✔ Medicine History Tracking
✔ Search and Sorting
✔ Profile Management
✔ Password Change System
********************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

class Medicine
{
public:
    string name, dosage, time, status;
    int stock;

    Medicine(string n, string d, string t, int s)
    {
        name = n;
        dosage = d;
        time = t;
        stock = s;
        status = "Pending";
    }
};

class UserProfile
{
public:
    string name;
    int age;
    char gender;
    string medicalConditions;
    string emergencyContact;

    void createProfile(string username)
    {
        cin.ignore();

        cout << "\nEnter Name: ";
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter Gender (M/F): ";
        cin >> gender;
        cin.ignore();

        cout << "Enter Medical Conditions: ";
        getline(cin, medicalConditions);

        cout << "Enter Emergency Contact: ";
        getline(cin, emergencyContact);

        ofstream file(username + "_profile.txt");

        file << name << endl;
        file << age << endl;
        file << gender << endl;
        file << medicalConditions << endl;
        file << emergencyContact << endl;

        file.close();

        cout << "Profile Saved Successfully!\n";
    }

    void loadProfile(string username)
    {
        ifstream file(username + "_profile.txt");

        getline(file, name);
        file >> age >> gender;
        file.ignore();

        getline(file, medicalConditions);
        getline(file, emergencyContact);

        file.close();
    }

    void showProfile()
    {
        cout << "\n========== USER PROFILE ==========\n";
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;

        cout << "Gender: "
             << (gender == 'M' || gender == 'm' ? "Male"
             : gender == 'F' || gender == 'f' ? "Female" : "-") << endl;

        cout << "Medical Conditions: "
             << (medicalConditions.empty() ? "-" : medicalConditions) << endl;

        cout << "Emergency Contact: "
             << (emergencyContact.empty() ? "-" : emergencyContact) << endl;
    }
};

vector<Medicine> medicines;
string currentUser;

bool duplicateMedicine(string name)
{
    for (auto &m : medicines)
        if (m.name == name)
            return true;

    return false;
}

bool usernameExists(string username)
{
    ifstream file("accounts.txt");
    string u, p;

    while (file >> u >> p)
        if (u == username)
            return true;

    return false;
}

void saveMedicines()
{
    ofstream file(currentUser + "_medicines.txt");

    for (auto &m : medicines)
        file << m.name << " "
             << m.dosage << " "
             << m.time << " "
             << m.stock << " "
             << m.status << endl;

    file.close();
}

void loadMedicines()
{
    medicines.clear();

    ifstream file(currentUser + "_medicines.txt");

    string name, dosage, time, status;
    int stock;

    while (file >> name >> dosage >> time >> stock >> status)
    {
        Medicine m(name, dosage, time, stock);
        m.status = status;
        medicines.push_back(m);
    }

    file.close();
}

void saveHistory(string text)
{
    ofstream file(currentUser + "_history.txt", ios::app);
    file << text << endl;
    file.close();
}

void addMedicine()
{
    string name, dosage, time;
    int stock, choice;

    cout << "\nEnter Medicine Name: ";
    cin >> name;

    if (duplicateMedicine(name))
    {
        cout << "Duplicate Medicine!\n";
        return;
    }

    cout << "Enter Dosage: ";
    cin >> dosage;

    cout << "Enter Stock: ";
    cin >> stock;

    cout << "\n1 Morning\n2 Afternoon\n3 Night\nChoice: ";
    cin >> choice;

    time = (choice == 1 ? "Morning" :
           (choice == 2 ? "Afternoon" : "Night"));

    medicines.push_back(Medicine(name, dosage, time, stock));

    saveMedicines();

    cout << "Medicine Added Successfully!\n";
}

void showMedicines()
{
    if (medicines.empty())
    {
        cout << "No Medicines Added.\n";
        return;
    }

    cout << "\n========================================================\n";
    cout << "No   Name        Dosage      Time       Stock    Status\n";
    cout << "========================================================\n";

    for(int i=0;i<medicines.size();i++)
    {
        cout << i+1 << "   "
            << medicines[i].name << "      "
            << medicines[i].dosage << "      "
            << medicines[i].time << "      "
            << medicines[i].stock << "      "
            << medicines[i].status << endl;
    }

    cout << "========================================================\n";
}

void markMedicine()
{
    showMedicines();

    int num, choice;

    cout << "Select Medicine Number: ";
    cin >> num;

    cout << "1 Taken\n2 Missed\nChoice: ";
    cin >> choice;

    if (choice == 1)
    {
        medicines[num - 1].status = "Taken";
        medicines[num - 1].stock--;

        if (medicines[num - 1].stock <= 2)
            cout << "\n****************************************\n";
            cout << "⚠  LOW STOCK ALERT!\n";
            cout << "Medicine: " << medicines[num-1].name << endl;
            cout << "Please refill your medicine soon.\n";
            cout << "****************************************\n";

        saveHistory("Taken: " + medicines[num - 1].name);
    }
    else
    {
        medicines[num - 1].status = "Missed";
        saveHistory("Missed: " + medicines[num - 1].name);
    }

    saveMedicines();
}

void deleteMedicine()
{
    showMedicines();

    int num;

    cout << "Enter Medicine Number To Delete: ";
    cin >> num;

    medicines.erase(medicines.begin() + num - 1);

    saveMedicines();

    cout << "Medicine Deleted.\n";
}

void editMedicine()
{
    showMedicines();

    int num, stock, choice;
    string dosage, time;

    cout << "Enter Medicine Number To Edit: ";
    cin >> num;

    cout << "Enter New Dosage: ";
    cin >> dosage;

    cout << "Enter New Stock: ";
    cin >> stock;

    cout << "1 Morning\n2 Afternoon\n3 Night\nChoice: ";
    cin >> choice;

    time = (choice == 1 ? "Morning" :
           (choice == 2 ? "Afternoon" : "Night"));

    medicines[num - 1].dosage = dosage;
    medicines[num - 1].stock = stock;
    medicines[num - 1].time = time;

    saveMedicines();

    cout << "Medicine Updated.\n";
}

void searchMedicine()
{
    string name;

    cout << "Enter Medicine Name: ";
    cin >> name;

    for (auto &m : medicines)
        if (m.name == name)
        {
            cout << "Found: "
                 << m.name << " | "
                 << m.dosage << " | "
                 << m.time << endl;
            return;
        }

    cout << "Medicine Not Found.\n";
}

void medicineHistory()
{
    ifstream file(currentUser + "_history.txt");

    string line;

    cout << "\n========== HISTORY ==========\n";

    while (getline(file, line))
        cout << line << endl;

    file.close();
}

void medicineReport()
{
    int taken = 0, missed = 0;

    for (auto &m : medicines)
    {
        if (m.status == "Taken") taken++;
        else if (m.status == "Missed") missed++;
    }

    cout << "\n========== REPORT ==========\n";
    cout << "Taken: " << taken << endl;
    cout << "Missed: " << missed << endl;
}

void sortMedicines()
{
    int choice;

    cout << "1 Sort By Name\n2 Sort By Stock\nChoice: ";
    cin >> choice;

    if (choice == 1)
        sort(medicines.begin(), medicines.end(),
             [](Medicine a, Medicine b){ return a.name < b.name; });

    else
        sort(medicines.begin(), medicines.end(),
             [](Medicine a, Medicine b){ return a.stock < b.stock; });

    cout << "Sorted Successfully.\n";
}

void medicineMenu()
{
    int choice;

    do
    {
        cout << "\n===== MEDICINE MENU =====\n";
        cout << "1 Add Medicine\n";
        cout << "2 Show Medicines\n";
        cout << "3 Mark Taken/Missed\n";
        cout << "4 Delete Medicine\n";
        cout << "5 Search Medicine\n";
        cout << "6 Medicine History\n";
        cout << "7 Medicine Report\n";
        cout << "8 Edit Medicine\n";
        cout << "9 Sort Medicines\n";
        cout << "10 Back\n";

        cin >> choice;

        switch(choice)
        {
            case 1: addMedicine(); break;
            case 2: showMedicines(); break;
            case 3: markMedicine(); break;
            case 4: deleteMedicine(); break;
            case 5: searchMedicine(); break;
            case 6: medicineHistory(); break;
            case 7: medicineReport(); break;
            case 8: editMedicine(); break;
            case 9: sortMedicines(); break;
        }

    } while(choice != 10);
}

void changePassword()
{
    string oldPass,newPass,u,p;

    cout<<"Enter Current Password: ";
    cin>>oldPass;

    ifstream file("accounts.txt");
    vector<pair<string,string>> accounts;

    bool match=false;

    while(file>>u>>p)
    {
        if(u==currentUser && p==oldPass)
        {
            match=true;

            cout<<"Enter New Password: ";
            cin>>newPass;

            accounts.push_back({u,newPass});
        }
        else
        {
            accounts.push_back({u,p});
        }
    }

    file.close();

    if(!match)
    {
        cout<<"Wrong Password!\n";
        return;
    }

    ofstream out("accounts.txt");

    for(auto &a:accounts)
        out<<a.first<<" "<<a.second<<endl;

    out.close();

    cout<<"Password Changed Successfully!\n";
}

void settingsMenu()
{
    int choice;

    do
    {
        cout<<"\n===== SETTINGS =====\n";
        cout<<"1 Change Password\n";
        cout<<"2 Back\n";

        cin>>choice;

        if(choice==1)
            changePassword();

    }while(choice!=2);
}

bool login()
{
    string username,password,u,p;

    cout<<"Enter Username: ";
    cin>>username;

    cout<<"Enter Password: ";
    cin>>password;

    ifstream file("accounts.txt");

    while(file>>u>>p)
        if(u==username && p==password)
        {
            currentUser=username;
            return true;
        }

    return false;
}

void createAccount(UserProfile &user)
{
    string username,password;

    cout<<"Create Username: ";
    cin>>username;

    if(usernameExists(username))
    {
        cout<<"Username Exists!\n";
        return;
    }

    cout<<"Create Password: ";
    cin>>password;

    ofstream file("accounts.txt",ios::app);
    file<<username<<" "<<password<<endl;
    file.close();

    currentUser=username;

    user.createProfile(username);
}

int main()
{
    UserProfile user;

    int choice;

    do
    {
        cout<<"\n===== MEDICINE REMINDER APP =====\n";
        cout<<"1 Create Account\n";
        cout<<"2 Login\n";
        cout<<"3 Exit\n";

        cin>>choice;

        if(choice==1)
            createAccount(user);

        else if(choice==2)
        {
            if(login())
            {
                cout << "\n====================================\n";
                cout << "  Welcome " << currentUser << "!\n";
                cout << "  Login Successful\n";
                cout << "====================================\n";

                user.loadProfile(currentUser);
                loadMedicines();

                int menuChoice;

                do
                {
                    cout<<"\n===== MAIN MENU =====\n";
                    cout<<"1 Medicine\n";
                    cout<<"2 Profile\n";
                    cout<<"3 Settings\n";
                    cout<<"4 Logout\n";

                    cin>>menuChoice;

                    if(menuChoice==1)
                        medicineMenu();

                    else if(menuChoice==2)
                        user.showProfile();

                    else if(menuChoice==3)
                        settingsMenu();

                }while(menuChoice!=4);
            }
            else
                cout<<"Login Failed!\n";
        }

    }while(choice!=3);

    cout << "\n=================================\n";
    cout << " Thank You For Using Our System\n";
    cout << " Stay Healthy!\n";
    cout << "=================================\n";
    return 0;
}