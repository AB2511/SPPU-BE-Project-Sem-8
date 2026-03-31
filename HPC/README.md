# ⚡ High Performance Computing (HPC) – SPPU Practicals

This folder contains implementation of **HPC Laboratory Practicals** as per SPPU syllabus (410250).

---

## 📂 Folder Structure

```
HPC/
│
├── Assignment_1/
│   └── Assignment1.cpp
│
├── Assignment_2/
│   └── Assignment2.cpp
│
├── Assignment_3/
│   └── Assignment3.cpp
│
├── Assignment_4/
│   └── HPC_Assignment4.ipynb
│
├── Assignment_5/
│   └── HPC_Assignment5.ipynb
```

---

## 🛠️ Software & Tools Used

| Tool                    | Purpose              |
| ----------------------- | -------------------- |
| Dev C++ (TDM-GCC 4.9.2) | OpenMP Programs      |
| Google Colab            | CUDA & Deep Learning |
| GCC with OpenMP         | Parallel execution   |

---

## ⚙️ IMPORTANT SETUP (VERY IMPORTANT)

### 🔹 For Practical 1, 2, 3 (OpenMP)

Go to:

```
Tools → Compiler Options → Settings
```

✔ In **Compiler Commands**, add:

```
-fopenmp
```

✔ In **Linker Commands**, keep:

```
-static-libgcc
```

👉 This enables OpenMP parallel execution

---

## 🧪 PRACTICAL 1

### Parallel BFS and DFS using OpenMP

✔ Implemented:

* Parallel DFS
* Parallel BFS

✔ Output order may vary due to parallel execution
👉 This is **expected and correct**

---

## 🧪 PRACTICAL 2

### Parallel Bubble Sort & Merge Sort

✔ Implemented:

* Sequential vs Parallel Bubble Sort
* Sequential vs Parallel Merge Sort

### ⚠️ IMPORTANT OBSERVATIONS

✔ Parallel may be slower for small inputs
👉 Reason: Thread overhead

✔ Time showing 0
👉 Due to low timer precision

### ❗ CRASH ISSUE

```
return value 3221225477
```

👉 Cause:

* Stack overflow / memory issue in Dev C++

### ✅ SOLUTION

✔ Use input size ≤ 100
✔ Avoid very large arrays in Dev C++

---

## 🧪 PRACTICAL 3

### Parallel Reduction

✔ Operations:

* Min
* Max
* Sum
* Average

✔ Used:

```
#pragma omp parallel for reduction(...)
```

### ⚠️ IMPORTANT

👉 Old compiler (TDM-GCC 4.9.2) may not support reduction properly

### ✅ If error occurs:

* Use **WSL (Ubuntu)**
* Or **CodeBlocks (new GCC)**

---

## 🧪 PRACTICAL 4

### CUDA Programming (GPU)

✔ Implemented:

* Vector Addition
* Matrix Multiplication

### ⚙️ HOW TO RUN

1. Open Google Colab
2. Go to:

```
Runtime → Change runtime type → GPU
```

3. Run:

```python
!pip install git+https://github.com/afnan47/cuda.git
%load_ext nvcc_plugin
```

### ⚠️ ERROR FIX

If you see:

```
nvcc not found
```

👉 GPU NOT enabled

---

## 🧪 PRACTICAL 5

### HPC Application (AI/ML using GPU)

✔ Model:

* CNN on MNIST dataset

✔ Accuracy:

```
~98.5%
```

✔ GPU Output:

```
GPU Available: [PhysicalDevice(...GPU...)]
```

👉 This confirms **true HPC execution**

---

## 📊 KEY LEARNING

* Parallel ≠ Always faster
* GPU significantly improves ML performance
* OpenMP depends on compiler support
* CUDA requires GPU runtime

---

## 🚀 FINAL STATUS

| Practical | Status |
| --------- | ------ |
| 1         | ✅ Done |
| 2         | ✅ Done |
| 3         | ✅ Done |
| 4         | ✅ Done |
| 5         | ✅ Done |

---

## ⚠️ FINAL ADVICE

* Use **small inputs in Dev C++**
* Always enable **GPU in Colab**
* Avoid unsupported features in old compilers

---

## 📌 Author

Final Year Computer Engineering Student
Savitribai Phule Pune University
