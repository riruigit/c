#include"hearder.h"

//˳����� LinkID
int searchID(EGraph *EGraph_t,int key)
{
	int i;
	EGraph_t->roadRecord[0].LinkID=key;
	for(i=MAXSIZE;EGraph_t->roadRecord[i].LinkID!=key;--i);
	if(i>0&&i<=MAXSIZE)
	{
		printf("\n��LinkID��Ӧ�ĵ�·��ϢΪ��\n");
		printf("��·�Ĵ�С��%d ",EGraph_t->roadRecord[i].recordSize);
		printf("��·��ţ�%d ",EGraph_t->roadRecord[i].LinkID);
		printf("��֧��Ϊ��%d ",EGraph_t->roadRecord[i].brunch);
		printf("����Ϊ��%d ",EGraph_t->roadRecord[i].classInfo);	
		if(EGraph_t->roadRecord[i].roadFlag==0)
				{
					printf("�޵�·����: "); 
					printf("����·");
				}	 
			else
				{
					printf("���ڵ�·����: ");
					printf("��·���ƣ�%s\n",EGraph_t->roadRecord[i].roadName);
				}
	}
	else{
		printf("\t�޴�LinkID��Ӧ�ĵ�·!\n");
	}	
 }  
 
 
 
 
  void searchB(EGraph *EGraph_t,int key)
 {	
 	int j,flag=0,i=1;
 	FILE *fp2;
 	fp2=fopen("����Link�б�ʾclass����.txt","w");
    for(j=1;j<=MAXSIZE;j++)
    {  
    	if(key==EGraph_t->roadRecord[j].classInfo)
   		{ 
			flag=1;
			if(i<=65357) 
			{
		
  				printf("��·�Ĵ�С��%d ",EGraph_t->roadRecord[j].recordSize);
				printf("��·��ţ�%d ",EGraph_t->roadRecord[j].LinkID);
				printf("��·��Ϊ��%d ",EGraph_t->roadRecord[j].brunch);
				printf("����Ϊ��%d ",EGraph_t->roadRecord[j].classInfo);
   				if(EGraph_t->roadRecord[j].roadFlag==1)
				{ printf("%s\n",EGraph_t->roadRecord[j].roadName);
				}
  		 		else printf("��·������!\n");
		
				i++;
		fprintf(fp2,"��Ϣ�Ĵ�С:%d��·���:%d\t����flag:%d��·��:%d����:%d��·����:%s\n",EGraph_t->roadRecord[j].recordSize,EGraph_t->roadRecord[j].LinkID,EGraph_t->roadRecord[j].roadFlag,
		EGraph_t->roadRecord[j].brunch,EGraph_t->roadRecord[j].classInfo,EGraph_t->roadRecord[j].roadName);
				
				
				
			}
		}
   } 
   
   if(flag==0) {printf("\t����Link�б�ʾclass���Ų�����!\n");}
  else printf("�洢���ļ�������Link�б�ʾclass����.txt\n");
   	fclose(fp2);
}
 void searchC(EGraph *EGraph_t,int key)
 {	
 	int j,flag=0,i=1;
 	FILE *fp3;
 	fp3=fopen("���Ҳ�·��.txt","w");
    for(j=1;j<=MAXSIZE;j++)
    {  
    	if(key==EGraph_t->roadRecord[j].brunch)
   		{ 
			flag=1;
			if(i<=65357) 
			{
  				printf("��·�Ĵ�С��%d ",EGraph_t->roadRecord[j].recordSize);
				printf("��·��ţ�%d ",EGraph_t->roadRecord[j].LinkID);
				printf("��·��Ϊ��%d ",EGraph_t->roadRecord[j].brunch);
				printf("����Ϊ��%d ",EGraph_t->roadRecord[j].classInfo);
   				if(EGraph_t->roadRecord[j].roadFlag==1)
				{ printf("%s\n",EGraph_t->roadRecord[j].roadName);
				}
  		 		else printf("��·������!\n");
		
				i++;
		fprintf(fp3,"��Ϣ�Ĵ�С:%d��·���:%d\t����flag:%d��·��:%d����:%d��·����:%s\n",EGraph_t->roadRecord[j].recordSize,EGraph_t->roadRecord[j].LinkID,EGraph_t->roadRecord[j].roadFlag,
		EGraph_t->roadRecord[j].brunch,EGraph_t->roadRecord[j].classInfo,EGraph_t->roadRecord[j].roadName);		
			}
		}
   } 
   if(flag==0) {printf("\t��·��������!\n");}
  else printf("�洢���ļ������Ҳ�·��.txt\n");
   	fclose(fp3);
}


//���ҵ�·���� 
void searchD(EGraph *EGraph_t,char C[20])
{
	int j;
	char str[50]="����";
	strcat(str,C);
	FILE *fp4;
 	fp4=fopen("����.txt","w");
for(j=1;j<=65357;j++)
    {  
    	if(strcmp(EGraph_t->roadRecord[j].roadName,str)==0)
   		{ 
  				printf("��·�Ĵ�С��%d ",EGraph_t->roadRecord[j].recordSize);
				printf("��·��ţ�%d ",EGraph_t->roadRecord[j].LinkID);
				printf("��·��Ϊ��%d ",EGraph_t->roadRecord[j].brunch);
				printf("����Ϊ��%d ",EGraph_t->roadRecord[j].classInfo);
   				if(EGraph_t->roadRecord[j].roadFlag==1)
				{ printf("%s\n",EGraph_t->roadRecord[j].roadName);
				}
  		 		else printf("��·������!\n");
		}
   } 
   	fclose(fp4);
}


