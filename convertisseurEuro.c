
#include <stdio.h>
#include <stdlib.h>

double conversion(double francs)
{
    double euros = 0;
    
    euros = francs / 6.55957;
    return euros;
}    

int main(int argc, char *argv[])
{    
    printf("10 francs = %fE\n", conversion(10));
    printf("50 francs = %fE\n", conversion(50));
    printf("100 francs = %fE\n", conversion(100));
    printf("200 francs = %fE\n", conversion(200));
    
    return 0;
}