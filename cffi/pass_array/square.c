/* Square each element of an array and store the output 
   in another array of the same size */
void square(double *input, double *output, int len)
{
  for(int i=0; i<len; i++)
    {
      output[i] = input[i]*input[i];
    } 
}
