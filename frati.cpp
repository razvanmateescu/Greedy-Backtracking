// Copyright 2018 Mateescu Razvan
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

bool comparaegal(pair <int, int> v1, pair <int, int> v2) {
    return v1.first > v2.first;
}

bool compara(pair <int, int>  v1, pair <int, int> v2) {
    int suma1 = v1.first +v1.second;
    int suma2 = v2.first +v2.second;
    return suma1 > suma2;
}

int main(int argc, char* argv[]) {
	vector< pair <int, int> > vect;
	ifstream fin("frati.in");
	int N, a, b, j, nr, sum1 = 0, sum2 = 0, max = 0;
	fin >> N;
	for (int i = 0 ; i < N ; ++i) {
		fin >> a >> b;
		vect.push_back(make_pair(a, b));
	}
	sort(vect.begin(), vect.end(), compara);
	int i = 0;
	while (i < N) {
		int s = 0;
		j = 0;
		nr = 0;
		while (vect[i].first + vect[i].second == vect[i+1].first + vect[i+1].second) {
			nr++;
		 	if (nr == 1) {
		 		j = i;
			}
			i++;
			s++;
		}
			sort(vect.begin()+j, vect.begin() + j + s + 1, comparaegal);
			i++;
	}
	int k = 0;
	int z = 0;
	int nr2 = 0;
	int y = 0;
	int v[N];
	for (i = 0 ; i < N ; i++) {
		v[i] = 0;
	}
	i = 0;
	while (i < N) {
		if(vect[i].first + vect[i].second != vect[i+1].first + vect[i+1].second) {
			if(k%2 == 0) {
				sum1 = sum1 + vect[i].first;
				k++;
				i++;
			} else {
				sum2 = sum2 + vect[i].second;
				k++;
				i++;
			}
		} else {
			nr = 0;
			z = i;
	  		y = i;

			while(vect[y].first+vect[y].second == vect[y+1].first +vect[y+1].second) {
				nr++;
				y++;
			}
		nr2 = nr;
		while(i <= z + nr) {
			if(k % 2 == 0) {
				if(v[i] == 0) {
					sum1 = sum1+vect[i].first;
					v[i] = 1;
					i++;
					k++;
				}
			} else {
				if(v[z+nr] == 0) {
					sum2 = sum2 + vect[z+nr].second;
					v[z+nr] = 1;
					nr--;
					k++;
				}
			}
		}
		i = z+nr2+1;
	}
	}
	ofstream fout("frati.out");
	fout << sum1 << " " << sum2;
	fout.close();
}
