#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {

	char alf[36] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	std::fstream odczyt("in.txt");
	std::fstream zapis("out.txt");
	std::string temp;
	std::string tekst="";
	std::string element=" ";
	std::vector<std::string> powt;
	int D=0,L,All=0;
	int tab[19] = { 0 };
	std::string start, znacznik, licznik;
	std::cout << "Lamanie szyfru Vigenere - analiza Kasiskiego" << std::endl;
	std::cout << "Podaj minimalna dlugosc powtorzenia(L): " << std::endl;
	std::cin >> L;
	int x = 0, y = 0;
	bool flag = 0;

	while (getline(odczyt, temp, '\n')) {
		for (int i = 0; i < temp.length(); i++) {
			for (int j = 0; j < 36; j++) {
				if (temp[i] == alf[j]) {
					tekst += temp[i];
				}
			}
		}
		tekst += "\n";
	}
	std::cout << tekst << std::endl;
	//for (int m = 2; m < 21; m++) {
		//std::string element = "";
		//std::vector<std::string> powt;
		D = 0, All = 0;
		flag = 0;
		for (int i = 0; i < tekst.length(); i+=L) {
			x = i;
			for (int j = (i + L + 1); j < tekst.length(); j++) {
				if(tekst[i]==tekst[j] && flag==0) {
					//std::cout << "first condition: " << tekst[x] << " " << tekst[j] << " i: " << i << " j: " << j << std::endl;
					//std::cout << x << std::endl;
					//D++;
					x++;
					element += tekst[j];
					flag = 1;					
					continue;
				}
				if (flag == 1 && (tekst[x] == tekst[j])){
					//std::cout << "second condition: " << tekst[x] << " " << tekst[j] << " i: " << i << " j: " << j << std::endl;
					D++;
					x++;
					element += tekst[j];
					continue;
				}
				if (tekst[x] != tekst[j] && flag==1){
					bool flag2 = 0;
					//std::cout << x - 1 << " " << D << std::endl;
					//std::cout << "third condition: " << tekst[x] << " " << tekst[j] << " " << i << " " << j << " " << D << std::endl;
					//std::cout << "third condition: " << element << " "<< D << std::endl;
					//std::cout << powt.size();
					if (D >= L) {
						if (powt.size() == 0)powt.push_back(element);
						else {
							int k = powt.size();
							for (int w = 0; w < k; w++) {
								//std::cout << "tab: " << element << " " << powt[w] << " " << powt.size() << std::endl;
								if (element == powt[w]) {
									flag2 = 1;
									//std::cout << "tab: 1"  << std::endl;
								}
								
							}
							if (!flag2) {
								//std::cout << "tab: 2 " << element << std::endl;
								powt.push_back(element);
							}
						}
						//All++;
						//std::cout << "D: " << D << " m: " << m << " D%m: " << D%m<<std::endl;
						for (int m = 2; m < 21; m++) {
							//std::cout << "D: " << D << " m: " << m << " D%m: " << D % m << std::endl;
							if (D >= m) {
								if (D % m == 0 ) tab[m - 2]++;
							}
							else {
								if (m % D == 0) tab[m - 2]++;
							}
						}
						
						x = i;
						D = 0;
						flag = 0;
					}
					else {
						x = i;
						D = 0;
						flag = 0;
					}
					//std::cout << powt.size();
					element = "";
					//std::cout << powt.size() << " " << i << std::endl;;
				}
			}
		}
	//}
	std::cout << "Ilosc powtorzen: " << powt.size() << std::endl;
	for (int i = 2; i < 21; i++) {
		std::cout << "m=" << i << " : " << tab[i - 2] << std::endl;
	}
	
	return 0;
}