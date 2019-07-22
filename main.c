#include "hearder.h"
EGraph EGraph_t; 
int main()
{
	EGraph_t.num=0;
 EGraph_t.sorted=0;
	int ID,A,B;char C[20];
	int N,M,L;
	printf("/******************************---'Welcome'---*******************************/\n");
	printf("/**                           电子地图管理系统                             **/\n");
	printf("/**                                                                        **/\n");
	printf("/**                                                           岭南师范学院 **/\n");
	printf("/**                                                              18外包2班 **/\n");
	printf("/**                                                             2018.07.23 **/\n");
	printf("/****************************************************************************/\n"); 
	printf("\n");
	while(1)
	{	
		printf("\n");
	printf("------------------------请选择服务的种类：---------------------------\n");
	printf("                        1.读取文件（GTBL.dat）                       \n");
	printf("                        2.排序                                       \n");
	printf("                        3.检索                                       \n");
	printf("                        0.退出                                       \n");
		printf("\t\t\t请输入服务种类相应的序号：");
		scanf("%d",&N);
			switch(N)
			{
				case 0:
					printf("系统已退出"); 
					exit(0);
					break;	
				case 1:
					printf("文件读取中......\n");
					ReadFile(&EGraph_t);
					printf("\n读取成功.....\n");
					printf("\n已生成txt文件：道路信息读取.txt") ;
					printf("\n");
					break; 
		 		case 2:
					printf("\n");
					printf("\t\t************选择一种排序方法**************\n");
    				printf("\t\t              1.快速排序                  \n");
					printf("\t\t              2.直接插入排序              \n");
					printf("\t\t              3.冒泡排序                  \n");
					printf("\t\t              0.返回上一层                \n");
					printf("\t\t\t请输入相应方法的序号：") ; 
					scanf("%d",&M);
					switch(M)
					{
						case 0:
							printf("已返回上一层"); 
							break;
						case 1:
							printf("\n快速排序中......\n"); 
                             QuickSort(&EGraph_t);
							printf("快速排序成功...\n");
					         wirte(&EGraph_t);
					 		printf("已生成文件：道路排序.txt"); 
					 		printf("\n");
							break;
						case 2:
							printf("\n直接插入排序中......\n"); 
				            InsertSort(&EGraph_t); 
						    printf("直接插入排序成功...\n");
					        wirte(&EGraph_t);
					 		printf("已生成文件：道路排序.txt"); 
					 		printf("\n");
							break;
						case 3:
							printf("\冒泡排序中......\n"); 
				            BubbleSort(&EGraph_t);
							printf("冒泡排序成功...\n");
					        wirte(&EGraph_t);
					 		printf("已生成文件：道路排序.txt"); 
					 		printf("\n");
							break;
						default:
							printf("无此排序方法,已自动返回上一层"); 
							printf("\n");
							break;
					}break;	
			    case 3:
                  	printf("\n");
                	printf("\t\t ------------请选择检索的方式：-------------\n");
                	printf("\t\t        1.指定LinkID查找                    \n");
                    printf("\t\t        2.指定交叉Link列表表示class番号     \n");
                	printf("\t\t        3.指定查找岔路数 检索               \n");
                	printf("\t\t        4.指定道路名称 检索                 \n");
                	printf("\t\t        0.返回上一层                        \n");
                	printf("\t\t\t请输入要检索的方式相应的序号：");
					scanf("%d",&L); 
					switch(L)
					 {
					 	case 0:
					 		printf("已返回上一层"); 
							break;
						case 1:
							printf("请输入要查找的LinkID:"); 		
							scanf("%d",&ID);
							searchID(&EGraph_t,ID);
							printf("\n");
							break;
						case 2:
							printf("指定交叉Link列表示class番号：");
							scanf("%d",&A); 
							printf("\t此番号对应的道路信息为：\n");
							searchB(&EGraph_t,A);
							printf("\n");
							break;
					    case 3:
							printf("请输入要查找岔路数：");
							scanf("%d",&B); 
							printf("\t此岔路数对应的道路信息为：\n");
							searchC(&EGraph_t,B);
							printf("\n");
							break;
						case 4:
							printf("请输入要查找的道路名称：");
							scanf("%s",&C);
							printf("\t此道路名称对应的道路信息为：\n"); 
							searchD(&EGraph_t,C); 
							printf("\n");
							break;
				    }break;
					default:
		 			printf("\n无此服务种类相应的序号！请重新输入...\n"); 
		 			break;			
		}
	}
return 0;
}










