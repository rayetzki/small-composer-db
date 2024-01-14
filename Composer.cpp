#include <iostream>
#include <string>
#include "Composer.h"

void Composer::set_first_name(const std::string in_first_name) {
	first_name_ = in_first_name;
};

std::string Composer::first_name() const {
	return first_name_;
};

void Composer::set_last_name(std::string in_last_name) {
	last_name_ = in_last_name;
};

std::string Composer::last_name() const {
	return last_name_;
};

void Composer::set_composer_yob(int in_composer_yob) {
	composer_yob_ = in_composer_yob;		
};

int Composer::composer_yob() const {
	return composer_yob_;
};

void Composer::set_composer_genre(std::string in_composer_genre) {
	composer_genre_ = in_composer_genre;
};

std::string Composer::composer_genre() const {
	return composer_genre_;
};

void Composer::set_ranking(int in_ranking) {
	ranking_ = in_ranking;
};

int Composer::ranking() const {
	return ranking_;
};

void Composer::set_fact(std::string in_fact) {
	fact_ = in_fact;
};

std::string Composer::fact() const {
	return fact_;
};

void Composer::Promote(int increment) {
	ranking_ += increment;			
};

void Composer::Demote(int decrement) {
	ranking_ -= decrement;
};

void Composer::Display() {
	std::cout << "Name: " << first_name_ << " " << last_name_ << std::endl;
	std::cout << "Year of Birth: " << composer_yob_ << std::endl;
	std::cout << "Genre: " << composer_genre_ << std::endl;
	std::cout << "Ranking: " << ranking_ << std::endl;
	std::cout << "Fact: " << fact_ << std::endl;
	std::cout << std::endl;
};
