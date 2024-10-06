#include <iostream>

int main() {
    int n, m, p, q;
    std::cin >> n >> m >> p >> q;

    // Simulasi bulanan
    for (int month = 1; month <= q; ++month) {
        // Bulan ke-1 dan ke-2 hanya menghasilkan anak bebek
        if (month > 2) {
            n -= p; // Jual bebek setiap bulan setelah bulan ke-2
        }

        // Setiap dua bebek menghasilkan m anak bebek
        if (month > 0) {
            n += (n / 2) * m; // Hitung jumlah anak bebek
        }
    }

    std::cout << n << std::endl;

    return 0;
}
