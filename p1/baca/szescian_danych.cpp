#include <iostream>

using namespace std;

void subMatrix(int matrix[32][32], int matrixSub[32][32], int col, int length) {
	int temp = 0;
	
	for(int i = 0; i < length; i++) {
		
        temp = 0;
        
        for(int j = 0; j < length; j++){
            if (col != j) {
                matrixSub[i][j - temp] = matrix[i + 1][j];
            } 
			else {
                temp = 1;
            }
        }
    }
}

long long int detMatrix(int matrix[32][32], int length){
	int matrixSub[32][32];
	long long int det = 0;
	int temp = 0;
	int multiplier = 1;
	
    if (length == 1) {
        return matrix[0][0];
    } 
	else {
        for(int i = 0; i < length; i++) {
        	
			subMatrix(matrix, matrixSub, i, length);
			
			if (matrix[0][i] != 0) 
			{
				det = det + (multiplier * matrix[0][i] * detMatrix(matrixSub, length - 1));
			}
			
			multiplier = multiplier * -1;
        }
        
        return det;
    }
}

int columnSame(int matrix[32][32], int length) {
	int sameColumn = 0;
	
	for (int i = 0; i < length - 1; i++) {
		sameColumn = 0;
		
		for (int j = i  + 1; j < length; j++) {
			sameColumn = 0;
			
			for (int k = 0; k < length; k++) {
				if (matrix[k][i] == matrix[k][j]) sameColumn++;	
			}
			if (sameColumn == length) break;
		}
		if (sameColumn == length) break;
	}
	
	return sameColumn;
}

int rowSame(int matrix[32][32], int length) {
	int sameRow = 0;
	
	for (int i = 0; i < length - 1; i++) {
		sameRow = 0;
		
		for (int j = i  + 1; j < length; j++) {
			sameRow = 0;
			
			for (int k = 0; k < length; k++) {
				if (matrix[i][k] == matrix[j][k]) sameRow++;	
			}
			if (sameRow == length) break;
		}
		if (sameRow == length) break;
	}
	
	return sameRow;
}

void readMatrix(int array[32][32][32], int matrix[32][32], int length, int n, char dim) {
	if (dim == 'l') {
		for (int i = 0; i < length; i++) {
			for (int k = 0; k < length; k++) {
				matrix[i][k] = array[n][k][i];
			}
		}
	}
	else if (dim == 'v') {
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < length; j++) {
				matrix[i][j] = array[j][n][i];
			}
		}
	}
	else if (dim == 'p') {
		for (int j = 0; j < length; j++) {
			for (int k = 0; k < length; k++) {
				matrix[j][k] = array[j][k][n];
			}
		}
	}
}

int oneEighthSquareInCube(int array[32][32][32], int length, int l, int v, int p, int r) {
	int sum = 0;
				
	int lTurn = 0;
	int vTurn = 0;
	int pTurn = 0;
	int lTwo = 0;
	int vTwo = 0;
	int pTwo = 0;
	
	if (l < length / 2) lTurn = 1;
	else lTurn = -1;
	
	if (v < length / 2) vTurn = 1;
	else vTurn = -1;
	
	if (p < length / 2) pTurn = 1;
	else pTurn = -1;

	for (int i = 0; i <= r; i++) {
		for (int j = 0; j <= r; j++) {
			for (int k = 0; k <= r; k++) {
				lTwo = lTurn * j + l;
				vTwo = vTurn * k + v;
				pTwo = pTurn * i + p;
				
				if (lTwo >= 0 && lTwo < length) {
					if (vTwo >= 0 && vTwo < length) {
						if (pTwo >= 0 && pTwo < length) {
							if (j * j + k * k + i * i <= r * r) {
								sum = sum + array[lTwo][vTwo][pTwo];
							}
						}
					}
				}
			}
		}
	}
	
	return sum;
}

