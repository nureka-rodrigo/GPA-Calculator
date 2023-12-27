#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declaring sub-functions
void selection1();
void selection2();
void selection3();
void selection4();
void display1(double GPA, int i, char name[20][50], char grade[20][5], double credit[20][2], double gp[20][10]);
void display2(double GPA, int i, char name[20][50], int marks[20], char grade[20][5], double credit[20][2], double gp[20][10]);
void display3(double extra_credit, double aim_GPA);
void file1(double GPA, int i, char name[20][50], char grade[20][5], double credit[20][2], double gp[20][10]);
void file2(double GPA, int i, char name[20][50], double credit[20][2], double gp[20][10],int marks[20]);
void file3(double extra_credit, double aim_GPA);
void file4();

//main(); function take inputs from the user to make decisions based on the Main Menu
int main()
{
    char op;

    printf("\n\t\t\t\t\t\t\t\t################################################");
    printf("\n\t\t\t\t\t\t\t\t#          WELCOME TO GPU CALCULATOR           #");
    printf("\n\t\t\t\t\t\t\t\t################################################ \n");

    printf("\n\t\t\t\t\t\t\t\tMAIN MENU\n\t\t\t\t\t\t\t\t ______________________________________________");
    printf("\n\t\t\t\t\t\t\t\t| [1] Calculate Current GPA by Grade           |");
    printf("\n\t\t\t\t\t\t\t\t| _____________________________________________|");
    printf("\n\t\t\t\t\t\t\t\t| [2] Calculate Current GPA by Mark            |");
    printf("\n\t\t\t\t\t\t\t\t| _____________________________________________|");
    printf("\n\t\t\t\t\t\t\t\t| [3] Calculate GPA by Goal                    |");
    printf("\n\t\t\t\t\t\t\t\t| _____________________________________________|");
    printf("\n\t\t\t\t\t\t\t\t| [4] View GPA Scale                           |");
    printf("\n\t\t\t\t\t\t\t\t| _____________________________________________|");
    printf("\n\t\t\t\t\t\t\t\t| [0] Exit                                     |\n");
    printf("\t\t\t\t\t\t\t\t________________________________________________\n");

X:
    printf("\n\t\t\t\t\t\t\t\tCHOOSE A NUMBER FROM THE BOX ABOVE: ");
    scanf(" %c", &op);
    for(;;){
        if(isdigit(op)){
            break;
        }
        else{
            printf("\t\t\t\t\t\t\t\tInvalid Selection!!!\n");
            goto X;
            break;
        }
    }
    switch(op)
    {
    case '0':
        printf("\n\t\t\t\t\t\t\t\t################################################");
        printf("\n\t\t\t\t\t\t\t\t#      Thank You for Using GPA CALCULATOR      #");
        printf("\n\t\t\t\t\t\t\t\t################################################ \n");
        exit(0);
        break;
    case '1':
        selection1();
        break;
    case '2':
        selection2();
        break;
    case '3':
        selection3();
        break;
    case '4':
        selection4();
        break;
    default:
        printf("\t\t\t\t\t\t\t\tInvalid Selection!!!\n");
        goto X;
        break;
    }
    return 0;
}

