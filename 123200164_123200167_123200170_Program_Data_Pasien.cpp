#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#define maks 999

using namespace std;

typedef struct {
    int no_rekam_medis, harga_rawat_inap;
    string nama_pasien, jenis_kelamin, penyakit, gol_darah, ttl, tgl_masuk, alamat;
    string rawat, jenis_kamar;
}data;

data data_pasien[maks], temp;
ifstream rumah_sakit_in;
ofstream rumah_sakit_out;
string daftar_file[maks], nama_file, cari_nama, file_baru;
int cari_no_rekam_medis, banyak_data;
char kembali = 'y', keluar = 'n';

void menu_data();
void input_data();
void tampil_data();
void delete_file();
void simpan_data();
void edit_file();
void sequential();
void binary();
void ambil_file(int *panjang);
void set_file(int panjang);
void list_file();
void shell_sort(int panjang);

main(){
    int pilihan, pilih;
    while (kembali == 'y' || kembali == 'Y' || keluar == 'N' || keluar == 'n'){
        system("cls");
        cout << "=====================================\n";
        cout << "  Program Data Pasien Rumah Sakit" << endl;
        cout << "=====================================\n";
        
        cout << "1. Data Pasien \n2. Searching Data \n3. Keluar" << endl;
        cout << "Masukkan Pilihan = "; cin >> pilihan;
        cout << endl;
        switch(pilihan){
            case 1 : {
                system("cls");
                menu_data();
            break;
            }case 2 : {
                system("cls");
                cout << "===========================\n";
                cout << "    Pencarian Data Pasien\n";
                cout << "===========================\n\n";
                cout << "1. Nama Pasien\n2. Nomor Rekam Medis\n3. Kembali "<< endl;
                cout << "Pilihan : "; cin >> pilih;
                if (pilih == 1){
                    sequential();
                }else if (pilih == 2){
                    binary();
                }else if (pilih == 3){
                    main();
                }else cout << "Salah Input" << endl;
            break;
            }case 3 : {
                system("cls");
                exit(1);
            break;
            }default : {
                cout << "Salah Input" << endl;
            break;
            }
        }
        cout << "Kembali ke Menu Utama (Y/N) ? "; cin >> kembali;
        if(kembali=='n' || kembali == 'N'){
            cout << "Keluar (Y/N) ? "; cin >> keluar;
        }
    }
}