int tetrahedronInCube(int array[32][32][32], int length, int l, int v, int p, int e) {
	int sum = 0;
	
	int lTurn = 0;
	int vTurn = 0;
	int pTurn = 0;
	int lTwo = 0;
	int vTwo = 0;
	int pTwo = 0;
	
	if (l < length / 2) lTurn = 1;
	else lTurn = -1;
	
	if (v < length / 2) vTurn = 1;
	else vTurn = -1;
	
	if (p < length / 2) pTurn = 1;
	else pTurn = -1;

	for (int i = 0; i <= e; i++) {
		for (int j = 0; j <= e - i; j++) {
			for (int k = 0; k <= e - i - j; k++) {
				lTwo = lTurn * j + l;
				vTwo = vTurn * k + v;
				pTwo = pTurn * i + p;
				
				if (lTwo >= 0 && lTwo < length) {
					if (vTwo >= 0 && vTwo < length) {
						if (pTwo >= 0 && pTwo < length) {
							sum = sum + array[lTwo][vTwo][pTwo];
						}
					}
				}
			}
		}
	}
	
	return sum;
}

int cuboidInCube(int array[32][32][32], int length, int l, int v, int p, int h, int w, int d) {
	int sum = 0;
	
	int lTurn = 0;
	int vTurn = 0;
	int pTurn = 0;
	int lTwo = 0;
	int vTwo = 0;
	int pTwo = 0;
	
	if (l < length / 2) lTurn = 1;
	else lTurn = -1;
	
	if (v < length / 2) vTurn = 1;
	else vTurn = -1;
	
	if (p < length / 2) pTurn = 1;
	else pTurn = -1;

	for (int i = 0; i <= d; i++) {
		for (int j = 0; j <= h; j++) {
			for (int k = 0; k <= w; k++) {
				lTwo = lTurn * j + l;
				vTwo = vTurn * k + v;
				pTwo = pTurn * i + p;
				
				if (lTwo >= 0 && lTwo < length) {
					if (vTwo >= 0 && vTwo < length) {
						if (pTwo >= 0 && pTwo < length) {
							sum = sum + array[lTwo][vTwo][pTwo];
						}
					}
				}
			}
		}
	}
	
	return sum;
}

void readArray(int array[32][32][32], int length) {
	for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            for (int k = 0; k < length; k++) {
                cin >> array[j][k][i];
            }
        }
    }
}

int main()
{
	int array[32][32][32];
	int length = 0;
	int sum = 0;
	
	int matrix[32][32];
	int n = 0;
	long long int det = 0;
	
	int i = 0;
	int j = 0;
	int k = 0;
	
	int l = 0;
	int v = 0;
	int p = 0;
	int h = 0;
	int w = 0;
	int d = 0;
	
	int e = 0;
	
	int r = 0;
	
	char choice;
	char dim;
	
    cin >> length;
    
    readArray(array, length);
	
	while (choice != 'E') {
		
		cin >> choice;
		
		switch(choice) {
			case 'C': {
				cin >> l >> v >> p >> h >> w >> d;
				
				cout << cuboidInCube(array, length, l, v, p, h, w, d) << endl;
				
				break;
			}
			
			case 'T': {
				cin >> l >> v >> p >> e;
				
				cout << tetrahedronInCube(array, length, l, v, p, e) << endl;
				
				break;
			}
			
			case 'O': {
				cin >> l >> v >> p >> r;
				
				cout << oneEighthSquareInCube(array, length, l, v, p, r) << endl;
				
				break;
			}
				
			case 'D': {
				cin >> dim >> n;
				
				readMatrix(array, matrix, length, n, dim);
				
				int sameRow = rowSame(matrix, length);
				int sameColumn = 0;	
				
				
				if (sameRow != length) {
					sameColumn = columnSame(matrix, length);	
				}
				
				if (sameRow != length && sameColumn != length) {
					det = detMatrix(matrix, length);	
				}
				
				cout << det << endl;
				
				break;	
			}
			
			default: {
				break;
			}
		}	
	}
	
    return 0;
}
