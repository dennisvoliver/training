
double raise(double num, int power)
{
	int i;
	for(i = 0; i < power; i++)
		num *= num;
	if(power > 0)
		return num;
	else if(power < 0)
		return 1/num;
	else
		return 1;
}
