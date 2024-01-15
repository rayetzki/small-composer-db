#pragma once

#include <string>

class Composer {
	public:
		Composer(
			std::string name,
			int composer_yob,
			std::string composer_genre,
			std::string fact
		) : name_(name), composer_yob_(composer_yob), composer_genre_(composer_genre), fact_(fact) {};

		std::string GetName() const;
		int GetRanking() const;

		void Promote(int increment);
		void Demote(int decrement);
		void Display();

	private:
		std::string name_;
		int composer_yob_;
		std::string composer_genre_;
		std::string fact_;
		int ranking_ = 0;
};