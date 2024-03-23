
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

//All arrays as global variables
//6 elements //1000 as maximum string size
char suspects[6][1000] = {"Colonel Mustard", "Miss Scarlett", "Mrs. Peacock", "Dr. Orchid", "Professor Plum", "Reverend Green"};
char weapons[6][1000] = {"Candlestick", "Dagger", "Lead Pipe", "Revolver", "Rope", "Wrench"};
char rooms[6][1000] = {"Ballroom", "Conservatory", "Hall", "Kitchen", "Library", "Study"};

char comp1[5][1000] = {};
char comp2[5][1000] = {};
char user[5][1000] = {};

//All answers as global variables
char murderer[1000] = "";
char murderweapon[1000] = "";
char crimescene[1000] = "";

//For loops
int i = 0;
int j = 0;
int r1, r2, r3, ch1, ch2, ch3;
int choice = -1;

int level = -1;

//boolean variables
bool userwon = false;
bool comp1won = false;
bool comp2won = false;

bool gameOver = false;

char shuffledArray[15][1000] = {};

int guesses = 0;

int main()
{
    //To ensure we get random numbers each time
    srand ( time(NULL) );
    //Intro to the game
    printf("\n\n??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????\n\n");
    printf("---------------------------------------------------WELCOME TO CLUEDO---------------------------------------------------------\n\n");
    printf("??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????\n\n");
    showInstructions();
    
    //Declare and initialize choice
    int choice = 5;
    
    //Show the menu to get user choice
    //Keep looping until user enters correct data4
    
    int numberRead = 0;
    
    while (choice != 1 && choice != 2 && choice !=3)
    {
        
        printf("\n\nMake a selection:\n");
        printf("1 - Show Instructions\n");
        printf("2 - Play the game\n");
        printf("3 - Exit the game\n");
        
        choice = -1;
        printf("Your choice: ");
        numberRead = scanf("%d", &choice);
        
        while (numberRead != 1)
        {
            printf("\nThat was not a number!");
            scanf("%*[^\n]");
            printf("Your choice: ");
            numberRead = scanf("%d", &choice);
            if (numberRead == 1){
                break;
            }
        }
    
        if (choice == 1)
        {
            gameInstructions();
            choice = -1;
        }
        
        else if (choice == 2)
        {
            numberRead = 0;
            printf("\n\nChoose a difficulty level: \n1.) Easy \n2.) Difficult\nYour choice: ");
            
            numberRead = scanf("%d", &level);
            
            while (numberRead != 1)
            {
                printf("That was not a number! ");
                scanf("%*[^\n]");
                printf("Your choice: ");
                numberRead = scanf("%d", &level);
            }
            
            while(level !=1 && level!=2)
            {
                printf("\nPlease enter 1 or 2!\n");
                scanf("%*[^\n]");
                printf("Your choice: ");
                numberRead = scanf("%d", &level);
            }
            
            getCaseFile(); //Solutions variables stored, and distribution array made, shuffled as well
            printf("\n\n-?-?-?-?-?-?-?-?-?-?-?-?-?-?-?-?-?-?-?-?-?-?-?-?-?-?-?-?-?-?-?-?-?-?-?-?-?-?-?-?-?-?-?-?-?-?-?-?-?-?-\n");
            printf("Mr. Blackwell craves justice! All the best!\n");
            assignCards(); 
            printf("You go first!\n");
            
            while (gameOver != true)
            {
                userTurn();
                if (userwon != true)
                {
                    guesses = guesses +1;
                    comp1Turn();
                }
                else
                {
                    printf("\n");
                    gameOver = true;
                    choice = -1;
                }
                
                if (userwon != true && comp1won != true)
                {
                    comp2Turn();
                }
                else
                {
                    printf("\n");
                    gameOver = true;
                    choice = -1;
                }
                
                if(comp2won !=true)
                {
                    
                }
                else
                {
                    gameOver = true;
                }
            }
            
            userwon = false;
            comp1won = false;
            comp2won = false;
            
            gameOver = false;
            
        }
        
        else if (choice == 3)
        {
            exit(0);
        }
        
        else
        {
            printf("Please enter 1, 2 or 3!");
        }
        
    }
    
    return 0;
}

void showAllCards()
{
    printf("The suspects are: \n");
    for (i = 0; i<6; i++)
    {
        printf("%d.) %s\n", i+1, suspects[i]);
    }
    
    printf("\nThe possible murder weapons are: \n");
    for (i = 0; i<6; i++)
    {
        printf("%d.) %s\n", i+1, weapons[i]);
    }
    
    printf("\nThe possible crime scenes are: \n");
    for (i = 0; i<6; i++)
    {
        printf("%d.) %s\n", i+1, rooms[i]);
    }
}

