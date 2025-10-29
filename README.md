💾 Student Management System (BST in C)
🎯 Project Overview
This is a Student Record Management program written in the C language. It uses a Binary Search Tree (BST) to store, organize, and quickly retrieve student records.

The primary key for ordering and searching is the unique Roll Number.

🧠 Data Structure & Operations
The core of the system is the Student structure, which serves as a node in the Binary Search Tree.

Student Data: Each node holds the student's Roll Number, Name, and Marks.

Insertion (insert): Adds a new student, placing the node according to its Roll Number (smaller rolls go to the left, larger rolls to the right).

Search (search): Quickly finds a student record by traversing the tree based on the target Roll Number.

Display (inorder): Prints all records in a neat, tabular format, ensuring they are sorted by Roll Number due to the nature of the inorder traversal.

🖥️ How to Use
The program runs in an infinite loop, providing a simple menu interface:

Add: Enter a Roll Number, Name, and Marks to insert a new student.

Search: Enter a Roll Number to find and display a specific student's data.

Display: Print a table of all records sorted by Roll Number.

Exit: Terminate the program.
