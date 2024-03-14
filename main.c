#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//Struct named student holds name, id, gender and year that will be used to initialize array.
struct student {
char name[30];
int id;
char gender;
int year;
float gpa;
};
//function to take suitable year input from user, accepts only valid input
int AcceptYear()
{
    int x;
    while(1) {
    printf("Enter year: ");
    fflush(stdin);
    scanf("%d",&x);
    fflush(stdin);
    if(x<=5 && x>0) {
        break;
        return x; }
    else {
        printf("invalid input..\n");
    }

    }
}

float AcceptGPA() {
float g;
while(1) {
printf("Enter GPA: ");
fflush(stdin);
    scanf("%f",&g);
    fflush(stdin);
if(g<=4.0 && g >=0) {
    return g;
    break; }
else
    printf("invalid, gpa must be between 0~4.0\n");
}
}

char AcceptGen() {
char p[10];
while(1) {
printf("Enter gender(m/f): ");
fflush(stdin);
    gets(p);
    fflush(stdin);
if((p[0]=='m' || p[0]=='f') && strlen(p)<2) {
    return p;
    break; }
else
    printf("Enter either 'm' or 'f'..\n");
}
}

////function to take suitable menu selection input from user, accepts only valid input
int menuSelect(int n)
{
    char x[40];
    strcpy(x,"");
    int m=1;
    while(1) {
    printf("\nEnter option: ");
    fflush(stdin);
    gets(x);
    m = x[0] - '0' ;
    if(isdigit(x[0])==1 && m<=n && m>0) {
        break;
        return m; }
    else {
        printf("invalid input..\n");
    }

    }
}
//function to take suitable ID input from user, accepts only valid input
int AcceptID()
{
    int id, nd;
    while(1) {
    printf("Enter ID: ");
    scanf("%d", &id);
    nd = floor(log10(abs(id))) + 1;
    if(nd!=7)
        printf("Invalid input, ID must be 7-digit nember\n");
    else
    {
        return id;
        break;
    } }}
//function that verifies if name is suitable and is only first and last name
int checkname(char nom[])
{
    int t=0, g=0;
    for(int i=0; i<strlen(nom); i++)
    {
        if(isalpha(nom[i])<1 || isalpha(nom[i])>2)
            g++;
        if(nom[i]==' ')
            t++;
    }
    if(t==1 && g==1)
    {
        return 1;
    }
    else
        {
        return 2;
        }

}


