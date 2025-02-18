# Voting Management Simulator

## Overview

The Voting Management Simulator is a project designed to simulate and manage voting processes using various data structures. The project includes implementations of Binary Search Trees (BST), Max Heaps, and Age Vectors to efficiently manage and query voter information.

## Features

- **Binary Search Tree (BST)**: Efficiently stores and retrieves voter information based on unique keys.
- **Max Heap**: Manages voters based on their impact scores.
- **Age Vector**: Organizes voters by age groups for quick access and analysis.


## Efficiency Requirements

| Operation           | Time Complexity |
| ------------------- | --------------- |
| `support`           | O(log N)        |
| `reduce-likelihood` | O(log N)        |
| `chauffeur`         | O(log N)        |
| `voted` & `voter`   | O(log N)        |
| `show-impact`       | O(N)            |


- **What is the expected input format?**
  The input file should contain commands to add voters, query voter information, and manage the voting process. Example:
  ```
  add_voter John Doe 30
  add_voter Jane Smith 25
  show_impact
  ```

## Project Structure

- **What are the key files in this project?**
  - `bst.h / bst.cpp`: Implementation of the Binary Search Tree.
  - `MaxHeap.h / MaxHeap.cpp`: Implementation of the Max Heap.
  - `AgeVector.h / AgeVector.cpp`: Implementation of the Age Vector.
  - `Voter.h / Voter.cpp`: Definition and implementation of the Voter class.
  - `helper.h / helper.cpp`: Utility functions used across the project.
  - `bstTest.cpp`: Unit tests for the BST implementation.
  - `MaxHeapTest.cpp`: Unit tests for the Max Heap implementation.

## Commands

### **1. Add a Voter**
```plaintext
voter <last-name> <first-name> <age>
```
- Adds a new voter to the system
- Name must contain only letters
- Age must be between 18 and 118
- Duplicate voters are not allowed

Example:
```plaintext
: voter Myers Michael 54
New voter Michael Myers, age 54, added.
```

### **2. Mark a Voter as Voted**
```plaintext
voted <last-name> <first-name> <age>
```
- Removes the voter from limo ride consideration

Example:
```plaintext
: voted Bird Earl 87
Voter Earl Bird, age 87, voted.
```

### **3. Increase Voter Support Strength**
```plaintext
support <last-name> <first-name> <strength>
```
- Increases a voter’s support strength (initially 75)
- Strength can only increase

Example:
```plaintext
: support Myers Michael 20
Support from Michael Myers increased by 20 strength points.
```

### **4. Reduce Voter Likelihood**
```plaintext
reduce-likelihood <last-name> <first-name> <reduction>
```
- Reduces the likelihood (initially 75%) of a voter reaching the polls
- Formula: `likelihood = likelihood * (100 - reduction) / 100`

Example:
```plaintext
: reduce-likelihood Myers Michael 10
Voting likelihood of Michael Myers decreased by 10%.
```

### **5. Select a Voter for Transport**
```plaintext
chauffeur
```
- Picks the voter with the highest impact (`impact = strength / likelihood`)
- Removes them from future updates

Example:
```plaintext
: chauffeur
Driving Michael Myers (54): strength of support: 95, likelihood: 67.5, impact: 1.41
```

### **6. Display Voter Impact List**
```plaintext
show-impact
```
- Displays all voters sorted by age with their support strength, likelihood, and impact

Example:
```plaintext
: show-impact
Alice Flanders (18): strength: 150, likelihood: 50, impact: 3.00
Michael Myers (54): strength: 95, likelihood: 67.5, impact: 1.41
Jimmy Carter (100): strength: 1000, likelihood: 10, impact: 100.0
```


## FAQ

### **How do you maintain links between your data structures?**
The BST owns Voter objects and deletes them in its destructor. The MaxHeap and Age Vector hold pointers to these objects.

### **How are memory leaks prevented? Who releases the memory?**
Each BSTNode has a pointer to a Voter and owns it, meaning the BSTNode destructor deletes the Voter objects. The BSTNode is deleted when the BST is deleted.

### **What data structures are sorted by what criteria?**
- **BST**: Sorted by voter name, used for general operations.
- **MaxHeap**: Sorted by **Impact**, used for `chauffeur`.
- **Age Vector**: Sorted by **Age**, used for `show-impact`.

## Testing

### **Example test case:**
```
# Test: voter, voted, and support
>> voter Lai Tulsi 16
out: Voter age should be between 18 and 118
```
- Lines starting with `#` are comments.
- Lines starting with `>>` are user inputs.
- Lines starting with `out:` are expected outputs.

## Setup Instructions

1. **How do I build the project?**
   ```sh
   make
   ```

2. **How do I run the tests?**
   ```sh
   ./bstTest
   ./MaxHeapTest
   ```

## Usage

- **How do I run the simulator?**
  ```sh
  ./lets_vote [input_file]
  ```
  If no input file is provided, the simulator will accept input from the console.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Authors
- **Alex Eskenazi** - Initial work
- **Vishil Patel** - Contributions

## Acknowledgments
- Special thanks to the teaching assistants and professors for their guidance and support.

