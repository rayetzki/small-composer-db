#pragma once

#include <string>
#include <array>
#include "Composer.h"

class Database {
	public:
		static const int kMaxComposers = 100;

		~Database();

		Composer* AddComposer(
			std::string in_name,
			std::string in_genre,
			int in_yob,
			std::string in_fact
		);

		Composer* GetComposer(std::string in_name);
		Composer* GetComposer(int index);

		void DisplayAll();
		void DisplayByIndex(int index);
		void DisplayByRank();
		void ClearDB();

	private:
		Composer* composers_[kMaxComposers];
		int next_slot_ = 0;
};