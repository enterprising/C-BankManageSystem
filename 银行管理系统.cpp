/*��ӭʹ�����й���ϵͳ~~  */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct glxt{
	char name[20];
	char sex[10];
	double amount;
	int num;
	char password[20];
	struct glxt *next;
};
struct glxt *d1(struct glxt *link,struct glxt *head);
struct glxt *d2(int num,struct glxt *head);
struct glxt *d3(int num,struct glxt *head);
struct glxt *d4(int num,struct glxt *head);
struct glxt *d5(int num,struct glxt *head);
struct glxt *d6(int num,struct glxt *head);
struct glxt *write_file(struct glxt *head);
void d7();
void d8();
void d9();
void bl(struct glxt *head);
int check(int num,struct glxt *head);
struct glxt *read_file(struct glxt *head);
void Choice()
{
	system("color 9F");
	int i;
	for(i=0;i<160;i++)
	{
			printf("\3");
	}
	printf("\n");
	printf("\t\t**************************************\n");
	printf("\t\t********��ӭʹ�����й���ϵͳ~~********\n");
	printf("\t\t<1>���½�                    <2>����ѯ\n");
	printf("\t\t<3>���޸�                    <4>��ɾ��\n");
	printf("\t\t<5>�����                    <6>��ȡ��\n");
	printf("\t\t<7>�����ʼ���                <8>������\n");
	printf("\t\t<9>������                    <10>���˳�\n");
	printf("\t\t**************************************\n"); 
	printf("\t\t**************************************\n"); 
	printf("\n");
	system("color 9F");
		for(i=0;i<160;i++)
	{

			printf("\2");

	}
	printf("\n");
	struct glxt *head,*p,*tail;
	head=tail=p=NULL;
	int choice,num;
	char name[20];
	char sex[10];
	char password[30];
	char password1[30];
	double amount;
	int size=sizeof(struct glxt);
	do
	{
	
		printf("Input your choice:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			system("cls");
		     	printf("���������贴���Ŀ���:\n");
             	scanf("%d",&num);
             	if(check(num,head)==1)
             	{
               	printf("������������:\n");
	            scanf("%s",name);
	            printf("���������Ա�:\n");
            	scanf("%s",sex);
             	printf("������Ҫ�趨�����룺\n");
               	scanf("%s",password);
	            printf("�ٴ�������Ҫ�趨�����룺\n");
             	scanf("%s",password1);
            	if(strcmp(password1,password)==0)
	              {
                 	printf("������Ҫ����Ľ�\n");
	                scanf("%lf",&amount);
	                p=(struct glxt *)malloc(size);
     	            if(p==NULL)
                	{
	                	printf("����ռ�ʧ��");
                        exit(1);
     	            }
		                p->num=num;
	                	p->amount=amount;
	                 	strcpy(p->name,name);
	                 	strcpy(p->sex,sex);
	                	strcpy(p->password,password);
                        head=d1(p,head);
	              }
                else 
                {
             	printf("�������\n");
             	printf("�����´����û�\n");
               	Choice();
                }
                }
                else if(check(num,head)==0)
                printf("���˺��ѱ�ע�ᣡ\n");
				break; 
		    case 2:
		        system("cls");
		    	printf("������Ҫ���ҵ��û��Ŀ��ţ�");
	            scanf("%d",&num); 
				head=d2(num,head);
				break;
		    case 3:
		    	system("cls");
		        printf("������Ҫ�޸ĵĿ��ţ�");
	            scanf("%d",&num);
				head=d3(num,head);
				break;
		    case 4:
		    	system("cls");
				head=d4(num,head);
				break;
		    case 5:
		    	system("cls");
		    	printf("�������Ŀ��ţ�");
	            scanf("%d",&num);
				head=d5(num,head);
				break;
		    case 6:
		    	system("cls");
				head=d6(num,head);
				break;
		    case 7:
		    	system("cls");
				d7();
				break;
			case 8:
				system("cls");
				head=read_file(head);
				break;
			case 9:
				system("cls");
				head=write_file(head);
				break;
            case 10:
		    	system("cls");
				d8();
				break;
		   	default:
		   		system("cls");
                printf("�������!\n");
                getchar();
			    break;
		}
      }while(choice!=11);
}


