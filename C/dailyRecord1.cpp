#include<stdio.h>
#include<conio.h>
#include<string.h>
void add_data1();
void search_by_roll();

void read_all_friend();
struct frnd_dtls
{
	char name[10];
	
	int data;
	char c[0];
};
struct frnd_dtls f;
FILE *fp;
int main()
{
	int choice,flag;
	while(1)
	{
		printf("\n enter your data -->2");
		printf("\nshow all of my frinds----->3");
		printf("\nexit  -->0");
		printf("\nenter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 2:
			{
				add_data1();
				break;
			}

			/*case 3:
				{
					read_all_friend();
					break;
				}*/
			case 0:
				return 0;
		}
	}
	
}


void add_data1()
{
	char ch='y';
	fp=fopen("F:\\Daily_record.txt","a+");
	if (fp==NULL)
	fprintf(fp,"NAME	DATA\n");	
	while(ch=='y'||ch=='Y')
	{
		//fprintf(fp,"\nNAME      ROLL NO      PHONE NO\n");
		printf("\n enter NAME:");
		scanf("%s",f.name);
		fprintf(fp,"%s",f.name);
		printf("\n enter amount :");
		scanf("%d",&f.data);
		fprintf(fp,"\t%d",f.data);
		if((f.data)<0)
		{
			printf("\n who given the amount:");
			scanf("%c",&f.c);
			fprintf(fp,"%c",f.c);
		}
		printf("add another record(y/n):");
		fflush(stdin);
		ch=getche();
	}
	fclose(fp);
}
/*void read_all_friend()
{
	char ch;
	fp=fopen("F:\\Daily_record.txt","a+");
	fprintf(fp,"NAME	DATA\n");
	while(fscanf ( fp,"%s\t%d%c\n",f.name, &f.data, f.c ) != EOF)
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
	}
	if(flag==0)
		printf("\n not present in the file");
    fclose(fp);	
	
}
void search_by_phone()
{
	char p[20];
	printf("enter  phone no:");
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
}*/
