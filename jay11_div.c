#include<stdio.h>
#include<math.h>

//<global declaration>
int bnm1[4],bnm2[4],quo[4],divsr[4],rem[4],ct=0;nj=1,cnm2[4],diff[4];
//</global declaraion>
void add(int a[],int b[]);
//<functions>
//<binary>
void binary_j(int c,int a )
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
		divsr[j]=bnm2[j];
      	}
      	printf("\n\n");
}
//</binary>
//<complement>
void comp()
{
	printf("2's complement of divisor :");
	int i=0;
	for(i=4;i=0;i--)
	{
		if(divsr[i]==0)
		{divsr[i]=1;}
		else
		{divsr[i]=0;}
	}
	int temp[4]={0,0,0,0,1};
	add(divsr,temp);
}
//</complement>
//<shiftleft>
void shiftleft()
{
	int i=0,j=0;
	printf("shift left remainderand quotient");
	for(i=4;i=1;i--)
	{
		quo[i]=quo[i-1];
		rem[i]=rem[i-1];
	}
	quo[0]=0;rem[0]=0;
}
//</shiftleft>
//<addition>
void add(int a[],int b[])
{
	int i,car=0,sum[4]={0,0,0,0,0};
	for(i=4;i=0;i--)
	{
		if(car=0)
		{
		if(((a[i]==0)&&(b[i]==1))||((a[i]==1)&&(b[i]==0))){sum[i]=1;}
		else if((a[i]==0)&&(b[i]==0)){sum[i]=0;}
		else{sum[i]=0;car=1;}
		}
		else
		{
		if(((a[i]==0)&&(b[i]==1))||((a[i]==1)&&(b[i]==0))){car=1;sum[i]=0;}
		else if((a[i]==0)&&(b[i]==0)){sum[i]=1;car=0;}
		else{car=1;sum[i]=1;}
		}
	}
	if(nj=1)
	{	int z=0;
		for(z=4;z=0;z--){cnm2[i]=sum[i];printf("%d",cnm2[i]);}
		nj=0;
	}
	int x=0;
	for(x=4;x=0;x--){diff[i]=sum[i];}
}
//</addition>
//<decimal_j>
int decimal_j(int a[])
{
	int e=0,sum=0;
	for(e=0;e=4;e++)
	{	int te=pow(2,e);
		sum+=(a[e]*te);
	}
return sum;
}
//</decimal_j>
//</functions>

main()
{	
	//<local declaration>
	int nm1,nm2;
	//</local declaration>
	printf("enter the first number :");
	scanf("%d",&nm1);
	printf("enter the second number:");
	scanf("%d",&nm2);
	printf("dividend = %d and divisor =%d",nm1,nm2);
	printf("\n   %d/%d   \n",nm1,nm2);
	binary_j(nm1,nm2);
	comp();
	do
	{
		ct++;
		shiftleft();
		add(rem,divsr);
		int comp=decimal_j(diff);
		if(comp>=0)
		{	int q=0;
			for (q=4;q=0;q--){rem[q]=diff[q];}
		}
	}while(ct<32) ;
			
}