struct glxt *d1(struct glxt *link,struct glxt *head)/*�½��û�*/ 
{
	system("color 9F");
	struct glxt *ptr,*ptr1,*ptr2;
	ptr2=head;
	ptr=link;
	link->next=NULL;
    if(head==NULL)
     {
        head=ptr;
        head->next=NULL;
     }
	 else if(head->next==NULL)
	 {
	 	ptr2->next=ptr;
	 	ptr->next=NULL;
	 }
	 else
	 {
	 	while(ptr2->next!=NULL)
	 	{
	 		ptr1=ptr2;
	 		ptr2=ptr2->next;
	 	}
	 	ptr2->next=ptr;
	 	ptr->next=NULL;
	 }       

	return head;
}


struct glxt *d2(int num,struct glxt *head)/*��ѯ�û�*/ 
{
	struct glxt *ptr;
	int n,c;
	ptr=head;
	if(head==NULL)
	{
	printf("NO FOUND!\n");
	return head;
	}
	else if(ptr->num==num)
	{
		printf("�������ҵĿ��Ŷ�Ӧ��Ϣ���£�\n");
		printf("\t������%s\n",ptr->name);
		printf("\t�Ա�%s\n",ptr->sex);
		printf("\t������%.2lf\n",ptr->amount);
		printf("�˳��밴1��������ѯ�밴2\n");
		scanf("%d",&n); 
		if(n==1)
		   getchar();
		else if(n==2)
			   {
			   system("cls");
		   	   printf("������Ҫ���ҵ��û��Ŀ��ţ�");
			   scanf("%d",&num); 
			   head=d2(num,head);
		       }
		else
		{
		   printf("�������,ϵͳ���Զ��˻������棡\n");
		   getchar(); 
	    }
	}
	else
	{
	    c=0;
	do
	{
		ptr=ptr->next;
		if(ptr->num=num)
		c=1;
	    
	}while(ptr->next!=NULL);
		if(c=1)
		{
		
		printf("�������ҵĿ��Ŷ�Ӧ��Ϣ���£�\n");
		printf("\t������%s\n",ptr->name);
		printf("\t�Ա�%s\n",ptr->sex);
		printf("\t������%.2lf\n",ptr->amount);
		printf("�˳��밴1��������ѯ�밴2\n");
		scanf("%d",&n); 
		if(n==1)
		   getchar();
		else if(n==2)
		   	{
		   	system("cls");
		   	printf("������Ҫ���ҵ��û��Ŀ��ţ�");
			scanf("%d",&num); 
			head=d2(num,head);
		    }
		else
		   {
		   printf("�������,ϵͳ���Զ��˻������棡");
		   Choice(); 
	       }
	   }
	   else
	   printf("NO FOUND\n");
	}

	return head;
}
struct glxt *d3(int num,struct glxt *head)/*�޸Ĳ���*/
{
	int xz;
	int c=0;
	char name[20];
	char sex[10];
	struct glxt *ptr;
	ptr=head;
	if(ptr->num==num)
	{ 
	c=1;
	printf("1��������2���Ա�3������\n");
	printf("ѡ����Ҫ�޸ĵ�����:");
	scanf("%d",&xz);
	switch(xz)
	{
		case 1:
			printf("�����������û�����");
			scanf("%s",name); 
			strcpy(ptr->name,name);
			printf("%s %s %d",ptr->name,ptr->sex,ptr->num);
			break;
		case 2:
			printf("�����������Ա�~~��");
			scanf("%s",sex) ;
			strcpy(ptr->sex,sex);
			printf("%s %s %d",ptr->name,ptr->sex,ptr->num);
			break; 
		case 3:
			printf("���������¿��ţ�");
			scanf("%d",&num); 
			ptr->num=num;
			printf("%s %s %d",ptr->name,ptr->sex,ptr->num);
			break;
		default:
			printf("�������");
			break;
	}
    }
    else
    {
    	do
		{
    		ptr=ptr->next;
    	}while(ptr->num!=num);
    c=1;
   	printf("1��������2���Ա�3������\n");
	printf("ѡ����Ҫ�޸ĵ�����:");
	scanf("%d",&xz);
	switch(xz)
	{
		case 1:
			printf("�����������û�����");
			scanf("%s",name); 
			strcpy(ptr->name,name);
			printf("%s%s%d",ptr->name,ptr->sex,ptr->num);
			break;
		case 2:
			printf("�����������Ա�~~��");
		    scanf("%s",sex) ;
			strcpy(ptr->sex,sex);
			printf("%s%s%d",ptr->name,ptr->sex,ptr->num);
			break;
		case 3:
			printf("���������¿��ţ�");
			scanf("%d",&num); 
			ptr->num=num;
			printf("%s%s%d",ptr->name,ptr->sex,ptr->num);
			break;
		default:
			printf("�������");
			break;
    }
    }
    if(c=0)
    {
    	printf("NO FOUND!\n");
    }
	return head;
}

