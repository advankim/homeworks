//Mateusz Rozdzinski, zadanie 2

#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char* argv[]) {
    printf("\n");
    
    for (int i = 1; i < argc; i++) {
        //wypisanie nazwy wywolanego pliku, uzycie deskryptora do otwarcia pliku zadanego w argumencie do odczytu
        printf("%s:\n", argv[i]);
        int fd = open(argv[i], O_RDONLY);

        //obsluga bledow
        if (errno == 2) {
            fprintf(stderr,"ERROR: Nie ma takiego pliku.\n");
            close(fd);
            continue;
        }
        else if (errno == 13) {
            fprintf(stderr,"ERROR: Brak dostepu do pliku.\n");
            close(fd);
            continue;
        }
        else if (fd == -1) {
            fprintf(stderr,"ERROR: Blad!\n");
            close(fd);
            continue;
        }

        //bufor, deskryptor i petla wypisujaca plik
        int rd;
        char buffer;

        while (1) {
            //odczytanie znaku za pomoca read()
            rd = read(fd, &buffer, 1);

            if (rd == 0) {
                break;
            }

            //obsluga bledu czytania pliku
            if (rd == -1) {
                fprintf(stderr, "Blad odczytu pliku!\n");

                break;
            }

            //wypisanie na wyjscie znaku
            printf("%c", buffer);
        }

        //zamkniecie deskryptorow
        close(fd);
        close(rd);

        printf("\n\n");
    }

    return 0;
}
