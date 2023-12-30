/*
Parentheses Checker
Author: Johan Sollenius
*/
#define _CRT_SECURE_NO_WARNINGS
#define MAX 10
#include "stdio.h"
#include "stdlib.h"

/* 
PUSH FUNCTION 
This function adds a char to the stack
The function has three parameters:
(1) The stack (An array of type char), (2) A reference to the top value, (3) the char that is to be added
Returns 
1 if succesfull, 0 if unsucessful (If the stack is full)
*/
int push(char* stack, int* top, char c);

/*
POP FUNCTION
This function removes the most recent item that was added to the stack (determined by the top value)
The function has three parameters:
(1) The stack (An array of type char), (2) A reference to the top value
Returns
1 if succesfull, 0 if unsucessful (If the stack is empty)
*/
int pop(char* stack, int* top); 

/*
PEEK FUNCTION
This function returns the most recent item that was added to the stack 
The function has three parameters:
(1) The stack (An array of type char), (2) A reference to the top value
Returns
1 if succesfull, 0 if unsucessful (If the stack is empty)
*/
int peek(char* stack, int* top); 

int main()
{
	
	
	char stack[MAX];
	int top = NULL;

	char input[100];
	printf("Enter an parenthese string: ");
	scanf("%s", input);

	char c;
	char topC = NULL;
	//while ((c=getchar()) != '\n' && !feof(stdin))
	for(int i = 0; (c = input[i]) != '\0'; i++)
	{

		//If it's a opening bracket add it to the stack
		if (c == '(' || c == '[' || c == '{')
		{
			topC = peek(stack, &top);

			/*ADDITIONAL REQUIREMENTS*/
			if (topC != 0)
			{
				if (topC == '(' && (c == '[' || c == '{')) break;
				if (topC == '[' && c == '{') break;
			}
			/*----------------------*/

			if (!push(stack, &top, c)) return 1; //Stack overflow
		}

		//If it's a closing bracket check the stack if there's a matching opening bracket,
		//If there's a match remove the opening bracket from the stack & repeat
		else if (c == ')' || c == ']' || c == '}')
		{
			if ((topC = peek(stack, &top)) == 0) break; //If the stack is empty, A closing bracket was entered without a opening 
					
			if ((topC == '(' && c == ')') || (topC == '{' && c == '}') || (topC == '[' && c == ']'))
			{
				pop(stack, &top);
			}
		}
		else
		{
			puts("Invalid input");
			return 1;
		}
	}
	if (top == NULL && topC != NULL) puts("Balanced!"); //If the stack is empty and the stack had a opening parameter that was popped
	else puts("Not Balanced!");
	
}


int push(char *stack, int *top, char c)
{
	if (*top == MAX - 1)
	{
		puts("Stack Overflow");
		return 0;
	}

	*top += 1;
	stack[*top] = c;
	return 1;
}

int pop(char* stack, int* top)
{
	if (*top == NULL)
	{
		puts("Stack Underflow");
		return 0;
	}
	*top -= 1;
	return 1;
}

int peek(char* stack, int* top)
{
	if (*top == NULL)
	{
		//puts("STACK is EMPTY");
		return 0;
	}
	return stack[*top];
}