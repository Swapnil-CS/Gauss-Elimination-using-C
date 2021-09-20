#include<stdio.h>
#include<stdlib.h>

void main()
{
	float **a;
	float *x;
	float ratio;
	int i,j,k,n;
	
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
	// Applying Gauss Elimination 
	for(i=1;i<=n-1;i++)
	{
		if(a[i][i] == 0.0)
		{
			printf("Mathematical Error!");
			exit(0);
		}
		for(j=i+1;j<=n;j++)
		{
		   	ratio = a[j][i]/a[i][i];
			   
			for(k=1;k<=n+1;k++)
			{
			  	a[j][k] = a[j][k] - ratio*a[i][k];
			}
		}
	}
	
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
	printf("\nSolution:\n");
	for(i=1;i<=n;i++)
	{
	  	printf("x[%d] = %0.3f\n",i, x[i]);
	}
}