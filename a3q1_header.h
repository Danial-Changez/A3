#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#ifndef BINARY_TREE
#define BINARY_TREE

// Node structure representing a binary tree node containing string data.
typedef struct Node
{
    char data[10];
    struct Node *left, *right;
} Node;

// Structure that stores variable names and their associated values.
typedef struct
{
    char varName[10];
    float value;
} Variable;

extern Variable variables[10];
extern int varCount;

bool areParenthesesBalanced(const char *expr);
Variable *getOrCreateVariable(char *name);
Node *createNode(char *data);
Node *parseExpression(char *expr);
void preorder(Node *root);
void inorder(Node *root);
void postorder(Node *root);
void promptVariables(Node *root);
float calculate(Node *root);

#endif
