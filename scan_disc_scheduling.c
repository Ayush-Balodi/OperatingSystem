#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

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

void scan( int disc_req[] , int n , int track , int head ){

    int ch;
    printf("Enter 1 for higher dic(right) or 0 for lower dic(left): ");
    scanf("%d",&ch);

    int index=0,i=0;

    sort( disc_req , n );

    while( head >= disc_req[i] ){
        index++;i++;
    }

    printf("\n%d=>",head);
    int distance=0;
    if( ch == 1 ){
        
        for( int i=index+1 ; i<n ; i++ ){
            distance += abs(head-disc_req[i]);
            head = disc_req[i];
            printf("%d =>",head);
        }
        distance += abs(head-track-1);
        head = track-1;
        printf("%d =>",head);
        for( int i=index ; i>=0 ; i-- ){
            distance = abs(head-disc_req[i]);
            head = disc_req[i];
            printf("%d =>",head);
        }
    }
    else{
        for( int i=index ; i>=0 ; i-- ){
            distance = abs(head-disc_req[i]);
            head = disc_req[i];
            printf("%d =>",head);
        }
        distance += abs( head - 0 );
        head = 0;
        printf("%d =>",head);
        for( int i=index+1 ; i<n ; i++ ){
            distance += abs(head-disc_req[i]);
            head = disc_req[i];
            printf("%d =>",head);
        }
    }
    return;
}

int main(){

    int tracks;
    printf("Enter the total number of tracks: ");
    scanf("%d",&tracks);

    int requests;
    printf("Enter the total number of disc requests: ");
    scanf("%d",&requests);

    int disc_req[requests];
    printf("Enter the disc requests respectively: ");
    for( int i=0 ; i<requests ; i++ ){
        scanf("%d",&disc_req[i]);
    }

    int head;
    printf("Enter the current position of the head: ");
    scanf("%d",&head);

    scan( disc_req , requests , tracks , head );
    return 0;
}