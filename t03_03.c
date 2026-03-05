// Ignacia Manurung - 12S25034

#include <stdio.h> // Untuk input/output seperti printf dan scanf
#include <stdlib.h> // Untuk fungsi umum (tidak langsung digunakan di sini tapi diminta)
#include <string.h> // Untuk operasi string (tidak langsung digunakan di sini tapi diminta)
#include <limits.h> // Untuk INT_MAX dan INT_MIN (membantu inisialisasi min/max)

int main() {
    int n; // Jumlah nilai yang akan dimasukkan
    
    // Meminta dan membaca input untuk n
    printf("Masukkan jumlah nilai (n): ");
    scanf("%d", &n);

    // Validasi sederhana untuk n positif
    if (n <= 0) {
        printf("Jumlah nilai (n) harus bilangan positif.\n");
        return 1; // Keluar dengan kode error
    }

    // Menggunakan alokasi dinamis untuk array jika n bisa sangat besar,
    // atau array statis dengan ukuran maksimum yang wajar.
    // Untuk tujuan tugas kuliah dan batasan memori, array statis 100 sudah cukup.
    // Jika n > 100, ini akan menjadi masalah. Untuk keamanan, bisa pakai alokasi dinamis.
    // Untuk kasus ini, kita asumsikan n tidak akan melebihi ukuran array.
    int nilai[n]; // Menggunakan Variable Length Array (VLA) yang didukung C99 dan C23.
                   // Jika kompiler lama dan tidak mendukung VLA, gunakan alokasi dinamis (malloc).

    long long sum = 0; // Menggunakan long long untuk sum agar dapat menampung nilai besar
    int min_val = INT_MAX; // Inisialisasi dengan nilai integer maksimum
    int max_val = INT_MIN; // Inisialisasi dengan nilai integer minimum
    int i; // Variabel counter untuk loop

    printf("Masukkan %d nilai tugas mahasiswa (0-100):\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &nilai[i]);

        // Validasi nilai harus antara 0-100
        if (nilai[i] < 0 || nilai[i] > 100) {
            printf("Nilai harus antara 0 dan 100. Mohon ulangi input dari awal.\n");
            return 1; // Keluar dengan kode error
        }

        sum += nilai[i]; // Menambahkan nilai ke total sum

        // Memperbarui nilai minimum dan maksimum
        if (nilai[i] < min_val) {
            min_val = nilai[i];
        }
        if (nilai[i] > max_val) {
            max_val = nilai[i];
        }
    }

    double average = (double)sum / n; // Menghitung rata-rata, pastikan casting ke double

    int count_above_avg = 0; // Menghitung berapa banyak nilai di atas atau sama dengan rata-rata
    for (i = 0; i < n; i++) {
        if (nilai[i] >= average) {
            count_above_avg++;
        }
    }

    int range = max_val - min_val; // Menghitung rentang nilai

    // Menampilkan hasil sesuai format yang diminta
    printf("\n--- Output ---\n");
    printf("%lld\n", sum); // Jumlah seluruh nilai
    printf("%.2f\n", average); // Nilai rata-rata dengan 2 digit presisi
    printf("%d\n", count_above_avg); // Banyaknya mahasiswa yang nilainya >= rata-rata
    printf("%d\n", range); // Rentang nilai (maksimum - minimum)
    printf("--------------\n");

    return 0; // Mengindikasikan program berjalan sukses
}