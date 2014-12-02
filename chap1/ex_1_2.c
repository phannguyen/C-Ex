/*
 * ex_1.2.c 
 *
 * phannguyen.ntc@gmail.com
 *
 * N,M is integer. Find integer K how N divisible M^K but M^(K+1).
 * 
 */

#include <stdio.h>

int main()
{
    int n,m,i,j;
    int z = 2;
    int fact[32];//prime factors of M
    int power[32];// power of the prime factors of M
    int pr,tmp,k;


    printf( "Enter a value N and M:");
    scanf("%d %d",&n,&m);
    
    /*
     * Factor analysis
     * m = 12 = 2^2*3
     * Better: Should check z =2,3 and z=z+2 to sqrt(m)
     */
    j = 0;
    while (m >= z) {
        if (m % z == 0)
        {
            fact[j] = z;
            m = m / z;
            i = 1;
            while (!(m % z)) 
            {
                i++;
                m = m / z;
            }
            power[j] = i;
            j++;
        } 
        z++;
    }

    /*
     * Check diviable N with the prime factors of M
     *
     */
   
    for (i = 0; i < j; i++) 
    {
        pr = st(fact[i],n); //pr = 0 mean: N! not divisible M
        if (pr == 0) 
        {
            k = 0;
            break;
        }
        tmp = pr / power[i]; //pr / power[i] = 0 mean power of factor of N! < poer of factor M
        if (tmp == 0)
        {
            k = 0;
            break;
        }
        k = ((k != 0) && k < tmp)? k : tmp;
    }
    printf("K:= %d\n",k);
    return 0;
}

/*
 * Return power of the factor prime of N!
 */
int st(int p, int n)
{
    int sum = 0;
    while(n >= p)
    {
        sum +=  n / p;
        n = n / p;
    }
    return sum;
}
