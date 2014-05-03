#include<iostream>
#include"string.h"
#include"stdio.h"
#include "bitSet.h"

int main()
{
    uint8_t array[1000] ={0,};
    uint32_t vS =0;
    int i =0;
    uint8_t *tempPtr ;

    memset(array,0,sizeof(array));

    bitSet bits(300);

    bits.setBit(0);
    bits.setBit(100);
    bits.setBit(200);
    bits.setBit(300);

    tempPtr = array;

#if 1
    if(-1==bits.GetBitArray(tempPtr,&vS))
         return -1;
#endif 
    printf("\n\n");
    for(i=0;i<vS;i++)
    { 
       printf("%02x\n",array[i]);
    }

    printf("\n\n");
 

    printf("\nbits.CheckIfBitSet(%d)   %d\n",0,bits.CheckIfBitSet(0));

    printf("\nbits.CheckIfBitSet(%d)   %d\n",100,bits.CheckIfBitSet(100));
    printf("\nbits.CheckIfBitSet(%d)   %d\n",200,bits.CheckIfBitSet(200));
    printf("\nbits.CheckIfBitSet(%d)   %d\n",300,bits.CheckIfBitSet(300));
 
}

