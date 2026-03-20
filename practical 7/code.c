#include <stdio.h>
#include <string.h>

char input[20], stack[20];
int top = -1, i = 0;

void push(char x) {
    stack[++top] = x;
}

void pop(int n) {
    top -= n;
}

void display() {
    for (int j = 0; j <= top; j++)
        printf("%c", stack[j]);
}

int main() {
    printf("Enter input string (end with $): ");
    scanf("%s", input);

    push('$');

    while (1) {
        printf("\nStack: ");
        display();
        printf("\tInput: %s", input + i);

        // Shift
        if (input[i] != '\0') {
            printf("\tAction: Shift %c", input[i]);
            push(input[i]);
            i++;
        }

        // Reduce rule: E → E+E
        if (top >= 2 && stack[top] == 'E' && stack[top-1] == '+' && stack[top-2] == 'E') {
            printf("\tAction: Reduce E→E+E");
            pop(3);
            push('E');
        }

        // Reduce rule: E → id
        if (top >= 1 && stack[top] == 'd' && stack[top-1] == 'i') {
            printf("\tAction: Reduce E→id");
            pop(2);
            push('E');
        }

        // Accept condition
        if (stack[top] == 'E' && input[i] == '\0') {
            printf("\nString Accepted!\n");
            break;
        }

        // Error condition
        if (i >= strlen(input) && stack[top] != 'E') {
            printf("\nString Rejected!\n");
            break;
        }
    }

    return 0;
}
