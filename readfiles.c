#include"hearder.h"
int ReadFile(EGraph *EGraph_t)
{
	FILE *fp, *file_write;  //��������ָ�룬һ��ָ������Ƶ��ļ���һ��ָ��Ҫд����ļ� 
	
	int num=0;//
	unsigned short recordSize;
	unsigned int LinkID;
	unsigned short roadNameLen;
	unsigned int roadInfo; 
	char roadName[30];
	unsigned int classInfo;
	unsigned int brunch;
	int roadFlag;
	
	if((fp=fopen("GTBL.dat","rb"))==NULL)//�򿪶������ļ� 
	{
		printf("�ļ�δ�ҵ�......");
		exit(0); 
	}
	
	
	file_write=fopen("��·��Ϣ��ȡ.txt","w");//
	
	while(1)
	{
		fread(&recordSize,sizeof(short int),1,fp);//��ȡ 
		if(feof(fp))   //��ȡ���ļ�����  1   
			break;
		fread(&LinkID,sizeof(long),1,fp);
		fread(&roadNameLen,sizeof(short int),1,fp);
		fread(&roadInfo,sizeof(long),1,fp);
		
		recordSize = M_CHG_INT16(recordSize);//ת����ȡ�Ķ����ƴ��� 
		LinkID = M_CHG_INT32(LinkID);
		roadNameLen =  M_CHG_INT16(roadNameLen);
		
		roadInfo = M_CHG_INT32(roadInfo);
		roadFlag = GET_FLAG(roadInfo);
		brunch = GET_BRUNCH(roadInfo);
		classInfo = GET_DISPCLASS(roadInfo);
		
		if(recordSize > 12)
		{
			fread(roadName,recordSize-12,1,fp);
			strcpy(EGraph_t->roadRecord[EGraph_t->num].roadName,roadName);//zhuan?
		}
		EGraph_t->roadRecord[EGraph_t->num].recordSize=recordSize;//ÿһ�����ݴ������� 
		EGraph_t->roadRecord[EGraph_t->num].LinkID=LinkID;
		EGraph_t->roadRecord[EGraph_t->num].roadInfo=roadInfo;
		EGraph_t->roadRecord[EGraph_t->num].brunch=brunch;
		EGraph_t->roadRecord[EGraph_t->num].roadFlag=roadFlag;
		EGraph_t->roadRecord[EGraph_t->num].classInfo=classInfo;
		
		fprintf(file_write,"%d\t��Ϣ�Ĵ�С:%d\tLinkID:%d\t����Flag:%d\t��·��:%d\t����Link�б�ʾClass:%d\t",EGraph_t->num,recordSize,LinkID,roadFlag,brunch,classInfo);
		//����Ϣд��һ���ļ��� 
		
		if(recordSize > 12)
			fprintf(file_write,"��·���ƣ�%s\n",roadName);
		else 
			fprintf(file_write,"��·������\n");
		
		EGraph_t->num++; 
		
	}
	printf("\n����ȡ��¼��Ϊ��%d\n",EGraph_t->num);
	fclose(fp);
	fclose(file_write);
	return 0;
	
}

