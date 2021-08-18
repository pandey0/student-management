#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
int newuser()
{
    char user[20];
    char pw[20]="";
    char c,i=0;
    
    
    printf("Enter your username: \n");
    scanf("%s",user);
    printf("\n");
    printf("Enter your password: \n");
    while(i<20)
    {
        pw[i]=getch();
        c=pw[i];
        if (c==13)
        {                               
            break;
        }
        else
        {
            printf("*");
            i++;
        }
        
    }
    
    FILE *fp;
    fp = fopen("login.csv","a");
    if(fp == NULL)
    {
        printf("The file couldn't be opened for some reason or doesn't exist");
    }
    // fprintf(fp,"Username,Password\n");
    fflush(stdin);
    fprintf(fp,"%s,%s",user,pw);
    fclose(fp);
    fp = 0;
    printf("\nWELCOME!!!");
return 0;
}
int adminlogin()
{
    int j=0;
    char uid[10];
    char pw1[10];
    char userid[10]="admin123";
    char pass[10]="admin@10";
    char d;
    
    printf("ADMIN LOGIN!\n");
    printf("ENTER YOUR USERNAME: \n");
    scanf("%s",&uid);
    printf("\n");
    printf("ENTER THE PASSWORD: \n");
    while(j<10)
    {
        pw1[j]=getch();
        d=pw1[j];
        if (d==13)
        {                               
            break;
        }
        else
        {
            printf("*");
            j++;
        }
        
    }
    pw1[j]='\0';
	j=0;
	if(strcmp(uid,userid)==0 && strcmp(pw1,pass)==0)
	{
	    printf("\n\nWELCOME!!!");
	}
	else
	{
		printf("\nTHE ENTERED CREDENTIALS WERE WRONG...PLEASE ENTER ONCE AGAIN\n\n");
        adminlogin();
    }
    return 0;
}
int existinguser()
{

    int k = 0;
    char euid[20];
    char pw2[20];
    char e;
    char newline[] = "\n";
    printf("WELCOME CUSTOMER!!!\n");
    printf("ENTER YOUR USERNAME: \n");
    scanf("%s", &euid);
    printf("\n");
    printf("ENTER THE PASSWORD: \n");
    while (k < 20)
    {
        pw2[k] = getch();
        e = pw2[k];
        if (e == 13)
        {
            break;
        }
        else
        {
            printf("*");
            k++;
        }
    }
    pw2[k] = '\0';
    k = 0;
    strcat(pw2, newline);
    FILE *fp = fopen("login.csv", "r");
    char buffer[100];
    int row = 0;
    int column = 0;
    int counter = 0;

    while (fgets(buffer, 100, fp))
    {
        column = 0;
        row++;
        char *value = strtok(buffer, ",");

        if (!strcmp(value, euid))
        {
            counter = counter + 1;
        }
        value = strtok(NULL, ",");

        if (!strcmp(value, pw2))
        {
            counter = counter + 1;
            // printf("%d",counter);
            if (counter == 2)
            {
                printf("\nWELCOME !!!");
            }
        }
    }
    if (counter != 2)
    {
        printf("\nTHE ENTERED CREDENTIALS WERE WRONG...PLEASE ENTER ONCE AGAIN\n\n");
        fclose(fp);
        existinguser();
    }
    fclose(fp);
}
int main()
{
    int x;
    printf("WELCOME TO HOTEL SAGA!!!\n");
    printf("Enter your category:\n");
    printf("1)Admin\n2)New Customer\n3)Existing Customer\n");
    scanf("%d",&x);
    if(x==1)
    {
        adminlogin();
    }
    else if(x==2)
    {
        newuser();
    }
    else if(x==3)
    {
        existinguser();
    }
}