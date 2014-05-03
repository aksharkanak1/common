#include<iostream>
#include<stdint.h>
#include "string.h"
#include "bitSet.h"


bitSet::bitSet(uint32_t size)
{
    uint32_t tempSize =0;
    
    ptr = NULL ;

    tempSize = (size/8);
    if(size%8 > 0)
       tempSize++;
 
    if(tempSize > MAX_BIT_SET_SIZE_IN_BYTES)
    {
        validSize =0;
        return ;
    }

    

    ptr = new uint8_t[tempSize];
    validSize = tempSize;
 
    return ;
}


bitSet::~bitSet()
{
     if(NULL != ptr)
         delete [] ptr;
}

int bitSet::setBit(uint32_t pos)
{
    uint32_t byte ;
    uint8_t  bit;

    if( NULL == ptr)
        return -1;

    byte = pos/8;
    bit = pos%8;

    if(byte >=validSize)
       return -1;
    else
    {
       if(0==(ptr[byte]&(0x01<<bit)))
       {
           total1s++;  
           ptr[byte] |=(0x01<<bit) ;
       }
    }

    //total1s++;
    return 0;
}

int bitSet::resetBit(uint32_t pos)
{
    uint32_t byte ;
    uint8_t  bit;

    if( NULL == ptr)
        return -1;

    byte = pos/8;
    bit = pos%8;

    if(byte >=validSize)
       return -1;
    else
    {
       if(0!=(ptr[byte]&(0x01<<bit)))
       {
          total1s--;
          ptr[byte] &=~(0x01<<bit) ;
       }
    }
    return 0;
}

int bitSet::GetBitArray(uint8_t *buff, uint32_t *vS)
{
    if(NULL == ptr||NULL == buff || NULL == vS )
         return -1;


   memcpy(buff,ptr,validSize);
   *vS = validSize;
}


int bitSet::CheckIfBitSet(uint32_t pos)
{
    uint32_t byte ;
    uint8_t  bit;

    if( NULL == ptr)
        return -1;

    byte = pos/8;
    bit = pos%8;

    if((ptr[byte] & (0x01<<bit)) != 0)
        return 1;
    else 
        return 0;
     
}

int bitSet::totalOnes()
{  
   return total1s;
}

