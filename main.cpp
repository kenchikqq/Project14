#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string.h>




class allocator
{
    int la_init(linear_allocator_t* allocator, size_t, memory_size)
    {
        if (memory_size == 0)
            return 0;

        allocator->offset = 0;
        allocator->size = memory_size;
        allocator->base_pointer = malloc(memory_size);
        return allocator->base_pointer != NULL;
    }

    void la_allocate(linear_allocator_t* allocator, size_t allocated_size)
    {
        
        if (allocator->offset + allocated_size > allocator->size)
            return NULL;

        
        if ((allocated_size == 0) || (allocator->size % allocated_size != 0))
            return NULL;

        size_t allocated_pointer = (size_t)allocator->base_pointer + allocator->offset;
        allocator->offset += allocated_size;
        return (void*)allocated_pointer;
    }




};


