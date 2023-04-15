#include "stive.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int validParenthesis(char *parenthesis){
    Node *stackTop = NULL;
    for (int i = 0; i < strlen(parenthesis); i++) {
        if (isEmptyStack(stackTop) == 1) {
            if (parenthesis[i] == ')')
                return i;
            else
                push(&stackTop, parenthesis[i]);
        }

        else if (top(stackTop) == '(' && parenthesis[i] == ')')
            pop(&stackTop);
        else if(top(stackTop) == ')' && parenthesis[i] == '(')
            return i;
    }   
    if (isEmptyStack(stackTop))
        return -1;
    else 
        return strlen(parenthesis);
}

int main(){
    char *parenthesis = "()(";
    printf("%d", validParenthesis(parenthesis));
   
    return 0;
}