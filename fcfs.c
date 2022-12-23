#include<stdio.h>

void waitingtime( int b[] , int w[] , int n )
{

    w[0] = 0;
    for( int i=1 ; i< n ; i++ ) {
        w[i] = b[i-1] + w[i-1];
    }
    return;
}

void turnaroundtime( int tat[] , int b[] , int w[] , int n )
{

    for( int i=0 ; i<n ; i++ ) {
        tat[i] = b[i] + w[i];
    }
    return;
}

void avgtime( int p[] , int b[] , int n )
{
    int w[n] , tat[n] ;
    float avgt, avgw;

    waitingtime( b , w , n );
    turnaroundtime( tat , b , w , n );

    for( int i=0 ; i<n ; i++ ) {
        avgt += tat[i];
        avgw += w[i];
    }
    printf("Avergae turn around time is : %f\n",(avgt/n));
    printf("Average waiting time is : %f\n",(avgw/n));
    return;
}

int main()
{
    int process[] = {1,2,3};
    int n = sizeof(process)/sizeof(process[0]);

    int burst_time[l] = {5,7,3};

    avgtime(process, burst_time, n);

    return 0;
}