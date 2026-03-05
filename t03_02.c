// Ignacia Manurung - 12S25034

#include <stdio.h> // Digunakan untuk input/output seperti printf dan scanf
#include <stdlib.h> // Digunakan untuk EXIT_SUCCESS dan fungsi utilitas lainnya
#include <string.h> // Disertakan sesuai permintaan, meskipun tidak digunakan secara langsung untuk operasi ini
#include <limits.h> // Digunakan untuk INT_MAX dan INT_MIN

int main() {
    int n; // Jumlah nilai tugas mahasiswa
    int nilai_mahasiswa[100]; // Array untuk menyimpan nilai, diasumsikan max 100 mahasiswa
    long int sum = 0; // Total seluruh nilai (menggunakan long int untuk menghindari overflow jika n dan nilai besar)
    double rata_rata; // Nilai rata-rata
    int count_diatas_rata = 0; // Banyaknya mahasiswa dengan nilai >= rata-rata
    int min_val = INT_MAX; // Nilai minimum, diinisialisasi dengan nilai int maksimum
    int max_val = INT_MIN; // Nilai maksimum, diinisialisasi dengan nilai int minimum
    
    // --- Input 'n' ---
    printf("Masukkan jumlah mahasiswa (n, maks 100): ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 100) {
        printf("Masukan tidak valid untuk n. n harus bilangan positif antara 1 dan 100.\n");
        return EXIT_FAILURE; // Keluar dengan status error
    }

    // --- Input Nilai Tugas Mahasiswa ---
    printf("Masukkan %d nilai tugas mahasiswa (0-100):\n", n);
    for (int i = 0; i < n; i++) {
        int current_nilai;
        printf("Nilai mahasiswa ke-%d: ", i + 1);
        if (scanf("%d", &current_nilai) != 1 || current_nilai < 0 || current_nilai > 100) {
            printf("Masukan nilai tidak valid. Nilai harus antara 0-100.\n");
            return EXIT_FAILURE; // Keluar dengan status error
        }
        nilai_mahasiswa[i] = current_nilai;
        
        // --- Perhitungan Sum, Min, Max saat input ---
        sum += nilai_mahasiswa[i];
        if (nilai_mahasiswa[i] < min_val) {
            min_val = nilai_mahasiswa[i];
        }
        if (nilai_mahasiswa[i] > max_val) {
            max_val = nilai_mahasiswa[i];
        }
    }

    // --- Perhitungan Rata-rata ---
    if (n > 0) { // Menghindari pembagian dengan nol
        rata_rata = (double)sum / n;
    } else {
        rata_rata = 0.0; // Jika n=0, rata-rata adalah 0
    }

    // --- Perhitungan Banyaknya Mahasiswa yang Nilainya >= Rata-rata ---
    for (int i = 0; i < n; i++) {
        if (nilai_mahasiswa[i] >= rata_rata) {
            count_diatas_rata++;
        }
    }

    // --- Output Hasil ---
    printf("\n--- Output Program ---\n");
    printf("%ld\n", sum); // Jumlah seluruh nilai
    printf("%.2f\n", rata_rata); // Rata-rata dengan 2 digit presisi
    printf("%d\n", count_diatas_rata); // Banyaknya mahasiswa >= rata-rata
    printf("%d\n", max_val - min_val); // Rentang nilai (maks - min)

    return EXIT_SUCCESS; // Program berakhir sukses
}