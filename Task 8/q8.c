#include<stdio.h>
#include<stdlib.h>
#include"qsort.c"

int get_line_num() {

    FILE *fp;
    int count=0;
    char c;
    if ((fp = fopen("data.txt","r")) == NULL){
        printf("Error! opening file");
        exit(1);
    }

    for(c=getc(fp);c!=EOF;c=getc(fp)){
        if(c=='\n'){
            count++;
        }
    }
    fclose(fp);
    return count;
}

int *convertToList(int *arr) {
    FILE *fp;
    int num=0,num_lines=0;
    num_lines=get_line_num();

    if ((fp = fopen("data.txt","r")) == NULL){
        printf("Error! opening file");
        exit(1);
    }
    for(int i=0;i<num_lines;i++){
        fscanf(fp,"%d",&num);
        arr[i]=num;
    }

    fclose(fp); 
    return arr;   
}

int main () {
    FILE *fp;
    fp = fopen("data_sorted.txt","w");

    int i,unsortArr[1000];
    int *ptr = convertToList(unsortArr); 
    int *ptr2 = quicksort(ptr,0,999);
    for(i=0;i<1000;i++)
        fprintf(fp,"%d\n",ptr2[i]);   

    fclose(fp);
}