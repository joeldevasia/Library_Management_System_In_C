#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

int MainPage();
int Book_info();
int Library();

int a;
char usr[50], pwd[50], Tusr[50], Tpwd[50], t[5] = {'\0'};
int PID, i;
struct User_Profile
{
    char Books_Owned;
    char wishlist;
};

struct Books
{
    int Index;
    char Name[100];
    char Author[50];
    int Owned;
    int wishlist;
} B[100] =
    {
        {1, "To Kill a Mockingbird", "Harper Lee", 0, 0},
        {2, "1984", "George Orwell", 0, 0},
        {3, "Harry Potter and the Philosophers Stone", "J.K. Rowling", 0, 0},
        {4, "The Lord of the Rings", "J.R.R. Tolkien", 0, 0},
        {5, "The Great Gatsby", "F. Scott Fitzgerald", 0, 0},
        {6, "Pride and Prejudice", "Jane Austen", 0, 0},
        {7, "The Diary Of A Young Girl", "Anne Frank", 0, 0},
        {8, "The Book Thief", "Markus Zusak", 0, 0},
        {9, "The Hobbit", "J.R.R. Tolkien", 0, 0},
        {10, "Little Women", "Louisa May Alcott", 0, 0},
        {11, "Fahrenheit 451", "Ray Bradbury", 0, 0},
        {12, "Jane Eyre", "Charlotte Bronte", 0, 0}

};

int Book_Info()
{
    printf("\n:::::::Book details:::::::\n\n");
    printf("  Index No.: %d\n  Name: %s\n  Author: %s\n", B[a - 1].Index, B[a - 1].Name, B[a - 1].Author);
    if (B[a - 1].Owned == 0)
    {
        printf("\n Would you like to Buy this book?[y/n]: ");
        scanf(" %s", t);
        if (strcmp(t, "y") == 0)
        {
            B[a - 1].Owned = 1;
            printf(".\n.\n.\n.\n.\n.\nThe Purchase was Successfull");
            printf("\nThe Book has been added to you ACCOUNT");
            getch();
            system("cls");
            Library();
        }
        else if (strcmp(t, "y") != 0)
        {
            if (B[a - 1].wishlist != 1)
            {
                printf("Would you like to add this book to your wishlist?[y/n]: ");
                scanf(" %s", t);
                if (strcmp(t, "y") == 0)
                {
                    B[a - 1].wishlist = 1;
                    printf("\n.\n.\n.\nThe Book has been added to your Wishlist Successfully.\n");
                }
            }
            else
                printf("\n.\n.\n.\nThis Book is already in your wishlist!!\n");
            printf("Returning back to previous page...");
            getch();
            system("cls");
            Library();
        }
        else
        {
        }
    }
    else
    {
        printf("\nYou already Own this Book\n\n");
        printf("Returning back to previous page...");
        getch();
        system("cls");
        Library();
    }
    return 0;
}
int Profile()
{
Start:
    printf("\nYour Details::::\n\n");
    printf("  PID: %d \n", PID);
    printf("  1-Change Username");
    printf("\n  2-Change Password");
    printf("\n  3-Your Wishlist");
    printf("\n  4-Go Back\n  Choice: ");
    scanf("%d", &a);
    system("cls");
    if (a == 1)
    {
        printf("\n  Enter Current Username: ");
        fgets(Tusr, sizeof(Tusr), stdin);
        fgets(Tusr, sizeof(Tusr), stdin);
        if (strcmp(Tusr, usr) == 0)
        {
            printf("  Enter New Username: ");
            fgets(usr, sizeof(usr), stdin);
            printf("\nUsername Updated Successfully!!!");
        }
        else
        {
            printf("--!!Incorrect Username!!--");
            goto Start;
        }
        getch();
        system("cls");
        goto Start;
    }
    else if (a == 2)
    {
        printf("\n  Enter Current Password: ");
        fgets(Tpwd, sizeof(Tpwd), stdin);
        fgets(Tpwd, sizeof(Tpwd), stdin);
        if (strcmp(Tpwd, pwd) == 0)
        {
            printf("  Enter New Password: ");
            fgets(pwd, sizeof(pwd), stdin);
            printf("\nPassword Updated Successfully!!!");
        }
        else
        {
            printf("--!!Incorrect Password!!--");
            goto Start;
        }
        getch();
        system("cls");
        goto Start;
    }
    else if (a == 3)
    {
        system("cls");
        printf("Books added to wishlist can be seen here\n\n");
        for (i = 0; i < 12; i++)
        {
            a=0;
            if (B[i].wishlist == 1)
            {
                a=1;
                printf("   %d.   %s.   By %s\n\n", B[i].Index, B[i].Name, B[i].Author);
            }
        }
        if(a=0)
        {
            printf("\n\nYou haven't added any book to your Wishlist");
        }
        printf("\n\n  Press any key to go back...  ");
        getch();
        system("cls");
        Profile();
    }
    else if (a == 4)
        MainPage();
    else
    {
        printf("\nERROR 69: Plss Choose The Correct Option\n");
        goto Start;
    }
    return 0;
}

