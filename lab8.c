
#include<stdio.h>
#include<malloc.h>
void main()
{
	int b[10],p[5],x[10],i,j,c,min,max,k,count,infr=0,exfr=0,y[10]={0};
	char n[10];
	p[0]=100;
	p[1]=275;
	p[2]=170;
	p[3]=340;
	p[4]=500;

	b[0]=500;
	b[1]=225;
	b[2]=900;
	b[3]=180;
	b[4]=80;
	b[5]=400;
	b[6]=300;
	b[7]=200;
	b[8]=120;
	b[9]=700;

	for(i=0;i<10;i++)
	{
	x[i]=b[i];
	}
	for(i=0;i<10;i++)
	{
	n[i]=(char*)malloc(b[i]*1000);
	}
	printf("1.First Fit\n");
	printf("2.Best Fit\n");
	printf("3.Worst Fit\n");
	printf("4.Next Fit\n");
	printf("Enter your choice:");
	scanf("%d",&c);

	switch(c)
	{
	case 1: 
	i=0;			
	while(i!=5)			
	{
	for(j=0;j<10;j++)
	{
	if(b[j]>=p[i])
	{
	b[j]=b[j]-p[i];
	y[j]=b[j];						
	n[j]=(char*)malloc(p[i]*1000);
	break;
	}
	}
	i++;
	}
	break;
	
	case 2: 
	count=0;
	b:	for(i=0;i<9;i++)
	{
	min=x[i];
	for(j=i+1;j<10;j++)
	{
	if(min>x[j])
	{
	min=x[j];
	x[j]=x[i];
	x[i]=min;
	}
	}
	}			
	while(count!=5)			
	{
	for(j=0;j<10;j++)
	{
	if(x[j]>=p[count])
	{
	for(k=0;k<10;k++)
	{
	if(b[k]==x[j])
	{
	b[k]=b[k]-p[count];	
	y[k]=b[k];								
	break;						
	}
	}
	x[j]=x[j]-p[count];
	n[j]=(char*)malloc(p[i]*1000);
	break;
	}
	}
	count++;
	goto b;
	}
	break;			
	case 3: 
	count=0;
	a:	for(i=0;i<9;i++)
	{
	max=x[i];
	for(j=i+1;j<10;j++)
	{
	if(max<x[j])
	{
	max=x[j];
	x[j]=x[i];
	x[i]=max;
	}
	}
	}
	while(count!=5)			
	{
	for(j=0;j<10;j++)
	{
	if(x[j]>=p[count])
	{
	for(k=0;k<10;k++)
	{
	if(b[k]==x[j])
	{
	b[k]=b[k]-p[count];	
	y[k]=b[k];								
	break;						
	}
	}
	x[j]=x[j]-p[count];
	n[j]=(char*)malloc(p[count]*1000);
	break;
	}
	}
	count++;
	goto a;
	}
	break;
	
	case 4: 
	i=0;
	k=0;
	while(i!=5)
	{
	for(j=k;j<10;j++)
	{
	if(b[j]>=p[i])
	{
	k=j;
	b[j]=b[j]-p[i];
	y[j]=b[j];
	n[j]=(char*)malloc(p[i]*1000);
	break;
	}
	if(j==9)
	{
	k=0;
	}
	}
	i++;
	}
	break;
	default:
	printf("Wrong choice\n");
	break;						
	}
	for(i=0;i<10;i++)
	{
	printf("%d\n",b[i]);
	}
	for(i=0;i<10;i++)
	{
	exfr=exfr+b[i];
	}
	for(i=0;i<10;i++)
	{
	infr=infr+y[i];
	}
	printf("Internal fragmentation %d\n",infr);
	printf("External fragmentation %d\n",exfr);
	}

