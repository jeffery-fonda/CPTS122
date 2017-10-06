#include "header.h"

void initinfix (INFIX *ptr_head) // makes the struct
{
    ptr_head -> top = -1 ;
    strcpy ( ptr_head -> target, "" ) ;
    strcpy ( ptr_head -> stack, "" ) ;
    ptr_head -> t = ptr_head -> target ;
    ptr_head -> s = ""  ;
}

void setexpr (INFIX *ptr_head, char *str) // sets s to point to given expr
{
    ptr_head -> s = str ;
}

void push (INFIX *ptr_head, char c) // push function
{
    if (ptr_head -> top == MAX)
        printf ("Stack is full.\n");
    else
    {
        ptr_head -> top++;
        ptr_head -> stack[ptr_head -> top] = c;
    }
}

char pop (INFIX *ptr_head) // pop function
{
    if (ptr_head -> top == -1)
    {
        printf ("Stack is empty.\n");
        return -1;
    }
    else
    {
        char item = ptr_head -> stack[ptr_head -> top];
        ptr_head -> top--;
        return item;
    }
}

void convert (INFIX *ptr_head) // converts function
{
    char opr;

    while (*(ptr_head -> s))
    {
        if (*(ptr_head -> s) == ' ' || *(ptr_head -> s) == '\t')
        {
            ptr_head -> s++;
            continue;
        }
        if (isdigit (*(ptr_head -> s)) || isalpha (*(ptr_head -> s)))
        {
            while (isdigit (*(ptr_head -> s)) || isalpha (*(ptr_head -> s)))
            {
                *(ptr_head -> t) = *(ptr_head -> s);
                ptr_head -> s++;
                ptr_head -> t++;
            }
        }
        if (*(ptr_head -> s) == '(')
        {
            push (ptr_head, *(ptr_head -> s));
            ptr_head -> s++;
        }
        if (*(ptr_head -> s) == '*' || *(ptr_head -> s) == '+' || *(ptr_head -> s) == '/' || 
			*(ptr_head -> s) == '%' || *(ptr_head -> s) == '-' || *(ptr_head -> s) == '$')
        {
            if (ptr_head -> top != -1)
            {
                opr = pop (ptr_head);
                while (priority (opr) >= priority (*(ptr_head -> s)))
                {
                    *(ptr_head -> t) = opr;
                    ptr_head -> t++;
                    opr = pop (ptr_head);
                }
                push (ptr_head, opr);
                push (ptr_head, *(ptr_head -> s));
            }
            else
                push (ptr_head, *(ptr_head -> s));
            ptr_head -> s++;
        }

        if (*(ptr_head -> s) == ')')
        {
            opr = pop (ptr_head);
            while ((opr) != '(')
            {
                *(ptr_head -> t) = opr;
                ptr_head -> t++;
                opr =  pop (ptr_head);
            }
            ptr_head -> s++;
        }
    }

    while (ptr_head -> top != -1)
    {
        char opr = pop (ptr_head);
        *(ptr_head -> t) = opr;
        ptr_head -> t++;
    }

    *(ptr_head -> t) = '\0';
}

int priority (char c) // returns priority of operator
{
    if (c == '$')
	{
        return 3;
	}
    if (c == '*' || c == '/' || c == '%')
	{
        return 2;
	}
    else
    {
        if (c == '+' || c == '-')
		{
            return 1;
		}
        else
		{
			return 0;
		}
    }
}

void show (INFIX ptr_head) // displays the postfix expression
{
    printf ("%s\n", ptr_head.target);
}

int evaluatePostFixExpression (INFIX *ptr_head, char expr)
{
	int x = 0, y = 0, digit = 0, result = 0;

	while (*(ptr_head -> s) != 'ÿ')
	{
		if (isdigit (*(ptr_head -> s)))
		{
			push (ptr_head, *(ptr_head -> s));
			*(ptr_head -> s++);
			continue;
		}
		if (*(ptr_head -> s) == '+')
		{
			y = pop (ptr_head) - 48;
			x = pop (ptr_head) - 48;
			result = x + y;
			result = (*(ptr_head -> s));
			push (ptr_head, result);
			*(ptr_head -> s++);
			continue;
		}
		if (*(ptr_head -> s) == '-')
		{
			y = pop (ptr_head) - 48;
			x = pop (ptr_head) - 48;
			result = x - y;
			result = (*(ptr_head -> s));
			push (ptr_head, result);
			*(ptr_head -> s++);
			continue;
		}
		if (*(ptr_head -> s) == '*');
		{
			y = pop (ptr_head) - 48;
			x = pop (ptr_head) - 48;
			result = x * y;
			result = (*(ptr_head -> s));
			push (ptr_head, result);
			*(ptr_head -> s++);
			continue;
		}
		if (*(ptr_head -> s) == '/')
		{
			y = pop (ptr_head) - 48;
			x = pop (ptr_head) - 48;
			result = x / y;
			result = (*(ptr_head -> s));
			push (ptr_head, result);
			*(ptr_head -> s++);
			continue;
		}
	}
	pop (ptr_head);
	printf ("Answer is: %d\n", *(ptr_head -> s));
	return 0;
}