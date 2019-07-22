#include"hearder.h"
int ReadFile(EGraph *EGraph_t)
{
	FILE *fp, *file_write;  //定义两个指针，一个指向二进制的文件，一个指向要写入的文件 
	
	int num=0;//
	unsigned short recordSize;
	unsigned int LinkID;
	unsigned short roadNameLen;
	unsigned int roadInfo; 
	char roadName[30];
	unsigned int classInfo;
	unsigned int brunch;
	int roadFlag;
	
	if((fp=fopen("GTBL.dat","rb"))==NULL)//打开二进制文件 
	{
		printf("文件未找到......");
		exit(0); 
	}
	
	
	file_write=fopen("道路信息读取.txt","w");//
	
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
		classInfo = GET_DISPCLASS(roadInfo);
		
		if(recordSize > 12)
		{
			fread(roadName,recordSize-12,1,fp);
			strcpy(EGraph_t->roadRecord[EGraph_t->num].roadName,roadName);//zhuan?
		}
		EGraph_t->roadRecord[EGraph_t->num].recordSize=recordSize;//每一条数据传给数组 
		EGraph_t->roadRecord[EGraph_t->num].LinkID=LinkID;
		EGraph_t->roadRecord[EGraph_t->num].roadInfo=roadInfo;
		EGraph_t->roadRecord[EGraph_t->num].brunch=brunch;
		EGraph_t->roadRecord[EGraph_t->num].roadFlag=roadFlag;
		EGraph_t->roadRecord[EGraph_t->num].classInfo=classInfo;
		
		fprintf(file_write,"%d\t信息的大小:%d\tLinkID:%d\t有无Flag:%d\t岔路数:%d\t交叉Link列表示Class:%d\t",EGraph_t->num,recordSize,LinkID,roadFlag,brunch,classInfo);
		//把信息写到一个文件里 
		
		if(recordSize > 12)
			fprintf(file_write,"道路名称：%s\n",roadName);
		else 
			fprintf(file_write,"道路无名称\n");
		
		EGraph_t->num++; 
		
	}
	printf("\n共读取记录数为：%d\n",EGraph_t->num);
	fclose(fp);
	fclose(file_write);
	return 0;
	
}