int Library()
{
    struct Books;
Start:
    printf("\n\n All Available Books Are As Follows \n\n\n");
    for (i = 0; i <= 11; i++)
    {
        printf("   %d.   %s.   By %s\n\n", B[i].Index, B[i].Name, B[i].Author);
    }
    printf("\n   0 -- Go Back\n");
    scanf("%d", &a);
    system("cls");
    if (a == 0)
    {
        MainPage();
    }
    else if (a > 0 && a < 13)
    {
        Book_Info();
        getch();
    }
    else
    {
        printf("\nERROR 69: Plss Choose The Correct Option\n");
        goto Start;
    }

    return 0;
}

int MainPage()
{
    printf("\n######Dashboard######\n\n");
Start:
    printf("1-Profile\n2-Library\n3-Exit\n\nChoice: ");
    scanf("%d", &a);
    system("cls");
    if (a == 1)
    {
        Profile();
    }
    else if (a == 2)
        Library();

    else if (a == 3)
        goto Stop;

    else
    {
        printf("\nERROR 69: Plss Choose The Correct Option\n");
        goto Start;
    }

Stop:
    system("cls");
    return 0;
}

int Login()
{
Start:
    printf("\n\n\t\tLogin Page\n");
    printf("Username :  ");
    fgets(Tusr, sizeof(Tusr), stdin);
    fgets(Tusr, sizeof(Tusr), stdin);
    printf("Password :  ");
    fgets(Tpwd, sizeof(Tpwd), stdin);
    if ((strcmp(Tusr, usr) == 0) && (strcmp(Tpwd, pwd) == 0))
    {
        printf("\n###LOGIN SUCCESSFULL###");
        getch();
        system("cls");
        MainPage();
    }
    else
    {
        printf("--!!Incorrect Username/Password!!--");
        getch();
        system("cls");
        goto Start;
    }

    return 0;
}

int Registration()
{
    printf("\t\tRegistration Page\n");
    printf("Enter your PID: ");
    scanf("%d", &PID);
    printf("\nEnter The Username(Less Than 50 characters):");
    fgets(usr, sizeof(usr), stdin);
    fgets(usr, sizeof(usr), stdin);
    printf("\nEnter The Password Of Your Choice(Less Than 20 characters):");
    fgets(pwd, sizeof(pwd), stdin);
    printf("\nYour Username is: %s", usr);
    printf("Your Password is: %s", pwd);
    getch();
    system("cls");
    Login();
    return 0;
}

int main()
{
    FILE *file;
    file = fopen("database.txt", "w");
    printf(" SFIT LIBRARY MANAGEMENT PORTAL\n\n");
Start:
    printf("Type index in front of the Service You Want\n1-Registration\n2-Login\n3-Exit\n\nChoice: ");
    scanf("%d", &a);
    system("cls");
    if (a == 1)
    {
        Registration();
    }

    else if (a == 2)
        Login();

    else if (a == 3)
        goto Stop;

    else
    {
        printf("\nERROR 69: Plss Choose The Correct Option\n");
        goto Start;
    }

Stop:
    return 0;
}
