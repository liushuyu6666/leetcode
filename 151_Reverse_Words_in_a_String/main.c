#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char * reverseWords(char * s){
    int len, i, j, p = -1, wb = 0, we = 0;
    bool prev_space = false, last_space = false;
    char t;

    len = strlen(s);
    printf("len is %d\n", len);

    if(len==0) return "";
    else if(len==1&&s[0]==' ') return "";
    else if(len==1) return s;

    // traverse the first time, just reverse char by char
    for(i=0; i<len/2; i++){
        t = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = t;
    }
    //printf("after the first reverse the string is |%s|\n", s);

    // reverse words and space
    // the most important part
    for(i=0; i<len; i++){
        if(s[i] != ' ' && i == 0 || s[i] != ' '&& s[i-1] == ' '){
            wb = i; // set beginning word
            p++;
            //printf("1) i is %d, p is %d, wb is %d, we is %d\n", i, p, wb, we);
        }
        if(s[i] != ' ' && i == len-1 || s[i] != ' ' && s[i+1] == ' '){
            we = i; // find the ending of the word
            //reverse the word from the former space
            //printf("2) i is %d, p is %d, wb is %d, we is %d\n", i, p, wb, we);
            for(j=p; j < (we + p +1) / 2; j++){
                t = s[j];
                s[j] = s[we + p - j];
                s[we + p - j] = t;
            }
            // update p
            p = p + we - wb + 1;

            //printf("change the order of chars in words is |%s|\n", s);
        }

        // check if it is the end of the string
        //printf("3) i is %d, p is %d, wb is %d, we is %d\n", i, p, wb, we);
        if(i == len - 1 && p == len){ // both at the end of the string
            return s;
        }

        // end when i reach the end bound
        if(i == len - 1){
            if(p == -1) return "";
            //printf("4) i is %d, p is %d, wb is %d, we is %d\n", i, p, wb, we);
            s[p] = '\0';
            return s;
        }
    }
    return s;
}

char * reverseWords2(char * s){
    char reverse[3000], w[3000], *t;
    int len, i, j, n;

    i = strlen(s); // geek for 4, point to the s stack
    if(i == 0){
        return "";
    }
    n = 0; // point to the reverse stack
    j = 0; // point to the w stack

    while(i){ // do not use while(i--) when handle with string char by char because when i = 0 it will become -1 after this loop
        i--;
        if(s[i] == ' '){
            if(j != 0){ // the word end here
                while(j){
                    j--;
                    reverse[n] = w[j];
                    n++;
                } // the j = 0 when it jump outof this while loop
                reverse[n] = ' '; // add space at the end of each word
                n++;
            }
        }
        else{
            /** WRONG !! reverse will have an extra space at the beginning of the string
            if(j == 0){ // at the beginning of a new word
                reverse[n] = ' '; // add space at the end of the last word
                n++;
            }*/
            w[j] = s[i];
            j++;
        }
    }

    if(j != 0){ //the last word still store in the w stack
        while(j){
            j--;
            reverse[n] = w[j];
            n++;
        } // the j = 0 when it jump outof this while loop
    }

    if(n > 0 && reverse[n-1] == ' '){ // stop the reverse stack
        n = n-1;
    }
    reverse[n] = '\0';
    printf("the result is (%s)\n", reverse);

    t = reverse; // why we need to pass reverse to t and return t instead of return reverse directly.

    return t;
}

int main()
{
    char s[3000], *result;
    while(1){
        gets(s); // not scanf("%s", s), or the space would be regarded as the end of each string
        result = reverseWords(s);
        printf("the result is |%s|\n", result);
    }
}
