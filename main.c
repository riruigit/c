#include "hearder.h"
EGraph EGraph_t; 
int main()
{
	EGraph_t.num=0;
 EGraph_t.sorted=0;
	int ID,A,B;char C[20];
	int N,M,L;
	printf("/******************************---'Welcome'---*******************************/\n");
	printf("/**                           ���ӵ�ͼ����ϵͳ                             **/\n");
	printf("/**                                                                        **/\n");
	printf("/**                                                           ����ʦ��ѧԺ **/\n");
	printf("/**                                                              18���2�� **/\n");
	printf("/**                                                             2018.07.23 **/\n");
	printf("/****************************************************************************/\n"); 
	printf("\n");
	while(1)
	{	
		printf("\n");
	printf("------------------------��ѡ���������ࣺ---------------------------\n");
	printf("                        1.��ȡ�ļ���GTBL.dat��                       \n");
	printf("                        2.����                                       \n");
	printf("                        3.����                                       \n");
	printf("                        0.�˳�                                       \n");
		printf("\t\t\t���������������Ӧ����ţ�");
		scanf("%d",&N);
			switch(N)
			{
				case 0:
					printf("ϵͳ���˳�"); 
					exit(0);
					break;	
				case 1:
					printf("�ļ���ȡ��......\n");
					ReadFile(&EGraph_t);
					printf("\n��ȡ�ɹ�.....\n");
					printf("\n������txt�ļ�����·��Ϣ��ȡ.txt") ;
					printf("\n");
					break; 
		 		case 2:
					printf("\n");
					printf("\t\t************ѡ��һ�����򷽷�**************\n");
    				printf("\t\t              1.��������                  \n");
					printf("\t\t              2.ֱ�Ӳ�������              \n");
					printf("\t\t              3.ð������                  \n");
					printf("\t\t              0.������һ��                \n");
					printf("\t\t\t��������Ӧ��������ţ�") ; 
					scanf("%d",&M);
					switch(M)
					{
						case 0:
							printf("�ѷ�����һ��"); 
							break;
						case 1:
							printf("\n����������......\n"); 
                             QuickSort(&EGraph_t);
							printf("��������ɹ�...\n");
					         wirte(&EGraph_t);
					 		printf("�������ļ�����·����.txt"); 
					 		printf("\n");
							break;
						case 2:
							printf("\nֱ�Ӳ���������......\n"); 
				            InsertSort(&EGraph_t); 
						    printf("ֱ�Ӳ�������ɹ�...\n");
					        wirte(&EGraph_t);
					 		printf("�������ļ�����·����.txt"); 
					 		printf("\n");
							break;
						case 3:
							printf("\ð��������......\n"); 
				            BubbleSort(&EGraph_t);
							printf("ð������ɹ�...\n");
					        wirte(&EGraph_t);
					 		printf("�������ļ�����·����.txt"); 
					 		printf("\n");
							break;
						default:
							printf("�޴����򷽷�,���Զ�������һ��"); 
							printf("\n");
							break;
					}break;	
			    case 3:
                  	printf("\n");
                	printf("\t\t ------------��ѡ������ķ�ʽ��-------------\n");
                	printf("\t\t        1.ָ��LinkID����                    \n");
                    printf("\t\t        2.ָ������Link�б��ʾclass����     \n");
                	printf("\t\t        3.ָ�����Ҳ�·�� ����               \n");
                	printf("\t\t        4.ָ����·���� ����                 \n");
                	printf("\t\t        0.������һ��                        \n");
                	printf("\t\t\t������Ҫ�����ķ�ʽ��Ӧ����ţ�");
					scanf("%d",&L); 
					switch(L)
					 {
					 	case 0:
					 		printf("�ѷ�����һ��"); 
							break;
						case 1:
							printf("������Ҫ���ҵ�LinkID:"); 		
							scanf("%d",&ID);
							searchID(&EGraph_t,ID);
							printf("\n");
							break;
						case 2:
							printf("ָ������Link�б�ʾclass���ţ�");
							scanf("%d",&A); 
							printf("\t�˷��Ŷ�Ӧ�ĵ�·��ϢΪ��\n");
							searchB(&EGraph_t,A);
							printf("\n");
							break;
					    case 3:
							printf("������Ҫ���Ҳ�·����");
							scanf("%d",&B); 
							printf("\t�˲�·����Ӧ�ĵ�·��ϢΪ��\n");
							searchC(&EGraph_t,B);
							printf("\n");
							break;
						case 4:
							printf("������Ҫ���ҵĵ�·���ƣ�");
							scanf("%s",&C);
							printf("\t�˵�·���ƶ�Ӧ�ĵ�·��ϢΪ��\n"); 
							searchD(&EGraph_t,C); 
							printf("\n");
							break;
				    }break;
					default:
		 			printf("\n�޴˷���������Ӧ����ţ�����������...\n"); 
		 			break;			
		}
	}
return 0;
}










