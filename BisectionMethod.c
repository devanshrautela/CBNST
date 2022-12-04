//Bisection Method (With Allowed Error Concept)
#include<stdio.h>
#include<math.h>
#define EPSILON 0.0001
float findValueAt(float x)
{
   return exp(x)+cos(x)-1;
}

float bisect(float x1,float x2)
{
    return (x1+x2)/2;
}
int main()
{
    int maxIteration,i=1;
    float x1,x2,x3,x;hello
    printf("Enter Maximum no of Iterations\n");
    scanf("%d",&maxIteration);
    
   do
   {
        printf("Enter the value of x1 and x2(starting boundary->Initial Roots)");
        scanf("%f%f",&x1,&x2);
        if(findValueAt(x1)*findValueAt(x2)>0)
        {
           printf("Roots are Invalid\n");
           continue;
        }
        else
        {
            printf("Roots Lie between %f and %f\n",x1,x2);
            break;

        }
    } while(1);

    //find the mid point
    x = bisect(x1,x2);   

    do
    {
      if(findValueAt(x)*findValueAt(x1)<0)
         x2=x;    
      else
         x1=x;
      printf("Iterations=%d  Roots=%f\n",i,x);   
      x3 = bisect(x1,x2);  
      if(fabs(x3-x)<EPSILON)
      {
          //print root
          printf("Root=%f  Total Iterations=%d",x,i);
          return 0;

      }
      x=x3;  //v.imp
      i++; 
    }while(i<=maxIteration);
    printf("Root=%f  Total Iterations=%d",x,--i);

    return 0;
}
/*
Bisection Method Algorithm (Step Wise)
1. start

2. Define function f(x)

3. Choose initial guesses x0 and x1 such that f(x0)f(x1) < 0

4. Choose pre-specified tolerable error e.

5. Calculate new approximated root as x2 = (x0 + x1)/2

6. Calculate f(x0)f(x2)
	a. if f(x0)f(x2) < 0 then x0 = x0 and x1 = x2
	b. if f(x0)f(x2) > 0 then x0 = x2 and x1 = x1
	c. if f(x0)f(x2) = 0 then goto (8)
	
7. if |f(x2)| > e then goto (5) otherwise goto (8)

8. Display x2 as root.

9. Stop
*/
