# CIS2520-F24-A3

## **Student Information**
- **Name**: Danial Changez
- **Student Number**: 1232341


## **Table of Contents**
1. [Assignment Overview](#assignment-overview)
2. [Resources](#resources)
3. [Implementation](#implementation)
4. [Testing and Results](#testing-and-results)


## **Assignment Overview**
### **What is the assignment about?**
This assignment involves implementing solutions for two questions, focusing on binary trees and heap structures.

1. **Question 1**:
   - The program parses a fully parenthesized arithmetic expression passed as a command-line argument.
   - It constructs a binary expression tree, performs different traversals (preorder, inorder, or postorder), and evaluates the expressions, supporting variables and floating-point numbers.
   - The program also handles error cases like divide-by-zero or malformed expressions.

2. **Question 2**:
   - The program processes a 2D array of integers (20 rows, 10 columns), treating each row as an object.
   - The first three numbers form the "key," and the rest form the data.
   - It builds a max-heap using the downheap algorithm and outputs the heap in a 2D format.

Both programs provide experience with binary trees and heaps in C.


## **Resources**
### **What resources were used for this assignment?**
In addition to class notes, slides, and examples, I consulted online resources to understand and implement the following:

1. **Makefiles**:
   - I reviewed the basic makefile structure, adjusting the clean and compile lines.
   - [GNU Make Documentation](https://www.gnu.org/software/make/manual/make.html)
   - [A Simple Makefile Tutorial](https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/)

2. **Windows Subsystem for Linux (WSL)**:
   - WSL was used to compile and test executables in a Linux environment on Windows.
   - [Installing and Using WSL](https://learn.microsoft.com/en-us/windows/wsl/install)

3. **Valgrind**:
   - Valgrind was used to detect memory leaks.
   - [Valgrind Documentation](https://valgrind.org/docs/manual/quick-start.html)


## **Implementation**
### **Is the assignment complete?**
Yes, the assignment is complete. Both programs are fully functional and include proper error handling.


## **Testing and Results**
### **Testing Procedure**
- **Question 1**:
  - Tested with various arithmetic expressions, including:
    1. Nested parentheses with variables: `'(((x1+5.12)*(x2-7.68))/x3)'`
    2. Invalid strings: `'((x1+5.12)'` (unbalanced parentheses)
    3. Divide-by-zero: `'(((1.00+2.00)*(3.00-4.00))/0)'`

  - Outputs:
    - Successfully parsed and evaluated expressions.
    - Handled invalid inputs with appropriate error messages.

- **Question 2**:
  - Tested with `f.dat`, containing 200 integers formatted as 20 rows by 10 columns.
  - Verified max-heap construction with correct outputs.

### **Valgrind Testing**
- After adding **fclose** to the main file for q2, **no memory leaks** were detected using Valgrind
  - Command: 
    ```bash
    valgrind --leak-check=full --track-origins=yes ./a3q1
    valgrind --leak-check=full --track-origins=yes ./a3q2
    ```
  - Output confirmed all heap memory was freed:
    ```
    All heap blocks were freed -- no leaks are possible.
    ```
    
