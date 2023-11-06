#include <iostream>

int main() {
    /*
     * Perubahan :
     */

    std::string command[6] = {
            "1. Pesan Makanan",
            "2. Pesan Minuman",
            "3. Rekap Pesanan",
            "4. Exit",
            "5. Hapus Pesanan",
            "6. [ADMIN] Tambah Menu Baru"
    };
    std::string makanan[30], minuman[30];           //Menu
    float harga_makanan[30], harga_minuman[30];     //Harga
    int pesanan_makanan[30], pesanan_minuman[30];
    int n_makanan = 3;                              //Jumlah Makanan di Menu
    int n_minuman = 3;                              //Jumlah Minuman di Menu
    int n_pesan_makanan = 0;
    int n_pesan_minuman = 0;
    makanan[0] = "Sop Buntut";
    makanan[1] = "Nasi Goreng";
    makanan[2] = "Bebek Bakar";
    minuman[0] = "Strawberry Squash";
    minuman[1] = "Orange Juice";
    minuman[2] = "Lemon Tea";
    harga_makanan[0] = 45000;
    harga_makanan[1] = 20000;
    harga_makanan[2] = 40000;
    harga_minuman[0] = 7000;
    harga_minuman[1] = 15000;
    harga_minuman[2] = 7000;

    bool is_lanjut = true;
    int i, pilih;
    float total_pesanan;
    while (is_lanjut) {
        for (i = 0; i < sizeof(command)/sizeof(std::string); i++) {
            std::cout << command[i] << std::endl;
        }
        std::cout << "Pilih Menu: ";
        std::cin >> pilih;
        std::cout << '\n';
        switch (pilih) {
            case 1:
                std::cout << "-----------------------\n";
                for (i = 0; i < n_makanan; i++) {
                    std::cout << makanan[i] << " (kode: " << i << ")\n";
                }
                std::cout << "-----------------------\n";
                std::cout << "Input kode: ";
                std::cin >> pesanan_makanan[n_pesan_makanan];
                std::cout << '\n';
                n_pesan_makanan++;
                break;
            case 2:
                std::cout << "-----------------------\n";
                for (i = 0; i < n_minuman; i++) {
                    std::cout << minuman[i] << " (kode: " << i << ")\n";
                }
                std::cout << "-----------------------\n";
                std::cout << "Input kode: ";
                std::cin >> pesanan_minuman[n_pesan_minuman];
                std::cout << '\n';
                n_pesan_minuman++;
                break;
            case 3:
                total_pesanan = 0;
                std::cout << "----------makanan-------------\n";
                for (i = 0; i < n_pesan_makanan; i++) {
                    std::cout << makanan[pesanan_makanan[i]];
                    std::cout << " (harga: ";
                    std::cout << harga_makanan[pesanan_makanan[i]];
                    std::cout << ")\n";
                    total_pesanan += harga_makanan[pesanan_makanan[i]];
                }
                std::cout << "----------minuman-------------\n";
                for (i = 0; i < n_pesan_minuman; i++) {
                    std::cout << minuman[pesanan_minuman[i]];
                    std::cout << " (harga: ";
                    std::cout << harga_minuman[pesanan_minuman[i]];
                    std::cout << ")\n";
                    total_pesanan += harga_minuman[pesanan_minuman[i]];
                }
                std::cout << "-----------total--------------\n";
                std::cout << "Total: " << total_pesanan << std::endl;
                std::cout << "------------------------------\n";
                break;
            case 4:
                is_lanjut = false;
                break;
            case 5:
                //
            default:
                std::cout<<"Input yang anda masukan tidak terdefinisi, silahkan coba lagi.\n";
                break;
        }
    }
}
