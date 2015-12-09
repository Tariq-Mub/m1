#include <stdio.h>
#include <math.h>

double pi_leibniz (int n);
double pi_bbp (int n);

double pi_leibniz (int n)
{
    double sum = 0.;
    double s = 1.;

    for (int i = 0; i < n; i++)
    {
        sum += s / (2.0 * i + 1.0);
        s = -s;
        //printf("m is %f \n", sum);
    }

    return 4 * sum;
}

double pi_bbp(int n){

    double sum = 0.;
    double prod = 1.;
    int i8, i;
    
    for (i = 0; i < n; i++){
        i8 = 8*i;
        sum += prod * ((4.0/(i8 + 1.0)) - (2.0/(i8 + 4.0)) - (1.0/(i8 + 5.0)) - (1.0/(i8 + 6.0)));
        prod *= (1./16.);
        printf("m is %f \n", sum);
    }
    return sum;
}
