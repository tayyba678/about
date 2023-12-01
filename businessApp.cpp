#include <iostream>  // This header is essential for standard input and output operations
#include <windows.h> // This header is for doing special things on a Windows computer.
#include <conio.h>   // This header provides functions for console input/output operations.
#include <string>    // This header allows you to easily work with words and sentences.
#include <cmath>     // This header provides mathematical functions like sin, cos, sqrt, etc.
#include <limits>    // This header defines various properties of fundamental types, such as maximum and minimum values.

using namespace std;

string signIn(string name, string password, string userName[], string userPassword[], string userRole[], int userCount);
bool signUpMe(string name, string password, string role, string userName[], string userPassword[], string userRole[], int &usersCount, int arrsize);
bool isValidInteger(const string &s);
void printHeader();
void logo();
void welcome();
int loginPage();
void logIn();
void signUp();
void bossLogo();
int managerMenu();
int bossMenu();
int employeeMenu();
int manager(string roll, int &employeeCount, string employeeName[], string employeeId[], string employeeSalary[], string employeeDepartment[]);
int boss(string roll, int &employeeCount, string employeeName[], string employeeId[], string employeeSalary[], string employeeDepartment[]);
int employee(string roll, int &employeeCount, string employeeName[], string employeeId[], string employeeSalary[], string employeeDepartment[]);
void employeeLogo();
void exitlogin();

