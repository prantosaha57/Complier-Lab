//212-15-4157
#include <stdio.h>

int main()
{
    char input[50];
    int flag = 0;
    printf("Enter a string: ");
    gets(input);

    char keyword[32][9] =
    {
        "auto", "break", "case", "char", "const", "continue", "default", "do", "double",
        "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register",
        "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef",
        "union", "unsigned", "void", "volatile","while"
    };

    for (int i = 0; i < 32; i++)
    {
        if (strcmp(input, keyword[i]) == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        printf("Valid.\n");
    }
    else
    {
        printf("Not a keyword.\n");
    }
    return 0;
}
