#include <iostream>
#include <string>
// Gabriela Sarai Valencia Suncin+

struct Member {
  std::string first_name;
  std::string last_name;
  int age;
};

struct Club {
  std::string name;
  std::string creation_date;
  int max_capacity;
  int currentMembers;
  Member *members;
};

// Main Functions
void CreateClub(Club clubs[], int &num_clubs, int max_clubs);
void ListClubs(Club clubs[], int num_clubs);
void TotalMembers(Club &club);
void RegisterMember(Club &club);
void ListMemebers(Club &club);
// Auxiliar Functions
int AskClubPosition();
void OptionMainMenu(int &);

int main(int argc, char *argv[]) {
  int menuOption = 0, num_clubs = 0, maxClubs = 0;
  std::cout << "\nEscriba la capacidad maxima de clubes que pueden existir: ";
  std::cin >> maxClubs;
  Club clubs[maxClubs];

  do {
    OptionMainMenu(menuOption);

    switch (menuOption) {
      case 1:
        CreateClub(clubs, num_clubs, maxClubs);
        break;

      case 2:
        ListClubs(clubs, num_clubs);
        break;

      case 3:
        TotalMembers(clubs[AskClubPosition()]);
        break;
      case 4:
        RegisterMember(clubs[AskClubPosition()]);
        break;

      case 5:
        ListMemebers(clubs[AskClubPosition()]);
        break;

      case 6:
        std::cout << "Saliendo del programa...." << std::endl;
        break;

      default:
        std::cout << "\nHa ingresado una opcion de menu incorrecta"
                  << std::endl;
        break;
    }

  } while (menuOption != 6);
  return 0;
}

// Funciones Principales
void CreateClub(Club clubs[], int &num_clubs,
                int max_clubs) {  // Funcion para Crear un Club
  if (num_clubs < max_clubs) {
    std::cout << "\nClub # " << num_clubs + 1 << ": " << std::endl;
    std::cout << "Ingrese el nombre del club: ";
    std::cin.ignore();
    getline(std::cin, clubs[num_clubs].name);
    std::cout << "Ingrese el fecha de creacion del club(DD/MM/YY): ";
    getline(std::cin, clubs[num_clubs].creation_date);
    std::cout << "Ingrese la capacidad maxima de miembros: ";
    std::cin >> clubs[num_clubs].max_capacity;
    clubs[num_clubs].members = new Member[clubs[num_clubs].max_capacity];
    clubs[num_clubs].currentMembers = 0;

    num_clubs++;

  } else {
    std::cout << "\nHa alcanzado el maximo numero de clubes, por lo que no es "
                 "posible agregar otro"
              << std::endl;
  }
}

void ListClubs(Club clubs[], int num_clubs) {  // Funcion para Mostrar Clubes
  std::cout << std::endl;
  for (int i = 0; i < num_clubs; i++) {
    std::cout << "Club # " << i + 1 << ": " << clubs[i].name
              << " con fecha de creacion de " << clubs[i].creation_date
              << " y con una capacidad maxima de miembros de "
              << clubs[i].max_capacity << std::endl;
  }
}

void TotalMembers(
    Club &club) {  // Funcion para mostrar el total de miembros de un club
  std::cout << "\nEl total de miembros del club " << club.name
            << " es: " << club.currentMembers << std::endl;
}

void RegisterMember(
    Club &club) {  // Funcion para registrar un miembro en un club
  if (club.currentMembers >= club.max_capacity) {
    std::cout << "\nHa excedido la maxima capacidad de miembros permitidos"
              << std::endl;
  } else {
    std::cout << "\nMiembro # " << club.currentMembers + 1 << ": " << std::endl;
    std::cout << "Ingrese el nombre del miembro: ";
    std::cin.ignore();
    getline(std::cin, club.members[club.currentMembers].first_name);
    std::cout << "Ingrese el apellido del miembro: ";
    getline(std::cin, club.members[club.currentMembers].last_name);
    std::cout << "Ingrese la edad del miembro: ";
    std::cin >> club.members[club.currentMembers].age;

    club.currentMembers++;
  }
}

void ListMemebers(Club &club) {  // Funcion para mostrar miembros de un club

  if (club.currentMembers == 0) {
    std::cout << "\nNo hay miembros que mostrar" << std::endl;
  } else {
    std::cout << "Lista de miembros del club " << club.name << ": ";
    std::cout << std::endl;
    for (int i = 0; i <= club.currentMembers; i++) {
      std::cout << club.members[i].first_name << " "
                << club.members[i].last_name << " con " << club.members[i].age
                << " años." << std::endl;
    }
  }
}

// Funciones Auxiliares
int AskClubPosition() {  // Funcion para pedir numero de club
  int clubPosition;
  std::cout << "\nIngrese el numero del club: ";
  std::cin >> clubPosition;

  clubPosition = clubPosition - 1;

  return clubPosition;
}

void OptionMainMenu(int &option) {  // Funcion que muestra y pide opcion de menu
  std::cout << "\n-----Sistema de Registro de Clubes-----" << std::endl;
  std::cout << "1. Agregar un Club" << std::endl;
  std::cout << "2. Mostrar Clubes" << std::endl;
  std::cout << "3. Mostrar Total de miembros en un club" << std::endl;
  std::cout << "4. Registrar miembros en un club" << std::endl;
  std::cout << "5. Listar los miembros de un club" << std::endl;
  std::cout << "6. Salir" << std::endl;
  std::cout << "Ingrese una opcion: ";
  std::cin >> option;
}