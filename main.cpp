#include <iostream>
#include <string>
#include "adamasmaca.h"
#include <vector>
#include <algorithm>
#include <random>
#include <fstream>
#include <chrono>
#include <thread>
#include <cctype>
#include <limits>
using namespace std;
int main() {
	bool tahminEdildiMi = false;
	bool isWin = false;
	int sayac = 0;
	string tahmin;
	char tahminChar;
	string tahminString;
	vector<char> hataliTahminler;
	bool isDogruTahmin = false;
	string kelime;
	int hataSayi = 0;
	int secim;
	int kelimeTuru;
	int dilSecim = 0;
	while(dilSecim != 1 && dilSecim != 2){
	cout << "Choose a language: (TR: 1, EN: 2)" << endl;
	cin >> dilSecim;
	if(dilSecim == 1){
		ifstream dosyaMeslek("meslek.txt");
		ifstream dosyaSehir("sehir.txt");
		ifstream dosyaUlke("ulke.txt");
		ifstream dosyaHayvan("hayvan.txt"); 
	}
	else if(dilSecim == 2){
		ifstream fileJobs("jobs.txt");
		ifstream fileCities("cities.txt");
		ifstream fileCountries("countries.txt");
		ifstream fileAnimals("animals.txt");
		vector<string> kelimeler(50);
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, kelimeler.size() - 1);
	int randomSayi = dis(gen);
	hosgeldinMesajIng();
	cin >> secim;
	while (secim != 1) {
		
		switch (secim) {
		
		case 2:
			kuralGosterIng();
			hosgeldinMesajIng();
			cin >> secim;
			break;
		case 3:
			cout << "Leaving the game..." << endl;
			std::this_thread::sleep_for(std::chrono::seconds(3));
			return 0;

		default:
			cout << "Invalid choice. Returning to main menu..." << endl;
			std::this_thread::sleep_for(std::chrono::seconds(3));
			main();
			return 0;
		}
	}
	if (secim == 1) {
		cout << "1. Jobs" << endl;
		cout << "2. Cities" << endl;
		cout << "3. Countries" << endl;
		cout << "4. Animals" << endl;
		cout << "Please choose a type of word: ";
		if (!(cin >> kelimeTuru)) {
			cout << "Invalid choice. Returning to main menu...";
			std::this_thread::sleep_for(std::chrono::seconds(3));
			main();
			return 0;
		}
	}
	
	ifstream dosya;
		switch (kelimeTuru) {
			
		case 1:
			dosya.open("jobs.txt");
			for (int i = 0; i < kelimeler.size(); i++) {
				getline(dosya, kelimeler[i]);
			}
			kelime = kelimeler[randomSayi];
			break;
		case 2:
			dosya.open("cities.txt");
			for (int i = 0; i < kelimeler.size(); i++) {
				getline(dosya, kelimeler[i]);
			}
			kelime = kelimeler[randomSayi];
			break;
		case 3:
			dosya.open("countries.txt");
			for (int i = 0; i < kelimeler.size(); i++) {
				getline(dosya, kelimeler[i]);
			}
			kelime = kelimeler[randomSayi];
			break;
		case 4:
			dosya.open("animals.txt");
			for (int i = 0; i < kelimeler.size(); i++) {
				getline(dosya, kelimeler[i]);
			}
			kelime = kelimeler[randomSayi];
			break;
		default:
			cout << "Invalid choice. Returning to main menu..." << endl;
			std::this_thread::sleep_for(std::chrono::seconds(3));
			main();
			return 0;
		}
		tahmin = string(kelime.length(), '_');
		for (int i = 0; i < kelime.length(); i++) {
			if (kelime[i] == ' ') {
				tahmin[i] = ' ';
			}
			else {
				tahmin[i] = '_';
			}
		}
		if (!dosya.is_open()) {
			cout << "File error. Quitting the program..." << endl;
			std::this_thread::sleep_for(std::chrono::seconds(3));
			return 1;
		}
		while (tahmin != kelime && hataSayi < 7) {
			tahminEdildiMi = false;
			hataSayiGoster(hataSayi);
			kelimeGosterIng(hataliTahminler, tahmin);
			cout << "Guess a letter: ";
			cin >> tahminString;
			if(tahminString.length() == 1){
				tahminChar = tahminString[0];
			}
			else{
				transform(tahminString.begin(), tahminString.end(), tahminString.begin(), ::tolower);
				if(tahminString == kelime){
					int input = 0;
					cout << "Correct word: " << kelime << endl;
					cout << "You won!!!" << endl;
					cout << "Would you like to play again?(1:Yes, 2:No):" << endl;
					if (!(cin >> input)) {
						cout << "Invalid choice. Leaving the game..." << endl;
						std::this_thread::sleep_for(std::chrono::seconds(3));
						return 1;
					}		
					else if (input == 1) {
						main();
						return 0;
					}
					else if (input == 2) {
						cout << "Leaving the game. Goodbye!" << endl;
						std::this_thread::sleep_for(std::chrono::seconds(3));
						return 0;
					}
				}
				else{
					int input = 0;
					cout << "Correct word: " << kelime << endl;
					cout << "You lost. " << endl;
					cout << "Would you like to play again?(1:Yes, 2:No):" << endl;
					if (!(cin >> input)) {
						cout << "Invalid choice. Leaving the game..." << endl;
						std::this_thread::sleep_for(std::chrono::seconds(3));
						return 1;
					}		
					else if (input == 1) {
						main();
						return 0;
					}
					else if (input == 2) {
						cout << "Leaving the game. Goodbye!" << endl;
						std::this_thread::sleep_for(std::chrono::seconds(3));
						return 0;
					}
				}
			}
			for (int i = 0; i < hataliTahminler.size(); i++) {
				if (tolower(tahminChar) == tolower(hataliTahminler[i])) {
					tahminEdildiMi = true;
				}
			}
			for (int i = 0; i < kelime.length(); i++) {
				if (tolower(tahminChar) == tolower(kelime[i])) {
					isDogruTahmin = true;
					tahmin[i] = tolower(tahminChar);
				}

			}
			if (tahminEdildiMi) {
				cout << "You have already guessed that letter." << endl;
			}
			else if (isDogruTahmin) {
				cout << "Correct guess!" << endl;
			}
			else {
				cout << "Wrong guess!" << endl;
				hataliTahminler.push_back(tahminChar);
				hataSayi++;
			}
			isDogruTahmin = false;
			for (int i = 0; i < tahmin.length(); i++) {
				if (tahmin[i] != '_' || tahmin[i] == ' ') {
					sayac++;
				}
			}
			
			if (sayac == tahmin.length()) {
				isWin = true;
				break;
			}
			sayac = 0;
		}
		if (isWin) {
			int input = 0;
			cout << "Correct Word: " << kelime << endl;
			cout << "You won!!!" << endl;
			cout << "Would you like to play again?(1:Yes, 2:No):" << endl;
			if (!(cin >> input)) {
				cout << "Invalid choice. Leaving the game..." << endl;
				std::this_thread::sleep_for(std::chrono::seconds(3));
				return 1;
			}
			else if (input == 1) {
				main();
				return 0;
			}
			else if (input == 2) {
				cout << "Leaving the game. Goodbye!" << endl;
				std::this_thread::sleep_for(std::chrono::seconds(3));
				return 0;
			}
		}
		else {
			int input = 0;
			cout << "Correct word: " << kelime << endl;
			cout << "You lost the game." << endl;
			cout << "Would you like to play again?(1:Yes, 2:No):" << endl;
			if (!(cin >> input)) {
				cout << "Invalid choice. Leaving the game..." << endl;
				std::this_thread::sleep_for(std::chrono::seconds(3));
				return 1;
			}
			else if (input == 1) {
				main();
				return 0;
			}
			else if (input == 2) {
				cout << "Leaving the game. Goodbye!" << endl;
				std::this_thread::sleep_for(std::chrono::seconds(3));
				return 0;
			}
		}
	}
	}
	
	vector<string> kelimeler(50);
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, kelimeler.size() - 1);
	int randomSayi = dis(gen);
	hosgeldinMesaj();
	cin >> secim;
	while (secim != 1) {
		
		switch (secim) {
		
		case 2:
			kuralGoster();
			hosgeldinMesaj();
			cin >> secim;
			break;
		case 3:
			cout << "Oyundan cikiliyor..." << endl;
			std::this_thread::sleep_for(std::chrono::seconds(3));
			return 0;

		default:
			cout << "Gecersiz secim. Ana menuye donuluyor..." << endl;
			std::this_thread::sleep_for(std::chrono::seconds(3));
			main();
			return 0;
		}
	}
	if (secim == 1) {
		cout << "1. Meslek" << endl;
		cout << "2. Sehir" << endl;
		cout << "3. Ulke" << endl;
		cout << "4. Hayvan" << endl;
		cout << "Lutfen kelime turu seciminizi yapiniz: ";
		if (!(cin >> kelimeTuru)) {
			cout << "Gecersiz secim. Ana menuye donuluyor...";
			std::this_thread::sleep_for(std::chrono::seconds(3));
			main();
			return 0;
		}
	}
	
	ifstream dosya;
		switch (kelimeTuru) {
			
		case 1:
			dosya.open("meslek.txt");
			for (int i = 0; i < kelimeler.size(); i++) {
				getline(dosya, kelimeler[i]);
			}
			kelime = kelimeler[randomSayi];
			break;
		case 2:
			dosya.open("sehir.txt");
			for (int i = 0; i < kelimeler.size(); i++) {
				getline(dosya, kelimeler[i]);
			}
			kelime = kelimeler[randomSayi];
			break;
		case 3:
			dosya.open("ulke.txt");
			for (int i = 0; i < kelimeler.size(); i++) {
				getline(dosya, kelimeler[i]);
			}
			kelime = kelimeler[randomSayi];
			break;
		case 4:
			dosya.open("hayvan.txt");
			for (int i = 0; i < kelimeler.size(); i++) {
				getline(dosya, kelimeler[i]);
			}
			kelime = kelimeler[randomSayi];
			break;
		default:
			cout << "Gecersiz secim. Oyundan cikiliyor..." << endl;
			std::this_thread::sleep_for(std::chrono::seconds(3));
			main();
			return 0;
		}
		tahmin = string(kelime.length(), '_');
		for (int i = 0; i < kelime.length(); i++) {
			if (kelime[i] == ' ') {
				tahmin[i] = ' ';
			}
			else {
				tahmin[i] = '_';
			}
		}
		if (!dosya.is_open()) {
			cout << "Dosya Hatasi" << endl;
			return 1;
		}
		while (tahmin != kelime && hataSayi < 7) {
			tahminEdildiMi = false;
			hataSayiGoster(hataSayi);
			kelimeGoster(hataliTahminler, tahmin);
			cout << "Tahmin giriniz: ";
			cin >> tahminString;
			if(tahminString.length() == 1){
				tahminChar = tahminString[0];
			}
			else{
				transform(tahminString.begin(), tahminString.end(), tahminString.begin(), ::tolower);
				if(tahminString == kelime){
					int input = 0;
					cout << "Dogru Kelime: " << kelime << endl;
					cout << "Oyunu kazandiniz!!!" << endl;
					cout << "Tekrar oynamak ister misiniz?(1:Evet, 2:Hayir):" << endl;
					if (!(cin >> input)) {
						cout << "Gecersiz secim. Oyundan cikiliyor..." << endl;
						std::this_thread::sleep_for(std::chrono::seconds(3));
						return 1;
					}		
					else if (input == 1) {
						main();
						return 0;
					}
					else if (input == 2) {
						cout << "Oyundan cikiliyor. Gorusmek uzere!" << endl;
						std::this_thread::sleep_for(std::chrono::seconds(3));
						return 0;
					}
				}
				else{
					int input = 0;
					cout << "Dogru Kelime: " << kelime << endl;
					cout << "Oyunu kaybettiniz. " << endl;
					cout << "Tekrar oynamak ister misiniz?(1:Evet, 2:Hayir):" << endl;
					if (!(cin >> input)) {
						cout << "Gecersiz secim. Oyundan cikiliyor..." << endl;
						std::this_thread::sleep_for(std::chrono::seconds(3));
						return 1;
					}		
					else if (input == 1) {
						main();
						return 0;
					}
					else if (input == 2) {
						cout << "Oyundan cikiliyor. Gorusmek uzere!" << endl;
						std::this_thread::sleep_for(std::chrono::seconds(3));
						return 0;
					}
				}
			}
			for (int i = 0; i < hataliTahminler.size(); i++) {
				if (tolower(tahminChar) == tolower(hataliTahminler[i])) {
					tahminEdildiMi = true;
				}
			}
			for (int i = 0; i < kelime.length(); i++) {
				if (tolower(tahminChar) == tolower(kelime[i])) {
					isDogruTahmin = true;
					tahmin[i] = tolower(tahminChar);
				}

			}
			if (tahminEdildiMi) {
				cout << "Bu harfi tahmin ettiniz." << endl;
			}
			else if (isDogruTahmin) {
				cout << "Dogru tahmin!" << endl;
			}
			else {
				cout << "Yanlis tahmin!" << endl;
				hataliTahminler.push_back(tahminChar);
				hataSayi++;
			}
			isDogruTahmin = false;
			for (int i = 0; i < tahmin.length(); i++) {
				if (tahmin[i] != '_' || tahmin[i] == ' ') {
					sayac++;
				}
			}
			
			if (sayac == tahmin.length()) {
				isWin = true;
				break;
			}
			sayac = 0;
		}
		if (isWin) {
			int input = 0;
			cout << "Dogru Kelime: " << kelime << endl;
			cout << "Oyunu kazandiniz!!!" << endl;
			cout << "Tekrar oynamak ister misiniz?(1:Evet, 2:Hayir):" << endl;
			if (!(cin >> input)) {
				cout << "Gecersiz secim. Oyundan cikiliyor..." << endl;
				std::this_thread::sleep_for(std::chrono::seconds(3));
				return 1;
			}
			else if (input == 1) {
				main();
				return 0;
			}
			else if (input == 2) {
				cout << "Oyundan cikiliyor. Gorusmek uzere!" << endl;
				std::this_thread::sleep_for(std::chrono::seconds(3));
				return 0;
			}
		}
		else {
			int input = 0;
			cout << "Dogru Kelime: " << kelime << endl;
			cout << "Oyunu kaybettiniz." << endl;
			cout << "Tekrar oynamak ister misiniz?(1:Evet, 2:Hayir):" << endl;
			if (!(cin >> input)) {
				cout << "Gecersiz secim. Oyundan cikiliyor..." << endl;
				std::this_thread::sleep_for(std::chrono::seconds(3));
				return 1;
			}
			else if (input == 1) {
				main();
				return 0;
			}
			else if (input == 2) {
				cout << "Oyundan cikiliyor. Gorusmek uzere!" << endl;
				std::this_thread::sleep_for(std::chrono::seconds(3));
				return 0;
			}
		}
	


	return 0;
}