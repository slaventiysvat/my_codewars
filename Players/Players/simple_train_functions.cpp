#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
#include <intrin.h>
#include "simple_train_functions.h"
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
int multiply(int a, char* b) {
	return a * (int)* b;
}
/**************************************************************
About task in short:
Check is a word palindrome or not
function name: isPalindrom

Input parametres:
const char* str - pointer on string

Output Parametres:
1 - result is positive, 0 - rezult is negative
**************************************************************/
int isPalindrom(const char* str) {

	int len = strlen(str);

	if (len == 1) { return 1; };

	if (str[0] == toupper(str[len - 1])) {

		return 1;

	}
	else if (str[0] != toupper(str[len - 1])) {

		return 0;

	}

}
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
double arithmetic(double a, double b, const char* operator1) {

	// Your Code here!
	char swt = operator1[0];
	double rez;
	switch (swt)
	{
	case 'a':
		rez = a + b;
		break;
	case 's':
		rez = a - b;
		break;
	case 'm':
		rez = a * b;
		break;
	case 'd':
		rez = a / b;
		break;
	default:
		rez = 0;
	}

	return rez;
}
/**************************************************************
About task in short:

funnction name:

Input parametres:


Output Parametres:

**************************************************************/
bool feast(const char* beast, const char* dish) {

	// <---- hajime!
	char st1 = dish[0];
	char st2 = beast[0];
	char end1 = ' ';
	char end2 = ' ';

	while (end1 != '\0') {
		dish++;
		end1 = dish[0];
	}

	dish--;
	end1 = dish[0];

	while (end2 != '\0') {
		beast++;
		end2 = beast[0];
	}
	beast--;
	end2 = beast[0];

	return ((st1 == st2) && (end1 == end2) > 0) ? true : false;

}
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
char* create_phone_number(char phnum[15], const unsigned char nums[10])
{
	

	phnum[0] = '(';
	phnum++;
	int k = 0;
	char tmp = 0;
	while (k < 10) {

		sprintf(phnum, "%d", nums[k]);

		if (k == 2) {
			phnum++;
			phnum++;

		}

		if (k == 5) {

			phnum++;

		}

		k = k + 1;
		phnum++;
	}
	phnum = phnum - 14;
	phnum[4] = ')';
	phnum[5] = ' ';
	phnum[9] = '-';
	return phnum;
}
/**************************************************************
About task in short:

funnction name:

Input parametres:


Output Parametres:

**************************************************************/
int rgb_out_hex(int r, int g, int b, char* output)
{

	if (r < 0x0) { r = 0x0; };
	if (g < 0x0) { g = 0x0; };
	if (b < 0x0) { b = 0x0; };

	if (r > 0xFF) { r = 0xFF; };
	if (g > 0xFF) { g = 0xFF; };
	if (b > 0xFF) { b = 0xFF; };

	int array_m[10] = { 0 };
	int number[3] = { r, g, b };
	char* ptr = output;
	int counter = 0;
	int k = 0;
	int tmp = 0;
	for (int i = 0; i < 3; i++) {

		tmp = number[i];
		while (tmp != 0)
		{
			array_m[counter] = tmp % 16;
			tmp /= 16;

			++counter;
		}
		if (counter == 0) {

			array_m[0] = 0;
			array_m[1] = 0;

		}
		else if (counter < 2) {

			tmp = array_m[0];
			array_m[0] = 0;
			array_m[1] = tmp;
		}
		else {

			tmp = array_m[0];
			array_m[0] = array_m[1];
			array_m[1] = tmp;

		}
		sprintf(ptr, "%X", array_m[0]);
		ptr++;
		sprintf(ptr, "%X", array_m[1]);
		ptr++;
		counter = 0;

	}

	return 0;
}

