#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    fp = fopen("data.txt" ,"w");

    for(int i = 0; i<1000; i++){
        fprintf( fp, "%d\n", rand() % 1000);
    }

    fclose(fp);
}