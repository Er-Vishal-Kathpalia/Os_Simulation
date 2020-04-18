#include <stdio.h>
int main(){
    int process, x, counter=0, timequantum;
    int i;
    int turnaroundtime = 0, waittime = 0, arrivaltime[50], bursttime[50];
    int arr[10];
    float Avgwtime,Avgttime;
    printf("Enter the total number of Processes::\n");
    scanf("%d",&process);
    x = process;
    for(i=0;i<process;i++){
        printf("Enter the detail of process%d::",i+1);
        printf("\nEnter Arrival time::");
        scanf("%d",&arrivaltime[i]);
        printf("Enter Burst time::");
        scanf("%d",&bursttime[i]);
        arr[i] = bursttime[i];
    }
    printf("Enter Time Quantum::");
    scanf("%d",&timequantum);

    printf("\nProcess id\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
    int Total = 0;
    for(i=0;x!=0;){
        if(arr[i]>0 && arr[i]<=timequantum){
            Total = Total+arr[i];
            arr[i]=0;
            counter=1;
        }
        else if(arr[i]>0){
            arr[i] = arr[i]-timequantum;
            Total = Total+timequantum;
        } 
        if(counter == 1 && arr[i] == 0){
            x--;
            printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d",i+1,bursttime[i],Total-arrivaltime[i], Total-arrivaltime[i]-bursttime[i]);
            waittime = waittime+Total-arrivaltime[i]-bursttime[i];
            turnaroundtime = turnaroundtime+Total-arrivaltime[i];
            counter=0;
        }
        if(i==process-1){
            i=0;
        }
        else if(arrivaltime[i+1]<=Total){
            i++;
        }
        else{
            i=0;
        }
    }
    Avgwtime = waittime*1.0/process;
    Avgttime = turnaroundtime*1.0/process;
    printf("\nAverage Waiting time:: \t%f",Avgwtime);
    printf("\nAverage Turnaround time:: \t%f",Avgttime);
    return 0;
}
