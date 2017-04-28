#include "game_of_life.h"
#include <ctime>

bool game_of_life::slucajna_vrijednost()
{
	int broj= rand() % (10 - 1+ 1) + 1;
	if (broj <= 2) {
		return true;
	}
	else {
		return false;
	}
}
bool game_of_life::celija_zauzeta(int i, int j)
{

	if (_generacija[i][j] == 1) {
		return true;
	}
	else {
		return false;
	}
}

/////////////////////////PUBLIC//////////////////////////////

game_of_life::game_of_life()
{
	srand(time(nullptr));

	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {

			if (!slucajna_vrijednost()) {
				_generacija[i][j] = 0;
			}
			else {
				_generacija[i][j] = 1;
			}
		}
	}
		
	

}
void game_of_life::sljedeca_generacija()

{

	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			_sljedeca_generacija[i][j] = _generacija[i][j];
		}
	}
	cout << endl;


	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j <  STUPACA; j++) {

			int brojSusjeda = 0;
			int nova = 0;
			int vecPostoji = 0;

				 ////////////////////////////PROVJERI
				if (celija_zauzeta(i-1,j)) {
					brojSusjeda++;
					nova++;
				}
				if (celija_zauzeta(i - 1,j+1)) {
					brojSusjeda++;
					nova++;
				}
				if (celija_zauzeta(i - 1,j -1)){
				 	brojSusjeda++;
				    nova++;
			    }
				if (celija_zauzeta(i,j + 1)) {
					brojSusjeda++;
					nova++;
				}
				if (celija_zauzeta(i + 1,j)) {
					brojSusjeda++;
					nova++;
				}
				if (celija_zauzeta(i + 1,j - 1)) {
					brojSusjeda++;
					nova++;
				}
				if (celija_zauzeta(i + 1,j + 1)) {
					brojSusjeda++;
					nova++;
				}
				if (celija_zauzeta(i,j - 1)) {
					brojSusjeda++;
					nova++;
				}

				if (_sljedeca_generacija[i][j] == 1) {
					if (brojSusjeda == 2 || brojSusjeda == 3) {////////////////////////////////PROVJERI
						_sljedeca_generacija[i][j];
					}
					else if (brojSusjeda < 2 || brojSusjeda > 3) {
						_sljedeca_generacija[i][j] = 0;
						vecPostoji++;
					}
				}
				else if(_sljedeca_generacija[i][j]==0){
					if ( nova == 3 && vecPostoji<1) {////////////////////////////////PROVJERI
						_sljedeca_generacija[i][j] = 1;
					}
			}
		}
	}
	
	
		for (int i = 0; i < REDAKA; i++) {
			for (int j = 0; j < STUPACA; j++) {
				_generacija[i][j] = _sljedeca_generacija[i][j];
			}
		}
}

void game_of_life::iscrtaj()
{
	for (int i = 0; i <REDAKA; i++) {
		for (int j = 0; j <STUPACA; j++) {
			if (_generacija[i][j] == 1) {
				cout << "*";
			}
			else{
				cout << "-";
			}
		}
		cout << endl;
	}

}
