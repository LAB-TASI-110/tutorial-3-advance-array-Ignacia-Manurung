// Ignacia Manurung - 12S25034

#include <stdio.h>  // Diperlukan untuk fungsi input/output seperti printf dan scanf
#include <stdlib.h> // Diperlukan untuk fungsi umum, contohnya exit() atau malloc(), meskipun di sini tidak eksplisit digunakan.
#include <string.h> // Diperlukan untuk manipulasi string, meskipun tidak digunakan secara langsung dalam kasus ini, disertakan sesuai permintaan.

// Fungsi utama program. Sesuai permintaan, semua logika akan berada dalam satu fungsi.
int main() {
    int n; // Variabel 'n' untuk menyimpan jumlah nilai yang akan dimasukkan.
    int i; // Variabel 'i' sebagai indeks untuk loop.
    int sum = 0; // Variabel untuk menyimpan total/jumlah seluruh nilai. Diinisialisasi dengan 0.
    double average; // Variabel untuk menyimpan nilai rata-rata. Menggunakan 'double' untuk presisi desimal.
    int count_above_average = 0; // Variabel untuk menghitung banyaknya nilai di atas atau sama dengan rata-rata. Diinisialisasi dengan 0.

    // 1. Membaca nilai 'n' dari input.
    // 'n' adalah baris pertama masukan, yang menunjukkan jumlah nilai berikutnya.
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Masukan tidak valid untuk N. N harus bilangan positif.\n");
        return 1; // Keluar dengan kode error
    }

    // Menggunakan array dinamis (atau cukup array statis jika N memiliki batasan maksimal yang diketahui).
    // Untuk kasus tugas kuliah, array statis seringkali diperbolehkan jika N tidak terlalu besar.
    // Namun, untuk fleksibilitas, kita bisa menggunakan VLA (Variable Length Array) yang didukung di C23
    // atau alokasi dinamis dengan malloc jika N bisa sangat besar.
    // Untuk kesederhanaan dan kepatuhan C23, VLA adalah pilihan yang bagus di sini.
    int scores[n]; // Mendefinisikan array 'scores' untuk menyimpan 'n' nilai tugas.

    // 2. Membaca 'n' baris nilai tugas mahasiswa.
    // Setiap nilai harus berada antara 0-100.
    for (i = 0; i < n; i++) {
        if (scanf("%d", &scores[i]) != 1 || scores[i] < 0 || scores[i] > 100) {
            fprintf(stderr, "Masukan nilai tugas tidak valid pada baris ke-%d. Nilai harus antara 0-100.\n", i + 1);
            return 1; // Keluar dengan kode error
        }
        sum += scores[i]; // Menambahkan setiap nilai ke 'sum'.
    }

    // 3. Menghitung rata-rata dari seluruh nilai.
    // Pastikan pembagian menggunakan double untuk mendapatkan hasil desimal yang akurat.
    if (n > 0) {
        average = (double)sum / n;
    } else {
        average = 0.0; // Jika n adalah 0 (meskipun sudah divalidasi tidak <=0), rata-rata adalah 0.
    }

    // 4. Menghitung banyaknya mahasiswa yang nilainya di atas atau sama dengan rata-rata.
    for (i = 0; i < n; i++) {
        if (scores[i] >= average) {
            count_above_average++; // Menambah hitungan jika kondisi terpenuhi.
        }
    }

    // 5. Menampilkan hasil sesuai format keluaran yang diminta.
    // Baris pertama: Jumlah seluruh nilai.
    printf("%d\n", sum);
    // Baris kedua: Nilai rata-rata dengan 2 digit presisi di belakang koma.
    printf("%.2f\n", average);
    // Baris ketiga: Banyaknya mahasiswa yang nilainya di atas atau sama dengan rata-rata.
    printf("%d\n", count_above_average);

    return 0; // Mengembalikan 0 menandakan program berakhir dengan sukses.
}