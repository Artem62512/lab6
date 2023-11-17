#include <fstream>
#include <string>
#include <iostream>

// picture 2

using namespace std;

class Bonjur
{
public:
    float m[19];
    const char ch = '\n';
    char mass[30][19];

    float line(int x)
    {
        float y = 0;
        if (x >= -10 && x < -8)
        {
            y = -3;
        }
        if (x >= -8 && x < -3)
        {
            y = (x + 3) * (0.6);
        }
        if (x >= -3 && x < 3)
        {
            y = sqrt(9 - x * x);
        }
        if (x >= 3 && x <= 5)
        {
            y = x - 3;
        }
        if (x > 5 && x <= 8)
        {
            y = 3;
        }
        return y;
    }

    void write_to_massive()
    {
        for (int i = -10; i <= 8; i++)
        {
            m[i + 10] = line(i);
        }
    }

    void write()
    {
        ofstream fout("lab1.txt"); // создание текстового файла
        for (int i = -10; i <= 8; i++)
        {
            fout << "x = " << i << "   y = " << line(i) << endl; // запись значений в файл
        }
        fout.close(); // закрываем файл
    }
    void read()
    {
        
        int x = 0;
        ifstream fin("lab1.txt"); // открываем текстовый файл
        
        for (int r = 0; r <= 19; r++)
        {
            fin.getline(mass[r], 30 - 1, ch); // Считываем строки в массив
            cout << mass[r] << endl;          // Выводи строку из массива
        }
        fin.close(); // Закрываем файл
    }
};

float main()
{
    Bonjur joni;
    int x = 0;
    cin >> x;
    cout << joni.line(x) << endl;
    joni.write_to_massive();
    joni.write();
    joni.read();
}