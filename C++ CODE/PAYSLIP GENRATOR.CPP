#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Employee {
    string id;
    string name;
    string designation;
    string department;
    double basic;
    int daysWorked;
};

Employee emp[100];
int countEmp = 0;

// Convert to CAPS
string toUpper(string str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

// Search by ID
int searchByID(string id) {
    for (int i = 0; i < countEmp; i++) {
        if (emp[i].id == id)
            return i;
    }
    return -1;
}

// Search by Name
int searchByName(string name) {
    for (int i = 0; i < countEmp; i++) {
        if (emp[i].name == name)
            return i;
    }
    return -1;
}

// Display Payslip
void displayPayslip(Employee e, int month, int year) {

    double effectiveBasic = (e.basic / 30) * e.daysWorked;
    double hra = 0.2 * effectiveBasic;
    double medical = 1500;
    double conveyance = 800;

    double gross = effectiveBasic + hra + medical + conveyance;

    double pf = 0.12 * effectiveBasic;
    double esi = 0.0175 * gross;
    double tax = 0.10 * gross;

    double deductions = pf + esi + tax;
    double net = gross - deductions;

    cout << "\n";
    cout << "========================================================\n";
    cout << "                EMPLOYEE PAYSLIP\n";
    cout << "========================================================\n";

    cout << left << setw(25) << "Employee ID" << ": " << e.id << "\n";
    cout << left << setw(25) << "Employee Name" << ": " << e.name << "\n";
    cout << left << setw(25) << "Designation" << ": " << e.designation << "\n";
    cout << left << setw(25) << "Department" << ": " << e.department << "\n";
    cout << left << setw(25) << "Month / Year" << ": " << month << "/" << year << "\n";

    cout << "--------------------------------------------------------\n";
    cout << "                     EARNINGS\n";
    cout << "--------------------------------------------------------\n";

    cout << left << setw(30) << "Effective Basic" << right << setw(10) << fixed << setprecision(2) << effectiveBasic << "\n";
    cout << left << setw(30) << "HRA (20%)" << right << setw(10) << hra << "\n";
    cout << left << setw(30) << "Medical Allowance" << right << setw(10) << medical << "\n";
    cout << left << setw(30) << "Conveyance" << right << setw(10) << conveyance << "\n";

    cout << "--------------------------------------------------------\n";
    cout << left << setw(30) << "GROSS SALARY" << right << setw(10) << gross << "\n";

    cout << "--------------------------------------------------------\n";
    cout << "                    DEDUCTIONS\n";
    cout << "--------------------------------------------------------\n";

    cout << left << setw(30) << "PF (12%)" << right << setw(10) << pf << "\n";
    cout << left << setw(30) << "ESI (1.75%)" << right << setw(10) << esi << "\n";
    cout << left << setw(30) << "Income Tax (10%)" << right << setw(10) << tax << "\n";

    cout << "--------------------------------------------------------\n";
    cout << left << setw(30) << "TOTAL DEDUCTIONS" << right << setw(10) << deductions << "\n";

    cout << "========================================================\n";
    cout << left << setw(30) << "NET SALARY" << right << setw(10) << net << "\n";
    cout << "========================================================\n";

    cout << "         *** THANK YOU ***\n";
    cout << "========================================================\n";
}

int main() {

    // Pre-stored employees
    countEmp = 40;

    emp[0] = {"0439400", "ANITA SHARMA", "PRINCIPAL", "ADMINISTRATION", 75000, 30};
    emp[1] = {"0439401", "RAJESH KUMAR", "HEAD TEACHER", "ADMINISTRATION", 60000, 30};
    emp[2] = {"0439402", "PRIYA VERMA", "MATHEMATICS TEACHER", "SCIENCE", 45000, 28};
    emp[3] = {"0439403", "SUNITA DAS", "SCIENCE TEACHER", "SCIENCE", 44000, 27};
    emp[4] = {"0439404", "AMIT PANDEY", "ENGLISH TEACHER", "ARTS & LANGUAGE", 43000, 30};
    emp[5] = {"0439405", "DEEPA NAIR", "HINDI TEACHER", "ARTS & LANGUAGE", 42000, 29};
    emp[6] = {"0439406", "RAVI GUPTA", "SOCIAL STUDIES TEACHER", "ARTS & LANGUAGE", 41000, 30};
    emp[7] = {"0439407", "MEENA JOSHI", "ART & CRAFT TEACHER", "ARTS & LANGUAGE", 38000, 26};
    emp[8] = {"0439408", "KAVITA SINGH", "MUSIC TEACHER", "ARTS & LANGUAGE", 37000, 30};
    emp[9] = {"0439409", "MOHAN YADAV", "PHYSICAL EDUCATION TEACHER", "SPORTS", 36000, 30};

    emp[10] = {"0439410", "SUMAN MISHRA", "COMPUTER TEACHER", "SCIENCE", 46000, 28};
    emp[11] = {"0439411", "POOJA TIWARI", "EVS TEACHER", "SCIENCE", 40000, 30};
    emp[12] = {"0439412", "RAHUL SAXENA", "DRAWING TEACHER", "ARTS & LANGUAGE", 35000, 25};
    emp[13] = {"0439413", "GEETA CHAUHAN", "DANCE TEACHER", "ARTS & LANGUAGE", 34000, 30};
    emp[14] = {"0439414", "VIKAS SRIVASTAVA", "GK TEACHER", "ARTS & LANGUAGE", 38000, 29};
    emp[15] = {"0439415", "REKHA PATEL", "JUNIOR TEACHER", "SCIENCE", 32000, 30};
    emp[16] = {"0439416", "SURESH THAKUR", "JUNIOR TEACHER", "ARTS & LANGUAGE", 32000, 27};
    emp[17] = {"0439417", "ANJALI DUBEY", "JUNIOR TEACHER", "ARTS & LANGUAGE", 31000, 30};
    emp[18] = {"0439418", "DINESH RAWAT", "JUNIOR TEACHER", "SCIENCE", 31000, 28};
    emp[19] = {"0439419", "SANTOSH KUMAR", "JUNIOR TEACHER", "ARTS & LANGUAGE", 30000, 30};

    emp[20] = {"0439420", "LATA BHATT", "PRE-PRIMARY TEACHER", "PRE-PRIMARY", 33000, 30};
    emp[21] = {"0439421", "HEMA MALHOTRA", "PRE-PRIMARY TEACHER", "PRE-PRIMARY", 33000, 29};
    emp[22] = {"0439422", "USHA TRIPATHI", "PRE-PRIMARY TEACHER", "PRE-PRIMARY", 32000, 30};
    emp[23] = {"0439423", "KAMLA DEVI", "PRE-PRIMARY TEACHER", "PRE-PRIMARY", 31000, 28};
    emp[24] = {"0439424", "NEHA AGARWAL", "PRE-PRIMARY TEACHER", "PRE-PRIMARY", 31000, 30};

    emp[25] = {"0439425", "ARUN SHARMA", "ACCOUNTANT", "ADMINISTRATION", 35000, 30};
    emp[26] = {"0439426", "RAMESH VERMA", "CLERK", "ADMINISTRATION", 28000, 30};
    emp[27] = {"0439427", "SEEMA GUPTA", "RECEPTIONIST", "ADMINISTRATION", 27000, 29};
    emp[28] = {"0439428", "PANKAJ SINGH", "LIBRARIAN", "ADMINISTRATION", 30000, 30};
    emp[29] = {"0439429", "NITIN KAPOOR", "LAB ASSISTANT", "SCIENCE", 26000, 28};

    emp[30] = {"0439430", "BHARAT LAL", "DRIVER", "SUPPORT", 22000, 30};
    emp[31] = {"0439431", "CHANDRA PRAKASH", "SECURITY GUARD", "SUPPORT", 20000, 30};
    emp[32] = {"0439432", "MUNNI DEVI", "COOK", "SUPPORT", 18000, 29};
    emp[33] = {"0439433", "RAMU PRASAD", "PEON", "SUPPORT", 16000, 30};
    emp[34] = {"0439434", "SHANTI BAI", "SWEEPER", "SUPPORT", 15000, 28};
    emp[35] = {"0439435", "GOPAL DAS", "GARDENER", "SUPPORT", 15000, 30};

    emp[36] = {"0439436", "KIRAN REDDY", "ASSISTANT TEACHER", "SCIENCE", 30000, 30};
    emp[37] = {"0439437", "LAKSHMI NARAYAN", "ASSISTANT TEACHER", "ARTS & LANGUAGE", 30000, 29};
    emp[38] = {"0439438", "VENKAT RAO", "OFFICE ASSISTANT", "ADMINISTRATION", 25000, 30};
    emp[39] = {"0439439", "SITA RAM", "HELPER", "SUPPORT", 20000, 28};

    int choice;

    do {
        cout << "\n--- MAIN MENU ---\n";
        cout << "1. Search Payslip\n";
        cout << "2. Add Employee\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int opt, index = -1;

            cout << "\n1. Search by ID\n2. Search by Name\nEnter option: ";
            cin >> opt;

            if (opt == 1) {
                string id;
                cout << "Enter Employee ID: ";
                cin >> id;
                index = searchByID(id);
            } 
            else if (opt == 2) {
                string name;
                cin.ignore();
                cout << "Enter Name: ";
                getline(cin, name);
                name = toUpper(name);
                index = searchByName(name);
            }

            if (index == -1) {
                cout << "Employee not found!\n";
            } else {
                int month, year;

                cout << "Enter Month (1-12): ";
                cin >> month;

                if (month < 1 || month > 12) {
                    cout << "Invalid Month!\n";
                    continue;
                }

                cout << "Enter Year: ";
                cin >> year;

                displayPayslip(emp[index], month, year);

                cin.ignore();
                cout << "Press ENTER to continue...";
                cin.get();
            }

        } 
        else if (choice == 2) {

            if (countEmp >= 100) {
                cout << "Storage Full!\n";
                continue;
            }

            Employee e;

            cout << "Enter Employee ID: ";
            cin >> e.id;

            if (searchByID(e.id) != -1) {
                cout << "ID already exists!\n";
                continue;
            }

            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, e.name);
            e.name = toUpper(e.name);

            cout << "Enter Designation: ";
            getline(cin, e.designation);

            cout << "Enter Department: ";
            getline(cin, e.department);

            cout << "Enter Basic Salary: ";
            cin >> e.basic;

            cout << "Enter Days Worked (1-30): ";
            cin >> e.daysWorked;

            if (e.daysWorked < 1 || e.daysWorked > 30) {
                cout << "Invalid Days!\n";
                continue;
            }

            emp[countEmp++] = e;
            cout << "Employee Added Successfully!\n";
        } 
        else if (choice == 3) {
            cout << "Thank You!\n";
        } 
        else {
            cout << "Invalid Choice!\n";
        }

    } while (choice != 3);

    return 0;
}
