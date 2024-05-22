//212-15-4157
#include<stdio.h>
#include<string.h>
int main() {
    char str[5];

    printf("Enter operator: ");
    scanf("%s", str);

    if(strcmp(str,"+")==0 || strcmp(str,"-")==0 || strcmp(str,"*")==0 || strcmp(str,"/")==0){

        printf("Valid\n");
        printf("Arithmetic Operator\n");
    }
    else if(strcmp(str,"++")==0 || strcmp(str,"--")==0){
        printf("Valid\n");
        printf("Unary Operator\n");
    }
    else if(strcmp(str,"<")==0 || strcmp(str,"<=")==0 || strcmp(str,">=")==0 || strcmp(str,">")==0 ||
            strcmp(str,"==")==0 || strcmp(str,"!=")==0){
        printf("Valid\n");
        printf("Relational Operator\n");
    }
    else if(strcmp(str,"&&")==0 || strcmp(str,"||")==0 || strcmp(str,"!")==0){
        printf("Valid\n");
        printf("Logical Operator\n");
    }
    else if(strcmp(str,"&")==0 || strcmp(str,"|")==0 || strcmp(str,">>")==0 ||
            strcmp(str,"<<")==0 || strcmp(str,"~")==0 || strcmp(str,"^")==0){
        printf("Valid\n");
        printf("Bitwise Operator\n");
    }
    else if(strcmp(str,"=")==0 || strcmp(str,"+=")==0 || strcmp(str,"-=")==0 ||
            strcmp(str,"*=")==0 || strcmp(str,"%=")==0 || strcmp(str,"^")==0){
        printf("Valid\n");
        printf("Assignment Operator\n");
    }
    else if(strcmp(str,"?:")==0){
        printf("Valid\n");
        printf("Ternary Operator\n");
    }
    else{
        printf("Invalid\n");
    }

    return 0;
}
