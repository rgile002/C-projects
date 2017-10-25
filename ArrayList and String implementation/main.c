//
//
//  HW#1
//
//  Created by Rolf Kinder Gilet  ID 5734407 on 6/30/17.
//  Copyright © 2017 Rolf Kinder Gilet. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include "String.h"
#include "globalconst.h"
#include "ArrayList.h"
//#include "LinkedList.h"
//#include "Hashmap.h"


int String_EqualN(String * lhs, String * rhs,size_t n)
{
    for (int i = 0; i < n; i++)
        if (lhs->str[i] != rhs->str[i])
            return 0;
    
    return 1;
}


int main(int argc, char **argv)
{
    printf("*************************************************************************\n");
    printf( "*\t\t\t\t\t\t\t\tHW1\t\t\t\t\t\t\t\t\t\t*\n");
    printf( "*\t\t\t\t\t\tRolf Kinder Gilet\t\t\t\t\t\t\t\t*\n");
    printf( "*\t\t\t\t\t\t\t  5734407\t\t\t\t\t\t\t\t\t*\n");
    printf("*************************************************************************\n");
    
    //memory allocation
    String *s1 = (String *) malloc(sizeof (String)); String *s2 = (String *) malloc(sizeof (String));
    String *s3 = (String *) malloc(sizeof (String)); String *s4 = (String *) malloc(sizeof (String));
    String *s5 = (String *) malloc(sizeof (String)); String *s6 = (String *) malloc(sizeof (String));
    String *s7 = (String *) malloc(sizeof (String)); String *s8 = (String *) malloc(sizeof (String));
    String *s9 = (String *) malloc(sizeof (String));String *s10 = (String *) malloc(sizeof (String));
    String *s11 = (String *) malloc(sizeof (String));String *s12 = (String *) malloc(sizeof (String));
    String *s13 = (String *) malloc(sizeof (String));String *s14 = (String *) malloc(sizeof (String));
    String *s15 = (String *) malloc(sizeof (String));String *s16 = (String *) malloc(sizeof (String));
    String *s17 = (String *) malloc(sizeof (String));String *s18 = (String *) malloc(sizeof (String));
    String *s19 = (String *) malloc(sizeof (String));String *s20 = (String *) malloc(sizeof (String));
    String *s21 = (String *) malloc(sizeof (String));String *s22 = (String *) malloc(sizeof (String));
    String *s23 = (String *) malloc(sizeof (String));String *s24 = (String *) malloc(sizeof (String));
    String *s25 = (String *) malloc(sizeof (String));String *s26 = (String *) malloc(sizeof (String));
    String *s27 = (String *) malloc(sizeof (String));String *s28 = (String *) malloc(sizeof (String));
    String *s29 = (String *) malloc(sizeof (String));
    
    
    //Appendix A
    printf("\n");
    printf("\t\t\t\t\t\tAPPENDIX A DRIVER\n");
    printf("\n ");
    
    // String_Append test
    printf("==>String_Append Test\n");
    String *s1a = (String *) malloc(sizeof (String));
    String_New(s1a, "Miami ");
    char * ab = "Florida";
    printf("BEFORE String_APPEND s1 is: %s\n", s1a->str);
    String_Append(s1a,ab);
    printf("AFTER String_APPEND s1 is: %s\n", s1a->str);
    free(s1a);
    
    //String_Cpy() test
    //Copy the source string to the destination string test
    String_New(s1, "Miami Florida");
    String_New(s2, "");
    String_New(s3, "Something");
    printf("\n");
    printf("==>String_Copy Test\n");
    printf("String s1 BEFORE String_Copy: %s\nString s2 BEFORE String_Copy: %s\nString s3 BEFORE String_Copy: %s\n", s1->str,s2->str,s3->str);
    String_Cpy(s2, s1);
    String_Cpy(s3, s1);
    printf("\n");
    printf("String s1 AFTER String_Copy: %s\nString s2 AFTER String_Copy: %s\nString s3 AFTER String_Copy: %s\n", s1->str,s2->str,s3->str);
    if (s1->size == s2->size && s1->size== s3->size){
        printf("*THE PROCESS SUCCEEDED*\n");
    }else printf("*THE PROCESS FAILED*\n");
    
    //String_Cpy() test
    //Copy empty source string to the destination string  test (should not copy)
    printf("\n");
    printf("==>String_Copy Test WITH EMPTY SOURCE\n");
    String_New(s4, "");
    String_New(s5, "Something");
    printf("String s1 BEFORE String_Copy: %s\nString s2 BEFORE String_Copy: %s\n", s4->str,s5->str);
    String_Cpy(s5, s4);
    String_Cpy(NULL, s5);
    printf("\n");
    printf("String s1 AFTER String_Copy: %s\nString s2 AFTER String_Copy: %s\n", s4->str, s5->str);
    if (s4->size != s5->size){
        printf("*THE PROCESS SUCCEEDED*\n");
    }else printf("*THE PROCESS FAILED*\n");
    
    //String_nCpy() test
    //Copy N first characters from source string to destination String
    printf("\n");
    printf("==>String_nCopy Test\n");
    String_New(s6, "Miami Florida");
    String_New(s7, "");
    String_New(s8, "Something");
    printf("String s1 BEFORE String_nCopy: %s\nString s2 BEFORE String_nCopy: %s\nString s3 BEFORE String_nCopy: %s\n", s1->str,s7->str,s8->str);
    String_nCpy(s7, s6,5);
    String_nCpy(s8, NULL,8);
    String_nCpy(s8, s6,8);
    printf("\n");
    printf("String s1 AFTER String_nCopy: %s\nString s2 AFTER String_nCopy: %s\nString s3 AFTER String_nCopy: %s\n", s6->str,s7->str,s8->str);
    if (s8->size ==8 && s7->size==5){
        printf("*THE PROCESS SUCCEEDED*\n");
    }else printf("*THE PROCESS FAILED*\n");
    
    
    //String_Cat() test
    //Appends a copy of the source string to the destination string
    printf("\n");
    printf("==>String_Cat Test\n");
    String_New(s9, "Miami ");
    String_New(s10, "Florida");
    String_New(s11, "");
    printf("String s1 BEFORE String_Cat: %s\nString s2: %s\n", s9->str,s10->str);
    int s1initialL= (int)s9->size;
    String_Cat(s9, s10);
    String_Cat(s11, NULL);
    String_Cat(s11, s9);
    printf("\n");
    printf("AFTER String_Cat with s2 String s1 is: %s\n", s9->str);
    if (s9->size == s1initialL + (int)s10->size){
        printf("*THE PROCESS SUCCEEDED *\n");
    }else printf("*THE PROCESS FAILED*\n");
    
    
    //String_nCat() test
    //Appends the first num characters of source to destination
    printf("\n");
    printf("==>String_nCat Test\n");
    String_New(s11, "Miami ");
    String_New(s12, "Florida");
    String_New(s13, "");
    printf("String s1 BEFORE String_nCat: %s\nString s2: %s\n", s11->str,s12->str);
    int s1initL= (int)s11->size;
    String_nCat(s11, s12,2);
    String_nCat(s13, NULL,2);
    String_nCat(s13, s11,5);
    printf("\n");
    printf("AFTER String_nCat with s2 String s1 is: %s\n", s11->str);
    if (s11->size == s1initL + 2){
        printf("*THE PROCESS SUCCEEDED *\n");
    }else printf("*THE PROCESS FAILED*\n");
    
    //String_Cmp() test
    //Compare 2 strings
    printf("\n");
    printf("==>String_Cmp Test\n");
    String_New(s14, "Miami");
    String_New(s15, "Florida");
    String_New(s16, "Miami");
    printf("String s1: %s\nString s2: %s\nString s3: %s\n", s14->str,s15->str,s16->str);
    printf("\n");
    if (String_Cmp(s14, s15)){
        printf("- String s1 EQUAL String s2\n");
    }else printf("- String s1 NOT EQUAL String s2\n");
    if (String_Cmp(s16, s14)){
        printf("- String s1 EQUAL String s3\n");
    }else printf("- String s1 NOT EQUAL String s2\n");
    
    //String_nCmp() test
    //Compare 2 strings up to N characters
    printf("\n");
    printf("==>String_nCmp Test\n");
    String_New(s17, "Miami");
    String_New(s18, "Miami Florida");
    String_New(s19, "Florida Miami");
    printf("String s1: %s\nString s2: %s\nString s3: %s\n", s17->str,s18->str,s19->str);
    printf("\n");
    int n=5; // number of char you want to compare
    if (String_nCmp(s17, s18,n)){
        printf("- String s1 EQUAL String s2 up to %d Char\n",n);
    }else printf("- String s1 NOT EQUAL String s2 up to %d Char\n",n);
    if (String_nCmp(s3, s19,n)){
        printf("- String s1 EQUAL String s3 up to %d Char\n",n);
    }else printf("- String s1 NOT EQUAL String s2 up to %d Char\n",n);
    
    //String_Chr() test
    //Returns a pointer to the first occurrence of character in the C string str
    printf("\n");
    printf("==>String_Chr Test\n");
    String_New(s20,"This is a sample string");
    String * p;
    printf ("Looking for the first occurence of the 'a' character in: \n%s \n",s20->str);
    p=String_Chr(s20,'a');
    if (p != NULL){
        printf ("Result: %s \n", p->str);
    }
    
    //String_cSpn() test
    //The length of the initial part of str1 not containing any of the characters that are part of str2
    printf("\n");
    printf("==>String_cSpn Test\n");
    String_New(s21,"This is a sample string");
    String_New(s22, "ibcm");
    printf("-String s1: %s\n-String s2: %s\n", s21->str,s22->str);
    printf ("The length of the initial part of s1 not containing any of the characters that are part of s2 is: %d \n",(int)String_cSpn(s21,s22));
    
    //String_pBrk() test
    //Returns a pointer to the first occurrence in str1 of any of the characters that are part of str2
    printf("\n");
    printf("==>String_pBrk Test\n");
    String_New(s23,"This is a sample string");
    String_New(s24, "bacm");
    printf("-String s1: %s\n-String s2: %s\n", s23->str,s24->str);
    String * p1=0;
    p1=String_pBrk(s23,s24);
    if (p1 != NULL){
        printf ("The first occurence of any Char from s2 in s1 is: %s \n",(char*)p1);
    } else  printf ("There is no occurence of any Char from s2 in s1\n");
    
    //String_rChr() test
    //Returns a pointer to the last occurrence of character in the C string str
    printf("\n");
    printf("==>String_rChr Test\n");
    String_New(s25,"This is a sample string");
    printf("-String s1: %s\n", s25->str);
    char * p2;
    p2=(char*)String_rChr(s25,'i');
    if (p2 != NULL){
        printf ("The last occurence of Char 'i' from s1 is: %s \n", p2);
    }else  printf ("There is no occurence of any Char from s2 in s1\n");
    
    //String_spn() test
    //Returns the length of the initial portion of str1 which consists
    //only of characters that are part of str2
    printf("\n");
    printf("==>String_spn Test\n");
    String_New(s26,"This is a sample string");
    String_New(s27, "ibh Tscm");
    printf("-String s1: %s\n-String s2: %s\n", s26->str,s27->str);
    printf ("The length of the initial part of s1 containing only characters that are part of s2 is: %d \n",(int)String_spn(s26,s27));
    
    //String_Str() test
    //Returns a pointer to the first occurrence of str2 in str1
    printf("\n");
    printf("==>String_Str Test\n");
    String_New(s28,"Miami Florida 33351");
    String_New(s29, "Florida");
    printf("-String s1: %s\n-String s2: %s\n", s28->str,s29->str);
    char * p3;
    p3=(char*)String_Str(s28,s29);
    if (p3 != NULL){
        printf ("The substring of s1 contains the string s2: %s \n", p3);
    }else  printf ("There is no occurence of any Char from s2 in s1\n");
    
    
    //String_Len() test
    //Returns the length of the C string str
    printf("\n");
    printf("==>String_Len Test\n");
    String_New(s1,"Miami");
    printf("-String s1: %s\n", s1->str);
    printf ("The string s1 lenght is: %d \n", (int)String_Len(s1));
    
    
    //free memory
    free(s1); free(s2); free(s3); free(s4); free(s5); free(s6); free(s7); free(s8); free(s9);
    free(s10);free(s11);free(s12);free(s13);free(s14);free(s15);free(s16);free(s17);free(s18);
    free(s19);free(s20);free(s21);free(s22);free(s23);free(s24);free(s25);free(s26);free(s27);
    free(s28);free(s29);
  
    printf("\n ");
    printf("*************************************************************************\n");
    
    //memory allocation
    String *a = (String *) malloc(sizeof (String)); String *b = (String *) malloc(sizeof (String));
    String *c = (String *) malloc(sizeof (String)); String *d = (String *) malloc(sizeof (String));
    String *e = (String *) malloc(sizeof (String)); String *f = (String *) malloc(sizeof (String));
    String *g = (String *) malloc(sizeof (String)); String *h = (String *) malloc(sizeof (String));
    String *k = (String *) malloc(sizeof (String)); String *l = (String *) malloc(sizeof (String));
    String *m = (String *) malloc(sizeof (String)); String *o = (String *) malloc(sizeof (String));
    String *r = (String *) malloc(sizeof (String)); String *q = (String *) malloc(sizeof (String));
    
    
    //Appendix B
    printf("\n");
    printf("\t\t\t\t\t\tAPPENDIX B DRIVER\n");
    printf("\n ");
    
    //String_GetHashCode() test
    //Returns the Hash Code of a string
    printf("\n");
    printf("==>GetHashCode Test\n");
    String_New(a,"miami");
    printf("String s1 actual Hash Code: 210720697842\n");
    printf("String s1 String_GetHashCode result: %zu\n",String_GetHashCode(a));
    
    //String_Trim() test
    //Trim left and right spaces at the end of the string
    printf("\n");
    printf("==>String_Trim Test\n");
    String_New(b,"   Miami   ");
    printf("-String s1 BEFORE String_Trim: %s* \n",b->str);
    printf("-String s1 AFTER String_Trim: %s* \n",(char*)String_Trim(b));
    
    //String_LTrim() test
    //Trim left spaces at the end of the string
    printf("\n");
    printf("==>String_LTrim Test\n");
    String_New(c,"   Miami   ");
    printf("-String s1 BEFORE String_LTrim: %s* \n",c->str);
    printf("-String s1 AFTER String_LTrim: %s* \n",(char*)String_LTrim(c));
    
    //String_RTrim() test
    //Trim right spaces at the beginning of the string
    printf("\n");
    printf("==>String_RTrim Test\n");
    String_New(c,"   Miami   ");
    printf("-String s1 BEFORE String_RTrim: %s* \n",c->str);
    printf("-String s1 AFTER String_RTrim: %s* \n",String_RTrim(c)->str);
    
    //String_GetCharFromIndex() test
    //return char from index
    printf("\n");
    printf("==>String_GetCharFromIndex Test\n");
    String_New(d,"Miami Florida");
    printf("String s1: %s \n",d->str);
    //the char array index start at 0
    printf("Char at index %d from String s1 is: %c\n",2,(int)String_GetCharFromIndex(d,2));
    
    //String_IndexOfChar() test
    //return index of char
    printf("\n");
    printf("==>String_IndexOfChar Test\n");
    String_New(e,"Miami Florida");
    printf("String s1: %s \n",e->str);
    //the char array index start at 0
    printf("The first occurence of char 'a' in s1 is at index: %d\n",String_IndexOfChar(e,'a'));
    
    //String_Lower() test
    printf("\n");
    printf("==>String_Lower Test\n");
    String_New(f,"MIAMI FLORIDA");
    printf("The string s1: %s \n", f->str);
    printf("The string s1 to lower case: %s\n", String_Lower(f)->str);
    
    //String_Upper() test
    printf("\n");
    printf("==>String_Upper Test\n");
    String_New(g,"miami florida");
    printf("The string s1: %s \n", g->str);
    printf("The string s1 to upper case: %s\n", String_Upper(g)->str);
    
    //String_Reverse() test
    //reverse string
    printf("\n");
    printf("==>String_Reverse Test\n");
    String_New(h,"0123456789");
    printf("The string s1: %s \n", h->str);
    printf("The string s1 reverse: %s\n", String_Reverse(h)->str);
    
    //String_WordCount() test
    //return the num of words in string
    printf("\n");
    printf("==>String_WordCount Test\n");
    String_New(k,"Hello Programming 3    Class");
    printf("The string s1: %s \n", k->str);
    printf("The number of word in s1 is: %d\n", (int)String_WordCount(k));
    
    //String_StartsWith() test
    //returns a substring of a string that starts with X
    printf("\n");
    printf("==>String_StartsWith Test\n");
    String_New(l,"Hello Programming 3    Class");
    String_New(m,"Progra");
    printf("The string s1: %s \n", l->str);
    printf("The string s2: %s \n", m->str);
    printf("The substring of s1 that start with s2 is: %s\n", String_StartsWith(l,m)->str);
    
    //String_TrimChar() test
    //remove all occurences of given char
    printf("\n");
    printf("==>String_TrimChar Test\n");
    String_New(r,"Hello Programming 3 Class");
    printf("The string s1: %s \n", r->str);
    char cs = 'a';
    char * cr = &cs;
    printf("s1 AFTER trim char 'a': %s\n", String_TrimChar(r,cr)->str);
    
    printf("\n ");
    printf("*************************************************************************\n");
    
    //Appendix C
    printf("\n");
    printf("\t\t\t\t\t\tAPPENDIX C DRIVER\n");
    printf("\n ");
    
    //String_Tok() test
    //extra credit
    //return all token of a string test
    printf("\n");
    printf("==>String_Tok Test\n");
    String_New(o,"- Hello Programming 3 Class.");
    char * ch;
    printf ("Splitting string \"%s\" into tokens:\n",o->str);
    ch = String_Tok(o," ,.-");
    while (ch != NULL)
    {
        printf ("%s\n",ch);
        ch = String_Tok(NULL, " ,.-");
    }
    
    //free memory
    free(a); free(b); free(c); free(d); free(e); free(f); free(g); free(h); free(k);
    free(l);free(m);free(r);free(o);free(q);
    
    printf("\n ");
    printf("*************************************************************************\n");
    
    //Array List
    printf("\n ");
    printf("\t\t\t\t\t\tARRAY LIST DRIVER\n");
    printf("\n ");
    
    //Arrayist_Get() test
    printf("\n");
    printf("==>Arrayist_New Test\n");
    ArrayList * strListA = (ArrayList *) malloc(sizeof(ArrayList));
    ArrayList * strListB = (ArrayList *) malloc(sizeof(ArrayList));
    boolean checkList = ArrayList_New(strListA);
    boolean checkList2 = ArrayList_New(strListB);
    
    if (!checkList || !checkList2){
        printf("Error initializing arraylists\n");
    }else printf("THE CREATION PROCESS SUCCEEDED\n");
    
    //ArrayList_Add
    for (int i = 0; i < 150; i++){
        String * str = (String *)malloc(sizeof(String));
        String * str2 = (String *)malloc(sizeof(String));
        String_New(str, "Programming 3");
        String_New(str2,"Programming 4");
        ArrayList_Add(strListA,str);
        ArrayList_Add(strListB,str2);
    }
    
    //Arrayist_Get() test
    printf("\n");
    printf("==>Arrayist_Get Test\n");
    //index start at 0
    String * str1 =  (String *) ArrayList_Get(strListA,100);
    String * str2 =  (String *) ArrayList_Get(strListB,149);
    printf("List 1 element at index 100 = %s \nList 2 element at index 149 = %s\n", str1->str,str2->str);
    
    //ArrayList_Copy() test
    printf("\n");
    printf("==>ArrayList_Copy Test\n");
    ArrayList_Copy(strListB,strListA);
    str1 =  (String *) ArrayList_Get(strListA,100);
    str2 =  (String *) ArrayList_Get(strListB,149);
    printf("After copy List 1 element at index 100 = %s \nList 2 element at index 149 = %s\n", str1->str,str2->str);
    
    
    //ArrayList_Clear() test
    printf("\n");
    printf("==>ArrayList_Clear and Compact Test\n");
    printf("Before clear (B): Size = %zu, Reserved = %zu \n",strListB->size,strListB->reserved);
    // does compact
    ArrayList_Clear(strListB);
    printf("After clear (B): Size = %zu, Reserved = %zu \n",strListB->size,strListB->reserved);
    
    
    //ArrayList_ExpandReserved() test
    printf("\n");
    printf("==>ArrayList_ExpandReserved Test\n");
    printf("Before expand reserved (B): Size = %zu, reserved = %zu \n",strListB->size,strListB->reserved);
    ArrayList_ExpandReserved(strListB, 400);
    printf("After expand reserved (B) by 400: Size = %zu, reserved = %zu \n",strListB->size,strListB->reserved);
    
    
    //ArrayList_Set() test
    printf("\n");
    printf("==>ArrayList_Set Test\n");
    String * strSet = (String *)malloc(sizeof(String));
    String_New(strSet,"Programming 3 Class");
    String * st2 = (String *)malloc(sizeof(String));
    String_New(st2,"Programming 4");
    ArrayList_Add(strListB,st2);
    String * sp= (String *) ArrayList_Get(strListB,0);
    printf ("BEFORE Set  index 0 contains : %s \n",sp->str);
    ArrayList_Set(strListB, 0, strSet);
    String * strSetPrint= (String *) ArrayList_Get(strListB,0);
    if (strSetPrint !=NULL){
        printf ("AFTER Set index 0  contains: %s\n \n",strSetPrint->str);
    }
    
    //ArrayList_RemoveLast() test
    printf("\n");
    printf("==>ArrayList_RemoveLast and Remove Test\n");
    printf("Before RevomeLast (A): Size = %zu, reserved = %zu \n",strListA->size,strListA->reserved);
    ArrayList_RemoveLast(strListA);
    printf("After RevomeLast (A): Size = %zu, reserved = %zu \n",strListA->size,strListA->reserved);
    ArrayList_Remove(strListA, 10);
    printf("After Revome at index 0 (A): Size = %zu, reserved = %zu \n",strListA->size,strListA->reserved);
    
    //free memory
    free(strListB);
    free(strListA);
    
    
    
    
    return 1;
}

