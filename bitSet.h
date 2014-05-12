/**/
#include<stdint.h>

#define MAX_BIT_SET_SIZE_IN_BYTES    1000

class bitSet 
{
    private :   
            uint8_t *ptr ;
            uint32_t validSize;
            uint32_t totalSize;
            uint32_t total1s;
            
    public :
            bitSet() {ptr = NULL ; validSize =0;totalSize=0;}
            bitSet(uint32_t size) ;  
            ~bitSet();
            int  setBit(uint32_t pos);
            int resetBit(uint32_t pos);
            int GetBitArray(uint8_t *buff, uint32_t * vS); 
            int CheckIfBitSet(uint32_t pos);
            int totalOnes();
            void clearBitSet();

};
