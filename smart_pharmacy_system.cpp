#include <iostream>
#include <string>
#include <ctime>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

// [Keep all struct definitions the same]
struct Date {
    int day;
    int month;
    int year;
};

struct Supplier {
    int Id;
    string name;
    string email;
    string phoneNum;
    string address;
};

struct Manager {
    int ID;
    string username;
    string password;
};

struct Pharmacist {
    int ID;
    string username;
    string password;
    double totalsalesamount;
};

struct Medicine {
    int medicineID;
    string medicinename;
    string Category;
    Date expirydate;
    double price;
    int stockquantity;
};

struct Bill {
    int ID;
    string PharmacistName;
    string CustomerName;
    int ArrayofMedicinesSold[100];
    double TotalPrice;
    Date dt;
};

// [Keep all global variables the same]
string ausername;
const int MAX_MEDICINES = 100;
int numMedicine = 50;
Medicine MedicineArray[MAX_MEDICINES] = {
    // Pain Relief & Anti-inflammatory
    {1, "Panadol", "Analgesic", {15, 6, 2027}, 15.50, 100},
    {2, "Brufen", "Analgesic", {20, 5, 2028}, 25.00, 80},
    {3, "Aspirin", "Analgesic", {10, 10, 2026}, 10.00, 200},
    {4, "Voltaren", "Analgesic", {12, 12, 2026}, 45.00, 60},
    {5, "Naproxen", "Analgesic", {5, 4, 2027}, 35.00, 45}, 
    {6, "Celebrex", "Analgesic", {14, 2, 2026}, 90.00, 30}, 

    // Antibiotics
    {7, "Amoxicillin", "Antibiotic", {10, 12, 2025}, 45.00, 50},
    {8, "Augmentin", "Antibiotic", {15, 1, 2026}, 110.00, 40}, 
    {9, "Zithromax", "Antibiotic", {22, 6, 2026}, 85.00, 25}, 
    {10, "Ciprofloxacin", "Antibiotic", {30, 3, 2027}, 55.00, 35}, 
    {11, "Doxycycline", "Antibiotic", {11, 11, 2025}, 40.00, 55},
    {12, "Clarithromycin", "Antibiotic", {19, 7, 2026}, 75.00, 20}, 
    {13, "Keflex", "Antibiotic", {4, 5, 2027}, 60.00, 30}, 

    // Allergy & Respiratory
    {14, "Cetirizine", "Antihistamine", {5, 3, 2026}, 12.00, 120}, 
    {15, "Claritin", "Antihistamine", {1, 1, 2027}, 22.00, 100}, 
    {16, "Allegra", "Antihistamine", {15, 5, 2026}, 30.00, 70}, 
    {17, "Ventolin", "Bronchodilator", {20, 8, 2028}, 55.00, 40}, 
    {18, "Flonase", "Nasal Spray", {10, 10, 2026}, 40.00, 50},
    {19, "Singulair", "Asthma", {12, 9, 2027}, 95.00, 25}, 

    // Digestive System
    {20, "Gaviscon", "Antacid", {30, 11, 2026}, 35.00, 60},
    {21, "Nexium", "PPI", {18, 4, 2027}, 120.00, 40}, 
    {22, "Omeprazole", "PPI", {25, 1, 2028}, 50.00, 90}, 
    {23, "Zantac", "Antacid", {14, 6, 2026}, 28.00, 65}, 
    {24, "Pepto-Bismol", "Antidiarrheal", {2, 2, 2027}, 45.00, 30}, 
    {25, "Motilium", "Antiemetic", {10, 10, 2026}, 32.00, 2},

    // Cardiovascular
    {26, "Lipitor", "Statin", {5, 5, 2027}, 150.00, 40},
    {27, "Concor", "Beta-Blocker", {12, 12, 2026}, 45.00, 100},
    {28, "Lasix", "Diuretic", {30, 8, 2026}, 15.00, 150}, 
    {29, "Plavix", "Antiplatelet", {19, 3, 2027}, 180.00, 20}, 
    {30, "Crestor", "Statin", {22, 11, 2026}, 140.00, 35},
    {31, "Norvasc", "Calcium Blocker", {8, 7, 2027}, 65.00, 4}, 
    {32, "Zestril", "ACE Inhibitor", {15, 4, 2026}, 40.00, 60}, 

    // Diabetes Management
    {33, "Glucophage", "Antidiabetic", {1, 1, 2028}, 25.00, 200}, 
    {34, "Januvia", "Antidiabetic", {10, 5, 2027}, 210.00, 1}, 
    {35, "Diamicron", "Antidiabetic", {18, 9, 2026}, 55.00, 80}, 
    {36, "Victoza", "Antidiabetic", {12, 12, 2025}, 450.00, 10},

    // Mental Health
    {37, "Xanax", "Anxiolytic", {5, 6, 2026}, 70.00, 30}, 
    {38, "Lexapro", "Antidepressant", {14, 8, 2027}, 110.00, 2}, 
    {39, "Prozac", "Antidepressant", {20, 1, 2027}, 95.00, 35}, 
    {40, "Lyrica", "Anticonvulsant", {11, 11, 2026}, 160.00, 25},
    {41, "Neurontin", "Anticonvulsant", {25, 3, 2027}, 80.00, 45}, 

    // Vitamins
    {42, "Centrum", "Vitamin", {30, 12, 2028}, 150.00, 50},
    {43, "Vitamin C", "Vitamin", {15, 10, 2027}, 40.00, 200},
    {44, "Neurobion", "Vitamin B", {1, 5, 2027}, 35.00, 100}, 
    {45, "Omega 3", "Supplement", {10, 8, 2026}, 120.00, 3}, 

    // Miscellaneous
    {46, "Solpadeine", "Analgesic", {14, 4, 2027}, 38.00, 75},
    {47, "Otrivin", "Nasal Decongestant", {19, 9, 2026}, 22.00, 90},
    {48, "Betadine", "Antiseptic", {5, 1, 2029}, 45.00, 40}, 
    {49, "Daktarin", "Antifungal", {12, 11, 2026}, 30.00, 50},
    {50, "Cataflam", "Analgesic", {25, 7, 2027}, 42.00, 4} 
};

