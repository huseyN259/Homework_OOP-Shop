#pragma once

namespace myAdmin
{
	class Admin
	{
		int id;
		string username, password;

	public:

		Admin(int id, string username, string password)
			: id(id), username(username), password(password) {}

		int getId() const { return id; }
		string getUsername() const { return username; }
		string getPassword() const { return password; }
	};
}