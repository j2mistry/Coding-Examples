#include<stdio.h>
#include<stdlib.h>
int main()
{
	int no_of_trans;
	printf("\nEnter number of transaction : ");
	scanf("%d",&no_of_trans);


	int no_of_items;
	printf("\nEnter number of items : ");
	scanf("%d",&no_of_items);
	
	
	printf("\nEnter trasaction details");
	int i=0,j=1,tmp;
	int trans[no_of_trans][no_of_items];
	
	
	//intialize transcation to zero
	for(i=0;i<no_of_trans;i++)
	{
		for(j=0;j<no_of_items;j++)
			trans[i][j]=0;
	}
	
	
	j=0;
	printf("\nplease enter item number between 1 to %d",no_of_items);
	for(i=0;i<no_of_trans;i++)
	{
		printf("\nEnter items in transcation[%d](Enter -1 when no more items in transcation)",i+1);
	        while(j<=no_of_items)
	        {
	        	scanf("%d",&tmp);
	        	if(tmp!=-1)
	        	{
	        		if(tmp>=1 && tmp<=no_of_items)
	        		{
		        		trans[i][tmp-1]=1;
       			        	j++;
		        	}
		        	else
		        		printf("please enter item number between 1 to %d",no_of_items);
	        	}
	        	else
	        		break;

	        }
	        j=1;
	}
	
	int min_sup;
	printf("\nEnter minimum support :");
	scanf("%d",&min_sup);
	//frequent 1-item set	
	int cand1[no_of_items],freq1[no_of_items];	
	
	//intialize cand1 and freq1
	for(i=0;i<no_of_items;i++)
	{
			cand1[i]=0;
			freq1[i]=0;
	}
	
	
	for(i=0;i<no_of_items;i++)
	{
		for(j=0;j<no_of_trans;j++)	
			cand1[i]+=trans[j][i];			
	}
	

	printf("\nFrequent one item set :{");
	for(i=0;i<no_of_items;i++)
	{
		if(cand1[i]>=min_sup)
		{		
			printf("{%d}  ",i+1);
			freq1[i]=1;
		}
	}	
	printf("}");
	
	
	//frequent 2 itemset
	
	int k;
	
	int cand2[no_of_items][no_of_items];
	int freq2[no_of_items][no_of_items];
	
	
	for(i=0;i<no_of_items;i++)
	{
		for(j=0;j<no_of_items;j++)
		{
			freq2[i][j]=0;
			cand2[i][j]=0;
		}
	}
	
	
	printf("\nCandidate 2-item set\n");
	for(i=0;i<no_of_items;i++)
	{
		if(freq1[i]==0)
			continue;
		for(j=0;j<=i;j++)
		{
		        if(i==j)
		          continue;	
			if(freq1[j]==0)
				continue;
			for(k=0;k<no_of_trans;k++)
			{
				if(trans[k][i]==1 && trans[k][j]==1)
					cand2[i][j]++;
				
			}
			printf("\n{%d,%d}=%d",(i+1),(j+1),cand2[i][j]);
		}
	}
	printf("\n\n Frequent 2-item set :{");
	for(i=0;i<no_of_items;i++)
	{
		for(j=0;j<no_of_items;j++)
		{
			if(cand2[i][j]>=min_sup)
			{
				freq2[i][j]=cand2[i][j];		
				printf("{%d,%d} ",(i+1),(j+1));	
			}
				
		}
	}
	printf("}");
	
	
	
	
	//candiate 3 item set
	
	int cand3[no_of_items][no_of_items][no_of_items];
	int freq3[no_of_items][no_of_items][no_of_items];
		
	for(i=0;i<no_of_items;i++)
	{
		for(j=0;j<no_of_items;j++)
		{
			for(k=0;k<no_of_items;k++)
			{
				cand3[i][j][k]=0;
				freq3[i][j][k]=0;	
			}
		}
	}
	
	
	//generate frequent 3
	int t;	
	printf("\n\n Candiadte 3-item set :{");
	for(i=0;i<no_of_items;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(freq2[i][j]==0)
				continue;
			for(k=0;k<=j;k++)
			{
				if(freq2[i][k]==0 || freq2[j][k]==0)
					continue;
				for(t=0;t<no_of_trans;t++)
				{
					if(trans[t][i]==1 && trans[t][j]==1 && trans[t][k]==1)
						cand3[i][j][k]++;
				}
				if(cand3[i][j][k]>=min_sup)
				{
					freq3[i][j][k]=cand3[i][j][k];
				//printf("{%d %d %d}= %d     ",(i+1),(j+1),(k+1),freq3[i][j][k]);        
				}
				printf("{%d %d %d}= %d     ",(i+1),(j+1),(k+1),cand3[i][j][k]);
			}
		}
	}	
	printf("}\n\n\n Frequent 3 -item set : {");
	
	for(i=0;i<no_of_items;i++)
	{
		for(j=0;j<no_of_items;j++)
		{
			for(k=0;k<no_of_items;k++)
			{
				if((freq3[i][j][k]) != 0)
					printf("{%d %d %d}= %d     ",(i+1),(j+1),(k+1),freq3[i][j][k]);
			}
		}
		
	}
	printf("}");
	
	float ans;
	int min_conf,temp;
	
	printf("Enter the min_conf \n");
	scanf("%d",&min_conf);
	
	printf("Strong rules are \n");
	
	for(i=0;i<no_of_items;i++)
	{
	    for(j=0;j<no_of_items;j++)
	    {
	        for(k=0;k<no_of_items;k++)
	        {
	            if(freq3[i][j][k] >= min_sup)
	            {
	               temp=freq3[i][j][k];
	               ans=(temp/freq1[i])*100;
	               if(ans >= min_conf)
	                   printf("\n %d -> %d ^ %d ",i+1,j+1,k+1);
	                   
	                ans=(temp/freq1[j])*100;
	               if(ans >= min_conf)
	                   printf("\n %d -> %d ^ %d ",j+1,i+1,k+1);
	                   
	                ans=(temp/freq1[j])*100;
	                if(ans >= min_conf)
	                   printf("\n %d -> %d ^ %d ",k+1,i+1,j+1);
	                   
	                ans=(temp/freq2[i][j])*100;
	                if(ans >= min_conf)
	                   printf("\n %d ^ %d -> %d ",i+1,j+1,k+1);
	                   
	                ans=(temp/freq2[j][k])*100;
	                if(ans >= min_conf)
	                   printf("\n %d ^ %d -> %d ",j+1,k+1,i+1);
	
	                ans=(temp/freq2[i][k])*100;
	                if(ans >= min_conf)
	                   printf("\n %d ^ %d -> %d ",i+1,k+1,j+1);
	           }
	        }
	     }
	   }
	return 0;
}
