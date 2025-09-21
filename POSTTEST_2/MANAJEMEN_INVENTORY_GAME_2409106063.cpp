#include <iostream>
#include <iomanip>
#include <string>
#include <limits> 
using namespace std;

struct Item 
{
    string namaItem;
    int jumlah;
    string tipe;
    Item *next;
};

Item *head = nullptr;

void addFirst(const string &nama, int jumlah, const string &tipe) 
{
    Item *nodeBaru = new Item{nama, jumlah, tipe, head};
    head = nodeBaru;
}

void addLast(const string &nama, int jumlah, const string &tipe) 
{
    Item *nodeBaru = new Item{nama, jumlah, tipe, nullptr};
    if (head == nullptr) 
    {
        head = nodeBaru;
        return;
    }
    Item *temp = head;
    while (temp->next != nullptr) temp = temp->next;
    temp->next = nodeBaru;
}

void addSpecific(const string &nama, int jumlah, const string &tipe, int posisi) {
    if (posisi <= 1 || head == nullptr) 
    {
        addFirst(nama, jumlah, tipe);
        return;
    }
    Item *temp = head;
    int hitung = 1;
    while (temp->next != nullptr && hitung < posisi - 1) 
    {
        temp = temp->next;
        hitung++;
    }
    Item *nodeBaru = new Item{nama, jumlah, tipe, temp->next};
    temp->next = nodeBaru;
}

void deleteLast() 
{
    if (head == nullptr) 
    {
        cout << ">> Inventory kosong <<\n";
        return;
    }
    if (head->next == nullptr) 
    {
        delete head;
        head = nullptr;
        cout << "Item terakhir dihapus.\n";
        return;
    }
    Item *temp = head;
    while (temp->next->next != nullptr) temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
    cout << "Item terakhir dihapus.\n";
}

void display() 
{
    if (head == nullptr) 
    {
        cout << ">> Inventory kosong <<\n";
        return;
    }
    cout << "\n+-------------------------------------------------------------+\n";
    cout << left << setw(5) << "No" << setw(25) << "Nama Item" << setw(10)
         << "Jumlah" << setw(15) << "Tipe" << endl;
    cout << "+-------------------------------------------------------------+\n";
    Item *temp = head;
    int i = 1;
    while (temp != nullptr) 
    {
        cout << left << setw(5) << i++ << setw(25) << temp->namaItem << setw(10)
             << temp->jumlah << setw(15) << temp->tipe << endl;
        temp = temp->next;
    }
    cout << "+-------------------------------------------------------------+\n";
}

void gunakanItem(const string &nama) 
{
    if (head == nullptr) 
    {
        cout << ">> Inventory kosong <<\n";
        return;
    }
    Item *temp = head;
    Item *prev = nullptr;
    while (temp != nullptr && temp->namaItem != nama) 
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr) 
    {
        cout << "Item tidak ditemukan.\n";
        return;
    }
    temp->jumlah--;
    cout << "Berhasil menggunakan 1 " << nama << ". Sisa: " << temp->jumlah << endl;
    if (temp->jumlah <= 0) 
    {
        if (prev == nullptr)
            head = temp->next;
        else
            prev->next = temp->next;
        delete temp;
        cout << "Item " << nama << " habis dan dihapus dari inventory.\n";
    }
}

string pilihTipe() 
{
    int pil;
    cout << "Pilih tipe item:\n";
    cout << "1. Sword\n2. Potion\n3. Shield\n4. Armor\n5. Lainnya\n";
    cout << "Masukkan pilihan (1-5): ";
    while (!(cin >> pil) || pil < 1 || pil > 5) 
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Masukkan angka 1-5: ";
    }
    cin.ignore();
    switch (pil) 
    {
        case 1: return "Sword";
        case 2: return "Potion";
        case 3: return "Shield";
        case 4: return "Armor";
        default: 
        {
            string t;
            cout << "Masukkan tipe lainnya: ";
            getline(cin, t);
            return t;
        }
    }
}

void pauseAndClear() {
    cout << "\nTekan ENTER untuk melanjutkan...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() 
{
    string namaAnda = "Anindtya Puji Astari";
    string nimAnda = "2409106063";

    int jumlahDefault = 63; 
    int digitTerakhir = nimAnda[nimAnda.size() - 1] - '0';
    int posisiSisip = digitTerakhir + 1;

    addLast("Pedang Pemula", jumlahDefault, "Sword");
    addLast("Ramuan Penyembuh", jumlahDefault, "Potion");
    addLast("Perisai Kayu", jumlahDefault, "Shield");
    addLast("Baju Zirah Latihan", jumlahDefault, "Armor");
    addLast("Panah Pemula", jumlahDefault, "Sword");

    int pilihan;
    do 
    {
        cout << "\n+-----------------------------------------------------+\n";
        cout << "|           GAME INVENTORY MANAGEMENT                 |\n";
        cout << "|     [ " << namaAnda << " - " << nimAnda << " ]           |\n";
        cout << "+-----------------------------------------------------+\n";
        cout << "| 1. Tambah Item Baru                                 |\n";
        cout << "| 2. Sisipkan Item                                    |\n";
        cout << "| 3. Hapus Item Terakhir                              |\n";
        cout << "| 4. Gunakan Item                                     |\n";
        cout << "| 5. Tampilkan Inventory                              |\n";
        cout << "| 0. Keluar                                           |\n";
        cout << "+-----------------------------------------------------+\n";
        cout << "Pilih menu: ";
        while (!(cin >> pilihan)) 
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Masukkan angka menu: ";
        }
        cin.ignore();

        if (pilihan == 1) 
        {
            string nama;
            cout << "Nama Item: ";
            getline(cin, nama);
            string tipe = pilihTipe();
            addLast(nama, jumlahDefault, tipe);
            cout << "Item berhasil ditambahkan.\n";
            display();
            pauseAndClear();
        } 
        else if (pilihan == 2) 
        {
            string nama;
            cout << "Nama Item: ";
            getline(cin, nama);
            string tipe = pilihTipe();
            addSpecific(nama, jumlahDefault, tipe, posisiSisip);
            cout << "Item berhasil disisipkan di posisi " << posisiSisip << ".\n";
            display();
            pauseAndClear();
        } 
        else if (pilihan == 3) 
        {
            deleteLast();
            display();
            pauseAndClear();
        } 
        else if (pilihan == 4) 
        {
            display();
            string nama;
            cout << "Masukkan nama item yang ingin digunakan: ";
            getline(cin, nama);
            gunakanItem(nama);
            display();
            pauseAndClear();
        } 
        else if (pilihan == 5) 
        {
            display();
            pauseAndClear();
        } 
        else if (pilihan == 0) 
        {
            cout << "Keluar dari program...\n";
        } 
        else 
        {
            cout << "Pilihan tidak valid.\n";
            pauseAndClear();
        }

    } 
    while (pilihan != 0);

    return 0;
}
