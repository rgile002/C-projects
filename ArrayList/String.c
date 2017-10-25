//
//  String.c
//  HW#1
//
//  Created by Rolf Kinder Gilet ID 5734407 on 6/29/17.
//  Copyright © 2017 Rolf Kinder Gilet. All rights reserved.
//

#include <stdio.h>
#include "String.h"
#include <stdlib.h>

size_t String_ChrLen(char *s)
{
    int len ;
    for (len =0; *s !='\0'; s++)
        len++;
    
    return len;
}

/* size_t String_ChrLen2(char *s)
 {
 char *p=s;
 while(p != '\0')
 p++;
 return p - s;
 }*/


int String_EqualLen(String *lhs, String *rhs)
{
    if ( lhs->size != rhs->size)
        return 0;
    
    return 1;
}

// new string
int String_New(String * strObj,char * str){
    if(strObj == NULL || str== NULL)
        return 0;
    
    strObj->size = String_ChrLen(str);
    strObj->str = (char *) malloc(sizeof(char) * (strObj->size) +1);
    if(strObj->str == NULL)
        return 0;
    for (int i=0; i<= strObj->size; i++){
        strObj->str[i]=str[i];
    }
    strObj->str[strObj->size+1] = '\0';
    
    strObj->hashcode = String_CreateHash(str);
    return 1;
}


int String_Equal(String * lhs, String * rhs){
    
    if (!String_EqualLen(lhs,rhs)){
        return 0;}
    
    for ( int i=0; i < lhs->size; i++)
        if(lhs->str[i] != rhs->str[i])
            return 0;
    return 1;
}


//void String_Delete(String  ** strObj);
char * String_Get(String * strObj){
    
    return strObj->str;
}


int String_Append(String * strObj, char * strAppend){
    
    int sizeOfNewString = (int)String_ChrLen(strAppend);
    char * temp = realloc(strObj->str, strObj->size + sizeOfNewString + 1);
    if (temp == NULL)
        return 0;
    strObj->str =temp;
    int i = (int)strObj->size ;
    int k =0 ;
    while(strAppend[k] != '\0'){
        strObj->str[i++] = strAppend[k++];
        strObj->size ++;
    }
    strObj->str[i+1] = '\0';
    
    
    return 1;
}


void String_Free(String * strObj){
    strObj->size =0;
    free(strObj->str);
}


//define get and set for a given char. only if is within bounds
char String_GetChar(const String *strObj,const size_t index){
    return strObj->str[index];
}


void String_SetChar(const String *strObj,const size_t index, const char c){
    strObj->str[index] = c;
    
}

// implementation
// Copies the C string pointed by source into the C string pointed by destination
String * String_Cpy( String * destination, const String * source )
{   // return if no memory is allocated to the destination
    if (destination == NULL || source==NULL)
        return NULL;
    
    if (source->size==0)
        return NULL;
    
    destination->size=0;
    free (destination->str);
    destination->str = (char *) malloc(sizeof(char) * (source->size) +1);
    
    int i;
    for ( i=0; i<=source->size; ++i){
        destination->str[i] = source->str[i];
        destination->size +=1;
    }
    destination->str[i+1] = '\0';
    
    return destination;
    
}

//Copies the first num characters of source to destination
String * String_nCpy ( String * destination, const String * source, size_t num ){
    
    // return if no memory is allocated to the destination
    if (destination == NULL || source==NULL)
        return NULL;
    
    if (source->size==0)
        return NULL;
    
    int i;
    destination->size=0;
    destination->str = (char *) malloc(sizeof(char) * (source->size) +1);
    
    for (i=0; i<source->size && i<num ; i++){
        destination->str[i] = source->str[i];
        destination->size++;
    }
    destination->str[i] = '\0';
    
    return destination;
    
}

//Appends a copy of the source string to the destination string
String * String_Cat ( String * destination, const String * source ){
    // return if no memory is allocated to the destination
    if (destination == NULL || source==NULL)
        return NULL;
    
    if (source->size==0 || destination->size==0)
        return NULL;
    
    
    destination->str = realloc ((destination->str),(destination->size + source->size  + 1));
    
    
    int i,j;
    j=0;
    j=(int)destination->size;
    for (i=0; i<source->size; i++,j++){
        destination->str[j] = source->str[i];
        destination->size++;
    }
    j = (int)destination->size;
    
    destination->str[j+1] = '\0';
    
    return destination;
}

// Appends the first num characters of source to destination
String * String_nCat ( String * destination, const String * source, size_t num ){
    // return if no memory is allocated to the destination
    if (destination == NULL || source==NULL)
        return NULL;
    
    if (source->size==0 || destination->size==0)
        return NULL;
    
    int i,j;
    j=0;
    j=(int)destination->size;
    
    for (i=0; i<source->size && i< num; ++i,j++){
        destination->str[j] = source->str[i];
        destination->size++;        
    }
    
    j = (int)destination->size;
    
    destination->str[j] = '\0';
    
    
    return destination;
    
}
//Compares the C string str1 to the C string str2
int String_Cmp ( const String * str1, const String * str2 ){
    if (str1 == NULL || str2 ==NULL)
        return 0;
    
    if (str1->size==0 || str2->size==0)
        return 0;
    
    unsigned char c1, c2;
    
    char *s1 = (str1->str);
    char *s2 = (str2->str);
    
    for (int i=0; i<str1->size; i++){
        if((s1[i]) >= 'A' && (s1[i]) <= 'Z')
            c1 = (s1[i]) + 32;
        else c1= s1[i];
        
        if((s2[i]) >= 'A' && (s2[i]) <= 'Z')
            c2 = (s2[i]) + 32;
        else c2= s2[i];
        
        if (c1!=c2)
            return 0;
    }
    
    return 1;
}

