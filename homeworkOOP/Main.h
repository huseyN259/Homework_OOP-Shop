#pragma once

class Main
{
public:

	static void Start()
	{
		Database d;
		d.admins.push_back(Admin(1, "Huseyn", "huseyn123"));
		d.admins.push_back(Admin(2, "Nuran", "nuran321"));

		Product p1 = Product("Apple", "Green", 2.5);
		Product p2 = Product("Strawberry", "Red", 4.3);

		d.productItem.push_back(ProductItem(30, &p1));
		d.productItem.push_back(ProductItem(45, &p2));

		cout << "\t\t\t\t\t======== Welcome to E-SHOP PROGRAM ========" << endl;
		cout << "Loading..." << endl;
		Sleep(2000);
		system("cls");

		int select;
		while (true)
		{
			cout << "\nADMIN -> 1\nCUSTOMER -> 2\nEXIT -> 3\n" << endl;
			cin >> select;

			if (select == 1)
			{
				int choice;
				string username, password;

				cout << "\nEnter USERNAME : ";
				cin >> username;
				cout << "Enter PASSWORD : ";
				cin >> password;

				for (size_t i = 0; i < d.admins.size(); i++)
				{
					if (d.admins[i].getUsername() == username && d.admins[i].getPassword() == password)
					{
						cout << "\nSHOW ALL PRODUCTS -> 1\nADD PRODUCT -> 2\nUPDATE -> 3\n" << endl;
						cin >> choice;

						if (choice == 1)
							d.Read();
						else if (choice == 2)
							d.Create();
						else if (choice == 3)
							d.Update();
						else
							cout << "\nInvalid Choice !\n" << endl;
					}
				}
			}

			else if (select == 2)
			{
				int id;
				string name, surname, birthday;

				cout << "\nEnter { ID, NAME, SURNAME, BIRTHDAY } : ";
				cin >> id >> name >> surname >> birthday;

				Customer c(id, name, surname, birthday);
				d.customers.push_back(c);
				cout << "\n";

				for (size_t i = 0; i < d.productItem.size(); i++)
				{
					cout << "\nId : " << d.productItem[i].getId() << endl;
					cout << "Name : " << d.productItem[i].getProduct().getName() << endl;
					cout << "Color : " << d.productItem[i].getProduct().getColor() << endl;
					cout << "Price : " << d.productItem[i].getProduct().getPrice() << endl;
				}

				char yesNo;
				cout << "\n";
				cout << "\nDo you want to buy ? (y / n) : ";
				cin >> yesNo;

				if (yesNo == 'y' || yesNo == 'Y')
				{
					int bId;
					cout << "\nEnter { ID } : ";
					cin >> bId;

					double cost;
					cout << "Enter any { COST } : ";
					cin >> cost;

					for (size_t i = 0; i < d.productItem.size(); i++)
					{
						if (bId == d.productItem[i].getId())
						{
							d.productItem[i].quantity -= cost;
							cout << "\nPlease...\n" << endl;
						}
					}
				}
			}

			else if (select == 3)
			{
				cout << "\nGood-bye !\n" << endl;
				break;
			}

			else 
				cout << "\nInvalid Choice !\n" << endl;
		}
	}
};