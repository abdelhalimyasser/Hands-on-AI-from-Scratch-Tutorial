# Machine Learning Tutorial

A practical, step-by-step machine learning learning repository focused on understanding the **mathematics behind ML** and applying each concept with code.

The goal of this repository is not only to show formulas, but to connect them to real machine learning ideas through examples, visualizations, and hands-on notebooks.

> The repository is currently under active development. The first module focuses on **Linear Algebra for Machine Learning** using MATLAB inside a Jupyter notebook.

---

## Why This Repository?

Machine learning becomes much easier when the mathematics is connected directly to code.

This tutorial is designed around a simple idea:

**Concept → Intuition → Math → Code → Visualization → Machine Learning Application**

Instead of studying linear algebra as isolated theory, the notebook uses a small student dataset and gradually builds the mathematical tools used in machine learning.

---

## Current Tutorial

### 01 — Linear Algebra for Machine Learning

Notebook:

[`tutorial/01-linear-algebra/01_ml_linear_algebra.ipynb`](tutorial/01-linear-algebra/01_ml_linear_algebra.ipynb)

The notebook starts with a dataset of **50 students × 5 features** and uses it to explain linear algebra step by step.

### Topics Covered

#### Matrices and Vectors
- Representing a dataset as a matrix
- Matrix dimensions
- Accessing individual matrix elements
- Rows and columns as vectors
- Row vectors vs. column vectors
- Matrix transpose

#### Vector Operations
- Vector addition
- Vector subtraction
- Scalar multiplication
- Linear combinations
- Visualizing vector operations

#### Vector Norms
- Why norms are useful in machine learning
- L1 norm / Manhattan norm
- L2 norm / Euclidean norm
- Max norm / L-infinity norm
- Measuring distances between samples
- Normalization
- Regularization intuition
- Similarity measurement
- Optimization intuition
- Feature representation

#### Error Metrics from Norms
- Mean Absolute Error (MAE)
- Root Mean Square Error (RMSE)
- Manual calculations and MATLAB implementations

#### Dot Product
- Manual dot-product calculation
- Geometric interpretation
- Scalar product
- Projection product
- Unit vectors
- Vector projection
- Projection visualization

#### Machine Learning Connections
- Dimensionality reduction intuition
- Projection and PCA intuition
- Similarity measurements
- Cosine similarity
- Interpreting cosine similarity geometrically

---

## Repository Structure

```text
Machine-Learning-Tutorial/
│
├── tutorial/
│   └── 01-linear-algebra/
│       └── 01_ml_linear_algebra.ipynb
│
├── LICENSE
└── README.md
```

More modules will be added as the tutorial grows.

---

## Dataset Used in the Linear Algebra Notebook

The current notebook uses a small educational dataset with 50 students.

Each row represents a student and each column represents a feature:

| Feature | Description |
|---|---|
| Study Hours | Study hours per day |
| Attendance | Attendance percentage |
| Assignments | Assignment performance percentage |
| Midterm | Midterm exam score |
| Final | Final exam score |

Mathematically, the dataset is represented as:

```text
A ∈ R^(50 × 5)
```

This makes it possible to introduce matrices and vectors using something that already looks like a real machine learning dataset.

---

## Tools

The tutorial currently uses:

- **MATLAB**
- **Jupyter Notebook**
- Mathematical visualizations and plots

You can run the notebook using a local MATLAB/Jupyter setup or a compatible online environment.

---

## Getting Started

Clone the repository:

```bash
git clone https://github.com/abdelhalimyasser/Machine-Learning-Tutorial.git
cd Machine-Learning-Tutorial
```

Then open:

```text
tutorial/01-linear-algebra/01_ml_linear_algebra.ipynb
```

Run the cells in order. The notebook is intentionally structured so that later concepts build on earlier ones.

---

## Learning Approach

For every major mathematical idea, try to answer five questions:

1. **What does it mean mathematically?**
2. **What does it mean geometrically?**
3. **How do we calculate it manually?**
4. **How do we implement it in MATLAB?**
5. **Where is it used in machine learning?**

This approach helps turn formulas into tools that can actually be used when studying ML algorithms.

---

## Roadmap

Planned areas for future tutorials include:

- [x] Linear Algebra Fundamentals
- [x] Vector Norms and Distance Metrics
- [x] Dot Product, Projection, and Cosine Similarity
- [ ] Matrix Multiplication
- [ ] Linear Transformations
- [ ] Rank, Linear Independence, and Basis
- [ ] Eigenvalues and Eigenvectors
- [ ] PCA from the Mathematics to the Implementation
- [ ] Probability and Statistics for Machine Learning
- [ ] Calculus and Optimization
- [ ] Data Preprocessing
- [ ] Linear Regression
- [ ] Logistic Regression
- [ ] K-Nearest Neighbors
- [ ] Support Vector Machines
- [ ] Decision Trees and Ensemble Methods
- [ ] Model Evaluation
- [ ] Neural Network Foundations

The roadmap may evolve as new notebooks are added.

---

## Who Is This For?

This repository is useful for anyone who:

- is starting machine learning,
- knows basic programming but wants stronger mathematical intuition,
- wants to understand *why* ML algorithms work instead of only calling libraries,
- wants practical MATLAB examples alongside the mathematics,
- or needs a structured revision reference for ML foundations.

---

## Contributing

Suggestions, corrections, and improvements are welcome.

If you find an error or have an idea for a better explanation, example, or visualization, feel free to open an issue or submit a pull request.

---

## License

This project is licensed under the [MIT License](LICENSE).

---

## Author

**Abdelhalim Yasser**

GitHub: [@abdelhalimyasser](https://github.com/abdelhalimyasser)

---

If this repository helps you understand machine learning more deeply, consider giving it a ⭐.
