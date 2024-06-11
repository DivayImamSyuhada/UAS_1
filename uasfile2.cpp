#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct MenuItem {
    int id;
    string nama;
    double harga;
};

struct OrderItem {
    MenuItem* item;
    int jumlah;
};

vector<MenuItem> menu = {
    {1, "Espresso", 30000},
    {2, "Americano", 35000},
    {3, "Latte", 40000},
    {4, "Cappuccino", 45000},
    {5, "Mocha", 50000}
};

vector<OrderItem> pesanan;

void tampilkanSelamatDatang() {
    cout << R"(
 .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------. 
| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |
| | _____  _____ | || |  _________   | || |   _____      | || |     ______   | || |     ____     | || | ____    ____ | || |  _________   | |
| ||_   _||_   _|| || | |_   ___  |  | || |  |_   _|     | || |   .' ___  |  | || |   .'    `.   | || ||_   \  /   _|| || | |_   ___  |  | |
| |  | | /\ | |  | || |   | |_  \_|  | || |    | |       | || |  / .'   \_|  | || |  /  .--.  \  | || |  |   \/   |  | || |   | |_  \_|  | |
| |  | |/  \| |  | || |   |  _|  _   | || |    | |   _   | || |  | |         | || |  | |    | |  | || |  | |\  /| |  | || |   |  _|  _   | |
| |  |   /\   |  | || |  _| |___/ |  | || |   _| |__/ |  | || |  \ `.___.'\  | || |  \  `--'  /  | || | _| |_\/_| |_ | || |  _| |___/ |  | |
| |  |__/  \__|  | || | |_________|  | || |  |________|  | || |   `._____.'  | || |   `.____.'   | || ||_____||_____|| || | |_________|  | |
| |              | || |              | || |              | || |              | || |              | || |              | || |              | |
| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |
 '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------' 
                                                                                                                                       
    )" << '\n';
}

void tampilkanMenu() {
    cout << "======== MENU ========\n";
    for (const auto& item : menu) {
        cout << item.id << ". " << item.nama << " - Rp " << fixed << setprecision(2) << item.harga << endl;
    }
    cout << "======================\n";
}

void tambahItemKePesanan(int id, int jumlah) {
    for (auto& item : menu) {
        if (item.id == id) {
            pesanan.push_back({&item, jumlah});
            cout << jumlah << " x " << item.nama << " ditambahkan ke pesanan Anda.\n";
            return;
        }
    }
    cout << "Item tidak ditemukan dalam menu.\n";
}

void lihatPesanan() {
    if (pesanan.empty()) {
        cout << "Pesanan Anda kosong.\n";
        return;
    }
    cout << "======= PESANAN ANDA =======\n";
    double total = 0;
    for (const auto& orderItem : pesanan) {
        double itemTotal = orderItem.item->harga * orderItem.jumlah;
        total += itemTotal;
        cout << orderItem.jumlah << " x " << orderItem.item->nama << " - Rp " << fixed << setprecision(2) << itemTotal << endl;
    }
    cout << "Total: Rp " << fixed << setprecision(2) << total << endl;
    cout << "============================\n";
}

void hapusItemDariPesanan(int id) {
    for (auto it = pesanan.begin(); it != pesanan.end(); ++it) {
        if (it->item->id == id) {
            cout << it->jumlah << " x " << it->item->nama << " dihapus dari pesanan Anda.\n";
            pesanan.erase(it);
            return;
        }
    }
    cout << "Item tidak ditemukan dalam pesanan Anda.\n";
}

void checkout() {
    if (pesanan.empty()) {
        cout << "Pesanan Anda kosong.\n";
        return;
    }
    double total = 0;
    cout << "======= CHECKOUT =======\n";
    for (const auto& orderItem : pesanan) {
        double itemTotal = orderItem.item->harga * orderItem.jumlah;
        total += itemTotal;
        cout << orderItem.jumlah << " x " << orderItem.item->nama << " - Rp " << fixed << setprecision(2) << itemTotal << endl;
    }
    cout << "Total pembayaran: Rp " << fixed << setprecision(2) << total << endl;
    cout << "=========================\n";
    pesanan.clear();
}

int main() {
    int pilihan, id, jumlah;

    tampilkanSelamatDatang();
    
    while (true) {
        cout << "\n===== COFFEE SHOP =====\n";
        cout << "1. Lihat Menu\n";
        cout << "2. Tambah Item ke Pesanan\n";
        cout << "3. Lihat Pesanan\n";
        cout << "4. Hapus Item dari Pesanan\n";
        cout << "5. Checkout\n";
        cout << "6. Keluar\n"; 
        cout << "======================= \n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanMenu();
                break;
            case 2:
                cout << "Masukkan ID item: ";
                cin >> id;
                cout << "Masukkan jumlah: ";
                cin >> jumlah;
                tambahItemKePesanan(id, jumlah);
                break;
            case 3:
                lihatPesanan();
                break;
            case 4:
                cout << "Masukkan ID item untuk dihapus: ";
                cin >> id;
                hapusItemDariPesanan(id);
                break;
            case 5:
                checkout();
                break;
            case 6:
                cout << "Terima kasih telah mengunjungi coffee shop kami!\n";
                return 0;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    }
}
