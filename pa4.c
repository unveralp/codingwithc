#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct flights{
    int number;
    char departure_city[15];
    char arrival_city[15];
    char departure_day[20];
    char departure_time[10];
    char arrival_day[20];
    char arrival_time[10];
};
struct passengers{
    char firstname[15];
    char lastname[15];
    char departurecity[15];
    char arrivalcity[15];
    char departureday[20];
};
void printReservation(struct passengers pass){
    printf("%s %s %s %s %s No reservation\n",pass.firstname,pass.lastname,pass.departurecity,pass.arrivalcity,pass.departureday);
}
int makeReservation(struct passengers pass,struct flights flght[],int n){
     int count=0;
     for(int i=0;i<n;i++){
        if(!(strcmp(pass.departurecity,flght[i].departure_city)) && !(strcmp(pass.arrivalcity,flght[i].arrival_city)) && !(strcmp(pass.departureday,flght[i].departure_day))){
            count++;
        }
        else{
            continue;
        }
     }
     if(count==0) printReservation(pass);
}
void searchFlight(struct flights flght[],int n,int flightnumber){
    int count2=0;
    for(int i=0;i<n;i++){
        if(flght[i].number==flightnumber){
            printf("%d %s %s %s %s %s %s\n",flght[i].number,flght[i].departure_city,flght[i].arrival_city,flght[i].departure_day,flght[i].departure_time,flght[i].arrival_day,flght[i].arrival_time);
            count2++;
        }
        else continue;
    }
    if(count2==0){
        printf("No flight with number %d\n",flightnumber);
    }
}
void searchDep(struct flights flght[],int n,char dep[15]){
    int count3=0;
    for(int i=0;i<n;i++){
        if(!(strcmp(flght[i].departure_city,dep))){
            printf("%d %s %s %s %s %s %s\n",flght[i].number,flght[i].departure_city,flght[i].arrival_city,flght[i].departure_day,flght[i].departure_time,flght[i].arrival_day,flght[i].arrival_time);
            count3++;
        }
    }
    if(count3==0){
        printf("No departure city %s\n",dep);
    }
}
void searchArr(struct flights flght[],int n,char arr[15]){
    int count4=0;
    for(int i=0;i<n;i++){
        if(!(strcmp(flght[i].arrival_city,arr))){
            printf("%d %s %s %s %s %s %s\n",flght[i].number,flght[i].departure_city,flght[i].arrival_city,flght[i].departure_day,flght[i].departure_time,flght[i].arrival_day,flght[i].arrival_time);
            count4++;
        }
    }
    if(count4==0){
        printf("No arrival city %s\n",arr);
    }
}
void printFlight(struct flights flght[],int n,struct passengers pass[],int numofpass,int flightnum){
    int i,count6=0;
    for(i=0;i<n;i++){
        if(flght[i].number==flightnum) break;
        else continue;
    }
    for(int j=0;j<numofpass;j++){
        if(!(strcmp(pass[j].departurecity,flght[i].departure_city)) && !(strcmp(pass[j].arrivalcity,flght[i].arrival_city)) && !(strcmp(pass[j].departureday,flght[i].departure_day))){
            count6++;
        }
        else continue;
    }
    printf("%d %s %s %s %s %s %s %d\n",flght[i].number,flght[i].departure_city,flght[i].arrival_city,flght[i].departure_day,flght[i].departure_time,flght[i].arrival_day,flght[i].arrival_time,count6);
}

