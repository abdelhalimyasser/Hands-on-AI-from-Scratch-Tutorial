# Exhaustive (Uninformed) Search Algorithms

A hands-on, first-principles guide to **Exhaustive (Uninformed / Blind) Search Algorithms** in classical Artificial Intelligence.

Exhaustive search algorithms navigate state spaces systematically without domain-specific heuristics. They rely solely on the formal problem formulation: the **initial state**, the **transition model (actions)**, the **goal test**, and the **path cost**.

---

## Directory Overview

```txt
search/Exhaustive_Search/
├── 01_breadth_first_search/
│   ├── bfs.ipynb                                      # Core BFS algorithm & interactive exercises
│   └── problems/
│       ├── 01_missionaries_and_cannibals.ipynb        # River-crossing puzzle (11 crossings)
│       └── 02_8-puzzle_problem.ipynb                  # Sliding tile puzzle & inversion parity
├── 02_depth_first_search/
│   ├── dfs.ipynb                                      # Core DFS algorithm & stack exploration
│   └── problems/
│       ├── 01_farmer_wolf_goat_and_cabbage.ipynb      # Classical riddle & cycle detection (7 crossings)
│       └── 02_N-queens_problem.ipynb                  # Constraint satisfaction via backtracking
├── 03_uniform_cost_search/
│   ├── ucs.ipynb                                      # Core UCS algorithm with min-heap priority queue
│   └── problems/
│       ├── 01_romania_route_finding.ipynb             # Weighted road-map routing (Bucharest)
│       └── 02_cheapest delivery_route_with_repeated_states.ipynb # Routing with repeated states & cycles
├── 04_depth_limited_search/
│   ├── dls.ipynb                                      # Core DLS algorithm with depth cutoff logic
│   └── problems/
│       ├── 01_depth_limited_maze.ipynb                # Grid maze navigation within depth bounds
│       └── 02_romania_route_finding.ipynb             # Depth-constrained route search
├── 05_bidirectional_search/
│   ├── bidirectional_search.ipynb                     # Core Bidirectional Search & frontier intersection
│   └── problems/
│       ├── 01_meet_in_the_middle.ipynb                # Graph pathfinding meeting in the middle
│       └── 02_bidirectional_8-Puzzle.ipynb            # Bidirectional 8-puzzle solver
└── README.md                                          # This documentation guide
```

---

## Core Algorithms Comparison

| Algorithm                            |      Frontier Data Structure      |              Step Cost Assumption              |                Complete?                |     Optimal?     |                     Time Complexity                     |                    Space Complexity                    | Best Used For                                                        |
| :----------------------------------- | :--------------------------------: | :---------------------------------------------: | :--------------------------------------: | :---------------: | :-----------------------------------------------------: | :-----------------------------------------------------: | :------------------------------------------------------------------- |
| **Breadth-First Search (BFS)** |       FIFO Queue (`deque`)       |               Uniform ($c = 1$)               |                   Yes                   | Yes (for $c=1$) |                  $\mathcal{O}(b^d)$                  |                  $\mathcal{O}(b^d)$                  | Shortest path by number of steps; shallow goal states                |
| **Depth-First Search (DFS)**   |       LIFO Stack (`list`)       |                       Any                       | Yes (finite graphs with cycle detection) |        No        |                  $\mathcal{O}(b^m)$                  |               $\mathcal{O}(b \cdot m)$               | Low-memory exploration; constraint satisfaction (Backtracking)       |
| **Uniform-Cost Search (UCS)**  |     Priority Queue (Min-Heap)     | Arbitrary non-negative ($c \ge \epsilon > 0$) |                   Yes                   |        Yes        | $\mathcal{O}(b^{1 + \lfloor C^* / \epsilon \rfloor})$ | $\mathcal{O}(b^{1 + \lfloor C^* / \epsilon \rfloor})$ | Shortest path in weighted graphs with non-uniform step costs         |
| **Depth-Limited Search (DLS)** |     LIFO Stack + Depth counter     |                       Any                       |           Yes (if $d \le l$)           |        No        |                  $\mathcal{O}(b^l)$                  |               $\mathcal{O}(b \cdot l)$               | Preventing infinite loops in deep or infinite state spaces           |
| **Bidirectional Search**       | Two Frontiers (Forward & Backward) |               Uniform ($c = 1$)               |                   Yes                   | Yes (for $c=1$) |                $\mathcal{O}(b^{d/2})$                |                $\mathcal{O}(b^{d/2})$                | Dramatic exponential search space reduction when goal state is known |

> **Notation:**
>
> - $b$: Branching factor (maximum successors per node)
> - $d$: Depth of the shallowest goal state
> - $m$: Maximum depth of the state space (can be $\infty$ in cyclic/infinite graphs)
> - $l$: Specified depth limit (for DLS)
> - $C^*$: Cost of the optimal solution
> - $\epsilon$: Minimum positive step cost ($\epsilon > 0$)

