#include <stdio.h>
#include <math.h>
int main()
{
    float true_value, absolute_value;

    printf("Enter True value and Absolute value\n");
    scanf("%f %f", &true_value, &absolute_value);

    float absolute_error, relative_error, percentage_error;

    absolute_error = fabs(true_value - absolute_value);
    relative_error = absolute_error / true_value;
    percentage_error = relative_error * 100;

    printf("Absolute Error = %f \n Relative Error = %f \n Percentage Error = %f", absolute_error, relative_error, percentage_error);
    return 0;
}