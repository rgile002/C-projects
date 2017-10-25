//
//  ArrayList.c
//  HW#1
//
//  Created by Rolf Kinder Gilet ID 5734407 on 6/30/17.
//  Copyright © 2017 Rolf Kinder Gilet. All rights reserved.
//

#include <stdio.h>
#include "ArrayList.h"

boolean ArrayList_New(ArrayList * list){
    list->size=0;
    
    list->arr = calloc(INITIAL_SIZE_STRING_LIST,INITIAL_SIZE_STRING_LIST * sizeof(void*));
    
    if (list->arr== NULL)
        return FALSE;
    list->reserved = INITIAL_SIZE_STRING_LIST;
    return TRUE;
}

boolean ArrayList_Expand(ArrayList * list){
    if (list ==NULL)
        return FALSE;
  
    size_t newReserved = list->reserved *2 ;
    void * temp = realloc(list->arr, newReserved* sizeof(void*));
    if (temp==NULL)
        return FALSE;
    list->reserved = newReserved;
    list->arr = temp;
    
    return TRUE;
    
}

//add at the last position of the array 
boolean ArrayList_Add(ArrayList * list, void * item){
    if (list ==NULL)
        return FALSE;
    
    if (list->size == list->reserved){
        ArrayList_Expand(list);
    }
    list->arr[list->size] = (void *) malloc( sizeof(void *));
    list->arr[list->size] = item;
    list->size +=1;
    
    return TRUE;
}


void * ArrayList_GetList(ArrayList * list){
    if (list ==NULL)
        return FALSE;
    
    return list->arr;
    
}
// return size of the array
size_t ArrayList_GetSize(ArrayList * list){
    if (list ==NULL)
        return FALSE;
    
    return list->size;
    
}

//need to define
//remove entire structure
boolean ArrayList_Free(ArrayList * list){
    if (list ==NULL)
        return FALSE;
    
    for(int i=0 ; i< list->size-1; i++){
    free(list->arr[i]);       
    }
    free(list);
    return TRUE;
}

//remove at index
boolean ArrayList_Remove(ArrayList * list, size_t index){
    if ((int)index < 0 || index > list->reserved)
        return FALSE;
    
    if (index == list->size){
        ArrayList_RemoveLast(list);
        return TRUE;
    }

    while (index < list->size-1){
        list->arr[index]= list->arr[index+1];
        index++;
    }
    list->arr[list->size-1]=NULL;
    list->size--;
    
    return TRUE;
}

// remove last element
boolean ArrayList_RemoveLast(ArrayList *list){ //remove last item and updates
    if (list ==NULL)
        return FALSE;

    list->arr[list->size-1]=NULL;
    list->size--;
    return TRUE;
}

// add an element at and index
boolean ArrayList_Set(ArrayList *list, size_t index, void * item){
    if (list ==NULL)
        return FALSE;
    
    if (list->size <= index || (int)index <0){
        printf("Index %zu out of bounds for the ArrayList of size %zu\n", index, list->size);
        return FALSE;
    }
    
    if(index<= list->size){
        list->arr[index]= realloc(list->arr[index], sizeof(void*));
    list->arr[index]= item;
    }
    return TRUE;
}

// return element at an index
void * ArrayList_Get(ArrayList *list, size_t index){
    if (list ==NULL)
        return NULL;
    
    if ( index >= list->size ||(int)index < 0) {
        printf("Index %zu out of bounds for the ArrayList of size %zu\n", index, list->size);
        return NULL;
    }
    return list->arr[index];
}

//remove all element in the structure
//must do compact
boolean ArrayList_Clear(ArrayList * list){
    if (list ==NULL)
        return FALSE;
    
    int i =0;
    while ( i < (int) list->size){
       free((list->arr[i]));
        i++;
    }
    ArrayList_Compact(list);
   
    return TRUE;
}


// copy elements from source to destination
boolean ArrayList_Copy(ArrayList * destination, const ArrayList * source){
    if (source ==NULL || source->size==0)
        return FALSE;
    
    ArrayList_Clear(destination);
    
    for (int i=0; i< source->size; i++){
        if (source->size > destination->reserved){
            ArrayList_Expand(destination);
        }
        ArrayList_Add(destination, source->arr[i]);
 
    }
    
    return TRUE;
}

//expand reserve memory for the structure
boolean ArrayList_ExpandReserved(ArrayList * list, size_t reserved){
    if (list ==NULL)
        return FALSE;
    
    if (list->reserved > reserved)
       return TRUE;
    
    size_t newReserved = reserved ;
    void * temp = realloc(list->arr, newReserved* sizeof(void*));
    if (temp==NULL)
        return FALSE;
    list->reserved = newReserved;
    list->arr = temp;
    
    return TRUE;
}

// compact the arraylist after clear 
boolean ArrayList_Compact(ArrayList * list){ //it compacts to size + 100 if possible.
    list->size=0;
    list->arr = realloc(list->arr,INITIAL_SIZE_STRING_LIST * sizeof(void*));
    list->reserved= INITIAL_SIZE_STRING_LIST;
    
 return 1;
}

//optional
///boolean ArrayList_InitStruct(ArrayList ** list);
///boolean ArrayList_FreeStruct(ArrayList ** list);
