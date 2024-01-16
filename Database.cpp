#include <iostream>
#include <string>
#include "Database.h"
#include "Composer.h"

Database::~Database() {
	for (int i = 0; i < next_slot_; i++) {
		delete composers_[i];
	}
}

Composer* Database::AddComposer(
	std::string in_name,
	std::string in_genre,
	int in_yob,
	std::string in_fact
) {
	Composer* composer = new Composer(
		in_name,
		in_yob,
		in_genre,
		in_fact
	);

	if (next_slot_ == kMaxComposers) {
		std::cout << "Database is full!" << std::endl;
		return composer;
	}

	composers_[next_slot_] = composer;
	next_slot_++;

	return composer;
};

Composer* Database::GetComposer(std::string query) {
	for (int i = 0; i < next_slot_; i++) {
		if (composers_[i]->GetName().find(query) != std::string::npos) {
			return composers_[i];
		}
	}

	return nullptr;
};

Composer* Database::GetComposer(int index) {
	if (index >= 0 && index <= next_slot_) {
		return composers_[index - 1];
	}

	return nullptr;
}

void Database::DisplayAll() {
	if (next_slot_ == 0) {
		std::cout << "There is no composer. Please add one." << std::endl;
	} else {
		for (int i = 0; i < next_slot_; i++) {
			std::cout << std::to_string(i + 1) + "." << std::endl;
			composers_[i]->Display();
		}
	}
};

void Database::DisplayByIndex(int index) {
	if (index >= 0 && index <= next_slot_) {
		composers_[index - 1]->Display();
		return;
	}
 
	std::cout << "Composer by index: " << index << " not found" << std::endl; 
}

void Database::DisplayByRank() {
	for (int i = 0; i < next_slot_; i++) {
		if (composers_[i]->GetRanking() > 0) {
			composers_[i]->Display();
		}
	}
};

void Database::ClearDB() {
	Database::~Database();
	next_slot_ = 0;
}
