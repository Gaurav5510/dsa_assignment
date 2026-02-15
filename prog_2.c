#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Stack for characters 
typedef struct {
    char items[MAX_SIZE];
    int top;
} CharStack;

// Stack for integers 
typedef struct {
    int items[MAX_SIZE];
    int top;
} IntStack;

// Character Stack Functions
void initCharStack(CharStack* s) {
    s->top = -1;
}

bool isCharStackEmpty(CharStack* s) {
    return s->top == -1;
}

bool isCharStackFull(CharStack* s) {
    return s->top == MAX_SIZE - 1;
}

void pushChar(CharStack* s, char item) {
    if (isCharStackFull(s)) {
        printf("Stack overflow!\n");
        return;
    }
    s->items[++(s->top)] = item;
}

char popChar(CharStack* s) {
    if (isCharStackEmpty(s)) {
        return '\0';
    }
    return s->items[(s->top)--];
}

char peekChar(CharStack* s) {
    if (isCharStackEmpty(s)) {
        return '\0';
    }
    return s->items[s->top];
}

// Integer Stack Functions
void initIntStack(IntStack* s) {
    s->top = -1;
}

bool isIntStackEmpty(IntStack* s) {
    return s->top == -1;
}

bool isIntStackFull(IntStack* s) {
    return s->top == MAX_SIZE - 1;
}

void pushInt(IntStack* s, int item) {
    if (isIntStackFull(s)) {
        printf("Stack overflow!\n");
        return;
    }
    s->items[++(s->top)] = item;
}

int popInt(IntStack* s) {
    if (isIntStackEmpty(s)) {
        return 0;
    }
    return s->items[(s->top)--];
}

// Check if character is operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Operator precedence
int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

// Convert infix to postfix
void infixToPostfix(char* infix, char* postfix) {
    CharStack stack;
    initCharStack(&stack);
    
    int j = 0; 
    
    for (int i = 0; infix[i] != '\0'; i++) {
        char current = infix[i];
        
        if (current == ' ')
            continue;
        
        // If operand, add to postfix
        if (isdigit(current)) {
            postfix[j++] = current;
        }
        // If '(', push to stack
        else if (current == '(') {
            pushChar(&stack, current);
        }
        // If ')', pop until '('
        else if (current == ')') {
            while (!isCharStackEmpty(&stack) && peekChar(&stack) != '(') {
                postfix[j++] = popChar(&stack);
            }
            popChar(&stack);  // Remove '('
        }
        // If operator
        else if (isOperator(current)) {
            while (!isCharStackEmpty(&stack) &&
                  ((precedence(peekChar(&stack)) > precedence(current)) ||
                  (precedence(peekChar(&stack)) == precedence(current) && current != '^'))) {
                postfix[j++] = popChar(&stack);
            }
            pushChar(&stack, current);
        }
    }
    
    // Pop remaining operators
    while (!isCharStackEmpty(&stack)) {
        postfix[j++] = popChar(&stack);
    }
    
    postfix[j] = '\0';
}

// Perform arithmetic operation
int performOperation(int operand1, int operand2, char operator) {
    switch (operator) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
        case '^': {
            int result = 1;
            for (int i = 0; i < operand2; i++) {
                result *= operand1;
            }
            return result;
        }
        default: return 0;
    }
}

// Evaluate postfix expression
int evaluatePostfix(char* postfix) {
    IntStack stack;
    initIntStack(&stack);
    
    for (int i = 0; postfix[i] != '\0'; i++) {
        char current = postfix[i];
        
        if (isdigit(current)) {
            pushInt(&stack, current - '0');
        }
        else if (isOperator(current)) {
            int operand2 = popInt(&stack);
            int operand1 = popInt(&stack);
            int result = performOperation(operand1, operand2, current);
            pushInt(&stack, result);
        }
    }
    
    return popInt(&stack);
}

int main() {
    printf("INFIX TO POSTFIX CONVERTER AND EVALUATOR\n");
    
    char infix1[] = "3+5*2";
    char infix2[] = "(3+5)*2";
    char infix3[] = "8-3+2";
    char infix4[] = "2^3+5";
    
    char postfix[MAX_SIZE];
    
    printf("\nExpression 1: %s\n", infix1);
    infixToPostfix(infix1, postfix);
    printf("Postfix: %s\n", postfix);
    printf("Result: %d\n", evaluatePostfix(postfix));
    
    printf("\nExpression 2: %s\n", infix2);
    infixToPostfix(infix2, postfix);
    printf("Postfix: %s\n", postfix);
    printf("Result: %d\n", evaluatePostfix(postfix));
    
    printf("\nExpression 3: %s\n", infix3);
    infixToPostfix(infix3, postfix);
    printf("Postfix: %s\n", postfix);
    printf("Result: %d\n", evaluatePostfix(postfix));
    
    printf("\nExpression 4: %s\n", infix4);
    infixToPostfix(infix4, postfix);
    printf("Postfix: %s\n", postfix);
    printf("Result: %d\n", evaluatePostfix(postfix));
   
    return 0;
}
