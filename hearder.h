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
	unsigned short recordSize;                               //道路大小 
	unsigned int LinkID;                                     //道路ID 
	unsigned int roadInfo;                                   // 道路信息 
	char roadName[30];                                      //道路名 
	short int brunch;                                        //分岔数 
	short int roadFlag;                                    //状态，如果为1，则存在道路名称 
	short int classInfo;                                    //交叉link表示class番号 
}RoadRecord;
typedef struct EGraph
{
	RoadRecord roadRecord[MAXSIZE];
	int num,sorted;
	 
}EGraph;
#endif hearder.h
