//selection1(); function execute Option 1 from Main Menu and then pass the data to display1(); function
void selection1()
{
    const double A_PLUS=4.0, A=4.0, A_MINUS=3.7, B_PLUS=3.3, B=3.0, B_MINUS=2.7, C_PLUS=2.3, C=2.0, C_MINUS=1.7, D_PLUS=1.3, D=1.0, E=0.0;
    const char dummy[]="=", A1[]="A+", A2[]="A", A3[]="A-", B1[]="B+", B2[]="B", B3[]="B-", C1[]="C+", C2[]="C", C3[]="C-", D1[]="D+", D2[]="D", E1[]="E";
    char name[20][50], grade[20][5], op;
    double credit[20][2], gp[20][10], credit_total=0, gp_total=0, GPA;
    int i=0;

    printf("\n\t\t\t\t\t\t\t\tREMEMBER THAT YOU CAN QUIT ANYTIME BY ENTERING '=' AS SUBJECT NAME OR GRADE...!\n\n");
    for(;;)
    {
        printf("\t\t\t\t\t\t\t\tEnter Subject Name: ");
        scanf("%s", &name[i]);
        if(strcmp(dummy, name[i])==0)
        {
            printf("\n\t\t\t\t\t\t\t\t################################################");
            printf("\n\t\t\t\t\t\t\t\t#      Thank You for Using GPA CALCULATOR      #");
            printf("\n\t\t\t\t\t\t\t\t################################################\n");
            exit(0);
        }
        printf("\t\t\t\t\t\t\t\tEnter Grade: ");
        scanf("%s", &grade[i]);
        if(strcmp(dummy, grade[i])==0)
        {
            printf("\n\t\t\t\t\t\t\t\t################################################");
            printf("\n\t\t\t\t\t\t\t\t#      Thank You for Using GPA CALCULATOR      #");
            printf("\n\t\t\t\t\t\t\t\t################################################\n");
            exit(0);
        }
        printf("\t\t\t\t\t\t\t\tEnter The Course Credits: ");
        scanf("%lf", &*credit[i]);

        if(strcmp(A1, grade[i])==0)
        {
            *gp[i]=A_PLUS**credit[i];
        }
        else if(strcmp(A2, grade[i])==0)
        {
            *gp[i]=A**credit[i];

        }
        else if(strcmp(A3, grade[i])==0)
        {
            *gp[i]=A_MINUS**credit[i];
        }
        else if(strcmp(B1, grade[i])==0)
        {
            *gp[i]=B_PLUS**credit[i];
        }
        else if(strcmp(B2, grade[i])==0)
        {
            *gp[i]=B**credit[i];
        }
        else if(strcmp(B3, grade[i])==0)
        {
            *gp[i]=B_MINUS**credit[i];
        }
        else if(strcmp(C1, grade[i])==0)
        {
            *gp[i]=C_PLUS**credit[i];
        }
        else if(strcmp(C2, grade[i])==0)
        {
            *gp[i]=C**credit[i];
        }
        else if(strcmp(C3, grade[i])==0)
        {
            *gp[i]=C_MINUS**credit[i];
        }
        else if(strcmp(D1, grade[i])==0)
        {
            *gp[i]=D_PLUS**credit[i];
        }
        else if(strcmp(D2, grade[i])==0)
        {
            *gp[i]=D**credit[i];
        }
        else if(strcmp(E1, grade[i])==0)
        {
            *gp[i]=E**credit[i];
        }
        else
        {
            printf("\t\t\t\t\t\t\t\tInvalid Grade!\n\n");
            continue;
        }
        credit_total=credit_total+*credit[i];
        gp_total=gp_total+*gp[i];
        GPA=gp_total/credit_total;
Y:      //To add another subject or to Quit
        printf("\t\t\t\t\t\t\t\tAdd Another Subject?(Y/N): ");
        scanf(" %c", &op);
        if(op=='N' || op=='n')
        {
            break;
        }
        else if(op=='Y' || op=='y')
        {
            goto X;
        }
        else
        {
            printf("\t\t\t\t\t\t\t\tInvalid Key!\n\n");
            goto Y;
        }
X:
        i++;
        printf("\n\t\t\t\t\t\t\t\t################################################\n\n\n");
    }
    //Pass the data to display1(); function
    display1(GPA, i, name, grade, credit, gp);

}

