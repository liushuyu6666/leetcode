#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT_MAX 2147483647

int myAtoi(char * str){
    int num = 0, i = 0, len;
    len = strlen(str);
    int sy = 1;

    // find the first int type
    for(i=0; i<len; i++){
        if(str[i] == ' ' || str[i] == '"');
        else if(str[i] >= '0' && str[i] <= '9'){
            break;
        }
        else if(str[i] == '-' || str[i] == '+'){
            sy = -1;
            break;
        }
        else{
                return 0;
        }
    }

    if(sy == -1){
        if(str[i] == '-'){
            sy = -1;
        }
        else sy = 1;
        i++;
    }

    // handle with numbers
    while(str[i] >= '0' && str[i] <= '9'){
        if(sy == -1){
            if(num > INT_MAX / 10 || num == INT_MAX / 10 && str[i] == '9'){
                    return (INT_MAX + 1) * -1;
            }
            else if(num > INT_MAX / 10 || num == INT_MAX / 10 && str[i] == '8'){
                    return -2147483648;
            }
            else{
                num = num * 10 + (str[i] - '0');
                i++;
            }
            /* if(INT_MAX - (str[i] - '0') < num * 10 -1){
                return (INT_MAX + 1) * -1;
            }*/
        }
        else{
            if(num > INT_MAX / 10 || num == INT_MAX /10 && (str[i] - '0') > 7){
                return INT_MAX;
            }
            else{
                num = num * 10 + (str[i] - '0');
                i++;
            }
        }
    }

    num = num * sy;

    return num;

}
int main()
{
    int test = 0;
    char s[32];

    while(1){
        scanf("%s", s);
        test = myAtoi(s);
        printf("this is %d\n", test);
    }


}