int showMenu()
{
    
    int numberRead = 0;
    
    printf("\n\nMake a selection:\n");
    printf("1 - Show Instructions\n");
    printf("2 - Play the game\n");
    printf("3 - Exit the game\n");
    
    choice = -1;
    printf("Your choice: ");
    numberRead = scanf("%d ", &choice);
    
    while (numberRead != 1)
    {
        printf("\nThat was not a number!");
        scanf("%*[^\n]");
        printf("Your choice: ");
        numberRead = scanf("%d", &choice);
    }
    
    return choice;
}

void showInstructions()
{
    printf("\n\nA murder has taken place in Abbotsford - and you must help solve the crime!\n");
    printf("You are playing against 2 bots, whoever finds the murderer, the weapon and the crimescene first wins!\n");
    printf("Here is what we know:\n\n");
    printf("The suspects are: \n");
    showAllCards();
}

void gameInstructions()
{
    printf("\n\nA murder has taken place in Abbotsford - and you must help solve the crime!\n");
    printf("You are playing against 2 bots, whoever finds the murderer, the weapon and the crimescene first wins!\n");
    printf("Here is what we know:\n\n");
    printf("The suspects are: \n");
    for (i = 0; i<6; i++)
    {
        printf("%d.) %s\n", i+1, suspects[i]);
    }
    
    printf("\nThe possible murder weapons are: \n");
    for (i = 0; i<6; i++)
    {
        printf("%d.) %s\n", i+1, weapons[i]);
    }
    
    printf("\nThe possible crime scenes are: \n");
    for (i = 0; i<6; i++)
    {
        printf("%d.) %s\n", i+1, rooms[i]);
    }
    
    printf("\n\n-------------------------------------------- EXTRA INSTRUCTIONS ---------------------------------------------\n\n");
    printf("\n\nThe game goes like this: A case file is made from the suspected items or people.\n");
    printf("The case file has three things: \nthe actual murderer, the actual crimescene and the actual murderweapons.\n");
    printf("The case file is put aside and the remaining cards are equally distributed among the players, \ni.e., the user, the Bot1 and the Bot2.\n");
    printf("Now you know the cards you have - are not associated with the crime \n(because they arent in the case file!)\n");
    printf("You have to make 3 guesses based on your understanding \nfor the murderer, the crimescene and the murderweapon.\n");
    printf("If your guess was incorrect the bot1 and bot2 play next.\n");
    printf("The guesses made by the bots are also shown on the screen to help your understanding.\n");
    printf("\n\n");
    printf("--------------------------------------------------- NOTE: ----------------------------------------------------------\nLevel 1 (Easy) gives you hints if you get anyone of the guesses correct\n");
    printf("Level 2 (Difficult) does not show any hint even if any 1 or 2 of your guesses were correct!\n");
    printf("If you win the game, your total number of guesses are displayed on the screen\n");
    
    printf("\n--------------------------------------------------- HINT ----------------------------------------------------------\n");
    printf("The bots aren't smart - they tend to ignore their cards and use them for guesses anyway\n");
    printf("If a bot's guess is incorrect it is because it wholly is - individual cards guessed by them could be with them too!\n");
}

void getCaseFile()
{
    r1 = rand() % 6;
    strcpy(murderer, suspects[r1]);
    
    r2 = rand() % 6;
    strcpy(murderweapon, weapons[r2]);
    
    r3 = rand() % 6;
    strcpy(crimescene, rooms[r3]);
    int i =0, j = 0;
    
    while(i < 6 && j<5)
    {
        if (i != r1)
        {
            strcpy(shuffledArray[j], suspects[i]);
            j++;
        }
        i++;
    }
    
    i = 0;
    while (i <6 && j <10)
    {
        if (i != r2)
        {
            strcpy(shuffledArray[j], weapons[i]);
            j++;
        }
        i++;
    }
    
    i = 0;
    while (i < 6 && j< 15)
    {
        if (i != r3)
        {
            strcpy(shuffledArray[j], rooms[i]);
            j++;
        }
        i++;
    }
    
    //Shuffling array:
    int size = 15;
    
    for (i = 0; i < size - 1; i++)
    {
    //Pick a random index (j) to swap it with
    //okay to pick same value as i
    int j = rand() % 14; //random between 0 and 15
    char temp[1000] = "";
    strcpy(temp, shuffledArray[j]);
    strcpy(shuffledArray[j], shuffledArray[i]);
    strcpy(shuffledArray[i], temp);
    }
    
    printf("\n");
}

void assignCards()
{
    for (i = 0; i<5; i++)
    {
        strcpy(comp1[i], shuffledArray[i]);
    }
    
    for (i = 0; i<5; i++)
    {
        strcpy(comp2[i], shuffledArray[i+5]);
    }
    
    for (i = 0; i<5; i++)
    {
        strcpy(user[i], shuffledArray[i+10]);
    }
    
    printf("\n\nThe cards have been distributed!\n");
    printf("Your cards are as follows:\n");
    for (i = 0; i<5; i++)
    {
        printf("%d.) %s\n", i+1, user[i]);
    }
    
}

void showSuspects()
{
    for (i = 0; i<6; i++)
    {
        printf("%d.) %s\n", i+1, suspects[i]);
    }
}

