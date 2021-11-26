#include "header.hpp"

using namespace std;

int main()
{
    HangmanModel model;
    HangmanView view;
    HangmanController controller;

    cout << "    THE GAME OF HANGMAN   " << endl << endl;
    cout << " Guess the name of a movie " << endl << endl;

    controller.get_sentence(model);

    while(controller.end_check(model))
    {
        controller.update_model(model);
        view.get_model(model);
        view.display_progress(model);
        view.display_used(model);
        controller.input_letter(model);
        controller.update_sentence(model);
    }
    controller.update_model(model);
    view.get_model(model);
    view.display_used(model);
    view.display_progress(model);
    view.display_sentence(model);
}
