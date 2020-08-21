#include "Header.h"

int main(void)
{
	FILE* infile = fopen("input.txt", "r");
	FILE* outfile = fopen("output.txt", "w");

	Employee payroll[200];

	int num = 0;

	double total = 0.0, average = 0.0, max = 0.0, min = 0.0;
	
	num = read_file(infile, payroll);
	calculate_pay(payroll, num);

	totals(payroll, num, &total, &average, &max, &min);

	fprintf(outfile, "Total: $%.2lf\n", total);
	fprintf(outfile, "Average: $%.2lf\n", average);
	fprintf(outfile, "Max: $%.2lf\n", max);
	fprintf(outfile, "Min: $%.2lf\n", min);

	fclose(infile);
	fclose(outfile);

	return 0;
}
