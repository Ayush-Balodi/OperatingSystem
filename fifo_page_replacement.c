#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

typedef struct PageTable{
    int frame_no;
    int valid;
}Page;

bool isPagePresent( Page PT[] , int page ){
    if( PT[page].valid == 1 ){
        return true;
    }
    return false;
}

void updateContent( Page PT[] , int page , int fr_no , int satus ){
    PT[page].frame_no = fr_no;
    PT[page].valid = satus;
}

void printContent( int frame[] , int nof ){
    for( int i=0 ; i<nof ; i++ ){
        printf("%d ",frame[i]);
    }
    printf("\n");
    return;
}

int main ()
{
    int n;
    printf("Enter the number of pages: ");
    scanf("%d",&n);

    int nof;
    printf("Enter the number of frames: ");
    scanf("%d",&nof);

    int frame[nof];
    for( int i=0 ; i<nof ; i++ ){
        frame[i] = -1;
    }
    // memset( frame , -1 , nof*sizeof(int) );

    int reference[n];
    printf("Enter the reference string: ");
    for( int i=0 ; i<n ; i++ ){
        scanf("%d",&reference[i]);
    }

    Page PT[100];
    for( int i=0 ; i<100 ; i++ ){
        PT[i].valid=0;
    }
    
    bool flag = false; 
    int current=0,page_fault=0,hit=0;
    
    for( int i=0 ; i<n ; i++ ){
        
        if( !isPagePresent( PT , reference[i]) ){
            
            page_fault++;
            if( flag == false && current<nof ){
                frame[current] = reference[i];
                printContent( frame , nof );
                updateContent(PT , reference[i] , current , 1);
                current = current+1;
                if( current == nof ){
                    current=0;
                    flag=true;
                }
            }
            else{
                updateContent( PT , frame[current] , -1 , 0 );
                frame[current] = reference[i];
                printContent( frame , nof );
                updateContent( PT , reference[i] , current , 1 );
                current = (current+1)%nof;
            }
        }
        else{
            hit++;
            printContent( frame , nof );
        }
    }
    printf("Page Fault = %d",page_fault);
    printf("Page Hit = %d",hit);
    return 0;
}