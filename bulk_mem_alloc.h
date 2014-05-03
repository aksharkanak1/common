



#define BULK_MEM_ALLOC_SUCCESS    0x01
#define BULK_MEM_ALLOC_FAILURE    0x00

#define BULK_MEM_ALLOC_HEADER_SIZE    10




typedef struct basic_list 
{
    struct basic_list *next ;
} BASIC_LIST ;


class memalloc 
{
    private :
    uint32_t count ;
    BASIC_LIST * first ;
    BASIC_LIST * last ;
    uint16_t st ;
    uint8_t * mem ;
    uint32_t memSize ;
    uint32_t max ;
    uint32_t chunkSize; 
    public :
      memalloc():count(0),first(NULL),last(NULL),
                 st(BULK_MEM_ALLOC_FAILURE),
                 mem(NULL),
                 memSize(0)
      { }
     memalloc(uint32_t num ,uint32_t chunkSize);
     ~memalloc();
     void * getChunk() ;
     int  returnChunk(void * ptr);
 
};
