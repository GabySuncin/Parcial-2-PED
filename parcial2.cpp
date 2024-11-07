#include <iostream>
#include <string>
#include <list>


struct Member {
  std::string first_name;
  std::string last_name;
  int age;
};

struct Club {
  std::string name;
  std::string creation_date;
  std::list<Member> members;
};

// Main Functions
void CreateClub(std::list<Club>& clubs);
void ListClubs(std::list<Club> clubs);
void TotalMembers(std::list <Club> clubs);
void RegisterMember(std::list <Club>& clubs);
void ListMemebers(std::list <Club> clubs);

// Auxiliar Functions
Club FindClub(std::list <Club> clubs);
void OptionMainMenu(int &);

int main(int argc, char *argv[]) {
  int menuOption = 0;
  
  std::list<Club> clubs;

  do {
    OptionMainMenu(menuOption);

    switch (menuOption) {
      case 1:
        CreateClub(clubs);
        break;

      case 2:
        ListClubs(clubs);
        break;

      case 3:
        TotalMembers(clubs);
        break;
      case 4:
        RegisterMember(clubs);
        break;

      case 5:
        ListMemebers(clubs);
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
void CreateClub(std::list<Club>& clubs) {  // Funcion para Crear un Club
  Club club; 
  std::cout << "Ingrese el nombre del Club: ";
  std::cin.ignore();
  getline(std::cin, club.name);
  std::cout << "Ingrese el dia en que se creó el club: "; 
  getline(std::cin, club.creation_date);

  clubs.push_front(club);
}

void ListClubs(std::list<Club> clubs) {  // Funcion para Mostrar Clubes
  
  if (clubs.empty()) {
    std::cout << "La Lista de Clubes esta vacia" << std::endl; 
  }
  
  std::list<Club> tempClubs; 
  tempClubs = clubs; 
  while (!tempClubs.empty()) {
    Club tempClub = tempClubs.front();
    std::cout << "------- " << tempClub.name << " -------" << std::endl;
    std::cout << "Dia de creación: " << tempClub.creation_date << std::endl; 
    std::cout << "Miembros del club actuales: " << tempClub.members.size() <<std::endl;
    tempClubs.pop_front(); 
  }
}

void TotalMembers(std::list <Club> clubs) { // Funcion para mostrar el total de miembros de un club
  
  if (clubs.empty()) {
    std::cout << "La Lista de Clubes esta vacia" << std::endl; 
  }

  Club clubFound = FindClub(clubs);
  
  std::cout << "La cantidad de miembros del club: " << clubFound.name << "es "<< clubFound.members.size() <<std::endl; 
  
}

void RegisterMember(std::list <Club>& clubs) {  // Funcion para registrar un miembro en un club
  if (clubs.empty()) {
    std::cout << "La Lista de Clubes esta vacia" << std::endl; 
  }
  
  Club clubFound = FindClub(clubs);
  Member tempMember; 
  std::cout << "Ingrese el nombre del miembro: ";
  std::cin.ignore();
  getline(std::cin,tempMember.first_name);
  std::cout << "Ingrese el apellido del miembro: ";
  getline(std::cin,tempMember.last_name);
  std::cout << "Ingrese la edad del miembro: "; 
  std::cin >> tempMember.age;

  clubFound.members.push_front(tempMember);

}

void ListMemebers(std::list <Club> clubs) {  // Funcion para mostrar miembros de un club
  Club clubFound = FindClub(clubs);
  std::list<Member> members = clubFound.members;

  std::cout << "-----MIEMBROS-----" << std::endl; 
  while (!members.empty()) {
    Member tempMember = members.front();
    std::cout << "Nombre: " << tempMember.first_name << ", Apellido: " << tempMember.last_name << ", Edad: " << tempMember.age << std::endl;
    members.pop_front();
  }
}

// Funciones Auxiliares
Club FindClub(std::list <Club> clubs) {  // Funcion para encontrar club
  std::string clubName; 
  std::cout << "\nEscriba el nombre del club: ";
  std::cin.ignore();
  getline (std::cin, clubName);
  
  std::list<Club> tempClubs;
  tempClubs = clubs; 
  while (!tempClubs.empty()) {
    Club tempClub = tempClubs.front();
    if (tempClub.name == clubName) {
      return tempClub;
    }
    tempClubs.pop_front(); 
  } 
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