---

## Algorithms Breakdown

### 1. Breadth-First Search (BFS)

- **Concept:** Explores the state space **level by level**, visiting all nodes at depth $k$ before proceeding to depth $k+1$.
- **Mechanism:** Implements a First-In, First-Out (FIFO) queue with a `visited` set to prevent cycles.
- **Key Guarantee:** Optimal for unweighted graphs (finds the path with the fewest edges).
- **Notebook:** [`01_breadth_first_search/bfs.ipynb`](01_breadth_first_search/bfs.ipynb)

### 2. Depth-First Search (DFS)

- **Concept:** Explores as deeply as possible along each branch before **backtracking** when a dead end or visited state is reached.
- **Mechanism:** Implements a Last-In, First-Out (LIFO) stack (or recursion) with cycle detection.
- **Key Advantage:** Memory-efficient—only stores the active branch of depth $m$, requiring $\mathcal{O}(b \cdot m)$ space compared to BFS's exponential $\mathcal{O}(b^d)$ memory footprint.
- **Notebook:** [`02_depth_first_search/dfs.ipynb`](02_depth_first_search/dfs.ipynb)

### 3. Uniform-Cost Search (UCS)

- **Concept:** Generalizes BFS to graphs with **varying non-negative edge costs**. Expands the frontier node with the lowest cumulative path cost $g(n)$.
- **Mechanism:** Uses a priority queue (min-heap) ordered by $g(n)$. Nodes are checked for the goal upon **expansion (removal from queue)** rather than upon generation.
- **Key Guarantee:** Mathematically guaranteed to find the cheapest cost path for arbitrary positive edge costs.
- **Notebook:** [`03_uniform_cost_search/ucs.ipynb`](03_uniform_cost_search/ucs.ipynb)

### 4. Depth-Limited Search (DLS)

- **Concept:** Solves DFS's vulnerability to infinite loops in deep or infinite state spaces by imposing a fixed **depth limit $l$**.
- **Mechanism:** Standard DFS where any node at depth $l$ is treated as having no successors (triggering a *cutoff*).
- **Key Distinction:** Returns `cutoff` if the limit was reached without finding the goal, distinguishing between failure (no path exists) and truncation.
- **Notebook:** [`04_depth_limited_search/dls.ipynb`](04_depth_limited_search/dls.ipynb)

### 5. Bidirectional Search

- **Concept:** Runs two simultaneous searches—one forward from the **initial state** and one backward from the **goal state**—stopping when their frontiers intersect.
- **Mechanism:** Maintains two queues and two visited sets; checks for frontier collision at each iteration to construct the combined path.
- **Key Power:** Exponentially shrinks the search space: $b^{d/2} + b^{d/2} \ll b^d$ (e.g., for $b=10$ and $d=6$, $10^6 = 1,000,000$ nodes shrinks to $2 \times 10^3 = 2,000$ nodes).
- **Notebook:** [`05_bidirectional_search/bidirectional_search.ipynb`](05_bidirectional_search/bidirectional_search.ipynb)

---

## Benchmark Problems Catalog

Every algorithm folder includes dedicated, fully traced benchmark problems:

### BFS Problems

1. **Missionaries and Cannibals Puzzle** ([`01_missionaries_and_cannibals.ipynb`](01_breadth_first_search/problems/01_missionaries_and_cannibals.ipynb))
   - *Problem:* Transport 3 missionaries and 3 cannibals across a river using a 2-person boat without cannibals ever outnumbering missionaries on either bank.
   - *Techniques:* State tuple `(M, C, B)`, constraint validation (`is_valid`), 20-state graph construction, full BFS frontier trace, finding the optimal 11-crossing solution.
2. **8-Puzzle Problem** ([`02_8-puzzle_problem.ipynb`](01_breadth_first_search/problems/02_8-puzzle_problem.ipynb))
   - *Problem:* Slide numbered tiles on a $3 \times 3$ grid to reach the sorted target layout using minimal moves.
   - *Techniques:* 1D flat tuple representation, 2D index arithmetic, branching factor analysis ($b \approx 2.67$), mathematical proof of **inversion parity** ($181,440$ reachable states), formatted ASCII board visualization.

### DFS Problems

1. **Farmer, Wolf, Goat, and Cabbage** ([`01_farmer_wolf_goat_and_cabbage.ipynb`](02_depth_first_search/problems/01_farmer_wolf_goat_and_cabbage.ipynb))
   - *Problem:* A farmer must transport a wolf, a goat, and a cabbage across a river with a 1-item boat without leaving predator and prey unattended.
   - *Techniques:* Binary state tuple `(F, W, G, C)`, predator-prey constraint filtering (10 valid states out of 16), DFS stack trace, discovery of the critical reverse-transport maneuver (Goat returned at Step 4), optimal 7-crossing solution.
