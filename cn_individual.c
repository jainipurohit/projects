#include<stdio.h>
#include<stdlib.h>
int a[30],n;

void insert()
{
	int i;
	printf("Enter size of data: ");
	scanf("%d",&n);
	printf("Enter data : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}
void display()
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
	printf("\n");
}
void ins_even()
{
	int i,count=0;
	for(i=0;i<n;i++)
	{
		if(a[i]==0)
		{
			break;
		}
		else if(a[i]==1)
		{
			count++;
		}
		else
		{
			printf("Enter binary");
		}
	}
	if(count%2==0)
	{
		printf("Required data: ");
		display();
	}
	else
	{
		a[n]=1;
		n++;
		printf("Data in even parity : ");
		display();
	}
}
void ins_odd()
{
	int i,count=0;
	for(i=0;i<n;i++)
	{
		if(a[i]==0)
		{
			break;
		}
		else if(a[i]==1)
		{
			count++;
		}
		else
		{
			printf("Enter data in binary");
		}
	}
	if(count%2==0)
	{
		a[n]=1;
		n++;
		printf("Data in odd parity : ");
		display();
	}
	else
	{
		printf("Data in odd parity : ");
		display();
	}
}
void ch_even()
{
	int i,count=0;
	for(i=0;i<n;i++)
	{
		if(a[i]==0)
		{
			break;
		}
		else if(a[i]==1)
		{
			count++;
		}
		else
		{
			printf("Enter data in binary");
		}
	}
	if(count%2==0)
	 printf("Data is error free ");
	else
	{
	 printf("Data has error\n");
	 ins_even();
	}
}
void ch_odd()
{
	int i,count=0;
	for(i=0;i<n;i++)
	{
		if(a[i]==0)
		{
			break;
		}
		else if(a[i]==1)
		{
			count++;
		}
		else
		{
			printf("Enter Binary");
		}
	}
	if(count%2==0)
	{
	 printf("Data has error\n ");
	 ins_odd();
	}
	else
	 printf("Data is error free");
}
void main()
{
	int choice;
	while(1)
	{
		printf("\nenter 1-even parity\n2-odd parity \n3-check even parity \n4-check odd parity \n5-exit : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert();
				ins_even();
				break;
			case 2:
				insert();
				ins_odd();
				break;
			case 3:
				insert();
				ch_even();
				break;
			case 4:
				insert();
				ch_odd();
				break;
			case 5:
				exit(0);
			default:
				printf("Enter valid input");
		}
	}
}