//selection2(); function execute Option 2 from Main Menu and then pass the data to display2(); function
void selection2()
{
    char name[20][50], grade[20][5], op;
    const char dummy[]="=";
    double credit[20][2], gp[20][10], credit_total=0, gp_total=0, GPA;
    int i=0,marks[20];

    printf("\n\t\t\t\t\t\t\t\tREMEMBER THAT YOU CAN QUIT ANYTIME BY ENTERING '=' AS SUBJECT NAME...!\n\n");
    for(;;)
    {
        printf("\t\t\t\t\t\t\t\tEnter Subject Name: ");
        scanf("%s", &name[i]);
        if(strcmp(dummy, name[i])==0)
        {
            printf("\n\t\t\t\t\t\t\t\t################################################");
            printf("\n\t\t\t\t\t\t\t\t#      Thank You for Using GPA CALCULATOR      #");
            printf("\n\t\t\t\t\t\t\t\t################################################\n");
            exit(0);
        }
        printf("\t\t\t\t\t\t\t\tEnter Marks: ");
        scanf("%d", &marks[i]);

        printf("\t\t\t\t\t\t\t\tEnter The Course Credits: ");
        scanf("%lf", &*credit[i]);

        if(marks[i]<=100 && marks[i]>90)
        {
            *gp[i]=4.0**credit[i];
            strcpy(grade[i],"A+");
        }
        else if(marks[i]<=90 && marks[i]>=85)
        {
            *gp[i]=4.0**credit[i];
            strcpy(grade[i],"A");
        }
        else if(marks[i]<85 && marks[i]>=80)
        {
            *gp[i]=3.7**credit[i];
            strcpy(grade[i],"A-");
        }
        else if(marks[i]<80 && marks[i]>=75)
        {
            *gp[i]=3.3**credit[i];
            strcpy(grade[i],"B+");
        }
        else if(marks[i]<75 && marks[i]>=70)
        {
            *gp[i]=3.0**credit[i];
            strcpy(grade[i],"B");
        }
        else if(marks[i]<70 && marks[i]>=65)
        {
            *gp[i]=2.7**credit[i];
            strcpy(grade[i],"B-");
        }
        else if(marks[i]<65 && marks[i]>=60)
        {
            *gp[i]=2.3**credit[i];
            strcpy(grade[i],"C+");
        }
        else if(marks[i]<60 && marks[i]>=55)
        {
            *gp[i]=2.0**credit[i];
            strcpy(grade[i],"C");
        }
        else if(marks[i]<55 && marks[i]>=50)
        {
            *gp[i]=1.7**credit[i];
            strcpy(grade[i],"C-");
        }
        else if(marks[i]<50 && marks[i]>=45)
        {
            *gp[i]=1.3**credit[i];
            strcpy(grade[i],"D+");
        }
        else if(marks[i]<45 && marks[i]>=40)
        {
            *gp[i]=1.0**credit[i];
            strcpy(grade[i],"D");
        }
        else if(marks[i]<40)
        {
            *gp[i]=0.0**credit[i];
            strcpy(grade[i],"E");
        }
        else
        {
            printf("\t\t\t\t\t\t\t\tInvalid Marks!\n\n");
            continue;
        }
        credit_total=credit_total+*credit[i];
        gp_total=gp_total+*gp[i];
        GPA=gp_total/credit_total;
Y:      //To add another subject or to Quit
        printf("\t\t\t\t\t\t\t\tAdd Another Subject?(Y/N): ");
        scanf(" %c", &op);
        if(op=='N' || op=='n')
        {
            break;
        }
        else if(op=='Y' || op=='y')
        {
            goto X;
        }
        else
        {
            printf("\t\t\t\t\t\t\t\tInvalid Key!\n\n");
            goto Y;
        }
X:
        i++;
        printf("\n\t\t\t\t\t\t\t\t################################################\n\n\n");
    }
    //Pass the data to display2(); function
    display2(GPA, i, name, marks, grade, credit, gp);
}

//selection3(); function execute Option 3 from Main Menu and then pass the data to display3(); function
void selection3()
{
    double current_GPA, current_credit, goal_GPA, extra_credit, points, aim_GPA;
    char op;

Y:
    printf("\n\t\t\t\t\t\t\t\tEnter Your Current GPA: ");
    scanf("%lf", &current_GPA);
    //To make sure that the  Current GPA is not exceed 4.00
    if(current_GPA>=4.00)
    {
        printf("\n\t\t\t\t\t\t\t\tGPA Can't Exceed 4.00!\n");
        goto Y;
    }
    printf("\t\t\t\t\t\t\t\tEnter Current Total Credits: ");
    scanf("%lf", &current_credit);
Z:
    printf("\t\t\t\t\t\t\t\tEnter Your Goal GPA: ");
    scanf("%lf", &goal_GPA);
    //To make sure that the  Goal GPA not exceeds 4.00
    if(goal_GPA>=4.00)
    {
        printf("\n\t\t\t\t\t\t\t\tGPA Can't Exceed 4.00!\n\n");
        goto Z;
    }
    //To make sure that the Goal GPA is higher than Current GPA
    if(current_GPA>=goal_GPA)
    {
        printf("\n\t\t\t\t\t\t\t\tGoal GPA Must Be Higher Than Current GPA!\n\n");
        goto Z;
    }
    printf("\t\t\t\t\t\t\t\tEnter Credits Left: ");
    scanf("%lf", &extra_credit);

    points=goal_GPA*(current_credit+extra_credit);
    points=points-(current_GPA*current_credit);
    aim_GPA=points/extra_credit;
    //Pass the data to display3(); function
    display3(extra_credit, aim_GPA);
}

