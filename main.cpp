#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>   
// size of array
#define MAX 10000

#define MAX_THREAD 1

  
int a[MAX] ; // it is array of size max which is equal to 10000 //
double sum[4] = { 0 }; // sum array 4 declear becuase this pthread has 10000 array sum will be calculate so 4 thread are best for time complexity //
int part = 0;   


void* sum_array(void* arg)
{
  
// Each thread computes sum of 1/4th of array
int thread_part = part++;
  
for (int i = thread_part * (MAX / 4); i < (thread_part + 1) * (MAX / 4); i++)   
   /* this is for time saving .. these proces are so long so pthread use to reduce time excuting */
sum[thread_part] += a[i]; // here i calculate the sum and index is pthread which thread current runningand then sum find and store it //
// its simple statement dont be confused it //
return 0;
}
  
// Driver Code
int main()
{


for(int i = 0 ; i<MAX ; i++){

a[i] = rand() % 1000 + 1 ; // i here random number generate between 1 to hundered and inlized to 10000 size array //

}

/* for(int i = 0 ; i<MAX ; i++){
    printf("%d\n" , a[i]);
   
    you can see the number are actually genereted or not. for confrm u can display random number here
}
*/


  
pthread_t threads[MAX_THREAD];
  
// Creating 4 threads
for (int i = 0; i < MAX_THREAD; i++)
pthread_create(&threads[i], NULL, sum_array, (void*)NULL);
  
for (int i = 0; i < MAX_THREAD; i++)
pthread_join(threads[i], NULL);
  
// adding sum of all 4 parts
int total_sum = 0;
for (int i = 0; i < MAX_THREAD; i++)
total_sum += sum[i];
  
printf("sum is %d\n" , total_sum) ;
return 0;
}