2. **N-Queens Problem** ([`02_N-queens_problem.ipynb`](02_depth_first_search/problems/02_N-queens_problem.ipynb))
   - *Problem:* Place $N$ non-attacking queens on an $N \times N$ chessboard.
   - *Techniques:* 1D row-indexed array representation `state[row] = col`, $\mathcal{O}(1)$ diagonal difference formula ($|r_1 - r_2| == |c_1 - c_2|$), DFS with Backtracking, search tree trace, scaling to $N=8$ (92 solutions).

### UCS Problems

1. **Romania Route Finding** ([`01_romania_route_finding.ipynb`](03_uniform_cost_search/problems/01_romania_route_finding.ipynb))
   - *Problem:* Find the shortest driving path from Arad to Bucharest across a weighted map of Romania with varying road distances.
2. **Cheapest Delivery Route with Repeated States** ([`02_cheapest delivery_route_with_repeated_states.ipynb`](<03_uniform_cost_search/problems/02_cheapest%20delivery_route_with_repeated_states.ipynb>))
   - *Problem:* Logistics route optimization on a cyclic weighted network, handling repeated state visits and path-cost updates.

### DLS Problems

1. **Depth-Limited Maze** ([`01_depth_limited_maze.ipynb`](04_depth_limited_search/problems/01_depth_limited_maze.ipynb))
   - *Problem:* Navigate a grid maze where paths beyond the cutoff limit $l$ are pruned, demonstrating the depth-cutoff boundary.
2. **Romania Route Finding (Depth-Constrained)** ([`02_romania_route_finding.ipynb`](04_depth_limited_search/problems/02_romania_route_finding.ipynb))
   - *Problem:* City route search constrained by a maximum number of hops.

### Bidirectional Search Problems

1. **Meet in the Middle** ([`01_meet_in_the_middle.ipynb`](05_bidirectional_search/problems/01_meet_in_the_middle.ipynb))
   - *Problem:* Graph traversal where forward and backward search frontiers meet at an intermediate node.
2. **Bidirectional 8-Puzzle** ([`02_bidirectional_8-Puzzle.ipynb`](05_bidirectional_search/problems/02_bidirectional_8-Puzzle.ipynb))
   - *Problem:* Solving sliding tile configurations simultaneously from the initial shuffle and the goal board.

---

## Pedagogical Structure of Each Notebook

Every notebook in this tutorial follows a consistent, classroom-tested pedagogical structure:

1. **Introduction & Theory:** Motivation, algorithm mechanics, state space representation, and core invariants.
2. **Graph Modeling:** Adjacency lists, edge representations, and formal transition models.
3. **From-Scratch Implementation:** Clean Python implementation with strict type hints, docstrings, and zero external search libraries.
4. **Step-by-Step Execution Tracing:** Tabular trace recording every iteration of the queue/stack/priority-queue frontier, node discovery, and cycle handling.
5. **Complexity & Scalability Analysis:** Rigorous derivations of time and space complexity with empirical observations.
6. **Self-Assessment & Coding Challenges:**
   - Output prediction quizzes to test mental tracing.
   - Fill-in-the-blank coding challenges.
   - Built-in automated test suites verifying correctness.

---

## Recommended Learning Path

```
  1. Breadth-First Search (BFS)
       │
       ├──> Master level-by-level queue exploration & shortest-path guarantee
       └──> Solve: Missionaries & Cannibals ──> 8-Puzzle
       │
  2. Depth-First Search (DFS)
       │
       ├──> Understand LIFO stack, cycle detection & backtracking
       └──> Solve: Farmer, Wolf, Goat & Cabbage ──> N-Queens
       │
  3. Uniform-Cost Search (UCS)
       │
       ├──> Extend BFS to weighted graphs using priority queues
       └──> Solve: Romania Route Finding ──> Delivery Routing
       │
  4. Depth-Limited Search (DLS)
       │
       ├──> Mitigate infinite paths with depth cutoffs
       └──> Solve: Depth-Limited Maze
       │
  5. Bidirectional Search
       │
       ├──> Cut exponential frontiers by meeting in the middle
       └──> Solve: Bidirectional 8-Puzzle
       │
       ▼
  Next: Heuristic (Informed) Search (Greedy Best-First, A*, IDA*)
```

---

## Prerequisites & Running Locally

All notebooks run in standard Python 3.10+ environments with no heavyweight dependencies required for the core algorithms:

```bash
# Clone the repository
git clone https://github.com/abdelhalimyasser/Hands-on-AI-from-Scratch-Tutorial.git
cd Hands-on-AI-from-Scratch-Tutorial

# Launch Jupyter Notebook or JupyterLab
jupyter notebook
```

Navigate to `search/Exhaustive_Search/` and open any notebook to begin experimenting!
