# 💊 Smart Pharmacy Management System

A comprehensive, menu-driven console application built in C++ for managing pharmacy operations. The system provides role-based access for Managers and Pharmacists, handles inventory control, customer billing, and maintains data persistence across sessions via file I/O.

> **Collaborative project** — JAMBOY refers to the initials of the project's contributors.

---

## ✨ Features

### 🔐 Role-Based Access Control
- **Manager Login** — Create accounts, manage stock, and view reports
- **Pharmacist Login** — Search medicines, process sales, and check prices
- Login attempts are limited to **3 tries** before access is denied

### 📦 Inventory Management
- Pre-loaded catalog of **50 medicines** across multiple medical categories
- Add new medicines to the system with full details (name, category, expiry, price, stock)
- Edit existing stock quantities by Medicine ID
- **Low Stock Alert** — Automatic warning when any item drops below 5 units
- **Low Stock Report** — Full list of all items needing restocking

### 🧾 Billing & Sales
- Pharmacist-driven billing with real-time stock verification
- Supports multiple items per transaction
- Automatic **10% discount** applied to orders exceeding 300 LE
- Pharmacist sales totals are tracked and updated per transaction
- **Sales Report** — Grand total and itemized bill history per pharmacist

### 💾 Data Persistence
All data is saved to and loaded from text files automatically:

| File | Contents |
|---|---|
| `medicine.txt` | Full medicine inventory |
| `bill.txt` | All transaction records |
| `pharmacists.txt` | Pharmacist accounts and sales totals |
| `managers.txt` | Manager accounts |

---

## 🏗️ System Architecture

The system is structured around five core `struct` types:

```
Medicine     → medicineID, name, category, expiryDate, price, stockQuantity
Bill         → ID, pharmacistName, customerName, medicinesSold[], totalPrice, date
Pharmacist   → ID, username, password, totalSalesAmount
Manager      → ID, username, password
Supplier     → ID, name, email, phone, address  (stored for reference)
```

---

## 🚀 Getting Started

### Prerequisites

- A C++ compiler supporting C++11 or later (e.g., `g++`, MSVC, Clang)

### Compilation & Run

```bash
# Using g++
g++ -o pharmacy smart_pharmacy_system.cpp

# Run
./pharmacy         # Linux / macOS
pharmacy.exe       # Windows
```

### Default Credentials

**Managers:**
| Username | Password |
|---|---|
| Omar | ASU123 |
| Ahmed | ASU456 |
| Sara | ASU789 |

**Pharmacists:**
| Username | Password |
|---|---|
| Ahmed | A123 |
| Ali | B456 |
| Mona | M789 |
| Hoda | H101 |
| Samer | S202 |

---

## 🗺️ Menu Flow

```
Main Menu
├── [1] Manager Login
│   ├── Add/Edit Stock
│   │   ├── Add New Medicine
│   │   └── Edit Existing Stock (by ID)
│   └── View Reports
│       ├── Low Stock Report
│       └── Total Sales Report
└── [2] Pharmacist Login
    ├── Search Medicine (by Name or Category)
    ├── Sell Medicine (Create Bill)
    ├── Check Item Price
    └── Logout
```

---

## 📦 Medicine Categories

The pre-loaded inventory covers: Analgesic, Antibiotic, Antihistamine, Bronchodilator, Nasal Spray, Asthma, Antacid, PPI, Antiemetic, Antidiarrheal, Statin, Beta-Blocker, Diuretic, Antiplatelet, Calcium Blocker, ACE Inhibitor, Antidiabetic, Anxiolytic, Antidepressant, Anticonvulsant, Vitamin, Supplement, Nasal Decongestant, Antiseptic, Antifungal.

---

## ⚠️ Known Limitations & Potential Improvements

- **Passwords stored in plain text** — A hashing mechanism should be implemented for production use
- **No date validation** — Expiry dates are entered manually without format or logic checks
- **Fixed billing date** — Bills are hardcoded to `21/12/2025` instead of using `<ctime>` to get the real current date
- **No medicine search case-insensitivity** — Searches are case-sensitive (e.g., "Panadol" ≠ "panadol")
- **Supplier data unused** — The `suppliers` array is defined but not accessible through any menu

---

## 👥 Authors

Developed collaboratively — **JAMBOY Team**
