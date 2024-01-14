#pragma once

#include <string>

class Composer {
	public:
		void set_first_name(std::string in_first_name);
		std::string first_name() const;

		void set_last_name(std::string in_last_name);
		std::string last_name() const;

		void set_composer_yob(int in_composer_yob);
		int composer_yob() const;

		void set_composer_genre(std::string in_composer_genre);
		std::string composer_genre() const;

		void set_ranking(int in_ranking);
		int ranking() const;
		
		void set_fact(std::string in_fact);
		std::string fact() const;

		void Promote(int increment);
		void Demote(int decrement);

		void Display();

	private:
		std::string first_name_;
		std::string last_name_;
		int composer_yob_;
		std::string composer_genre_;
		std::string fact_;
		int ranking_;
};