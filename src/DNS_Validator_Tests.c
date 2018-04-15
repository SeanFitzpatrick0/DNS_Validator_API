/*!
 * @file DNS_Validator_Test.c
 * @brief Used to test the API funtions
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "DNS_Validator.h"

int main(){
    //checking valid names
    printf("***\tTesting checkDNSValid\t***\n");
    char validDNS[][100] = {    "www.tcd.ie",
                                "www.tcd.ie.",
                                ".",
                                "www.tcd.xn--5",
                                "www.tcd.xn---",
                                "www.xn--_",
                                ".",
                                "www.tcd.xn--5."
                                };
    size_t i = 0;
    for( i = 0; i < sizeof(validDNS) / sizeof(validDNS[0]); i++)
    {
        if(!checkDNSValid(validDNS[i])){
            printf("ERROR: %s is a valid DNS but failed.\n",validDNS[i]);
        }
        else{
            printf("SUCCESS: %s is a valid DNS and passed.\n",validDNS[i]);
        }
    }
    //checking invalid names
    char invalidDNS[][300] = {  "",
                                "www.tcd.ie5",
                                "www..ie","www.*.ie",
                                "www.reallyLonglabel-----------------------------------------------------.ie",
                                "www.tcd.reallyLonglabel-----------------------------------------------------",
                                ".www.tcd.ie",
                                "realy long DNS-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"
                                };
    for( i = 0; i < sizeof(invalidDNS) / sizeof(invalidDNS[0]); i++)
    {
        if(checkDNSValid(invalidDNS[i])){
            printf("ERROR: %s is a invalid DNS but passed.\n",invalidDNS[i]);
        }
        else{
            printf("SUCCESS: %s is a invalid DNS and failed.\n",validDNS[i]);
        }
    }
    //NULL Test
    if(checkDNSValid(NULL)){
        printf("ERROR: NULL is invalid DNS but passed.\n");
    }
    else{
        printf("SUCCESS: NULL DNS is invalid failed.\n");
    }

    //compareDNSNames
    printf("***\tTesting compareDNSNames\t***\n");
    char sameDNS[][300] = {     "www.tcd.ie",
                                "www.tcd.ie."
                                };
    for( i = 0; i < sizeof(sameDNS) / sizeof(sameDNS[0]); i++)
    {
        if(!compareDNSNames(sameDNS[0],sameDNS[i])){
            printf("ERROR: %s and %s are the same DNS but failed.\n",sameDNS[0],sameDNS[i]);
        }
        else{
            printf("SUCCESS: %s and %s are the same DNS and passed.\n",sameDNS[0],sameDNS[i]);
        }
    }
    char differentDNS[][300] = {    "www.tcd.ie",
                                    "www.tcd.ief.",
                                    "www.tcf.ie"
                                };
    for( i = 1; i < sizeof(differentDNS) / sizeof(differentDNS[0]); i++)
    {
        if(!compareDNSNames(differentDNS[0],differentDNS[i])){
            printf("SUCCESS: %s and %s are different DNS and failed.\n",differentDNS[0],differentDNS[i]);
        }
        else{
            printf("ERROR: %s and %s are the different DNS but passed.\n",differentDNS[0],differentDNS[i]);
        }
    }
}

