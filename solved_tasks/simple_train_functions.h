#ifndef SIMPLE_TRAIN_FUNCTION
#define SIMPLE_TRAIN_FUNCTION

//Description about all situation
//Some simple functions which i made on Codewars platform.
//Here you can find some solutions on Codewars tasks. Levels 8ku, 7ku, 6ku, 5ku.
//                                  <-Hajime!

/**************************************************************
About task in short:
In this small function need to try fix
problem when one of pointers has a another type
function name: multiply

Input parametres:
int a
char* b

Output Parametres:
rezult of multiply two numbers
**************************************************************/
int multiply(int a, char* b);

/**************************************************************
About task in short:
Check is a word palindrome or not
function name: isPalindrom

Input parametres:
const char* str - pointer on string

Output Parametres:
1 - result is positive, 0 - rezult is negative
**************************************************************/
int isPalindrom(const char* str);
/**************************************************************
About task in short:
Create a function which will be do arithmetic operations on numbers
funnction name: arithmetic

Input parametres:
double a, - first operand
double b, -secound operand
const char* operator1 - the operator who switches operations
on numbers ( 'a' - 'add','s' - 'subsrtact',
'm' - 'multiply', 'd' - 'divide')

Output Parametres:
double rez - rezult after operation
**************************************************************/
double arithmetic(double a, double b, const char* operator1);

/**************************************************************
About task in short:

funnction name:

Input parametres:


Output Parametres:

**************************************************************/
bool feast(const char* beast, const char* dish);

/**************************************************************
About task in short:
you have input array, from this array you must ctreate
a phone number like this "(123) 456-7890 "
funnction name:

Input parametres:
cahr* phnum - output phone number
const unsigned char* nums  - input array of numbers

Output Parametres:
pointer on output array
**************************************************************/

char* create_phone_number(char phnum[15], const unsigned char nums[10]);


/**************************************************************
About task in short:

funnction name:

Input parametres:


Output Parametres:

**************************************************************/

int rgb_out_hex(int r, int g, int b, char* output);

/**************************************************************
About task in short:

funnction name:

Input parametres:


Output Parametres:

**************************************************************/
char* printerError(char* s);

/**************************************************************
About task in short:
function must be reverse number
funnction name: reverse_num

Input parametres:
long long n - input number

Output Parametres:
long long output reszult
**************************************************************/
long long reverse_num(long long n);

/**************************************************************
About task in short:
Check if after mathematical operation is was a negative number
funnction name:isNegativeZero

Input parametres:
float n - input number

Output Parametres:
bool rezult
**************************************************************/

bool isNegativeZero(float n);

/**************************************************************
About task in short:

funnction name:
nbYear
Input parametres:


Output Parametres:

**************************************************************/

int nbYear(int p0, double percent, int aug, int p);

/**************************************************************
About task in short:
System A : buy a ticket(15 dollars) every time
System B : buy a card(500 dollars) and every time
buy a ticket the price of which is 0.90 times the price he paid for the previous one.
System A : 15 * 3 = 45
System B : 500 + 15 * 0.90 + (15 * 0.90) * 0.90 + (15 * 0.90 * 0.90) * 0.90 (= 536.5849999999999, no rounding for each ticket)
funnction name:
movie
Input parametres:
int card - prise of card
int ticket -  prise of ticket
double perc -
Output Parametres:

**************************************************************/

int movie(int card, int ticket, double perc);

/**************************************************************
About task in short:

funnction name:

Input parametres:


Output Parametres:

**************************************************************/

char* rad_ladies(const char* text);

/**************************************************************
About task in short:

funnction name:

Input parametres:


Output Parametres:

**************************************************************/

int unlucky_days(int year);

/**************************************************************
About task in short:

funnction name:

Input parametres:


Output Parametres:

**************************************************************/

int gps(int s, double* x, int sz);

/**************************************************************
About task in short:

funnction name:

Input parametres:


Output Parametres:

**************************************************************/

int* matrix_addition(size_t n, int* matrix_a, int* matrix_b);

/**************************************************************
About task in short:

funnction name:

Input parametres:


Output Parametres:

**************************************************************/

bool validParentheses(const char* strin);

/**************************************************************
About task in short:

funnction name:

Input parametres:


Output Parametres:

**************************************************************/

char* iterPi(double epsilon);

/**************************************************************
About task in short:

funnction name:

Input parametres:


Output Parametres:

**************************************************************/

char** inArray(const char* arr1[], int sz1, const char* arr2[], int sz2, int* lg);

/*****************************************************************************
  functionname: get_free_bits

  description: analizing value on free bits

  input:pointer for output value (result) and input num,

  output:
  result value
*****************************************************************************/

int get_free_bits(long value);

/*****************************************************************************


/*****************************************************************************
  functionname: add_shift_division

  description: Restoring division using shift and adding

  input: dividend and divisor (num,denum)
  value alvays positive!
  output:
  division result
*****************************************************************************/

int add_shift_division(int num, int denum);

#endif // !SIMPLE_TRAIN_FUNCTION

