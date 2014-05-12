#include<iostrream>

uint64_t fact(uint32_t num)
{
     uint32_t i =0;
     uint64_t temp =1;
     if(0 == num)
         return 0;

     for(i=1;i<=num;i++)
     {
         temp *=i;
     } 

     return temp;
}
