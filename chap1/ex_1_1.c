/* 
 * ex_1_1.c
 * 
 * phannguyen.ntc@gmail.com
 *
 * The Number of Zeros end of the N! 
 * */

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    FILE *ifp,*ofp;
    char in[10];
    char buffer[10];
    ifp = fopen("SK.INP","r");
    ofp = fopen("SK.OUT","w+");

    if (ifp == NULL)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }
    while(fgets(in, 10, ifp) != NULL)
    {
        printf("N:%s Number of zero: %d\n",in,sk(atoi(in)));
        sprintf(buffer,"%d\n",sk(atoi(in)));
        fputs(buffer,ofp);
    }
    fclose(ifp);
    fclose(ofp);
    return 0;
}

int  sk(int n)
{
    int sum = 0;
    while(n >= 5)
    {
        sum +=  n / 5;
        n = n / 5;
    }
    return sum;
}