void showWeapons()
{
    for (i = 0; i<6; i++)
    {
        printf("%d.) %s\n", i+1, weapons[i]);
    }
}

void showRooms()
{
    for (i = 0; i<6; i++)
    {
        printf("%d.) %s\n", i+1, rooms[i]);
    }
}

void userTurn()
{
    int ch1;
    int ch2;
    int ch3;
    
    int numberRead = 0;
    
    printf("\n\nGuess the murderer:\n");
    showSuspects();
    //printf("%s", murderer);
    
    printf("Enter number: ");
    numberRead = scanf("%d", &ch1);
   
    while (numberRead != 1)
    {
        numberRead = scanf("%d", &ch1);
        
        printf("\nPlease enter a number!\n");
        scanf("%*[^\n]");
        printf("Your choice: ");
        numberRead = scanf("%d", &ch1);
    }
    
    
    printf("\n\nGuess the murder weapon:\n");
    showWeapons();
    //printf("%s", murderweapon);
    
    printf("Enter number: ");
    numberRead = scanf("%d", &ch2);
   
    while (numberRead != 1)
    {
        numberRead = scanf("%d", &ch2);
        
        printf("\nPlease enter a number!\n");
        scanf("%*[^\n]");
        printf("Your choice: ");
        numberRead = scanf("%d", &ch2);
    }
    
    
    printf("\n\nGuess the crime scene:\n");
    showRooms();
    //printf("%s", crimescene);
    
    printf("Enter number: ");
    numberRead = scanf("%d", &ch3);
   
    while (numberRead != 1)
    {
        numberRead = scanf("%d", &ch3);
        
        printf("\nPlease enter a number!\n");
        scanf("%*[^\n]");
        printf("Your choice: ");
        numberRead = scanf("%d", &ch3);
    }
    
    
    if (strcmp(suspects[ch1-1],murderer) ==0 && strcmp(weapons[ch2-1], murderweapon) ==0 && strcmp(rooms[ch3-1],crimescene) == 0)
    {
        userwon = true;
        printf("\n\n--------------------------CONGRATS! YOU GOT IT RIGHT!-------------------------------\n\n");
        printf("YOU HAVE SOLVED THE CASE! Now we must go arrest %s for their crime!\n", suspects[ch1-1]);
        printf("You made a total of %d guesses before you sloved the crime!\n\n", guesses);
        printf("See you next time detective!"); 
    }
    
    else
    {
        printf("\nWrong guess! BOT 1 plays next -- wait for your turn, if there is any!\n");
        
        if (level ==1)
        {
            if (strcmp(suspects[ch1-1],murderer) ==0)
            {
                printf("\nBut here are a few clues:--\n");
                printf("Your murderer guess was correct!\n"); 
            }
            
            if (strcmp(weapons[ch2-1], murderweapon) ==0)
            {
                printf("\nBut here are a few clues:--\n");
                printf("Your murderweapon guess was correct!\n"); 
            }
            
            if (strcmp(rooms[ch3-1],crimescene) ==0)
            {
                printf("\nBut here are a few clues:--\n");
                printf("Your crimescene guess was correct!\n"); 
            }
            
            printf("\n\n");
        }
        
    }
}

void comp1Turn()
{
    ch1 = rand() % 6;
    ch2 = rand() % 6;
    ch3 = rand() % 6;
    
    if (strcmp(suspects[ch1],murderer)==0 && strcmp(weapons[ch2], murderweapon) ==0 && strcmp(rooms[ch3],crimescene) == 0)
    {
        comp1won = true;
        printf("\n\n---------------------OH NO! Seems like BOT 1 cracked the case--------------------------\n\n");
        printf("The crime was committed by %s using %s in the %s\n", murderer, murderweapon, crimescene);
        printf("See you next time detective!\n"); 
    }
    
    else
    {
        printf("According to BOT1: The crime was committed by %s using %s in the %s\n", suspects[ch1], weapons[ch2], rooms[ch3]);
        printf("Seems like the guess was wrong\n");
        printf("BOT 1 couldn't solve the case either! BOT2 goes next!\n\n");
    }

}

void comp2Turn()
{
    ch1 = rand() % 6;
    ch2 = rand() % 6;
    ch3 = rand() % 6;
    
    if (strcmp(suspects[ch1],murderer)==0 && strcmp(weapons[ch2], murderweapon) ==0 && strcmp(rooms[ch3],crimescene) == 0)
    {
        comp1won = true;
        printf("\n\n---------------------OH NO! Seems like BOT 2 cracked the case--------------------------\n\n");
        printf("The crime was committed by %s using %s in the %s\n", murderer, murderweapon, crimescene);
        printf("See you next time detective!\n"); 
    }
    
    else
    {
        printf("According to BOT2: The crime was committed by %s using %s in the %s\n", suspects[ch1], weapons[ch2], rooms[ch3]);
        printf("Seems like the guess was wrong\n");
        printf("BOT 2 couldn't solve the case either! You go next again!\n\n");
    }
}