const int MAX_PHARMACISTS = 15;
int numPharmacist = 5;
Pharmacist pharmacists[MAX_PHARMACISTS] = {
    {1, "Ahmed", "A123", 104.50},
    {2, "Ali", "B456", 25.00},
    {3, "Mona", "M789", 0.0},
    {4, "Hoda", "H101", 35.00},
    {5, "Samer", "S202", 57.00}
};


const int MAX_MANAGERS = 100;
int numManager = 3;
Manager managers[MAX_MANAGERS] = {
{1,"Omar","ASU123"},
{2,"Ahmed","ASU456"},
{3,"Sara","ASU789"}
};

const int maxAttempts = 3;
const int MAX_BILLS = 100;
int numBills = 5;
Bill bills[MAX_BILLS] = {
    {1, "Ahmed", "John Doe", {3, 0, 1}, 56.50, {10, 10, 2024}},
    {2, "Ali", "Jane Smith", {0, 1}, 25.00, {11, 10, 2024}},
    {3, "Ahmed", "Robert Brown", {2, 1}, 48.00, {12, 10, 2024}},
    {4, "Hoda", "Emily Davis", {0, 0, 0, 0, 1}, 35.00, {13, 10, 2024}},
    {5, "Samer", "Michael Wilson", {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1}, 57.00, {14, 10, 2024}}
};

const int numSuppliers = 5;
Supplier suppliers[numSuppliers] = {
    {1, "PharmaCorp", "sales@pharmacorp.com", "011-222-333", "Industrial Zone, Cairo"},
    {2, "MediSupply", "info@medisupply.net", "012-333-444", "Downtown, Alexandria"},
    {3, "GlobalHealth", "contact@globalhealth.org", "010-444-555", "Maadi, Cairo"},
    {4, "QuickMeds", "orders@quickmeds.com", "015-555-666", "Giza District"},
    {5, "BioCure", "support@biocure.com", "011-666-777", "New Cairo"}
};

// [Function prototypes]
void mainmenu();
void managermenu();
void pharmacistLogin(Pharmacist pharmacists[], int numpharmacists, int maxattempts);
void managerlogin(Manager managers[]);
void ADDmedicine(Medicine Medicine[], int& numMedicine);
int lowstockalert(Medicine medicines[], int numMedicines);
void lowstockreport(Medicine medicines[], int numMedicines);
void pharmacistMenu();
void checkprice();
void logout();
int Discount(int totalbill);
void OutputMedicineDetails(const Medicine MedicineArray[], int index);
bool searchMedicinebyName(const Medicine MedicineArray[], int numMedicine, string MedicineName);
bool searchMedicinebyNameReturnsIndex(const Medicine MedicineArray[], int numMedicine, string MedicineName, int& foundIndex);
void writeBills(Bill bills[], int count, const string& filename);
void writeMedicine(Medicine medicines[], int count, const string& filename);
void writePharmacists(Pharmacist pharmacists[], int count, const string& filename);
int readPharmacists(Pharmacist pharmacists[], int maxSize, const string& filename);
void writeManagers(Manager managers[], int count, const string& filename);
int readManagers(Manager managers[], int maxSize, const string& filename);
void exitProgram();


// ==================== UTILITY FUNCTIONS ====================

void printLine(char ch = '=', int length = 80) {
    for (int i = 0; i < length; i++) {
        cout << ch;
    }
    cout << endl;
}

void printHeader(const string& title) {
    cout << "\n";
    printLine('=', 80);
    cout << "|" << setw(40 + title.length() / 2) << title << setw(40 - title.length() / 2) << "|" << endl;
    printLine('=', 80);
    cout << endl;
}

void printSubHeader(const string& subtitle) {
    cout << "\n";
    printLine('-', 80);
    cout << "  " << subtitle << endl;
    printLine('-', 80);
}

