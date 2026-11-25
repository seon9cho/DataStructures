# DataStructures

This repo contains labs related to data structures coded during college. 
The folders starting with **Lab** are from CS classes and are coded in C++ whereas the ones with **(py)** at the end are from ACME and are coded in Python.

## ACME labs

My solutions to the data structure labs from BYU's Applied and Computational Mathematics Emphasis (ACME), drawn from *Volume 2* of the lab manuals. Each lab is a notebook that pairs the spec's problem statements with my solutions and their output, plus condensed notes on the concepts the lab covers.

| Lab | Volume | Notebook |
|-----|--------|----------|
| Linked Lists | Vol. 2, Lab 1 | [LinkedLists (py)/linked_lists.ipynb](<LinkedLists (py)/linked_lists.ipynb>) |
| Binary Search Trees | Vol. 2, Lab 2 | [Trees (py)/trees.ipynb](<Trees (py)/trees.ipynb>) |
| Breadth-First Search | Vol. 2, Lab 4 | Not completed |

Each folder also keeps the grader feedback from my original submissions (`*_feedback.txt`). Each notebook runs from its own folder, with `english.txt` next to it, and needs NumPy and Matplotlib.

## CS 235 labs

My C++ labs from CS 235 (Data Structures). Each lab implemented an interface the course provided; the course's own test driver isn't included, so each `main.cpp` is a small driver or menu I used while working on it.

| Lab | What it implements | Sources to compile |
|-----|--------------------|--------------------|
| [Lab 1 - RPG](<Lab 1 - RPG>) | An arena of fighters (robot, archer, cleric), each with its own damage, regeneration and special ability, created through a factory | `main.cpp Fighter.cpp Factory.cpp` |
| [Lab 2 - Linked List](<Lab 2 - Linked List>) | A templated singly linked list without duplicates | `main.cpp` |
| [Lab 3 - Shunting Yard](<Lab 3 - Shunting Yard>) | Bracket balancing, infix-to-postfix and postfix-to-infix conversion, and postfix evaluation; `part1`–`part4.txt` are sample inputs | `main.cpp ExpressionManager.cpp` |
| [Lab 4 - Railroad](<Lab 4 - Railroad>) | A railroad switching station that moves cars between a stack, a queue and three kinds of deque, all built on hand-written linked containers | `main.cpp Station.cpp` |
| [Lab 5 - 3D Maze](<Lab 5 - 3D Maze>) | Loads, validates and randomly generates 5×5×5 mazes and solves them by recursive depth-first search | `main.cpp Pathfinder.cpp` |
| [Lab 6 - BST](<Lab 6 - BST>) | An integer binary search tree with add, remove and clear | `main.cpp BST.cpp Node.cpp` |
| [Lab 7 - Maps and Sets](<Lab 7 - Maps and Sets>) | Student records in a `std::map` by ID and a `std::set` by name, with grade import, GPA calculation and queries; sample data in `Files/` | `main.cpp` |
| [Lab 8 - Quicksort](<Lab 8 - Quicksort>) | Quicksort on a dynamic array, with median-of-three pivot selection and partitioning | `main.cpp QS.cpp` |
| [Lab 9 - AVL Tree](<Lab 9 - AVL Tree>) | A self-balancing AVL tree built on Lab 6's BST, with all four rotations | `main.cpp AVL.cpp Node.cpp` |

Build a lab from its folder with a C++11-or-later compiler, passing the sources listed for it, for example:

```bash
cd "Lab 9 - AVL Tree" && clang++ -std=c++17 main.cpp AVL.cpp Node.cpp -o avl
```

Labs 4 and 6–9 run a numbered command menu on standard input.

## Credits

The ACME lab specifications come from the [Foundations of Applied Mathematics](https://foundations-of-applied-mathematics.github.io/) *Volume 2* lab manual, © Dr. J. Humpherys, licensed under [CC BY 3.0 US](http://creativecommons.org/licenses/by/3.0/us/). `english.txt` comes from the original lab materials. Problem statements are quoted from the specs; the solutions are my own.
