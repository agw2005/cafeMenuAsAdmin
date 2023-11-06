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
    std::string makanan[30], minuman[30];           //List Menu
    float harga_makanan[30], harga_minuman[30];     //List Harga Menu
    int pesanan_makanan[30], pesanan_minuman[30];   //List pesanan
    int n_makanan = 3;                              //Jumlah Makanan di Menu
    int n_minuman = 3;                              //Jumlah Minuman di Menu
    int n_pesan_makanan = 0;                        //Pesanan makanan ke-[List pesanan makanan]
    int n_pesan_minuman = 0;                        //Pesanan makanan ke-[List pesanan minuman]
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
    float placeholderHarga;
    std::string placeholderNama;
    bool tambahMenuBaru = true;
    bool tambahMinuman = true;
    bool tambahMakanan = true;
    while (is_lanjut) {

        //--------------------------------------------------------------------------------------------------------------
        for (i = 0; i < sizeof(command)/sizeof(std::string); i++)
        {
            std::cout << command[i] << std::endl;
        }
        //Menunjukan list command (ln:8)
        //--------------------------------------------------------------------------------------------------------------

        //--------------------------------------------------------------------------------------------------------------
        std::cout << "Pilih Menu: ";
        std::cin >> pilih;
        std::cout << '\n';
        //Input user sesuai dengan command yang dijalankan (ln:8)
        //--------------------------------------------------------------------------------------------------------------

        switch (pilih) {

            case 1:
                std::cout << "-----------------------\n";
                for (i = 0; i < n_makanan; i++) {
                    std::cout << makanan[i] << " (kode: " << i << ")\n";
                }
                //Loop diatas akan output list menu makanan ke console
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
                //Hapus pesanan
            case 6:
                //Tambah menu baru
                int selection;
                while(tambahMenuBaru)
                {
                    std::cout<<"Menu apa yang ingin anda tambahkan?\n1. Menu makanan\n2. Menu minuman\nInput: ";
                    std::cin>>selection;
                    std::cout<<'\n';
                    switch(selection)
                    {
                        case 1:
                            n_makanan++;
                            while (tambahMakanan)
                            {
                                std::cout<<"Apa nama menu makanan baru yang akan anda tambahkan?";
                                //  Kalau pake std::cin >> makanan[n_makanan-1];
                                //  Cuman ngeread kata pertamanya
                                //  Kata keduanya kagak masuk variabel, tapi masuk "input buffer"
                                //  Karena ada input buffer, bakal ngeskip pertanyaan "berapa harga satuan"
                                //  dan langsung masukin yang ada di input buffer ke harga_makanan[n_makanan-1]
                                //  Tapi karena nilai harga_makanan[n_makanan-1] itu integer, bukan string
                                //  Hasilnya harga_makanan[n_makanan-1] = 0
                                std::cin >> makanan[n_makanan-1];
                                std::cout<<"Berapa harga satuan dari "<<makanan[n_makanan-1]<<"?\n";
                                std::cin>>harga_makanan[n_makanan-1];
                                std::cout<<'\n';
                                tambahMakanan = false;
                            }
                            tambahMenuBaru = false;
                            break;
                        case 2:
                            while (tambahMinuman)
                            {
                                std::cout<<"Apa nama menu minuman baru yang akan anda tambahkan?\n";
                                std::getline(std::cin, placeholderNama);
                                std::cout<<'\n';
                                std::cout<<"Berapa harga satuan dari "<<placeholderNama<<"?\n";
                                std::cin>>placeholderHarga;
                                std::cout<<'\n';
                                tambahMinuman = false;
                            }
                            n_minuman++;
                            minuman[n_minuman-1] = placeholderNama;
                            harga_minuman[n_minuman-1] = placeholderHarga;
                            tambahMenuBaru = false;
                            break;
                        default:
                            std::cout<<"Input yang anda masukan tidak terdefinisi, silahkan coba lagi.\n";
                            break;
                    }
                }
                break;
            default:
                std::cout<<"Input yang anda masukan tidak terdefinisi, silahkan coba lagi.\n";
                break;
        }
    }
}
