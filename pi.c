#include <stdio.h>
#include <math.h>

#include "timer.h"

double pi_leibniz (int n);
double pi_bbp (int n);
int adjust_rep_count (int count, double time, double tmin, double tmax);

int main (void)
{

    int i;
    double abserr;
    double tol = 1.0E-6;

    i = 1;
    do
    {
        double pi = pi_leibniz (i);

        abserr = fabs (pi - M_PI);
        printf ("%8d    %20.15f    %20.15f \n", i, pi, abserr);
        i *= 2;

    }
    while (abserr > tol);
    int ileibniz = i / 2;

    //switch to calculating pi with bbp series
    //i = 5;
    //double pi = pi_bbp (i);

    i = 1;
    do
    {

        double pi = pi_bbp (i);

        abserr = fabs (pi - M_PI);
        printf ("%8d    %20.15f    %20.15f \n", i, pi, abserr);
        i *= 2;
    }
    while (abserr > tol);
    int ibbp = i / 2;

    double tmin = 1., tmax = 2.;
    int count = 1000;
    double time, time1, time2;

    do
    {
        timer_start ();

        for (i = 0; i < count; i++)
        {
            double pi = pi_bbp (ibbp);
        }

        time = timer_stop ();
        time1 = time / count;
        printf (" %10.2f usec %10.6f sec %10d\n", time1 * 1.e6, time, count);
        /*
         * adjust count such that cpu time is between
         * tmin and tmax
         */
        count = adjust_rep_count (count, time, tmin, tmax);
    }
    while ((time > tmax) || (time < tmin));
        time1 = time / count;
    printf (" %10.2f usec %10.6f sec %10d\n", time1 * 1.e6, time, count);

    return 0;
}
