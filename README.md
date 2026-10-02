# Hands-on AI from Scratch Tutorial

A long-term, hands-on learning repository for understanding **Artificial Intelligence and Machine Learning from first principles to real-world implementation**.

This repository is being built as a complete learning path — not just a collection of notebooks and not a single university course.

The goal is to understand what happens **under the hood**, build important ideas **from scratch**, study the mathematics behind them, and then apply them using the tools and workflows used in practice.

---

## What This Repository Is About

AI is much easier to understand when you do not treat libraries as black boxes.

This repository follows the same idea across every topic:

**Theory → Intuition → Mathematics → From-Scratch Implementation → Visualization → Practical Implementation → Experiments**

The repository will gradually cover the foundations behind AI, machine learning, neural networks, NLP, and related areas, while also going beyond standard university material whenever a deeper or more advanced explanation is useful.

It is intended to grow into a large reference that can be used for:

- learning,
- revision,
- experimentation,
- implementation practice,
- understanding algorithms internally,
- and connecting mathematical theory to real AI systems.

---

# Three Languages, Three Different Roles

This repository intentionally uses **C, MATLAB, and Python**.

They are not interchangeable here. Each one has a specific purpose.

## C — Understand What Happens Under the Hood

C is used when implementing algorithms or important mechanisms from scratch helps reveal what libraries normally hide.

Examples may include:

- core algorithms,
- data structures used by ML methods,
- numerical routines,
- optimization-related implementations,
- matrix or vector operations,
- low-level algorithm experiments,
- and selected ML algorithms built without relying on high-level ML libraries.

The purpose is not to replace Python libraries.

The purpose is to understand what those libraries are doing internally.

---

## MATLAB — Mathematics, Proofs, and Visualization

MATLAB is used for the mathematical foundation of AI and machine learning.

This includes topics such as:

- linear algebra,
- probability,
- statistics,
- calculus,
- optimization,
- numerical methods,
- mathematical derivations,
- geometric intuition,
- proofs and demonstrations,
- and visual experiments.

MATLAB makes it possible to move quickly between equations, vectors, matrices, plots, and experiments.

The goal is to make the mathematics **visible and executable**, rather than leaving it only on paper.

---

## Python — Real-World AI and Machine Learning

Python is used for the practical implementation of the concepts in realistic AI and machine learning workflows.

This will include tools and libraries such as:

- NumPy
- Pandas
- Matplotlib
- SciPy
- scikit-learn
- PyTorch
- and other libraries when they become relevant.

Python notebooks and projects will focus on:

- working with real datasets,
- preprocessing,
- training models,
- evaluation,
- experimentation,
- model comparison,
- deep learning,
- NLP,
- and practical AI workflows.

---

# Learning Philosophy

The repository is built around understanding before abstraction.

For an important concept or algorithm, the preferred progression is:

1. **What problem are we trying to solve?**
2. **What is the intuition behind it?**
3. **What is the mathematics?**
4. **Can we calculate a small example manually?**
5. **Can we visualize what is happening?**
6. **Can we implement the important parts from scratch?**
7. **How do real libraries implement or expose the idea?**
8. **How is it used in an actual machine learning workflow?**
9. **What assumptions and limitations does it have?**
10. **What changes when we move to larger or more advanced problems?**

The goal is not to memorize APIs.

The goal is to understand the ideas deeply enough that the APIs make sense.

---

# Scope

The repository will cover multiple subjects that contribute to modern AI.

The exact structure will evolve as the repository grows, but the intended scope includes the following areas.

## Mathematical Foundations

- Linear Algebra
- Probability
- Statistics
- Calculus
- Optimization
- Numerical Methods
- Information Theory

## Machine Learning Foundations

- Data preprocessing
- Feature engineering
- Distance and similarity
- Regression
- Classification
- Model evaluation
- Bias and variance
- Regularization
- Optimization
- Cross-validation
- Hyperparameter tuning

## Classical Machine Learning

