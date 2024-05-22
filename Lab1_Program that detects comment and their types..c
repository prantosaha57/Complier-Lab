#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    gets(str);
    int flag=0;
    int length = strlen(str);
    //printf("Length of string is : %d", length);
    for(int i=0; i<=length-1; i++)
    {
        if(str[i]=='/')
        {
            if(str[i+1]=='/')
            {
                flag=1;
            }
            if(str[i+1]=='*')
            {

                for(int j=i+2; j<=length-1; j++)
                {
                    if(str[j]=='*' && str[j+1]=='/')
                    {
                        flag=2;
                    }
                }

            }

        }
    }


    if(flag==1)
    {
        printf("Single line comment detected");
    }
    else if (flag==2)
    {
        printf("Multiple line comment detected");

    }
    else
    {
        printf("No comment detected");
    }
    return 0;
}

