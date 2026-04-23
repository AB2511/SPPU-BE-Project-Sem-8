# 📊 Business Intelligence Lab (410253(C))

This repository contains all practical assignments performed for the **Business Intelligence Lab (SPPU BE Semester 8)**.

---

## 📂 Folder Structure

```
BI/
├── BI_Assignment1/
│   ├── BI_Assignment1.docx
│   └── BI_Assignment1.pdf
│
├── BI_Assignment2/
│   ├── BI_Assignment2.docx
│   ├── BI_Assignment2.pdf
│   ├── SQLQuery1.sql
│   └── SQLQuery2.sql
│
├── BI_Assignment3/
│   ├── BI_Assignment3.docx
│   ├── BI_Assignment3.pdf
│   ├── SQLQuery1.sql
│   ├── SQLQuery2.sql
│   └── SQLQuery3.sql
│
├── BI_Assignment4/
│   ├── BI_Assignment4.docx
│   ├── BI_Assignment4.pdf
│   ├── BI_Assignment4.xlsx
│   └── SQLQuery1.sql
│
├── BI_Assignment5/
│   ├── BI_Assignment5.ipynb
│   └── BI_Assignment5.pdf
│
├── MiniProject/
│   ├── BI_Miniproject.docx
│   ├── BI_Miniproject.ipynb
│   ├── BI_Miniproject.pdf
│   ├── BI_Miniprojectcode.pdf
│   └── student-mat-pass-or-fail.csv
│
└── README.md
```

---

* ETL is a **process**, not just tools
* SQL itself can perform ETL

---

## 🔹 Practical 3: OLAP Models

### Implemented:

* Dimension Tables:

  * `DimStudent`
  * `DimSubject`
* Fact Table:

  * `FactMarks`
* Performed JOIN queries (ROLAP)

### Not Implemented:

* ❌ MOLAP
* ❌ HOLAP

### Reason:

* Requires **SQL Server Analysis Services (SSAS)**
* Not available in SQL Server Express

📌 Key Learning:

* ROLAP = SQL-based analysis
* MOLAP = Cube-based (advanced tools required)

---

## 🔹 Practical 4: Excel Data Analysis

### What was done:

1. Connected Excel to SQL Server
2. Imported tables:

   * FactMarks
   * DimStudent
   * DimSubject
3. Used **Power Query (Merge)** to join tables
4. Created final dataset:

   * Name, SubjectName, Marks
5. Created:

   * Pivot Table
   * Pivot Chart

📌 Key Learning:

* Power Query = SQL JOIN inside Excel
* Pivot Table enables fast analysis

---

## 🔹 Practical 5: Data Classification

### What was done:

* Dataset: Iris
* Algorithm: Naive Bayes

### Steps:

* Train-test split
* Feature scaling
* Model training
* Prediction
* Evaluation

📌 Important Insight:

* Accuracy = 100% (misleading due to small dataset)

📌 Key Learning:

* Always validate ML results critically

---

## 🔹 Mini Project: Student Pass/Fail Prediction

### What was done:

* Dataset: Student Performance (`student-mat-pass-or-fail.csv`)
* Algorithm: Classification (Pass/Fail prediction)
* Tools: Power BI, Python

### Steps:

* Data loading and exploration
* Feature engineering
* Model training
* Evaluation and visualization

### 📁 Project Files:

```
MiniProject/
├── BI_Miniproject.ipynb       # Python implementation
├── BI_Miniproject.pdf         # Project documentation
├── BI_Miniproject.docx        # Word document
├── BI_Miniprojectcode.pdf     # Code documentation
└── student-mat-pass-or-fail.csv  # Dataset
```

---

# 📂 Repository Structure

```
BI/
├── README.md
│
├── BI_Assignment1/
│   ├── BI_Assignment1.docx
│   └── BI_Assignment1.pdf
│
├── BI_Assignment2/
│   ├── BI_Assignment2.docx
│   ├── BI_Assignment2.pdf
│   ├── SQLQuery1.sql
│   └── SQLQuery2.sql
│
├── BI_Assignment3/
│   ├── BI_Assignment3.docx
│   ├── BI_Assignment3.pdf
│   ├── SQLQuery1.sql
│   ├── SQLQuery2.sql
│   └── SQLQuery3.sql
│
├── BI_Assignment4/
│   ├── BI_Assignment4.docx
│   ├── BI_Assignment4.pdf
│   ├── BI_Assignment4.xlsx
│   └── SQLQuery1.sql
│
├── BI_Assignment5/
│   ├── BI_Assignment5.ipynb
│   └── BI_Assignment5.pdf
│
└── MiniProject/
    ├── BI_Miniproject.docx
    ├── BI_Miniproject.ipynb
    ├── BI_Miniproject.pdf
    ├── BI_Miniprojectcode.pdf
    └── student-mat-pass-or-fail.csv
```

### 📌 Structure Notes

* `.docx / .pdf` → Final submission files
* `.sql` → SQL queries used in ETL and ROLAP
* `.ipynb` → Machine learning implementation

---

# ⚠️ Issues Faced & Solutions

### ❌ Invalid object name 'FactMarks'

✔ Fix:

```sql
USE BI_Practical;
```

---

### ❌ Tables not visible in Excel

✔ Fix:

* Enable **Select Multiple Items** in Navigator

---

### ❌ Merge not clickable

✔ Fix:

* Select matching columns before clicking OK

---

### ❌ MOLAP confusion

✔ Reality:

* Requires SSAS
* Not possible in basic setup

---

### ❌ Python errors

✔ Fix:

* Clean copied code
* Check imports and indentation

---

# 🛠️ Tools Used

* SQL Server 2022 Express
* SSMS
* Microsoft Excel
* Power BI
* Python (Jupyter Notebook)

---

# 🧠 Key Takeaways

* BI = Data pipeline + analysis
* Excel is a powerful BI tool
* Power Query is essential for data transformation
* ROLAP is easiest for academic implementation
* ML results must be interpreted carefully

---

# 👩‍💻 Author

Anjali Barge  
BE Computer Engineering (SPPU)