//Compares up to num characters of the C string str1 to those of the C string str2
int String_nCmp ( const String * str1, const String * str2, size_t num ){
    if (str1 == NULL || str2 ==NULL)
        return 0;
    
    if (str1->size==0 || str2->size==0)
        return 0;
    
    unsigned char c1, c2;
    
    char *s1 = (str1->str);
    char *s2 = (str2->str);
    
    for (int i=0; i<num; i++){
        if((s1[i]) >= 'A' && (s1[i]) <= 'Z')
            c1 = (s1[i]) + 32;
        else c1= s1[i];
        
        if((s2[i]) >= 'A' && (s2[i]) <= 'Z')
            c2 = (s2[i]) + 32;
        else c2= s2[i];
        if (c1!=c2)
            return 0;
    }
    
    return 1;
}
//Returns a pointer to the first occurrence of character in the C string str
String * String_Chr (String * str, int character ){
    if (str == NULL)
        return NULL;
    
    if (str->size==0)
        return NULL;
    
    for ( ; *str->str != '\0'; str->str++){
        if (*(str->str) == character)
            return str;
    }
    return NULL;
}

//Scans str1 for the first occurrence of any of the characters that are part of str2
//return The length of the initial part of str1 not containing any of the characters
//that are part of str2
size_t String_cSpn ( const String * str1, const String * str2 ){
    if (str1 == NULL || str2 == NULL)
        return -1;
    
    if (str1->size==0 || str2->size==0)
        return -1;
    
    size_t len=0;
    char a= '0';
    int b=0;
    for (int i=0 ; i<str1->size; i++){
        a = str1->str[i];
        for (int j=0 ; j< str2->size; j++){
            if (str2->str[j] == a){
                b=1;
                break;
            }
        }
        if(b==0){
            len++;
        }
        else return len;
    }
    return len;
}
//Returns a pointer to the first occurrence in str1
//of any of the characters that are part of str2
//a null pointer if there are no matches
String * String_pBrk (const String * str1, const String * str2 ){
    if (str1 == NULL || str2 == NULL)
        return NULL;
    
    if (str1->size==0 || str2->size==0)
        return NULL;
    
    char a= '0';
    for ( int i=0; i<str1->size; i++){
        a = str1->str[i];
        for (int j=0 ; j< str2->size; j++){
            if (str2->str[j] == a){
                return (String *) (str1->str+i);
            }
        }
    }
    return NULL;
}

//Returns a pointer to the last occurrence of character in the C string str
String * String_rChr (const String * str, int character ){
    if (str == NULL )
        return NULL;
    
    if (str->size==0 )
        return NULL;
    
    int step= -1;
    for ( int i=0; i<str->size; i++){
        if (str->str[i] == character)
            step =i;
    }
    
    if (step !=-1){
        
        return (String *) (str->str + step);
    }
    return NULL;
}

//Returns the length of the initial portion of str1 which consists only of characters that are part of str2
size_t String_spn ( const String * str1, const String * str2 ){
    if (str1 == NULL || str2 == NULL)
        return -1;
    
    if (str1->size==0 || str2->size==0)
        return -1;
    
    size_t len=0;
    char a= '0';
    int found=0;
    for (int i=0 ; i<str1->size; i++){
        a = str1->str[i];
        
        for (int j=0 ; j< str2->size; j++){
            if (str2->str[j] == a){
                found=1;
                break;
            }
        }
        if(found==1){
            len++;
            found=0;
        }
        else break;
    }
    return len;
}
//Returns a pointer to the first occurrence of str2 in str1
//or a null pointer if str2 is not part of str1
String * String_Str (String * str1, const String * str2 ){
    if (str1 == NULL || str2 == NULL)
        return NULL;
    
    if (str1->size==0 || str2->size==0)
        return NULL;
    
    char a= '0';
    int step=0;
    
    for ( int i=0, j =0; i<str1->size;){
        a = str1->str[i];
        
        if (str2->str[j] == a){
            i++;
            j++;
            
        } else {
            i++;
            j=0;
            step=i;
        }
        
        if (j== str2->size){
            return (String *) (str1->str+step);
        }
    }
    
    return NULL;
}
// Returns the length of the C string str
size_t String_Len ( const String * str ){
    if (str == NULL )
        return -1;
    
    return str->size;
    
}


//Appendix B

