#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<time.h>
#include <string.h>
#include"card.h"


struct data {
    char name[50];
    char pan[50];
    char expiry[50];
    float balance;
    int pin;
};



void ReadData() {

    printf("\n === Transaction  Payment / Withdrwal === \n");

    struct data readData;
    
    //-------------- input file name / PAN ----------------//
    char namePan[50] ;
    printf("\nEnter Card PAN : ");
    scanf("%s", namePan);


    FILE  *readFile;
    

    readFile = fopen(strcat(namePan, ".dat"), "r");
    if (readFile == NULL)
    {
       printf("Card / PAN does not exist...!");
       ReadData();
    }
    else { 
    
    fread(&readData, sizeof(struct data), 1, readFile);
    printf(" CARD HOLDER : %s", readData.name);
   // printf("READ Data File PIN is %d", readData.pin);
    
    }

    int inPin;
    printf("\nEnter PIN : ");
    scanf("%d", &inPin);

    if (inPin == readData.pin) {
        float withDraw;
        printf("Enter Withdrwal Amount : ");
        scanf("%f", &withDraw);

        printf("Current Balance %f", readData.balance);

        if (withDraw > readData.balance)
        {
            printf("\nInsufficient Balance...!");
            ReadData();
        }
        else 
        {
            printf("\nWithdrawl Successfull ");
            readData.balance = readData.balance - withDraw;
            printf("\nUpdated Balance %f", readData.balance);

            //--------------- Update file Data (Balance)-------------//
            FILE* WriteFile;




            WriteFile = fopen(readData.pan, "w");

            fwrite(&readData, sizeof(struct data), 1, WriteFile);


            fclose(WriteFile);


        }
    }
    else {
        printf("Wrong PIN...! ");
        ReadData();
    }


   


}




void WriteData() 
{

    //struct data writeData = {"Samir Youssif", "12/2012", "PAN7777", 8000.8};

    struct data writeData; // sub stract 

    HolderName(&writeData.name);
    PanNum(&writeData.pan);
    ExpiryDate(&writeData.expiry);
    Balance(&writeData.balance);
    Pin(&writeData.pin);

    printf("Struct writeData.pin is  %d", writeData.pin); // tst struct of pin 
    
    FILE *WriteFile;



        
        WriteFile = fopen(strcat(writeData.pan, ".dat") , "w");
       
        fwrite(&writeData, sizeof(struct data), 1, WriteFile);

        
        fclose(WriteFile);

        
}


    