- Linear Regression
- Logistic Regression
- K-Nearest Neighbors
- Naive Bayes
- Support Vector Machines
- Decision Trees
- Random Forests
- Ensemble Learning
- Clustering
- Dimensionality Reduction
- Principal Component Analysis
- and related algorithms

## Artificial Intelligence Foundations

- Search algorithms
- State-space search
- Heuristics
- Constraint satisfaction
- Knowledge representation
- Logic
- Reasoning
- Expert systems
- Planning
- and other classical AI topics

## Neural Networks and Deep Learning

- Perceptrons
- Neural network fundamentals
- Forward propagation
- Backpropagation
- Activation functions
- Loss functions
- Optimization algorithms
- Initialization
- Regularization
- Multilayer neural networks
- Convolutional Neural Networks
- Recurrent Neural Networks
- Attention
- Transformers
- and deeper architectures

## Natural Language Processing

- Text preprocessing
- Tokenization
- Vector representations
- Word embeddings
- Language modeling
- Sequence models
- Attention
- Transformers
- modern NLP workflows
- and related topics

## Advanced Topics

As the repository grows, additional advanced topics may be added, including subjects from:

- representation learning,
- deep learning,
- generative AI,
- large language models,
- retrieval systems,
- AI agents,
- reinforcement learning,
- computer vision,
- research papers,
- optimization,
- and AI systems.

The repository is not restricted to a fixed syllabus.

If a topic helps build a stronger understanding of AI, it can become part of the tutorial.

---

# Current Progress

The repository currently starts with **Linear Algebra for Machine Learning**.

The first notebook is:

[`tutorial/01-linear-algebra/01_ml_linear_algebra.ipynb`](tutorial/01-linear-algebra/01_ml_linear_algebra.ipynb)

Current material includes:

- representing datasets as matrices,
- matrix dimensions,
- accessing matrix elements,
- rows and columns as vectors,
- row vectors and column vectors,
- transpose,
- vector addition,
- vector subtraction,
- scalar multiplication,
- linear combinations,
- vector norms,
- L1 / Manhattan distance,
- L2 / Euclidean distance,
- Max / L-infinity norm,
- Mean Absolute Error,
- Root Mean Square Error,
- dot product,
- geometric interpretation of the dot product,
- unit vectors,
- projection,
- dimensionality reduction intuition,
- similarity measurement,
- cosine similarity,
- and MATLAB visualizations.

The Linear Algebra section is **still in progress** and will continue to expand.

---

# Repository Structure

The repository structure is still evolving.

At the moment:

```text
Hands-on-AI-from-Scratch-Tutorial/
│
├── tutorial/
│   └── 01-linear-algebra/
│       └── 01_ml_linear_algebra.ipynb
│
├── LICENSE
└── README.md
```

As heavier topics are added, the repository will be reorganized into a clearer structure for the different subjects, languages, implementations, exercises, and experiments.

The structure may therefore change significantly over time.

---

# Example of How a Topic May Be Covered

A topic such as **Support Vector Machines** may eventually include several layers:

```text
Support Vector Machines
│
├── Mathematical intuition
├── Geometry of the separating hyperplane
├── Margin derivation
├── Optimization formulation
├── MATLAB visualization
├── From-scratch implementation
├── C implementation of selected internals
├── Python implementation
├── scikit-learn comparison
├── Experiments on datasets
├── Evaluation
└── Advanced extensions
```

The same philosophy can be applied to many other topics.

This is what is meant by **Hands-on AI from Scratch**.

---

# Not a Fixed University Syllabus

Some of the material in this repository overlaps with university courses in:

- Artificial Intelligence,
- Machine Learning,
- Mathematics,
- Probability and Statistics,
- Neural Networks,
- NLP,
- and related subjects.

However, this repository is **not intended to follow the university curriculum lesson by lesson**.

The pace may be faster.

Some topics may be explored much more deeply.

Some topics may appear earlier when they are useful.

