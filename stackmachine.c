#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Stack {
        int data[1000000];
        int currentTopIndex;
};

void setupStack(struct Stack * stack) {
        ( * stack).currentTopIndex = -1;
}

bool isStackVacant(struct Stack * stack) {
        return ( * stack).currentTopIndex == -1;
}

bool isStackAtCapacity(struct Stack * stack) {
        return ( * stack).currentTopIndex == 999999;
}

void addToStack(struct Stack * stack, int number) {
        if (isStackAtCapacity(stack))
                exit(1);
        ( * stack).data[++( * stack).currentTopIndex] = number;
}

int removeFromStack(struct Stack * stack) {
        if (isStackVacant(stack))
                exit(1);
        return ( * stack).data[( * stack).currentTopIndex--];
}

int main() {
        int value;
        int num1;
        int num2;
        int result;
        struct Stack mainStack;
        setupStack( & mainStack);
        char command[6];

        for (;;) {
                if (scanf("%s", command) == EOF) break;
                if (strcmp(command, "CONST") == 0) {
                        scanf("%d", & value);
                        addToStack( & mainStack, value);
                } else if (strcmp(command, "ADD") == 0) {
                        addToStack( & mainStack, removeFromStack( & mainStack) + removeFromStack( & mainStack));
                } else if (strcmp(command, "SUB") == 0) {
                        num2 = removeFromStack( & mainStack);
                        num1 = removeFromStack( & mainStack);
                        addToStack( & mainStack, num2 - num1);
                } else if (strcmp(command, "MUL") == 0) {
                        addToStack( & mainStack, removeFromStack( & mainStack) * removeFromStack( & mainStack));
                } else if (strcmp(command, "DIV") == 0) {
                        num2 = removeFromStack( & mainStack);
                        num1 = removeFromStack( & mainStack);
                        addToStack( & mainStack, num2 / num1);
                } else if (strcmp(command, "MAX") == 0) {
                        num2 = removeFromStack( & mainStack);
                        num1 = removeFromStack( & mainStack);
                        if (num1 > num2) {
                                result = num1;
                        } else {
                                result = num2;
                        }
                        addToStack( & mainStack, result);
                } else if (strcmp(command, "MIN") == 0) {
                        num2 = removeFromStack( & mainStack);
                        num1 = removeFromStack( & mainStack);
                        if (num1 < num2) {
                                result = num1;
                        } else {
                                result = num2;
                        }
                        addToStack( & mainStack, result);
                } else if (strcmp(command, "NEG") == 0) {
                        addToStack( & mainStack, -removeFromStack( & mainStack));
                } else if (strcmp(command, "DUP") == 0) {
                        value = removeFromStack( & mainStack);
                        addToStack( & mainStack, value);
                        addToStack( & mainStack, value);
                } else if (strcmp(command, "SWAP") == 0) {
                        num2 = removeFromStack( & mainStack);
                        num1 = removeFromStack( & mainStack);
                        addToStack( & mainStack, num2);
                        addToStack( & mainStack, num1);
                } else if (strcmp(command, "END") == 0) {
                        break;
                }
        }

        if (!isStackVacant( & mainStack)) {
                printf("%d\n", removeFromStack( & mainStack));
        }

        return 0;
}
