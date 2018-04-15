/*!
 * @file DNS_Validator.h
 * @brief Defines functions
 */

/*!
* @brief: Determines if a given DNS is valid 
* @input: A pointer to the DNS name as a null-terminated string. 
* @return: 1: If valid/true, 0: If invalid/false 
*/
int checkDNSValid(char *str);

/*! 
* @brief: Determines if a given DNS label is valid. 
* This is as helper function for checkDNSValid and 
* is not recommended to be used on its own. 
* @input: A pointer to the start of the DNS label within 
* the full name as a null-terminated string. 
* @return: 1: If valid/true, 0: If invalid/false 
*/
int checkDNSlabelValid(char *str);

/*! 
* @brief: Determines if 2 DNS names are the same. 
* If either DNS are invalid it will return False 
* @input: A pointer to the 1st DNS name as a null-terminated string. 
* @input: A pointer to the 2nd DNS name as a null-terminated string. 
* @return: 1: If same/true, 0: If different/false 
*/
int compareDNSNames(char *str1, char *str2);