// ==================== VIEW TOTAL SALES ====================

void viewTotalSales(const Pharmacist pharmacists[], int numPharmacists, int numbills, const Bill bills[], const Medicine medicines[], int numMedicines) {
    printHeader("TOTAL SALES REPORT");

    double grandTotalSales = 0.0;

    cout << left << setw(15) << "Pharmacist ID"
        << setw(20) << "Username"
        << right << setw(20) << "Total Sales (LE)" << endl;
    printLine('-', 80);

    for (int i = 0; i < numPharmacists; i++) {
        double sales = pharmacists[i].totalsalesamount;
        grandTotalSales += sales;

        cout << left << setw(15) << pharmacists[i].ID
            << setw(20) << pharmacists[i].username
            << right << setw(20) << fixed << setprecision(2) << sales << endl;
    }

    printLine('=', 80);
    cout << left << setw(35) << "GRAND TOTAL SALES:"
        << right << setw(45) << fixed << setprecision(2) << grandTotalSales << " LE" << endl;
    printLine('=', 80);

    // Display bills
    cout << "\n\n";
    printSubHeader("DETAILED BILL INFORMATION");

    for (int i = 0; i < numbills; i++) {
        if (bills[i].TotalPrice > 0) {
            cout << "\n";
            printLine('-', 80);
            cout << "  BILL ID: " << bills[i].ID << endl;
            cout << "  Pharmacist: " << bills[i].PharmacistName
                << "  |  Customer: " << bills[i].CustomerName
                << "  |  Date: " << bills[i].dt.day << "/" << bills[i].dt.month << "/" << bills[i].dt.year << endl;
            printLine('-', 80);

            cout << left << setw(10) << "Med No."
                << setw(25) << "Product Name"
                << right << setw(15) << "Qty Sold"
                << setw(20) << "Total Price" << endl;
            printLine('-', 80);

            for (int j = 0; j < numMedicines; j++) {
                if (bills[i].ArrayofMedicinesSold[j] > 0) {
                    double total = bills[i].ArrayofMedicinesSold[j] * medicines[j].price;
                    cout << left << setw(10) << (j + 1)
                        << setw(25) << medicines[j].medicinename
                        << right << setw(15) << bills[i].ArrayofMedicinesSold[j]
                        << setw(17) << fixed << setprecision(2) << total << " LE" << endl;
                }
            }

            printLine('-', 80);
            cout << right << setw(50) << "Bill Total: "
                << setw(17) << fixed << setprecision(2) << bills[i].TotalPrice << " LE" << endl;
            printLine('-', 80);
        }
    }

    cout << "\n\nPress Enter to return to menu...";
    cin.ignore();
    cin.get();
    managermenu();
}

// ==================== MANAGER LOGIN ====================

void managerlogin(Manager managers[]) {
    printHeader("MANAGER LOGIN");

    int attempts;
    int choice2;
    string username;
    string password2;
    string password;
    bool flag2 = false;

    cout << "  [1] Login\n";
    cout << "  [2] Create an account\n\n";
    cout << "  Choice: ";
    cin >> choice2;

    if (choice2 == 1) {
        cout << "\n  Username: ";
        cin >> username;
        cout << "  Password: ";
        cin >> password;

        for (int i = 0; i < numManager; i++) {
            if (username == managers[i].username && password == managers[i].password) {
                flag2 = true;
            }
        }

        if (flag2 == true) {
            printLine('=', 80);
            cout << "\n   Login successful! Welcome, Boss!\n";
            printLine('=', 80);
            managermenu();
        }
        else {
            attempts = 3;
            while (attempts > 0 && flag2 == false) {
                cout << "\n   Invalid credentials. Try again.\n";
                cout << "  Attempts remaining: " << attempts << "\n\n";

                cout << "  Username: ";
                cin >> username;
                cout << "  Password: ";
                cin >> password;

                for (int i = 0; i < numManager; i++) {
                    if (username == managers[i].username && password == managers[i].password) {
                        flag2 = true;
                    }
                }

                attempts--;

                if (attempts == 0 && flag2 == false) {
                    cout << "\n   Login failed. Returning to main menu...\n";
                    mainmenu();
                    break;
                }
                else if (flag2 == true) {
                    printLine('=', 80);
                    cout << "\n   Login successful! Welcome, Boss!\n";
                    printLine('=', 80);
                    managermenu();
                }
            }
        }
    }
    else if (choice2 == 2) {
        printSubHeader("CREATE NEW MANAGER ACCOUNT");

        cout << "\n  Enter username: ";
        cin >> username;
        cout << "  Enter password: ";
        cin >> password;
        cout << "  Confirm password: ";
        cin >> password2;

        while (password != password2) {
            cout << "\n   Passwords do not match. Try again.\n";
            cout << "  Enter password: ";
            cin >> password;
            cout << "  Confirm password: ";
            cin >> password2;
        }

        managers[numManager].username = username;
        managers[numManager].password = password;
        managers[numManager].ID = (managers[numManager - 1].ID) + 1;
        numManager++;

        // SAVE MANAGERS TO FILE
        writeManagers(managers, numManager, "managers.txt");

        printLine('-', 80);
        cout << "\n   Account created successfully!\n";
        cout << "  ✓ Manager data saved to file!\n";
        printLine('-', 80);

        managermenu();
    }
}

