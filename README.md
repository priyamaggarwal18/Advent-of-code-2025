<div align="center">
  <img src="./Banner.png" alt="Advent of Code Banner" />
</div>
<br>
<div align="center">
  <img alt="GitHub repo size" src="https://img.shields.io/github/repo-size/priyamaggarwal18/Advent-of-code-2025?style=for-the-badge&color=0f1023">
  <img alt="GitHub Repo stars" src="https://img.shields.io/github/stars/priyamaggarwal18/Advent-of-code-2025?style=for-the-badge&color=0f1023">
  <img alt="GitHub forks" src="https://img.shields.io/github/forks/priyamaggarwal18/Advent-of-code-2025?style=for-the-badge&color=0f1023">
  <img alt="Last commit" src="https://img.shields.io/github/last-commit/priyamaggarwal18/Advent-of-code-2025?style=for-the-badge&color=0f1023">
</div>

<br>

# 📚 Table of Contents

* [Day 1: Secret Entrance](#-day-1-secret-entrance)
* [Day 2: Gift Shop](#-day-2-gift-shop)
* [Day 3: Lobby](#-day-3-lobby)
* [Day 4: Printing Department](#-day-4-printing-department)
* [Day 5: Cafeteria](#-day-5-cafeteria)
* [Day 6: Trash Compactor](#-day-6-trash-compactor)
* [Day 7: Laboratories](#-day-7-laboratories)
* [Day 8: Playground](#-day-8-playground)
* [Day 9: Movie Theater](#-day-9-movie-theater)
* [Day 10: Factory](#-day-10-factory)
* [Day 11: Reactor](#-day-11-reactor)
* [Day 12: Christmas Tree Farm](#-day-12-christmas-tree-farm)

---

# 🎄 Day 1: Secret Entrance

<details>
  <summary><h2>🌟 Part 1: Final Position Count (Answer: 1055)</h2></summary>

### 📝 Description
You are at the secret entrance to the North Pole base, but the password is locked in a safe. The safe has a dial with numbers $\text{0}$ through $\text{99}$. You are given a sequence of rotations (e.g., $\text{L68}$ or $\text{R48}$). The dial starts at $\text{50}$.

The actual password is the **number of times the dial is left pointing at $\text{0}$ after any rotation** in the sequence. The dial wraps around (e.g., one click left from $\text{0}$ is $\text{99}$).

### 💡 Approach
1.  **Read Input:** Read each rotation (direction and distance) from the input file.
2.  **Maintain Position:** Use an integer variable, `dial`, initialized to $\text{50}$, to track the current position of the dial.
3.  **Apply Rotation:**
    * For a right rotation ($\text{R}$), add the distance to `dial`.
    * For a left rotation ($\text{L}$), subtract the distance from `dial`.
4.  **Handle Wrap-Around:** Since the dial is $\text{0}$ to $\text{99}$, we must use the modulo arithmetic or a loop to keep the `dial` value within this range:
    * **Right:** If `dial` is $\ge \text{100}$, repeatedly subtract $\text{100}$.
    * **Left:** If `dial}$ is $<\text{0}$, repeatedly add $\text{100}$.
5.  **Count:** After each rotation, check if `dial` is equal to $\text{0}$. If it is, increment a counter.

### 💻 Solution Location (C++)
The C++ code for Part 1 can be found in the repository at:
**[View C++ Code for Part 1](./Day1/Part1.cpp)**
**[View Input](./Day1/input.txt)**

</details>

<details>
  <summary><h2>🌟 Part 2: Total Clicks Count (Answer: 6386)</h2></summary>

### 📝 Description
The new security protocol ("method $\text{0x434C49434B}$") changes the password rule. You must now count the **total number of times any click causes the dial to point at $\text{0}$**, regardless of whether it happens during a rotation or at the end of one. For large rotations, the dial may pass $\text{0}$ multiple times.

### 💡 Approach
1.  **Read Input & Setup:** The setup is the same as Part 1, maintaining the current `dial` position and a counter.
2.  **Simulate Click by Click:** Since we need to count every time $\text{0}$ is reached, we must simulate the rotation one click at a time instead of calculating the final position directly.
3.  **Apply Click Logic:**
    * Use a loop that runs for the `distance` of the rotation.
    * **Right ($\text{R}$):** Increment `dial`. Apply modulo $\text{100}$: `dial = (dial + 1) % 100;`.
    * **Left ($\text{L}$):** Decrement `dial}$. Apply wrap-around (using $\text{+ 100}$ before modulo to handle negative results): `dial = (dial - 1 + 100) % 100;`.
    * **Count:** Inside the loop, after updating the `dial` position for that click, check if `dial}$ is equal to $\text{0}$. If it is, increment the `countZero` counter.

### 💻 Solution Location (C++)
The C++ code for Part 2 can be found in the repository at:
**[View C++ Code for Part 2](./Day1/Part2.cpp)**
**[View Input](./Day1/input.txt)**

</details>

# 🎁 Day 2: Gift Shop

<details>
  <summary><h2>🌟 Part 1: Double-Repeated IDs (Answer: 29940924880)</h2></summary>

### 📝 Description
A young Elf added invalid product IDs to the gift shop database. You are given a single line of comma-separated ID ranges (e.g., $\text{L-R}$). An ID is considered **invalid** if it is made only of a sequence of digits repeated **exactly twice** (e.g., $\text{55}$, $\text{6464}$, $\text{123123}$). IDs do not have leading zeros. Your task is to find the sum of all invalid IDs within the given ranges.

### 💡 Approach
1.  **Parse Input:** Read the single line of input, split it by commas ($\text{,}$) to get individual ranges. Then, split each range by the dash ($\text{-}$) to get the start ($\text{L}$) and end ($\text{R}$) IDs.
2.  **Iterate Ranges:** Loop through every integer ID $x$ from $L$ to $R$.
3.  **Check for Double Repeat (`isDoubleNumber`):**
    * Convert the ID $x$ to a string $s$.
    * An ID can only be a double repeat if its length $n$ is **even**.
    * Check if the first half of the string ($s[0 \dots n/2 - 1]$) is exactly equal to the second half of the string ($s[n/2 \dots n - 1]$).
4.  **Sum Total:** If an ID is invalid, add it to the running `total`. Since the IDs can be very large (up to 11 digits), use a $\text{long long}$ data type for the total sum.

### 💻 Solution Location (C++)
The C++ code for Part 1 can be found in the repository at:
**[View C++ Code for Part 1](./Day2/Part1.cpp)**
**[View Input](./Day2/input.txt)**

</details>

<details>
  <summary><h2>🌟 Part 2: At Least Twice Repeated IDs (Answer: 48631958998)</h2></summary>

### 📝 Description
The rule for invalid IDs has been updated: an ID is now invalid if it is made only of some sequence of digits repeated **at least twice** (e.g., $\text{12341234}$ two times, $\text{123123123}$ three times, $\text{1111111}$ seven times). The task remains to find the sum of all invalid IDs across all ranges.

### 💡 Approach
1.  **Iterate Ranges:** The input parsing and range iteration remains the same as Part 1.
2.  **Check for General Repeat (`isRepeatedPattern`):**
    * Convert the ID $x$ to a string $s$ of length $n$.
    * Iterate through all possible pattern lengths, $k$, from $\text{1}$ up to $n/2$. This $k$ is the length of the potential repeating block.
    * **Check Divisibility:** The total length $n$ must be perfectly divisible by the block length $k$ ($n \pmod k = 0$).
    * **Extract Block:** Take the first $k$ characters as the repeating `block`.
    * **Rebuild and Compare:** Reconstruct the entire string $s$ by repeating the `block` $n/k$ times. If the reconstructed string matches the original string $s$, the ID is invalid, and we can immediately return $\text{true}$.
3.  **Sum Total:** If an ID is invalid, add it to the $\text{long long}$ running `total`.

### 💻 Solution Location (C++)
The C++ code for Part 2 can be found in the repository at:
**[View C++ Code for Part 2](./Day2/Part2.cpp)**
**[View Input](./Day2/input.txt)**

</details>

# ⚡ Day 3: Lobby

<details>
  <summary><h2>🌟 Part 1: Max 2-Digit Joltage (Answer: 17229)</h2></summary>

### 📝 Description
The elevators and escalators are offline, needing emergency power from nearby battery banks. Each line of the input represents a battery bank, a sequence of joltage digits ($\text{1}$ to $\text{9}$). You must turn on **exactly two** batteries from each bank. The joltage output is the 2-digit number formed by the digits of the two chosen batteries (in the order they appear). The goal is to find the **largest possible 2-digit joltage** from each bank and sum these maximum values to get the total output joltage.

### 💡 Approach
The problem is equivalent to finding the largest possible number that can be formed by deleting all but two digits from the original battery bank string, while maintaining the relative order of the remaining digits.

This is solved using a **Greedy Algorithm** with a Monotonic Stack (implemented using a `std::vector<char>`):

1.  **Goal:** Keep $K=2$ digits (and remove $M = N - K$ digits).
2.  **Iterate and Optimize:** Iterate through the digits of the bank string one by one. Maintain a temporary result vector/stack.
3.  **Greedy Removal:** For each new digit $c$:
    * While the stack is *not empty*, you still have *removal budget* ($M > 0$), and the **last digit in the stack is smaller than the current digit $c$**:
        * Pop the smaller digit from the stack (greedy choice to improve the result's prefix).
        * Decrement the removal budget $M$.
    * Push the current digit $c$ onto the stack.
4.  **Final Truncation:** After processing all digits, if the stack is longer than the required length $K=2$, pop the trailing digits until the length is exactly $K=2$.
5.  **Calculate Total:** Convert the resulting 2-digit string to a number and add it to the running $\text{long long}$ `total`.

### 💻 Solution Location (C++)
The C++ code for Part 1, using the `pickBest(s, 2)` function, can be found in the repository at:
**[View C++ Code for Part 1](./Day3/Part1.cpp)**
**[View Input](./Day3/input.txt)**

</details>

<details>
  <summary><h2>🌟 Part 2: Max 12-Digit Joltage (Answer: 170520923035051)</h2></summary>

### 📝 Description
Due to static friction, the escalator needs more joltage. The new requirement is to turn on **exactly twelve** batteries ($\text{K}=12$) within each bank. The total output joltage is the sum of the maximum 12-digit joltages from each bank.

### 💡 Approach
The approach is identical to Part 1, but the target length $K$ is changed from 2 to 12.

1.  **Algorithm Re-use:** The `pickBest` function, which solves the "remove $M$ digits to maximize the result" problem, remains the correct tool.
2.  **New Target Length:** Call the function with $K=12$: `pickBest(s, 12)`.
3.  **Data Type Consideration:** Since the resulting numbers are 12 digits long, they fit within a standard $\text{long long}$ for individual results. However, the puzzle answer is much larger (over $1.7 \times 10^{14}$), suggesting the total sum might exceed the standard 64-bit integer limit if the input were very large. Given your final answer, the cumulative sum should be calculated with caution, but the core logic relies only on the change in $K$.

### 💻 Solution Location (C++)
The C++ code for Part 2, using the `pickBest(s, 12)` function, can be found in the repository at:
**[View C++ Code for Part 2](./Day3/Part2.cpp)**
**[View Input](./Day3/input.txt)**

</details>

# 📦 Day 4: Printing Department

<details>
  <summary><h2>🌟 Part 1: Initial Accessible Rolls (Answer: 1604)</h2></summary>

### 📝 Description
You are in the Printing Department, where rolls of paper (@) are arranged on a large grid. A roll of paper can be accessed by a forklift if it has **fewer than four** other rolls of paper in its eight adjacent positions (including diagonals). You need to find the total count of rolls that are accessible in the initial configuration.

### 💡 Approach
This is a straightforward grid traversal and neighbor-counting problem.

1.  **Read Grid:** Read the input line by line into a `vector<string>` to represent the grid.
2.  **Traverse:** Iterate over every cell $(i, j)$ in the grid.
3.  **Check Roll:** If the current cell `grid[i][j]` is a paper roll ('@'), proceed to count its neighbors.
4.  **Count Neighbors:** Check all eight surrounding cells (up, down, left, right, and four diagonals). Ensure the checks stay within the grid boundaries. For each adjacent cell that contains a paper roll ('@'), increment a counter, `countneighbors`.
5.  **Check Accessibility:** If `countneighbors` is less than $\text{4}$, the roll is accessible. Increment the `total` count.

### 💻 Solution Location (C++)
The C++ code for Part 1 can be found in the repository at:
**[View C++ Code for Part 1](./Day4/Part1.cpp)**
**[View Input](./Day4/input.txt)**

</details>

<details>
  <summary><h2>🌟 Part 2: Total Removable Rolls (Answer: 9397)</h2></summary>

### 📝 Description
Once an accessible roll is removed (changed from '@' to '.'), this removal may make newly freed-up neighbors accessible to a forklift in the next step. The process must be repeated: identify all accessible rolls in the current configuration, remove them, and repeat the process until no more rolls can be accessed. The goal is to find the **total number of rolls removed** throughout the entire iterative process. 

### 💡 Approach
This part requires a simulation loop that continues until a stable state (no more removals) is reached.

1.  **Initial Setup:** Initialize the grid and a `totalRemoved` counter.
2.  **Simulation Loop (`while (true)`):**
    * **Identify Removals:** Create a list (`toRemove`) to store the coordinates of all rolls accessible in the *current* state of the grid.
    * **Check Accessibility:** Iterate over the entire grid. For every '@', count its '@' neighbors exactly as in Part 1. If the neighbor count is less than 4, add its coordinates to `toRemove`.
    * **Termination:** If `toRemove` is empty after checking the whole grid, break the loop.
    * **Execute Removals:** Iterate through the `toRemove` list and update the grid: set `grid[i][j] = '.'` for each coordinate.
    * **Update Total:** Add the size of `toRemove` to `totalRemoved`.
3.  **Final Result:** Output `totalRemoved`.

**Crucial Detail:** All rolls accessible in a single step must be identified based on the grid state **at the beginning of that step** and then removed simultaneously. Your solution correctly implements this by collecting coordinates in `toRemove` before modifying the grid.

### 💻 Solution Location (C++)
The C++ code for Part 2 can be found in the repository at:
**[View C++ Code for Part 2](./Day4/Part2.cpp)**
**[View Input](./Day4/input.txt)**

</details>

# ☕ Day 5: Cafeteria

<details>
  <summary><h2>🌟 Part 1: Count Fresh Available IDs (Answer: 525)</h2></summary>

### 📝 Description
The input consists of two sections: a list of **fresh ingredient ID ranges** (inclusive and possibly overlapping), followed by a blank line, and then a list of **available ingredient IDs**. An ingredient is fresh if its ID falls within *any* of the fresh ID ranges. The goal is to determine how many of the available ingredient IDs are fresh.

### 💡 Approach
The core difficulty lies in efficiently checking the large number of available IDs against potentially overlapping fresh ranges. Your solution handles this by first merging the ranges.

1.  **Parse Input:** Read the file, separating the fresh ID ranges (Section 1) from the available IDs (Section 2). Store ranges as $(start, end)$ pairs and available IDs in a list.
2.  **Merge Overlapping Ranges (Preprocessing):** 
    * **Sort:** Sort the fresh ID ranges based on their starting value.
    * **Merge:** Iterate through the sorted ranges, merging any adjacent range $A$ into range $B$ if $A.\text{end} \ge B.\text{start}$ (since the ranges are inclusive, they merge if they touch or overlap). Update the merged range $A.\text{end}$ to be $\max(A.\text{end}, B.\text{end})$. This creates a minimal set of non-overlapping fresh ranges.
3.  **Check Available IDs:** Iterate through the list of available ingredient IDs. For each ID:
    * **Binary Search/Linear Scan:** Check if the ID falls into any of the *merged* non-overlapping fresh ranges. (Since the list of merged ranges is much smaller, this check is very fast).
    * **Count:** If the ID is found within a range, increment the count and move to the next available ID.

### 💻 Solution Location (C++)
The C++ code for Part 1, which implements the range merging logic, can be found in the repository at:
**[View C++ Code for Part 1](./Day5/Part1.cpp)**
**[View Input](./Day5/input.txt)**

</details>

<details>
  <summary><h2>🌟 Part 2: Total Fresh IDs in Ranges (Answer: 333892124923577)</h2></summary>

### 📝 Description
Part 2 disregards the list of available IDs and asks for the **total count of all unique ingredient IDs** considered fresh by the original fresh ID ranges. The range values are very large, meaning the total count must be stored in a $\text{long long}$ (or larger) data type.

### 💡 Approach
This part is entirely solved by the **Range Merging** logic developed in Part 1.

1.  **Parse & Merge:** Perform the exact same range parsing, sorting, and merging steps as in Part 1 to obtain a minimal list of non-overlapping fresh ID ranges.
2.  **Sum Lengths:** Once the ranges are merged, the total number of fresh IDs is simply the sum of the lengths of all the resulting non-overlapping ranges.
3.  **Calculate Range Length:** For a range $[L, R]$ (inclusive), the length (number of IDs) is $R - L + 1$.
4.  **Final Total:** Sum the length of every merged range and store the result in a $\text{long long}$ to accommodate the massive size.

### 💻 Solution Location (C++)
The C++ code for Part 2, focusing solely on the range merging and summation, can be found in the repository at:
**[View C++ Code for Part 2](./Day5/Part2.cpp)**
**[View Input](./Day5/input.txt)**

</details>

# 🐙 Day 6: Trash Compactor

<details>
  <summary><h2>🌟 Part 1: Standard Vertical Math (Answer: 4951502530386)</h2></summary>

### 📝 Description
You must help the cephalopods with their math worksheet. The input is a multi-line, wide grid representing a sequence of math problems. Each problem is a vertical column of numbers, with the operation ($\text{+}$ or $\text{*}$) at the bottom. Problems are separated by a full column of spaces. The numbers within a column need to be combined using the indicated operation. The final answer is the **grand total** of adding together the result of all individual problems.

### 💡 Approach
This part requires recognizing that the input is structured as a grid where each math problem corresponds to a single logical column.

1.  **Read and Tokenize:** Read all lines of the input. Because the numbers and operators within a single line are space-separated, the easiest way to handle this is to treat the input as a set of tokens arranged in a grid (`vector<vector<string>> data`). Pad shorter rows with a placeholder (like "0") to match the width of the row containing the operators.
2.  **Determine Problems:** The number of problems is equal to the number of tokens in the last row (the operator row).
3.  **Calculate Problem Results:** Iterate through each column $i$:
    * Identify the operator at `data[R-1][i]`.
    * If the operator is $\text{+}$, initialize a sum to $\text{0}$ and add the numerical value of `data[r][i]` for all rows $r < R-1$.
    * If the operator is $\text{*}$, initialize a product to $\text{1}$ and multiply by the numerical value of `data[r][i]` for all rows $r < R-1$.
4.  **Grand Total:** Sum the results of all individual problems. Use $\text{long long}$ for all calculations to prevent overflow.

### 💻 Solution Location (C++)
The C++ code for Part 1 can be found in the repository at:
**[View C++ Code for Part 1](./Day6/Part1.cpp)**
**[View Input](./Day6/input.txt)**

</details>

<details>
  <summary><h2>🌟 Part 2: Right-to-Left Columnar Numbers (Answer: 8486156119946)</h2></summary>

### 📝 Description
The cephalopods reveal a new rule: the numbers themselves are written **right-to-left in columns**, with the most significant digit at the top. The structure of the problems (vertical column of numbers, operator at the bottom, problems separated by spaces) remains the same. You must re-parse the numbers and recalculate the grand total.

### 💡 Approach
The key challenge is correctly reconstructing the numbers, as a number now spans multiple rows but only a single column width, and its digits appear vertically.

1.  **Grid Reconstruction:** Read the input lines and pad them with spaces to a uniform width $W$. This ensures true columnar alignment.
2.  **Identify Problems:** Determine the start and end column indices for each problem by finding columns that are not all spaces (non-separator columns). 
3.  **Number Reconstruction:** For each problem (group of columns from $start$ to $end$):
    * Iterate through the columns within the problem's range. Each column is a single number.
    * For a specific column $c$:
        * Build a number string by reading the non-space characters from top row $r=0$ down to $r=R-2$. This sequence of digits forms the actual number.
        * Convert the resulting string to a $\text{long long}$.
    * Collect all these reconstructed numbers into a list for the current problem.
4.  **Calculate and Sum:** Use the operator (found in the last row) on the list of reconstructed numbers to find the problem's result. Add this result to the $\text{long long}$ `grandTotal`.

### 💻 Solution Location (C++)
The C++ code for Part 2, which involves complex parsing to reconstruct the numbers, can be found in the repository at:
**[View C++ Code for Part 2](./Day6/Part2.cpp)**
**[View Input](./Day6/input.txt)**

</details>

# 🔬 Day 7: Laboratories

<details>
  <summary><h2>🌟 Part 1: Count Beam Splits (Answer: 1546)</h2></summary>

### 📝 Description
A tachyon beam enters a manifold at $\text{S}$ and always travels downward. The beam passes freely through empty space ('.'). When it hits a splitter ('^'), the beam stops, and two new beams are emitted, one from the immediate left and one from the immediate right of the splitter. This process continues until all beams reach a splitter or exit the manifold. The goal is to find the total number of times the beam is split.

### 💡 Approach
This problem can be solved by simulating the path of the tachyon beams using **Depth First Search (DFS)**, ensuring we only count each splitter once, even if it is hit by multiple beams.

1.  **Grid Setup:** Store the manifold diagram as a grid. Identify the starting position $\text{S}$.
2.  **DFS Simulation:** Start a DFS from the cell immediately below $\text{S}$, moving downward.
3.  **Visited Tracking:** Use a $\text{set}$ (`vis`) to store the coordinates $(r, c)$ of every cell that has been traversed by *any* part of a beam. This prevents infinite loops and redundant exploration in empty space.
4.  **Movement Logic:**
    * **Empty Space ('.'):** If the current cell is '.', continue the DFS downward: $\text{dfs}(r+1, c)$.
    * **Splitter ('^'):** If the current cell is a splitter, increment the `splitCount`. Then, initiate two new DFS calls for the split paths: $\text{dfs}(r, c-1)$ (left) and $\text{dfs}(r, c+1)$ (right).
5.  **Base Case:** The DFS stops if the beam moves out of bounds or reaches a cell already in `vis`.

### 💻 Solution Location (C++)
The C++ code for Part 1 can be found in the repository at:
**[View C++ Code for Part 1](./Day7/Part1.cpp)**
**[View Input](./Day7/input.txt)**

</details>

<details>
  <summary><h2>🌟 Part 2: Count Timelines (Answer: 13883459503480)</h2></summary>

### 📝 Description
In a quantum tachyon manifold, a single particle takes **both** the left and right path at every splitter, causing a split in the timeline. The total number of timelines active after the particle completes its journey is the total number of unique paths from $\text{S}$ to the exit boundary.

### 💡 Approach
Since the number of timelines grows exponentially and the paths can overlap, this problem is equivalent to finding the number of distinct paths in a Directed Acyclic Graph (DAG) and is best solved using **Dynamic Programming (or Memoization)**.

1.  **Memoization Setup:** Use a map (`memo`) to store the result for each cell $(r, c)$: `memo[(r, c)] = \text{number of timelines that can reach the exit from this cell}`.
2.  **Recursive Function (`countTimelines(r, c)`):**
    * **Base Case (Exit):** If the particle is out of bounds ($\text{r < 0 || r >= R || c < 0 || c >= C}$), it has completed a journey, so return $\text{1}$ (one successful timeline).
    * **Memo Check:** If the result for $(r, c)$ is already in `memo`, return the cached value.
    * **Movement Logic:**
        * **Empty Space ('.'):** The particle must move downward. The number of timelines is equal to the number of timelines from the cell below: $\text{countTimelines}(r + 1, c)$.
        * **Splitter ('^'):** The particle splits into two timelines (left and right). The total number of timelines from this splitter is the sum of timelines from the left path and the right path: $\text{countTimelines}(r, c - 1) + \text{countTimelines}(r, c + 1)$.
    * **Store and Return:** Store the calculated result in `memo` and return it.

### 💻 Solution Location (C++)
The C++ code for Part 2, using memoization to efficiently calculate the paths, can be found in the repository at:
**[View C++ Code for Part 2](./Day7/Part2.cpp)**
**[View Input](./Day7/input.txt)**

</details>

# 🔌 Day 8: Playground

<details>
  <summary><h2>🌟 Part 1: Multiply Top 3 Circuit Sizes (Answer: 68112)</h2></summary>

### 📝 Description
You are given the 3D coordinates ($\text{X}, \text{Y}, \text{Z}$) of many electrical junction boxes. By connecting the two closest unconnected boxes, electricity flows between them, merging their circuits. This process is repeated for the $\text{1000}$ shortest possible connections. After $\text{1000}$ connections, you need to find the sizes of all resulting circuits, identify the three largest sizes, and multiply them together.

### 💡 Approach
This is a problem about forming connected components based on the shortest edges, which is efficiently solved using the **Disjoint Set Union (DSU)** data structure.

1.  **Parse Coordinates:** Read all $(\text{X}, \text{Y}, \text{Z})$ coordinates into a list of points.
2.  **Generate Edges:** Calculate the distance squared ($\text{dist}^2$) between *every* unique pair of points. Storing $\text{dist}^2$ is sufficient since we only care about the relative order of distances, avoiding floating-point math. Store each connection as an edge tuple: $(\text{distance}^2, \text{index A}, \text{index B})$.
3.  **Sort Edges:** Sort the list of edges in ascending order based on the distance.
4.  **DSU Initialization:** Initialize a DSU structure where each point is its own set (circuit). The DSU also needs to track the size of each set.
5.  **Process Top 1000:** Iterate through the first $\text{1000}$ shortest edges:
    * For each edge $(u, v)$: If $u$ and $v$ are not already in the same set ($\text{find}(u) \neq \text{find}(v)$), unite them using DSU's $\text{unite}(u, v)$ operation.
6.  **Calculate Result:** After $\text{1000}$ connections, gather the size of every resulting circuit from the DSU structure, sort these sizes in descending order, and multiply the top three. 

### 💻 Solution Location (C++)
The C++ code for Part 1, utilizing the DSU structure, can be found in the repository at:
**[View C++ Code for Part 1](./Day8/Part1.cpp)**
**[View Input](./Day8/input.txt)**

</details>

<details>
  <summary><h2>🌟 Part 2: Last Connection for Full Circuit (Answer: 44543856)</h2></summary>

### 📝 Description
The process of connecting the shortest unconnected pairs continues until all junction boxes are in **one single circuit**. You must identify the very last connection that achieves this goal and multiply the $\text{X}$ coordinates of the two junction boxes involved in that final connection.

### 💡 Approach
This is fundamentally asking for the **maximum weight edge** on the path between the two most distant points in the Minimum Spanning Tree (MST), or more simply, applying Kruskal's algorithm until only one component remains.

1.  **Preparation (Same as Part 1):** Parse coordinates, generate all possible edges with $\text{dist}^2$, and sort the edges by distance.
2.  **DSU with Component Counter:** Use the DSU structure, but enhance it to track the total number of independent circuits (`components`), initialized to $N$ (the number of points).
3.  **Kruskal's Simulation:** Iterate through the sorted edges, connecting them using $\text{unite}(u, v)$.
    * The DSU's $\text{unite}$ function should decrement the `components` counter only if a successful merge occurs.
    * **Termination:** Immediately after a successful merge, check if `components == 1`.
    * **Final Answer:** If the condition is met, the current edge $(u, v)$ is the last required connection. The answer is $\text{X}_u \times \text{X}_v$.

### 💻 Solution Location (C++)
The C++ code for Part 2, which implements a version of Kruskal's algorithm to track the components count, can be found in the repository at:
**[View C++ Code for Part 2](./Day8/Part2.cpp)**
**[View Input](./Day8/input.txt)**

</details>

# 🎬 Day 9: Movie Theater

<details>
  <summary><h2>🌟 Part 1: Largest Area, Red Corners Only (Answer: 4759531084)</h2></summary>

### 📝 Description
Given a list of red tile coordinates $(\text{X}, \text{Y})$, find the largest rectangle that can be formed using any two red tiles as opposite corners. The area of a rectangle spanning from $(x_1, y_1)$ to $(x_2, y_2)$ is defined as $(\text{width}) \times (\text{height})$, where width is $|x_2 - x_1| + 1$ and height is $|y_2 - y_1| + 1$ (since the tiles themselves are included).

### 💡 Approach
Since there is no constraint on the tiles *inside* the rectangle, this is a brute-force geometric check.

1.  **Parse Coordinates:** Read all red tile coordinates into a list.
2.  **Brute-Force Check:** Iterate over every unique pair of red tiles $(i, j)$.
3.  **Calculate Area:** For the pair of tiles $(\text{x}_i, \text{y}_i)$ and $(\text{x}_j, \text{y}_j)$:
    * $\text{Width} = |\text{x}_j - \text{x}_i| + 1$
    * $\text{Height} = |\text{y}_j - \text{y}_i| + 1$
    * $\text{Area} = \text{Width} \times \text{Height}$
4.  **Find Maximum:** Track the maximum area found across all pairs.

### 💻 Solution Location (C++)
The C++ code for Part 1 can be found in the repository at:
**[View C++ Code for Part 1](./Day9/Part1.cpp)**
**[View Input](./Day9/input.txt)**

</details>

<details>
  <summary><h2>🌟 Part 2: Largest Area, Red/Green Tiles Only (Answer: 1539238860)</h2></summary>

### 📝 Description
The rectangle must still use two red tiles as opposite corners, but now **every tile** within the rectangle must be either red or green. Green tiles are defined as:
1.  All tiles on the straight lines connecting adjacent red tiles (the boundary).
2.  All tiles enclosed *inside* this closed loop formed by the red/green boundary.

### 💡 Approach
The constraint that the entire rectangle must be within the red/green loop dramatically changes the problem. The brute-force check must be maintained, but augmented with three checks using coordinate compression and computational geometry:

1.  **Coordinate Compression (Handling Large, Sparse Coordinates):** The grid is massive, but only the coordinates of the red tiles matter. This technique transforms the large coordinates into indices in a smaller, dense grid, where each cell represents a region of tiles.
    * Sort and unique all X-coordinates and Y-coordinates.
    * Map each unique coordinate to a compressed index.
    * Map the gap between coordinates (e.g., $X_2 - X_1 - 1$) to the size/weight of the region represented by the new compressed index.
2.  **Validity Check ($\text{is\_valid}$):** For a rectangle defined by red corners $(x_1, y_1)$ and $(x_2, y_2)$, the rectangle is valid only if:
    * **Corners:** All four corners of the rectangle are inside or on the red/green boundary. (Your `inside` and `onBoundary` functions address this, using a point-in-polygon algorithm like the winding number or ray casting algorithm on a modified point: $\text{query.x} + 0.5$, $\text{query.y} + 0.5$). 
    * **No Boundary Crossing:** None of the red/green boundary segments cross the interior of the rectangle. (Your `rectangle_crosses_boundary` function checks this by ensuring no horizontal or vertical boundary segment passes between the rectangle's minimum and maximum coordinates.)
3.  **2D Prefix Sum (Efficient Area Calculation):**
    * Create a 2D grid of the size of the compressed coordinates.
    * Initialize each cell with the area it represents (i.e., $\text{x\_size}[i] \times \text{y\_size}[j]$).
    * Compute a 2D prefix sum array over this compressed grid.
    * When a valid rectangle is found, use the prefix sum array to quickly calculate the true total area of the tiles within the compressed rectangle defined by the corner indices $\text{(cx}_1, \text{cy}_1)$ and $\text{(cx}_2, \text{cy}_2)$.

### 💻 Solution Location (C++)
The complex C++ code for Part 2, featuring coordinate compression and geometric checks, can be found in the repository at:
**[View C++ Code for Part 2](./Day9/Part2.cpp)**
**[View Input](./Day9/input.txt)**

</details>

# 🏭 Day 10: Factory

<details>
  <summary><h2>🌟 Part 1: Minimum Presses for Lights (Answer: 457)</h2></summary>

### 📝 Description
Each machine has indicator lights (initially off) and buttons. Each button toggles the state of a specified subset of lights. The goal is to find the **fewest total button presses** required to match a target light configuration. Since state changes are toggles, this is equivalent to solving a system of linear equations in the finite field $GF(2)$ (arithmetic modulo 2).

### 💡 Approach
Let $N$ be the number of lights and $M$ be the number of buttons. We are looking for a solution vector $\vec{x} \in \{0, 1\}^M$ that minimizes $||\vec{x}||_1$ (the number of 1s in $\vec{x}$) such that:
$$A \vec{x} \equiv \vec{b} \pmod 2$$
where $A$ is an $N \times M$ matrix (the toggle matrix), and $\vec{b}$ is the $N \times 1$ target vector.

1.  **Matrix Setup:** Construct the augmented matrix $[A | \vec{b}]$ where $A_{i, j} = 1$ if button $j$ toggles light $i$, and $\vec{b}_i = 1$ if light $i$ must be on.
2.  **Gaussian Elimination $\pmod 2$:** Reduce the augmented matrix to row echelon form using XOR operations (addition $\pmod 2$).
3.  **Check Consistency:** If a row of the form $[0, 0, \dots, 0 | 1]$ exists, no solution is possible.
4.  **Find Minimum Press Solution:** When a system has multiple solutions (i.e., it has free variables), the general solution is $\vec{x} = \vec{x}_{\text{particular}} + c_1 \vec{v}_1 + c_2 \vec{v}_2 + \dots$ where $c_i \in \{0, 1\}$ and $\vec{v}_i$ are basis vectors for the null space.
    * The number of free variables is $k = M - \text{rank}(A)$.
    * Since $k$ is small, all $2^k$ possible combinations for the free variables are checked.
    * For each combination, the full solution $\vec{x}$ is constructed, and the sum of its elements (the total presses) is minimized. 

### 💻 Solution Location (C++)
The C++ code for Part 1, implementing Gaussian Elimination $\pmod 2$ and exhaustive search of the solution space, can be found in the repository at:
**[View C++ Code for Part 1](./Day10/Part1.cpp)**
**[View Input](./Day10/input.txt)**

</details>

<details>
  <summary><h2>🌟 Part 2: Minimum Presses for Joltage (Answer: 17576)</h2></summary>

### 📝 Description
In this mode, button presses increase the joltage counters by 1 (instead of toggling lights). The goal is to find the **fewest total button presses** to meet a positive integer joltage requirement vector. The number of presses must be non-negative integers.

### 💡 Approach
This is a standard **Integer Linear Programming (ILP)** problem. Let $x_j$ be the number of times button $j$ is pressed. We want to find a solution vector $\vec{x} \in \mathbb{N}_0^M$ that minimizes the total presses $\sum x_j$ such that:
$$A \vec{x} = \vec{b}$$
where $A$ is the $N \times M$ matrix (same structure as before), and $\vec{b}$ is the target joltage vector.

This problem is computationally hard to solve in a general-purpose programming language without specialized solvers. The solution uses the $\text{Z3}$ optimization library:

1.  **Define Variables:** Create an integer variable $x_i$ for each button $i$, representing the number of presses.
2.  **Constraints:**
    * **Non-negativity:** $x_i \ge 0$ for all $i$.
    * **Target Equations:** For each joltage counter $i$, the sum of presses on buttons that affect counter $i$ must equal the target joltage $b_i$.
3.  **Objective:** Minimize the sum of all variables: $\text{Minimize } \sum x_i$.
4.  **Solve:** The solver finds the minimum non-negative integer solution that satisfies all constraints.

### 💻 Solution Location (Python/Z3)
The Python code for Part 2, utilizing the $\text{Z3}$ library to solve the ILP, can be found in the repository at:
**[View Python Code for Part 2](./Day10/Part2.py)**
**[View Input](./Day10/input.txt)**

</details>

# ⚛️ Day 11: Reactor

<details>
  <summary><h2>🌟 Part 1: Count Simple Paths (Answer: 636)</h2></summary>

### 📝 Description
Given a network of devices and their connections (a directed graph), find the total number of distinct paths from the starting node (`you`) to the end node (`out`). Since the problem specifies "Data only ever flows from a device through its outputs; it can't flow backwards," and implies finding all paths, we must handle cycles if they exist in the input.

### 💡 Approach
This problem is solved using a recursive **Depth First Search (DFS)** algorithm with a mechanism to prevent infinite loops caused by cycles.

1.  **Graph Representation:** Parse the input into an adjacency list (e.g., `unordered_map<string, vector<string>>`) where keys are devices and values are their output neighbors.
2.  **DFS with Cycle Detection:** The `dfsCount` function is implemented to:
    * **Base Case 1:** If the current `node` is `"out"`, return $1$ (one successful path found).
    * **Cycle Detection:** Use a `set` (`onPath`) to track all nodes currently on the path from the starting node to the current node. If a neighbor is already in `onPath`, that connection is skipped to avoid cycling (since the problem only asks for unique paths, a path involving a cycle is technically a different path, but typically in these problems, cycles are excluded to find *simple* paths).
    * **Recursive Step:** For each neighbor, recursively call `dfsCount` and sum the results.
    * **Backtracking:** Remove the current `node` from `onPath` before returning to allow it to be visited again in a different path branch.

### 💻 Solution Location (C++)
The C++ code for Part 1, implementing DFS with cycle detection, can be found in the repository at:
**[View C++ Code for Part 1](./Day11/Part1.cpp)**
**[View Input](./Day11/input.txt)**

</details>

<details>
  <summary><h2>🌟 Part 2: Count Paths Visiting Two Required Nodes (Answer: 509312913844956)</h2></summary>

### 📝 Description
Find the total number of paths from a new start node (`svr`) to the end node (`out`). Crucially, the path must visit two specific nodes, `dac` and `fft`, in any order.

### 💡 Approach
The large answer suggests that cycles must be allowed in the graph, as excluding them leads to a number that is typically much smaller. When cycles are allowed, simple DFS becomes slow due to re-computation. This structure (finding path counts in a potentially cyclic graph, often implicitly a DAG based on node ordering or problem constraints) calls for **Dynamic Programming (or Memoization)**.

1.  **State Definition:** The state of the DFS/DP must include not just the current node, but also the required information: whether `dac` and `fft` have been visited so far.
    * $\text{State} = (\text{node}, \text{dacVisited}, \text{fftVisited})$
2.  **Memoization Table:** Use a map to store results: $\text{memo}[\text{node}][\text{state\_key}] = \text{number of valid paths from this point}$. The state key can be simplified (e.g., a string or integer representing the combination of two boolean values).
3.  **Recursive Function (`dfs`):**
    * **Update State:** When entering a node, update the `dacVisited` or `fftVisited` flags if the node is `dac` or `fft`.
    * **Base Case (Target):** If $\text{node} = \text{"out"}$, return $1$ if both flags are true, and $0$ otherwise.
    * **Recursive Step:** Calculate the total paths by summing the results of recursive calls to all neighbors, passing the *updated* state flags to the next call.
    * **Memoization:** Store the result in the `memo` table before returning.

This DP approach is efficient because the total number of states is small ($\text{Number of Nodes} \times 4$ different flag combinations), allowing the large count of non-simple paths to be computed quickly.

### 💻 Solution Location (C++)
The C++ code for Part 2, implementing DFS with memoization on the required state flags, can be found in the repository at:
**[View C++ Code for Part 2](./Day11/Part2.cpp)**
**[View Input](./Day11/input.txt)**

</details>

# 🎄 Day 12: Christmas Tree Farm

<details>
  <summary><h2>🌟 Part 1: Fit Presents in Regions (Answer: 497)</h2></summary>

### 📝 Description
Given a list of present shapes (polycubes on a 2D grid) and a list of rectangular regions with a required count of each shape, determine how many regions can successfully fit all the required presents. Presents can be rotated and flipped. They must align perfectly with the unit grid and cannot overlap.

### 💡 Approach
This is a complex constraint satisfaction and tiling problem. Since the number of presents and the size of the regions are relatively small, it can be solved using a systematic **Backtracking Search** algorithm.

1.  **Shape Pre-processing:**
    * **Normalize:** Represent each shape as a set of relative $(r, c)$ coordinates, starting from $(0, 0)$.
    * **Generate Variants:** For each unique shape, generate all its possible unique orientations (rotations and flips). This minimizes redundant work during the main search. 

2.  **Backtracking Search (The $\text{solve}$ function):**
    * The goal is to place a sequence of present instances into the $\text{Grid}(\text{W} \times \text{H})$.
    * **Base Case:** If all required presents are placed, return $\text{True}$.
    * **Recursive Step:** For the current present, iterate over every possible cell $(\text{r}, \text{c})$ in the grid.
        * If the present's current variant can be placed at $(\text{r}, \text{c})$ without going out of bounds or overlapping an already placed present (`canPlace`):
            * $\text{Place}$ the present.
            * Recursively call $\text{solve}$ for the next present.
            * If the recursive call succeeds, return $\text{True}$.
            * If it fails, $\text{Unplace}$ the present (backtrack) and continue the loop to try the next position $(\text{r}, \text{c})$.
    * If no position works, return $\text{False}$.

3.  **Outer Variant Search (The $\text{tryVariants}$ function):**
    * Since a region may require multiple instances of the *same* shape (e.g., two shape 4s), and each instance can use a different variant (rotation/flip), we must search the combinations of variants first.
    * The $\text{tryVariants}$ function iterates through all combinations of variants for the required presents. For each combination, it collects the specific set of coordinates for all presents and then calls the main $\text{solve}$ function to attempt placement.

### 💻 Solution Location (C++)
The C++ code for Day 12, implementing the backtracking and variant search logic, can be found in the repository at:
**[View C++ Code for Day 12](./Day12/Part1.cpp)**
**[View Input](./Day12/input.txt)**

</details>

<details>
  <summary><h2>🌟 Part 2: Completion</h2></summary>
  
Part 2 of this puzzle was a narrative continuation and did not present a new computational problem. All the required stars were collected through the previous days..
</details>
