#include<stdio.h>
int main(){ 
    int n=5;
    for(int row=1;row<=n;row++){
        for(int col=1;col<=row;col++){
            if(row==1){
                printf("A ");
            }
            else if(row==2){
                printf("B ");
            }
            else if(row==3){
                printf("C ");
            }
            else if(row==4){
                printf("D ");
            }
            else if(row==5){
                printf("E ");
            }

        }
        printf("\n");
    }
    return 0;
}