// ==================== MANAGER MENU ====================

void managermenu() {
    printHeader("MANAGER MENU");

    if (lowstockalert(MedicineArray, numMedicine) == 1) {
        cout << "   WARNING: Low stock items detected!\n\n";
    }

    int choice3;
    int choice4;

    cout << "  [1] Add/Edit Stock\n";
    cout << "  [2] View Reports\n";
    cout << "  [3] Logout\n";
    cout << "  [4] Exit Program\n\n";
    cout << "  Choice: ";
    cin >> choice3;

    while (choice3 != 1 && choice3 != 2 && choice3 != 3 && choice3 != 4) {
        cout << "   Invalid choice. Try again: ";
        cin >> choice3;
    }

    if (choice3 == 1) {
        ADDmedicine(MedicineArray, numMedicine);
    }
    else if (choice3 == 2) {
        printSubHeader("SELECT REPORT TYPE");

        cout << "\n  [1] Low Stock Report\n";
        cout << "  [2] Total Sales Report\n";
        cout << "  [3] Return to Main Menu\n\n";
        cout << "  Choice: ";
        cin >> choice4;

        while (choice4 != 1 && choice4 != 2 && choice4 != 3) {
            cout << "   Invalid choice. Try again: ";
            cin >> choice4;
        }

        if (choice4 == 1) {
            lowstockreport(MedicineArray, numMedicine);
        }
        else if (choice4 == 2) {
            viewTotalSales(pharmacists, numPharmacist, numBills, bills, MedicineArray, numMedicine);
        }
        else {
            mainmenu();
        }
    }
    else if (choice3 == 3) {
        mainmenu();
    }
    else {
        exitProgram();
    }
}

// ==================== MAIN MENU ====================

void mainmenu() {
    printHeader(" AGZAKHANET JAMBOY MANAGEMENT SYSTEM");
    cout << "JAMBOY refers to the initials of the makers of this program" << endl;
    cout << endl;
    cout << "  [1] Manager Login\n";
    cout << "  [2] Pharmacist Login\n";
    cout << "  [3] Exit Program\n\n";
    cout << "  Choice: ";

    int choice;
    cin >> choice;

    while (choice != 1 && choice != 2 && choice != 3) {
        cout << "  ✗ Invalid choice. Try again: ";
        cin >> choice;
    }

    if (choice == 1) {
        managerlogin(managers);
    }
    else if (choice == 2) {
        pharmacistLogin(pharmacists, numPharmacist, maxAttempts);
    }
    else {
        exitProgram();
    }
}

// ==================== LOW STOCK FUNCTIONS ====================

int lowstockalert(Medicine medicines[], int numMedicines) {
    for (int i = 0; i < numMedicines; i++) {
        if (medicines[i].stockquantity < 5) {
            return 1;
        }
    }
    return 0;
}

void lowstockreport(Medicine medicines[], int numMedicines) {
    printHeader("LOW STOCK REPORT");

    bool aflag = true;

    cout << left << setw(40) << "Medicine Name"
        << right << setw(20) << "Stock Quantity" << endl;
    printLine('-', 80);

    for (int i = 0; i < numMedicines; i++) {
        if (medicines[i].stockquantity < 5) {
            cout << left << setw(40) << medicines[i].medicinename
                << right << setw(20) << medicines[i].stockquantity << endl;
            aflag = false;
        }
    }

    if (aflag == true) {
        cout << "  ✓ No low stock items found.\n";
    }

    printLine('=', 80);
    cout << "\nPress Enter to return to menu...";
    cin.ignore();
    cin.get();
    managermenu();
}

// ==================== PHARMACIST LOGIN ====================

void pharmacistLogin(Pharmacist pharmacists[], int numpharmacists, int maxattempts) {
    printHeader("PHARMACIST LOGIN");

    int attempt = 0;
    bool found = false;

    while (attempt < maxattempts && !found) {
        string username;
        string password;

        cout << "  Username: ";
        cin >> username;
        cout << "  Password: ";
        cin >> password;

        for (int i = 0; i < numpharmacists; i++) {
            if (pharmacists[i].username == username && pharmacists[i].password == password) {
                found = true;
                ausername = username;

                printLine('=', 80);
                cout << "\n   Login successful! Welcome, " << pharmacists[i].username << "!\n";
                printLine('=', 80);

                pharmacistMenu();
                break;
            }
        }

        if (!found) {
            attempt++;
            cout << "\n   Invalid credentials.\n";

            if (attempt < maxattempts) {
                cout << "  Attempts remaining: " << (maxattempts - attempt) << "\n\n";
            }
            else {
                cout << "\n   Maximum attempts exceeded. Access denied.\n";
                mainmenu();
            }
        }
    }
}

