# 🚀 Mini Project: Parallel Quicksort using MPI

## Subject: 410250 - High Performance Computing

---

## 📌 Problem Statement

Evaluate the performance enhancement of the Parallel Quicksort Algorithm using MPI (Message Passing Interface).

---

## 🎯 Objective

* Implement parallel sorting using MPI
* Compare execution time with different number of processes
* Analyze performance improvement (Speedup)

---

## ⚙️ Technologies Used

* Language: C
* Parallel Library: MPI (OpenMPI)
* Environment: WSL (Ubuntu on Windows)

---

## 🧩 Project Approach

The implementation follows a simple parallel strategy:

1. Root process generates random array
2. Data is divided using `MPI_Scatter`
3. Each process sorts its portion using `qsort()`
4. Results are collected using `MPI_Gather`
5. Final merge sort is done at root

---

## 🛠️ Setup & Installation

### Step 1: Install WSL (Windows Subsystem for Linux)

```bash
wsl --install
```

### Step 2: Open Ubuntu terminal

### Step 3: Install MPI

```bash
sudo apt update
sudo apt install mpich
```

### Step 4: Issue Faced ⚠️

MPICH was installed but parallel processes were not working properly.

Output issue:

```
Hello from process 0 out of 1
```

### ✅ Solution:

Installed OpenMPI instead:

```bash
sudo apt install openmpi-bin libopenmpi-dev
```

---

## ▶️ How to Run the Program

## 🖥️ How to Open and Navigate (IMPORTANT)

This project must be run inside WSL (Ubuntu), not Windows Command Prompt.

### Step 1: Open WSL
wsl

### Step 2: Navigate to Project Directory
cd /mnt/d/SPPU-BE-Practical-Sem-8/HPC/Mini_Project

Note: Replace `d` with your drive letter if different.

### Compile:

```bash
mpicc src/pq.c -o pq
```

### Execute:

```bash
mpirun -np 1 ./pq
mpirun -np 2 ./pq
mpirun -np 4 ./pq
```

---

## ⚠️ Important Observations

* Running with more processes than CPU cores gives error:

```
There are not enough slots available
```

### Solution:

Use:

```bash
mpirun --oversubscribe -np 8 ./pq
```

But this may reduce performance due to CPU overload.

---

## 📊 Results

| Processes | Time (sec) | Speedup |
| --------- | ---------- | ------- |
| 1         | 0.2156     | 1.00    |
| 2         | 0.1344     | 1.60    |
| 4         | 0.0974     | 2.21    |

---

## 📈 Performance Analysis

* Execution time decreases with increase in processes

* Speedup is **not linear** due to:

  * Communication overhead
  * Load imbalance
  * Synchronization cost

* Larger input sizes show better parallel efficiency

---

## 🧠 Key Learning

* MPI enables distributed memory parallelism
* Environment setup is critical (MPICH vs OpenMPI)
* Small input sizes do not benefit much from parallelism
* Performance evaluation is essential in HPC

---

## ⚠️ Common Errors Faced & Solutions

### ❌ 1. MPI not running parallel processes

**Cause:** MPICH issue in WSL
**Fix:** Install OpenMPI

---

### ❌ 2. All processes showing rank 0

**Cause:** Incorrect MPI environment
**Fix:** Switch to OpenMPI

---

### ❌ 3. Linux commands not working in Windows

Example:

```
mv: not recognized
```

**Fix:**
Use:

* WSL → Linux commands
* CMD → Windows commands

---

### ❌ 4. Permission / sudo password confusion

**Fix:** Reset using:

```bash
wsl -u root
passwd username
```

---

## 📂 Project Structure

```
HPC/
 └── Mini_Project/
      ├── src/
      │    └── pq.c
      └── README.md
```

---

## 📌 Conclusion

Parallel Quicksort using MPI significantly improves performance for large datasets.
However, speedup is limited by communication overhead and system constraints.

This project demonstrates the practical implementation of parallel computing concepts in HPC.

---

## 👩‍💻 Author

Anjali Santosh Barge  
B.E Computer Engineering  
SPPU

---
