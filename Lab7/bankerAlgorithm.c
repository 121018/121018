        #include<stdio.h>
       
        void main() {
        int k=0,output[10],d=0,t=0,ins[5],i,avail[5],allocated[10][5],need[10][5],Max[10][5],procno,P[10],j,res,count=0;
        
        printf("\n Enter the number of resources : ");
        scanf("%d", &res);
        printf("\n enter the maximum instances of each resources\n");
        for (i=0;i<res;i++) {
        avail[i]=0;
        printf("%d= ",i);
        scanf("%d",&ins[i]);
        }
        printf("\n Enter the number of processes : ");
        scanf("%d", &procno);
        printf("\n Enter the allocation matrix \n ");
        for (i=0;i<res;i++)
        printf(" %d",i);
        printf("\n");
        for (i=0;i <procno;i++) {
        P[i]=i;
        printf("P[%d] ",P[i]);
        for (j=0;j<res;j++) {
        scanf("%d",&allocated[i][j]);
        avail[j]+=allocated[i][j];
        }
        }
        printf("\nEnter the Max matrix \n ");
        for (i=0;i<res;i++) {
        printf(" %d",i);
        avail[i]=ins[i]-avail[i];
        }
        printf("\n");
        for (i=0;i <procno;i++) {
        printf("P[%d] ",i);
        for (j=0;j<res;j++)
        scanf("%d", &Max[i][j]);
        }
        printf("\n");
	printf("\nNeed Matrix is:\n");
        A: d=-1;
        for (i=0;i <procno;i++) {
        count=0;
        t=P[i];
	
        for (j=0;j<res;j++) {
        need[t][j] = Max[t][j]-allocated[t][j];
	printf("%d",need[t][j]);
	printf("\t");
	printf("\n");
        if(need[t][j]<=avail[j])
        count++;
        }
	//printf("\n");
        if(count==res) {
        output[k++]=P[i];
        for (j=0;j<res;j++)
        avail[j]+=allocated[t][j];
        } else
        P[++d]=P[i];
        }
        if(d!=-1) {
        procno=d+1;
        goto A;
        }
        printf("\t <");
        for (i=0;i<k;i++)
	
        printf(" P[%d] ",output[i]);
        printf(">");
       
        }


