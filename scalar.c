#include <stdio.h>
#include <stdlib.h>
#include <math.h>


Matrix ScalarDiv(Matrix mat,float scalar)
{
	Matrix divmat;
	initialiseZero(&divmat,mat.r,mat.c);
	
	if (scalar==0)
	{
		printf("division by zero is invalid\n");
	}
	else
	{
		for (int i=0;i<mat.r;i++)
		{
			for(int j=0;j<mat.c;j++)
			{
				divmat.MatPtr[i][j]=(mat.MatPtr[i][j])/scalar;
			}
		}
	}

	return divmat;
}



Matrix ScalarMul(Matrix mat,float scalar)
{
	Matrix mulmat;
	initialiseZero(&mulmat,mat.r,mat.c);
	
	for (int i=0;i<mat.r;i++)
	{
		for(int j=0;j<mat.c;j++)
		{
			mulmat.MatPtr[i][j]=(mat.MatPtr[i][j])*scalar;
		}
	}
	return mulmat;
}



Matrix ScalarAdd(Matrix mat,float scalar)
{
	Matrix addmat;
	initialiseZero(&addmat,mat.r,mat.c);
	for (int i=0;i<mat.r;i++)
	{
		for(int j=0;j<mat.c;j++)
		{
			addmat.MatPtr[i][j]=(mat.MatPtr[i][j])+scalar;
		}
	}
	return addmat;
}


Matrix ScalarSub(Matrix mat,float scalar)
{
	Matrix subtmat;
	initialiseZero(&subtmat,mat.r,mat.c);
	
	
	for (int i=0;i<mat.r;i++)
	{
		for(int j=0;j<mat.c;j++)
		{
			subtmat.MatPtr[i][j] = (mat.MatPtr[i][j])-scalar;
		}
	}
	return subtmat;
}


Matrix ScalarMod(Matrix mat, int n)
{
    Matrix mmat;
    initialiseZero(&mmat, mat.r, mat.c);
    if(n != 0)
    {   
        for(int i=0;i<mat.r;i++)
        {
            for(int j=0;j<mat.c;j++)
            {
                mmat.MatPtr[i][j] = fmod(mat.MatPtr[i][j],n);
            }
        }
        return mmat;
    }
    else
    {
    	printf("zero division");
        return mmat;
    }
}