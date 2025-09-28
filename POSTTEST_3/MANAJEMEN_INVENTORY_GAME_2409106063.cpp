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
    Item *prev;
};

Item *head = nullptr;
Item *tail = nullptr;
int panjangList = 0;

void addFirst(const string &nama, int jumlah, const string &tipe) 
{
    Item *nodeBaru = new Item{nama, jumlah, tipe, head, nullptr};
    if (head == nullptr && tail == nullptr) 
    {
        head = tail = nodeBaru;
    } 
    else 
    {
        head->prev = nodeBaru;
        head = nodeBaru;
    }
    panjangList++;
}

void addLast(const string &nama, int jumlah, const string &tipe) 
{
    Item *nodeBaru = new Item{nama, jumlah, tipe, nullptr, tail};
    if (head == nullptr && tail == nullptr) 
    {
        head = tail = nodeBaru;
    } 
    else 
    {
        tail->next = nodeBaru;
        tail = nodeBaru;
    }
    panjangList++;
}

void addSpecific(const string &nama, int jumlah, const string &tipe, int posisi) 
{
    if (posisi <= 1 || head == nullptr) 
    {
        addFirst(nama, jumlah, tipe);
        return;
    }
    if (posisi > panjangList) 
    {
        addLast(nama, jumlah, tipe);
        return;
    }
    Item *temp = head;
    for (int i = 1; i < posisi - 1; i++) temp = temp->next;
    Item *nodeBaru = new Item{nama, jumlah, tipe, temp->next, temp};
    temp->next->prev = nodeBaru;
    temp->next = nodeBaru;
    panjangList++;
}

void deleteLast() 
{
    if (head == nullptr && tail == nullptr) 
    {
        cout << ">> Inventory kosong <<\n";
        return;
    } 
    else if (head->next == nullptr) 
    {
        delete head;
        head = tail = nullptr;
    } 
    else 
    {
        Item *del = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete del;
    }
    panjangList--;
    cout << "Item terakhir dihapus.\n";
}

void tampilkan(int arah) 
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
    if (arah == 1) 
    {
        Item *temp = head;
        int i = 1;
        while (temp != nullptr) 
        {
            cout << left << setw(5) << i++ << setw(25) << temp->namaItem
                 << setw(10) << temp->jumlah << setw(15) << temp->tipe << endl;
            temp = temp->next;
        }
    } 
    else 
    {
        Item *temp = tail;
        int i = panjangList;
        while (temp != nullptr) 
        {
            cout << left << setw(5) << i-- << setw(25) << temp->namaItem
                 << setw(10) << temp->jumlah << setw(15) << temp->tipe << endl;
            temp = temp->prev;
        }
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
    while (temp != nullptr && temp->namaItem != nama) temp = temp->next;
    if (temp == nullptr) 
    {
        cout << "Item tidak ditemukan.\n";
        return;
    }
    temp->jumlah--;
    cout << "Berhasil menggunakan 1 " << nama << ". Sisa : " << temp->jumlah << endl;
    if (temp->jumlah <= 0) 
    {
        if (temp == head && temp == tail) 
        {
            delete temp;
            head = tail = nullptr;
        } 
        else if (temp == head) 
        {
            head = head->next;
            head->prev = nullptr;
            delete temp;
        } 
        else if (temp == tail) 
        {
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        } 
        else 
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
        panjangList--;
        cout << "Item " << nama << " habis dan dihapus dari inventory.\n";
    }
}


bool adaSubstring(const string &teks, const string &cari) 
{
    string t = teks, c = cari;
    for (auto &ch : t) ch = tolower(ch);
    for (auto &ch : c) ch = tolower(ch);
    return t.find(c) != string::npos;
}