void ambil_file(int *panjang){
    int i = 0;

    while(true){
        getline(rumah_sakit_in,data_pasien[i].nama_pasien);
        if(rumah_sakit_in.eof()){
            break;
        }
        rumah_sakit_in >> data_pasien[i].no_rekam_medis;rumah_sakit_in.ignore();
        getline(rumah_sakit_in,data_pasien[i].ttl);
        getline(rumah_sakit_in,data_pasien[i].jenis_kelamin);
        getline(rumah_sakit_in,data_pasien[i].gol_darah);
        getline(rumah_sakit_in,data_pasien[i].alamat);
        getline(rumah_sakit_in,data_pasien[i].penyakit);
        getline(rumah_sakit_in,data_pasien[i].tgl_masuk);
        getline(rumah_sakit_in,data_pasien[i].rawat);
        rumah_sakit_in >> data_pasien[i].harga_rawat_inap;rumah_sakit_in.ignore();
        i++;
    }
    *panjang = i;
}
void set_file(int panjang){
    for (int i = 0; i < panjang; i++){
        rumah_sakit_out << data_pasien[i].nama_pasien << endl;
        rumah_sakit_out << data_pasien[i].no_rekam_medis << endl;
        rumah_sakit_out << data_pasien[i].ttl << endl;
        rumah_sakit_out << data_pasien[i].jenis_kelamin << endl;
        rumah_sakit_out << data_pasien[i].gol_darah << endl;
        rumah_sakit_out << data_pasien[i].alamat << endl;
        rumah_sakit_out << data_pasien[i].penyakit << endl;   
        rumah_sakit_out << data_pasien[i].tgl_masuk << endl;
        rumah_sakit_out << data_pasien[i].rawat << endl;
        rumah_sakit_out << data_pasien[i].harga_rawat_inap << endl;
    }
}
void list_file(){
    int i = 0;
    rumah_sakit_in.open("Daftar File.txt");
    while(!rumah_sakit_in.eof()){
        rumah_sakit_in >> daftar_file[i];
        i++;
    }
    rumah_sakit_in.close();
    cout << "Daftar File" << endl;
    for(int j=0; j < i-1; j++){
        cout << j+1 << ". " << daftar_file[j] << endl;
    }
}
void menu_data(){
    int pilih;
    cout << "===========================\n";
    cout << "\tDATA PASIEN " << endl;
    cout << "===========================\n";
    cout << "1. Input Data Pasien\n2. Tampil Data Pasien\n3. Simpan Data\n4. Delete File\n5. Ubah Data\n6. Kembali " << endl;
    cout << "Pilihan : "; cin >> pilih;

    if (pilih == 1){
        input_data();
    }else if (pilih == 2){
        tampil_data();
    }else if (pilih == 3){
         simpan_data();
    }else if (pilih == 4){
        delete_file();
    }else if (pilih == 5){
        edit_file();
    }else main();
}
void input_data(){
    char kembali_menu_data;
    int jenis_rawat, hari, kamar, kembali, panjang;
    system("cls");
    cout << "===========================\n";
    cout << "      Input Data Pasien "<< endl;
    cout << "===========================\n\n";
    cout << "Banyak Data Pasien : "; cin >> banyak_data;

    for (int i = 0; i < banyak_data; i++){
        cout << endl;
        cout << "Pasien " << i+1 << endl;
        cout << "Nama Pasien\t\t: "; cin.ignore(); getline(cin,data_pasien[i].nama_pasien);
        cout << "Nomor Rekam Medis\t: ";cin >> data_pasien[i].no_rekam_medis; 
        cout << "Tempat, Tanggal Lahir\t: "; cin.ignore(); getline(cin,data_pasien[i].ttl);
        cout << "Jenis Kelamin\t\t: "; getline(cin,data_pasien[i].jenis_kelamin);
        cout << "Golongan Darah\t\t: "; getline(cin,data_pasien[i].gol_darah);
        cout << "Alamat\t\t\t: "; getline(cin,data_pasien[i].alamat);
        cout << "Penyakit\t\t: "; getline(cin, data_pasien[i].penyakit);
        cout << "Tanggal Masuk Pasien\t: "; getline(cin, data_pasien[i].tgl_masuk);
        cout << endl;
        cout << "Jenis Rawat" << endl;
        cout << "1. Rawat Jalan\n2. Rawat Inap " << endl;
        cout << "Pilihan : "; cin >> jenis_rawat;

        if(jenis_rawat == 1){
            data_pasien[i].rawat = "Rawat Jalan";
            data_pasien[i].harga_rawat_inap = 100000;
        }else if (jenis_rawat == 2){
            data_pasien[i].rawat = "Rawat Inap";
            cout << endl;
            cout << "Hari Menginap : "; cin >> hari;
            cout << "Jenis Kamar " << endl;
            cout << "1. Kelas I\n2. Kelas II\n3. VIP" << endl;
            cout << "Pilihan : "; cin >> kamar;
            
            if (kamar == 1){
                data_pasien[i].jenis_kamar = "Kelas I";
                data_pasien[i].harga_rawat_inap = 850000*hari;
            }else if (kamar == 2){
                data_pasien[i].jenis_kamar = "Kelas II";
                data_pasien[i].harga_rawat_inap = 1000000*hari;
            }else if (kamar == 3){
                data_pasien[i].jenis_kamar = "Kelas VIP";
                data_pasien[i].harga_rawat_inap = 1200000*hari;
            }
        }
    }
    panjang = banyak_data;
    cout << "Kembali ke Menu Data Pasien (Y/N) ? "; cin >> kembali_menu_data;
    if (kembali_menu_data == 'Y' || kembali_menu_data == 'y'){
        system("cls");
        menu_data();
    }
}
void tampil_data(){
    int panjang;
    char kembali_menu_data;
    system("cls");
    cout << "===========================\n";
    cout << "     Tampil Data Pasien " << endl;
    cout << "===========================\n\n";
    list_file();
    cout << "Nama File\t: "; cin >> nama_file;
    rumah_sakit_in.open(nama_file.c_str());
    if(!rumah_sakit_in.good()){
        char kembali;
        cout << endl;
        cout << "File Tidak Ada" << endl << endl;
        rumah_sakit_in.close();
        cout << "Kembali (Y/N) : "; cin >> kembali;
        if(kembali == 'y' || kembali == 'Y'){
            system("cls");
            tampil_data();
        }else {
            system("cls");
            main();
        }
    }
    ambil_file(&panjang);

    cout << "=========================================================================================================================================================================================================\n";
    cout << "|" << "  NO" << setw(2) << "|"  
    << "       Nama" << setw(7) << "|" 
    << "  No. Rekam Medis" << setw(2) << "|"
    << "          TTL" << setw(10) << "|"
    << "     Kelamin" << setw(5) << "|"
    << "     Gol. Darah" << setw(5) << "|"
    << "       Alamat" << setw(7) << "|"
    << "    Penyakit" << setw(3) << "|"
    << "  Tanggal Masuk Pasien" << setw(2) << "|" 
    << "    Jenis Rawat" << setw(4) << "|"
    << "    Harga Rawat" << setw(4) << "|" << endl;
    cout << "=========================================================================================================================================================================================================\n";
    for (int i = 0; i < panjang; i++){
        cout << "|  " << i+1 << setw(3) << "|"
        << setw(17) << data_pasien[i].nama_pasien << "|"
        << setw(18) << data_pasien[i].no_rekam_medis  << "|"
        << setw(22) << data_pasien[i].ttl  << "|"
        << setw(16) << data_pasien[i].jenis_kelamin  << "|"
        << setw(19) << data_pasien[i].gol_darah  << "|"
        << setw(19) << data_pasien[i].alamat  << "|"
        << setw(14) << data_pasien[i].penyakit  << "|"  
        << setw(23) << data_pasien[i].tgl_masuk  << "|"
        << setw(18) << data_pasien[i].rawat << "|"
        << setw(3) << "Rp" << setw(15)  << data_pasien[i].harga_rawat_inap << "|" << endl;
    }
    cout << "=========================================================================================================================================================================================================\n";
    rumah_sakit_in.close();
    cout << "Kembali ke Menu Data Pasien (Y/N) ? "; cin >> kembali_menu_data;
    if (kembali_menu_data == 'Y' || kembali_menu_data == 'y'){
        system("cls");
        menu_data();
    }
}
void simpan_data(){
    char kembali_menu_data;
    system("cls");
    cout << "===========================\n";
    cout << "\tSimpan Data\n";
    cout << "===========================\n\n";
    cout << "Masukkan Nama File : "; cin >> nama_file;
    rumah_sakit_out.open("Daftar File.txt", ios :: app);
    rumah_sakit_out << nama_file << endl;
    rumah_sakit_out.close();

    rumah_sakit_out.open(nama_file.c_str(), ios :: out);
    if(rumah_sakit_out.is_open()){
        cout << "Data berhasil disimpan " << endl;
        for(int i = 0; i < banyak_data; i++){
            rumah_sakit_out << data_pasien[i].nama_pasien << endl;
            rumah_sakit_out << data_pasien[i].no_rekam_medis << endl;
            rumah_sakit_out << data_pasien[i].ttl << endl;
            rumah_sakit_out << data_pasien[i].jenis_kelamin << endl;
            rumah_sakit_out << data_pasien[i].gol_darah << endl;
            rumah_sakit_out << data_pasien[i].alamat << endl;
            rumah_sakit_out << data_pasien[i].penyakit << endl;   
            rumah_sakit_out << data_pasien[i].tgl_masuk << endl;
            rumah_sakit_out << data_pasien[i].rawat << endl;
            rumah_sakit_out << data_pasien[i].harga_rawat_inap << endl;
        }

    }
    rumah_sakit_out.close();
    cout << "Kembali ke Menu Data Pasien (Y/N) ? "; cin >> kembali_menu_data;
    if (kembali_menu_data == 'Y' || kembali_menu_data == 'y'){
        system("cls");
        menu_data();
    }
}
void delete_file(){
    char kembali_menu_data;
    string file_hapus, null;
    int i = 0;
    system("cls");
    cout << "===========================\n";
    cout << "\tDelete File\n";
    cout << "===========================\n\n";
    list_file();
    cout << "Nama File : "; cin >> file_hapus;
    rumah_sakit_in.open(file_hapus.c_str());
    if(!rumah_sakit_in.good()){
        char kembali;
        cout << endl;
        cout << "File Tidak Ada" << endl << endl;
        rumah_sakit_in.close();
        cout << "Kembali (Y/N) : "; cin >> kembali;
        if(kembali == 'y' || kembali == 'Y'){
            system("cls");
            tampil_data();
        }else {
            system("cls");
            main();
        }
    }
    rumah_sakit_in.close();

    remove(file_hapus.c_str());
    cout << "File berhasil dihapus" << endl;

    rumah_sakit_out.open("Daftar File.txt");
    while(daftar_file[i] != null){
        if (file_hapus != daftar_file[i]){
            
            rumah_sakit_out << daftar_file[i] << endl;
        }
        i++;
    }
    rumah_sakit_out.close();

    cout << "Kembali ke Menu Data Pasien (Y/N) ? "; cin >> kembali_menu_data;
    if (kembali_menu_data == 'Y' || kembali_menu_data == 'y'){
        system("cls");
        menu_data();
    }
}
void edit_file(){
    char kembali_menu_data;
    int panjang, jenis_rawat, hari, kamar;
    bool found;
    string nama;

    system("cls");
    cout << "===========================\n";
    cout << "\tUbah Data\n";
    cout << "===========================\n\n";
    list_file();
    cout << endl;
    cout << "Nama File\t: "; cin >> nama;

    rumah_sakit_in.open(nama.c_str());
    if(!rumah_sakit_in.good()){
        char kembali;
        cout << endl;
        cout << "File Tidak Ada" << endl << endl;
        rumah_sakit_in.close();
        cout << "Kembali (Y/N) : "; cin >> kembali;
        if(kembali == 'y' || kembali == 'Y'){
            system("cls");
            tampil_data();
        }else {
            system("cls");
            main();
        }
    }
    ambil_file(&panjang);
    rumah_sakit_in.close();

    cout << endl;
    cout << "=========================================================================================================================================================================================================\n";
    cout << "|" << "  NO" << setw(2) << "|"  
    << "       Nama" << setw(7) << "|" 
    << "  No. Rekam Medis" << setw(2) << "|"
    << "          TTL" << setw(10) << "|"
    << "     Kelamin" << setw(5) << "|"
    << "     Gol. Darah" << setw(5) << "|"
    << "       Alamat" << setw(7) << "|"
    << "    Penyakit" << setw(3) << "|"
    << "  Tanggal Masuk Pasien" << setw(2) << "|" 
    << "    Jenis Rawat" << setw(4) << "|"
    << "    Harga Rawat" << setw(4) << "|" << endl;
    cout << "=========================================================================================================================================================================================================\n";
    for (int i=0; i < panjang; i++){
        cout << "|  " << i+1 << setw(3) << "|"
        << setw(17) << data_pasien[i].nama_pasien << "|"
        << setw(18) << data_pasien[i].no_rekam_medis  << "|"
        << setw(22) << data_pasien[i].ttl  << "|"
        << setw(16) << data_pasien[i].jenis_kelamin  << "|"
        << setw(19) << data_pasien[i].gol_darah  << "|"
        << setw(19) << data_pasien[i].alamat  << "|"
        << setw(14) << data_pasien[i].penyakit  << "|"  
        << setw(23) << data_pasien[i].tgl_masuk  << "|"
        << setw(18) << data_pasien[i].rawat << "|"
        << setw(3) << "Rp" << setw(15)  << data_pasien[i].harga_rawat_inap << "|" << endl;
    }
    cout << "=========================================================================================================================================================================================================\n";
    found = false;
    cout << "Masukkan No Rekam Medis : "; cin >> cari_no_rekam_medis;

    for (int i = 0; i < panjang; i++){
        if (cari_no_rekam_medis == data_pasien[i].no_rekam_medis){
            found = true;
            cout << "Nama Pasien\t\t: ";cin.ignore();getline(cin,data_pasien[i].nama_pasien);
            cout << "Nomor Rekam Medis\t: ";cin >> data_pasien[i].no_rekam_medis; 
            cout << "Tempat, Tanggal Lahir\t: "; cin.ignore(); getline(cin,data_pasien[i].ttl);
            cout << "Jenis Kelamin\t\t: "; getline(cin,data_pasien[i].jenis_kelamin);
            cout << "Golongan Darah\t\t: "; getline(cin,data_pasien[i].gol_darah);
            cout << "Alamat\t\t\t: "; getline(cin,data_pasien[i].alamat);
            cout << "Penyakit\t\t: ";getline(cin,data_pasien[i].penyakit);
            cout << "Tanggal Masuk Pasien\t: "; getline(cin, data_pasien[i].tgl_masuk);
            cout << endl;
            cout << "Jenis Rawat" << endl;
            cout << "1. Rawat Jalan\n2. Rawat Inap " << endl;
            cout << "Pilihan : "; cin >> jenis_rawat;

            if(jenis_rawat == 1){
                data_pasien[i].rawat = "Rawat Jalan";
                data_pasien[i].harga_rawat_inap = 100000;
            }else if (jenis_rawat == 2){
                data_pasien[i].rawat = "Rawat Inap";
                cout << "Hari Menginap : "; cin >> hari;
                cout << "Jenis Kamar " << endl;
                cout << "1. Kelas I\n2. Kelas II\n3. VIP" << endl;
                cout << "Pilihan : "; cin >> kamar;
                
                if (kamar == 1){
                    data_pasien[i].jenis_kamar = "Kelas I";
                    data_pasien[i].harga_rawat_inap = 850000*hari;
                }else if (kamar == 2){
                    data_pasien[i].jenis_kamar = "Kelas II";
                    data_pasien[i].harga_rawat_inap = 1000000*hari;
                }else if (kamar == 3){
                    data_pasien[i].jenis_kamar = "Kelas VIP";
                    data_pasien[i].harga_rawat_inap = 1200000*hari;
                }
            }
            cout << "File penyimpan setelah di-update\t: "; cin >> file_baru;
            rumah_sakit_out.open("Daftar File.txt", ios :: app);
            rumah_sakit_out << file_baru << endl;
            rumah_sakit_out.close();

            rumah_sakit_out.open(file_baru.c_str());
            set_file(panjang);
            rumah_sakit_out.close();
        }

         if (found == true){
            break;
        }
    }
    if (!found){
            cout << "Pasien tidak ada" << endl << endl;
    }
    cout << "Kembali ke Menu Data Pasien (Y/N) ? "; cin >> kembali_menu_data;
    if (kembali_menu_data == 'Y' || kembali_menu_data == 'y'){
        system("cls");
        menu_data();
    }
}
void sequential(){
    int panjang;
    bool found;
    system("cls");
    cout << "===========================\n";
    cout << "    Pencarian Data Pasien\n";
    cout << "===========================\n\n";
    cout << endl;
    list_file();
    cout << "Nama File\t: "; cin >> nama_file;

    rumah_sakit_in.open(nama_file.c_str());
    if(!rumah_sakit_in.good()){
        char kembali;
        cout << endl;
        cout << "File Tidak Ada" << endl << endl;
        rumah_sakit_in.close();
        cout << "Kembali (Y/N) : "; cin >> kembali;
        if(kembali == 'y' || kembali == 'Y'){
            system("cls");
            tampil_data();
        }else {
            system("cls");
            main();
        }
    }
    ambil_file(&panjang);
    rumah_sakit_in.close();

    cout << endl;
    cout << "Nama yang dicari\t: "; cin.ignore();getline(cin,cari_nama);
    found = false;
    for (int i = 0; i < panjang; i++){
        if (cari_nama == data_pasien[i].nama_pasien){
            found = true;
        }
    }
    if (found){
        cout << "=========================================================================================================================================================================================================\n";
        cout << "|" << "  NO" << setw(2) << "|"  
        << "       Nama" << setw(7) << "|" 
        << "  No. Rekam Medis" << setw(2) << "|"
        << "          TTL" << setw(10) << "|"
        << "     Kelamin" << setw(5) << "|"
        << "     Gol. Darah" << setw(5) << "|"
        << "       Alamat" << setw(7) << "|"
        << "    Penyakit" << setw(3) << "|"
        << "  Tanggal Masuk Pasien" << setw(2) << "|" 
        << "    Jenis Rawat" << setw(4) << "|"
        << "    Harga Rawat" << setw(4) << "|" << endl;
        cout << "=========================================================================================================================================================================================================\n";
        for(int i = 0; i < panjang; i++){
            if (cari_nama == data_pasien[i].nama_pasien){
                cout << "|  " << i+1 << setw(3) << "|"
                << setw(17) << data_pasien[i].nama_pasien << "|"
                << setw(18) << data_pasien[i].no_rekam_medis  << "|"
                << setw(22) << data_pasien[i].ttl  << "|"
                << setw(16) << data_pasien[i].jenis_kelamin  << "|"
                << setw(19) << data_pasien[i].gol_darah  << "|"
                << setw(19) << data_pasien[i].alamat  << "|"
                << setw(14) << data_pasien[i].penyakit  << "|"  
                << setw(23) << data_pasien[i].tgl_masuk  << "|"
                << setw(18) << data_pasien[i].rawat << "|"
                << setw(3) << "Rp" << setw(15)  << data_pasien[i].harga_rawat_inap << "|" << endl;
            }
        }
        cout << "=========================================================================================================================================================================================================\n";
    }else cout << "Data Pasien Tidak Ada" << endl;
}
void binary(){
    bool found;
    int panjang,i,j,k;
    system("cls");
    cout << "===========================\n";
    cout << "    Pencarian Data Pasien\n";
    cout << "===========================\n\n";
    list_file();
    cout << "Nama File\t: "; cin >> nama_file;
    rumah_sakit_in.open(nama_file.c_str());
    if(!rumah_sakit_in.good()){
        char kembali;
        cout << endl;
        cout << "File Tidak Ada" << endl << endl;
        rumah_sakit_in.close();
        cout << "Kembali (Y/N) : "; cin >> kembali;
        if(kembali == 'y' || kembali == 'Y'){
            system("cls");
            tampil_data();
        }else {
            system("cls");
            main();
        }
    }
    ambil_file(&panjang);
    rumah_sakit_in.close();

    cout << "Nomor Rekam Medis yang dicari\t: "; cin >> cari_no_rekam_medis;
    shell_sort(panjang);

    cout << endl;
    i = 0;
    j = panjang;
    while((!found) & (i<=j)){
        k = (i + j)/2;
        if (cari_no_rekam_medis == data_pasien[k].no_rekam_medis){
            found = true;
            cout << "=========================================================================================================================================================================================================\n";
        cout << "|" << "  NO" << setw(2) << "|"  
        << "       Nama" << setw(7) << "|" 
        << "  No. Rekam Medis" << setw(2) << "|"
        << "          TTL" << setw(10) << "|"
        << "     Kelamin" << setw(5) << "|"
        << "     Gol. Darah" << setw(5) << "|"
        << "       Alamat" << setw(7) << "|"
        << "    Penyakit" << setw(3) << "|"
        << "  Tanggal Masuk Pasien" << setw(2) << "|" 
        << "    Jenis Rawat" << setw(4) << "|"
            << "    Harga Rawat" << setw(4) << "|" << endl;
        cout << "=========================================================================================================================================================================================================\n";
        cout << "|  " << i+1 << setw(3) << "|"
        << setw(17) << data_pasien[k].nama_pasien << "|"
        << setw(18) << data_pasien[k].no_rekam_medis  << "|"
        << setw(22) << data_pasien[k].ttl  << "|"
        << setw(16) << data_pasien[k].jenis_kelamin  << "|"
        << setw(19) << data_pasien[k].gol_darah  << "|"
        << setw(19) << data_pasien[k].alamat  << "|"
        << setw(14) << data_pasien[k].penyakit  << "|"  
        << setw(23) << data_pasien[k].tgl_masuk  << "|"
        << setw(18) << data_pasien[k].rawat << "|"
        << setw(3) << "Rp" << setw(15)  << data_pasien[k].harga_rawat_inap << "|" << endl;
        cout << "=========================================================================================================================================================================================================\n";
        }else {
            if (cari_no_rekam_medis < data_pasien[k].no_rekam_medis){
                j = k-1;
            }else {
                i = k + 1;
            }
        }
    }
    if(!found){
       cout << "Data Pasien Tidak Ada" << endl;
    }
}

void shell_sort(int panjang){
    int i, j, k;
    for (k = panjang; k > 0; k /= 2){
        for (j = k; j < panjang; j++){
            for (i = j-k; i >= 0; i -= k){
                if (data_pasien[i+k].no_rekam_medis >= data_pasien[i].no_rekam_medis){
                    break;
                }else {
                    temp = data_pasien[i];
                    data_pasien[i] = data_pasien[i+k];
                    data_pasien[i + k] = temp;
                }
            }
        }
    }
}
