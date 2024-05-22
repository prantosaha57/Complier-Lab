//212-15-4157
#include <stdio.h>
int main()
{
    char str[100];
    int i = 0;
    gets(str);
    while (str[i] != '\0')
    {
        char token[15];
        int j = 0;

        while(str[i] == ' ')
        {
            i++;
        }

        while (str[i] != ' ' && str[i] != '\0')
        {
            token[j] = str[i];
            i++;
            j++;
        }
        token[j] = '\0';

        int flag = 1;
        if (!((token[0] >= 'a' && token[0] <= 'z') || (token[0] >= 'A' && token[0] <= 'Z') || token[0] == '_'))
            flag = 0;
        else
        {
            for (int k = 1; token[k] != '\0'; k++)
            {
                if (!((token[k] >= 'a' && token[k] <= 'z') || (token[k] >= 'A' && token[k] <= 'Z') || (token[k] >= '0' && token[k] <= '9') || token[k] == '_'))
                {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag==1)
            printf("%s is valid. \n", token);
        else
            printf("%s is invalid. \n", token);

        if (str[i] == ' ')
            i++;
    }

    return 0;
}
