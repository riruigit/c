#include"hearder.h"
EGraph EGraph_t;

int Partition(EGraph *EGraph_t,int low,int high)
{ 
	//��˳���L�е��ӱ�r[low..high]����һ�����򣬷�������λ��
	int pivotkey;
	EGraph_t->roadRecord[0]=EGraph_t->roadRecord[low];                    	//���ӱ�ĵ�һ����¼�������¼
	pivotkey=EGraph_t->roadRecord[low].LinkID;		   			//�����¼�ؼ��ֱ�����pivotkey��
	while(low<high)
	{										//�ӱ�����˽�������м�ɨ��
		while(low<high&&EGraph_t->roadRecord[high].LinkID>=pivotkey) --high;
		EGraph_t->roadRecord[low]=EGraph_t->roadRecord[high];					//���������¼С�ļ�¼�Ƶ��Ͷ�
		while(low<high&&EGraph_t->roadRecord[low].LinkID<=pivotkey) ++low;
		EGraph_t->roadRecord[high]=EGraph_t->roadRecord[low];					//���������¼��ļ�¼�Ƶ��߶�
	}//while
	EGraph_t->roadRecord[low]=EGraph_t->roadRecord[0];						//�����¼��λ
	return  low;							//��������λ��
}//Partition

void QSort(EGraph *EGraph_t,int low,int high)
{	//����ǰ�ó�ֵ��low=1; high=L.length;
    //��˳���L�е�������L.r[low..high]����������
	int pivotloc;
    if(low<high)
	{										//���ȴ���1
       pivotloc=Partition(EGraph_t,low,high); 		//��L.r[low..high]һ��Ϊ����pivotloc������λ��
       QSort(EGraph_t,low,pivotloc-1);				//�����ӱ�ݹ�����
       QSort(EGraph_t,pivotloc+1,high);        	//�����ӱ�ݹ�����
	}
}	
										//QSort
void QuickSort(EGraph *EGraph_t)
{
   //��˳���L����������
   QSort(EGraph_t,1,63536);
}



void BubbleSort(EGraph *EGraph_t)
{
	//��˳���L��ð������
	int m,j;
RoadRecord t;
    m=63536; 				//flag�������ĳһ�������Ƿ�������
    while(m>0)
	{
	          				//flag��Ϊ0�������������û�з����������򲻻�ִ����һ������
        for(j=1;j<=63536;j++)
			if(EGraph_t->roadRecord[j].LinkID>EGraph_t->roadRecord[j+1].LinkID) 
			{
								//flag��Ϊ1����ʾ�����������˽���
				t=EGraph_t->roadRecord[j];EGraph_t->roadRecord[j]=EGraph_t->roadRecord[j+1];EGraph_t->roadRecord[j+1]=t;	//����ǰ��������¼
			}							//if
		--m;
    }									//while
}	



void InsertSort(EGraph *EGraph_t)                                                                                       //���в������� 
{
	int i,j; 		                       
	for(i=2;i<=EGraph_t->num;++i)                     
		if(EGraph_t->roadRecord[i].LinkID<EGraph_t->roadRecord[i-1].LinkID)                                             // ��<������Ҫ��r[i]���������ֱ� 
		{                
			EGraph_t->roadRecord[0]=EGraph_t->roadRecord[i];                                                            //��������ļ�¼�ݴ浽�������� 
			EGraph_t->roadRecord[i]=EGraph_t->roadRecord[i-1];			                                                //r[i-1]���� 
			for(j=i-2;EGraph_t->roadRecord[0].LinkID<EGraph_t->roadRecord[j].LinkID;--j)                                //�Ӻ���ǰѰ�Ҳ���λ�� 
				EGraph_t->roadRecord[j+1]=EGraph_t->roadRecord[j];                                                      //��¼������ƣ�ֱ���ҵ�����λ�� 
			EGraph_t->roadRecord[j+1]=EGraph_t->roadRecord[0];					                                        //��r[0]��ԭ��[i],���뵽��ȷλ�� 
		}	
}



int wirte(EGraph *EGraph_t)
{
	FILE *fp1;
	int i;
	fp1=fopen("��·����.txt","w");
	for(i=1;i<=EGraph_t->num;i++)
	{
		fprintf(fp1,"%d\t   ��Ϣ�Ĵ�С:%d\t   LinkID:%d\t  ����Flag:%d\t   ��·��:%d\t   ����Link�б�ʾClass:%d\t",i,EGraph_t->roadRecord[i].recordSize,EGraph_t->roadRecord[i].LinkID,EGraph_t->roadRecord[i].roadFlag,EGraph_t->roadRecord[i].brunch,EGraph_t->roadRecord[i].classInfo);
		//����Ϣд��һ���ļ��� 
	
	if(EGraph_t->roadRecord[i].recordSize > 12)
	
		fprintf(fp1,"��·����:%s\n",EGraph_t->roadRecord[i].roadName);		
	else
		fprintf(fp1,"��·������\n");
	} 
	fclose(fp1);
	return 0;
	
	
}
