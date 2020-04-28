#include <stdio.h>
#include <stdlib.h>
#include <string.h> //include to use strnlen function

void railFence(char *message, char *cipherText, int length, int A); //function prototype given in project brief
void railFence2(char *message, char *cipherText, int length, int A, int B, int dir); //function prototype given in project brief

int main()
{
    /* This section of code is for the selection menu */

    int selection = 0;  //initially set to an invalid option

    while(selection != 1 && selection != 2 && selection != 3 && selection != 4 && selection != 5 && selection != 6)  {
        printf("Select from the following options:\n\n");
        printf("1) Classic rail-fence cipher encryption.\n");
        printf("2) 2-Level rail-fence cipher encryption.\n");
        printf("3) 2-Level rail-fence cipher decryption.\n");
        printf("4) Substitution cipher decryption.\n");
        printf("5) Unseen text substitution cipher decryption.\n");
        printf("6) Close program.\n\n");
        scanf("%d", &selection);    //stores the choice in variable selection
        if(selection != 1 && selection != 2 && selection != 3 && selection != 4 && selection != 5 && selection != 6) {
            printf("\nInvalid selection. Please try again.\n\n");
        }
    }

    /* This section of code uses switch cases to decide between various coding fuctions */

    switch(selection)   {   //uses the value of selection to decide what program to run
        case 1: //This section of code is for selection: 1 = classic rail fence cypher encryption
            printf("\nYou have selected: 1) Classic rail-fence cipher encryption.\n\n");
            int A = 0;
            while(A != 2 && A != 3 && A != 4 && A != 5 && A != 6)    {
                printf("Please enter a whole integer between 2 and 6 to use as the key: ");
                scanf("%d", &A);
            }
            char message[1024];    //declare an array called message to hold text
            char cipherText[1024];
            int length;
            int i = 0;
            char c;
            printf("\nPlease type a line of text to be encrypted, use ~ to indicate end of message:\n\n");
            for(i = 0; i < 1024; i++)    {
                scanf("%c", &c);
                if(c == 126)    //will stop when reads ascii value of ~
                    break;
                else
                    message[i] = c; //else it will continue looping and reading chars to message[]
                }
            length = strlen(message);
            printf("\nYour message: %s\n\n", message);  //prints message entered by user
            railFence(message, cipherText, length, A);
            printf("\n\nYour encrypted message: \n%s\n\n", cipherText);
            break;

        case 2: // This section of code is for selection: 2 = 2 level rail fence cypher encryption
            printf("\nYou have selected: 2) 2-Level rail-fence cipher encryption.\n\n");
            break;

        case 3: //This section of code is for selection: 3 = 2 level rail fence cypher decrpytion
            printf("\nYou have selected: 3) 2-Level rail-fence cipher decryption.\n\n");
            break;

        case 4: // This section of code is for selection: 4 = substitution cypher decrpytion
            printf("\nYou have selected: 4) Substitution cipher decryption.\n\n");
            break;

        case 5: // This section of code is for selection: 5 = unseen text substitution cypher
            printf("\nYou have selected: 5) Unseen text substitution cipher decryption.\n\n");
            break;

        case 6: // This section of code is for selection: 6 = close program
            printf("\nYou have selected: 6) Close program.\n");
            printf("Press any key to close program.\n");    //Pressing any key will close the terminal
            break;

        default:        //if no valid selection is made the default will display an error message
            printf("\nERROR\nYour selection: %d is not valid.\n", selection);
            return 0;
    }
    return 0;
}
    /*this section is below main*/
    void railFence(char *message, char *cipherText, int length, int A)  {   //function definition given in project brief
        int i = 0;
        int j = 0;
        /* this section of code is just initialising all the variables to an _ */
        char grid[A][length];
        while(i < A) {
            while(j < length)   {
                grid[i][j] = '_';
                printf("%c ", grid[i][j]);
                j++;
                }
                printf("\n");
                i++;
                j = 0;
            }
        /* this section of code writes message onto the grid*/
        i = 0;
        j = 0;
        int m = 1;  //start at 1 not zero because message starts with new line due to scanf issues
        int count = 1;  //count starts at 1 as there were problems when it started at 0
        while(j < length - 1)   {   //wont print the terminating /0, just the message
            for(count = 1; count <= A; count++){
               grid[i][j] = message[m];
               m++;
               j++;
               if(j == length - 1)  //will break here if end of message reached
                break;
               if(count == A && j < length - 1) {   //if we are at bottom of rail and not at end of message, we will now move up the rails
                    while(count != 1)  {
                        i--;    //need to decrease i before printing the next message character
                        grid[i][j] = message[m];
                        m++;
                        j++;
                        count--;    //count decreases as we are moving up rails instead of down now
                        if(j == length - 1) //will break if at end of message
                            break;
                    }
               }
               i++; //need to increase i before printing next message charcter
            }
            }
        printf("\n\n"); //news lines to keep it easy to read on output
        /* this section will print the entire grid with the message, using same code form above*/
        i = 0;
        j = 0;
        while(i < A) {
            while(j < length - 1)   {
                printf("%c ", grid[i][j]);
                j++;
                }
                printf("\n");
                i++;
                j = 0;
            }
    /*this section uses a loop that run across each rail, and if the charcter is anything other than a _ it will print to cipherText[m] then increase m, once at end of row it moves down to next rail and so on */
    m = 0;
    i = 0;
    j = 0;
    while(i < A)   {
        while(j < length - 1)   {
            if(grid[i][j] != '_'){
                cipherText[m] = grid[i][j];
                m++;
            }
            j++;
        }
        i++;
        j = 0;
    }
}

    void railFence2(char *message, char *cipherText, int length, int A, int B, int dir) {

}
