/*!
 * @file DNS_Validator.c
 * @brief Contains the API functions
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "DNS_Validator.h"

/*! * @brief: Determines if a given DNS is valid * @input: A pointer to the 
DNS name as a null-terminated string. * @return: 1: If valid/true, 0: If 
invalid/false */ int checkDNSValid(char *str) {
    //NULL check
    if(str==NULL){
        return 0; //False
    }
    //Check overall length
    if(strlen(str)<1||strlen(str)>255){
        return 0; //False
    }
    //Check if root DNS
    if(str[0]=='.'&& strlen(str)==1){
        return 1; //True
    }
    //Split DNS into labels
    char *dot=str;
    if(checkDNSlabelValid(dot)==0){
            return 0; //False
    }
    dot=strchr(str, '.');
    while(dot!=NULL){
        dot+=sizeof(char);
        if(checkDNSlabelValid(dot)==0){
            return 0; //false
        }
        dot=strchr(dot, '.');
        //check for trailing dot
        if(dot!=NULL&&strlen(dot)==1){
            break;
        }
    }
    //Passed all tests
     return 1; //true
}
/*! * @brief: Determines if a given DNS label is valid. * This is as helper 
function for checkDNSValid and * is not recommended to be used on its own. 
* @input: A pointer to the start of the DNS label within * the full name as 
a null-terminated string. * @return: 1: If valid/true, 0: If invalid/false 
*/ int checkDNSlabelValid(char *str) {
    char *res = strchr(str, '.');
    int labelLen;
    //Check if last label
    if(res==NULL){ //Last label
        char* internatDNS = "xn--";
        //Check if label starts with international encoding
        if(memcmp(str,internatDNS,strlen(internatDNS))!=0){ //Dosnt contain international encoding
            	//Checking if contains invalid chars
                if((strchr(str,'-'))&&(strchr(str,'_'))){ //Contains invalid char
                    return 0; //False
                }
                char * temp =str;
                while(*temp){ //check if last label contains a digit
                    if(isdigit(*temp)){
                        return 0; //False
                    }
                    temp+=sizeof(char);
                }
        }
        labelLen=strlen(str); //length of last label
    }
    else{ //Not last label
        labelLen=(strlen(str)-strlen(res)); //length of non last label
    }
    //Checking label length
    if(labelLen<1||labelLen>63){
        return 0; //False
    }
    //Check if chars in label are valid
    for(char* pos = str; pos!=str+(labelLen*sizeof(char)) 
;pos+=sizeof(char)){ //iterate throgh each char in label
        if((!isalpha(*pos))&&(!isdigit(*pos))&&(*pos!='-')&&(*pos!='_')){
            return 0; //False
        }
    }
    return 1; //True
}
/*! * @brief: Determines if 2 DNS names are the same. * If either DNS are 
invalid it will return False * @input: A pointer to the 1st DNS name as a 
null-terminated string. * @input: A pointer to the 2nd DNS name as a 
null-terminated string. * @return: 1: If same/true, 0: If different/false 
*/ int compareDNSNames(char *str1, char *str2){
    //Check if valid
    if(!checkDNSValid(str1)||!checkDNSValid(str2)){
        return 0; //false
    }
    //length check
    if(strlen(str1)!=strlen(str2)&&abs(strlen(str1)-strlen(str2))!=1){
        return 0; //false
    }
    char temp [strlen(str1)+1]; //Used to resize a DNS with trailing dot
    //same length
    if(strlen(str1)==strlen(str2)){
        if(strcasecmp(str1,str2)==0){
            return 1; //True
        }
        return 0; //False
    }
    //str1 has trailing dot
    else if(strlen(str1)>strlen(str2)){
        strncpy(temp,str1,strlen(str1)-1); //Remove trailing dot
        temp[strlen(temp)-1]='\0'; //null-terminate
        //Check if same
        if(strcasecmp(temp,str2)){
            return 0; //False
        }
    }
    //str2 has trailing dot
    else{
        strncpy(temp,str2,strlen(str2)-1); //remove trailing dot
        temp[strlen(temp)-1]='\0'; //null-terminate
        //Check if same
        if(strcasecmp(temp,str1)){
            return 0; //False
        }
    }
    return 1; //True
}
