#include "header.hpp"
#include <cctype>
#include <cstring>
#include <fstream>
#include <time.h>

using namespace std;

void HangmanView::get_model(HangmanModel model)
{
    cout  << model.cur_hangman << endl;
}

void HangmanView::display_progress(HangmanModel model)
{
    cout << "Current sentence: " << model.cur_sentence << endl;
}

void HangmanView::display_sentence(HangmanModel model)
{
    cout << "Correct sentence: " << model.sentence << endl;
}

void HangmanView::display_used(HangmanModel model)
{
    cout << "Used letters: ";
    for (int i = 0; i < model.used.size(); i++)
    {
        cout << model.used[i] << " ";
    }
    cout << endl;
}

void HangmanController::get_sentence(HangmanModel &model)
{
    srand(time(NULL));
    fstream fp;
    vector<string> sentences;
    fp.open("movie.txt",ios::in);
    if (fp.is_open())
    {
        string sen;
        while (getline(fp, sen))
        {
            sentences.push_back(sen);
        }
        fp.close();
    }
    model.sentence = sentences[rand() % sentences.size()];

    for (int i=0; i < model.sentence.size(); i++)
    {
        if (ispunct(model.sentence[i]))
        {
            model.sentence.erase(i,1);
        }
    }

    for (auto & c: model.sentence) c = toupper(c);

    for (int i = 0; i < model.sentence.size(); i++)
    {
        if (isspace(model.sentence[i]))
        {
            model.cur_sentence.push_back(' ');
        }
        else
        {
            model.cur_sentence.push_back('_');
        }
    }
}

void HangmanController::update_mistake(HangmanModel &model, bool mistake)
{
    if (mistake) model.lives--;
}

void HangmanController::update_sentence(HangmanModel &model)
{
    char letter = model.used.back();
    bool mistake = true;
    for (int i = 0; i < model.sentence.size(); i++)
    {
        if (model.sentence[i] == letter)
        {
            model.cur_sentence[i] = letter;
            mistake = false;
        }
    }
    update_mistake(model, mistake);
}

void HangmanController::input_letter(HangmanModel &model)
{
    char c;
    cout << "Enter a new letter: "<< endl;
    cin >> c;
    model.used.push_back(toupper(c));
}

void HangmanController::update_model(HangmanModel &model)
{
    int lives = model.lives;
    if (lives == 0)
    {
        string drawing =
            "    ________    \n"
            "    | /  |      \n"
            "    |/   0      \n"
            "    |   /|\\    \n"
            "    |    |      \n"
            "    |   / \\    \n"
            "    |           \n"
            "    |           \n"
            " ___|___        \n";
        model.cur_hangman = drawing;
    }
    else if (lives == 1)
    {
        string drawing =
            "    ________    \n"
            "    | /  |      \n"
            "    |/   0      \n"
            "    |   /|\\    \n"
            "    |    |      \n"
            "    |   /       \n"
            "    |           \n"
            "    |           \n"
            " ___|___        \n";
        model.cur_hangman = drawing;
    }
    else if (lives == 2)
    {
        string drawing =
            "    ________    \n"
            "    | /  |      \n"
            "    |/   0      \n"
            "    |   /|\\    \n"
            "    |    |      \n"
            "    |           \n"
            "    |           \n"
            "    |           \n"
            " ___|___        \n";
        model.cur_hangman = drawing;
    }
    else if (lives == 3)
    {
        string drawing =
            "    ________    \n"
            "    | /  |      \n"
            "    |/   0      \n"
            "    |   /|\\    \n"
            "    |           \n"
            "    |           \n"
            "    |           \n"
            "    |           \n"
            " ___|___        \n";
        model.cur_hangman = drawing;
    }
    else if (lives == 4)
    {
        string drawing =
            "    ________    \n"
            "    | /  |      \n"
            "    |/   0      \n"
            "    |   /|      \n"
            "    |           \n"
            "    |           \n"
            "    |           \n"
            "    |           \n"
            " ___|___        \n";
        model.cur_hangman = drawing;
    }
    else if (lives == 5)
    {
        string drawing =
            "    ________    \n"
            "    | /  |      \n"
            "    |/   0      \n"
            "    |    |      \n"
            "    |           \n"
            "    |           \n"
            "    |           \n"
            "    |           \n"
            " ___|___        \n";
        model.cur_hangman = drawing;
    }
    else if (lives == 6)
    {
        string drawing =
            "    ________    \n"
            "    | /  |      \n"
            "    |/   0      \n"
            "    |           \n"
            "    |           \n"
            "    |           \n"
            "    |           \n"
            "    |           \n"
            " ___|___        \n";
        model.cur_hangman = drawing;
    }
    else
    {
        string drawing =
            "    ________    \n"
            "    | /  |      \n"
            "    |/          \n"
            "    |           \n"
            "    |           \n"
            "    |           \n"
            "    |           \n"
            "    |           \n"
            " ___|___        \n";
        model.cur_hangman = drawing;
    }
}

bool HangmanController::end_check(HangmanModel &model)
{
    if (!model.lives)
    {
        cout << " You lost the game!" << endl;
        return false;
    }
    for (int i = 0; i < model.sentence.size(); i++)
    {
        if (model.sentence[i] != model.cur_sentence[i])
        {
            return true;
        }
    }
    cout << " You won the game!" << endl;
    return false;
}