struct glxt *d4(int num,struct glxt *head)/*ɾ������*/ 
{
	struct glxt *ptr1,*ptr2;
	printf("������Ҫɾ�����û����ţ�");
	scanf("%d",&num);
	while(head!=NULL&&head->num==num)  /*Ҫɾ���Ľ��Ϊ��ͷ�ڵ�*/
	{
	ptr2=head;
	head=head->next;
	free(ptr2);	
	}
	if(head==NULL)   /*�����*/
	{
		return NULL;
	}
	/*Ҫɾ���Ľ��Ϊ�Ǳ�ͷ�ڵ�*/
	ptr1=head;
	ptr2=head->next;/*�ӱ�ͷ����һ������������еķ���Ҫ��Ľ��*/
	while(ptr2!=NULL)
	{
		if(ptr2->num=num)
		{
			ptr1->next=ptr2->next;
			free(ptr2);
		}
		else
		ptr1=ptr2;
		ptr2=ptr1->next;
	} 
	return head;
}
struct glxt *d5(int num,struct glxt *head)/*���*/ 
{
	double deposit;
	double c;
	struct glxt *ptr;
	ptr=head;
	if(ptr==NULL)
	 return NULL;
	 else if(ptr->num==num)
	 {
	 printf("������Ҫ����Ľ�");
	 scanf("%lf",&deposit);
	 c=ptr->amount;
	 c=c+deposit;
	 ptr->amount=c;
	 printf("�����ڵ����Ϊ��%lf\n",ptr->amount);
}
	else
	{
		do
		{
			ptr=ptr->next;
		}while(ptr->num!=num);
		printf("������Ҫ����Ľ�");
		scanf("%lf",&deposit);
		c=ptr->amount;
		c=c+deposit;
	    ptr->amount=c;
	    printf("�����ڵ����Ϊ��%lf\n",ptr->amount);
	}
return head;
}
struct glxt *d6(int num,struct glxt *head)/*ȡ��*/ 
{
	system("color 4F");
	double minus,c;
	struct glxt *ptr;
	printf("�������Ŀ��ţ�");
	scanf("%d",&num);
	ptr=head;
	if(ptr==NULL)
	 return NULL;
	 else if(ptr->num==num)
	 {
	 printf("������Ҫȡ���Ľ�"); 
	    scanf("%lf",&minus);
		c=ptr->amount;
		c=c-minus;
	    ptr->amount=c;
	    printf("�����ڵ����Ϊ��%lf\n",ptr->amount);
	}
	else
	{
		
		do
		{
			ptr=ptr->next;
		}while(ptr->num!=num);
		printf("������Ҫȡ���Ľ�"); 
	    scanf("%lf",&minus);
		c=ptr->amount;
		c=c-minus;
	    ptr->amount=c;
	    printf("�����ڵ����Ϊ��%lf\n",ptr->amount);
	}
return head;
}
void d7()
{
	int choice,n,a,b=0,c;
	double year;
	double amount,result;
	system("color 5F");
	printf("\t\t\t��ӭ����������㡣\n");
	printf("\t\t���ڴ��                �����ʣ�0.35\n");
	printf("\t\t3���¶���               �����ʣ�2.35\n");
    printf("\t\t���궨��                �����ʣ�2.55\n");
    printf("\t\t1�궨��                 �����ʣ�2.75\n");
    printf("\t\t2�궨��                 �����ʣ�3.35\n");
    printf("\t\t3�궨��                 �����ʣ�4.00\n");
    printf("��������ѡ��1�����ڣ�2������\n");
    scanf("%d",&choice);
    if(choice==1)
    {
    	printf("�������ı����Լ����ʱ�䣨��λ���꣩\n");
    	scanf("%lf%lf",&amount,&year);
    	result=amount*0.35*year/100+amount;
    	printf("�������㣬%.2lf�����ɻ�õ��ʽ��ܶ�Ϊ%lf",year,result);
    	b=1;
    	
    }
    else if(choice==2)
    {
    	printf("�������ı���\n");
    	scanf("%lf",&amount);
    	printf("ѡ����Ҫ�����ʱ�䡣1�������¡�2�����ꡣ3��һ�ꡣ4�����ꡣ5������\n");
    	scanf("%d",&n);
        if(n==1)
    		{
    	        result=amount*2.35*0.25/100+amount;
    	     	printf("�������㣬�����º�����õ��ʽ��ܶ�Ϊ��%.2lf",result);
    	     	b=1;
			}   
        else if(n==2)
            {
       			result=amount*2.55*0.5/100+amount;
    			printf("�������㣬���������õ��ʽ��ܶ�Ϊ��%.2lf",result);
    			b=1;
            }
        else if(n==3)
            {
      			result=amount*2.75*1/100+amount;
    			printf("�������㣬һ�������õ��ʽ��ܶ�Ϊ��%.2lf",result);
    			b=1;
            }
    	else if(n==4)
    	    {
      			result=amount*3.35*2/100+amount;
    			printf("�������㣬���������õ��ʽ��ܶ�Ϊ��%.2lf",result);
    			b=1;
            }
    	else if(n==5)
    	    {
       			result=amount*4.00*3/100+amount;
    			printf("�������㣬���������õ��ʽ��ܶ�Ϊ��%.2lf",result);
    			b=1;
    		}
    	else
    	{
    	printf("�������ϵͳ���������ʼ������\n");
        printf("�����������밴����1��\n");
		scanf("%d",&a);
		if(a==1)
		{
		system("cls");
        d7();
		}
    	}
    	
    }
    else
    {
    	printf("�������ϵͳ���������ʼ������\n");
        printf("�����������밴����1��\n");
		scanf("%d",&a);
		if(a==1)
		{
		system("cls");
        d7();
		}
    }
if(b==1)
{
	printf("\n");
	printf("�����������ӭʹ��~\n");
	printf("����������������1���˳�ϵͳ���������1֮�����������\n");
	scanf("%d",&c);
	if(c==1)
	{
		system("cls");
		Choice();
	} 
	else
	{
		system("cls");
		d8();
	}
}
}
void d8()
{
	system("color 1F");
	printf("��������˳�...");
    exit(0);
}
void d9()
{
	 int a;
	 system("color 3F"); 
	 printf("������󣬷�����������ѡ��1��,�����1��������������˳�ϵͳ\n");
     scanf("%d",&a);
	 if(a==1)
	 {
		 system("cls");
         Choice();
	 }
	 else
	 {
	 	system("cls");
        d8();
	 }
}

