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
	unsigned short recordSize;                               //��·��С 
	unsigned int LinkID;                                     //��·ID 
	unsigned int roadInfo;                                   // ��·��Ϣ 
	char roadName[30];                                      //��·�� 
	short int brunch;                                        //�ֲ��� 
	short int roadFlag;                                    //״̬�����Ϊ1������ڵ�·���� 
	short int classInfo;                                    //����link��ʾclass���� 
}RoadRecord;
typedef struct EGraph
{
	RoadRecord roadRecord[MAXSIZE];
	int num,sorted;
	 
}EGraph;
#endif hearder.h
















