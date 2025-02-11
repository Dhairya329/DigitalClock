#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>
//time function
void fill_time(char* buffer, int format)
{
    time_t rawtime; 
    struct tm *current_time; 
    time(&rawtime); 
    current_time=localtime(&rawtime); 
    if(format==1)
    {
        strftime(buffer, 50, "%H:%M:%S", current_time);
    }
    else
    {
        strftime(buffer, 50, "%I:%M:%S %p", current_time);   
    }
     

}

//date function
void fill_date( char *buffer)
{
    time_t rawtime; 
    struct tm *current_time; 
    time(&rawtime); 
    current_time=localtime(&rawtime); 
    strftime(buffer, 50, "%A %B %d %Y", current_time);
}

// clearing the screen
void clearscreen()
{
   #ifdef _WIN32  
 system("cls"); 
 #else
 system("clear"); 
 #endif
}

int main()
{
   char time[50];int format; char date[100]; 
  
   printf("\nChoose the time format:\n1. 24 Hour Format\n2. 12 Hour Format\t\t\t ");
   scanf("%d",&format); 
   while(1)
   {
    fill_time(time, format);  
    fill_date(date);
    clearscreen(); 
     printf("Current time: %s\n",time  );
     printf("Date: %s\n",date );
     sleep(1); 
   }

    return 0;
}