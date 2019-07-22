#include"hearder.h"
EGraph EGraph_t;

int Partition(EGraph *EGraph_t,int low,int high)
{ 
	//对顺序表L中的子表r[low..high]进行一趟排序，返回枢轴位置
	int pivotkey;
	EGraph_t->roadRecord[0]=EGraph_t->roadRecord[low];                    	//用子表的第一个记录做枢轴记录
	pivotkey=EGraph_t->roadRecord[low].LinkID;		   			//枢轴记录关键字保存在pivotkey中
	while(low<high)
	{										//从表的两端交替地向中间扫描
		while(low<high&&EGraph_t->roadRecord[high].LinkID>=pivotkey) --high;
		EGraph_t->roadRecord[low]=EGraph_t->roadRecord[high];					//将比枢轴记录小的记录移到低端
		while(low<high&&EGraph_t->roadRecord[low].LinkID<=pivotkey) ++low;
		EGraph_t->roadRecord[high]=EGraph_t->roadRecord[low];					//将比枢轴记录大的记录移到高端
	}//while
	EGraph_t->roadRecord[low]=EGraph_t->roadRecord[0];						//枢轴记录到位
	return  low;							//返回枢轴位置
}//Partition

void QSort(EGraph *EGraph_t,int low,int high)
{	//调用前置初值：low=1; high=L.length;
    //对顺序表L中的子序列L.r[low..high]做快速排序
	int pivotloc;
    if(low<high)
	{										//长度大于1
       pivotloc=Partition(EGraph_t,low,high); 		//将L.r[low..high]一分为二，pivotloc是枢轴位置
       QSort(EGraph_t,low,pivotloc-1);				//对左子表递归排序
       QSort(EGraph_t,pivotloc+1,high);        	//对右子表递归排序
	}
}	
										//QSort
void QuickSort(EGraph *EGraph_t)
{
   //对顺序表L做快速排序
   QSort(EGraph_t,1,63536);
}



void BubbleSort(EGraph *EGraph_t)
{
	//对顺序表L做冒泡排序
	int m,j;
RoadRecord t;
    m=63536; 				//flag用来标记某一趟排序是否发生交换
    while(m>0)
	{
	          				//flag置为0，如果本趟排序没有发生交换，则不会执行下一趟排序
        for(j=1;j<=63536;j++)
			if(EGraph_t->roadRecord[j].LinkID>EGraph_t->roadRecord[j+1].LinkID) 
			{
								//flag置为1，表示本趟排序发生了交换
				t=EGraph_t->roadRecord[j];EGraph_t->roadRecord[j]=EGraph_t->roadRecord[j+1];EGraph_t->roadRecord[j+1]=t;	//交换前后两个记录
			}							//if
		--m;
    }									//while
}	



void InsertSort(EGraph *EGraph_t)                                                                                       //进行插入排序 
{
	int i,j; 		                       
	for(i=2;i<=EGraph_t->num;++i)                     
		if(EGraph_t->roadRecord[i].LinkID<EGraph_t->roadRecord[i-1].LinkID)                                             // “<”，需要将r[i]插入有序字表 
		{                
			EGraph_t->roadRecord[0]=EGraph_t->roadRecord[i];                                                            //将待插入的记录暂存到监视哨中 
			EGraph_t->roadRecord[i]=EGraph_t->roadRecord[i-1];			                                                //r[i-1]后移 
			for(j=i-2;EGraph_t->roadRecord[0].LinkID<EGraph_t->roadRecord[j].LinkID;--j)                                //从后向前寻找插入位置 
				EGraph_t->roadRecord[j+1]=EGraph_t->roadRecord[j];                                                      //记录逐个后移，直到找到插入位置 
			EGraph_t->roadRecord[j+1]=EGraph_t->roadRecord[0];					                                        //将r[0]即原人[i],插入到正确位置 
		}	
}



int wirte(EGraph *EGraph_t)
{
	FILE *fp1;
	int i;
	fp1=fopen("道路排序.txt","w");
	for(i=1;i<=EGraph_t->num;i++)
	{
		fprintf(fp1,"%d\t   信息的大小:%d\t   LinkID:%d\t  有无Flag:%d\t   岔路数:%d\t   交叉Link列表示Class:%d\t",i,EGraph_t->roadRecord[i].recordSize,EGraph_t->roadRecord[i].LinkID,EGraph_t->roadRecord[i].roadFlag,EGraph_t->roadRecord[i].brunch,EGraph_t->roadRecord[i].classInfo);
		//把信息写到一个文件里 
	
	if(EGraph_t->roadRecord[i].recordSize > 12)
	
		fprintf(fp1,"道路名称:%s\n",EGraph_t->roadRecord[i].roadName);		
	else
		fprintf(fp1,"道路无名称\n");
	} 
	fclose(fp1);
	return 0;
	
	
}