//selection3(); function execute Option 4 from Main Menu and then pass the data to display3(); function
void selection4()
{
    char op;
    int c=0;

    printf("\t\t\t\t\t\t\t===================================================================\n");
    printf("\t\t\t\t\t\t\t    Range of Marks\t\tGrade\t\t    Grade Value\n");
    printf("\t\t\t\t\t\t\t===================================================================\n");
    printf("\t\t\t\t\t\t\t\t 91-100\t\t\t A+\t\t\t4.0\n");
    printf("\t\t\t\t\t\t\t\t 85-90\t\t\t A\t\t\t4.0\n");
    printf("\t\t\t\t\t\t\t\t 80-84\t\t\t A-\t\t\t3.7\n");
    printf("\t\t\t\t\t\t\t\t 75-79\t\t\t B+\t\t\t3.3\n");
    printf("\t\t\t\t\t\t\t\t 70-74\t\t\t B\t\t\t3.0\n");
    printf("\t\t\t\t\t\t\t\t 65-69\t\t\t B-\t\t\t2.7\n");
    printf("\t\t\t\t\t\t\t\t 60-64\t\t\t C+\t\t\t2.3\n");
    printf("\t\t\t\t\t\t\t\t 55-59\t\t\t C\t\t\t2.0\n");
    printf("\t\t\t\t\t\t\t\t 50-54\t\t\t C-\t\t\t1.7\n");
    printf("\t\t\t\t\t\t\t\t 45-49\t\t\t D+\t\t\t1.3\n");
    printf("\t\t\t\t\t\t\t\t 40-44\t\t\t D\t\t\t1.0\n");
    printf("\t\t\t\t\t\t\t\t 0-40\t\t\t E\t\t\t0.0\n");
    printf("\t\t\t\t\t\t\t===================================================================\n");

    file4();

    //To go back to Main Menu or to Quit
    printf("\n\t\t\t\t\t\t\t\tIF YOU WANT TO GO BACK TO MAIN MENU, ENTER 'X'\n");
    printf("\t\t\t\t\t\t\t\tIF YOU WANT TO EXIT, ENTER '='\n");
Z:
    printf("\n\t\t\t\t\t\t\t\t: ");
    scanf(" %c", &op);
    if(op=='X' || op=='x')
    {
        main();
    }
    else if(op=='=')
    {
        exit(0);
    }
    else
    {
        printf("\t\t\t\t\t\t\t\tInvalid Key!");
        goto Z;
    }
}

//display1(); function recieve data from selection1(); and display the relevant result
void display1(double GPA, int i, char name[20][50], char grade[20][5], double credit[20][2], double gp[20][10])
{
    char op;
    int c=0;

    printf("\n\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 GPU CALCULATOR \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\t\t\t\t\t\t=========================================================================================\n");
    printf("\t\t\t\t\t\tSubject\t\t\t Credit\t\t\t Grade\t\t\t GP\n");
    printf("\t\t\t\t\t\t=========================================================================================\n");

    for(c=0; c<=i; c++)
    {
        printf("\t\t\t\t\t\t%-10s\t\t %-12lf\t\t %3s\t %20.2lf\n\n", name[c], *credit[c], grade[c], *gp[c]);
    }
    printf("\t\t\t\t\t\t=========================================================================================\n");
    printf("\n\t\t\t\t\t\t\t\t################################################");
    printf("\n\t\t\t\t\t\t\t\t#            Your GPA Is: %.3lf                #", GPA);
    printf("\n\t\t\t\t\t\t\t\t################################################\n");

    file1(GPA, i, name, grade, credit, gp);

    //To go back to Main Menu or to Quit
    printf("\n\t\t\t\t\t\t\t\tIF YOU WANT TO GO BACK TO MAIN MENU, ENTER 'X'\n");
    printf("\t\t\t\t\t\t\t\tIF YOU WANT TO EXIT, ENTER '='\n");
Z:
    printf("\n\t\t\t\t\t\t\t\t: ");
    scanf(" %c", &op);
    if(op=='X' || op=='x')
    {
        main();
    }
    else if(op=='=')
    {
        exit(0);
    }
    else
    {
        printf("\t\t\t\t\t\t\t\tInvalid Key!");
        goto Z;
    }
}

