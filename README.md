# DNS_Validator_API
Contains functions for validating and comparing DNS names 

## Whats here:
- include->   DNS_Validator.h (This is the header file used for function definitions)\n
- src->       DNS_Validator.c	(Contains source code for API functions)
              DNS_Validator_Tests.c	(Testing for functions. See here for example uses)
              Makefile  (Used for comiling files)
              obj->   (Contains the object files)
            
## Setup:
To start clone this repo.
```
git clone https://github.com/SeanFitz1997/DNS_Validator_API.git
```
Then go to src and compile the files
```
cd src
make
```
To run the tests
```
./DNS_Tests
```
Expected output:
```
***     Testing checkDNSValid   ***
SUCCESS: www.tcd.ie is a valid DNS and passed.
SUCCESS: www.tcd.ie. is a valid DNS and passed.
SUCCESS: . is a valid DNS and passed.
SUCCESS: www.tcd.xn--5 is a valid DNS and passed.
SUCCESS: www.tcd.xn--- is a valid DNS and passed.
SUCCESS: www.xn--_ is a valid DNS and passed.
SUCCESS: . is a valid DNS and passed.
SUCCESS: www.tcd.xn--5. is a valid DNS and passed.
SUCCESS: www.tcd.ie is a invalid DNS and failed.
SUCCESS: www.tcd.ie. is a invalid DNS and failed.
SUCCESS: . is a invalid DNS and failed.
SUCCESS: www.tcd.xn--5 is a invalid DNS and failed.
SUCCESS: www.tcd.xn--- is a invalid DNS and failed.
SUCCESS: www.xn--_ is a invalid DNS and failed.
SUCCESS: . is a invalid DNS and failed.
SUCCESS: www.tcd.xn--5. is a invalid DNS and failed.
SUCCESS: NULL DNS is invalid failed.
***     Testing compareDNSNames ***
SUCCESS: www.tcd.ie and www.tcd.ie are the same DNS and passed.
SUCCESS: www.tcd.ie and www.tcd.ie. are the same DNS and passed.
SUCCESS: www.tcd.ie and www.tcd.ief. are different DNS and failed.
SUCCESS: www.tcd.ie and www.tcf.ie are different DNS and failed.
```
## API Functions:
```
int checkDNSValid(char *str);
```
Determines if a given DNS is valid. Takes a null-terminated string and returns 
1: If valid/true, 
0: If invalid/false 
A DNS name is valid if it meets the following:
- Consists of a sequence of labels separated by the dot ".".
- Labels must be between 1 and 63 charcaters long.
- The overall name including dot characters must be less than 255 characters.
- May have a trailing dot (e.g. "www.tcd.ie." is valid).
- A name consisting of only a dot "." is valid (This is the root of the DNS nameing tree).
  No other names beging with a dot are valid.
- Valid label characters are digits(0-9), letters(A-Z) upper or lower, or a dash "-" or underscore "_" character.
- The last lable in the name (ignoring the trailing dot) may not contain a dash (“-”), underscore (“_”) or any digits, 
  unless it starts with the string "xn--" (for internationalised top-level domain names).
