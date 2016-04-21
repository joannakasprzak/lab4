#include <iostream>
#include <stdlib.h>

using namespace std;

int value;


string units[]={"", "jeden","dwa","trzy","cztery","piec","szesc","siedem","osiem","dziewiec"};
string tens[]={"", "dziesiec","dwadziescia","trzydziesci","czterdziesci","piecdziesiat","szescdziesiat","siedemdziesiat","osiemdziesiat","dziewiecdziesiat"};
string hundreds[]={"", "sto","dwiescie","trzysta","czterysta","piecset","szescset","siedemset","osiemset","dziewiecset"};
string thousands[]={"", "tysiac","dwa tysiace","trzy tysiace", "cztery tysiace", "piec tysiecy", "szesc tysiecy", "siedem tysiecy", "osiem tysiecy", "dziewiec tysiecy"};
string exceptions1[]={"dziesiec", "jedenascie","dwanascie","trzynascie","czternascie","pietnascie","szesnascie","siedemnascie","osiemnascie","dziewietnascie"};
string exceptions2[]={"dziesiec tysiecy", "jedenascie tysiecy","dwanascie tysiecy ","trzynascie tysiecy","czternascie tysiecy","pietnascie tysiecy","szesnascie tysiecy","siedemnascie tysiecy","osiemnascie tysiecy","dziewietnascie tysiecy"};

int main (int argc, char *argv[])
{
	value = atoi (argv[1]);
	
	if (value == 0) {
		cout << "zero" << endl;
		return 0;
	}
	
	if (value == 1000000) {
		cout << "milion" << endl;
		return 0;
	}
	
	int digits[6];
	int number = value;
	
	for (int i = 0; i<6; i++){
		digits[i] = 0;
	}
	
	int i=5;
	do {
		int a = number % 10;
		number = number / 10;
		digits[i--]=a;
		
	} while( number > 0 );
	
	bool is_different_than_0 = false;
	bool is_thousand = false;
	for (int i = 0; i<6; i++){
		if (digits[i] != 0) {
			is_different_than_0 = true;
		}

		if (is_different_than_0) {
			if(i == 5) {
				cout << units[digits[i]];			
			} else if(i == 4) {
				if (digits[i] == 1) {
					i++;
					cout << exceptions1[digits[i]];
				} else {
					cout << tens[digits[i]];			
				}
			} else if (i == 3 ){
				cout << hundreds[digits[i]];			
			} else if (i == 2 ){
				if (is_thousand) {
					cout << units[digits[i]] << " tysiecy";
				} else {
					cout << thousands[digits[i]];
				}
			} else if (i == 1 ){
				if (digits[i] == 1) {
					i++;
					cout << exceptions2[digits[i]];
				} else {
					cout << tens[digits[i]];			
				}
			} else if (i == 0 ){
				is_thousand = true;
				cout << hundreds[digits[i]];			
			} 
			cout << " ";
		}
	}
}
