// Ignacia Manurung - 12S25034

#include <stdio.h>  // Untuk fungsi input/output seperti printf, scanf
#include <stdlib.h> // Untuk fungsi alokasi memori dinamis seperti malloc, free, dan EXIT_FAILURE
#include <string.h> // Diminta disertakan, meskipun tidak digunakan secara langsung di sini

int main() {
    int n;
    long long sum = 0;
    double average;
    int countAboveAverage = 0;
    int maxScore = -1; // Inisialisasi untuk memastikan nilai pertama lebih besar
    int minScore = 101; // Inisialisasi untuk memastikan nilai pertama lebih kecil
    int *scores = NULL; // Pointer untuk menyimpan nilai-nilai tugas

    // 1. Input n (jumlah mahasiswa)
    printf("Masukkan jumlah nilai mahasiswa (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Masukan tidak valid. n harus bilangan positif.\n");
        return EXIT_FAILURE; // Keluar dengan kode error
    }

    // 2. Alokasi memori dinamis untuk menyimpan nilai
    scores = (int *)malloc(n * sizeof(int));
    if (scores == NULL) {
        printf("Gagal mengalokasikan memori.\n");
        return EXIT_FAILURE; // Keluar dengan kode error
    }

    // 3. Input n nilai dan hitung jumlah, nilai maksimum, dan nilai minimum
    printf("Masukkan %d nilai tugas (0-100):\n", n);
    for (int i = 0; i < n; i++) {
        int currentScore;
        if (scanf("%d", &currentScore) != 1 || currentScore < 0 || currentScore > 100) {
            printf("Masukan nilai tidak valid pada indeks %d. Nilai harus antara 0-100.\n", i + 1);
            free(scores); // Bebaskan memori sebelum keluar
            return EXIT_FAILURE;
        }
        scores[i] = currentScore; // Simpan nilai ke array
        sum += currentScore;      // Tambahkan ke total

        // Perbarui nilai maksimum dan minimum
        if (currentScore > maxScore) {
            maxScore = currentScore;
        }
        if (currentScore < minScore) {
            minScore = currentScore;
        }
    }

    // 4. Hitung rata-rata
    average = (double)sum / n;

    // 5. Hitung banyaknya mahasiswa yang nilainya di atas atau sama dengan rata-rata
    for (int i = 0; i < n; i++) {
        if (scores[i] >= average) {
            countAboveAverage++;
        }
    }

    // 6. Output hasil sesuai format yang diminta
    printf("\n--- Output ---\n");
    printf("%lld\n", sum);                    // Jumlah seluruh nilai
    printf("%.2f\n", average);                // Nilai rata-rata dengan 2 digit presisi
    printf("%d\n", countAboveAverage);        // Banyaknya mahasiswa >= rata-rata
    printf("%d\n", maxScore - minScore);     // Rentang nilai (maksimum - minimum)
    printf("--------------\n");

    // 7. Bebaskan memori yang dialokasikan
    free(scores);
    scores = NULL; // Hindari dangling pointer

    return 0; // Program berhasil dijalankan
}