#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 4
int main() {
    FILE *fp = fopen("11.in", "r");
    unsigned short grid[20][20];
    unsigned long long product = 1, max_product = 1;

    for(unsigned short i = 0; i < 20; i++) 
        for(unsigned short j = 0; j < 20; j++) 
        {
        fscanf(fp, "%hu", &grid[i][j]);
        }

    for(unsigned short i = 0; i < 20; i++) 
        for(unsigned short j = 0; j < 20; j++) 
        {
            if(i < (MAX_TERMS - 1)) 
            { 
                product = 1;

                if(j < (MAX_TERMS - 1)) 
                { 
                    for(unsigned short k = 0; k < MAX_TERMS; k++) {product *= grid[i + k][j]; printf("%lluu\n", product); }
                    if(product > max_product) max_product = product;
                    product = 1;

                    for(unsigned short k = 0; k < MAX_TERMS; k++) product *= grid[i][j + k];
                    if(product > max_product) max_product = product;
                    product = 1;

                    for(unsigned short k = 0; k < MAX_TERMS; k++) product *= grid[i + k][j + k];
                    if(product > max_product) max_product = product;
                    product = 1;
                }

                else if (j >= (20 - MAX_TERMS + 1))
                {
                    for(unsigned short k = 0; k < MAX_TERMS; k++) product *= grid[i + k][j]; 
                    if(product > max_product) max_product = product;
                    product = 1;

                    for(unsigned short k = 0; k < MAX_TERMS; k++) product *= grid[i][j - k];
                    if(product > max_product) max_product = product;
                    product = 1;

                    for(unsigned short k = 0; k < MAX_TERMS; k++) product *= grid[i + k][j - k];
                    if(product > max_product) max_product = product;
                    product = 1;
                }
                
            }
        }

    for(unsigned short i = 0; i < 20; i++) 
        for(unsigned short j = 0; j < 20; j++) printf("%hu\n", grid[i][j]);

    fclose(fp);
    return 0;
}