int main()
{
    //some Entries
    struct student st[10];
    strcpy(st[0].name, "ahmad mohamad");
    st[0].id=2017802 ;
    st[0].gender='m' ;
    st[0].year=3 ;
    st[0].gpa=3.31 ;

    strcpy(st[1].name, "hossam mostafa");
    st[1].id=1234567 ;
    st[1].gender='m' ;
    st[1].year=4 ;
    st[1].gpa=2.51 ;

    strcpy(st[2].name, "mariam mohamad");
    st[2].id=1899951 ;
    st[2].gender='f' ;
    st[2].year=2 ;
    st[2].gpa=2.71 ;


    char names[30];
   //some variables are for data handling, some are flages.
    int s, test=0, check=0, ids, last=3, brk=0;
    printf("Welcome to student management system!\n");

    //this loop is to keep user in program when he finishes an operation. breaks when user ask to exit
    //and hence program terminates.
    while(1) {
    printf("---------------------------------------");

    //options are selected using switch case
    printf("\n1)Retreieve information\n2)Add Student\n3)Delete student\n4)Update information\n5)Exit\n");
    s= menuSelect(5);
    switch(s) {
case 1://query
    printf("\n--------------Query------------------\n");
    printf("\n1)search by Name\n2)Search by ID\n");
    s=menuSelect(2);
    switch(s) {
    case 1://query by name

        //checking name validity
        while(1) {
        printf("Enter name: ");
        fflush(stdin);
        gets(names);
        test= checkname(names);
        if(test==1)
            break;
        else {
            printf("\nInvalid input, enter first and last name, No special charchters..\n");
        }}

            //when name is valid, this is the operation of retrieving information..
            for(int i=0; i<10; i++) {
                check=0;
                if(strcmp(names,st[i].name)==0)
                {
                    printf("\nName: %s\n", st[i].name);
                    printf("ID: %d\n", st[i].id);
                    printf("year: %d\n", st[i].year);
                    printf("gender: %c\n", st[i].gender);
                    printf("GPA: %1.2f\n", st[i].gpa);
                    check=1;
                    break;
                }
            }//for loop for searching for entry
            if(check==0)
                printf("Not Found.\n");
            break;
    case 2://query by id
        ids= AcceptID();
        for(int i=0; i<10; i++) {
                check=0;
                if(ids==st[i].id)
                {
                    printf("\nName: %s\n", st[i].name);
                    printf("ID: %d\n", st[i].id);
                    printf("year: %d\n", st[i].year);
                    printf("gender: %c\n", st[i].gender);
                    printf("GPA: %1.2f\n", st[i].gpa);
                    check=1;
                    break;
                }
            }//for loop for searching for entry
            if(check==0)
                printf("Not Found.\n");
            break;

        }
    break;//query switch
    case 2://add student/sub of main switch
        printf("\n--------------Add Student----------------\n");
        while(1) {
            printf("Enter name: ");
            fflush(stdin);
            gets(names);
            test =checkname(names);
            if(test==1)
                break;
            else {
                printf("\nInvalid input, enter first and last name, No special charchters..\n"); }}
        strcpy(st[last].name , names);
        st[last].gender= AcceptGen();
        st[last].year= AcceptYear();
        st[last].gpa= AcceptGPA();
        while(1) {
        int ms=0, idch;
        idch= AcceptID();
        for(int i=0; i<10; i++) {
            if(idch==st[i].id)
            {
                ms++;
                break;
            }
        }
        if(ms==0) {
            st[last].id= idch;
            break;
        }
        else
            printf("ID Already Exists\n");
        }

        printf("\nSuccess.\n");
        break;

    case 3: // Delete student(case of main switch)
        printf("\n--------------Delete Student---------------\n");
        printf("\n1)search by Name\n2)Search by ID\n");
    s=menuSelect(2);
    switch(s) {
    case 1://query by name

        while(1) {
        printf("Enter name: ");
        fflush(stdin);
        gets(names);
        test= checkname(names);
        if(test==1)
            break;
        else {
            printf("\nInvalid input, enter only first & last name..\n");
        }}

            for(int i=0; i<10; i++) {
                if(strcmp(names,st[i].name)==0)
                {
                    strcpy(st[i].name, "");
                    st[i].id= 0 ;
                    printf("\nDeleted.\n");
                    check=1;
                    break;
                }
            }//for loop for searching for entry
            if(check==0)
                printf("Not Found.\n");
            break;
    case 2://query by id
        ids= AcceptID();
        for(int i=0; i<10; i++) {
                if(ids==st[i].id)
                {
                    strcpy(st[i].name, "");
                    st[i].id= 0 ;
                    printf("\nDeleted.\n");
                    check=1;
                    break;
                }
            }//for loop for searching for entry
            if(check==9)
                printf("Not Found.\n");
            break;

        }
        break; //break of case3 main.
    case 4: // case 4 main.
        printf("\n-------------Update Information---------------\n");
        printf("\n1)search by Name\n2)Search by ID\n");
    s=menuSelect(2);
    switch(s) {
    case 1://query by name

        while(1) {
        printf("Enter name: ");
        fflush(stdin);
        gets(names);
        test= checkname(names);
        if(test==1)
            break;
        else {
            printf("\nInvalid input, enter only first & last name..\n");
        }}

            check=0;
            for(int i=0; i<10; i++) {


                if(strcmp(names,st[i].name)==0)
                {
                    check=1;
                    printf("Found.\n\n1))update year\n2)update GPA\n");
                    s = menuSelect(3);
                    switch(s) {

                case 1:
                    st[i].year= AcceptYear();
                    printf("\nUpdated.\n");
                    break;
                case 2:
                    printf("Enter GPA: ");
                    st[i].gpa = AcceptGPA();
                    printf("\nUpdated.\n");
                    break;
                    }

                }

            }//for loop for searching for entry
            if(check==0)
                printf("\nNot found.\n");

            break;
    case 2://query by id
        ids= AcceptID();
        check=0;
        for(int i=0; i<10; i++) {

                if(ids==st[i].id)
                {
                    check=1;
                    printf("Found.\n\n1))update year\n2)update GPA\n");
                    s = menuSelect(3);
                    switch(s) {
                case 1:
                    st[i].year= AcceptYear();
                    printf("\nUpdated.\n");
                    break;
                case 2:
                    st[i].gpa= AcceptGPA();
printf("\nUpdated.\n");
                    break;
                    }
                    break;
                }
            }//for loop for searching for entry
            if(check==0)
                printf("\nNot Found.\n");

            break;

        }//switch for update case
        break;
                case 5:
                    brk=1;
                    break;


    break; }//main switch
    if(brk==1) {
        printf("Exiting...\nThank you for using!\n");
        //This causes the program to terminate.
        break; }
    }
    return 0;
}
