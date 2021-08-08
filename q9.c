#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include"reverse.c"

char * to_hex (int64_t value) {
    int64_t start = 1;
    char *mem_alloc = malloc(10*sizeof(char));
    char *s = malloc(32*sizeof(char));
    char *HEX_DIGITS = "0123456789abcdef";
    char temp[64];
    
    strcpy(mem_alloc,"");
    strcpy(s,"0x");
    strcpy(temp,"");

    if(value<0){
        value+=(start<<32);
    }
    while(1){
        char d[20]= {HEX_DIGITS[value&0xf],'\0'};
        strcat(temp,d);
        value>>=4;
        reverse(temp, 0, strlen(temp)-1);
        if(value==0){
            strcat(mem_alloc,temp);
            break;
        }
    }
    strcat(s,mem_alloc);
    return s;
}

int main () {
    printf("%s\n",to_hex(33));
    printf("%s\n",to_hex(-1));
    
}