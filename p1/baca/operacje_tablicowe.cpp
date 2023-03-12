#include <iostream>

using namespace std;

int main() 
{
    int i = 0;
    int j = 0;
    int I = 0;
    int J = 0;
    int K = 0;
    int M = 0;
    int s = 0;
    
	int h = 0;
	int h2 = 0;
	int u = 0;
	int g = 0;
	int l = 0;
	int k = 0;
	
	int ind = 0;
	int ind2 = 0;
	int dl = 0;
	int p1 = 0;
	int p2 = 0;
	int p3 = 0;
	int dl2 = 0;
	
	char instr;
	
    cin >> i;

    while (s < i) {
        j = 0;

        cin >> j;
		
        int T[j];
        
        I = 0;

        while (I < j) {
            cin >> T[I];

            I = I + 1;
        }
        
        I = 0;
        
        while (I < j) {
            cout << T[I] << " ";

            I = I + 1;
        }
        
        cout << endl;
        
        I = 0;
        
		instr = 'A';
		
		while (instr != 'F') {
			cin >> instr;
			
			if (instr != 'F') cin >> ind >> dl;
	

            while (ind < 0) {
                ind += j;
            }

            while (ind >= j) {
                ind -= j;
            }
            
            u = 0;
            
            if (dl < 0) {
            	dl = dl * -1;
            	u = -1;
			}
			
			g = 0;
			
            if (instr == 'R' && dl != 0) {
				g = (j - (j % dl))/dl;
				
				I = 0;
				J = 0;
				
				while (I < g) {
					p1 = ind;
					if (ind + dl > j - 1) ind = dl - (j - ind);
					else ind = ind + dl;		
					
					J = 0;
					
					dl2 = dl - 1;
					if (dl > 1) {
						while (J < dl/2) {
							if (p1 + dl2 > j - 1) p2 = dl2 - (j - p1);
							else p2 = p1 + dl2;
							
							h = T[p1];
							T[p1] = T[p2];
							T[p2] = h;
							
							if (p1 + 1 > j - 1) p1 = 0;
							else p1 = p1 + 1;
							
							dl2 -= 2;
							
							J = J + 1;
						}	
					}
					I = I + 1;
				}
            }
            else if (instr == 'M') {
                int przes = 0;
				int przes2 = 0;
				
                cin >> przes;
  				
				przes2 = przes;              
                
                if (dl > j) dl = j;
                
                if (dl > 0 && dl <= j) {
					
					g = (j - (j % dl))/dl;
					if (j % dl != 0) g = g + 1;
					
					I = 0;
					J = 0;
					l = 0;
					k = 0;
					K = 0;
					
					while (I < g) {
						ind2 = ind;
						if (ind + dl > j - 1) ind = dl - (j - ind);
						else ind = ind + dl;
						
						l = l + dl;
						if (l > j) k = j % dl;
						else k = dl;
						
						przes = przes2;
						
						while (przes >= k) {
	                	przes -= k;
		            	}
		            	while (przes < 0) {
		                	przes += k;
		            	}
						
						M = 0;
						
						while (M < przes) {
							K = 0;
							
							if (ind2 + k - 1 > j - 1) K = (ind2 + k - 1) - j;
							else K = ind2 + k - 1;
							
							J = K - 1;
							
							if (K - 1 < 0) J = j - 1;
							else J = K - 1;
							
							h = T[K];
							
							int k2 = k;
							
							while (k2 - 1 > 0) {
								T[K] = T[J];
								
								if (K - 1 < 0) K = j - 1;
								else K = K - 1;
								
								if (J - 1 < 0) J = j - 1;
								else J = J - 1;
								
								k2 = k2 - 1;
							}
							
							T[K] = h;
							
							M = M + 1;
						}
						
						I = I + 1;
					}	
				}
            }
            else if (instr == 'C' && dl != 0) {
				g = (j - j % (dl * 2)) / (dl * 2);
				I = 0;
				J = 0;
				
				while (I < g) {
					if (dl >= 1) {
						p1 = ind;
						if (ind + 2 * dl > j - 1) ind = (2 * dl) - (j - ind);
						else ind = ind + (2 * dl);		
						
						if (p1 + dl > j - 1) p2 = dl - (j - p1);
						else p2 = p1 + dl;
						
						J = 0;
						
						while (J < dl) {
							h = T[p1];
							T[p1] = T[p2];
							T[p2] = h;
							
							if (p1 + 1 > j - 1) p1 = 0;
							else p1 = p1 + 1;
							if (p2 + 1 > j - 1) p2 = 0;
							else p2 = p2 + 1;
							
							J = J + 1;
						}	
					}
					
					I = I + 1;
				}
            }
            else if (instr == 'S' && dl != 0) {
            	g = (j - (j % dl))/dl;
				if (j % dl != 0) g = g + 1;
				
				I = 0;
				J = 0;
				l = 0;
				k = 0;

				while (I < g) {
					p1 = ind;
					if (ind + dl > j - 1) ind = dl - (j - ind);
					else ind = ind + dl;	
					p3 = p1;
					
					l = l + dl;
					if (l > j) k = j % dl;
					else k = dl;
					
					if (u == 0) {
						
						J = 0;
						
						while (J < k - 1) {
							K = 0;					
							
							p1 = p3;
							if (p1 + 1 > j - 1) p2 = 0;
							else p2 = p1 + 1;
							
							while (K < k - 1) {
								if (T[p1] > T[p2]) {
									h = T[p2];
									T[p2] = T[p1];
									T[p1] = h;
								}
								
								if (p1 + 1 > j - 1) p1 = 0;
								else p1 = p1 + 1;
								
								if (p2 + 1 > j - 1) p2 = 0;
								else p2 = p2 + 1;
								
								K = K + 1;
							}	
							
							J = J + 1;
						}
					}
					
					if (u == -1) {
						J = 0;
						
						while (J < k - 1) {
							K = 0;					
							
							p1 = p3;
							if (p1 + 1 > j - 1) p2 = 0;
							else p2 = p1 + 1;
							
							while (K < k - 1) {
								if (T[p1] < T[p2]) {
									h = T[p2];
									T[p2] = T[p1];
									T[p1] = h;
								}
								
								if (p1 + 1 > j - 1) p1 = 0;
								else p1 = p1 + 1;
								
								if (p2 + 1 > j - 1) p2 = 0;
								else p2 = p2 + 1;
								
								K = K + 1;
							}	
							
							J = J + 1;
						}
					}
					
					
					I = I + 1;
				}
            }
            
            int G = 0;
        
	        while (G < j) {
	            cout << T[G] << " ";
	
	            G= G + 1;
	        }
	
	        cout << endl;

		}

        I = 0;
        
        while (I < j) {
            cout << T[I] << " ";

            I = I + 1;
        }

        cout << endl;

        s = s + 1;
    }
	
	system("pause");
    return 0;
}
