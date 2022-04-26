#include <iostream>
#include <vector>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Генерирование k-элементных подмножеств заданного множества:" << endl;
    cout << "Введите n: ";
    int n;
    cin >> n;
    cout << "Введите множество (после каждого элемента нажмите <Enter>: " << endl;
    vector <int> a;
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        a.push_back(s);
    }
    cout << "Введите k: ";
    int k;
    cin >> k;
    vector <int> b;
    for (int i = 1; i <= n; i++) {
        b.push_back(i);
    }
    vector <int> c;
    for (int i = 0; i < k; i++) {
        c.push_back(a[i]);
    }
    vector <int> c1;
    for (int i = 1; i <= k; i++) {
        c1.push_back(i);
    }
    
    int n1 = 1, k1 = 1, nk = 1;
    for (int i = 1; i <= n; i++) {
        n1 *= i;
    }
    for (int i = 1; i <= k; i++) {
        k1 *= i;
    }
    for (int i = 1; i <= n - k; i++) {
        nk *= i;
    }
    int q = n1 / ((nk) * k1);
 

    int p = k;
    for (int i = 0; i < q; i++) {      
        cout << "{";
        for (int g = 0; g < k; g++) {
            cout << c[g] << " ";
        }
        cout << "}" << endl;
        if (c[k - 1] == a[n - 1]) {
            p -= 1;      
        }
        else {
            p = k;
        }
        
        
        if (p >= 1) {
            for (int j = k; j >= p; j--) {
                c[j - 1] = a[c1[p - 1] + j - p];
                c1[j - 1] = b[c1[p - 1] + j - p];
            }
        }
        
    }
}