bool addEmployee(string namE, string id, string dp, string salary, string employeeName[], string employeeId[], string employeeDepartment[], string employeeSalary[], int &studentCount, int arrSize);
void displayEmployee(string employeeName[], string employeeId[], string employeeDepartment[], int studentCount);
void employeeInfo(string employeeId[], string employeeDepartment[], int studentCount);
bool isNumeric(const string &str);
void averageSalary(string employeeSalary[], int studentCount);
void increaseSalary(string employeeId[], string employeeSalary[], int studentCount);
void checkTask(string employeeId[], string employeeName[], int studentCount);
void totalSalary(string employeeSalary[], int studentCount);
void giveBonus(string employeeId[], string employeeSalary[], string employeeName[], int studentCount);
void fireEmployee(string employeeId[], string employeeName[], string employeeDepartment[], string employeeSalary[], int &studentCount);
void checkStatus(string employeeName[], string employeeId[], int studentCount);
void displaySalary(string employeeId[], string employeeSalary[], int ecount, string id);
void calculateAndDisplayBonus(string employeeId[], string employeeSalary[], int employeeCount, string id);
void managerlogo();
void exitP();
void gotoxy(int x, int y);
int main()
{
    const int arrsize = 100;
    string userName[arrsize];
    string userPassword[arrsize];
    string userRole[arrsize];
    static int emCount = 0;
    const int arrSize = 100;
    string employeeName[arrSize];
    string employeeId[arrSize];
    string employeeDepartment[arrSize];
    string employeeSalary[arrSize];
    int userCount = 0;
    int loginOption = 0;
    logo();
    system("cls");

    while (loginOption != 3)
    {
        loginOption = loginPage();
        {
            if (loginOption == 1)
            {

                system("cls");
                system("Color 0B");
                string name;
                string password;
                string role;
                printHeader();
                logIn();
                gotoxy(45, 15);
                cout << "Enter your Name: ";
                cin >> name;
                gotoxy(45, 17);
                cout << "Enter your Password: ";
                cin >> password;
                role = signIn(name, password, userName, userPassword, userRole, userCount);

                if (role == "manager" || role == "Manager")
                    manager(role, emCount, employeeName, employeeId, employeeSalary, employeeDepartment);
                else if (role == "boss" || role == "Boss")
                    boss(role, emCount, employeeName, employeeId, employeeSalary, employeeDepartment);
                else if (role == "employee" || role == "Employee")
                    employee(role, emCount, employeeName, employeeId, employeeSalary, employeeDepartment);
                else
                {
                    cout << "User not found. Please try again." << endl;
                    system("pause");
                    system("cls");
                }
            }
            else if (loginOption == 2)
            {
                system("cls");
                system("Color 0B");
                string name;
                string password;
                string role;
                printHeader();
                signUp();
                gotoxy(45, 15);
                cout << "1. User name: ";
                cin >> name;
                gotoxy(45, 16);
                cout << "2. User Password: ";
                cin >> password;
                gotoxy(45, 17);
                cout << "3. Role (Boss, Manager, Employee): ";
                cin >> role;
                bool isValid = signUpMe(name, password, role, userName, userPassword, userRole, userCount, arrsize);
                if (isValid)
                {
                    cout << "Signed Up Successfully" << endl;
                }
                if (!isValid)
                {
                    cout << "Warning! Signed Up not Successfully" << endl;
                }
                system("pause");
                system("cls");
            }
        }
        if (loginOption == 3)
        {
            exitP();
        }
    }
}
void printHeader()
{
    cout << "                               _   _                               ____                                                " << endl;
    cout << "                              | | | |_   _ _ __ ___   __ _ _ __   |  _ \\ ___  ___  ___  _   _ _ __ ___ ___             " << endl;
    cout << "                              | |_| | | | | '_ ` _ \\ / _` | '_ \\  | |_) / _ \\/ __|/ _ \\| | | | '__/ __/ _ \\       " << endl;
    cout << "                              |  _  | |_| | | | | | | (_| | | | | |  _ <  __/\\__ \\ (_) | |_| | | | (_|  __/          " << endl;
    cout << "                              |_| |_|\\__,_|_| |_| |_|\\__,_|_| |_| |_| \\_\\___||___/\\___/ \\__,_|_|  \\___\\___|    " << endl;

    cout << "                    __   __                                                  _     ____            _                          " << endl;
    cout << "                   |  \\/  | __ _ _ __   __ _  __ _  ___ _ __ ___   ___ _ __ | |_  / ___| _   _ ___| |_ ___ _ __ ___          " << endl;
    cout << "                   | |\\/| |/ _` | '_ \\ / _` |/ _` | / _\\  '_ ` _ \\ / _\\ '_ \\| __| \\___ \\| | | / __| __/ _ \\ '_ ` _ \\" << endl;
    cout << "                   | |  | | (_| | | | | (_| | (_| |  __/ | | | | |  __/ | | | |_   ___) | |_| \\__ \\ ||  __/ | | | | |       " << endl;
    cout << "                   |_|  |_|\\___ |_| |_|\\__,_|\\__  |\\___|_| |_| |_|\\___|_| |_|\\__| |____/ \\__, |___/\\__\\___|_| |_| |_|" << endl;
    cout << "                                             |___/                                       |___/                                " << endl;
    cout << endl;
}
void welcome()
{
    gotoxy(45, 30);
    cout << "  _       __     __                         " << endl;
    gotoxy(45, 31);
    cout << " | |     / /__  / /________  ____ ___  ___ " << endl;
    gotoxy(45, 32);
    cout << " | | /| / / _ \\/ / ___/ __ \\/ __ `__ \\/ _ " << endl;
    gotoxy(45, 33);
    cout << " | |/ |/ /  __/ / /__/ /_/ / / / / / /  __/" << endl;
    gotoxy(45, 34);
    cout << " |__/|__/\\___/_/\\___/\\____/_/ /_/ /_/\\___/ " << endl;
}
bool isValidInteger(const string &s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

int loginPage()
{
    string op;
    printHeader();
    welcome();
    system("Color 0E");
    int option;
    bool invalidInput = false;

    while (true)
    {
        gotoxy(45, 15);
        cout << "1. Sign In" << endl;
        gotoxy(45, 16);
        cout << "2. Sign Up" << endl;
        gotoxy(45, 17);
        cout << "3. Exit" << endl;
        gotoxy(49, 18);
        cout << "Select your Option (only press 1 or 2 or 3): ";
        cin >> op;

        if (isValidInteger(op) && op.length() == 1)
        {
            option = stoi(op);
            if (option >= 1 && option <= 3)
            {
                break;
            }
            else
            {
                cout << "Invalid input. Please enter a valid option (1, 2, or 3)." << endl;
                system("pause");
                invalidInput = true;
            }
        }
        else
        {
            cout << "Invalid input. Please enter a valid option (1, 2, or 3)." << endl;
            system("pause");
            invalidInput = true;
        }
        system("CLS");

        if (invalidInput)
        {
            printHeader();
            welcome();
            system("Color 0E");
            invalidInput = false;
        }
    }

    return option;
}
void logIn()
{
    string name, password;
    gotoxy(45, 30);
    cout << "   _____ _                ____        " << endl;
    gotoxy(45, 31);
    cout << "  / ___/(_)___ _____     /  _/___     " << endl;
    gotoxy(45, 32);
    cout << "  \\__ \\/ / __ `/ __ \\    / // __ \\   " << endl;
    gotoxy(45, 33);
    cout << " ___/ / / /_/ / / / /  _/ // / / /     " << endl;
    gotoxy(45, 34);
    cout << "/____/_/\\__, /_/ /_/  /___/_/ /_/      " << endl;
    gotoxy(45, 35);
    cout << "       /____/                          " << endl;
    gotoxy(45, 12);
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
int manager(string roll, int &employeeCount, string employeeName[], string employeeId[], string employeeSalary[], string employeeDepartment[])
{
    const int arrSize = 100;
    string yearsWorked[arrSize];
    string namE, id, dp, salary;
    int select1;
    system("cls");
    printHeader();
    managerlogo();
    while (select1 != 9)
    {
        select1 = managerMenu();
        if (select1 == 1)
        {
            system("Color 0E");
            system("cls");
            printHeader();
            managerlogo();
            cout << "Enter Employee Name: ";
            cin >> namE;
            cout << "Enter Employee Id: ";
            cin >> id;
            cout << "Enter Employee Department: ";
            cin >> dp;
            cout << "Enter Employee Salary: ";
            cin >> salary;
            addEmployee(namE, id, dp, salary, employeeName, employeeId, employeeDepartment, employeeSalary, employeeCount, arrSize);
            system("pause");
            system("cls");
        }
        else if (select1 == 2)
        {
            system("cls");
            printHeader();
            managerlogo();
            displayEmployee(employeeName, employeeId, employeeDepartment, employeeCount);
            system("cls");
        }
        else if (select1 == 3)
        {
            system("cls");
            printHeader();
            managerlogo();
            employeeInfo(employeeId, employeeDepartment, employeeCount);
            system("cls");
        }
        else if (select1 == 4)
        {
            system("cls");
            printHeader();
            managerlogo();
            averageSalary(employeeSalary, employeeCount);
            system("cls");
        }
        else if (select1 == 5)
        {
            system("cls");
            printHeader();
            managerlogo();
            increaseSalary(employeeId, employeeSalary, employeeCount);
            system("cls");
        }
        else if (select1 == 6)
        {
            system("cls");
            printHeader();
            managerlogo();
            checkTask(employeeId, employeeName, employeeCount);
            system("cls");
        }
        else if (select1 == 7)
        {
            system("cls");
            printHeader();
            managerlogo();
            fireEmployee(employeeId, employeeName, employeeDepartment, employeeSalary, employeeCount);
            system("cls");
        }
        else if (select1 == 8)
        {
            system("cls");
            printHeader();
            managerlogo();
            exitlogin();
            system("cls");
        }
    }
    return 0;
}

int managerMenu()
{
    system("cls");
    int select1;
    bool isValidInput = false;
    printHeader();
    do
    {

        managerlogo();
        gotoxy(40, 19);
        cout << "1. Add Employee" << endl;
        gotoxy(40, 20);
        cout << "2. Display All Employees" << endl;
        gotoxy(40, 21);
        cout << "3. Employees Working Info" << endl;
        gotoxy(40, 22);
        cout << "4. Calculate Average Salary" << endl;
        gotoxy(40, 23);
        cout << "5. Increase Salary" << endl;
        gotoxy(40, 24);
        cout << "6. Check tasks" << endl;
        gotoxy(40, 25);
        cout << "7. Fire Employee" << endl;
        gotoxy(40, 26);
        cout << "8. Exit" << endl;
        gotoxy(40, 27);
        cout << "Enter your choice(1-8): ";

        if (!(cin >> select1))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("pause");
        }
        else if (select1 < 1 || select1 > 8)
        {
            system("pause");
        }
        else
        {
            isValidInput = true;
        }

    } while (!isValidInput);

    return select1;
}
void managerlogo()
{
    gotoxy(8, 12);
    cout << "     __  ___                  ______          " << endl;
    gotoxy(8, 13);
    cout << "    /  |/  /___ _____  ____ _/ ____/__  _____" << endl;
    gotoxy(8, 14);
    cout << "   / /|_/ / __ `/ __ \\/ __ `/ / __/ _ \\/ ___/" << endl;
    gotoxy(8, 15);
    cout << "  / /  / / /_/ / / / / /_/ / /_/ /  __/ /    " << endl;
    gotoxy(8, 16);
    cout << " /_/  /_/\\__,_/_/ /_/\\__,_/\\____/\\___/_/     " << endl;
}
void signUp()
{
    gotoxy(45, 30);
    cout << "   _____ _                __  __    " << endl;
    gotoxy(45, 31);
    cout << "  / ___/(_)___ _____     / / / /___ " << endl;
    gotoxy(45, 32);
    cout << "  \\__ \\/ / __ `/ __ \\   / / / / __ \\" << endl;
    gotoxy(45, 33);
    cout << " ___/ / / /_/ / / / /  / /_/ / /_/ /" << endl;
    gotoxy(45, 34);
    cout << "/____/_/\\__, /_/ /_/   \\____/ .___/ " << endl;
    gotoxy(45, 35);
    cout << "       /____/              /_/      " << endl;
}
bool signUpMe(string name, string password, string role, string userName[], string userPassword[], string userRole[], int &userCount, int arrsize)
{
    bool isPresent = false;

    for (int index = 0; index < userCount; index++)
    {
        if (userName[index] == name && userPassword[index] == password)
        {
            isPresent = true;
            break;
        }
    }
    if (isPresent == true)
    {
        return 0;
    }
    else if (userCount < arrsize)
    {
        userName[userCount] = name;
        userPassword[userCount] = password;
        userRole[userCount] = role;
        userCount++;
        return true;
    }
    else
    {
        return false;
    }
}
string signIn(string name, string password, string userName[], string userPassword[], string userRole[], int userCount)
{
    for (int index = 0; index < userCount; index++)
    {
        if (userName[index] == name && userPassword[index] == password)
        {
            return userRole[index];
        }
    }
    return "Not Found";
}
int boss(string roll, int &employeeCount, string employeeName[], string employeeId[], string employeeSalary[], string employeeDepartment[])
{
    const int arrSize = 100;
    string yearsWorked[arrSize];
    string namE, id, dp, salary;
    int select2;
    system("cls");
    printHeader();
    managerlogo();
    while (select2 != 8)
    {
        select2 = bossMenu();
        if (select2 == 1)
        {
            system("cls");
            printHeader();
            managerlogo();
            cout << "Enter Employee Name: ";
            cin >> namE;
            cout << "Enter Employee Id: ";
            cin >> id;
            cout << "Enter Employee Department: ";
            cin >> dp;
            cout << "Enter Employee Salary: ";
            cin >> salary;
            addEmployee(namE, id, dp, salary, employeeName, employeeId, employeeDepartment, employeeSalary, employeeCount, arrSize);
            system("pause");
            system("cls");
        }
        else if (select2 == 2)
        {
            system("cls");
            printHeader();
            bossLogo();
            displayEmployee(employeeName, employeeId, employeeDepartment, employeeCount);
            system("cls");
        }
        else if (select2 == 3)
        {
            system("cls");
            printHeader();
            bossLogo();
            totalSalary(employeeSalary, employeeCount);
            system("cls");
        }
        else if (select2 == 4)
        {
            system("cls");
            printHeader();
            bossLogo();
            averageSalary(employeeSalary, employeeCount);
            system("cls");
        }
        else if (select2 == 5)
        {
            system("cls");
            printHeader();
            bossLogo();
            giveBonus(employeeId, employeeSalary, employeeName, employeeCount);
            system("cls");
        }
        else if (select2 == 6)
        {
            system("cls");
            printHeader();
            bossLogo();
            fireEmployee(employeeId, employeeName, employeeDepartment, employeeSalary, employeeCount);
            system("cls");
        }
        else if (select2 == 7)
        {
            system("cls");
            printHeader();
            bossLogo();
            exitlogin();
            system("cls");
        }
    }
}
int bossMenu()
{
    system("cls");
    int select2;
    bool isValidInput = false;
    printHeader();
    do
    {
        bossLogo();
        gotoxy(40, 18);
        cout << "1. Add Employees" << endl;
        gotoxy(40, 19);
        cout << "2. View Employees" << endl;
        gotoxy(40, 20);
        cout << "3. View Total Salary Of Employees" << endl;
        gotoxy(40, 21);
        cout << "4. View Average Salary Of Employees" << endl;
        gotoxy(40, 22);
        cout << "5. Give Bonus " << endl;
        gotoxy(40, 23);
        cout << "6. Fire Employees " << endl;
        gotoxy(40, 24);
        cout << "7. Exit " << endl;
        gotoxy(40, 25);
        cout << "Enter your choice: ";
        if (!(cin >> select2))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("pause");
        }
        else if (select2 < 1 || select2 > 7)
        {
            system("pause");
        }
        else
        {
            isValidInput = true;
        }

    } while (!isValidInput);
    return select2;
}
int employee(string roll, int &employeeCount, string employeeName[], string employeeId[], string employeeSalary[], string employeeDepartment[])
{
    const int arrSize = 100;
    string yearsWorkeds[arrSize];
    string namEs, ids, dps, salarys;
    int select3 = 0;
    system("cls");
    printHeader();
    employeeLogo();
    while (select3 != 5)
    {
        select3 = employeeMenu();
        if (select3 == 1)
        {
            system("cls");
            printHeader();
            employeeLogo();
            checkStatus(employeeName, employeeId, employeeCount);
            system("cls");
        }
        else if (select3 == 2)
        {
            system("cls");
            printHeader();
            employeeLogo();
            string id;
            cout << "Enter id to check Salary: ";
            cin >> id;
            displaySalary(employeeId, employeeSalary, employeeCount, id);
            system("cls");
        }
        else if (select3 == 3)
        {
            system("cls");
            printHeader();
            employeeLogo();
            displayEmployee(employeeName, employeeId, employeeDepartment, employeeCount);
            system("cls");
        }
        else if (select3 == 4)
        {
            system("cls");
            printHeader();
            employeeLogo();
            string id;
            cout << "Enter id to check Salary: ";
            cin >> id;
            calculateAndDisplayBonus(employeeId, employeeSalary, employeeCount, id);
            system("cls");
        }
        else if (select3 == 5)
        {
            system("cls");
            printHeader();
            employeeLogo();
            exitlogin();
            system("cls");
        }
    }
    return 0;
}
int employeeMenu()
{
    system("cls");
    int select3;
    bool isValidInput = false;
    printHeader();
    do
    {
        employeeLogo();
        gotoxy(40, 19);
        cout << "1. Check Status " << endl;
        gotoxy(40, 20);
        cout << "2. View Salary Status " << endl;
        gotoxy(40, 21);
        cout << "3. Update Work " << endl;
        gotoxy(40, 22);
        cout << "4. View Bonus " << endl;
        gotoxy(40, 23);
        cout << "5. Exit " << endl;
        gotoxy(40, 24);
        cout << "Enter your choice: ";
        cin >> select3;

        if (cin.fail() || select3 < 1 || select3 > 5)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 5." << endl;
            system("pause");
        }
        else
        {
            isValidInput = true;
        }
    } while (!isValidInput);
    return select3;
}
void checkStatus(string employeeName[], string employeeId[], int studentCount)
{
    string name, id;
    cout << "Enter Your Name: ";
    cin.ignore(); // Ignore any newline characters in the buffer
    getline(cin, name);
    cout << "Enter Your Employee ID: ";
    cin >> id;
    bool employeeFound = false;
    for (int i = 0; i < studentCount; ++i)
    {
        if (employeeName[i] == name && employeeId[i] == id)
        {
            cout << "\nEmployee Status: Hired" << endl;
            employeeFound = true;
            break;
        }
    }
    if (!employeeFound)
    {
        cout << "\nEmployee Status: Not Hired" << endl;
    }
    system("pause");
}
void displaySalary(string employeeId[], string employeeSalary[], int ecount, string id)
{
    bool employeeFound = false;
    for (int i = 0; i < ecount; ++i)
    {
        if (employeeId[i] == id)
        {
            cout << "Employee ID: " << id << endl;
            cout << "Salary: " << employeeSalary[i] << endl;
            employeeFound = true;
            break;
        }
    }
    if (!employeeFound)
    {
        cout << "Employee with ID " << id << " not found." << endl;
    }
    system("pause");
}
void calculateAndDisplayBonus(string employeeId[], string employeeSalary[], int employeeCount, string id)
{
    bool employeeFound = false;
    for (int i = 0; i < employeeCount; ++i)
    {
        if (employeeId[i] == id)
        {
            cout << "Employee ID: " << id << endl;
            float salary = stof(employeeSalary[i]);
            float bonus = 0;
            if (salary > 50000)
            {
                bonus = 0.1 * salary; // 10% bonus if salary is greater than 50000
                cout << "Bonus: " << bonus << endl;
                cout << "Original Salary: " << salary << endl;
                cout << "Salary with Bonus: " << salary + bonus << endl;
            }
            else
            {
                cout << "No Bonus. Original Salary: " << salary << endl;
            }
            employeeFound = true;
            break;
        }
    }

    if (!employeeFound)
    {
        cout << "Employee with ID " << id << " not found." << endl;
    }
    system("pause");
}
void bossLogo()
{
    gotoxy(8, 12);
    cout << "    ____                    " << endl;
    gotoxy(8, 13);
    cout << "   / __ )____  __________   " << endl;
    gotoxy(8, 14);
    cout << "  / __  / __ \\/ ___/ ___/  " << endl;
    gotoxy(8, 15);
    cout << " / /_/ / /_/ (__  |__  )    " << endl;
    gotoxy(8, 16);
    cout << "/_____/\\____/____/____/    " << endl;
}
bool addEmployee(string namE, string id, string dp, string salary, string employeeName[], string employeeId[], string employeeDepartment[], string employeeSalary[], int &studentCount, int arrSize)
{
    for (int index = 0; index < studentCount; index++)
    {
        if (employeeId[index] == id)
        {
            cout << "Employee with ID " << id << " already exists." << endl;
            return false;
        }
    }
    if (studentCount < arrSize)
    {
        employeeName[studentCount] = namE;
        employeeId[studentCount] = id;
        employeeDepartment[studentCount] = dp;
        employeeSalary[studentCount] = salary;
        studentCount++;
        cout << "Employee added successfully. Total employees: " << studentCount << endl;
        return true;
    }
    else
    {
        cout << "Employee is not added. Array is full." << endl;
        return false;
    }
}
void displayEmployee(string employeeName[], string employeeId[], string employeeDepartment[], int studentCount)
{
    if (studentCount > 0)
    {
        for (int x = 0; x < studentCount; x++)
        {
            cout << "Employee Name: " << employeeName[x] << endl;
            cout << "Employee Id: " << employeeId[x] << endl;
            cout << "Employee Department: " << employeeDepartment[x] << endl;
            cout << endl;
        }
    }
    else
        cout << "No Employee to display.";
    system("pause");
}
void employeeInfo(string employeeId[], string employeeDepartment[], int studentCount)
{
    string yearsWorked[100];
    string id;
    bool found = false;

    cout << "Enter Employee ID: ";
    cin >> id;

    for (int i = 0; i < studentCount; ++i)
    {
        if (employeeId[i] == id)
        {
            cout << "\nEmployee Department: " << employeeDepartment[i] << endl;
            cout << "Enter number of years: ";
            cin >> yearsWorked[i];
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Employee with ID " << id << " not found." << endl;
    }

    system("pause");
}
bool isNumeric(const string &str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (!isdigit(str[i]))
        {
            return false;
        }
    }
    return true;
}

