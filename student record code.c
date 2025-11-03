// #include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    int roll;
    char name[50];
    float marks;
    struct Student* left;
    struct Student* right;
} Student;

Student* insert(Student* root, int roll, char* name, float marks) {
    switch (root == NULL) {
        case 1:
            root = (Student*)malloc(sizeof(Student));
            root->roll = roll;
            strcpy(root->name, name);
            root->marks = marks;
            root->left = root->right = NULL;
            return root;
    }
    switch (roll < root->roll) {
        case 1:
            root->left = insert(root->left, roll, name, marks);
            break;
        default:
            root->right = insert(root->right, roll, name, marks);
    }
    return root;
}

Student* search(Student* root, int roll) {
    switch (root == NULL || root->roll == roll) {
        case 1:
            return root;
    }
    switch (roll < root->roll) {
        case 1:
            return search(root->left, roll);
        default:
            return search(root->right, roll);
    }
}

void inorder(Student* root) {
    switch (root != NULL) {
        case 1:
            inorder(root->left);
            printf("| %-4d | %-15s | %6.2f |\n", root->roll, root->name, root->marks);
            inorder(root->right);
    }
}

int main() {
    Student* root = NULL;
    int choice, roll;
    char name[50];
    float marks;
    Student* found;
    
    while (1) {
        printf("1.Add 2.Search 3.Display 4.Exit: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Roll: ");
                scanf("%d", &roll);
                printf("Name: ");
                scanf("%s", name);
                printf("Marks: ");
                scanf("%f", &marks);
                root = insert(root, roll, name, marks);
                printf("Added\n");
                break;
            case 2:
                printf("Roll: ");
                scanf("%d", &roll);
                found = search(root, roll);
                switch (found != NULL) {
                    case 1:
                        printf("%d %s %.2f\n", found->roll, found->name, found->marks);
                        break;
                    default:
                        printf("Not found\n");
                }
                break;
            case 3:
                printf("+------+-----------------+--------+\n");
                printf("| Roll  |         Name          | Marks  |\n");
                printf("+------+-----------------+--------+\n");
                inorder(root);
                printf("+------+-----------------+--------+\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid\n");
        }
    }
    return 0;
}