//display2(); function recieve data from selection2(); and display the relevant result
void display2(double GPA, int i, char name[20][50], int marks[20], char grade[20][5], double credit[20][2], double gp[20][10])
{
    char op;
    int c=0;

    printf("\n\n\t\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 GPU CALCULATOR \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\t\t\t\t\t\t==============================================================================================\n");
    printf("\t\t\t\t\t\tSubject\t\t\t Credit\t\t\t Marks\t\t Grade\t\t\t GP\n");
    printf("\t\t\t\t\t\t==============================================================================================\n");

    for(c=0; c<=i; c++)
    {
        printf("\t\t\t\t\t\t%-10s\t\t %-12lf\t\t  %d\t\t  %3s\t %20.2lf\n\n", name[c], *credit[c], marks[c], grade[c], *gp[c]);
    }
    printf("\t\t\t\t\t\t==============================================================================================\n");
    printf("\n\t\t\t\t\t\t\t\t################################################");
    printf("\n\t\t\t\t\t\t\t\t#            Your GPA Is: %.3lf                #", GPA);
    printf("\n\t\t\t\t\t\t\t\t################################################\n");

    file2(GPA, i, name, credit, gp, marks);

    //To go back to Main Menu or to Quit
    printf("\n\t\t\t\t\t\t\t\tIF YOU WANT TO GO BACK TO MAIN MENU, ENTER 'X'\n");
    printf("\t\t\t\t\t\t\t\tIF YOU WANT TO EXIT, ENTER '='\n");
Z:
    printf("\n\t\t\t\t\t\t\t\t: ");
    scanf(" %c", &op);
    if(op=='X' || op=='x')
    {
        main();
    }
    else if(op=='=')
    {
        exit(0);
    }
    else
    {
        printf("\t\t\t\t\t\t\t\tInvalid Key!");
        goto Z;
    }
}

//display3(); function recieve data from selection3(); and display the relevant result
void display3(double extra_credit, double aim_GPA)
{
    char op, x;

    //If the aim GPA exceeded 4.00
    if(aim_GPA>4.00)
    {
        printf("\t\t\t\t\t\t==============================================================================\n");
        printf("\n\t\t\t\t\t\t\t\t################################################");
        printf("\n\t\t\t\t\t\t\t\t#         This Goal Can't Be Achieved!         #");
        printf("\n\t\t\t\t\t\t\t\t################################################\n");
    }
    else
    {
        printf("\t\t\t\t\t\t==============================================================================\n");
        printf("\n\t\t\t\t\t\t\t\t####################################################");
        printf("\n\t\t\t\t\t\t\t\t# For Your Next %.0lf Credits, Your GPA Must Be %.3lf #", extra_credit, aim_GPA);
        printf("\n\t\t\t\t\t\t\t\t####################################################\n");
    }

    file3(extra_credit, aim_GPA);


    //To go back to Main Menu or to Quit
    printf("\n\t\t\t\t\t\t\t\tIF YOU WANT TO GO BACK TO MAIN MENU, ENTER 'X'\n");
    printf("\t\t\t\t\t\t\t\tIF YOU WANT TO EXIT, ENTER '='\n");
Z:
    printf("\n\t\t\t\t\t\t\t\t: ");
    scanf(" %c", &op);
    if(op=='X' || op=='x')
    {
        main();
    }
    else if(op=='=')
    {
        exit(0);
    }
    else
    {
        printf("\t\t\t\t\t\t\t\tInvalid Key!");
        goto Z;
    }
}

