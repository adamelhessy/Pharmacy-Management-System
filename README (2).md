# 💊 Smart Pharmacy Management System

> A C++ console application that helps a pharmacy run day to day: track stock, serve customers, and keep sales records, all from a simple text menu.

---

## 📖 Overview

Smart Pharmacy Management System is a menu-driven program written in C++. It separates the work of **managers** and **pharmacists** through two different logins, keeps an up-to-date medicine inventory, creates customer bills, and saves everything to text files so nothing is lost when the program closes.

---

## ✨ Key Features

| Area | What it does |
| --- | --- |
| 🔐 **Access control** | Separate Manager and Pharmacist logins, with a limit of 3 login attempts |
| 📦 **Inventory** | 50 pre-loaded medicines, add new ones, edit stock by ID |
| ⚠️ **Stock alerts** | Warning when an item falls below 5 units, plus a full low-stock report |
| 🧾 **Billing** | Multi-item bills with live stock checks and an automatic 10% discount on orders over 300 LE |
| 📊 **Reports** | Grand total sales and an itemized bill history per pharmacist |
| 💾 **Persistence** | All data is saved to and loaded from text files automatically |

### Who can do what

**Manager**
- Create accounts
- Add new medicines or edit existing stock
- View the low-stock and total-sales reports

**Pharmacist**
- Search medicines by name or category
- Sell medicine and generate a bill
- Check item prices

---

## 🧱 How It's Built

The program is organized around five `struct` types:

```
Medicine     → medicineID, name, category, expiryDate, price, stockQuantity
Bill         → ID, pharmacistName, customerName, medicinesSold[], totalPrice, date
Pharmacist   → ID, username, password, totalSalesAmount
Manager      → ID, username, password
Supplier     → ID, name, email, phone, address   (stored for reference)
```

### Data files

| File | Purpose |
| --- | --- |
| `medicine.txt` | Medicine inventory |
| `bill.txt` | Transaction records |
| `pharmacists.txt` | Pharmacist accounts and sales totals |
| `managers.txt` | Manager accounts |

---

## 🚀 Quick Start

**Requirements:** any C++ compiler with C++11 support (g++, MSVC, or Clang).

```bash
# Compile
g++ -o pharmacy smart_pharmacy_system.cpp

# Run
./pharmacy          # Linux / macOS
pharmacy.exe        # Windows
```

### Demo accounts

| Role | Username | Password |
| --- | --- | --- |
| Manager | Omar | ASU123 |
| Manager | Ahmed | ASU456 |
| Manager | Sara | ASU789 |
| Pharmacist | Ahmed | A123 |
| Pharmacist | Ali | B456 |
| Pharmacist | Mona | M789 |
| Pharmacist | Hoda | H101 |
| Pharmacist | Samer | S202 |

> These are sample credentials for testing only.

---

## 🗺️ Menu Map

```
Main Menu
├── [1] Manager Login
│   ├── Add / Edit Stock
│   │   ├── Add New Medicine
│   │   └── Edit Existing Stock (by ID)
│   └── View Reports
│       ├── Low Stock Report
│       └── Total Sales Report
└── [2] Pharmacist Login
    ├── Search Medicine (by name or category)
    ├── Sell Medicine (create a bill)
    ├── Check Item Price
    └── Logout
```

---

## 🏷️ Medicine Categories

The starting inventory covers: Analgesic, Antibiotic, Antihistamine, Bronchodilator, Nasal Spray, Asthma, Antacid, PPI, Antiemetic, Antidiarrheal, Statin, Beta-Blocker, Diuretic, Antiplatelet, Calcium Blocker, ACE Inhibitor, Antidiabetic, Anxiolytic, Antidepressant, Anticonvulsant, Vitamin, Supplement, Nasal Decongestant, Antiseptic, and Antifungal.

---

## 🛠️ Known Limitations & Ideas for Improvement

- **Plain-text passwords:** passwords should be hashed before any real-world use.
- **No date validation:** expiry dates are typed in with no format or logic checks.
- **Hardcoded bill date:** bills always use `21/12/2025`; switching to `<ctime>` would give the real date.
- **Case-sensitive search:** "Panadol" and "panadol" are treated as different searches.
- **Unused supplier data:** the `suppliers` array exists but no menu option reaches it yet.

---

## 🤝 Credits

This project was built as a team effort by the **JAMBOY Team**. JAMBOY is made from the initials of the project's contributors. Thank you to everyone on the team for the ideas, code, and time that went into this system.
