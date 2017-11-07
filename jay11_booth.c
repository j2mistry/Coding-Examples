#include<stdio.h>
#include<math.h>

// global declaration
int bnm1[4],bnm2[4],bt=0,sr=0,temp[4],cnm1[4];
//functions

int binary_j(int c,int a )
{	
	int b[4];
      	int i=0,j=0;
    	int temp1=a;
	int temp2=c;

	int bb[4];
	
	 while(c>0) 
      	{ 	
           	bb[i]=c%2; 
           	i++; 
           	c=c/2;
      	}
      		printf("Binary number of %d is = ",temp2); 

     	 for(j=i-1;j>=0;j--) 
      	{
           	 printf("%d",bb[j]);
		 bnm1[j]=bb[j];
      	}
	j=0;i=0;
	printf("\n");
     	 while(a>0) 
      	{ 	
           	b[i]=a%2; 
           	i++; 
           	a=a/2;
      	}
      		printf("Binary number of %d is = ",temp1); 

     	 for(j=i-1;j>=0;j--) 
      	{
           	 printf("%d",b[j]);
		bnm2[j]=b[j];
      	}
      	printf("\n\n");return 0;
}

//addition
add(int a[],int b[])
{
	printf("addition");
}

//shift right
shiftright()
{
bt=bnm2[4];
int jay;
for(jay=4;jay=1;jay--)
	{
	bnm2[jay-1]=bnm2[jay];
	cnm1[jay-1]=cnm1[jay];	
	}
bnm2[4]=cnm1[0];
sr++;
}

///functions
int main()
{

//local declaration
int nm1,nm2;
printf("enter first decimal no: ");
scanf("%d",&nm1);
printf("enter second binary no: ");
scanf("%d",&nm2);
int ac=binary_j(nm1,nm2);
printf("%d",ac);
//printing -ve of nm1
//booths algorithm//
printf("  $ Booths algorithm $  ");

do
{
	if((bt==1) && (bnm2[4]==0))
	{	
	add(temp,bnm1);
	shiftright(); 
	}
	else if((bt==0) && (bnm2[4]==1))
	{
	add(temp,cnm1);
	shiftright(); 
	}
	else
	{  shiftright(); }

}while(sr<5);


return 0;
}





