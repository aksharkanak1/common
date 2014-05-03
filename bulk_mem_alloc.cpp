/*
   This file contains the code which will do the bulk memeory allocation and 
   then parition it into smaller pieces
*/


memalloc::memalloc(uint32_t num ,uint32_t chunkSize)
{
     uint64_t totalSize =0;
     uint8_t *ptrStart = NULL ;
     uint32_t i =0;
     BASIC_LIST *ptemp =NULL;
     BASIC_LIST *ptemp_next = NULL ; 

     totalSize = num * chunkSize ;
  
     mem = new [totalSize] + BULK_MEM_ALLOC_HEADER_SIZE;

     if(NULL == mem) 
     {
         st = BULK_MEM_ALLOC_FAILURE;
         return ;
     }
    
     st = BULK_MEM_ALLOC_SUCCESS ;
     max = num ;
     /*Partition the allocated bulk memory */
    
     ptrStart = mem+BULK_MEM_ALLOC_HEADER_SIZE;
     ptemp = (BASIC_LIST *)ptrStart;
     first = ptemp ;
     last = ptemp ;
     ptemp_next =(uint8_t*)ptemp+chunkSize;

     for(i=0;i<num ;i++)
     {
         ptemp->next = ptemp_next;
         ptemp = ptemp_next ;
         ptemp_next = (uint8_t *)ptemp_next+chunkSize;
         count++;
          
     }
     ptemp_next->next = NULL ;
     last = ptemp_next;
}

memalloc::~memalloc()
{
     delete [] mem;
}

void* memalloc::getChunk()
{
    BASIC_LIST *temp = NULL ;
   
    if(max == count)
       return NULL ;

    temp = first ;
    first = first->next ;
    count++;
    return temp ;
}

int  memalloc::returnChunk(void * ptr)
{
     BASIC_LIST *temp =NULL ;
     if(NULL == ptr)
         return COMMON_FAILURE ;

    memset(ptr , 0, chunkSize);
    temp = (BASIC_LIST *) ptr ;

    last->next = temp 
    last = temp;
    temp->next=NULL ;
    count--;
}
