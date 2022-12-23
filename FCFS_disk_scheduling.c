#include<stdio.h>
#include<math.h>

void fcfs( int cylinders[] , int n , int head ){

    int head_movement;
    for( int i=0 ;i<n ; i++ ){
        head_movement += abs(cylinders[i]-head);
        head= cylinders[i];
    }
    printf("Total head movements during the requests is: %d",head_movement);
    return;
}

int main (){
    int n;
    printf("Enter the number of requests: ");
    scanf("%d",&n);

    int cylinders[n];
    printf("Enter order of cylinder requests: ");
    for( int i=0 ; i<n ; i++ ){
        scanf("%d",&cylinders[i]);
    }

    int head;
    printf("Enter the starting position of the head: ");
    scanf("%d",&head);

    fcfs( cylinders , n , head );
    return 0;
}