#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void main()
{
	float **a;
	float *x,*temp;
	float ratio;
	int i,j,k,n,sum,max,indx,count=0;
	
	printf("Enter number of variables: ");
	scanf("%d", &n);
	a = (float**)malloc(n*sizeof(float*));
	for(i=1;i<=n;i++)
	{
		a[i] = (float*)malloc((n+1)*sizeof(float));
	}

	x = (float*)malloc(n*sizeof(float));
	for(i=1;i<=n;i++)
	{
		printf("\nEnter Coefficients of equation number %d",i);
		for(j=1;j<=n;j++)
		{
			printf("\na[%d][%d] = ",i,j);
			scanf("%f", &a[i][j]);
		}
		printf("\nEnter Constant of equation number %d",i);
		printf("\na[%d][%d] = ",i,j);
		scanf("%f", &a[i][j]);
	}
	//checking if the equations satisfy the diagonal dominance or not. 
	i=1;
	while(i<=n)
	{
		sum=0;
		max=abs(a[i][i]);		//considering absoulte value everywhere to check diagonal dominance asper rules
		for(j=1;j<=n;j++)
		{
			if(i!=j)
			{
				sum=sum+abs(a[i][j]);
				if(abs(a[i][j])>=max)
				{
					max=abs(a[i][j]);
					indx=j;
				}
			}	
		}
		//if any equation doesn't satisfy diagonal dominance then arranging in proper order
		if(abs(a[i][i])<sum)
		{
			temp=a[i];
			a[i]=a[indx];
			a[indx]=temp;
			count++;		//counting number of equations properly arranged if it was not in order
		}
		else
		{
			i++;
		}
		if(count==n-1)	//if all eqns except one are arranged then its clear the remaining one is also arranged	
			break;
	}

	if(count==0)
	{
		printf("\nGiven equations are already arranged properly acc to diagonal dominance rule");
	}
	//displaying the equations after arranging properly
	printf("\nEquations after arranging in diagonally dominant manner:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n+1;j++)
		{
			printf("\t%0.3f",a[i][j]);
		}
		printf("\n");
	}

	// Applying Gauss Elimination 
	for(i=1;i<=n-1;i++)
	{
		for(j=i+1;j<=n;j++)
		{
		   	ratio = a[j][i]/a[i][i];
			   
			for(k=1;k<=n+1;k++)
			{
			  	a[j][k] = a[j][k] - ratio*a[i][k];
			}
		}
	}
	//applying backtracking
	x[n] = a[n][n+1]/a[n][n];
	
	for(i=n-1;i>=1;i--)
	{
		x[i] = a[i][n+1];
		for(j=i+1;j<=n;j++)
		{
		  	x[i] = x[i] - a[i][j]*x[j];
		}
		x[i] = x[i]/a[i][i];
	}
	// Displaying Solutions 
	printf("\nSolutions:\n");
	for(i=1;i<=n;i++)
	{
	  	printf("Value of variable number %d is x[%d] = %0.3f\n",i,i, x[i]);
	}
}