struct glxt *write_file(struct glxt *head)
{
   FILE *fp1;
   struct glxt *p;
   system("cls");
   p=head;
  if((fp1=fopen("best.txt","a+"))==NULL)
	{
	printf("open error!");
	
	exit(0);	
	}	
   while(p!=NULL)
   {
   /* 
   if(fwrite(p,sizeof(struct glxt),1,fp1)!=1);
      {
      printf("write error!");
      } 
   */    
      if(fprintf(fp1,"%d %lf %s %s ",p->num,p->amount,p->sex,p->name,p->password)==NULL)
      {
			printf("\n\n\n\n\n\n\n\n         д��ʧ��!\n");
		
	  }
              p=p->next;  
   }
   printf("\n    ����ɹ���\n\n");
   Choice(); 
  if(fclose(fp1))
	{
		printf("close error!");
		exit(0);
	} 
	return head;
}
struct glxt *read_file(struct glxt *head)
{
	FILE *fp;
	struct glxt *p;
	system("cls");
	p=head;
	fp=fopen("best.txt","a+");
	if(fp==NULL)
	{ 
		printf("open error!");
	
	exit(0);	
	}  
     while(!feof(fp))
	 {  
		 
	    p=(struct glxt *)malloc(sizeof(struct glxt));
        fscanf(fp,"%d%lf%s%s\n",&p->num,&p->amount,p->sex,p->name);
		printf("����:%d\n���:%lf\n�Ա�:%s\n����:%s\n",p->num,p->amount,p->sex,p->name);
	 }
	return head;
}

int check(int num,struct glxt *head)
{
	int c=1;
	struct glxt *ptr;
	ptr=head;
	if(head==NULL)
	c=1;
	else if(ptr->num==num)
	{
	     c=0;
	}
	else if(ptr->next==NULL)
	{
		 c=1;
	}
    else 
	{
	    do 
		{
			ptr=ptr->next;
            if(ptr->num==num)
              c=0;
		}while(ptr->next!=NULL);

   }
return c;
}

 
int main()
{
	Choice();
}
