#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"hearder.h"



int ReadFile(EGraph *EGraph_t)
{
	FILE *fp, *file_write;  //��������ָ�룬һ��ָ������Ƶ��ļ���һ��ָ��Ҫд����ļ� 
	
	int num=0;//?
	unsigned short recordSize;
	unsigned int LinkID;
	unsigned short roadNameLen;
	unsigned int roadInfo; 
	char roadName[30];
	
	unsigned int classInfo;
	unsigned int brunch;
	int roadFlag;
	
	if((fp=fopen("c:\\data\\dzdt.dat","rb"))==NULL)//�򿪶������ļ� 
	{
		printf("�ļ�δ�ҵ�......");
		exit(0); 
	}
	else
		printf("�ļ����ҵ�......");
	
	file_write=fopen("c:\\data\\resule.2.txt","w");//
	
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
		classInfo = GET_DISPCLASS(roadInfo);//?
		
		if(recordSize > 12)
		{
			fread(roadName,recordSize-12,1,fp);
			strcpy(EGraph_t->roadRecord[EGraph_t->num].roadName,roadName);//zhuan?
		}
		EGraph_t->roadRecord[EGraph_t->num].recordSize=recordSize;//ÿһ�����ݴ������� 
		EGraph_t->roadRecord[EGraph_t->num].LinkID=LinkID;
		EGraph_t->roadRecord[EGraph_t->num].roadInfo=roadInfo;
		
		fprintf(file_write,"%d\t��Ϣ�Ĵ�С:%d\tLinkID:%d\t����Flag:%d\t��·��:%d\t����Link�б�ʾClass:%d\t",EGraph_t->num,recordSize,LinkID,roadFlag,brunch,classInfo);
		//����Ϣд��һ���ļ��� 
		
		if(recordSize > 12)
			fprintf(file_write,"��·���ƣ�%s\n",roadName);
		else 
			fprintf(file_write,"��·������\n");
		
		EGraph_t->num++; 
		
	}
	printf("����ȡ��¼��Ϊ��%d\n",EGraph_t->num);
	fclose(fp);
	fclose(file_write);
	return 0;
	
}





#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef hearder.h
#define hearder.h
#define MAXSIZE 65000

#define M_CHG_INT16(__data__) ((__data__>>8)|(__data__<<8))          //��ת�����ε�16λ������
#define M_CHG_INT32(__data__) ((__data__>>24)|((__data__&0xff0000)>>8)|((__data__&0xff00)<<8)|(__data__<<24))
//��ת�����͵�16������

#define GET_FLAG(__data__) ((__data__&0x80)>>7)               //��ȡ�Ƿ��е�·����
#define GET_BRUNCH(__data__) ((__data__&0x70)>>4)            //��ȡ��֧��
#define GET_DISPCLASS(__data__) (__data__&0x0f)                //��ȡ�����

typedef struct RoadRecord
{
	unsigned short recordSize;
	unsigned int LinkID;
	unsigned int roadInfo;
	char roadName[30];
}RoadRecord;

typedef struct EGraph
{
	RoadRecord roadRecord[MAXSIZE];
	int num,sorted;
}EGraph;


#endif hearder.h