//return a hash code already calculated in the String_New
size_t String_GetHashCode(const String * str){
    if (str == NULL )
        return -1;
    
    return str->hashcode;
}
// need to be tested
size_t String_CreateHash(const char * s){
    
    unsigned long hash = 5381;
    int c;
    
    while ((c = *s++))
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    
    return hash;
    
}
//Trim left and right spaces at the end of the string.
String * String_Trim(String * str){
    if (str == NULL )
        return NULL;
    
    if (str->size==0 )
        return NULL;
    
    int i = (int) str->size -1;
    
    while( str->str[i] == ' ' ){
        i--;
        str->size --;
    }
    str->str[i+1] ='\0';
    
    while (*str->str == ' '){
        str->str++;
        //  str->size -= 1;
    }
    return (String *)str->str;
}

// Trim Left space
String * String_LTrim(String * str){
    if (str == NULL )
        return NULL;
    
    if (str->size==0 )
        return NULL;
    
    while (*str->str ==' '){
        str->str++;
    }
    return (String *)str->str;
}

//Trim Right space
String * String_RTrim(String * str){
    if (str == NULL )
        return NULL;
    
    if (str->size==0 )
        return NULL;
    
    int i = (int) str->size -1;
    while( str->str[i] == ' ' ){
        i--;
        str->size--;
    }
    str->str[i+1] = '\0';
    
    return str;
}

//return char from index
size_t String_GetCharFromIndex(const String * str, int index){
    if (str == NULL || (index < 0 || index> str->size))
        return -1;
    
    if (str->size==0 )
        return -1;
    
    return str->str[index];
}

//return the index of the first occurrence
int String_IndexOfChar(const String * str, char c){
    if (str == NULL )
        return -1;
    
    if (str->size==0 )
        return -1;
    
    int i;
    for (i=0; i<*str->str; i++){
        if ( str->str[i]==c)
            return i;
    }
    return -1;
}
//make string all lowercase
String * String_Lower(String * str){
    if (str == NULL )
        return NULL;
    
    if (str->size==0 )
        return NULL;
    
    for (int  i=0; i<=str->size; i++){
        if((str->str[i]) >= 'A' && (str->str[i]) <= 'Z')
            (str->str[i]) = (str->str[i]) + 32;
    }
    return str;
}

//make string all uppercase
String * String_Upper(String * str){
    if (str == NULL )
        return NULL;
    
    if (str->size==0 )
        return NULL;
    
    for (int  i=0; i<=str->size; i++){
        if((str->str[i]) >= 'a' && (str->str[i]) <= 'z')
            (str->str[i]) = (str->str[i]) - 32;
    }
    return str;
}

// reverse string
String * String_Reverse(String * str){
    if (str == NULL )
        return NULL;
    
    if (str->size==0 )
        return NULL;
    
    int c, i, j;
    int len = (int)String_ChrLen(str->str);
    for (i=0 , j=(len- 1); i<j; i++ , j--){
        c = str->str[i];
        str->str[i]=str->str[j];
        str->str[j]= c;
    }
    return str;
}


//count the amount of words in a given a string
size_t String_WordCount(const String * str){
    if (str == NULL )
        return -1;
    
    if (str->size==0 )
        return -1;
    
    int count=0;
    for (int i = 0;str->str[i] != '\0';i++)
    {
        if (str->str[i] == ' '&& str->str[i+1] != ' ')
            count++;
    }
    return count+1;
}


//returns a substring of a string that starts with X.
//return new string
String * String_StartsWith (const String * str, const String * startsWith){
    if (str == NULL || startsWith == NULL)
        return NULL;
    
    if (str->size==0 || startsWith->size==0)
        return NULL;
    
    char a= '0';
    int step=0;
    
    for ( int i=0, j =0; i<str->size;){
        a = str->str[i];
        
        if (startsWith->str[j] == a){
            i++;
            j++;
        } else {
            i++;
            j=0;
            step=i;
        }
        
        if (j== startsWith->size){
            char b[str->size -step];
            j=0;
            for(int i=0, j=step; str->str[j] != '\0'; i++,j++){
                b[i]= str->str[j];
            }
            String *w = (String *) malloc(sizeof (String));
            String_New(w, b);
            return w;
        }
    }
    return NULL;
}

//remouve all instances of a given char
//assume a single char input
String * String_TrimChar(String * str, const char * c){
    if (str == NULL )
        return NULL;
    
    if (str->size==0 )
        return NULL;
    
    for (int i=0; i< str->size; i++)
        if (str->str[i] == *c)
            str->str[i] = ' ';
    
    return str;
}

//extra credit
//return first token of a string
char * String_Tok ( String * str, const char * delimiters ){
    static char* temp;
    if(str != NULL) temp = str->str;
    if(temp[0] == '\0') return NULL;
    
    char *ret = temp, *b;
    const char *d;
    
    for(b = temp; *b !='\0'; b++) {
        for(d = delimiters; *d != '\0'; d++) {
            if(*b == *d) {
                *b = '\0';
                temp = b+1;
                
                if(b == ret) {
                    ret++;
                    continue;
                }
                return ret;
            }
        }
    }
    return ret;
}


//optional
//void String_InitStruct(String ** strObj){
//}

//void String_FreeStruct(String ** strObj){
//}
