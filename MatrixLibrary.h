typedef struct{
	int r;																		//Number of rows
	int c;																		//Number of columns	
	float **MatPtr;																//Pointer to the matrix.
} Matrix;

void initialiseZero(Matrix *a, int row, int column);
void initialiseOne(Matrix *a, int row, int column);
void initialiseRandom(Matrix *a, int row, int column);
void printMatrix(Matrix n);
void readMatrix(Matrix a);
Matrix indentity(int n);
Matrix vector(float a, float b, float c);
void delMatrix(Matrix A);
bool isSymmetric(Matrix a);
bool isAntisymmetric(Matrix a);
bool isInvolutary(Matrix a);
bool compareMatrices(Matrix a, Matrix b);
bool isIdempotent(Matrix a);
Matrix ScalarDiv(Matrix mat,float scalar);
Matrix ScalarMul(Matrix mat,float scalar);
Matrix ScalarAdd(Matrix mat,float scalar);
Matrix ScalarSub(Matrix mat,float scalar);
Matrix ScalarMod(Matrix mat, int n);
Matrix floorMat(Matrix mat);
Matrix powMat(Matrix mat, float p);
Matrix absMat(Matrix mat);
Matrix logMat(Matrix mat);
Matrix ceilMat(Matrix mat);
Matrix sinMat(Matrix mat);
Matrix cosMat(Matrix mat);
Matrix tanMat(Matrix mat);
Matrix alogMat(Matrix mat);
Matrix asinMat(Matrix mat);
Matrix acosMat(Matrix mat);
Matrix atanMat(Matrix mat);
Matrix addMatrices(Matrix A, Matrix B);
Matrix subMatrices(Matrix A, Matrix B);
Matrix mulMatrices(Matrix A, Matrix B);
Matrix divMatrices(Matrix A, Matrix B);
Matrix matMul(Matrix A, Matrix B);
Matrix cofactor(Matrix mat,int exr, int  exc);
float determinant(Matrix mat);
Matrix transpose(Matrix A);
Matrix adjoint(Matrix mat);
Matrix inverse(Matrix mat);
float fMax(Matrix A);
float fMin(Matrix A);
Matrix maxMat(Matrix mat, int axis);
Matrix minMat(Matrix mat, int axis);
Matrix sumMat(Matrix mat, int axis);
float fsum(Matrix mat);
Matrix meanMat(Matrix mat, int axis);
Matrix stdMat(Matrix mat, int axis);
Matrix cramer(Matrix A,Matrix B);

