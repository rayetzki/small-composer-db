#include <iostream>
#include <string>
#include "Composer.h"

void Composer::Promote(int increment) {
	ranking_ += increment;	
};

void Composer::Demote(int decrement) {
	ranking_ -= decrement;
};

int Composer::GetRanking() const {
	return ranking_;
}

std::string Composer::GetName() const {
	return name_;
}

void Composer::Display() {
  std::cout << " ---------------------------------------------" << std::endl;
	std::cout << " Name: " << name_ << std::endl;
	std::cout << " Year of Birth: " << composer_yob_ << std::endl;
	std::cout << " Genre: " << composer_genre_ << std::endl;
	std::cout << " Ranking: " << ranking_ << std::endl;
	std::cout << " Fact: " << fact_ << std::endl;
	std::cout << std::endl;
};