// ==================== SEARCH FUNCTIONS ====================

int ChooseSearchMethod() {
    printSubHeader("SEARCH METHOD");

    int choosesearch;
    cout << "\n  [1] Search by Name\n";
    cout << "  [2] Search by Category\n\n";
    cout << "  Choice: ";
    cin >> choosesearch;

    while (choosesearch != 1 && choosesearch != 2) {
        cout << "   Invalid choice. Try again: ";
        cin >> choosesearch;
    }

    return choosesearch;
}

void OutputMedicineDetails(const Medicine MedicineArray[], int index) {
    printLine('-', 80);
    cout << "  Medicine ID:       " << MedicineArray[index].medicineID << endl;
    cout << "  Name:              " << MedicineArray[index].medicinename << endl;
    cout << "  Category:          " << MedicineArray[index].Category << endl;
    cout << "  Expiry Date:       " << MedicineArray[index].expirydate.day << "/"
        << MedicineArray[index].expirydate.month << "/" << MedicineArray[index].expirydate.year << endl;
    cout << "  Price:             " << fixed << setprecision(2) << MedicineArray[index].price << " LE" << endl;
    cout << "  Stock Quantity:    " << MedicineArray[index].stockquantity << endl;
    printLine('-', 80);
}

bool searchMedicinebyNameReturnsIndex(const Medicine MedicineArray[], int numMedicine, string MedicineName, int& foundIndex) {
    for (int i = 0; i < numMedicine; i++) {
        if (MedicineArray[i].medicinename == MedicineName) {
            foundIndex = i;
            return true;
        }
    }
    return false;
}

bool searchMedicinebyName(const Medicine MedicineArray[], int numMedicine, string MedicineName) {
    for (int i = 0; i < numMedicine; i++) {
        if (MedicineArray[i].medicinename == MedicineName) {
            return true;
        }
    }
    return false;
}

void searchMedicinebyNameOutputDetails(const Medicine MedicineArray[], int numMedicine) {
    printHeader("SEARCH MEDICINE BY NAME");

    string MedicineName;
    int indexholder = -1;

    cout << "  Enter medicine name: ";
    cin >> MedicineName;

    bool isfound = searchMedicinebyNameReturnsIndex(MedicineArray, numMedicine, MedicineName, indexholder);

    if (isfound) {
        cout << "\n   Medicine found!\n\n";
        OutputMedicineDetails(MedicineArray, indexholder);
    }
    else {
        cout << "\n   Medicine not found in database.\n";
    }

    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
    pharmacistMenu();
}

void searchMedicinebyCategory(Medicine MedicineArray[], int numMedicine) {
    printHeader("SEARCH MEDICINE BY CATEGORY");

    string Category;
    bool found = false;
    int countmedicinefound = 0;

    cout << "  Enter category: ";
    cin >> Category;
    cout << endl;

    for (int i = 0; i < numMedicine; i++) {
        if (MedicineArray[i].Category == Category) {
            found = true;
            countmedicinefound++;

            cout << "\n  Medicine #" << countmedicinefound << " in this category:\n";
            OutputMedicineDetails(MedicineArray, i);
        }
    }

    if (!found) {
        cout << "   No medicines found in this category.\n";
    }

    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
    pharmacistMenu();
}

// ==================== CHECK PRICE ====================

void checkprice() {
    printHeader("CHECK MEDICINE PRICE");

    string name;
    cout << "  Enter medicine name: ";
    cin >> name;

    bool found = false;
    int n = -1;

    for (int i = 0; i < numMedicine; i++) {
        if (MedicineArray[i].medicinename == name) {
            found = true;
            n = i;
            break;
        }
    }

    if (found) {
        printLine('-', 80);
        cout << "  Medicine Name:  " << MedicineArray[n].medicinename << endl;
        cout << "  Price:          " << fixed << setprecision(2) << MedicineArray[n].price << " LE" << endl;
        printLine('-', 80);
    }
    else {
        cout << "\n   Medicine not found.\n";
    }

    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
    pharmacistMenu();
}

// ==================== LOGOUT ====================

void logout() {
    printLine('=', 80);
    cout << "\n  Logging out...\n";
    printLine('=', 80);
    mainmenu();
}

// ==================== DISCOUNT ====================

int Discount(int totalbill) {
    double discount = 0;

    if (totalbill > 300) {
        discount = totalbill * 0.9;
        cout << "\n   Discount Applied: 10% off\n";
        cout << "  Final amount: " << discount << " LE\n";
    }
    else {
        cout << "\n  No discount applied (minimum 300 LE required)\n";
    }

    return discount;
}

// ==================== BILLING ====================