//file1(); function recieve data from selection1(); and print the relevant result in descending order in the file1.txt file
void file1(double GPA, int i, char name[20][50], char grade[20][5], double credit[20][2], double gp[20][10])
{
    FILE *fptr1;
    fptr1 = fopen("file1.txt","w");
    fprintf(fptr1,"\n\n\t\t\t************ GPU CALCULATOR ************\n");
    fprintf(fptr1,"=========================================================================================\n");
    fprintf(fptr1,"Subject\t\t\t Credit\t\t\t Grade\t\t\t GP\n");
    fprintf(fptr1,"=========================================================================================\n");
    char a1[]="A+", a2[]="A", a3[]="A-", b1[]="B+", b2[]="B", b3[]="B-", c1[]="C+", c2[]="C", c3[]="C-", d1[]="D+", d2[]="D", e1[]="E";


    for(int c=0; c<=i; c++)
    {
        if(strcmp(a1, grade[c])==0)
        {
            fprintf(fptr1,"%-10s\t\t %-12lf\t\t %3s\t %20.2lf\n\n", name[c], *credit[c], grade[c], *gp[c]);
        }
        else
            continue;

    }
    for(int c=0; c<=i; c++)
    {
        if(strcmp(a2, grade[c])==0)
        {
            fprintf(fptr1,"%-10s\t\t %-12lf\t\t %3s\t %20.2lf\n\n", name[c], *credit[c], grade[c], *gp[c]);
        }
        else
            continue;

    }
    for(int c=0; c<=i; c++)
    {
        if(strcmp(a3, grade[c])==0)
        {
            fprintf(fptr1,"%-10s\t\t %-12lf\t\t %3s\t %20.2lf\n\n", name[c], *credit[c], grade[c], *gp[c]);
        }
        else
            continue;

    }
    for(int c=0; c<=i; c++)
    {
        if(strcmp(b1, grade[c])==0)
        {
            fprintf(fptr1,"%-10s\t\t %-12lf\t\t %3s\t %20.2lf\n\n", name[c], *credit[c], grade[c], *gp[c]);
        }
        else
            continue;

    }
    for(int c=0; c<=i; c++)
    {
        if(strcmp(b2, grade[c])==0)
        {
            fprintf(fptr1,"%-10s\t\t %-12lf\t\t %3s\t %20.2lf\n\n", name[c], *credit[c], grade[c], *gp[c]);
        }
        else
            continue;

    }
    for(int c=0; c<=i; c++)
    {
        if(strcmp(b3, grade[c])==0)
        {
            fprintf(fptr1,"%-10s\t\t %-12lf\t\t %3s\t %20.2lf\n\n", name[c], *credit[c], grade[c], *gp[c]);
        }
        else
            continue;

    }
    for(int c=0; c<=i; c++)
    {
        if(strcmp(c1, grade[c])==0)
        {
            fprintf(fptr1,"%-10s\t\t %-12lf\t\t %3s\t %20.2lf\n\n", name[c], *credit[c], grade[c], *gp[c]);
        }
        else
            continue;

    }
    for(int c=0; c<=i; c++)
    {
        if(strcmp(c2, grade[c])==0)
        {
            fprintf(fptr1,"%-10s\t\t %-12lf\t\t %3s\t %20.2lf\n\n", name[c], *credit[c], grade[c], *gp[c]);
        }
        else
            continue;

    }
    for(int c=0; c<=i; c++)
    {
        if(strcmp(c3, grade[c])==0)
        {
            fprintf(fptr1,"%-10s\t\t %-12lf\t\t %3s\t %20.2lf\n\n", name[c], *credit[c], grade[c], *gp[c]);
        }
        else
            continue;

    }
    for(int c=0; c<=i; c++)
    {
        if(strcmp(d1, grade[c])==0)
        {
            fprintf(fptr1,"%-10s\t\t %-12lf\t\t %3s\t %20.2lf\n\n", name[c], *credit[c], grade[c], *gp[c]);
        }
        else
            continue;

    }
    for(int c=0; c<=i; c++)
    {
        if(strcmp(d2, grade[c])==0)
        {
            fprintf(fptr1,"%-10s\t\t %-12lf\t\t %3s\t %20.2lf\n\n", name[c], *credit[c], grade[c], *gp[c]);
        }
        else
            continue;

    }
    for(int c=0; c<=i; c++)
    {
        if(strcmp(e1, grade[c])==0)
        {
            fprintf(fptr1,"%-10s\t\t %-12lf\t\t %3s\t %20.2lf\n\n", name[c], *credit[c], grade[c], *gp[c]);
        }
        else
            continue;

    }

    fprintf(fptr1,"=========================================================================================\n");
    fprintf(fptr1,"\n\t\t\t################################################");
    fprintf(fptr1,"\n\t\t\t#            Your GPA Is: %.3lf                #", GPA);
    fprintf(fptr1,"\n\t\t\t################################################\n");
    if(fptr1==NULL)
    {
        printf("\n\t\t\t\t\t\t\t\tCAN'T OPEN THE FILE.\n");
        exit(1);
    }
    else
        printf("\n\t\t\t\t\t\t\t\tTHIS RESULT WAS SUCCESSFULLY SAVED TO A FILE.\n");
    fclose(fptr1);
}

