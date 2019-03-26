#include<stdlib.h>
#include<stdio.h>
#include <math.h>


float fMax(Matrix A)
{
	float max = A.MatPtr[0][0];

	for(int i = 0; i< A.r; i++)
	{
		for(int j = 0; j<A.c; j++)
		{
			if(A.MatPtr[i][j] > max)
				max = A.MatPtr[i][j];
		}
	}

	return max;

}


float fMin(Matrix A)
{
	float min = A.MatPtr[0][0];

	for(int i = 0; i< A.r; i++)
	{
		for(int j = 0; j<A.c; j++)
		{
			if(A.MatPtr[i][j] < min)
				min = A.MatPtr[i][j];
		}
	}

	return min;

}



Matrix maxMat(Matrix mat, int axis)
{
    Matrix max_mat;
    if(axis == 0)
    {
        initialiseZero(&max_mat, 1, mat.c);
        float cmax;
        for(int i = 0; i<mat.c;i++)
        {
            cmax = mat.MatPtr[i][0];

            for(int j=0;j<mat.r;j++)
            {
                if(mat.MatPtr[j][i] > cmax)
                	cmax = mat.MatPtr[j][i];
            }
            max_mat.MatPtr[0][i] = cmax;
        }
    }
    else
    {
        initialiseZero(&max_mat, mat.r, 1);
        float rmax;
        for(int i = 0; i<mat.r;i++)
        {
            rmax = mat.MatPtr[0][i];
            for(int j=0;j<mat.c;j++)
            {
                if(mat.MatPtr[i][j] > rmax)
                	rmax = mat.MatPtr[i][j];
            }
            max_mat.MatPtr[i][0] = rmax;
        }
    }
    return max_mat;
}



Matrix minMat(Matrix mat, int axis)
{
    Matrix min_mat;
    if(axis == 0)
    {
        initialiseZero(&min_mat, 1, mat.c);
        float cmin;
        for(int i = 0; i<mat.c;i++)
        {
            cmin = mat.MatPtr[i][0];

            for(int j=0;j<mat.r;j++)
            {
                if(mat.MatPtr[j][i] < cmin)
                	cmin = mat.MatPtr[j][i];
            }
            min_mat.MatPtr[0][i] = cmin;
        }
    }
    else
    {
        initialiseZero(&min_mat, mat.r, 1);
        float rmin;
        for(int i = 0; i<mat.r;i++)
        {
            rmin = mat.MatPtr[0][i];
            for(int j=0;j<mat.c;j++)
            {
                if(mat.MatPtr[i][j] < rmin)
                	rmin = mat.MatPtr[i][j];
            }
            min_mat.MatPtr[i][0] = rmin;
        }
    }
    return min_mat;
}




Matrix sumMat(Matrix mat, int axis)
{
    Matrix sum_mat;
    if(axis == 0)
    {
        initialiseZero(&sum_mat, 1, mat.c);
        float csum = 0.0;
        for(int i = 0; i<mat.c;i++)
        {
            csum = 0.0;
            for(int j=0;j<mat.r;j++)
            {
                csum += mat.MatPtr[j][i];
            }
            sum_mat.MatPtr[0][i] = csum;
        }
    }
    else
    {
        initialiseZero(&sum_mat, mat.r, 1);
        float rsum = 0.0;
        for(int i = 0; i<mat.r;i++)
        {
            rsum = 0.0;
            for(int j=0;j<mat.c;j++)
            {
                rsum += mat.MatPtr[i][j];
            }
            sum_mat.MatPtr[i][0] = rsum;
        }
    }
    return sum_mat;
}


float fsum(Matrix mat)
{
    float s;
    for(int i = 0;i<mat.r;i++)
    {
        for(int j = 0;j<mat.c;j++)
        {
            s += mat.MatPtr[i][j];
        }
    }
    return s;
}



Matrix meanMat(Matrix mat, int axis)
{
    Matrix mean_mat;
    if(axis == 0)
    {
        initialiseZero(&mean_mat, 1, mat.c);
        float csum = 0.0;
        for(int i = 0; i<mat.c;i++)
        {
            csum = 0.0;
            for(int j=0;j<mat.r;j++)
            {
                csum += mat.MatPtr[j][i];
            }
            mean_mat.MatPtr[0][i] = csum/mat.r;
        }
    }
    else
    {
        initialiseZero(&mean_mat, mat.r, 1);
        float rsum = 0.0;
        for(int i = 0; i<mat.r;i++)
        {
            rsum = 0.0;
            for(int j=0;j<mat.c;j++)
            {
                rsum += mat.MatPtr[i][j];
            }
            mean_mat.MatPtr[i][0] = rsum/mat.c;
        }
    }
    return mean_mat;
}


Matrix stdMat(Matrix mat, int axis)
{
    Matrix std_mat,mean_mat;
    if(axis == 0)
    {
        initialiseZero(&std_mat, 1, mat.c);
        mean_mat = meanMat(mat, axis =0);
        float csum = 0.0;
        for(int i = 0; i<mat.c;i++)
        {
            csum = 0.0;
            for(int j=0;j<mat.r;j++)
            {
                csum += pow((mean_mat.MatPtr[0][i] - mat.MatPtr[j][i]),2);
            }
            std_mat.MatPtr[0][i] = csum/mat.r;
        }
    }
    else
    {
        initialiseZero(&std_mat, mat.r, 1);
        mean_mat = meanMat(mat, axis =1);
        float rsum = 0.0;
        for(int i = 0; i<mat.r;i++)
        {
            rsum = 0.0;
            for(int j=0;j<mat.c;j++)
            {
                rsum += pow((mean_mat.MatPtr[i][0]-mat.MatPtr[i][j]),2);
            }
            std_mat.MatPtr[i][0] = rsum/mat.c;
        }
    }
    std_mat = powMat(std_mat,0.5);
    return std_mat;
}
