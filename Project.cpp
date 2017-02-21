/***********************************************************************
*    THIS IS A CAR WORK SHOP MADE BY:				       *
*         1-YOUSIF __________________________________ 2-EZZELDIEN      *
*         3-SADDAM  __________________________________ 4-ABDALLAH      *
*                                                                      *
*                           5-AHMED SHAKER                             *
*                                                                      *
*           COPYRIGHT             31/12/2012                           *
*                                 11:24                                *
/**********************************************************************/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
char a;

/**********************************************************************/

struct carworkshop
{
int id,flag;
char name[30],address[30],phone[30],model[30],color[30],lis_plate[30],type[30],price[30];
}cw;


/**********************************************************************/

void add();
void del();
void modi();
void search_id();
void new_insert();
void list();
void search_name();

/**********************************************************************/

void main()
{
main_menu:
textbackground(BLACK);
char choice;
clrscr();
textcolor(YELLOW+BLINK);
cprintf(" * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
cprintf("\n\r*                                                                              *");
cprintf("\n\r*                                                                              *");
cprintf("\n\r*                                                                              *");
cprintf("\n\r*                                                                              *");
cprintf("\n\r*                                                                              *");
cprintf("\n\r*                                                                              *");
cprintf("\n\r*                                                                              *");
cprintf("\n\r*                                                                              *");
cprintf("\n\r*                                                                              *");
cprintf("\n\r*                                                                              *");
cprintf("\n\r*                                                                              *");
cprintf("\n\r*                                                                              *");


gotoxy(2,25);
cprintf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
textcolor(RED);
gotoxy(30,10);
cprintf("*******WELCOME*******\n\n\r");
textcolor(YELLOW+BLINK);
cprintf("*   ");
textcolor(WHITE);
cprintf(" This Is The Main Menu For The Car Workshop ->\r\n\r\n");
textcolor(YELLOW+BLINK);
cprintf("*   ");
textcolor(GREEN);
cprintf(" Please Choose A Choice ->\r\n");
textcolor(WHITE);
cprintf("      1) Would You Like To Add Any Record\r\n");
textcolor(YELLOW+BLINK);
cprintf("*   ");
textcolor(WHITE);
cprintf("  2) Would You Like To Delete Any Record\r\n      3) Would You Like To Modify Any Record\r\n");
textcolor(YELLOW+BLINK);
cprintf("*   ");
textcolor(WHITE);
cprintf("  4) Would You Like To Search With Id\r\n      5) Would You Like To List \r\n");
textcolor(YELLOW+BLINK);
cprintf("*   ");
textcolor(WHITE);
cprintf("  6) Would You Like To Search By Name\r\n      7) Would You Like To Exit");
choice=getch();
switch(choice)
{
case '1':
add();
break;
case '2':
del();
break;
case '3':
modi();
break;
case '4':
search_id();
break;
case '5':
list();
break;
case '6':
search_name();
break;
case '7':
textbackground(BLUE);
clrscr();
printf("  **************************************************************************** ");
gotoxy(2,25);
printf(" **************************************************************************** ");
gotoxy(25,10);
printf("THIS IS A CAR WORK SHOP MADE BY\n\t\n\t      1-YOUSIF __________________________________ 2-EZZELDIEN\n\t      3-SADAM  __________________________________ 4-ABD ALLA\n\t\t\t\t5-AHMED SHAKER\n\n\t\tCOPYRIGHT             31/12/2012    11:24");
getch();
exit(0);
default:
{textcolor(225);
cprintf("\r\n******ERROR******\r\n\r\n");
getch();}}
goto main_menu; }


/**********************************************************************/

void add()
{
textbackground(BLACK);
textcolor(WHITE);
clrscr();
FILE *fp;
fp=fopen("project.txt","a");
if(fp==NULL)
{printf("There Is An Error In Opening The File");
getch();     //testing the file
exit(1);}


clrscr();
printf("Enter Customer ID\r\n");
scanf("%d",&cw.id);
fflush(stdin);
printf("\r\nEnter Customer Name\r\n");
scanf("%s",cw.name);
fflush(stdin);
printf("\r\nEnter Customer Phone Number\r\n");
scanf("%s",cw.phone);
fflush(stdin);
printf("\r\nEnter Customer Address\r\n");
scanf("%s",cw.address);
fflush(stdin);
printf("\r\nEnter Customers Car Type\r\n");
scanf("%s",cw.type);
fflush(stdin);
printf("\r\nEnter Customers Car Model\r\n");
scanf("%s",cw.model);
fflush(stdin);
printf("\r\nEnter Customers Car Color\r\n");
scanf("%s",cw.color);
fflush(stdin);
cprintf("\r\nEnter Customers Car Liscense Plate\r\n");
scanf("%s",cw.lis_plate);
fflush(stdin);
cprintf("\r\nEnter Customers Car Price\r\n");
scanf("%s",cw.price);
fflush(stdin);
fwrite(&cw,sizeof(cw),1,fp);
fprintf(fp,"\n");
fclose(fp);
cprintf("\r\nDo You Want To Add Again? Y/N\n");
a=getche();
fflush(stdin);
if(a=='y')
add();  // to continue adding
fclose(fp);
}


/**********************************************************************/

void modi()
{
clrscr();
textbackground(122),textcolor(BLACK);
mod_again:
clrscr();
FILE *fp,*np;
fp=fopen("project.txt","r+");
if(fp==NULL)
{printf("There Is An Error In Opening The File");      //testing the file
exit(1);}



int z;
double size;
rewind(fp);
if(fp)
fseek(fp,0,SEEK_END); //feof(fp)
size=ftell(fp);  //size = size of pointer
if(size==0)
{
gotoxy(36,12);
textcolor(RED+BLINK);
cprintf("No Records");
goto b;} //Test if empty file to print No records if it is



b:
int no,count=0;
if(size==0)
goto a;
cprintf("\nEnter ID No:\n");
scanf("%d",&no);
rewind(fp);
fread(&cw,sizeof(cw),1,fp);
while(!feof(fp))
{
if(no==cw.id)
{count++;
break;} //testing if it exist or not
fscanf(fp,"\n");
fread(&cw,sizeof(cw),1,fp);
} //END OF WHILE
if(count!=0)
new_insert();
no=sizeof(cw);
fseek(fp,-no,SEEK_CUR);
fwrite(&cw,sizeof(cw),1,fp);
if(count==0)
printf("\nThe ID Does Not Exist");
cprintf("\r\nDo You Want To Modify Again? Y/N\r\n");
if(getche()=='y')
goto mod_again;
a:
getch();
fclose(fp);}


/**********************************************************************/

void list()
{
textbackground(WHITE),textcolor(BLACK);
clrscr();
FILE *fp;
fp=fopen("project.txt","a");
fp=fopen("project.txt","r");
if(fp==NULL)
{printf("There Is An Error In Opening The File");      //testing the file
exit(1);}


double size;
rewind(fp);
if(fp)
fseek(fp,0,SEEK_END); //feof(fp)
size=ftell(fp);  //size = size of pointer
if(size==0)
{
gotoxy(36,12);
textcolor(RED+BLINK);
cprintf("No Records");
goto end_list;} //Test if empty file to print No records if it is

rewind(fp);
fread(&cw,sizeof(cw),1,fp);
while(!feof(fp))
{
if((cw.id)>=0&&size!=0)  //Test File the id is a number>0 and the size of pointer is > 0
cprintf("\r\nCustomer   Id.........................................%d",cw.id);
cprintf("\r\nCustomer   Name.......................................%s",cw.name);
cprintf("\r\nCustomer   Phone......................................%s",cw.phone);
cprintf("\r\nCustomer   Address....................................%s",cw.address);
cprintf("\r\nCustomer   Car Type...................................%s",cw.type);
cprintf("\r\nCustomer   Car Car Model..............................%s",cw.model);
cprintf("\r\nCustomer   Car Color..................................%s",cw.color);
cprintf("\r\nCustomer   Car Car Lisence Plate......................%s",cw.lis_plate);
cprintf("\r\nCustomer   Car Price..................................%s SDG",cw.price);
cprintf("\r\n");
fscanf(fp,"\n");
fread(&cw,sizeof(cw),1,fp);
}
end_list:
getch();
fclose(fp);
}


/**********************************************************************/

void search_id()
{
textbackground(WHITE),textcolor(BLACK);
search_again:
clrscr();
FILE *fp;
fp=fopen("project.txt","r");
if(fp==NULL)
{printf("There Is An Error In Opening The File");      //testing the file
exit(1);}



int z;
double size;
rewind(fp);
if(fp)
{fseek(fp,0,SEEK_END); //feof(fp)
size=ftell(fp);  //size = size of pointer
if(size==0)
{
textcolor(RED+BLINK);
cprintf("\r\nNo Records %ld",size);
goto b;}} //Test if empty file to print No records if it is


rewind(fp);
b:
int no,count=0;
if(size==0)
goto a;
cprintf("\nEnter ID No:\n");
scanf("%d",&no);
fread(&cw,sizeof(cw),1,fp);
while(!feof(fp))
{
if((no==cw.id)&&(cw.flag!=1) )
{
count++;
cprintf("\r\nCustomer   Id..............................................%d %d",cw.id,cw.flag);
cprintf("\r\nCustomer   Name............................................%s",cw.name);
cprintf("\r\nCustomer   Phone...........................................%s",cw.phone);
cprintf("\r\nCustomer   Address.........................................%s",cw.address);
cprintf("\r\nCustomer   Car Type........................................%s",cw.type);
cprintf("\r\nCustomer   Car Car Model...................................%s",cw.model);
cprintf("\r\nCustomer   Car Color.......................................%s",cw.color);
cprintf("\r\nCustomer   Car Car Lisence Plate...........................%s",cw.lis_plate);
cprintf("\r\nCustomer   Car Price.......................................%s SDG",cw.price);
break;  }
fscanf(fp,"\n");
fread(&cw,sizeof(cw),1,fp);    }
if(count==0)          //TO TEST IF THE RECORD EXIST OR NOT
printf("The ID Number Does Not Exist");
cprintf("\r\n\r\nDo You Want To Search Again? Y/N");
if(getche()=='y')
goto search_again;
a:
getch();
fclose(fp);
}
/**********************************************************************/

void search_name()

{
textbackground(WHITE),textcolor(BLACK);
search_again:
clrscr();
FILE *fp;
fp=fopen("project.txt","r");
if(fp==NULL)
{printf("There Is An Error In Opening The File");      //testing the file
exit(1);}



int z;
double size;
rewind(fp);
if(fp)
{fseek(fp,0,SEEK_END); //feof(fp)
size=ftell(fp);  //size = size of pointer
if(size==0)
{
textcolor(RED+BLINK);
cprintf("\r\nNo Records %ld",size);
goto b;}} //Test if empty file to print No records if it is


rewind(fp);
b:
char name[30];
int compare,count=0;
if(size==0)
goto a;
cprintf("\nEnter Customer Name (Caps Sensitive):\n");
scanf("%s",name);
fread(&cw,sizeof(cw),1,fp);
while(!feof(fp))
{
compare=strcmp(name,(cw.name));
if((compare==0)&&(cw.flag!=1) )
{
count++;
cprintf("\r\nCustomer   Id..............................................%d %d",cw.id,cw.flag);
cprintf("\r\nCustomer   Name............................................%s",cw.name);
cprintf("\r\nCustomer   Phone...........................................%s",cw.phone);
cprintf("\r\nCustomer   Address.........................................%s",cw.address);
cprintf("\r\nCustomer   Car Type........................................%s",cw.type);
cprintf("\r\nCustomer   Car Car Model...................................%s",cw.model);
cprintf("\r\nCustomer   Car Color.......................................%s",cw.color);
cprintf("\r\nCustomer   Car Car Lisence Plate...........................%s",cw.lis_plate);
cprintf("\r\nCustomer   Car Price.......................................%s SDG",cw.price);
printf("\n\r");
}
fscanf(fp,"\n");
fread(&cw,sizeof(cw),1,fp);    }
if(count==0)          //TO TEST IF THE RECORD EXIST OR NOT
printf("The Customer Name Does Not Exist");
cprintf("\r\n\r\nDo You Want To Search Again? Y/N");
if(getche()=='y')
goto search_again;
a:
getch();
fclose(fp);
}


/**********************************************************************/

void del()
{
fflush(stdin);
textbackground(WHITE),textcolor(BLACK);
delet_again:
clrscr();
FILE *fp,*np;
fp=fopen("project.txt","r");
np=fopen("temp.txt","w");
if(fp==NULL&&np==NULL)
{printf("There Is An Error In Opening The File");      //testing the file
exit(1);}





int z;
double size;
rewind(fp);
if(fp)
{fseek(fp,0,SEEK_END); //feof(fp)
size=ftell(fp);  //size = size of pointer
if(size==0)
{
textcolor(RED+BLINK);
cprintf("No Records %ld",size);
goto a;}} //Test if empty file to print No records if it is


fflush(stdin);
int no;
printf("Enter ID Number To Delete:\n");
fflush(stdin);
scanf("%d",&no);

a:
int count=0;
if(size==0)
{goto c;}

rewind(fp);
fread(&cw,sizeof(cw),1,fp);

while(!feof(fp))
{
if(no==cw.id)
count++;
fscanf(fp,"\n");
fread(&cw,sizeof(cw),1,fp);
}

if(count==0)
{printf("This Record Doesn't Exists");
goto b;}



rewind(fp);
fread(&cw,sizeof(cw),1,fp);
while(!feof(fp))
{
if(no!=cw.id)
fwrite(&cw,sizeof(cw),1,np);
fscanf(fp,"\n");
fread(&cw,sizeof(cw),1,fp);
continue;
}
fclose(fp);
fclose(np);
fp=fopen("project.txt","w");
np=fopen("temp.txt","r+");
rewind(fp);
rewind(np);
fread(&cw,sizeof(cw),1,np);
while(!feof(np))
{
fwrite(&cw,sizeof(cw),1,fp);
fscanf(np,"\n");
fread(&cw,sizeof(cw),1,np);
}
fclose(fp);
fclose(np);
textcolor(BROWN+BLINK);
cprintf("\n\rRecord Deleted!");
b:
c:
remove("temp.txt");
getch();
}

/**********************************************************************/

void new_insert()
{
printf("Choose A Number To Modify The Record\r\n\r\n1- ID\n\r2-Name\n\r3-Phone\n\r4-Address\r\n5-Car Type\r\n6-Car Model\r\n7-Car Color\r\n8-Car Liscence Plate\r\n9-Car Price");
char choice;

choice=getche();
clrscr();
switch(choice)
{
case '1':
{printf("\nEnter New Customer ID\r\n");
scanf("%d",&cw.id);
fflush(stdin);}
break;
case '2':
{printf("\nEnter New Customer Name\r\n");
scanf("%s",&cw.name);
fflush(stdin);}
break;
case '3':
{
printf("\nEnter New Customer Phone Number\r\n");
scanf("%s",cw.phone);
fflush(stdin);}
break;
case '4':
{printf("\nEnter New Customer Address\r\n");
fflush(stdin);
scanf("%s",cw.address);
break;}
case '5':
{printf("Enter New Customer Car Type\r\n");
scanf("%s",cw.type);
fflush(stdin);
break;}
case '6':
{printf("Enter New Customer Car Model\r\n");
scanf("%s",cw.model);
fflush(stdin);
break;}
case '7':
{printf("Enter New Customer Car Color\r\n");
scanf("%s",cw.color);
fflush(stdin);
break;}
case '8':
{printf("Enter New Customer Car Liscence Plate\r\n");
scanf("%s",cw.lis_plate);
fflush(stdin);
break;}
case '9':
{printf("Enter New Customer Car Price\r\n");
scanf("%s",cw.price);
fflush(stdin);
break;}
default:{printf("\r\!!The Choice You Selected Does Not Exist!!\n\r");
getch();
}
}
}




