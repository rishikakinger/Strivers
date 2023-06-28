// code without using global variables - imp to understand each func will print 
//its OWN N- not the N of the other func & also it remebers this N
//doesnt this make recursion SUPER useful!!!
//instead of global parameters, can make use of parameterized recursion also 

//NOTE: segmentation fault/stack overflow- infinite recursion


//imp code 


#include<stdio.h>

void printNos(int N)
{
    
    if(N==0){
        return;
    }
    else{
    
    printNos(N-1);
    printf("%d ",N);
    }
    
    
}

int main(){
    printNos(5);
}