And advanced material may be added far beyond the requirements of a normal course.

The aim is to build a coherent understanding of AI rather than reproduce a specific syllabus.

---

# Who Is This Repository For?

This repository may be useful if you:

- are learning AI or machine learning,
- want stronger mathematical foundations,
- want to understand algorithms instead of only calling libraries,
- like learning through notebooks and experiments,
- want both theoretical and practical explanations,
- want to see selected algorithms implemented from scratch,
- want to connect C, MATLAB, and Python to AI concepts,
- or need a growing reference to revisit later.

You do not need to understand every advanced topic before starting.

The repository is designed to grow from foundations toward more difficult material.

---

# How to Use the Repository

Clone the repository:

```bash
git clone https://github.com/abdelhalimyasser/Hands-on-AI-from-Scratch-Tutorial.git
cd Hands-on-AI-from-Scratch-Tutorial
```

Then explore the tutorials in order when possible.

For the current material:

```text
tutorial/01-linear-algebra/01_ml_linear_algebra.ipynb
```

Each topic may eventually contain different combinations of:

- explanations,
- notebooks,
- source code,
- visualizations,
- exercises,
- derivations,
- experiments,
- datasets,
- and practical implementations.

---

# Roadmap

This is a long-term roadmap and will continue to evolve.

### Foundations

- [ ] Linear Algebra
- [ ] Probability
- [ ] Statistics
- [ ] Calculus
- [ ] Optimization
- [ ] Numerical Methods

### Machine Learning

- [ ] Data preprocessing
- [ ] Regression
- [ ] Classification
- [ ] K-Nearest Neighbors
- [ ] Naive Bayes
- [ ] Support Vector Machines
- [ ] Decision Trees
- [ ] Random Forests
- [ ] Ensemble Learning
- [ ] Clustering
- [ ] Dimensionality Reduction
- [ ] Model Evaluation
- [ ] Hyperparameter Tuning

### Artificial Intelligence

- [ ] Search
- [ ] Heuristics
- [ ] Constraint Satisfaction
- [ ] Knowledge Representation
- [ ] Logic and Reasoning
- [ ] Expert Systems
- [ ] Planning

### Deep Learning

- [ ] Neural Network Foundations
- [ ] Backpropagation from Scratch
- [ ] Optimization for Neural Networks
- [ ] CNNs
- [ ] RNNs
- [ ] Attention
- [ ] Transformers

### Natural Language Processing

- [ ] Text Processing
- [ ] Embeddings
- [ ] Language Models
- [ ] Sequence Models
- [ ] Transformers for NLP
- [ ] Modern NLP Applications

### Beyond the Fundamentals

- [ ] Computer Vision
- [ ] Reinforcement Learning
- [ ] Generative AI
- [ ] Large Language Models
- [ ] Retrieval-Augmented Systems
- [ ] AI Agents
- [ ] Research Paper Implementations

This is not a promise of a fixed order. Topics will be added and reorganized as the repository develops.

---

# Contributing

Contributions are welcome.

If you want to contribute an explanation, implementation, notebook, visualization, exercise, correction, or improvement, feel free to open an issue or submit a pull request.

Contributions should try to preserve the main philosophy of the repository:

> **Explain the idea, understand the mathematics, reveal what happens under the hood, and connect it to practical AI.**

If you are interested in becoming a regular contributor as the repository grows, you are also welcome to get involved.

---

# Follow the Progress

This repository is under active development.

New material will be added continuously as new topics are studied, implemented, and refined.

If you find the project useful, consider giving the repository a **⭐ Star** so you can easily return to it and follow future updates.

---

# License

This project is licensed under the [MIT License](LICENSE).

---

# Author

**Abdelhalim Yasser**

GitHub: [@abdelhalimyasser](https://github.com/abdelhalimyasser)

Repository:

[Hands-on AI from Scratch Tutorial](https://github.com/abdelhalimyasser/Hands-on-AI-from-Scratch-Tutorial)
