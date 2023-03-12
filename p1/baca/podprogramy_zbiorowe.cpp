#include <iostream>

using namespace std;

void Sort(int n, int T[]) {
	int h = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (T[j] > T[j + 1]) {
				h = T[j];
				T[j] = T[j + 1];
				T[j + 1] = h;
			}
		}
	}
}

void Add(int a, int T[]) {
	int i = 0;
	bool d = false;
	
	
	if (a >= 1 && a <= 4095) {
		do {
		if (T[i] == a) {
			d = true;
			break;
		}
		
		i++;
		} while (T[i - 1] != -1);
	
	
		if (d == false) {
			i = 0;
			
			do {
				if (T[i] == -1) {
					T[i] = a;
					T[i + 1] = -1;
					break;
				}
				
				i++;
			} while (T[i - 1] != -1);
			
			Sort(i + 1, T);
		}
	}
}

void Create(int n, int createT[], int T[]) {
	int i = 0;
	int j = 0;
	int k = 0;
	bool d = false;
	
	for (i = 0; i < n; i++) {
		d = false;
		
		for (j = i; j < n; j++) {
			if (i != j) {
				if (createT[i] == createT[j]) 
				{
					d = true;
					break;
				}
			}
		}
		
		if (d == false && createT[i] >= 1 && createT[i] <= 4095) {
			T[k] = createT[i];
			k++;
		}
	}
	
	T[k] = -1;
	Sort(k, T);
}

void Complement(int oneT[], int T[]) {
	int i = 0;
	int j = 0;
	int k = 0;
	bool d = true;
	
	for (i = 1; i <= 4095; i++) {
		j = 0;
		d = true;

		do {
			if (oneT[j] == i) {
				d = false;

				break;
			}
			
			j++;
		} while (oneT[j - 1] != -1);
		
		if (d == true) {
			T[k] = i;
			k++;
		}
	}
	
	T[k] = -1;
	
	Sort(k, T);
}

void Union(int oneT[], int twoT[], int T[]) {
	int i = 0;
	int j = 0;
	int k = 0;
	bool d = false;
	
	do {
		if (oneT[i] >= 1 && oneT[i] <= 4095) {
			T[k] = oneT[i];
			
			k++;
		}
		
		i++;
	} while (oneT[i - 1] != -1);
	
	T[k] = -1;
	
	i = 0;
	
	do {
		if (twoT[i] >= 1 && twoT[i] <= 4095) {
			
			j = 0;
			d = false;
			
			do {
				if (twoT[i] == T[j]) {
					d = true;

					break;
				}
				
				j++;
			} while (T[j - 1] != -1);
			
			if (d == false) {
				T[k] = twoT[i];
				
				k++;
				
				T[k] = -1;
			}
		}
		
		i++;
	} while (twoT[i - 1] != -1);

	Sort(k, T);
}

void Intersection(int oneT[], int twoT[], int T[]) {
	int i = 0;
	int j = 0;
	int k = 0;
	
	do {
		if (oneT[i] < 1 || oneT[i] > 4095) 
		{
			i++;
			continue;
		}
		
		j = 0;
		
		do {
			if (oneT[i] == twoT[j]) {
				T[k] = oneT[i];
				k++;
				break;
			}
			
			j++;
		} while (twoT[j - 1] != -1);
		
		i++;
	} while (oneT[i - 1] != -1); 
	
	T[k] = -1;
	
	Sort(k, T);
}

void Difference(int oneT[], int twoT[], int T[]) {
	int i = 0;
	int j = 0;
	int k = 0;
	bool o = false;
	
	do {
		if (oneT[i] >= 1 && oneT[i] <= 4095) {
			j = 0;
			o = false;
			do {
				if (oneT[i] == twoT[j]) {
					o = true;
					break;
				}
				
				j++;
			} while (twoT[j - 1] != -1);
			
			if (o == false) {
				T[k] = oneT[i];

				k++;
			}
		}
		
		i++;
	} while (oneT[i - 1] != -1);
	
	T[k] = -1;
	Sort(k, T);
}

