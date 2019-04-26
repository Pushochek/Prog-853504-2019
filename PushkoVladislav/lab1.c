#include <stdio.h>
#include <stdlib.h>
char* toBin(char* s, int n);   
int isSymmetrical(char* str);       
int main() 
{
    int n;                          
    printf("Enter N: ");
    scanf("%d", &n);               
    char buf[255];                        
    for (int i = 1 ; i <= n; i++)
	{         
        char *binary = toBin(buf, i);   

        if (isSymmetrical(binary)) 
		{
            printf("Decimal: %d\t\tBinary: %s\n", i, binary);
        }
    }

    return 0;                              
}
char* toBin(char*s, int num)
{
    int nextNum, ostatok=0;
    char *str=s;
    char *result;

    while(num!=0)
    {
        nextNum = num/2;
        ostatok = num %2;
        num= nextNum;
        *str++ = ostatok+'0';
    }
    int len = strlen(s);
    result = (char*)malloc(len+1);
    result[len] = '\0';
    for (int i=0; i<len;i++)
    {
        result[i]=s[len-1-i];
    }
    return result;
}
int isSymmetrical(char* str) 
{
    int flag = 1;                      
    for (int i = 0, j = strlen(str) - 1; i < j; ++i, --j) {
        if (str[i] != str[j]) {     
            flag = 0;               
            break;                  
        }
    }
    return flag;  
}

