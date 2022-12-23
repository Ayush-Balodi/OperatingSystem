#include<stdio.h>
#include<math.h>
#include<limits.h>

void sstf( int disc_req[] , int n , int head ){

    int min, diff,distance=0;
    int pending = n,index;

    int finish[n];
    for( int i=0 ; i<n ; i++ ){
        finish[i] = 0;
    }

    printf("%d=>",head);
    while( pending >0 ){

        min = INT_MAX;
        for( int i=0 ; i<n ; i++ ){
            diff = abs(head-disc_req[i]);
            if( finish[i] == 0 && diff<min ){
                min=diff;
                index=i;
            }
        }
        finish[index]=1;
        distance += abs(head-disc_req[index]);
        head = disc_req[index];
        pending--;
        printf("%d=>",head);
    }
    printf("\nDistance covered is: %d\n",distance);
    return;
}

int main (){
    int tracks;
    printf("Enter the total number of tracks: ");
    scanf("%d",&tracks);

    int no_request;
    printf("Enter the number of requests to the disc: ");
    scanf("%d",&no_request);

    int disc_request[no_request];
    printf("Enter the disc request: ");
    for( int i=0 ; i<no_request ; i++ ){
        scanf("%d",&disc_request[i]);
    }
    
    int head;
    printf("Enter the current position of the head: ");
    scanf("%d",&head);

    sstf( disc_request , no_request , head );
    return 0;
}