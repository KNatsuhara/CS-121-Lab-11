#include "Header.h"

int read_file(FILE* infile, Employee payroll[])
{
	int i = 0;
	double empty = 0;
	while (!feof(infile))
	{
		fgets(payroll[i].name, 100, infile);
		fscanf(infile, "%c ", &payroll[i].title);
		fscanf(infile, "%lf ", &payroll[i].hours_worked);
		fscanf(infile, "%lf ", &payroll[i].payrate);
		//fscanf(infile, "%lf", &empty);
		//fscanf(infile, "%lf", &empty);
		i++;
	}
	return i;
}

void calculate_pay(Employee payroll[], int num)
{
	for (int i = 0; i < num; i++)
	{
		if (payroll[i].hours_worked < 80)
		{
			payroll[i].payment = payroll[i].payrate * payroll[i].hours_worked;
		}
		else
		{
			if (payroll[i].title == 'M')
			{
				payroll[i].payment = (payroll[i].payrate * 80) + (payroll[i].payrate * 1.8 * (payroll[i].hours_worked - 80));
			}
			else
			{
				payroll[i].payment = (payroll[i].payrate * 80) + (payroll[i].payrate * 1.5 * (payroll[i].hours_worked - 80));
			}
		}
	}
}

void totals(Employee payroll[], int num, double* p_total, double* p_average, double* p_max, double* p_min)
{
	double total = 0.0, average = 0.0;
	double max = payroll[0].payment, min = payroll[0].payment;

	for (int i = 0; i < num; i++)
	{
		total += payroll[i].payment;
		if (max < payroll[i].payment)
		{
			max = payroll[i].payment;
		}
		if (min > payroll[i].payment)
		{
			min = payroll[i].payment;
		}
	}

	*p_total = total;
	*p_average = total / num;
	*p_max = max;
	*p_min = min;
}