void bill(int numMedicine, Medicine Medicine[], int& numBills, Bill Bill[], Pharmacist pharmacists[], int numPharmacists) {
    printHeader("CREATE NEW BILL");

    double TotalPrice = 0.0;
    int Quantity[10];
    int NoItems;
    bool quantitycheck;
    string MedicineName[10];

    // Initialize array
    for (int k = 0; k < 100; k++) {
        Bill[numBills].ArrayofMedicinesSold[k] = 0;
    }

    cout << "  Pharmacist: " << ausername << endl;
    cout << "  Customer Name: ";
    cin >> Bill[numBills].CustomerName;
    cout << "  Number of items: ";
    cin >> NoItems;

    printLine('-', 80);

    for (int j = 0; j < NoItems; j++) {
        cout << "\n  === Item " << (j + 1) << " ===" << endl;
        cout << "  Medicine name: ";
        cin >> MedicineName[j];

        while (searchMedicinebyName(Medicine, numMedicine, MedicineName[j]) == 0) {
            cout << "   Not found. Enter valid name: ";
            cin >> MedicineName[j];
        }

        cout << "  Quantity: ";
        cin >> Quantity[j];

        quantitycheck = false;
        while (quantitycheck == false) {
            quantitycheck = true;
            for (int i = 0; i < numMedicine; i++) {
                if (Medicine[i].medicinename == MedicineName[j]) {
                    if (Medicine[i].stockquantity < Quantity[j]) {
                        cout << "   Insufficient stock (" << Medicine[i].stockquantity << " available)\n";
                        cout << "  Enter quantity: ";
                        cin >> Quantity[j];
                        quantitycheck = false;
                    }
                }
            }
        }

        // Process sale
        for (int i = 0; i < numMedicine; i++) {
            if (Medicine[i].medicinename == MedicineName[j]) {
                TotalPrice += Medicine[i].price * Quantity[j];
                Medicine[i].stockquantity -= Quantity[j];
                Bill[numBills].ArrayofMedicinesSold[i] += Quantity[j];

                cout << "   Added: " << Quantity[j] << " x " << MedicineName[j]
                    << " @ " << Medicine[i].price << " LE each\n";
                cout << "    Remaining stock: " << Medicine[i].stockquantity << endl;
            }
        }
    }

    // Finalize bill
    printLine('=', 80);
    cout << "\n  BILL SUMMARY\n";
    printLine('-', 80);

    Bill[numBills].ID = numBills + 1;
    Bill[numBills].PharmacistName = ausername;
    Bill[numBills].dt.day = 21;
    Bill[numBills].dt.month = 12;
    Bill[numBills].dt.year = 2025;

    cout << "  Bill ID:        " << Bill[numBills].ID << endl;
    cout << "  Subtotal:       " << TotalPrice << " LE" << endl;

    int discountedPrice = Discount(TotalPrice);
    if (discountedPrice > 0) {
        Bill[numBills].TotalPrice = discountedPrice;
    }
    else {
        Bill[numBills].TotalPrice = TotalPrice;
    }

    // UPDATE PHARMACIST TOTAL SALES
    for (int i = 0; i < numPharmacists; i++) {
        if (pharmacists[i].username == ausername) {
            pharmacists[i].totalsalesamount += Bill[numBills].TotalPrice;
            cout << "\n   Pharmacist sales updated: " << fixed << setprecision(2)
                << pharmacists[i].totalsalesamount << " LE\n";
            break;
        }
    }

    printLine('=', 80);

    numBills++;

    // Save to files
    writeMedicine(Medicine, numMedicine, "medicine.txt");
    writeBills(bills, numBills, "bill.txt");
    writePharmacists(pharmacists, numPharmacists, "pharmacists.txt");

    cout << "\n   Bill saved successfully!\n";
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();

    pharmacistMenu();
}

// ==================== ADD MEDICINE ====================

