#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"hearder.h"



int ReadFile(EGraph *EGraph_t)
{
	FILE *fp, *file_write;  //定义两个指针，一个指向二进制的文件，一个指向要写入的文件 
	
	int num=0;//?
	unsigned short recordSize;
	unsigned int LinkID;
	unsigned short roadNameLen;
	unsigned int roadInfo; 
	char roadName[30];
	
	unsigned int classInfo;
	unsigned int brunch;
	int roadFlag;
	
	if((fp=fopen("c:\\data\\dzdt.dat","rb"))==NULL)//打开二进制文件 
	{
		printf("文件未找到......");
		exit(0); 
	}
	else
		printf("文件已找到......");
	
	file_write=fopen("c:\\data\\resule.2.txt","w");//
	
	while(1)
	{
		fread(&recordSize,sizeof(short int),1,fp);//读取 
		if(feof(fp))   //读取完文件返回  1   
			break;
		fread(&LinkID,sizeof(long),1,fp);
		fread(&roadNameLen,sizeof(short int),1,fp);
		fread(&roadInfo,sizeof(long),1,fp);
		
		recordSize = M_CHG_INT16(recordSize);//转化读取的二进制代码 
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
		EGraph_t->roadRecord[EGraph_t->num].recordSize=recordSize;//每一条数据传给数组 
		EGraph_t->roadRecord[EGraph_t->num].LinkID=LinkID;
		EGraph_t->roadRecord[EGraph_t->num].roadInfo=roadInfo;
		
		fprintf(file_write,"%d\t信息的大小:%d\tLinkID:%d\t有无Flag:%d\t岔路数:%d\t交叉Link列表示Class:%d\t",EGraph_t->num,recordSize,LinkID,roadFlag,brunch,classInfo);
		//把信息写到一个文件里 
		
		if(recordSize > 12)
			fprintf(file_write,"道路名称：%s\n",roadName);
		else 
			fprintf(file_write,"道路无名称\n");
		
		EGraph_t->num++; 
		
	}
	printf("共读取记录数为：%d\n",EGraph_t->num);
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

#define M_CHG_INT16(__data__) ((__data__>>8)|(__data__<<8))          //反转短整形的16位进制码
#define M_CHG_INT32(__data__) ((__data__>>24)|((__data__&0xff0000)>>8)|((__data__&0xff00)<<8)|(__data__<<24))
//反转长整型的16进制码

#define GET_FLAG(__data__) ((__data__&0x80)>>7)               //获取是否有道路名称
#define GET_BRUNCH(__data__) ((__data__&0x70)>>4)            //获取分支数
#define GET_DISPCLASS(__data__) (__data__&0x0f)                //获取分类号

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