/**************************************************************
About task in short:

funnction name:

Input parametres:


Output Parametres:

**************************************************************/
char* printerError(char* s) {
	// your code

	char len = strlen(s);
	char b = 0;
	char i = 0;

	while (s[i] != '\0') {

		if (s[i] < 'a' || s[i] > 'm')
		{
			b++;

		}

		i++;
	}

	char count = 3;

	if ((b > 9) && (len > 9)) {

		count = 6;

	}
	else if ((b > 9) && (len < 9)) {

		count = 4 + 1;

	}
	else if ((b < 9) && (len > 9)) {

		count = 4 + 1;
	}

	char* array_m = (char*)malloc(sizeof(char) * count);


	sprintf(array_m, "%d%c%d", b, '/', len);

	return array_m;
}
/**************************************************************
About task in short:
function must be reverse number
funnction name: reverse_num

Input parametres:
long long n - input number

Output Parametres:
long long output reszult
**************************************************************/
long long reverse_num(long long n) {

	long long y = 0;

	while (n)
	{
		y = y * 10 + n % 10;
		n /= 10;
	}

	return y;

}
/**************************************************************
About task in short:
Check if after mathematical operation is was a negative number
funnction name:isNegativeZero

Input parametres:
float n - input number

Output Parametres:
bool rezult
**************************************************************/
bool isNegativeZero(float n) {

	// <---- hajime!
	if (n == 0) {

		float x = 1.0;
		x = copysign(x, n);
		if (x < 0) {

			return true;

		}

	}
	return false;

}
/**************************************************************
About task in short:

funnction name:
nbYear
Input parametres:


Output Parametres:

**************************************************************/
int nbYear(int p0, double percent, int aug, int p) {
	//At the end of the first year there will be :
	//1000 + 1000 * 0.02 + 50 = > 1070 inhabitants
	//
	//At the end of the 2nd year there will be :
	//1070 + 1070 * 0.02 + 50 = > 1141 inhabitants(number of inhabitants is an integer)
	//
	//At the end of the 3rd year there will be :
	//1141 + 1141 * 0.02 + 50 = > 1213
	//
	//It will need 3 entire years.
	//nb_year(1500, 5, 100, 5000) -> 15
	int k = 0;
	while (p0 < p) {

		p0 = p0 + (p0 * percent / 100) + aug;

		k = k + 1;

	}

	return k;
}
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
int movie(int card, int ticket, double perc) {
	// your code
	/*System A : buy a ticket(15 dollars) every time
	System B : buy a card(500 dollars) and every time
	buy a ticket the price of which is 0.90 times the price he paid for the previous one.*/
	//System A : 15 * 3 = 45
	//System B : 500 + 15 * 0.90 + (15 * 0.90) * 0.90 + (15 * 0.90 * 0.90) * 0.90 (= 536.5849999999999, no rounding for each ticket)
	int n = 1;
	double System_A = 0;
	double System_B = card;

	while (1) {

		System_A = ticket * n;
		System_B = System_B + (ticket * pow(perc, n));

		if (ceil(System_B) < System_A) {

			break;

		}

		n = n + 1;

	}

	return  n;
}
/**************************************************************
About task in short:

funnction name:

Input parametres:


Output Parametres:

**************************************************************/
char* rad_ladies(const char* text) {

	//<---- hajime!
	int n = 0;
	int i = 0;
	while (text[i] != '\0') {

		if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] == ' ' || text[i] == '!')) {

			n = n + 1;

		}
		i = i + 1;
	}
	n = n + 1;
	char* submitted = (char*)malloc(sizeof(char) * n);
	char* ptr = submitted;
	n = 0;
	i = 0;
	while (text[n] != '\0') {

		if ((text[n] >= 'a' && text[n] <= 'z') || (text[n] == ' ' || text[n] == '!')) {

			sprintf(ptr, "%c", toupper(text[n]));
			ptr++;
			i = i + 1;
		}

		n = n + 1;
	}

	return submitted;
}

struct struct_date
{
	short day;
	short month;
	short year;
};

