#include<stdlib.h>
#include<stdio.h>
#include<math.h>


Matrix cofactor(Matrix mat,int exr, int  exc)
{
	/*
		function to return cofactor matrix.
	*/
	Matrix sub;					//holds the cofactor matrix
	initialiseZero(&sub, mat.r-1, mat.c-1);	//initializing the cofactor matrix
	int subr = 0;
	int subc = 0;		//the indexes for filling the cofactor matrix
	for(int row=0;row<mat.r;row++)
	{
		for(int col = 0;col<mat.c;col++)
		{
			if(col!=exc && row!= exr)   //removing the exr->row and exc->column
			{
				sub.MatPtr[subr][subc] = mat.MatPtr[row][col];  //filling the cofactor matrix1
				subc++;        
				if(subc == mat.c-1)
				{
					subc = 0;	//increasing row count
					subr++;
				}
			}
		}
	}
	return sub;			//returning the cofactor matrix
}


float determinant(Matrix mat)
{
	/*
		function that returns the determinant.
	*/
	float det=0.0;
	if (mat.r == 2 && mat.c==2)
	{
		det = mat.MatPtr[0][0]*mat.MatPtr[1][1] - mat.MatPtr[0][1]*mat.MatPtr[1][0];    //determinant for 2x2 matrix
	}
	else
	{
		Matrix sub;		//cofactor
		int sign = 1;	//for alternating the sign
		for(int i = 0;i<mat.c;i++)
		{	
			sub = cofactor(mat,0,i);
			det += mat.MatPtr[0][i]*determinant(sub)*sign;	//determinant recursion
			sign = -sign;
		}
	}
	return det;  //returning det
}

Matrix transpose(Matrix A)
{
	/*
		The function returns transpose of a matrix
	*/
	Matrix t;

	initialiseZero(&t, A.c, A.r);

	for (int i = 0; i < t.r; i++)
	{
		for (int j = 0; j < t.c; j++)
			t.MatPtr[i][j] = A.MatPtr[j][i];   //Finding the traspose
	}

	return t;
}


Matrix adjoint(Matrix mat)
{
	/*
		The function returns adjoint of a matrix
	*/
	Matrix sub;				//cofactor matrix
	Matrix adj;				//adjoint matrix
	float det;				
	initialiseZero(&adj, mat.r, mat.c);    //init adjoint matrix
	for(int row = 0;row<mat.r;row++)
	{
		for(int col=0;col<mat.c;col++)
		{
			sub = cofactor(mat,row,col);		//getting cofactor
			det = determinant(sub);
			adj.MatPtr[row][col] = det;			//putting in adjoint
		}
	}
	adj = transpose(adj);		//transpose to get adjoint
	return adj;				//returning adjoint
}

Matrix inverse(Matrix mat)
{
	/*
	The function returns inverse of the matrix if it exists(Non singular)
	*/
	Matrix inv,adj;
	float det;
	initialiseZero(&inv,mat.r,mat.c);
	adj = adjoint(mat);			//findind the adjoint
	det  = determinant(mat);	//determinant
	if (det == 0)
	{
		printf("The matrix is singualar");    //check for singular matrix
	}
	else
	{
		inv = ScalarDiv(mat, det);       //getting the inverse
	}
	return inv;								//returning the inverse
}

