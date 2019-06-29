#include<stdio.h>
#include<conio.h>
#include<string.h>
void add_frnd_dtls();
void search_by_roll();
void search_by_name();
void search_by_phone();
void read_all_friend();
struct frnd_dtls
{
	char name[10];
	int roll;
	char phone[10];
};
struct frnd_dtls f;
FILE *fp;
int main()
{
	int choice,flag;
	while(1)
	{
		printf("\nadd freind details -->1");
		printf("\nsearch any freind details -->2");
		printf("\nshow all of my frinds----->3");
		printf("\nexit  -->0");
		printf("\nenter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				add_frnd_dtls();
				break;
			}
			case 2:
			{
				flag=1;
				while(1)
				{
					printf("\n\t search by roll_no -->1");
					printf("\n\t search by name -->2");
					printf("\n\t search by phone_no----->3");
					printf("\n\t exit  -->0");
					printf("\nenter your choice:");
					scanf("%d",&choice);	
					switch(choice)
					{
						case 1:
							search_by_roll();
							break;
						case 2:
							search_by_name();
							break;
						case 3:
							search_by_phone();
							break;
						case 0:
							flag=0;
							break;
					}
					if(flag==0)
					break;
				}
			}
			break;
			case 3:
				{
					read_all_friend();
					break;
				}
			default:
				return 0;
		}
	}
	
}


void add_frnd_dtls()
{
	char ch='y';
	fp=fopen("F:\\bio_frnd.txt","a+");
	if (fp==NULL)
	fprintf(fp,"NAME      ROLL NO      PHONE NO\n");	
	while(ch=='y'||ch=='Y')
	{
		//fprintf(fp,"\nNAME      ROLL NO      PHONE NO\n");
		printf("\n enter NAME:");
		scanf("%s",f.name);
		fprintf(fp,"%s",f.name);
		printf("\n enter ROLL NO :");
		scanf("%d",&f.roll);
		fprintf(fp,"\t%d",f.roll);
		printf("\n enter  PHONE NUMBER :");
		scanf("%s",f.phone);
		fprintf(fp,"\t%s\n",f.phone);
		printf("add another record(y/n):");
		fflush(stdin);
		ch=getche();
	}
	fclose(fp);
}
void read_all_friend()
{
	char ch;
	fp=fopen("F:\\bio_frnd.txt","a+");
	printf("\n NAME          ROLL NO      PHONE NO");
	while(fscanf ( fp,"%s\t%d\t%s\n",f.name, &f.roll, f.phone ) != EOF)
	{
		//fscanf ( fp,"%s\t %d\t %s\n",f.name, &f.roll, f.phone );
		printf ( "\n%s\t%d\t %s\n", f.name, f.roll, f.phone ) ;
	}
	fclose(fp);
	
}



void search_by_roll()
{
	int n,flag=0;
	printf("ENTER THE ROLL_NO:");
	scanf("%d",&n);
	fp=fopen("F:\\bio_frnd.txt","a+");	
	printf("\n NAME         ROLL NO       PHONE NO\n");
	while ( fscanf ( fp,"%s\t %d\t %s\n",f.name, &f.roll, f.phone ) != EOF )
	{
		if(f.roll==n)
		{
			flag=1;
			printf ( "%s\t %d\t %s\n", f.name, f.roll, f.phone ) ;
			break;
		}
	}
	if(flag==0)
		printf("\n not present in the file");
    fclose(fp);
}
void search_by_name()
{
	char n[20];
	int i,count,flag;
	printf("\n\tENTER THE NAME(part wise check)::");
	scanf("%s",n);
	fp=fopen("F:\\bio_frnd.txt","a+");
	printf("\nNAME       ROLL NO       PHONE NO\n");
	flag=0;	
	while ( fscanf ( fp,"%s\t %d\t %s\n",f.name, &f.roll, f.phone ) != EOF )
	{
		count=0;
		for(i=0;i<strlen(n);i++)
		{
			if((f.name[i]==n[i]))
			{	
				count++;
				if(strlen(n)==count)
					{   
						flag=1;
						printf ( "%s\t %d\t %s\n", f.name, f.roll, f.phone );
						break;
					}
			}
			else
				break;
		}
	}
	if(flag==0)
		printf("\n not present in the file");
    fclose(fp);	
	
}
void search_by_phone()
{
	char p[5];
	printf("enter phone no:");
	scanf("%s",&p);
	fp=fopen("F:\\bio_frnd.txt","a+");	
	printf("\n NAME         ROLL NO       PHONE NO\n");
	while ( fscanf ( fp,"%s\t %d\t %s\n",f.name, &f.roll, f.phone ) != EOF )
	{
		if(strcmp(f.phone,p)==0)
		{
			printf ( "%s\t %d\t %s\n", f.name, f.roll, f.phone ) ;
			break;
		}
		
	}
    fclose(fp);
}
