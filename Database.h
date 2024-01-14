#pragma once

#include <string>
#include "Composer.h"

class Database {
	public:
		static const int kMaxComposers = 100;

		Composer* AddComposer(
			std::string in_first_name,
			std::string in_last_name,
			std::string in_genre,
			int in_yob,
			std::string in_fact
		);

		Composer* GetComposer(std::string in_last_name);

		void DisplayAll();
		void DisplayByRank();

	private:
		Composer* composers_[kMaxComposers];
		int next_slot_ = 0;
};