#include <iostream>
#include <fstream>
#include <cstdlib>
#include <chrono>
using namespace std;
using namespace std::chrono;
const int size = 8;

void move(int n, char source, char destination)
{
    cout << "move disc : " << n << " from " << source << " to " << destination << endl;
}

void TOH(int n, char source, char spare, char destination)
{
    if (n == 0)
        return;
    else
        TOH(n - 1, source, destination, spare);
    move(n, source, destination);
    TOH(n - 1, spare, source, destination);
}

int main()
{
    fstream file;
    int avg_time = 0;
    int total_time = 0;
    file.open("tower_of_hanoi.txt", ios::out);
    for (int i = 2; i <= 16; i = i * 2)
    {
        avg_time = 0;
        total_time = 0;
        char source = 'A';
        char spare = 'B';
        char destination = 'C';
        for (int m = 0; m < 10; m++)
        {
            cout << "trial : " << m + 1 << endl;
            auto start = high_resolution_clock::now();
            TOH(i, source, spare, destination);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            total_time += duration.count();
        }
        avg_time = total_time / 10;
        cout << "avg time taken by disc " << i << " is " << avg_time << " microseconds" << endl;
        file << "(" << i << "," << avg_time << ")" << endl;
    }
}