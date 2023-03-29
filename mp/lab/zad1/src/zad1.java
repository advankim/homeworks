public class zad1 {
    public static int power(int x, int n)
    {
        if (n == 0) {
            return 1;
        }

        int recursive = power(x, n/2);

        if (n % 2 == 0) {
            return recursive * recursive;
        }

        return recursive * recursive * x;
    }

    public static int zadA(int x, int n) {
        if (n == 0) {
            //warunek konczy wywolywanie kolejnych funkcji, zwraca 1
            return 1;
        }
        else {
            //wywolanie funkcji, ktora pomnozy podstawe kolejny raz, dopoki n != 0
            return zadA(x, --n) * x;
        }
    } // O(n)

    public static int zadB(int polynomial[], int x, int n)
    {
        int result = 0;

        for (int i = 0; i < n; i++) {
            result += zadA(x, n - i - 1) * polynomial[i];
        }

        return result;
    } //O(n * log n)
    public static void main(String[] args) {
        int x = 4;
        int n = 3;

        System.out.println(power(x, n));

        System.out.println(zadA(x, n));
        //zad 1a

        int[] polynomial = {1, -1, 8, -3, -4, 6, 2 ,1};
        x = 9;
        n = 8;

        System.out.println(zadB(polynomial, x, n));
        //zad 1b
    }
}