void cariDetail(const string &kata) 
{
    if (head == nullptr) 
    {
        cout << ">> Inventory kosong <<\n";
        return;
    }
    Item *temp = head;
    bool ditemukan = false;
    cout << "\n+-------------------------------------------------------------+\n";
    cout << left << setw(5) << "No" << setw(25) << "Nama Item" << setw(10)
         << "Jumlah" << setw(15) << "Tipe" << endl;
    cout << "+-------------------------------------------------------------+\n";
    int i = 1;
    while (temp != nullptr) 
    {
        if (adaSubstring(temp->namaItem, kata)) 
        {
            cout << left << setw(5) << i << setw(25) << temp->namaItem
                 << setw(10) << temp->jumlah << setw(15) << temp->tipe << endl;
            ditemukan = true;
        }
        temp = temp->next;
        i++;
    }
    cout << "+-------------------------------------------------------------+\n";
    if (!ditemukan) cout << "Item tidak ditemukan.\n";
}

string pilihTipe() 
{
    int pil;
    cout << "Pilih tipe item:\n";
    cout << "1. Sword\n2. Potion\n3. Shield\n4. Armor\n5. Lainnya\n";
    cout << "Masukkan pilihan (1-5) : ";
    while (!(cin >> pil) || pil < 1 || pil > 5) 
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Masukkan angka 1-5 : ";
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
            cout << "Masukkan tipe lainnya : ";
            getline(cin, t);
            return t;
        }
    }
}

void pauseMsg(const string &msg = "\nTekan ENTER untuk melanjutkan...") 
{
    cout << msg;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
        cout << "|        GAME INVENTORY MANAGEMENT                    |\n";
        cout << "|     [ " << namaAnda << " - " << nimAnda << " ]           |\n";
        cout << "+-----------------------------------------------------+\n";
        cout << "| 1. Tambah Item Baru                                 |\n";
        cout << "| 2. Sisipkan Item                                    |\n";
        cout << "| 3. Hapus Item Terakhir                              |\n";
        cout << "| 4. Gunakan Item                                     |\n";
        cout << "| 5. Tampilkan Inventory                              |\n";
        cout << "| 6. Cari Detail Item                                 |\n";
        cout << "| 0. Keluar                                           |\n";
        cout << "+-----------------------------------------------------+\n";
        cout << "Pilih menu : ";
        while (!(cin >> pilihan)) 
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Masukkan angka menu : ";
        }
        cin.ignore();

        if (pilihan == 1) 
        {
            string nama;
            cout << "Nama Item : ";
            getline(cin, nama);
            string tipe = pilihTipe();
            addLast(nama, jumlahDefault, tipe);
            cout << "Item berhasil ditambahkan.\n";
            tampilkan(1);
            pauseMsg();
        } 
        else if (pilihan == 2) 
        {
            string nama;
            cout << "Nama Item : ";
            getline(cin, nama);
            string tipe = pilihTipe();
            addSpecific(nama, jumlahDefault, tipe, posisiSisip);
            cout << "Item berhasil disisipkan di posisi " << posisiSisip << ".\n";
            tampilkan(1);
            pauseMsg();
        } 
        else if (pilihan == 3) 
        {
            deleteLast();
            tampilkan(1);
            pauseMsg();
        } 
        else if (pilihan == 4) 
        {
            tampilkan(1);
            string nama;
            cout << "Masukkan nama item yang ingin digunakan : ";
            getline(cin, nama);
            gunakanItem(nama);
            tampilkan(1);
            pauseMsg();
        } 
        else if (pilihan == 5) 
        {
            int subpil;
            do 
            {
                cout << "\n+---------------- TAMPILKAN INVENTORY ----------------+\n";
                cout << "1. Urut dari depan\n2. Urut dari belakang\n0. Kembali ke menu utama\n";
                cout << "Pilih : ";
                while (!(cin >> subpil) || subpil < 0 || subpil > 2) 
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Masukkan angka 0,1,2 : ";
                }
                cin.ignore();
                if (subpil == 1 || subpil == 2) 
                {
                    tampilkan(subpil);
                    pauseMsg();
                }
            } 
            while (subpil != 0);
        } 
        else if (pilihan == 6) 
        {
            string nama;
            cout << "Masukkan kata/nama item yang ingin dicari : ";
            getline(cin, nama);
            cariDetail(nama);
            pauseMsg();
        } 
        else if (pilihan == 0) 
        {
            cout << "Keluar dari program...\n";
        } 
        else 
        {
            cout << "Pilihan tidak valid.\n";
            pauseMsg();
        }

    } 
    while (pilihan != 0);

    return 0;
}