void ADDmedicine(Medicine Medicine[], int& numMedicine) {
    printHeader("STOCK MANAGEMENT");

    int choice;
    cout << "  [1] Add New Medicine\n";
    cout << "  [0] Edit Existing Stock\n\n";
    cout << "  Choice: ";
    cin >> choice;

    while (choice != 0 && choice != 1) {
        cout << "   Invalid choice. Try again: ";
        cin >> choice;
    }

    if (choice == 0) {
        // Edit stock
        printSubHeader("EDIT STOCK");

        int editID;
        bool found = false;

        while (!found) {
            cout << "\n  Medicine ID: ";
            cin >> editID;

            for (int i = 0; i < numMedicine; i++) {
                if (Medicine[i].medicineID == editID) {
                    printLine('-', 80);
                    cout << "  Current Details:\n";
                    cout << "  Name:           " << Medicine[i].medicinename << endl;
                    cout << "  Category:       " << Medicine[i].Category << endl;
                    cout << "  Expiry:         " << Medicine[i].expirydate.day << "/"
                        << Medicine[i].expirydate.month << "/" << Medicine[i].expirydate.year << endl;
                    cout << "  Price:          " << Medicine[i].price << " LE" << endl;
                    cout << "  Stock:          " << Medicine[i].stockquantity << endl;
                    printLine('-', 80);

                    int stockquantity;
                    cout << "\n  New stock quantity: ";
                    cin >> stockquantity;

                    while (stockquantity < 0) {
                        cout << "   Invalid (cannot be negative): ";
                        cin >> stockquantity;
                    }

                    Medicine[i].stockquantity = stockquantity;

                    writeMedicine(Medicine, numMedicine, "medicine.txt");

                    cout << "\n   Stock updated successfully!\n";
                    found = true;

                    cout << "\nPress Enter to continue...";
                    cin.ignore();
                    cin.get();
                    managermenu();
                    return;
                }
            }

            if (!found) {
                cout << "   Medicine ID not found. Try again.\n";
            }
        }
    }
    else {
        // Add new medicine
        printSubHeader("ADD NEW MEDICINE");

        int medicineID;
        string medicinename, Category;
        int day, month, year;
        double price;
        int stockquantity;
        medicineID = numMedicine + 1;
        cout << "\n  Medicine ID: " << medicineID << endl;
        cout << "  Name: ";
        cin >> medicinename;
        cout << "  Category: ";
        cin >> Category;
        cout << "  Expiry Day: ";
        cin >> day;
        cout << "  Expiry Month: ";
        cin >> month;
        cout << "  Expiry Year: ";
        cin >> year;
        cout << "  Price (LE): ";
        cin >> price;

        while (price < 0) {
            cout << "   Invalid (cannot be negative): ";
            cin >> price;
        }

        cout << "  Stock Quantity: ";
        cin >> stockquantity;

        while (stockquantity < 0) {
            cout << "   Invalid (cannot be negative): ";
            cin >> stockquantity;
        }

        Medicine[numMedicine] = { medicineID, medicinename, Category, {day, month, year}, price, stockquantity };
        numMedicine++;

        writeMedicine(Medicine, numMedicine, "medicine.txt");

        cout << "\n   Medicine added successfully!\n";

        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
        managermenu();
        return;
    }
}

// ==================== PHARMACIST MENU ====================

void pharmacistMenu() {
    printHeader("PHARMACIST MENU");

    int choice;

    cout << "  [1] Search Medicine\n";
    cout << "  [2] Sell Medicine\n";
    cout << "  [3] Check Item Price\n";
    cout << "  [4] Logout\n";
    cout << "  [5] Exit Program\n\n";
    cout << "  Choice: ";
    cin >> choice;

    while (choice < 1 || choice > 5) {
        cout << "   Invalid choice. Try again: ";
        cin >> choice;
    }

    switch (choice) {
    case 1: {
        int searchMethod = ChooseSearchMethod();
        if (searchMethod == 1) {
            searchMedicinebyNameOutputDetails(MedicineArray, numMedicine);
        }
        else {
            searchMedicinebyCategory(MedicineArray, numMedicine);
        }
        break;
    }
    case 2:
        bill(numMedicine, MedicineArray, numBills, bills, pharmacists, numPharmacist);
        break;
    case 3:
        checkprice();
        break;
    case 4:
        logout();
        break;
    case 5:
        exitProgram();
        break;
    }
}

// ==================== FILE I/O FUNCTIONS ====================

void writeMedicine(Medicine medicines[], int count, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Cannot open file for writing!" << endl;
        return;
    }

    file << count << endl;
    for (int i = 0; i < count; i++) {
        file << medicines[i].medicineID << endl;
        file << medicines[i].medicinename << endl;
        file << medicines[i].Category << endl;
        file << medicines[i].expirydate.day << endl;
        file << medicines[i].expirydate.month << endl;
        file << medicines[i].expirydate.year << endl;
        file << medicines[i].price << endl;
        file << medicines[i].stockquantity << endl;
    }
    file.close();
}

int readMedicines(Medicine medicines[], int maxSize, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        return 0;
    }

    int count;
    file >> count;
    file.ignore();

    if (count > maxSize) {
        file.close();
        return 0;
    }

    for (int i = 0; i < count; i++) {
        file >> medicines[i].medicineID;
        file.ignore();
        getline(file, medicines[i].medicinename);
        getline(file, medicines[i].Category);
        file >> medicines[i].expirydate.day;
        file >> medicines[i].expirydate.month;
        file >> medicines[i].expirydate.year;
        file >> medicines[i].price;
        file >> medicines[i].stockquantity;
        file.ignore();
    }

    file.close();
    return count;
}

void writeBills(Bill bills[], int count, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Cannot open file for writing!" << endl;
        return;
    }

    file << count << endl;
    for (int i = 0; i < count; i++) {
        file << bills[i].ID << endl;
        file << bills[i].PharmacistName << endl;
        file << bills[i].CustomerName << endl;

        for (int j = 0; j < 100; j++) {
            file << bills[i].ArrayofMedicinesSold[j] << " ";
        }
        file << endl;

        file << bills[i].TotalPrice << endl;
        file << bills[i].dt.day << endl;
        file << bills[i].dt.month << endl;
        file << bills[i].dt.year << endl;
    }
    file.close();
}

