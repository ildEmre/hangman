#include "adamasmaca.h"
#include <locale>
using namespace std;
void hataSayiGoster(int hataSayi)
{
    if (hataSayi == 0)
    {
        cout << "  +---+ \n";
        cout << "  |   | \n";
        cout << "      | \n";
        cout << "      | \n";
        cout << "      | \n";
        cout << "      | \n";
        cout << " ========= \n";
    }
    else if (hataSayi == 1)
    {
        cout << "  +---+ \n";
        cout << "  |   | \n";
        cout << "  O   | \n";
        cout << "      | \n";
        cout << "      | \n";
        cout << "      | \n";
        cout << " ========= \n";
    }
    else if (hataSayi == 2)
    {
        cout << "  +---+ \n";
        cout << "  |   | \n";
        cout << "  O   | \n";
        cout << "  |   | \n";
        cout << "      | \n";
        cout << "      | \n";
        cout << " ========= \n";
    }
    else if (hataSayi == 3)
    {
        cout << "  +---+ \n";
        cout << "  |   | \n";
        cout << "  O   | \n";
        cout << " /|   | \n";
        cout << "      | \n";
        cout << "      | \n";
        cout << " ========= \n";
    }
    else if (hataSayi == 4)
    {
        cout << "  +---+ \n";
        cout << "  |   | \n";
        cout << "  O   | \n";
        cout << " /|\\  | \n";
        cout << "      | \n";
        cout << "      | \n";
        cout << " ========= \n";
    }
    else if (hataSayi == 5)
    {
        cout << "  +---+ \n";
        cout << "  |   | \n";
        cout << "  O   | \n";
        cout << " /|\\  | \n";
        cout << " /    | \n";
        cout << "      | \n";
        cout << " ========= \n";
    }
    else if (hataSayi == 6)
    {
        cout << "  +---+ \n";
        cout << "  |   | \n";
        cout << "  O   | \n";
        cout << " /|\\  | \n";
        cout << " / \\  | \n";
        cout << "      | \n";
        cout << " ========= \n";
    }

}
void hosgeldinMesaj() {
    cout << R"(
=========================================================================================================
=========================================================================================================
=========================================================================================================
88                                                                            
88                                                                            
88                                                                            
88,dPPYba,  ,adPPYYba, 8b,dPPYba,   ,adPPYb,d8 88,dPYba,,adPYba,  ,adPPYYba, 8b,dPPYba,  
88P'    "8a ""     `Y8 88P'   `"8a a8"    `Y88 88P'   "88"    "8a ""     `Y8 88P'   `"8a 
88       88 ,adPPPPP88 88       88 8b       88 88      88      88 ,adPPPPP88 88       88 
88       88 88,    ,88 88       88 "8a,   ,d88 88      88      88 88,    ,88 88       88 
88       88 `"8bbdP"Y8 88       88  `"YbbdP"Y8 88      88      88 `"8bbdP"Y8 88       88 
                                    aa,    ,88                                
                                     "Y8bbdP"                                 
                    
 ___________.._______
| .__________))______|
| | / /      ||
| |/ /       ||
| | /        ||.-''.
| |/         |/  _  \
| |          ||  `/,|
| |          (\\`_.'
| |         .-`--'.
| |        /Y . . Y\
| |       // |   | \\
| |      //  | . |  \\
| |     ')   |   |   (`
| |          ||'||
| |          || ||
| |          || ||
| |          || ||
| |         / | | \
""""""""""|_`-' `-' |"""|
|"|"""""""\ \       '"|"|
| |        \ \        | |
: :         \ \       : :  
. .          `'       . .
=========================================================================================================
=========================================================================================================
=========================================================================================================    
)" << endl;
    cout << "Adam asmaca oyununa hosgeldiniz!" << endl << endl;
    cout << "1. Basla" << endl;
    cout << "2. Kurallar" << endl;
    cout << "3. Cik" << endl;
    cout << "Lutfen seciminizi yapiniz: ";
}
void hosgeldinMesajIng() {
    cout << R"(
=========================================================================================================
=========================================================================================================
=========================================================================================================
88                                                                            
88                                                                            
88                                                                            
88,dPPYba,  ,adPPYYba, 8b,dPPYba,   ,adPPYb,d8 88,dPYba,,adPYba,  ,adPPYYba, 8b,dPPYba,  
88P'    "8a ""     `Y8 88P'   `"8a a8"    `Y88 88P'   "88"    "8a ""     `Y8 88P'   `"8a 
88       88 ,adPPPPP88 88       88 8b       88 88      88      88 ,adPPPPP88 88       88 
88       88 88,    ,88 88       88 "8a,   ,d88 88      88      88 88,    ,88 88       88 
88       88 `"8bbdP"Y8 88       88  `"YbbdP"Y8 88      88      88 `"8bbdP"Y8 88       88 
                                    aa,    ,88                                
                                     "Y8bbdP"                                 
                    
 ___________.._______
| .__________))______|
| | / /      ||
| |/ /       ||
| | /        ||.-''.
| |/         |/  _  \
| |          ||  `/,|
| |          (\\`_.'
| |         .-`--'.
| |        /Y . . Y\
| |       // |   | \\
| |      //  | . |  \\
| |     ')   |   |   (`
| |          ||'||
| |          || ||
| |          || ||
| |          || ||
| |         / | | \
""""""""""|_`-' `-' |"""|
|"|"""""""\ \       '"|"|
| |        \ \        | |
: :         \ \       : :  
. .          `'       . .
=========================================================================================================
=========================================================================================================
=========================================================================================================    
)" << endl;
    cout << "Welcome to Hangman!" << endl << endl;
    cout << "1. Start" << endl;
    cout << "2. Rules" << endl;
    cout << "3. Leave" << endl;
    cout << "Please make your choice: ";
}
void kuralGoster() {
    cout << endl << endl << endl;
    cout << "Kurallar: " << endl;
    cout << "Kelimenin harflerini dogru tahmin ederek oyunu kazanin!" << endl;
    cout << "6 Adet tahmin sayiniz vardir." << endl << endl << endl;
}
void kuralGosterIng(){
    cout << endl << endl << endl;
    cout << "Rules: " << endl;
    cout << "Win the game by correctly guessing each letter of the hidden word!" << endl;
    cout << "You have 6 guesses in total." << endl << endl << endl;
}
void kelimeGoster(vector<char> hataliTahminler, string tahmin) {
    cout << "Hatali tahminler: \n";
    for (int i = 0; i < hataliTahminler.size(); i++) {
        cout << hataliTahminler[i] << " ";
    }
    cout << "\nKelime:\n";

    for (int i = 0; i < tahmin.length(); i++) {
        cout << tahmin[i] << " ";
    }
}
void kelimeGosterIng(vector<char> hataliTahminler, string tahmin) {
    cout << "Wrong guesses: \n";
    for (int i = 0; i < hataliTahminler.size(); i++) {
        cout << hataliTahminler[i] << " ";
    }
    cout << "\nWord:\n";

    for (int i = 0; i < tahmin.length(); i++) {
        cout << tahmin[i] << " ";
    }
}
