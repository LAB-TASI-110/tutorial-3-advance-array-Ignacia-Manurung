// Ignacia Manurung - 12S25034

#include <stdio.h>  // Untuk fungsi input/output standar seperti printf dan scanf
#include <stdlib.h> // Untuk utilitas umum (tidak secara eksplisit digunakan di sini, tapi disertakan sesuai permintaan)
#include <string.h> // Untuk manipulasi string (tidak digunakan dalam kasus ini, tapi disertakan sesuai permintaan)

int main() {
    int n;             // Variabel untuk menyimpan jumlah nilai yang akan dimasukkan
    int i;             // Variabel pencacah untuk loop
    int nilai;         // Variabel untuk menyimpan setiap nilai tugas
    long long int total_nilai = 0; // Variabel untuk menyimpan total seluruh nilai, diinisialisasi 0
    double rata_rata;  // Variabel untuk menyimpan nilai rata-rata

    // Langkah 1: Membaca jumlah nilai (n) dari baris pertama masukan
    // printf("Masukkan jumlah nilai (n): "); // Contoh prompt jika interaktif
    scanf("%d", &n);

    // Langkah 2: Melakukan perulangan sebanyak n kali untuk membaca setiap nilai
    // dan menambahkannya ke total_nilai
    for (i = 0; i < n; i++) {
        // printf("Masukkan nilai ke-%d (0-100): ", i + 1); // Contoh prompt jika interaktif
        scanf("%d", &nilai);
        total_nilai += nilai; // Menambahkan nilai yang dibaca ke total_nilai
    }

    // Langkah 3: Menghitung nilai rata-rata
    // Pastikan pembagian menggunakan floating-point dengan melakukan type casting
    rata_rata = (double)total_nilai / n;

    // Langkah 4: Menampilkan hasil total nilai
    printf("%lld\n", total_nilai);

    // Langkah 5: Menampilkan hasil rata-rata dengan 2 digit presisi di belakang koma
    printf("%.2lf\n", rata_rata);

    return 0; // Menandakan program berakhir dengan sukses
}