//file2(); function recieve data from selection2(); and print the relevant result in descending order in the file2.txt file
void file2(double GPA, int i, char name[20][50], double credit[20][2], double gp[20][10],int marks[20])
{
    FILE *fptr2;
    fptr2 = fopen("file2.txt","w");
    fprintf(fptr2,"\n\n\t\t\t************ GPU CALCULATOR ************\n");
    fprintf(fptr2,"=========================================================================================\n");
    fprintf(fptr2,"Subject\t\t\t Credit\t\t\t Grade\t\t\t GP\n");
    fprintf(fptr2,"=========================================================================================\n");
    char a1[]="A+", a2[]="A", a3[]="A-", b1[]="B+", b2[]="B", b3[]="B-", c1[]="C+", c2[]="C", c3[]="C-", d1[]="D+", d2[]="D", e1[]="E";

    for(int c=0; c<=i; c++)
    {
        if((marks[c]>=91)&&(100>=marks[c]))
        {
            fprintf(fptr2,"%-10s\t\t %-12lf\t\t %3s\t %20.2lf\n\n", name[c], *credit[c], a1, *gp[c]);
        }
        else
            continue;
    }
    for(int c=0; c<=i; c++)
    {
        if((marks[c]>=85)&&(90>=marks[c]))
        {
            fprintf(fptr2,"%-10s\t\t %-12lf\t\t %3s\t %20.2lf\n\n", name[c], *credit[c], a2, *gp[c]);
        }
        else
            continue;
    }
    for(int c=0; c<=i; c++)
    {
        if((marks[c]>=80)&&(84>=marks[c]))
        {
            fprintf(fptr2,"%-10s\t\t %-12lf\t\t %3s\t %20.2lf\n\n", name[c], *credit[c], a3, *gp[c]);
        }
        else
            continue;
    }
    for(int c=0; c<=i; c++)
    {
        if((marks[c]>=75)&&(79>=marks[c]))
        {
            fprintf(fptr2,"%-10s\t\t %-12lf\t\t %3s\t %20.2lf\n\n", name[c], *credit[c], b1, *gp[c]);
        }
        else
            continue;
    }
    for(int c=0; c<=i; c++)
    {
        if((marks[c]>=70)&&(74>=marks[c]))
        {
            fprintf(fptr2,"%-10s\t\t %-12lf\t\t %3s\t %20.2lf\n\n", name[c], *credit[c], b2, *gp[c]);
        }
        else
            continue;
    }
    for(int c=0; c<=i; c++)
    {
        if((marks[c]>=65)&&(69>=marks[c]))
        {
            fprintf(fptr2,"%-10s\t\t %-12lf\t\t %3s\t %20.2lf\n\n", name[c], *credit[c], b3, *gp[c]);
        }
        else
            continue;
    }
    for(int c=0; c<=i; c++)
    {
        if((marks[c]>=60)&&(64>=marks[c]))
        {
            fprintf(fptr2,"%-10s\t\t %-12lf\t\t %3s\t %20.2lf\n\n", name[c], *credit[c], c1, *gp[c]);
        }
        else
            continue;
    }
    for(int c=0; c<=i; c++)
    {
        if((marks[c]>=55)&&(59>=marks[c]))
        {
            fprintf(fptr2,"%-10s\t\t %-12lf\t\t %3s\t %20.2lf\n\n", name[c], *credit[c], c2, *gp[c]);
        }
        else
            continue;
    }
    for(int c=0; c<=i; c++)
    {
        if((marks[c]>=50)&&(54>=marks[c]))
        {
            fprintf(fptr2,"%-10s\t\t %-12lf\t\t %3s\t %20.2lf\n\n", name[c], *credit[c], c3, *gp[c]);
        }
        else
            continue;
    }
    for(int c=0; c<=i; c++)
    {
        if((marks[c]>=45)&&(49>=marks[c]))
        {
            fprintf(fptr2,"%-10s\t\t %-12lf\t\t %3s\t %20.2lf\n\n", name[c], *credit[c], d1, *gp[c]);
        }
        else
            continue;
    }
    for(int c=0; c<=i; c++)
    {
        if((marks[c]>=40)&&(44>=marks[c]))
        {
            fprintf(fptr2,"%-10s\t\t %-12lf\t\t %3s\t %20.2lf\n\n", name[c], *credit[c], d2, *gp[c]);
        }
        else
            continue;
    }
    for(int c=0; c<=i; c++)
    {
        if((40>marks[c]))
        {
            fprintf(fptr2,"%-10s\t\t %-12lf\t\t %3s\t %20.2lf\n\n", name[c], *credit[c], e1, *gp[c]);
        }
        else
            continue;
    }

    fprintf(fptr2,"=========================================================================================\n");
    fprintf(fptr2,"\n\t\t\t################################################");
    fprintf(fptr2,"\n\t\t\t#            Your GPA Is: %.3lf                #", GPA);
    fprintf(fptr2,"\n\t\t\t################################################\n");
    if(fptr2==NULL)
    {
        printf("\n\t\t\t\t\t\t\t\tCAN'T OPEN THE FILE.\n");
        exit(1);
    }
    else
        printf("\n\t\t\t\t\t\t\t\tTHIS RESULT WAS SUCCESSFULLY SAVED TO A FILE.\n");
    fclose(fptr2);
}

