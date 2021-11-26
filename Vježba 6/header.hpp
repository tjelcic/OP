#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HangmanModel
{
public:
    string sentence;
    string cur_sentence;
    string cur_hangman;
    vector<char> used;
    int lives = 7;
};

class HangmanView
{
public:
    void get_model(HangmanModel model);
    void display_progress(HangmanModel model);
    void display_used(HangmanModel model);
    void display_sentence(HangmanModel model);
};

class HangmanController
{
public:
    void get_sentence(HangmanModel &model);
    void input_letter(HangmanModel &model);
    void update_sentence(HangmanModel &model);
    void update_model(HangmanModel &model);
    void update_mistake(HangmanModel &model, bool mistake);
    bool end_check(HangmanModel &model);
};
