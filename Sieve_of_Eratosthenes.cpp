#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <fstream>
#include <algorithm>

using namespace std;


int main() {
    ofstream fout;
    fout.open("primes.txt");
    vector <bool> is_prime(33554432);
    for (int i = 0; i < is_prime.size(); i++)
        is_prime[i] = true;
    int number = 2;
    while (number <= 33554432 - 2000) {
        cout << number << "\n";
        fout << number << "\n";
        int tmp = number;
        for (int i = tmp * 2; i < is_prime.size(); i += tmp) 
            is_prime[i] = false;
        for (int i = ++number; i < is_prime.size(); i++) {
            if (is_prime[i] == true) {
                //cout << i << "\n";
                number = i;
                break;
            }
        }
    }
    fout.close();
}