//file3(); function recieve data from selection3(); and print the relevant result in file3.txt file
void file3(double extra_credit, double aim_GPA)
{
    FILE *fptr3;
    fptr3= fopen("file3.txt","w");

    if(aim_GPA>4.00)
    {
        fprintf(fptr3,"\n\t\t\t\t\t\t\t\t################################################");
        fprintf(fptr3,"\n\t\t\t\t\t\t\t\t#         This Goal Can't Be Achieved!         #");
        fprintf(fptr3,"\n\t\t\t\t\t\t\t\t################################################\n");
    }
    else
    {
        fprintf(fptr3,"####################################################");
        fprintf(fptr3,"\n# For Your Next %.0lf Credits, Your GPA Must Be %.3lf #", extra_credit, aim_GPA);
        fprintf(fptr3,"\n####################################################\n");
    }
    if(fptr3==NULL)
    {
        printf("\n\t\t\t\t\t\t\t\tCAN'T OPEN THE FILE.\n");
        exit(1);
    }
    else
        printf("\n\t\t\t\t\t\t\t\tTHIS RESULT WAS SUCCESSFULLY SAVED TO A FILE.\n");
    fclose(fptr3);
}

//file4(); function Print the output of selection4() into file4.txt file
void file4()
{
    FILE *fptr4;
    fptr4= fopen("file4.txt","w");
    fprintf(fptr4,"===================================================\n");
    fprintf(fptr4,"   Range of Marks\tGrade\t    Grade Value\n");
    fprintf(fptr4,"===================================================\n");
    fprintf(fptr4,"\t91-100\t\t A+\t\t4.0\n");
    fprintf(fptr4,"\t85-90\t\t A\t\t4.0\n");
    fprintf(fptr4,"\t80-84\t\t A-\t\t3.7\n");
    fprintf(fptr4,"\t75-79\t\t B+\t\t3.3\n");
    fprintf(fptr4,"\t70-74\t\t B\t\t3.0\n");
    fprintf(fptr4,"\t65-69\t\t B-\t\t2.7\n");
    fprintf(fptr4,"\t60-64\t\t C+\t\t2.3\n");
    fprintf(fptr4,"\t55-59\t\t C\t\t2.0\n");
    fprintf(fptr4,"\t50-54\t\t C-\t\t1.7\n");
    fprintf(fptr4,"\t45-49\t\t D+\t\t1.3\n");
    fprintf(fptr4,"\t40-44\t\t D\t\t1.0\n");
    fprintf(fptr4,"\t0-40\t\t E\t\t0.0\n");
    fprintf(fptr4,"===================================================\n");
    if(fptr4==NULL)
    {
        printf("\n\t\t\t\t\t\t\t\tCAN'T OPEN THE FILE.\n");
        exit(1);
    }
    else
        printf("\n\t\t\t\t\t\t\t\tTHIS RESULT WAS SUCCESSFULLY SAVED TO A FILE.\n");
    fclose(fptr4);
}
