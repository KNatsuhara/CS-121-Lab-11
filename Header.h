#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct employee
{
	char name[100];
	char title;
	double hours_worked;
	double payrate;
	double payment;
} Employee;

int read_file(FILE* infile, Employee payroll[]);
void calculate_pay(Employee payroll[], int num);
void totals(Employee payroll[], int num, double* p_total, double* p_average, double* p_max, double* p_min);