void Symmetric(int oneT[], int twoT[], int T[]) {
	int i = 0;
	int j = 0;
	int k = 0;
	bool o = false;
	
	do {
		if (oneT[i] >= 1 && oneT[i] <= 4095) {
			j = 0;
			o = false;
			do {
				if (oneT[i] == twoT[j]) {
					o = true;
					break;
				}
				
				j++;
			} while (twoT[j - 1] != -1);
			
			if (o == false) {
				T[k] = oneT[i];

				k++;
			}
		}
		
		i++;
	} while (oneT[i - 1] != -1);
	
	i = 0;
	j = 0;
	o = false;
	
	do {
		if (twoT[i] >= 1 && twoT[i] <= 4095) {
			j = 0;
			o = false;
			do {
				if (twoT[i] == oneT[j]) {
					o = true;
					break;
				}
				
				j++;
			} while (oneT[j - 1] != -1);
			
			if (o == false) {
				T[k] = twoT[i];

				k++;
			}
		}
		
		i++;
	} while (twoT[i - 1] != -1);
	
	T[k] = -1;
	Sort(k, T);
}

bool Subset(int oneT[], int twoT[]) {
	int i = 0;
	int j = 0;
	bool z = true;
	do {
		if (oneT[i] >= 1 && oneT[i] <= 4095) {
			z = false;
			j = 0;
			
			do {
				if (oneT[i] == twoT[j]) z = true;
				
				j++;	
			} while (twoT[j - 1] != -1);
		}
		
		if (z == false) return false;
		
		i++;
	} while (oneT[i - 1] != -1);
	
	return true;
}

int main() {
	int oneT[10] = {2, 3, 5, -1}; 
	int twoT[10] = {4, 2, 3, 5, -1};
	
	cout << Subset(oneT, twoT) << endl;
	
	return 0;
}

bool Equal(int oneT[], int twoT[]) {
	int i = 0;
	int j = 0;
	int l = 0;
	
	do {		
		i++;
	} while (oneT[i - 1] != -1);
	
	do {		
		j++;
	} while (twoT[j - 1] != -1);
	
	if (i != j) return false;
	
	i = 0;
	j = 0;
	
	do {
		j = 0;
		l = 0;
		
		do {
			if (oneT[i] == twoT[j]) l = 1;
			
			j++;
		} while (twoT[j - 1] != -1);
		
		if (l == 0) return false;
		
		i++;
	} while (oneT[i - 1] != -1);
	
	return true;
}

bool Empty(int T[]) {
	if (T[0] == -1) return true;
	else return false;
}

bool Nonempty(int T[]) {
	if (T[0] == -1) return false;
	else return true;
}

bool Element(int a, int T[]) {
	int i = 0;
	
	if (a < 1 || a > 4095) return false;
	
	do {
		cout << T[i] << endl;
		if (T[i] == a) return true;
		i++;
	} while (T[i - 1] != -1);
	
	return false;
}

double Arithmetic(int T[]) {
	if (Empty(T) == true) return 0;
	
	double m = 0;
	int i = 0;	
	
	do {
		m += T[i];
		
		i++;
	} while	(T[i] != -1);
	
	return m / i;
}

double Harmonic(int T[]) {
	if (Empty(T) == true) return 1;
	
	double m = 0;
	int i = 0;
	
	do {
		m += (1. / T[i]);
		
		i++;
	} while	(T[i] != -1);
	
	return i / m;
}

void MinMax(int T[], int* min, int& max) {
	int i = 0;
	
	if (Empty(T) == false) {
		*min = T[0];
		max = T[0];
		
		do {
			if (T[i] >= 1 && T[i] <= 4095) {
				if (T[i] < *min) *min = T[i];
				if (T[i] > max) max = T[i];	
			}
			
			i++;
		} while (T[i] != -1);
	}
}

void Cardinality(int T[], int* p) {
	int i = 0;
	*p = 0;
	
	if (Empty(T) == false) {
		do {
			*p = *p + 1;
			
			i++;
		} while (T[i] != -1);
	}
}

void Properties(int T[], char C[], double& mArithmetic, double* mHarmonic, int& min, int* max, int& p) {
	int i = 0;
	
	while (C[i] != '\0') {
		if (C[i] == 'a') mArithmetic = Arithmetic(T);
		if (C[i] == 'h') *mHarmonic = Harmonic(T);
		if (C[i] == 'm') MinMax(T, &min, *max);
		if (C[i] == 'c') Cardinality(T, &p);
		
		i++;
	}
}