void averageSalary(string employeeSalary[], int studentCount)
{
    double sum = 0;
    double average;
    if (studentCount > 0)
    {
        for (int l = 0; l < studentCount; l++)
        {
            string salaryString = employeeSalary[l];
            if (isNumeric(salaryString))
            {
                sum += stod(salaryString);
            }
            else
            {
                cout << "Invalid input for salary at index " << l << ": " << salaryString << endl;
            }
        }
        if (sum != 0)
        {
            average = sum / studentCount;
            cout << "Average Salary: " << average << endl;
        }
        else
        {
            cout << "No valid salaries to calculate average." << endl;
        }
    }
    else

    {
        cout << "No employees to calculate average salary." << endl;
    }
    system("pause");
}
void increaseSalary(string employeeId[], string employeeSalary[], int studentCount)
{
    string targetId;
    int increasePercentage;
    bool employeeFound = false;
    cout << "Enter Employee ID to check and increase salary: ";
    cin >> targetId;
    for (int i = 0; i < studentCount; i++)
    {
        if (employeeId[i] == targetId)
        {
            employeeFound = true;
            string salaryString = employeeSalary[i];
            if (isNumeric(salaryString))
            {
                float currentSalary = stof(salaryString);
                cout << "Employee ID: " << employeeId[i] << endl;
                cout << "Current Salary: " << currentSalary << endl;
                cout << "Enter the percentage increase for salary: ";
                cin >> increasePercentage;
                cout << "Enter the joining year: ";
                string year;
                 do {
                    cout << "Enter the joining year (four digits): ";
                    cin >> year;
                } while (year.length() != 4 || !isNumeric(year));
                cin >> year;
                float years = stof(year);
                years = 2023 - years;
                if (years >= 5)
                {
                    float increaseAmount = (currentSalary * increasePercentage) / 100;
                    float newSalary = currentSalary + increaseAmount;
                    employeeSalary[i] = to_string(newSalary);

                    cout << "Salary increased to: " << newSalary << endl;
                }
                else
                {
                    cout << "No salary increase as the employee has not worked for the required number of years." << endl;
                }
            }
            else
            {
                cout << "Invalid salary format for employee: " << employeeId[i] << endl;
            }
        }
    }
    if (!employeeFound)
    {
        cout << "Employee with ID " << targetId << " not found." << endl;
    }
    system("pause");
}
void checkTask(string employeeId[], string employeeName[], int employeeCount)
{
    string id;
    cout << "Enter Employee ID: ";
    cin >> id;

    int employeeIndex = -1; // Assume the employee is not found

    for (int i = 0; i < employeeCount; ++i)
    {
        if (employeeId[i] == id)
        {
            employeeIndex = i;
            break;
        }
    }

    if (employeeIndex != -1)
    {
        cout << "\nEmployee Name: " << employeeName[employeeIndex] << endl;

        int task;
        cout << "Have you done tasks (1=Yes, 0=No)? ";
        cin >> task;

        if (task == 1)
            cout << "Tasks done successfully." << endl;
        else if (task == 0)
            cout << "Warning! Tasks not done." << endl;
        else
            cout << "Invalid input for task. Please enter 1 for Yes or 0 for No." << endl;
    }
    else
    {
        cout << "Employee with ID " << id << " not found." << endl;
    }

    system("pause");
}
void exitP()
{
    cout << "Have a nice day ";
    getch();
}
void totalSalary(string employeeSalary[], int studentCount)
{
    long double sum = 0;
    long double total;

    for (int l = 0; l < studentCount; l++){
    string salaryString = employeeSalary[l];

        if (isNumeric(salaryString)) 
    {
        sum += stold(employeeSalary[l]);
    }
     else {
            cout << "Invalid salary format for employee " << l << ": " << salaryString << endl;  }
    }
    if (studentCount > 0)
    {
        total = sum;
        cout << "Total Salary: " << total << endl;
    }
    else
    {
        cout << "No employees to calculate Total salary." << endl;
    }
    system("pause");
}
void giveBonus(string employeeId[], string employeeSalary[], string employeeName[], int studentCount)
{
    
        string taskCompleted;
        string id;
        cout << "Enter Employee ID to check and give bonus: ";
        cin >> id;

        bool employeeFound = false;

        for (int i = 0; i < studentCount; i++)
        {
            if (employeeId[i] == id)
            {
                employeeFound = true;
                cout << "Is Employee " << employeeName[i] << " completed tasks (1 for Yes and 0 for No ): ";
                cin >> taskCompleted;
                int taskCom = stoi(taskCompleted);
                if (taskCom == 1)
                {
                    // Bonus for completing tasks
                    if (isNumeric(employeeSalary[i])) {
                    float currentSalary = stof(employeeSalary[i]);
                    float bonusAmount = 0.1 * currentSalary; // 10% bonus
                    float newSalary = currentSalary + bonusAmount;
                    employeeSalary[i] = to_string(newSalary);
                    cout << "Bonus given successfully. New salary: " << newSalary << endl;
                }
                else
                {
                    cout << "No bonus given as the employee has not completed tasks." << endl;
                }
                }
                else {
                cout << "Invalid input for task completion. Please enter 1 for Yes or 0 for No." << endl;
            }
            
        }
        if (!employeeFound)
        {
            cout << "Employee with ID " << id << " not found." << endl;
        }
        system("pause");
    }
}
void exitlogin()
{
    cout << "Thanks for visiting. ";
    getch();
    const int arrsize = 100;
    string userName[arrsize];
    string userPassword[arrsize];
    string userRole[arrsize];
    static int emCount;
    const int arrSize = 100;
    string employeeName[arrSize];
    string employeeId[arrSize];
    string employeeDepartment[arrSize];
    string employeeSalary[arrSize];
    int userCount = 0;
    int loginOption = 0;
    system("cls");
    while (loginOption != 3)
    {
        loginOption = loginPage();
        {
            if (loginOption == 1)
            {

                system("cls");
                string name;
                string password;
                string role;
                printHeader();
                logIn();
                gotoxy(45, 15);
                cout << "Enter your Name: " << endl;
                cin >> name;
                gotoxy(45, 16);
                cout << "Enter your Password: " << endl;
                cin >> password;
                role = signIn(name, password, userName, userPassword, userRole, userCount);

                if (role == "manager" || role == "Manager")
                    manager(role, emCount, employeeName, employeeId, employeeSalary, employeeDepartment);
                else if (role == "boss" || role == "Boss")
                    boss(role, emCount, employeeName, employeeId, employeeSalary, employeeDepartment);
                else if (role == "employee" || role == "Employee")
                    employee(role, emCount, employeeName, employeeId, employeeSalary, employeeDepartment);
                else
                {
                    cout << "User not found. Please try again." << endl;
                    system("pause");
                    system("cls");
                }
            }

            else if (loginOption == 2)
            {
                system("cls");
                string name;
                string password;
                string role;
                printHeader();
                signUp();
                gotoxy(45, 15);
                cout << "1. User name: ";
                cin >> name;
                gotoxy(45, 16);
                cout << "2. User Password: ";
                cin >> password;
                gotoxy(45, 17);
                cout << "3. Role (Boss, Manager, Employee): ";
                cin >> role;
                bool isValid = signUpMe(name, password, role, userName, userPassword, userRole, userCount, arrsize);
                if (isValid)
                {
                    cout << "Signed Up Successfully" << endl;
                }
                if (!isValid)
                {
                    cout << "Warning! Signed Up not Successfully" << endl;
                }
                system("pause");
                system("cls");
            }

            if (loginOption == 3)
            {
                exitP();
            }
        }
    }
}
void fireEmployee(string employeeId[], string employeeName[], string employeeDepartment[], string employeeSalary[], int &studentCount)
{
    string idToRemove;
    cout << "Enter the ID of the employee to be fired: ";
    cin >> idToRemove;

    bool employeeFound = false;
    for (int i = 0; i < studentCount; i++)
    {
        if (employeeId[i] == idToRemove)
        {
            for (int j = i; j < studentCount - 1; j++)
            {
                employeeId[j] = employeeId[j + 1];
                employeeName[j] = employeeName[j + 1];
                employeeDepartment[j] = employeeDepartment[j + 1];
                employeeSalary[j] = employeeSalary[j + 1];
            }
            studentCount--;

            cout << "Employee with ID " << idToRemove << " has been fired." << endl;
            employeeFound = true;
            break;
        }
    }

    if (!employeeFound)
    {
        cout << "Employee with ID " << idToRemove << " not found." << endl;
    }

    system("pause");
}
void employeeLogo()
{
    gotoxy(8, 13);
    cout << "    ________  _______  __    ______  ______________      " << endl;
    gotoxy(8, 14);
    cout << "   / ____/  |/  / __ \\/ /   / __ \\ \\/ / ____/ ____/   " << endl;
    gotoxy(8, 15);
    cout << "  / __/ / /\\_/ / /_/ / /   / / / /\\  / __/ / __/       " << endl;
    gotoxy(8, 16);
    cout << " / /___/ /  / / ____/ /___/ /_/ / / / /___/ /___         " << endl;
    gotoxy(8, 17);
    cout << "/_____/_/  /_/_/   /_____/\\____/ /_/_____/_____/        " << endl;
}
void logo()
{
    system("cls");
    printHeader();
    system("Color 0B");
    welcome();
    gotoxy(35, 14);
    cout << "*********************************************************" << endl;
    gotoxy(35, 15);
    cout << "****                      @@            /%           ****" << endl;
    gotoxy(35, 16);
    cout << "***                    |@@@@\\          /%             ***" << endl;
    gotoxy(35, 17);
    cout << "***                   _|@@@@\\\\__oooooo/%__            ***" << endl;
    gotoxy(35, 18);
    cout << "**                      |@@  |      ||                 **" << endl;
    gotoxy(35, 19);
    cout << "***                     | @@ |      ||                ***" << endl;
    gotoxy(35, 20);
    cout << "****                    O  @@       ||               ****" << endl;
    gotoxy(35, 21);
    cout << "*********************************************************" << endl;
    Sleep(2000);
}