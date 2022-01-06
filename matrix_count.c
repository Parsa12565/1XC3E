/**
 * @file matrix_count.c
 * @author Parsa Zanganeh
 * @date April 17th, 2021.
 * @brief To count the number of instances of integers in a 2d matrix.
 * 
 */
#include <stdio.h>

/**
 * Counts the number of instances of integers in a 2d matrix.
 * 
 * @param check A list of integers, the intances of which will be counted in the 2d matrix.
 * @param count The array in which the number of instances will be stored.
 * @param length The length of both check and count.
 * @param matrix A 2d Matrix of size M x N filled with integers.
 * 
 */
void matrix_count(int *check,int *count,int length,int **matrix)
{
	for(int i=0;i<length;i++)
	{
		count[i]=0;
		for(int j=0;j<M;j++)
		{
			for(int k=0;k<N;k++)
			{
				if(matrix[j][k]==check[i])
				{
					count[i]++;
				}
			}
		}
	}
}