int what_day(struct_date * date)
{
	int a = (14 - date->month) / 12;
	int y = date->year - a;
	int m = date->month + 12 * a - 2;
	return (date->day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
}
/**************************************************************
About task in short:

funnction name:

Input parametres:


Output Parametres:

**************************************************************/
int unlucky_days(int year) {

	int day = 0;

	int a, y, m;
	int day_per_month[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int month = 1;
	int rez = 0;
	int unlucky = 0;
	int num_of_days = 366;

	//check leap year or not high year
	if (year % 4 != 0 || year % 100 == 0 && year % 400 != 0) {

		num_of_days = 365;
		day_per_month[1] = day_per_month[1] - 1;
	}


	for (int i = 0; i < 12; i++) {

		for (int day = 1; day <= day_per_month[i]; day++) {

			a = (14 - month) / 12;
			y = year - a;
			m = month + 12 * a - 2;
			rez = (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;

			if (rez == 5 && day == 13) {

				unlucky = unlucky + 1;

			}


		}

		month = month + 1;

	}

	return unlucky;
}
/**************************************************************
About task in short:

funnction name:

Input parametres:


Output Parametres:

**************************************************************/
int gps(int s, double* x, int sz) {

	// your code

	if (sz <= 1) {

		return (int)0;

	}

	double max = 0;
	double tmp = 0;
	for (int i = 1; i < sz; i++) {

		tmp = x[i - 1] - x[i];

		if (tmp < 0) {

			tmp = tmp * (-1);
		}

		if (max < tmp) {

			max = tmp;

		}

	}

	max = (3600 * max) / s;

	return (int)max;
}
/**************************************************************
About task in short:

funnction name:

Input parametres:


Output Parametres:

**************************************************************/
const int SIZE = 2;
int* matrix_addition(size_t n, int* matrix_a, int* matrix_b) {

	// <---- hajime!

	int* submitted = (int*)malloc(sizeof(int) * n * n);

	for (int i = 0; i < n * n; i++) {

		submitted[i] = matrix_a[i] + matrix_b[i];

	}

	return submitted;
}
/**************************************************************
About task in short:

funnction name:

Input parametres:


Output Parametres:

**************************************************************/
bool validParentheses(const char* strin) {

	// <---- hajime!
	int a = 0;
	int i = 0;
	while (strin[i] != '\0') {

		if (strin[i] == '(') {

			a++;

		}
		else if (strin[i] == ')' && --a < 0) {

			break;

		}

		i++;

	}

	return (a == 0) ? true : false;

}

#define M_PI 3.14159265358979323846
/**************************************************************
About task in short:

funnction name:

Input parametres:


Output Parametres:

**************************************************************/
char* iterPi(double epsilon) {

	// <---- hajime, nya!
	double my_pi = 0.0;
	printf("epsilon is %f", epsilon);
	int i = 0;
	double diff = 0.0;
	do {

		my_pi = my_pi + ((pow((-1.0), i)) / ((2.0 * i) + 1.0));
		diff = my_pi * 4 - M_PI;

		if (diff < 0) {
			diff = diff * (-1);
		}

		i++;
	} while (diff > epsilon);
	my_pi = my_pi * 4;
	char s[100] = { 0 };
	sprintf(s, "[%d%c%c%.10f]", i, ',', ' ', my_pi);
	return s;
}
/**************************************************************
About task in short:

funnction name:

Input parametres:


Output Parametres:

**************************************************************/
char** inArray(const char* arr1[], int sz1, const char* arr2[], int sz2, int* lg) {
	int tmp_len = 0;
	int tmp_len2 = 0;
	
	const char* f_s = 0;
	const char* t_s = 0;
	int f_of_subford = 0;
	int i = 0;
	char tmp = 0;
	int len1 = 0;
	int len2 = 0;
	int cc = 0;
	int* f_of_idx = (int*)malloc(sizeof(int) * sz1);
	for (int m = 0; m < sz1; m++) {

		t_s = arr1[m];
		len2 = strlen(t_s);
		while (cc < sz2) {

			f_s = arr2[cc];
			len1 = strlen(f_s);
			while (i < len1) {

				if (t_s[0] == f_s[i]) {

					tmp_len2 = 0;
					f_of_subford = f_of_subford + 1;
					while (tmp_len2 < len2) {

						if (t_s[tmp_len2] != f_s[i + tmp_len2]) {
							f_of_subford = f_of_subford - 1;
							break;

						}

						tmp_len2++;
					}

				}

				i++;
			}
			i = 0;
			cc++;
		}
		cc = 0;
		f_of_idx[m] = f_of_subford;
		f_of_subford = 0;
	}
	//find max value
	int max = 0;
	tmp = 0;
	int lens = 0;
	int* sort_idx = (int*)malloc(sizeof(int) * sz1);

	int len_new_str = 0;
	for (int k = 0; k < sz1; k++) {

		for (int i = 0; i < sz1; i++) {

			if (f_of_idx[i] > max) {

				max = f_of_idx[i];
				tmp = i;
			}

		}

		if (max > 0) {
			len_new_str++;

			for (int i = 0; i < sz1; i++) {

				if (f_of_idx[i] == max) {

					sort_idx[k] = i;
					f_of_idx[i] = 0;
					break;
				}

			}

		}
		else {

			sort_idx[k] = -1;

		}

		max = 0;

	}


	char** rez_array = (char**)malloc(sizeof(char) * len_new_str);
	int kk = 0;
	int real_ctn = 0;
	char m_s[100] = { 0 };
	for (int count = 0; count < sz1; count++) {

		kk = sort_idx[count];

		if (kk >= 0) {

			tmp_len = strlen(arr1[kk]) + 1;
			rez_array[real_ctn] = (char*)malloc(sizeof(char) * tmp_len);
			t_s = arr1[kk];
			strcpy(m_s, t_s);
			t_s = rez_array[real_ctn];
			strcpy((char*)t_s, m_s);
			real_ctn++;
		}


	}
	free(sort_idx);
	free(f_of_idx);
	*lg = len_new_str;
	return rez_array;
}

/*****************************************************************************
  functionname: get_free_bits

  description: analizing value on free bits

  input:pointer for output value (result) and input num,

  output:
  result value
*****************************************************************************/
int get_free_bits(long value) {
	unsigned long result = 0;
	unsigned char err;
	err = _BitScanReverse(&result, value);
	if (err) {
		return 31 - result;
	}
	else {
		return 32;
	}
}
/*****************************************************************************


/*****************************************************************************
  functionname: add_shift_division

  description: Restoring division using shift and adding

  input: dividend and divisor (num,denum)
  value alvays positive!
  output:
  division result
*****************************************************************************/
int add_shift_division(int num, int denum) {

	int maxvalue = 0x7FFFFFFF;

	if (num == denum) {

		return  maxvalue;

	}

	int k1 = 31 + 8;
	int shift1 = get_free_bits(num);
	long long int Remainder = (long long int)num;
	Remainder = Remainder << shift1 - 1;  //normalithation
	Remainder = Remainder << 8;
	long long int Divisor = denum;

	int shift2 = get_free_bits(denum);
	Divisor = Divisor << shift2 - 1;
	Divisor = Divisor << 8;
	long long int Quotient = 0x0;

	while (k1 > 0) {
		/*Subtract the Divisor
		register from the Remainder
		register and place them result
		in the Remainder register*/
		Remainder = Remainder - Divisor;
		// Test Remainder
		if (Remainder >= 0) {
			/*Shift the Quotient register
			to the left, setting the
			new rightmost bit to 1;*/
			Quotient = Quotient + 0x00000001;
		}

		if (Remainder < 0) {
			/*Restore the original value by adding
			the Divisor register to the Remainder register
			and place the sum in the Remainder register.
			Also shift the Quotient register to the left,
			setting the new least significant bit to 0.*/
			Remainder = Remainder + Divisor;
			Quotient = Quotient + 0x00000000;
		}
		Quotient = Quotient << 1;
		// Shift the Divisor register right 1 bit

		Divisor = Divisor >> 1;
		k1 = k1 - 1;
	}
	shift1 = shift1 - shift2;
	Quotient = Quotient >> shift1 + 8;

	return Quotient;
}