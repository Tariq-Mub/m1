#include <stdio.h>
#include <math.h>

double pi_leibniz (int n);
double pi_bbp (int n);

int main (void)
{

    int i = 1;
    double abserr;
    double tol = 1.0E-6;


/*    double sum = 0.;


    for (double i = 1; i < 6; i++)
    {
        sum += (1 / i);
        printf ("sum is %f \n", sum);
                                                                                                                                }               *///ends here
/*    do
    {
        double pi = pi_leibniz (i);

        abserr = fabs (pi - M_PI);
        printf ("%8d    %20.15f    %20.15f \n", i, pi, abserr);
        i *= 2;

    }
    while (abserr > tol);
    i /= 2;*/

//switch to calculating pi with bbp series
    i = 5;
    double pi = pi_bbp (i);

    /*  do
       {

       double pi = pi_bbp (i);

       abserr = fabs (pi - M_PI);
       printf ("%8d    %20.15f    %20.15f \n", i, pi, abserr);
       i *= 2;
       }
       while (abserr > tol); */
    i /= 2;


    return 0;
}

/*

for (double i = 0; i < n; i++){
    double x = pow(-1, i); //printf("%d \n", x);
         sum += (x)/(2.0 * i + 1.0);
         //printf("m is %f \n", sum);
    }
*/
