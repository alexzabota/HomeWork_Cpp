#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <chrono>


using namespace std;


class Gibbet
{
public:
	Gibbet();
	~Gibbet();

	string word, hidden_word,all_leters;
	char letter;
	int Wrong_answers, answers;


	void Gibbet_Cout();

	char letter_cin();

	bool check_letter();

	void print_hidden_word();

	void Game_Win_result();
	void Game_Over_result();

	bool Game_Win_check();
	bool Game_Over_check();

	string Get_Word();

	void initialization();


private:

};

Gibbet::Gibbet()
{
	word = Get_Word();
	hidden_word = "a___e";
	all_leters = " ";
	answers = 0;
	Wrong_answers = 0;
}

Gibbet::~Gibbet()
{
	cout <<endl<<"Number of attempts - "<<answers <<endl<< "Original word - " << word << endl << "All letters - " << all_leters;
}

char Gibbet::letter_cin()
{
	cin >> letter;
	return letter;
}

bool Gibbet::check_letter()
{
	bool result = false;
	for (int i = 0; i < word.size(); i++) {
		if (word[i] == letter) {
			hidden_word[i] = letter;
			result = true;
		}
	}
	return result;
	
}

void Gibbet::print_hidden_word()
{
	cout << hidden_word<<endl;
}

bool Gibbet::Game_Win_check()
{
	return word == hidden_word;
}

bool Gibbet::Game_Over_check()
{
	return Wrong_answers == 6;
}

string Gibbet::Get_Word()
{   
	string str;
	srand(time(0));
	int a = rand() % 10 + 1;

	ifstream fl;
	fl.open("words.txt");

	if (!fl.is_open()) {
		cout << "Ошибка чтения файла"<<endl;
	}
	else {
		cout << "файл открыт!" << endl;
		while (a) {
			getline(fl, str);
			a--;
		}
		fl.close();
		return str;

	}
	
}

void Gibbet::initialization()
{
	hidden_word = word;
	for (int i = 1; i < word.size() - 1; i++) {
		hidden_word[i] = '_';
	}
}

void Gibbet::Game_Win_result()
{
	cout << "You Win!";
}

void Gibbet::Game_Over_result()
{
	cout << "Game Over";
}

void Gibbet::Gibbet_Cout()
{
	switch (Wrong_answers)
	{
	case 1:
		cout <<
			"        $$$$$$$$$$$$$$$\n"
			"                      $\n"
			"                      $\n"
			"                      $\n"
			"                      $\n"
			"                      $\n"
			"                      $\n"
			"                      $\n"
			"                      $\n"
			"                      $\n"
			"                      $\n"
			" $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
			" $                          $\n";
		break;
	case 2:
		cout <<
			"        $$$$$$$$$$$$$$$\n"
			"        |             $\n"
			"        |             $\n"
			"        |             $\n"
			"        |             $\n"
			"                      $\n"
			"                      $\n"
			"                      $\n"
			"                      $\n"
			"                      $\n"
			"                      $\n"
			" $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
			" $                          $\n";
		break;
	case 3:
		cout <<
			"        $$$$$$$$$$$$$$$\n"
			"        |             $\n"
			"        |             $\n"
			"        |             $\n"
			"        |             $\n"
			"        O             $\n"
			"                      $\n"
			"                      $\n"
			"                      $\n"
			"                      $\n"
			"                      $\n"
			" $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
			" $                          $\n";
		break;
	case 4:
		cout <<
			"        $$$$$$$$$$$$$$$\n"
			"        |             $\n"
			"        |             $\n"
			"        |             $\n"
			"        |             $\n"
			"        O             $\n"
			"      /   \\           $\n"
			"                      $\n"
			"                      $\n"
			"                      $\n"
			"                      $\n"
			" $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
			" $                          $\n";
		break;
	case 5:
		cout <<
			"        $$$$$$$$$$$$$$$\n"
			"        |             $\n"
			"        |             $\n"
			"        |             $\n"
			"        |             $\n"
			"        O             $\n"
			"      / | \\           $\n"
			"        |             $\n"
			"                      $\n"
			"                      $\n"
			"                      $\n"
			" $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
			" $                          $\n";
		break;
	case 6:
		cout <<
			"        $$$$$$$$$$$$$$$\n"
			"        |             $\n"
			"        |             $\n"
			"        |             $\n"
			"        |             $\n"
			"        O             $\n"
			"      / | \\           $\n"
			"        |             $\n"
			"       / \\            $\n"
			"                      $\n"
			"                      $\n"
			" $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
			" $                          $\n";
		break;
	}
}



int main()
{
	//setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(866);
	SetConsoleCP(866);
	Gibbet a;

	auto start = chrono::high_resolution_clock::now();

	a.initialization();

	while (true)
	{
		cout << a.word << endl;
		a.print_hidden_word();
		a.letter_cin();
		if (a.check_letter()) {
			a.print_hidden_word();
		}
		else {
			a.Wrong_answers++;
			a.Gibbet_Cout();
		}
		a.answers++;
		a.all_leters += a.letter;
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<float> duration = end - start;
		if (a.Game_Win_check()) {
			a.Game_Win_result();
			cout << endl << "Time - " << duration.count()<<"s";
			return 0;
		}
		if (a.Game_Over_check()) {
			a.Game_Over_result();
			cout << endl << "Time - " << duration.count()<<"s";
			return 0;
		}
	}

}
