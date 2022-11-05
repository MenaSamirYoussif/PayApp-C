
#include<stdio.h>
#include <stdlib.h>
#include<string.h>




void HolderName(char *name_back[50]) // rtrn pointer to name
{
    
    char holderName[50];
    printf("Holder Name : ");
    fgets(holderName, sizeof(holderName), stdin);
    holderName[strlen(holderName) - 1] = '\0';
    strcpy(name_back, holderName);
   
    

}

void ExpiryDate(char *date_back[50]) // rtrn pointer to expiry date
{
    int month;
    int year;


dategain:

    printf("\nEnter Card Expiry Date MM/YYYY : ");
    int validate = scanf("%d/%d", &month, &year);

    if (validate != 2) {
        printf("Please Enter Valid Date format MM/YYYY!");
        goto dategain;

    }

    else if (month <= 0 || month > 12) {

        printf("Enter Month from 1 to 12 !");
        printf("%d", month);
        goto dategain;
    }

    else if (year < 2000 || year > 2100) {

        printf("Enter years from 2000 to 2100");
        goto dategain;
    }


    else {
        
        sprintf(date_back, "%d/%d", month, year);
        date_back[strlen(date_back) - 1] = '\0';
      

    }



}

void PanNum(char *pan_back) {

    char PanNum[50];
    printf("\nPAN Number  : ");
    fgets(PanNum, sizeof(PanNum), stdin);
    PanNum[strlen(PanNum) - 1] = '\0';
    strcpy(pan_back, PanNum);


}

void Balance(float* amt) {
    float balance;
    printf("\nBalance : ");
    scanf("%f", &balance);
    *amt = balance;
}

void Pin(int *pin) {
    int set_pin;
    printf(" Set PIN : ");
    scanf("%d", &set_pin);
    *pin = set_pin;
    printf(" TST *pin  %d |", *pin);
}