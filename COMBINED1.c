// Online C compiler to run C program online
#include <stdio.h>
#include <math.h>
#include <conio.h>
float func(float g[],float m,float l);
int main()
{
    int choice;
    float a,b,c,x,g,k,l,n,m,val;
    int j,i;
     float x1[100], y1[100], xp, yp=0, p;
	 int i1,j1,n1;
    float coef[10];
    clrscr();
    printf("\n\t~~~~~~~~~~LIST~~~~~~~~~~~\n");
    while(1)
    {
	printf("\n 1)bisection method\n 2)interpolation \n 3)exit");
	printf("\n enter your choice");
	scanf("%d",&choice);
	fflush(stdin);
	switch(choice)
	{
	    case 1:
		    printf("enter the number of coefficients\n");
		    scanf("%f",&n);
		    printf("enter the coefficients \n");
		    for(i=0;i<n;i++)
		    {
			printf("coef[%d] = ",i);
			scanf("%f",&coef[i]);
			printf("\n");
		    }
		    a=0;
		    b=1;
		    for(i=0;i<20;i++)
		    {

		    val=(func(coef,a,n)*func(coef,b,n));
		    if (val<=0)
		    {
		    printf("\na= %f \t  b=%f\n",a,b);
		     break;
		    }
		    else
		    a++;
		    b++;

		    }
		    if(val>0&&i>=20)
		    {
		    a=0;
		    b=-1;

		    for(i=0;i>-20;i--)
		    {

		    val=(func(coef,a,n)*func(coef,b,n));
		    if (val<=0)
		    {
		    printf("\na= %f \t  b=%f\n",a,b);
		    break;
		     }
		    else
		    a--;
		    b--;

		    }
		    }
		    if(val==0||val<0)
		    {
		    while(val<=0)
		    {
			k=(a+b)/2;
		if(func(coef,k,n)<=0.0001&&func(coef,k,n)>0)
		{
		    printf("\n %f is the root\n",k);
		    break;
		}
		else if(func(coef,a,n)==0)
		{
		     printf("\n %f is the root1 \n",a);
		     break;
		}
		else if(func(coef,b,n)==0)
		{
		    printf("\n %f is the root2\n",b);
		    break;
		}
	    else if((func(coef,a,n)*func(coef,k,n))<0)
		    {
			b=k;
		    }
	     else if((func(coef,b,n)*func(coef,k,n))<0)
		    {
			    a=k;
		    }

	}
    }
    else
    {
	   printf("\n roots are imaginary\n");
    }
    break;
    case 2:
	 /* Input Section */
	 printf("Enter number of data: ");
	 scanf("%d", &n1);
	 printf("Enter data:\n");
	 for(i1=1;i1<=n1;i1++)
	 {
		  printf("x1[%d] = ", i1);
		  scanf("%f", &x1[i1]);
		  printf("y1[%d] = ", i1);
		  scanf("%f", &y1[i1]);
	 }
	 printf("Enter interpolation point: ");
	 scanf("%f", &yp);
	 /* Implementing Lagrange Interpolation */
	 for(i1=1;i1<=n1;i1++)
	 {
		  p=1;
		  for(j1=1;j1<=n1;j1++)
		  {
			   if(i1 !=j1)
			   {
				p = p* (yp - y1[j1])/(y1[i1] - y1[j1]);
			   }
		  }
		  xp = xp + p * x1[i1];
	 }
	 printf("Interpolated value at %.3f is %.3f.", yp, xp);
    break;
    case 3: printf("\n exiting the program\n");
    exit(0);
    default:printf("\n invalid\n");
    }
    }
    getch();
    return 0;
}
float func(float g[],float m,float l)
{
    int i=1;
    float sum=0;
    for(i=1;i<l;i++)
    {
	sum+=((g[i])*pow(m,i));
    }
    sum+=g[0];
    return sum;
}