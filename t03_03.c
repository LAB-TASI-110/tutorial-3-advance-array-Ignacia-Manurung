// Ignacia Manurung - 12S25034

#include <stdio.h> // Diperlukan untuk fungsi input/output seperti printf dan scanf
#include <limits.h> // Diperlukan untuk INT_MAX dan INT_MIN untuk inisialisasi min/max

int main() {
    int n;                 // Variabel untuk menyimpan jumlah nilai yang akan dimasukkan (jumlah mahasiswa)
    int totalNilai = 0;    // Variabel untuk menjumlahkan seluruh nilai
    int nilai;             // Variabel sementara untuk setiap nilai yang dibaca
    int nilaiMin = INT_MAX; // Inisialisasi nilai minimum dengan nilai integer terbesar
    int nilaiMax = INT_MIN; // Inisialisasi nilai maksimum dengan nilai integer terkecil
    int countDiAtasRataRata = 0; // Variabel untuk menghitung mahasiswa yang nilainya di atas atau sama dengan rata-rata

    // Deklarasi array untuk menyimpan nilai-nilai, diasumsikan n tidak lebih dari 100
    // Untuk n yang lebih besar atau tidak tentu, disarankan menggunakan alokasi dinamis (malloc)
    int scores[100]; 

    // Membaca baris pertama masukan: jumlah nilai (n)
    // printf("Masukkan jumlah mahasiswa (n): "); // Contoh prompt untuk pengguna
    scanf("%d", &n);

    // Membaca n baris berikutnya: nilai tugas mahasiswa
    for (int i = 0; i < n; i++) {
        // printf("Masukkan nilai mahasiswa ke-%d (0-100): ", i + 1); // Contoh prompt
        scanf("%d", &nilai);

        // Menambahkan nilai ke total
        totalNilai += nilai;

        // Memperbarui nilai minimum dan maksimum
        if (nilai < nilaiMin) {
            nilaiMin = nilai;
        }
        if (nilai > nilaiMax) {
            nilaiMax = nilai;
        }

        // Menyimpan nilai ke dalam array
        scores[i] = nilai;
    }

    // Menghitung nilai rata-rata
    // Menggunakan (double) untuk memastikan pembagian menghasilkan nilai floating-point
    double rataRata = (double)totalNilai / n;

    // Menghitung banyaknya mahasiswa yang nilainya di atas atau sama dengan rata-rata
    for (int i = 0; i < n; i++) {
        if (scores[i] >= rataRata) {
            countDiAtasRataRata++;
        }
    }

    // Menghitung rentang nilai (nilai maksimum - nilai minimum)
    int rentangNilai = nilaiMax - nilaiMin;

    // Menampilkan keluaran sesuai format yang diminta
    printf("%d\n", totalNilai);          // Baris pertama: jumlah seluruh nilai
    printf("%.2f\n", rataRata);          // Baris kedua: nilai rata-rata dengan 2 digit presisi
    printf("%d\n", countDiAtasRataRata); // Baris ketiga: banyaknya mahasiswa yang nilainya diatas atau sama dengan rata-rata
    printf("%d\n", rentangNilai);        // Baris keempat: rentang nilai (max - min)

    return 0; // Menandakan program berakhir dengan sukses
}