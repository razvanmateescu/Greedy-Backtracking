// Copyright 2018 Mateescu Razvan
#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int solutie[150];
int suma_curenta, nr_elemente, x;
long long I;
int S, K;
int index_curent = -1;
bool exista_solutie = false;

void afisare() {
    index_curent++;
    if (index_curent != I) return;
    ofstream fout("numaratoare.out");
	fout << S << "=";
    for (int i = 1; i < K; ++i)
    fout << solutie[i] << "+";
    fout << solutie[K];
	fout.close();
    exista_solutie = true;
}

void backtrack(int Max) {
    if (index_curent >= I) return;
    if (suma_curenta == S && nr_elemente == K) { afisare();
    } else {
        for (int i = Max; i > 0; --i)
            if (suma_curenta + i > S || nr_elemente + 1 > K) { continue;
            } else {
                suma_curenta += i;
                solutie[++nr_elemente] = i;
                backtrack(min(S-suma_curenta-(K-nr_elemente)+1, i));
                suma_curenta -= i;
                nr_elemente--;
            }
         }
}

int main() {
	ifstream fin("numaratoare.in");
	fin >> S >> K >> I;
    backtrack(S-K+1);
    if (exista_solutie == false) {
	ofstream fout("numaratoare.out");
	fout << "-";
	fout.close();
	}
    return 0;
}

