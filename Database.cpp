#include <iostream>
#include <string>
#include "Database.h"
#include "Composer.h"

Composer* Database::AddComposer(
	std::string in_first_name,
	std::string in_last_name,
	std::string in_genre,
	int in_yob,
	std::string in_fact
) {
	Composer* composer = new Composer();

	composer->set_first_name(in_first_name);
	composer->set_last_name(in_last_name);
	composer->set_composer_yob(in_yob);
	composer->set_composer_genre(in_genre);
	composer->set_fact(in_fact);

	if (next_slot_ == kMaxComposers) {
		std::cout << "Database is full!" << std::endl;
		return composer;
	}

	composers_[next_slot_] = composer;
	next_slot_++;

	return composer;
};

Composer* Database::GetComposer(std::string in_last_name) {
	for (int i = 0; i < next_slot_; i++) {
		if (composers_[i]->last_name() == in_last_name) {
			return composers_[i];
		}
	}

	return nullptr;
};

void Database::DisplayAll() {
	for (int i = 0; i < next_slot_; i++) {
		composers_[i]->Display();
	}
};

void Database::DisplayByRank() {
	for (int i = 0; i < next_slot_; i++) {
		if (composers_[i]->ranking() > 0) {
			composers_[i]->Display();
		}
	}
};
