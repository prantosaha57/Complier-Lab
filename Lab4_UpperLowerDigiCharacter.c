//212-15-4157
#include <stdio.h>
int main()
{
    char str[100];
    int uppercase = 0, lowercase = 0, digits = 0, special = 0;
    char special_chars[100] = "";

    printf("Enter string: ");
    gets(str);


    for (int i=0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            uppercase++;
        else if (str[i] >= 'a' && str[i] <= 'z')
            lowercase++;
        else if (str[i] >= '0' && str[i] <= '9')
            digits++;
        else
        {
            special++;
            int j;
            for (j=0; special_chars[j] != '\0'; j++)
            {
                if (special_chars[j] == str[i])
                    break;
            }
            if (special_chars[j] == '\0')
                special_chars[j] = str[i];
        }
    }

    printf("Uppercase letters: %d\n", uppercase);
    printf("Lowercase letters: %d\n", lowercase);
    printf("Digits: %d\n", digits);
    printf("Special characters: %d\n", special);
    printf("List of special characters: %s\n", special_chars);

    return 0;
}
