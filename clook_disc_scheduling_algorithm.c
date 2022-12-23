#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

void sort( int arr[] , int n ){

    for( int i=0 ; i<n-1 ; i++ ){
        for( int j=i+1 ; j<n ; j++ ){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return;
}

void clook( int disc_req[] , int n , int head , int tracks ){

    int ch;
    printf("Enter 1 for higher disc(right) or 0 fr lower disc(left): ");
    scanf("%d",&ch);

    sort( disc_req , n );

    int index=0,i=0;
    while( head >= disc_req[i] ){
        index=i;
        i++;
    }

    int distance=0;
    if( ch == 1 ){
        for( int i=index+1; i<n ; i++ ){
            distance += abs(head-disc_req[i]);
            head = disc_req[i];
        }
        for( int i=0 ; i<index; i++ ){
            distance += abs(head-disc_req[i]);
            head = disc_req[i];
        }
    }
    else{
        for( int i=index ; i>=0; i-- ){
            distance += abs(head-disc_req[i]);
            head = disc_req[i];
        }
        for( int i=n-1; i>index ; i-- ){
            distance += abs(head-disc_req[i]);
            head = disc_req[i];
        }
    }
    printf("Distance is: %d\n",distance);
    return;
}

int main (){

    int tracks;
    printf("Enter the total number of tracks: ");
    scanf("%d",&tracks);

    int n;
    printf("Enter the number of disc requests: ");
    scanf("%d",&n);

    int disc_req[n];
    printf("Enter the disc requests respectively: ");
    for( int i=0 ; i<n ; i++ ){
        scanf("%d",&disc_req[i]);
    }

    int head;
    printf( "Enter the current position of the head: ");
    scanf("%d",&head);

    clook( disc_req , n , head , tracks );
    return 0;
}