#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

string cekTebakan(int tebakan, int angkaRahasia) {
    if(tebakan < angkaRahasia) {
        return "Terlalu kecil!";
    } else if(tebakan > angkaRahasia) {
        return "Terlalu besar!";
    } else {
        return "Benar!";
    }
}
int pilihLevel() {
    int pilihan;
    cout << "Pilih level kesulitan:" << endl;
    cout << "1. Easy (1 - 20)" << endl;
    cout << "2. Medium (1 - 50)" << endl;
    cout << "3. Hard (1 - 100)" << endl;
    cout << "Masukkan pilihan (1/2/3): ";
    cin >> pilihan;
    
    if (pilihan == 1) return 20;
    else if (pilihan == 2) return 50;
    else return 100; 
}

void mainGame (){
    srand(time(0));
    
    int batas = pilihLevel();
    int angkaRahasia = rand() % batas + 1;
    int tebakan, percobaan = 0;
    
    cout << "\n Selamat datang di Game Tebak Angka!" << endl;
    cout << "Saya sudah memilih angka antara 1 sampai " << batas << " . " << endl;
    
    while (true) {
        cout << "Masukkan tebakanmu: ";
        cin >> tebakan;
        percobaan++;
        
        string hasil = cekTebakan(tebakan, angkaRahasia);
        cout << hasil << endl;
        
        if (hasil == "Benar!") {
            cout << "Selamat! Kamu berhasil menebak dalam " << percobaan << " kali percobaan." << endl;
            break;
        }
    }
}

int main() {
    mainGame();
    return 0;
}
