#pragma once

namespace myCustomer
{
	class Customer
	{
		int id;
		string name, surname, birthday;

	public:

		Customer(int id, string name, string surname, string birthday)
			: id(id), name(name), surname(surname), birthday(birthday) {}

		int getId() const { return id; }
		string getName() const { return name; }
		string getSurname() const { return surname; }
		string getBirthday() const { return birthday; }
	};
}