void printFlightwPassengers(struct flights flght[],int n,struct passengers pass[],int numofpass,int num){
    int i,count7=0;
    for(i=0;i<n;i++){
        if(flght[i].number==num) break;
        else continue;
    }
    for(int j=0;j<numofpass;j++){
        if(!(strcmp(pass[j].departurecity,flght[i].departure_city)) && !(strcmp(pass[j].arrivalcity,flght[i].arrival_city)) && !(strcmp(pass[j].departureday,flght[i].departure_day))){
            count7++;
        }
        else continue;
    }
    printf("%d %s %s %s %s %s %s %d\n",flght[i].number,flght[i].departure_city,flght[i].arrival_city,flght[i].departure_day,flght[i].departure_time,flght[i].arrival_day,flght[i].arrival_time,count7);
    int k;
    for(k=0;k<numofpass;k++){
        if(!(strcmp(pass[k].departurecity,flght[i].departure_city)) && !(strcmp(pass[k].arrivalcity,flght[i].arrival_city)) && !(strcmp(pass[k].departureday,flght[i].departure_day))){
            printf("%s %s\n",pass[k].firstname,pass[k].lastname);
        }
        else continue;
    }
}
void printr(struct flights flght[],int n,struct passengers pass[],int numofpass,char fn[15],char ln[15]){
    int i,j;
    for(i=0;i<numofpass;i++){
        if(!(strcmp(pass[i].firstname,fn))&& !(strcmp(pass[i].lastname,ln))){
            break;
        }
        else continue;
    }
    for(j=0;j<n;j++){
        if(!(strcmp(flght[j].departure_city,pass[i].departurecity)) && !(strcmp(flght[j].arrival_city,pass[i].arrivalcity)) && !(strcmp(flght[j].departure_day,pass[i].departureday))){
            break;
        }
        else continue;
    }
    printf("%s %s %d %s %s %s %s %s %s\n",pass[i].firstname,pass[i].lastname,flght[j].number,flght[j].departure_city,flght[j].arrival_city,flght[j].departure_day,flght[j].departure_time,flght[j].arrival_day,flght[j].arrival_time);
}
int main()
{
    int n;
    scanf("%d",&n);
    struct flights* flght;
    flght=(struct flights*)malloc(n*sizeof(struct flights));
    for(int i=0;i<n;i++){
      scanf("%d%s%s%s%s%s%s",&flght[i].number,flght[i].departure_city,flght[i].arrival_city,flght[i].departure_day,flght[i].departure_time,flght[i].arrival_day,flght[i].arrival_time);
    }
    int numofpass;
    scanf("%d",&numofpass);
    struct passengers* pass;
    pass=(struct passengers*)malloc(numofpass*sizeof(struct passengers));
    for(int i=0;i<numofpass;i++){
        scanf("%s%s%s%s%s",pass[i].firstname,pass[i].lastname,pass[i].departurecity,pass[i].arrivalcity,pass[i].departureday);
        makeReservation(pass[i],flght,n);
    }
    printf("\n");
    char queries[10];
    while(1){
        scanf("%s",queries);
        if(!(strcmp(queries,"END"))) break;
        else if(!(strcmp(queries,"search"))){
            char query[15];
            scanf("%s",query);
            if(!(strcmp(query,"flightNumber"))){
            int flightnumber;
            scanf("%d",&flightnumber);
            searchFlight(flght,n,flightnumber);
            printf("\n");
            }
            else if(!(strcmp(query,"departure"))){
            char dep[15];
            scanf("%s",dep);
            searchDep(flght,n,dep);
            printf("\n");
            }
            else if(!(strcmp(query,"arrival"))){
            char arr[15];
            scanf("%s",arr);
            searchArr(flght,n,arr);
            printf("\n");
            }
        }
        else if(!(strcmp(queries,"print"))){
            int flightnum;
            scanf("%d",&flightnum);
            printFlight(flght,n,pass,numofpass,flightnum);
            printf("\n");
        }
        else if(!(strcmp(queries,"printwP"))){
            int num;
            scanf("%d",&num);
            printFlightwPassengers(flght,n,pass,numofpass,num);
            printf("\n");
        }
        else if(!(strcmp(queries,"printR"))){
            char fn[15];
            scanf("%s",fn);
            char ln[15];
            scanf("%s",ln);
            printr(flght,n,pass,numofpass,fn,ln);
            printf("\n");
        }

    }
}
