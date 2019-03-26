Matrix cramer(Matrix A,Matrix B)
{ Matrix X;
	initialiseZero(&B,A.c,1);
	X=matMul(inverse(A),B);
	return X;
}