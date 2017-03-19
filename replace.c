
/* replace: replaces all occurances of a character in an array */
int replace(char *in, char to, char from)
{
	(*in == from) ? (*in = to) : 0;
	return (*in) ? replace(in + 1, to, from) : 0;
}
