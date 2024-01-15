#include <iostream>
#include <string>
#include <stdlib.h>
#include <limits>
#include "Database.h"

void show_menu() {
  std::cout << std::endl;
  std::cout << "Composer Database" << std::endl;
  std::cout << "---------------------------------------------" << std::endl;
  std::cout << "1) Add a new composer" << std::endl;
  std::cout << "2) Retrieve a composer's data" << std::endl;
  std::cout << "3) Promote/demote a composer's rank" << std::endl;
  std::cout << "4) List all composers" << std::endl;
  std::cout << "5) List all composers by rank" << std::endl;
  std::cout << "0) Quit" << std::endl << std::endl;
}

int main() {
  Database myDB;

  while (true) {
    int choice;
  
    show_menu();

    std::cout << std::endl;
    std::cout << "Choose option: ";
    std::cin >> choice;

    switch (choice) {
      case 0: {
        myDB.ClearDB();
        return 0;
      }

      case 1: {
        std::string name, genre, fact;
        int yob;
  
        std::cout << "Name: ";
        std::getline(std::cin, name);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Year of Birth: ";
        std::cin >> yob;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Genre: ";
        std::getline(std::cin, genre);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Fact: ";
        std::getline(std::cin, fact);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        myDB.AddComposer(
          name,
          genre,
          yob,
          fact
        );

        continue;
      }

      case 2: {
        int index;
        std::cout << "Composer index: ";
        std::cin >> index;

        myDB.DisplayByIndex(index);

        continue;
      }

      case 3: {
        int index;
        std::cout << "Composer index: ";
        std::cin >> index;

        Composer* composer = myDB.GetComposer(index);

        if (composer == nullptr) {
          std::cout << "Composer not found" << std::endl;
          continue;
        }

        int rank = 0;
        std::cout << "Provide rank: ";
        std::cin >> rank;

        if (rank < 0) {
          composer->Demote(std::abs(rank));
        } else {
          composer->Promote(rank);
        }

        continue;
      }
  
      case 4: {
        std::cout << std::endl << "All Composers: " << std::endl << std::endl;
        myDB.DisplayAll();
        continue;
      }

      case 5: {
        std::cout << std::endl << "Top Composers: " << std::endl << std::endl;
        myDB.DisplayByRank();
        continue;
      }
    }
  }

  return 0;
}