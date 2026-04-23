# 🤖 NLP Mini Project – Transformer Fine-Tuning

## 📌 Title
Fine-Tuning BERT for Sentiment Classification

---

## 🎯 Objective
To fine-tune a pretrained transformer model (BERT) for sentiment classification using the IMDb dataset.

---

## 🛠️ Tools & Technologies

- Python
- Google Colab
- PyTorch
- HuggingFace Transformers
- Datasets Library
- GPU Acceleration

---

## 📊 Dataset

- IMDb Movie Reviews Dataset
- Binary Classification:
  - Positive
  - Negative

---

## 🧠 Model Used

- Pretrained Model: `bert-base-uncased`
- Task: Sequence Classification

---

## ⚙️ Methodology

1. Load dataset using HuggingFace
2. Tokenize text using BERT tokenizer
3. Convert data to PyTorch tensors
4. Fine-tune pretrained BERT model
5. Evaluate model performance
6. Perform inference on new text

---

## 🚀 Training Details

- Epochs: 2
- Batch Size: 8
- Learning Rate: 2e-5

---

## 📈 Results

- Test Accuracy: ~98.5%
- Model performs well on unseen data

---

## 🔍 Sample Output

Input:
```

This movie was fantastic!

```

Output:
```

Positive

```

---

## ⚠️ Important Notes

- GPU must be enabled in Google Colab
- Dataset size reduced for faster training
- Transformer models require high computation

---

## 🧾 Conclusion

Transformer-based models like BERT achieve high accuracy in NLP tasks due to self-attention mechanisms and pretraining on large datasets.

---

## 👩‍💻 Author

Anjali Barge  
Final Year Computer Engineering Student  
Savitribai Phule Pune University
