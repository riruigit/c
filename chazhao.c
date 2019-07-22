#include"hearder.h"

//顺序查找 LinkID
int searchID(EGraph *EGraph_t,int key)
{
	int i;
	EGraph_t->roadRecord[0].LinkID=key;
	for(i=MAXSIZE;EGraph_t->roadRecord[i].LinkID!=key;--i);
	if(i>0&&i<=MAXSIZE)
	{
		printf("\n此LinkID对应的道路信息为：\n");
		printf("道路的大小：%d ",EGraph_t->roadRecord[i].recordSize);
		printf("道路编号：%d ",EGraph_t->roadRecord[i].LinkID);
		printf("分支数为：%d ",EGraph_t->roadRecord[i].brunch);
		printf("番号为：%d ",EGraph_t->roadRecord[i].classInfo);	
		if(EGraph_t->roadRecord[i].roadFlag==0)
				{
					printf("无道路名称: "); 
					printf("无名路");
				}	 
			else
				{
					printf("存在道路名称: ");
					printf("道路名称：%s\n",EGraph_t->roadRecord[i].roadName);
				}
	}
	else{
		printf("\t无此LinkID对应的道路!\n");
	}	
 }  
 
 
 
 
  void searchB(EGraph *EGraph_t,int key)
 {	
 	int j,flag=0,i=1;
 	FILE *fp2;
 	fp2=fopen("交叉Link列表示class番号.txt","w");
    for(j=1;j<=MAXSIZE;j++)
    {  
    	if(key==EGraph_t->roadRecord[j].classInfo)
   		{ 
			flag=1;
			if(i<=65357) 
			{
		
  				printf("道路的大小：%d ",EGraph_t->roadRecord[j].recordSize);
				printf("道路编号：%d ",EGraph_t->roadRecord[j].LinkID);
				printf("岔路数为：%d ",EGraph_t->roadRecord[j].brunch);
				printf("番号为：%d ",EGraph_t->roadRecord[j].classInfo);
   				if(EGraph_t->roadRecord[j].roadFlag==1)
				{ printf("%s\n",EGraph_t->roadRecord[j].roadName);
				}
  		 		else printf("道路无名称!\n");
		
				i++;
		fprintf(fp2,"信息的大小:%d道路编号:%d\t有无flag:%d岔路数:%d番号:%d道路名称:%s\n",EGraph_t->roadRecord[j].recordSize,EGraph_t->roadRecord[j].LinkID,EGraph_t->roadRecord[j].roadFlag,
		EGraph_t->roadRecord[j].brunch,EGraph_t->roadRecord[j].classInfo,EGraph_t->roadRecord[j].roadName);
				
				
				
			}
		}
   } 
   
   if(flag==0) {printf("\t交叉Link列表示class番号不存在!\n");}
  else printf("存储到文件：交叉Link列表示class番号.txt\n");
   	fclose(fp2);
}
 void searchC(EGraph *EGraph_t,int key)
 {	
 	int j,flag=0,i=1;
 	FILE *fp3;
 	fp3=fopen("查找岔路数.txt","w");
    for(j=1;j<=MAXSIZE;j++)
    {  
    	if(key==EGraph_t->roadRecord[j].brunch)
   		{ 
			flag=1;
			if(i<=65357) 
			{
  				printf("道路的大小：%d ",EGraph_t->roadRecord[j].recordSize);
				printf("道路编号：%d ",EGraph_t->roadRecord[j].LinkID);
				printf("岔路数为：%d ",EGraph_t->roadRecord[j].brunch);
				printf("番号为：%d ",EGraph_t->roadRecord[j].classInfo);
   				if(EGraph_t->roadRecord[j].roadFlag==1)
				{ printf("%s\n",EGraph_t->roadRecord[j].roadName);
				}
  		 		else printf("道路无名称!\n");
		
				i++;
		fprintf(fp3,"信息的大小:%d道路编号:%d\t有无flag:%d岔路数:%d番号:%d道路名称:%s\n",EGraph_t->roadRecord[j].recordSize,EGraph_t->roadRecord[j].LinkID,EGraph_t->roadRecord[j].roadFlag,
		EGraph_t->roadRecord[j].brunch,EGraph_t->roadRecord[j].classInfo,EGraph_t->roadRecord[j].roadName);		
			}
		}
   } 
   if(flag==0) {printf("\t岔路数不存在!\n");}
  else printf("存储到文件：查找岔路数.txt\n");
   	fclose(fp3);
}


//查找道路名称 
void searchD(EGraph *EGraph_t,char C[20])
{
	int j;
	char str[50]="１＝";
	strcat(str,C);
	FILE *fp4;
 	fp4=fopen("查数.txt","w");
for(j=1;j<=65357;j++)
    {  
    	if(strcmp(EGraph_t->roadRecord[j].roadName,str)==0)
   		{ 
  				printf("道路的大小：%d ",EGraph_t->roadRecord[j].recordSize);
				printf("道路编号：%d ",EGraph_t->roadRecord[j].LinkID);
				printf("岔路数为：%d ",EGraph_t->roadRecord[j].brunch);
				printf("番号为：%d ",EGraph_t->roadRecord[j].classInfo);
   				if(EGraph_t->roadRecord[j].roadFlag==1)
				{ printf("%s\n",EGraph_t->roadRecord[j].roadName);
				}
  		 		else printf("道路无名称!\n");
		}
   } 
   	fclose(fp4);
}


