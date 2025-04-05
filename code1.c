#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

void clear_input_buffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int menu (double *choice){
    int validation, flag;
    double int_part;
    char next_char;

    
    printf("\nPlease type a number from the list below:\n\
            1. Find the maximum of a list of numbers\n\
            2. Print a Pyramid of base n and height h\n\
            3. Select a number n to find the sum from 1 to n\n\
            4. Find the Factorial of a selected number n\n\
            5. Find the number of vowels and consonants in a string entered by the user\n\
            6. Find out if a string entered is a palindrome or not\n\
            7. Exit\n\n");
    
    printf("--> Select your choice and press 'Enter': ");
    validation =  scanf("%lf%c", choice, &next_char);
    if(validation != 2 || *choice > 7 || *choice < 1 || modf(*choice, &int_part) != 0.0 || (!isspace(next_char))){
        printf("\n\nYou Entered an invalid choice. Press Enter to go back to menu\n\n");
        //fflush(stdin);  ==> removing this as it's not standard in C, meaning it works in some systems but not others. Avoid it to make code portable
        if(next_char != '\n')
        while(getchar() != '\n');
        clear_input_buffer();
        return 0;
    }
    return 1;  
}




void sorting (){
    double *arr = NULL;
    double num, int_part, temp;
    int size = 0, i, j,validation;

    while(1){
        printf("Input a number (or 0 to stop): ");
        validation = scanf("%lf", &num);
        if(validation != 1 || num > 21000){
            printf("\nYou Entered an invalid choice. Try again\n\n");
            //fflush(stdin);
            clear_input_buffer();
            continue;
        }
        if(num == 0){
            //fflush(stdin);
            clear_input_buffer();
            break;
        }
        //fflush(stdin);
        clear_input_buffer();
        size ++;
        arr = (double*)realloc(arr, size * sizeof(double));
        arr[size-1] = num;
    }
    printf("\nThe list of numbers entered: ");
    for(i = 0; i < size; i++){
        if(modf(arr[i], &int_part) != 0.0){
            printf("%.1f ", arr[i]);
        }
        else{
            printf("%d ", (int)arr[i]);
        }
    }
    printf("\n");
    printf("and here is the sorted list of numbers: ");
    for(j = size-1; j > 0; j--){
        for(i = 0; i < j; i++){
            if(arr[i] > arr[i+1]){
                temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
            }
            continue;
        }
    }

    for(i = 0; i < size; i++){
        if(modf(arr[i], &int_part) != 0.0){
            printf("%.1f ", arr[i]);
            if(i < size-1)
            printf(">= ");

        }
        else{
            printf("%d ", (int)arr[i]);
            if(i < size-1)
            printf(">= ");
        }
    }

    printf("\n");
    free(arr);

    printf("\n\nPress Enter to go back to menu\n\n");
    while(getchar() != '\n');

}


void pyramid(){

    int i, j, k, validation;
    double n, int_part;

    printf("\nEnter half the base of the Pyramid: ");
    validation = scanf("%lf", &n);
    while(1){
        if(modf(n, &int_part) != 0.0 || validation != 1 || n > 97){
            printf("\nThe number you entered is not valid.\nEnter a valid integer: ");
            clear_input_buffer();
            validation = scanf("%lf", &n);   
            continue;
        }
        break;
    }

    //method 1 - I don't remember if it was me or AI
    /*for(j=1; j<= n; j++){
        printf("\n");
        k = n-j;
        while(k>0){
            printf(" ");
            k--;
        }
        for(i = j; i > 0; i--){
            printf("**");
        }
        
    }*/

    //method 2 - I built this one
    for(i=1; i<=n; i++){
        printf("\n");
        for(j=0; j<n-i; j++){
            printf(" ");
        }
        for(k=0; k<i; k++){
            printf("**");
        }
    }

    printf("\n");
    printf("\n\nPress Enter to go back to menu\n\n");
    while(getchar() != '\n');

    clear_input_buffer();
  
}


