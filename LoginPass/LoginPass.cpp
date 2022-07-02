// LoginForm.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>


bool file_exist(std::string fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}

void regist() {
    std::string login;
    std::string password;
    std::string filename;
    std::cout << "\n\nidentifiant: ";
    std::cin >> login;
    std::ofstream myfile;
    filename = login + ".txt";
    if (file_exist(filename)) {
        std::cout << "\nCe compte exist deja !\n\n";
    }
    else {
        std::cout << "\nmot de passe: ";
        std::cin >> password;
        myfile.open(filename);
        myfile << login << "\n" << password;
        myfile.close();

        std::cout << "\nCompte cree !\n";
    }

}



void login() {
    std::ifstream infile;
    std::string FileLogin, FilePassword;
    std::string login;
    std::string password;
    std::string filename;
    std::cout << "Entrez votre identifiant: ";
    std::cin >> login;
    filename = login + ".txt";
    if (file_exist(filename)) {
        std::cout << "\nMot de passe: ";
        std::cin >> password;
        infile.open(filename);
        if (infile.is_open()) {
            infile >> FileLogin;
            infile >> FilePassword;
        }
        if (FileLogin == login & FilePassword == password) {
            std::cout << "\nConnection reussie\n\n";
        }
        else {
            std::cout << "Mauvais mot de passe !";
        }

    }
    else {
        std::cout << "Aucun Compte avec cet identifiant trouve.";
    }
}

int menuprincipal() {
    int choice = 0;
    while (choice != 3) {
        std::cout << "1.S'inscrire\n2.Se connecter\n3.Quitter\n ";
        std::cout << "\nVotre choix: ";
        std::cin >> choice;
        switch (choice) {
        case 1:
            regist();
            menuprincipal();
        case 2:
            login();
            menuprincipal();
        case 3:
            return 0;
            
        }
    }
}

int main()
{
    menuprincipal();
}
