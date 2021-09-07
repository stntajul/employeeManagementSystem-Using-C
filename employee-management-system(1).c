#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>                  //contains strcmp(),strcpy(),strlen(),etc
#include<ctype.h>                   //contains toupper(), tolower(),etc
#include<dos.h>                     //contains _dos_getdate
#include<time.h>

COORD coord = {0,0};

void gotoxy(int x,int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
int main()
{
    Password();
    getche();
    return 0;
}

void mainmenu()
{
    FILE *fp, *ft, *tt;
    char another, choice;

    struct emp
    {
        char name[40];
        int age;
        float bs;
        char address[100];
        int a,b,c;
        char married[100];
        double salary;
        double present;
        char id[40];
    };
    struct emp e;
    char empname[40];
    char ch;
    int j,i=0,k,cas=0,cnt,dlt=0,bns,mdfy,slry,srch=0;
    char d[40]={"Employee Management System"};
    char galaxy[10000]={"*************************EMPLOYEE RECORD*************************"};

    char mnth[100];

    long int recsize,flag=1;
    int day,month,year;

    fp = fopen("EMP.DAT","rb+");
    if(fp == NULL)
    {
        fp = fopen("EMP.DAT","wb+");
        if(fp == NULL)
        {
            printf("Can't open file");
            exit(1);
        }
    }
    recsize = sizeof(e);

    while(1)
    {
        system("cls");
        gotoxy(6,1);
         for(k=0;k<21;k++)
{
Sleep(40);
if(k%2==0)
printf("_");
else
    printf("^");
}
for(k=0;k<strlen(d);k++)
{
    Sleep(40);
    printf("%c",d[k]);
}
 for(k=0;k<21;k++)
{
Sleep(40);
if(k%2==0)
printf("_");
else
    printf("^");
}
gotoxy(28,3);
printf("1. Add Records");
gotoxy(28,5);
printf("2. Search employee");
gotoxy(28,7);
printf("3. List Records");
gotoxy(28,9);
printf("4. Modify Records");
gotoxy(28,11);
printf("5. Delete Records");
gotoxy(28,13);
printf("6. Calculate  salary");
gotoxy(28,15);
printf("7. Calculate bonus");
gotoxy(28,17);
printf("0. Exit");
printf("\n");
gotoxy(20,19);

t();
gotoxy(20,21);
printf("Enter Your Choice: ");

fflush(stdin); // flush the input buffer
choice  = getche();

switch(choice)
{
case '1':
    system("cls");
    fseek(fp,0,SEEK_END);

    another = 'y';
    while(another == 'y')
{
    printf("\n  Enter Joining Date formate(day month year): ");
    scanf("%d%d%d",&e.a,&e.b,&e.c);
    printf("\n  Enter employee id: ");
    scanf("%s",e.id);
    printf("\n  Enter Name: ");
    scanf("%s",e.name);

    printf("\n  Enter Age: ");
    scanf("%d", &e.age);
    printf("\n  Enter Basic Salary: ");
    scanf("%lf", &e.bs);
    printf("\n  Enter Address: ");
    scanf("%s",e.address);
    printf("\n  Enter Married Status (single/married): ");
    scanf("%s",e.married);

    printf("\n\n\nSuccessfully  added\n\n");

    fwrite(&e,recsize,1,fp);

    printf("\nAdd another record(y/n) ");
    fflush(stdin);
    another = getche();
}
break;

case '2':
    system("cls");
    another = 'y';
    cas=3;
while(another == 'y')
{
    printf("\nEnter id of Employee to search: ");
    scanf("%s",empname);
    cas+=3;
    rewind(fp);
while(fread(&e,recsize,1,fp) == 1)
{
    if(strcmp(e.id,empname) == 0)
{
     gotoxy(0,cas);
    printf("Joining Date");
     gotoxy(15,cas);
     printf("Name");
     gotoxy(25,cas);
     printf("id");
      gotoxy(35,cas);
    printf("Age");
 gotoxy(45,cas);
    printf("Salary");
 gotoxy(60,cas);
    printf("Address");
 gotoxy(75,cas);
    printf("Married Status");

    cas+=2;
    gotoxy(0,cas);
    printf("%d-%d-%d",e.a,e.b,e.c);
     gotoxy(15,cas);
     printf("%s",e.name);
     gotoxy(25,cas);
     printf("%s",e.id);
      gotoxy(35,cas);
    printf("%d",e.age);
 gotoxy(45,cas);
    printf("%0.2lf",e.bs);
 gotoxy(60,cas);
    printf("%s",e.address);
 gotoxy(75,cas);
    printf("%s",e.married);

    srch=1;
    break;
}
if(strcmp(e.id,empname)!=0)
{
    srch=0;
}

}

if(srch==0)
{
    printf("\n\nThe record not found\n");
    cas+=3;

}
srch=0;

printf("\n\ndo u want to search another record (y/n) ? : ");



    another = getche();
    getche();
    cas+=3;
    if(another=='n')
    {
        printf("\n\n\n\n\nenter any key for main menu\n");
        getche();
    }

}
break;


case '3':
    system("cls");
    rewind(fp);
    //gotoxy(5,5);
    for(k=0;k<strlen(galaxy);k++)
    {
        Sleep(40);
        printf("%c",galaxy[k]);
    }
    gotoxy(0,3);
    printf("Joining Date");
     gotoxy(15,3);
     printf("Name");
     gotoxy(25,3);
     printf("id");
      gotoxy(35,3);
    printf("Age");
 gotoxy(45,3);
    printf("Salary");
 gotoxy(60,3);
    printf("Address");
 gotoxy(75,3);
    printf("Married Status");
    cas=3;
while(fread(&e,recsize,1,fp)==1)
{
    cas+=2;
    gotoxy(0,cas);
    printf("%d-%d-%d",e.a,e.b,e.c);
     gotoxy(15,cas);
     printf("%s",e.name);
     gotoxy(25,cas);
     printf("%s",e.id);
      gotoxy(35,cas);
    printf("%d",e.age);
 gotoxy(45,cas);
    printf("%0.2lf",e.bs);
 gotoxy(60,cas);
    printf("%s",e.address);
 gotoxy(75,cas);
    printf("%s",e.married);
}
    printf("\n\n\n\nDo u want to Calculate Salary ?(y/n)\n");
    another=getche();
    getche();
while(another=='y')
{
    double temp=0,d,present;

    printf("\nEnter id of Employee to Calculate Salary: ");
    scanf("%s",empname);

    tt = fopen("Temp2.dat","wb");
    rewind(fp);
    //if(strcmp(e.id,empname) != 0)

while(fread(&e,recsize,1,fp) == 1)
{
    if(strcmp(e.id,empname) == 0){


    printf("\nenter present month\n");
    scanf("%s",mnth);
    cnt=1;

    if(strcmp(mnth,"january")==0 || strcmp(mnth,"January")==0 || strcmp(mnth,"JANUARY")==0){
    printf("\nEnter Present Day:\n");
    scanf("%lf",&present);
    if(present>31 || present<0)
    {
        printf("\ninvalid day\n");
        cnt=1;
        break;
    }

    temp=(e.bs/31);
    printf("\n%s will get %0.2lf taka of this month",e.name,temp*present);
    cnt=1;
     break;
    }
    else if(strcmp(mnth,"february")==0 || strcmp(mnth,"February")==0 || strcmp(mnth,"FEBRUARY")==0){
                printf("\nEnter Present Day:\n");
    scanf("%lf",&present);
    if(present>28 || present<0)
    {
        printf("\ninvalid day\n");
        cnt=1;
        break;
    }

    temp=(e.bs/28);
    printf("\n%s will get %0.2lf taka of this month",e.name,temp*present);
    cnt=1;
     break;
    }

    else if(strcmp(mnth,"march")==0 || strcmp(mnth,"March")==0 || strcmp(mnth,"MARCH")==0){
                printf("\nEnter Present Day:\n");
    scanf("%lf",&present);
    if(present>31 || present<0)
    {
        printf("\ninvalid day\n");
        cnt=1;
        break;
    }

    temp=(e.bs/31);
    printf("\n%s will get %0.2lf taka of this month",e.name,temp*present);
    cnt=1;
     break;
    }
       else if(strcmp(mnth,"april")==0 || strcmp(mnth,"April")==0 || strcmp(mnth,"APRIL")==0){
                printf("\nEnter Present Day:\n");
    scanf("%lf",&present);
    if(present>30 || present<0)
    {
        printf("\ninvalid day\n");
        cnt=1;
        break;
    }

    temp=(e.bs/30);
    printf("\n%s will get %0.2lf taka of this month",e.name,temp*present);
    cnt=1;
     break;
    }
           else if(strcmp(mnth,"may")==0 || strcmp(mnth,"May")==0 || strcmp(mnth,"MAY")==0){
                    printf("\nEnter Present Day:\n");
    scanf("%lf",&present);
    if(present>31 || present<0)
    {
        printf("\ninvalid day\n");
        cnt=1;
        break;
    }

    temp=(e.bs/31);
    printf("\n%s will get %0.2lf taka of this month",e.name,temp*present);
    cnt=1;
     break;
    }

          else if(strcmp(mnth,"june")==0 || strcmp(mnth,"June")==0 || strcmp(mnth,"JUNE")==0){
                    printf("\nEnter Present Day:\n");
    scanf("%lf",&present);
    if(present>30 || present<0)
    {
        printf("\ninvalid day\n");
        cnt=1;
        break;
    }

    temp=(e.bs/30);
    printf("\n%s will get %0.2lf taka of this month",e.name,temp*present);
    cnt=1;
     break;
    }
          else if(strcmp(mnth,"july")==0 || strcmp(mnth,"July")==0 || strcmp(mnth,"JULY")==0){
                    printf("\nEnter Present Day:\n");
    scanf("%lf",&present);
    if(present>31 || present<0)
    {
        printf("\ninvalid day\n");
        cnt=1;
        break;
    }

    temp=(e.bs/31);
    printf("\n%s will get %0.2lf taka of this month",e.name,temp*present);
    cnt=1;
     break;
    }
          else if(strcmp(mnth,"august")==0 || strcmp(mnth,"August")==0 || strcmp(mnth,"AUGUST")==0){
                    printf("\nEnter Present Day:\n");
    scanf("%lf",&present);
    if(present>31 || present<0)
    {
        printf("\ninvalid day\n");
        cnt=1;
        break;
    }

    temp=(e.bs/31);
    printf("\n%s will get %0.2lf taka of this month",e.name,temp*present);
    cnt=1;
     break;
    }
          else if(strcmp(mnth,"september")==0 || strcmp(mnth,"September")==0 || strcmp(mnth,"SEPTEMBER")==0){
                    printf("\nEnter Present Day:\n");
    scanf("%lf",&present);
    if(present>30 || present<0)
    {
        printf("\ninvalid day\n");
        cnt=1;
        break;
    }

    temp=(e.bs/30);
    printf("\n%s will get %0.2lf taka of this month",e.name,temp*present);
    cnt=1;
     break;
    }
          else if(strcmp(mnth,"october")==0 || strcmp(mnth,"October")==0 || strcmp(mnth,"OCTOBER")==0){
                    printf("\nEnter Present Day:\n");
    scanf("%lf",&present);
    if(present>31 || present<0)
    {
        printf("\ninvalid day\n");
        cnt=1;
        break;
    }

    temp=(e.bs/31);
    printf("\n%s will get %0.2lf taka of this month",e.name,temp*present);
    cnt=1;
     break;
    }
          else if(strcmp(mnth,"november")==0 || strcmp(mnth,"November")==0 || strcmp(mnth,"NOVEMBER")==0){
                    printf("\nEnter Present Day:\n");
    scanf("%lf",&present);
    if(present>30 || present<0)
    {
        printf("\ninvalid day\n");
        cnt=1;
        break;
    }

    temp=(e.bs/30);
    printf("\n%s will get %0.2lf taka of this month",e.name,temp*present);
    cnt=1;
     break;
    }
          else if(strcmp(mnth,"december")==0 || strcmp(mnth,"December")==0 || strcmp(mnth,"DECEMBER")==0){
                    printf("\nEnter Present Day:\n");
    scanf("%lf",&present);
    if(present>31 || present<0)
    {
        printf("\ninvalid day\n");
        cnt=1;
        break;
    }

    temp=(e.bs/31);
    printf("\n%s will get %0.2lf taka of this month",e.name,temp*present);
    cnt=1;
     break;
    }
    else
    {
        printf("\ninvalid month\n");
        break;
    }




}
else
{
    cnt=0;
    continue;
}

    }
    if(cnt==0){
    printf("\nIncorrect id....\n");
    }

    fclose(tt);
    printf("\nCalculate Another Employee Salary(y/n)");
    fflush(stdin);
    another = getche();
}

    printf("\n\nPress any key to go Main Menu\n");
    getch();
break;

case '4':
    system("cls");
    another = 'y';
while(another == 'y')
{
    printf("Enter the Employee id to Modify: ");
    scanf("%s", empname);
    rewind(fp);

while(fread(&e,recsize,1,fp)==1)
{
    if(strcmp(e.id,empname) == 0){
            printf("\n\nid found\n\n");

    printf("\n  Enter new id : ");
    scanf("%s",e.id);
     printf("\n  Enter Name : ");
    scanf("%s",e.name);
    printf("\n  Enter Age: ");
    scanf("%d", &e.age);
    printf("\n  Enter Basic Salary: ");
    scanf("%f", &e.bs);
    printf("\n  Enter Address: ");
    scanf("%s",e.address);
    printf("\n  Enter Married Status (single/married): ");
    scanf("%s",e.married);
    fseek(fp,-recsize,SEEK_CUR);
    fwrite(&e,recsize,1,fp);
    printf("\n\n successfully  modified.....\n");
    mdfy=1;
break;

}
else
    mdfy==0;
    }
    if((strcmp(e.id,empname)!=0) && mdfy!=1)
{
    printf("wrong id.....");

    printf("\n\nPRESS ANY KEY FOR MAIN MENU\n");
}


    if(strcmp(e.id,empname) == 0)
    printf("\nModify another record(y/n)");

    fflush(stdin);
    another = getche();
}
break;
case '5':
    system("cls");
    another = 'y';
    dlt=0;
while(another == 'y')
{
    printf("\nEnter id of Employee to Delete: ");
    scanf("%s",empname);
    ft = fopen("Temp.dat","wb");
    rewind(fp);
while(fread(&e,recsize,1,fp) == 1)
{
    if(strcmp(e.id,empname) != 0)
{
    fwrite(&e,recsize,1,ft);
}
if(strcmp(e.id,empname)==0)
{
    printf("\n\n\nThe record is sucessfully deleted\n\n\n");
    dlt=1;
}

}



    fclose(fp);
    fclose(ft);
    remove("EMP.DAT");
    rename("Temp.dat","EMP.DAT");
    fp = fopen("EMP.DAT", "rb+");

if(dlt==0)
{
    printf("\n\n\nThe record not found\n\n\n");

}
dlt=0;
    printf("\nDelete another record(y/n)");
    fflush(stdin);
    another = getche();


}
break;

case '6':
    system("cls");
    another='y';
while(another=='y')
{
    double temp=0,d,present;

    printf("\nEnter id of Employee to Calculate Salary: ");
    scanf("%s",empname);

    tt = fopen("Temp2.dat","wb");
    rewind(fp);
    //if(strcmp(e.id,empname) != 0)

while(fread(&e,recsize,1,fp) == 1)
{
    if(strcmp(e.id,empname) == 0){


    printf("\nenter present month\n");
    scanf("%s",mnth);
    cnt=1;

    if(strcmp(mnth,"january")==0 || strcmp(mnth,"January")==0 || strcmp(mnth,"JANUARY")==0){
    printf("\nEnter Present Day:\n");
    scanf("%lf",&present);
    if(present>31 || present<0)
    {
        printf("\ninvalid day\n");
        cnt=1;
        break;
    }

    temp=(e.bs/31);
    printf("\n%s will get %0.2lf taka of this month",e.name,temp*present);
    cnt=1;
     break;
    }
    else if(strcmp(mnth,"february")==0 || strcmp(mnth,"February")==0 || strcmp(mnth,"FEBRUARY")==0){
                printf("\nEnter Present Day:\n");
    scanf("%lf",&present);
    if(present>28 || present<0)
    {
        printf("\ninvalid day\n");
        cnt=1;
        break;
    }

    temp=(e.bs/28);
    printf("\n%s will get %0.2lf taka of this month",e.name,temp*present);
    cnt=1;
     break;
    }

    else if(strcmp(mnth,"march")==0 || strcmp(mnth,"March")==0 || strcmp(mnth,"MARCH")==0){
                printf("\nEnter Present Day:\n");
    scanf("%lf",&present);
    if(present>31 || present<0)
    {
        printf("\ninvalid day\n");
        cnt=1;
        break;
    }

    temp=(e.bs/31);
    printf("\n%s will get %0.2lf taka of this month",e.name,temp*present);
    cnt=1;
     break;
    }
       else if(strcmp(mnth,"april")==0 || strcmp(mnth,"April")==0 || strcmp(mnth,"APRIL")==0){
                printf("\nEnter Present Day:\n");
    scanf("%lf",&present);
    if(present>30 || present<0)
    {
        printf("\ninvalid day\n");
        cnt=1;
        break;
    }

    temp=(e.bs/30);
    printf("\n%s will get %0.2lf taka of this month",e.name,temp*present);
    cnt=1;
     break;
    }
           else if(strcmp(mnth,"may")==0 || strcmp(mnth,"May")==0 || strcmp(mnth,"MAY")==0){
                    printf("\nEnter Present Day:\n");
    scanf("%lf",&present);
    if(present>31 || present<0)
    {
        printf("\ninvalid day\n");
        cnt=1;
        break;
    }

    temp=(e.bs/31);
    printf("\n%s will get %0.2lf taka of this month",e.name,temp*present);
    cnt=1;
     break;
    }

          else if(strcmp(mnth,"june")==0 || strcmp(mnth,"June")==0 || strcmp(mnth,"JUNE")==0){
                    printf("\nEnter Present Day:\n");
    scanf("%lf",&present);
    if(present>30 || present<0)
    {
        printf("\ninvalid day\n");
        cnt=1;
        break;
    }

    temp=(e.bs/30);
    printf("\n%s will get %0.2lf taka of this month",e.name,temp*present);
    cnt=1;
     break;
    }
          else if(strcmp(mnth,"july")==0 || strcmp(mnth,"July")==0 || strcmp(mnth,"JULY")==0){
                    printf("\nEnter Present Day:\n");
    scanf("%lf",&present);
    if(present>31 || present<0)
    {
        printf("\ninvalid day\n");
        cnt=1;
        break;
    }

    temp=(e.bs/31);
    printf("\n%s will get %0.2lf taka of this month",e.name,temp*present);
    cnt=1;
     break;
    }
          else if(strcmp(mnth,"august")==0 || strcmp(mnth,"August")==0 || strcmp(mnth,"AUGUST")==0){
                    printf("\nEnter Present Day:\n");
    scanf("%lf",&present);
    if(present>31 || present<0)
    {
        printf("\ninvalid day\n");
        cnt=1;
        break;
    }

    temp=(e.bs/31);
    printf("\n%s will get %0.2lf taka of this month",e.name,temp*present);
    cnt=1;
     break;
    }
          else if(strcmp(mnth,"september")==0 || strcmp(mnth,"September")==0 || strcmp(mnth,"SEPTEMBER")==0){
                    printf("\nEnter Present Day:\n");
    scanf("%lf",&present);
    if(present>30 || present<0)
    {
        printf("\ninvalid day\n");
        cnt=1;
        break;
    }

    temp=(e.bs/30);
    printf("\n%s will get %0.2lf taka of this month",e.name,temp*present);
    cnt=1;
     break;
    }
          else if(strcmp(mnth,"october")==0 || strcmp(mnth,"October")==0 || strcmp(mnth,"OCTOBER")==0){
                    printf("\nEnter Present Day:\n");
    scanf("%lf",&present);
    if(present>31 || present<0)
    {
        printf("\ninvalid day\n");
        cnt=1;
        break;
    }

    temp=(e.bs/31);
    printf("\n%s will get %0.2lf taka of this month",e.name,temp*present);
    cnt=1;
     break;
    }
          else if(strcmp(mnth,"november")==0 || strcmp(mnth,"November")==0 || strcmp(mnth,"NOVEMBER")==0){
                    printf("\nEnter Present Day:\n");
    scanf("%lf",&present);
    if(present>30 || present<0)
    {
        printf("\ninvalid day\n");
        cnt=1;
        break;
    }

    temp=(e.bs/30);
    printf("\n%s will get %0.2lf taka of this month",e.name,temp*present);
    cnt=1;
     break;
    }
          else if(strcmp(mnth,"december")==0 || strcmp(mnth,"December")==0 || strcmp(mnth,"DECEMBER")==0){
                    printf("\nEnter Present Day:\n");
    scanf("%lf",&present);
    if(present>31 || present<0)
    {
        printf("\ninvalid day\n");
        cnt=1;
        break;
    }

    temp=(e.bs/31);
    printf("\n%s will get %0.2lf taka of this month",e.name,temp*present);
    cnt=1;
     break;
    }
    else
    {
        printf("\ninvalid month\n");
        break;
    }




}
else
{
    cnt=0;
    continue;
}

    }
    if(cnt==0){
    printf("\nIncorrect id....\n");
    }

    fclose(tt);
    printf("\nCalculate Another Employee Salary(y/n)");
    fflush(stdin);
    another = getche();
}
    printf("\n\n\nPress any key to go Main Menu\n");
    getch();
break;

case '7':
    system("cls");
    another='y';
while(another=='y')
{

    printf("\n\nEnter id of Employee to Calculate bonus: ");
    scanf("%s",empname);

    tt = fopen("Temp2.dat","wb");
    rewind(fp);


while(fread(&e,recsize,1,fp) == 1)
{
    if(strcmp(e.id,empname) == 0){


    printf("\nEnter Present date :\n");
    scanf("%d",&day);
    printf("\nEnter Present month :\n");
    scanf("%d",&month);
    printf("\nEnter Present year :\n");
    scanf("%d",&year);
    if(e.c==year)
    {
        printf("\n%s will not get bonus\n",e.name);
        break;
    }
    else if(year-e.c==1)
    {
        if(month>=e.b)
        {
            if(day>=e.a)
                printf("\n%s will get  =%0.2lf taka as  bonus\n",e.name,e.bs);
                if(day<e.a)
                printf("\n%s will not get bonus\n",e.name);
        }
        if(month<e.b)
        printf("\n%s will not get bonus\n",e.name,e.bs);

    }

    else if(year-e.c>1)
        printf("\n%s will get  =%0.2lf taka as bonus\n",e.name,e.bs);

        else
    {
             printf("\n%s will not get bonus\n",e.name);
    }
        bns=1;
        break;
    }
    else
    {
        bns=0;
        continue;
    }

}

   if(bns==0)
        printf("\nIncorrect employee id\n");
    fclose(tt);
    printf("\nCalculate Another Employee bonus(y/n)\n");
    fflush(stdin);
    another = getche();
}
    printf("\n\n\nPress any key to go Main Menu\n");
    getch();
break;
case '0':
    fclose(fp);
    exit(0);
}
}
}

int t(void) //for time
{
time_t t;
time(&t);
printf("Date and time:%s\n",ctime(&t));

return 0 ;
}
void Password(void)
{
    system("cls");
    int i=0,j;
    char ch;
    char pass[1000];
    char d[40]={"Password Protected"};
    char dd[40]={"Enter Password : "};
    gotoxy(10,2);
    for(j=0;j<30;j++)
{
Sleep(50);
if(j%2==0)
printf("~");
else
    printf("~");
}
for(j=0;j<strlen(d);j++)
{
    Sleep(50);
    printf("%c",d[j]);
}
 for(j=0;j<30;j++)
{
Sleep(50);
if(j%2==0)
printf("~");
else
    printf("~");
}
gotoxy(16,7);
for(j=0;j<strlen(dd);j++)
{
    Sleep(40);
    printf("%c",dd[j]);
}
while(ch!=13)
{
ch=getch();

if(ch!=13 && ch!=8){
putch('*');
pass[i] = ch;
i++;
}
}
pass[i] = '\0';
if(strcmp(pass,"nexus")==0)
{

gotoxy(15,10);
printf("Password match");
gotoxy(15,13);
printf("Press any key to continue.....");
getch();
mainmenu();

}
else
{
gotoxy(15,16);
printf("\a Warning!!! Incorrect Password .............try again.....\n");
getch();
Password();
}
}

