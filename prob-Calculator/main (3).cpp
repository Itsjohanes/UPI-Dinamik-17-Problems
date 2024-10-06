#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> ones = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
vector<string> teens = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
vector<string> tens = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
vector<string> thousands = { "", "Thousand", "Million", "Billion" };

string convertToWords(int n) {
    if (n == 0) return "Zero";
    
    string result = "";
    int i = 0;

    while (n > 0) {
        int chunk = n % 1000;
        if (chunk > 0) {
            string chunkStr = "";
            if (chunk >= 100) {
                chunkStr += ones[chunk / 100] + " Hundred ";
                chunk %= 100;
            }
            if (chunk >= 20) {
                chunkStr += tens[chunk / 10] + " ";
                chunk %= 10;
            }
            if (chunk >= 10 && chunk < 20) {
                chunkStr += teens[chunk - 10] + " ";
            } else if (chunk > 0) {
                chunkStr += ones[chunk] + " ";
            }
            result = chunkStr + thousands[i] + " " + result;
        }
        n /= 1000;
        i++;
    }

    return result.substr(0, result.size() - 1); // Remove trailing space
}

int main() {
    long long a, b;
    cout << "Masukkan dua angka (a dan b): ";
    cin >> a >> b;

    long long sum = a + b;
    string result = convertToWords(sum);
    
    cout << result << endl;
    return 0;
}
