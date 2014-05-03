/*
   This file contains the class declaration that will be generating the number 
*/

#define GEN_NUM_SERIALLY 
#define GEN_NUM_USING_DEV
#define GEN_NUM_USING_RAND


#define GEN_NUM_DEFAULT_TOTAL_NUM   100

class genNum {
   private :
   uint32_t flag ;
   uint32_t totalNum ;
   uint64_t seed ;
   uint64_t counter ;
   public :
   genNum(): flag(GEN_NUM_SERIALLY),totalNum(GEN_NUM_DEFAULT_TOTAL_NUM)
   {
   } 
   genNum(uint64_t s , uint32_t tNum)
   
   {
         totalNum = tNum;
         seed = s;
         counter = seed;
   }
   
   int getnextNum(uint64_t *pdata)
   {
       counter++;
       *pdata = counter;
   }

};