void pushups() {
    int validation, n, sum;
    double int_part;

    printf("\nEnter the number of pushups you want to start the dropset from: ");
    validation = scanf("%d", &n);
    while(1){
        if(modf((double)n, &int_part) != 0.0 || validation != 1 || n < 0 || n > 21000){
            printf("\nThe number you entered is not valid.\nEnter a valid integer: ");
            // fflush(stdin);
            clear_input_buffer();
            validation = scanf("%d", &n);   
            continue;
        }
        break;
    }

    sum = (n * (n+1))/2;
    printf("\nThe sum of pushups you'll achieve by starting a dropset from %d is: %d pushups\n", n, sum);
    
    printf("\n");
    printf("\n\nPress Enter to go back to menu\n\n");
    while(getchar() != '\n');
    getchar();

}


void factorial() {

    int validation, n, res = 1, i;
    double int_part;

    printf("\nEnter a number n to get its factorial: ");
    validation = scanf("%d", &n);
    while(1){
        if(modf((double)n, &int_part) != 0.0 || validation != 1 || n < 0 || n > 21000){
            printf("\nThe number you entered is not valid.\nEnter a valid integer: ");
            // fflush(stdin);
            clear_input_buffer();
            validation = scanf("%d", &n);   
            continue;
        }
        break;
    }

    for(i = n ; i > 0; i--){
        res = res * i;
    }
    printf("\nThe factorial of %d (or %d!)is: %d\n", n, n, res);
    
    printf("\n\nPress Enter to go back to menu\n\n");
    while(getchar() != '\n');
    getchar();

}

void vowel_consonant(){

    int i, size = 1, vowel = 0, consonant = 0;
    char* str = (char*) malloc(size * sizeof(char));
    char c;

    printf("\nEnter a string: ");
    do{
        c = getchar();
        if(c == '\n')
        continue;
        str[size-1] = c;
        size++;
        str = (char*) realloc(str, size * sizeof(char)); 
    }while(c != '\n');

    printf("\n>>>>>>>  %s  <<<<<<<<", str);

    for(i = 0; i < strlen(str); i++){
        if(tolower(str[i]) >= 'a' && tolower(str[i]) <= 'z'){
            if(tolower(str[i]) == 'a' || tolower(str[i]) == 'i'\
             || tolower(str[i]) == 'u' || tolower(str[i]) == 'e'\
              || tolower(str[i]) == 'o'){
                vowel++;
            }
            else
                consonant++;
        }
    }

    
    printf("\n\nThe string you entered is: %s\n", str);    
    printf("-Vowels: %d\n-Consonants: %d", vowel, consonant);
    free(str);

    printf("\n");
    printf("\n\nPress Enter to go back to menu\n\n");
    while(getchar() != '\n');

}



void palindrome(){

    int size = 1, i, j;
    char *str = NULL;
    char c;
    
    printf("\nEnter a string: ");
    do{
        c = getchar();
        if(c == '\n')
        break;
        //printf(" ! %c ! \n", c);
        str = (char*)realloc(str, (size+1) * sizeof(char));
        str[size-1] = c;
        str[size] = '\0';
        size++;
        // str = (char*)realloc(str, size * sizeof(char));
    }while(1);
    j = strlen(str)-1;
    for(i = 0; i < strlen(str); i++){
        if(str[i] != str[j]){
            printf("\nSorry, the string %s is not a palindrome\n", str);
            break;
        }
        j--;
    }
    
    if(i == strlen(str))
    printf("\nThe string %s is a palindrome !\n", str);

    free(str);

    printf("\n\nPress Enter to go back to menu\n\n");
    while(getchar() != '\n');

}


int main (){
    int flag;
    double choice;
    
    do{ 
        flag = menu(&choice);
        if(flag == 0)
        continue;
        switch((int)choice){
            case 1: 
                sorting();
                break;
            case 2:
                pyramid();
                break;
            case 3:
                pushups();
                break;
            case 4:
                factorial();
                break;
            case 5:
                vowel_consonant();
                break;
            case 6:
                palindrome();
                break;
        }
    }while(choice != 7);
   
    return 0;
}