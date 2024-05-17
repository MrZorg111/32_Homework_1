#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <nlohmann/json.hpp>
#include "function.h"


/*
Что нужно сделать
Запишите подробную информацию о киноленте в виде JSON-файла. Выберите понравившуюся вам картину на любимом портале, 
проанализируйте информацию о ней и составьте JSON-словарь.

В информации должны присутствовать: страна и дата создания киноленты, студия, которая вела съёмки, автор сценария, 
режиссёр и продюсер киноленты. Обязательно добавьте информацию обо всех главных действующих лицах и тех актёрах, которые их сыграли.
*/

struct LovelyMovie {
    std::string nameMovie;
    std::string country;
    std::string date;
    std::string studio;
    std::string nameWritten;
    std::string nameDirector;
    std::string nameProduser;
    std::vector<std::string> nameCharacter;
    std::vector<std::string> nameActors;
};

int main() {
    //The iteration unit:
    //########################################################################################################
    LovelyMovie lovelymovie;
    std::ofstream movieData("MovieData.json");
    nlohmann::json dict;
    //########################################################################################################

    //input unit:
    //########################################################################################################
    std::cout << "Enter the name of your favorite movie: " << std::endl;
    std::getline(std::cin, lovelymovie.nameMovie);
    
    std::cout << "Manufacturer's country: " << std::endl;
    std::getline(std::cin, lovelymovie.country);

    std::cout << "Release date: " << std::endl;
    std::getline(std::cin, lovelymovie.date);

    std::cout << "Studio manufacturer: " << std::endl;
    std::getline(std::cin, lovelymovie.studio);

    std::cout << "The author of the script: " << std::endl;
    std::getline(std::cin, lovelymovie.nameWritten);

    std::cout << "Director: " << std::endl;
    std::getline(std::cin, lovelymovie.nameDirector);

    std::cout << "Produser: " << std::endl;
    std::getline(std::cin, lovelymovie.nameProduser); 
    
    std::cout << "Enter the name of the character, and then the Actor who played him, enter \"Stop\" to complete: " << std::endl;
    std::string tempo_enter_actor, tempo_enter_character;
    for(;;) {
        std::cout << "Character: " << std::endl;
        std::getline(std::cin, tempo_enter_character);
        std::cout << "Actor: " << std::endl;
        std::getline(std::cin, tempo_enter_actor);
        if(tempo_enter_character != "Stop" && tempo_enter_actor != "Stop") {
        lovelymovie.nameCharacter.push_back(tempo_enter_character);
        lovelymovie.nameActors.push_back(tempo_enter_actor);
        }
        else {
            break;
        }
    }
    //########################################################################################################
    //The recording unit:

    dict = {
        {"Name Movie", lovelymovie.nameMovie}, 
        {"Country", lovelymovie.country},
        {"Date", lovelymovie.date},
        {"Studio", lovelymovie.studio},
        {"Name Written", lovelymovie.nameWritten},
        {"Name Director", lovelymovie.nameDirector},
        {"Name Produser", lovelymovie.nameProduser},
        {"Name Character", lovelymovie.nameCharacter},
        {"Name Actors", lovelymovie.nameActors}
    };
    movieData << dict;
    return 0;
}