#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack for operators
char operator_stack[MAX];
int operator_top = -1;

// Stack for operands
char *operand_stack[MAX];
int operand_top = -1;

// Push to operator stack
void push_operator(char op) {
    if (operator_top == MAX - 1) {
        printf("Operator stack overflow\n");
        exit(1);
    }
    operator_stack[++operator_top] = op;
}

// Pop from operator stack
char pop_operator() {
    if (operator_top == -1) {
        printf("Operator stack underflow\n");
        exit(1);
    }
    return operator_stack[operator_top--];
}

// Peek top of operator stack
char peek_operator() {
    return operator_stack[operator_top];
}

// Push to operand stack
void push_operand(char *operand) {
    if (operand_top == MAX - 1) {
        printf("Operand stack overflow\n");
        exit(1);
    }
    operand_stack[++operand_top] = operand;
}

// Pop from operand stack
char *pop_operand() {
    if (operand_top == -1) {
        printf("Operand stack underflow\n");
        exit(1);
    }
    return operand_stack[operand_top--];
}

// Check if a character is an operand (alphabet or digit)
int is_operand(char ch) {
    return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

// Check precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/' || op == '%') return 2;
    return 0;
}

// Check if a character is an operator
int is_operator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%';
}

// Check if a character is an opening bracket
int is_opening_bracket(char ch) {
    return ch == '(' || ch == '{' || ch == '[';
}

// Check if a character is a closing bracket
int is_closing_bracket(char ch) {
    return ch == ')' || ch == '}' || ch == ']';
}

// Check if brackets match
int is_matching_bracket(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Process an operator: pop two operands, apply the operator, and push the result
void process_operator() {
    char *operand2 = pop_operand();
    char *operand1 = pop_operand();
    char operator = pop_operator();
    
    // Allocate space for the new operand string and format it
    char *result = (char *)malloc(MAX * sizeof(char));
    snprintf(result, MAX, "%s %s %c", operand1, operand2, operator);
    push_operand(result);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <infix_expression>\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        char *token = argv[i];
        char ch = token[0];

        // If token is an operand, push it to the operand stack
        if (is_operand(ch)) {
            push_operand(token);
        }
        // If token is an opening bracket, push it to the operator stack
        else if (is_opening_bracket(ch)) {
            push_operator(ch);
        }
        // If token is a closing bracket
        else if (is_closing_bracket(ch)) {
            while (operator_top != -1 && !is_opening_bracket(peek_operator())) {
                process_operator();
            }
            if (operator_top != -1 && is_opening_bracket(peek_operator())) {
                char open_bracket = pop_operator();
                if (!is_matching_bracket(open_bracket, ch)) {
                    printf("Mismatched brackets\n");
                    return 1;
                }
            }
        }
        // If token is an operator
        else if (is_operator(ch)) {
            while (operator_top != -1 && precedence(peek_operator()) >= precedence(ch)) {
                process_operator();
            }
            push_operator(ch);
        } else {
            printf("Invalid character in expression\n");
            return 1;
        }
    }

    // Process remaining operators
    while (operator_top != -1) {
        if (is_opening_bracket(peek_operator())) {
            printf("Mismatched brackets\n");
            return 1;
        }
        process_operator();
    }

    // Final result is on the operand stack
    printf("Postfix expression: %s\n", pop_operand());

    // Free remaining allocated strings
    while (operand_top != -1) {
        free(operand_stack[operand_top--]);
    }

    return 0;
}
