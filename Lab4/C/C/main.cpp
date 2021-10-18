#include <iostream>
#include <string.h>

using namespace std;

typedef struct Stack {
    char value;
    Stack* previous;
} Stack;

void push(Stack** last_element, char value)
{
    Stack* el = (Stack*)malloc(sizeof(Stack));

    el->value = value;
    el->previous = *last_element;
    *last_element = el;
}

char pop(Stack** last_element)
{
    if (*last_element == NULL)
        return 'e';

    char value = (*last_element)->value;
    Stack* temp_pointer = *last_element;

    *last_element = (*last_element)->previous;
    free(temp_pointer);
    return value;
}

int main(void)
{
    char c, res;
    string str;

    freopen("brackets.in", "r", stdin);
    freopen("brackets.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> str)
    {
        Stack* last_element = NULL;
        int flag = 1;

        if (str.length() % 2 == 1)
            flag = 0;
        else
            for (int i = 0; i < str.length(); ++i)
            {
                c = str[i];
                if (c == '(' or c == '[')
                    push(&last_element, c);
                else
                {
                    res = pop(&last_element);
                    if (res == 'e')
                        flag = 0;
                    if (res == '(' && c != ')')
                        flag = 0;
                    else if (res == '[' && c != ']')
                        flag = 0;
                }
            }

        if (flag)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }

    return 0;
}