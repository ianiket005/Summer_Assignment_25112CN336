#include <stdio.h>
int main(){
    int n=5;
   
    for(int row=1;row<=n;row++){
        for(int col=1;col<=row;col++){
            if(col==1){
                printf("A ");
                continue;
            }
            if(col==2){
                printf("B ");
                continue;
            }
            if(col==3){
                printf("C ");
                continue;
            }
            if(col==4){
                printf("D ");
                continue;
            }
            if(col==5){
                printf("E ");
                break;
            }

           
        }   
         printf("\n");         
    }
   

    return 0;
}