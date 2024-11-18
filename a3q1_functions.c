#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "a3q1_header.h"

Variable variables[10];
int varCount = 0;

// The createNode function allocates memory to the tree and creates a new node using the given data before returning the node.
Node *createNode(char *data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	strcpy(newNode->data, data);

	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

// The parseExpression function parses the expression string passed in from command line, stores the information in a new node, and returns the root node of the tree.
Node *parseExpression(char *expr)
{
	int len = strlen(expr);
	if (len == 0)
		return NULL;

	// If a single variable or number
	if (expr[0] != '(')
		return createNode(expr);

	// Location of main operator
	int brackets = 0, operatorPos = -1;
	for (int i = 1; i < len - 1; i++)
	{
		if (expr[i] == '(')
			brackets++;
		if (expr[i] == ')')
			brackets--;
		if (brackets == 0 && (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/'))
		{
			operatorPos = i;
			break;
		}
	}

	char leftSub[100], rightSub[100], operator[2];

	// Splitting input into left and right subtrees
	strncpy(leftSub, expr + 1, operatorPos - 1);
	leftSub[operatorPos - 1] = '\0';
	strncpy(rightSub, expr + operatorPos + 1, len - operatorPos - 2);
	rightSub[len - operatorPos - 2] = '\0';

	operator[0] = expr[operatorPos];
	operator[1] = '\0';

	// Creating root node and recursively parse subtrees
	Node *root = createNode(operator);
	root->left = parseExpression(leftSub);
	root->right = parseExpression(rightSub);
	return root;
}

// The preOrder function prints tree nodes in preorder traversal.
void preorder(Node *root)
{
	// Check if NULL
	if (!root)
		return;

	printf("%s ", root->data);
	preorder(root->left);
	preorder(root->right);
}

// The inOrder function prints tree nodes in inorder traversal fully parenthesized.
void inorder(Node *root)
{
	if (!root)
		return;
	if (root->left)
		printf("(");

	inorder(root->left); // Left subtree traversal
	printf("%s", root->data);
	inorder(root->right); // Right subtree traversal

	if (root->right)
		printf(")");
}

// The postOrder function prints tree nodes in postorder traversal.
void postorder(Node *root)
{
	if (!root)
		return;
	postorder(root->left);	// Left subtree traversal
	postorder(root->right); // Right subtree traversal
	printf("%s ", root->data);
}

// The promptVariables function prompts the user to assign values to each variable found in the expression tree. The values should be stored in the Variables struct.
void promptVariables(Node *root)
{
	if (!root)
		return;
	if (isalpha(root->data[0]))
	{
		Variable *var = getOrCreateVariable(root->data);
		printf("Enter value for %s: ", var->varName);
		scanf("%f", &var->value);
	}

	promptVariables(root->left);  // Left subtree traversal
	promptVariables(root->right); // Right subtree traversal
}

// The calculate function calculates the expression and returns its result. Division by 0 and/or other error scenarios should be checked.
float calculate(Node *root)
{
	if (!root)
		return 0;

	// If the node contains a number, return its value
	if (isdigit(root->data[0]) || (root->data[0] == '-' && isdigit(root->data[1])))
		return atof(root->data);

	// If the node contains a variable, retrieve its value
	if (isalpha(root->data[0]))
	{
		Variable *var = getOrCreateVariable(root->data);
		return var->value;
	}

	// Recursively calculate the left and right subtrees
	float left = calculate(root->left);
	float right = calculate(root->right);

	// Perform the operation based on the operator
	if (root->data[0] == '+')
		return left + right;
	if (root->data[0] == '-')
		return left - right;
	if (root->data[0] == '*')
		return left * right;
	if (root->data[0] == '/')
	{
		if (right == 0)
		{
			printf("Error: Division by zero\n");
			return 0;
		}
		return left / right;
	}

	printf("Error: Unknown operator %s\n", root->data);
	return 0;
}

// The areParenthesesBalanced checks if all paratheses are closed by the end of the expression.
bool areParenthesesBalanced(char *expr)
{
	int balance = 0;
	// Checks all characters besides null character
	for (int i = 0; expr[i] != '\0'; i++)
	{
		if (expr[i] == '(')
			balance++;
		if (expr[i] == ')')
			balance--;
		if (balance != 0)
			return false; // More closing than opening or vice versa
	}
	return true;
}

// The isValidExpression validates that the input expression contains valid characters
bool isValidExpression(char *expr)
{
	for (int i = 0; expr[i] != '\0'; i++)
	{
		if (!isdigit(expr[i]) && expr[i] != '.' && expr[i] != '+' &&
			expr[i] != '-' && expr[i] != '*' && expr[i] != '/' &&
			expr[i] != '(' && expr[i] != ')' && !isalpha(expr[i]))
			return false; // Invalid character found
	}
	return true; // All characters are valid
}

/*
 * The getOrCreateVariable function retrieves an existing variable or creates a new one.
 * If the variable is undefined, it assigns a default value of 0.00 and displays a warning.
 */
Variable *getOrCreateVariable(char *name)
{
	// Check if the variable already exists in the list
	for (int i = 0; i < varCount; i++)
	{
		if (strcmp(variables[i].varName, name) == 0)
			return &variables[i];
	}

	// Variable is undefined; print a warning and create a new entry
	printf("Warning: Variable %s is undefined. Using 0.00 as default.\n", name);

	// If space for new variable exists, create a new entry with default value
	if (varCount < 10)
	{
		Variable *var = &variables[varCount++];
		strcpy(var->varName, name);
		var->value = 0.0; // Default value for undefined variables
		return var;
	}

	// If max capacity of variables is reached
	printf("Error: Maximum number of variables reached. Cannot create %s.\n", name);
	return NULL;
}