int readBills(Bill bills[], int maxSize, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        return 0;
    }

    int count;
    file >> count;
    file.ignore();

    if (count > maxSize) {
        file.close();
        return 0;
    }

    for (int i = 0; i < count; i++) {
        file >> bills[i].ID;
        file.ignore();
        getline(file, bills[i].PharmacistName);
        getline(file, bills[i].CustomerName);

        for (int j = 0; j < 100; j++) {
            file >> bills[i].ArrayofMedicinesSold[j];
        }
        file.ignore();

        file >> bills[i].TotalPrice;
        file >> bills[i].dt.day;
        file >> bills[i].dt.month;
        file >> bills[i].dt.year;
        file.ignore();
    }

    file.close();
    return count;
}

void writePharmacists(Pharmacist pharmacists[], int count, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Cannot open file for writing!" << endl;
        return;
    }

    file << count << endl;
    for (int i = 0; i < count; i++) {
        file << pharmacists[i].ID << endl;
        file << pharmacists[i].username << endl;
        file << pharmacists[i].password << endl;
        file << pharmacists[i].totalsalesamount << endl;
    }
    file.close();
}

int readPharmacists(Pharmacist pharmacists[], int maxSize, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        return 0;
    }

    int count;
    file >> count;
    file.ignore();

    if (count > maxSize) {
        file.close();
        return 0;
    }

    for (int i = 0; i < count; i++) {
        file >> pharmacists[i].ID;
        file.ignore();
        getline(file, pharmacists[i].username);
        getline(file, pharmacists[i].password);
        file >> pharmacists[i].totalsalesamount;
        file.ignore();
    }

    file.close();
    return count;
}

void writeManagers(Manager managers[], int count, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Cannot open file for writing!" << endl;
        return;
    }

    file << count << endl;
    for (int i = 0; i < count; i++) {
        file << managers[i].ID << endl;
        file << managers[i].username << endl;
        file << managers[i].password << endl;
    }
    file.close();
}

int readManagers(Manager managers[], int maxSize, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        return 0;
    }

    int count;
    file >> count;
    file.ignore();

    if (count > maxSize) {
        file.close();
        return 0;
    }

    for (int i = 0; i < count; i++) {
        file >> managers[i].ID;
        file.ignore();
        getline(file, managers[i].username);
        getline(file, managers[i].password);
    }

    file.close();
    return count;
}

void exitProgram() {
    printHeader("EXIT PROGRAM");

    char confirm;
    cout << "  Are you sure you want to exit? (y/n): ";
    cin >> confirm;

    if (confirm == 'y' || confirm == 'Y') {
        printLine('-', 80);
        cout << "\n  Saving all data...\n";

        // Save all data before exit
        writeMedicine(MedicineArray, numMedicine, "medicine.txt");
        writeBills(bills, numBills, "bill.txt");
        writePharmacists(pharmacists, numPharmacist, "pharmacists.txt");
        writeManagers(managers, numManager, "managers.txt");

        printLine('-', 80);
        cout << "\n   Medicines saved: " << numMedicine << " records\n";
        cout << "   Bills saved: " << numBills << " records\n";
        cout << "   Pharmacists saved: " << numPharmacist << " records\n";
        cout << "   Managers saved: " << numManager << " records\n";
        printLine('-', 80);
        cout << "\n  Thank you for using Pharmacy Management System.\n";
        cout << "  Goodbye!\n\n";
        printLine('=', 80);

        exit(0);  // Exit the program
    }
    else {
        cout << "\n   Exit cancelled. Returning to menu...\n";
        mainmenu();
    }
}

// ==================== MAIN ====================

int main() {
    
    int loadedMedicinCount = readMedicines(MedicineArray, MAX_MEDICINES, "medicine.txt");
    int loadedBillCount = readBills(bills, MAX_BILLS, "bill.txt");
    int loadedPharmacistCount = readPharmacists(pharmacists, numPharmacist, "pharmacists.txt");
    int loadedManagerCount = readManagers(managers, MAX_MANAGERS, "managers.txt");

    if (loadedMedicinCount > 0) {
        numMedicine = loadedMedicinCount;
    }
    if (loadedBillCount > 0) {
        numBills = loadedBillCount;
    }
    if (loadedPharmacistCount > 0) {
        // Pharmacists loaded successfully
        cout << "Loaded " << loadedPharmacistCount << " pharmacist records.\n";
    }
    if (loadedManagerCount > 0) {
        numManager = loadedManagerCount;
        cout << "Loaded " << loadedManagerCount << " manager records.\n";
    }
   
    mainmenu();

    // This code will only run if the program exits abnormally
    // Normal exit is handled by exitProgram()
    writeMedicine(MedicineArray, numMedicine, "medicine.txt");
    writeBills(bills, numBills, "bill.txt");
    writePharmacists(pharmacists, numPharmacist, "pharmacists.txt");
    writeManagers(managers, numManager, "managers.txt");

    return 0;
}