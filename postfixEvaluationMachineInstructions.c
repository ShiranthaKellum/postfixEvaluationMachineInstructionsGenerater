#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 50

char stack [SIZE], tempCount = 1;       // tempCount is the number of temps
int top = -1;

bool isFull () {                // check for overflow
    if (top == SIZE-1) {
        return 1;

    }else {
        return 0;

    }
}

bool isEmpty () {               // check for underflow condition
    if (top == -1) {
        return 1;

    }else {
        return 0;

    }
}

void push (char c) {                            // if it is not overflow, char is inserted
    if (isFull ()) {
        printf ("Overflow condition\n");

    }else {
        top ++;
        stack [top] = c;

    }
}

char pop () {
    if (isEmpty ()) {
        printf ("Underflow condition\n");

    }else {
        char popedValue = stack [top];
        top --;
        return popedValue;                      // return poped value

    }
}

void addition () {
    char x = pop ();        // 1st popped element (current topmost 1)
    char y = pop ();        // 2nd popped element (topmost 1 after 1st pop)

    if ('a' <= y && y <= 'z' || 'A' <= y && y <= 'Z') {         // if y is not a temp variable
        printf ("   LD      %c\n", y);

    }else {                                         // if it is
        printf ("   LD      TEMP %d\n", y);

    }

    if ('a' <= x && x <= 'z' || 'A' <= x && x <= 'Z'){          // if x is not a temp variable
        printf ("   AD      %c\n", x);
        
    }else {                                         // if it is
        printf ("   AD      TEMP %d\n", x);

    }

    printf ("   ST      TEMP %d\n", tempCount);         // pass calculated value in the reg to a temp variable
    push (tempCount);                   // push temp value
    tempCount++;

}

void subtraction () {
    char x = pop ();
    char y = pop ();

    if ('a' <= y && y <= 'z' || 'A' <= y && y <= 'Z') { // if y is not a temp variable
        printf("   LD      %c\n", y);

    }else { // if it is
        printf("   LD      TEMP %d\n", y);

    }

    if ('a' <= x && x <= 'z' || 'A' <= x && x <= 'Z') { // if x is not a temp variable
        printf("   SB      %c\n", x);

    }else { // if it is
        printf("   SB      TEMP %d\n", x);

    }

    printf("   ST      TEMP %d\n", tempCount); // pass calculated value in the reg to a temp variable
    push(tempCount);                           // push temp value
    tempCount++;

}

void multipication () {
    char x = pop();
    char y = pop();

    if ('a' <= y && y <= 'z' || 'A' <= y && y <= 'Z') { // if y is not a temp variable
        printf("   LD      %c\n", y);

    }else { // if it is
        printf("   LD      TEMP %d\n", y);

    }

    if ('a' <= x && x <= 'z' || 'A' <= x && x <= 'Z') { // if x is not a temp variable
        printf("   ML      %c\n", x);

    }else { // if it is
        printf("   ML      TEMP %d\n", x);

    }

    printf("   ST      TEMP %d\n", tempCount); // pass calculated value in the reg to a temp variable
    push(tempCount);                           // push temp value
    tempCount++;

}

void division () {
    char x = pop();
    char y = pop();

    if ('a' <= y && y <= 'z' || 'A' <= y && y <= 'Z')
    { // if y is not a temp variable
        printf("   LD      %c\n", y);
    }
    else
    { // if it is
        printf("   LD      TEMP %d\n", y);
    }

    if ('a' <= x && x <= 'z' || 'A' <= x && x <= 'Z')
    { // if x is not a temp variable
        printf("   DV      %c\n", x);
    }
    else
    { // if it is
        printf("   DV      TEMP %d\n", x);
    }

    printf("   ST      TEMP %d\n", tempCount); // pass calculated value in the reg to a temp variable
    push(tempCount);                           // push temp value
    tempCount++;

}

int main () {
    int i;
    char exp [SIZE];        // ABC*+DE-/, A+B/*C*+, AB+CD-*E+, ABCD+-*, AB+C*D/

    printf ("Expression : ");
    gets (exp);

    for (i = 0; i < strlen (exp); i++) {
        if ('a' <= exp[i] && exp[i] <= 'z' || 'A' <= exp[i] && exp[i] <= 'Z') {      // if it is a operand,
            push (exp [i]);                                                         // push

        }else if (exp [i] == '+') {
            addition ();

        }else if (exp [i] == '-') {
            subtraction ();

        }else if (exp [i] == '*') {
            multipication ();

        }else {
            division ();

        }
    }
}