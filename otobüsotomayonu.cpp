#include <iostream>
#include <string>
#include <locale.H>


using namespace std;

struct Otobus {
    int hatNumarasi;
    string guzergah;
    double ucret;
};

struct YolcuKarti {
    double bakiye;
    string kartTipi;
};

void hatlariGoster(Otobus otobusler[]) {
    cout << "***ISPARTA BELEDIYESI OTOBUS HATLARI***";
    for (int i = 0; i < 4; i++) {
        cout << "Hat No: " << otobusler[i].hatNumarasi 
             << " Guzergah: " << otobusler[i].guzergah 
             << " Ucret: " << otobusler[i].ucret << " TL" << endl;
    }
    
}

int main() {
    setlocale(LC_ALL, "Turkish");

    Otobus otobusFilosu[4] = {
        {33, "SDU Dogu - Cunur - Carsi", 15.0},
        {48, "SDU - Tip Fakultesi - Terminal", 15.0},
        {37, "Sanayi - Carsi - Halikent", 15.0},
        {9, "Carsi - Anadolu Mahallesi", 15.0}
    };

    YolcuKarti kartim;
    kartim.bakiye = 50.0;
    kartim.kartTipi = "Tam Kart";

    int secim;
    bool donguDevam = true;

    cout << "Isparta Sehir Ici Ulasim Sistemine Hosgeldiniz" << endl;

    while (donguDevam) {
        cout << "MEVCUT BAKIYE: " << kartim.bakiye << " TL" << endl;
        cout << "1. Hatlari Listele" << endl;
        cout << "2. Otobuse Bin (Kart Bas)" << endl;
        cout << "3. Bakiye Yukle" << endl;
        cout << "4. Cikis" << endl;
        cout << "Seciminiz: ";
        cin >> secim;

        switch (secim) {
            case 1:
                hatlariGoster(otobusFilosu);
                break;

            case 2: {
                int binilecekHat;
                bool hatBulundu = false;
                cout << "Binmek istediginiz otobus numarasini girin (33, 48, 37, 9): ";
                cin >> binilecekHat;

                for (int i = 0; i < 4; i++) {
                    if (otobusFilosu[i].hatNumarasi == binilecekHat) {
                        hatBulundu = true;
                        if (kartim.bakiye >= otobusFilosu[i].ucret) {
                            kartim.bakiye -= otobusFilosu[i].ucret;
                            cout << "ISLEM BASARILI!" << endl;
                            cout << binilecekHat << " Nolu otobuse bindiniz." << endl;
                            cout << "Kalan Bakiye: " << kartim.bakiye << " TL" << endl;
                        } else {
                            cout << "YETERSIZ BAKIYE!" << endl;
                            cout << "Lutfen bakiye yukleyiniz." << endl;
                        }
                        break;
                    }
                }

                if (!hatBulundu) {
                    cout << "Hatali hat numarasi girdiniz! Boyle bir otobus yok." << endl;
                }
                break;
            }

            case 3: {
                double yuklenecekTutar;
                cout << "Yuklenecek miktari giriniz: ";
                cin >> yuklenecekTutar;
                if (yuklenecekTutar > 0) {
                    kartim.bakiye += yuklenecekTutar;
                    cout << "Yukleme Basarili. Yeni Bakiye: " << kartim.bakiye << " TL" << endl;
                } else {
                    cout << "Gecersiz tutar." << endl;
                }
                break;
            }

            case 4:
                cout << "Sistemden cikiliyor.İYİ GÜNLER DİLERİZ :))" << endl;
                donguDevam = false;
                break;

            default:
                cout << "Hatali secim yaptiniz, tekrar deneyin." << endl;
        }
    }

    return 0;
}