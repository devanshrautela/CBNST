//C Program to Implement Gauss Seidel Method

#include<stdio.h>
#include<conio.h>
#include<math.h>

/* Arrange systems of linear
   equations to be solved in
   diagonally dominant form
   and form equation for each
   unknown and define here
*/
/* In this example we are solving
   3x + 20y - z = -18
   2x - 3y + 20z = 25
   20x + y - 2z = 17
*/
/* Arranging given system of linear
   equations in diagonally dominant
   form:
   20x + y - 2z = 17
   3x + 20y -z = -18
   2x - 3y + 20z = 25
*/
/* Equations:
   x = (17-y+2z)/20
   y = (-18-3x+z)/20
   z = (25-2x+3y)/20
*/
/* Defining function */
#define f1(x,y,z)  (17-y+2*z)/20
#define f2(x,y,z)  (-18-3*x+z)/20
#define f3(x,y,z)  (25-2*x+3*y)/20

/* Main function */
int main()
{
 float x0=0, y0=0, z0=0, x1, y1, z1, e1, e2, e3, e;
 int count=1;
 clrscr();
 printf("Enter tolerable error:\n");
 scanf("%f", &e);

 printf("\nCount\tx\ty\tz\n");
 do
 {
  /* Calculation */
  x1 = f1(x0,y0,z0);
  y1 = f2(x1,y0,z0);
  z1 = f3(x1,y1,z0);
  printf("%d\t%0.4f\t%0.4f\t%0.4f\n",count, x1,y1,z1);

  /* Error */
  e1 = fabs(x0-x1);
  e2 = fabs(y0-y1);
  e3 = fabs(z0-z1);

  count++;

  /* Set value for next iteration */
  x0 = x1;
  y0 = y1;
  z0 = z1;

 }while(e1>e && e2>e && e3>e);

 printf("\nSolution: x=%0.3f, y=%0.3f and z = %0.3f\n",x1,y1,z1);

 getch();
 return 0;
}
/*#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#define EPSILON 0.001  // till 3 correct decimal places

int n;
int flag;

//Helper function
float findSum(int i,float a[][n+1])
{
     float sum=0;
     for(int j=0;j<n;j++)
     {  
       if(i!=j)  
         sum+=a[i][j];
     }
     return sum;
}

//checks if Gauss Seidel Method is applicable and return true if yes otherwise return false
bool isMethodApplicable(float a[][n+1])
{
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {

           if(fabs(a[i][i])>findSum(i,a))
              continue;
           else  
              return false;   

       }
   }
   return true;
}

//prints the Value of Unknowns
void print(int iteration,float values[n]) 
{
  printf("Iteration %d ",iteration);  
  for(int i=0;i<n;i++)
    printf("value[%d]=%f ",i+1,values[i]);
  printf("\n");
}


void findValues(float a[][n+1],int maxIterations,float values_old[n])
{
    int i,j,k,iteration;
    float ratio,sum=0;
    float values_new[n];
    for(int i=0;i<n;i++)
     values_new[i]=0;
    for(iteration=1;iteration<=maxIterations;iteration++)
    {
        for(i=0;i<n;i++)
        {
            sum=0;
            for(j=0;j<n;j++)
            {
                if(i!=j)
                sum+=a[i][j]*values_new[j];
            }
          
            values_new[i]=(a[i][n] - sum)/a[i][i];
        }
        
        //Now you have found the values of n unknowns for above iteration
        //Now check if your matching criteria satisfied , comparing with previous iteration values
        for(k=0;k<n;k++)
        {
            if(fabs(values_old[k]-values_new[k])<EPSILON)
                continue;          
            else
            {
               flag=1;
               break;
            }
        } 
        if(flag==0)
        {
            print(iteration,values_new);  // print final values of unknowns  and return
            return ;
        }
        flag=0; //resetting the flag
       
        print(iteration,values_new); //To print intermediate roots

        //copy new values of unknowns to old value array
        for(k=0;k<n;k++)
             values_old[k]=values_new[k];
    } //end of iteration loop
    print(iteration,values_new) ; 

} //end of findValues()

 
int main()
{
    int i,j,k,x,y,maxIterations;
    float ratio;
    printf("Enter no of Unknowns\n");
    scanf("%d",&n);
    printf("Enter no. of iterations\n");
    scanf("%d",&maxIterations);
    float a[n][n+1];
    float values[n];;

    printf("Enter the Augmented Matrix\n");
    for(int i=0;i<n;i++)
    {
     for(int j=0;j<n+1;j++)
        scanf("%f",&a[i][j]);
    }

   if(!isMethodApplicable(a))
   {
        printf("Gauss Seidel Method can't be applied");
        return 0;
   }
   printf("\n\nGauss Seidel Method is applicable\n");
   for(int i=0;i<n;i++)
     values[i]=0;
   findValues(a,maxIterations,values);
   return 0;
}
*/