#pragma once

class Database
{
public:

	vector<ProductItem> productItem;
	vector<Admin> admins;
	vector<Customer> customers;

	void Create()
	{
		string name, color;
		double price;
		int quantity;

		cout << "\nAdd { PRODUCT NAME, COLOR, PRICE and QUANTITY }, for creating a new product : ";
		cin >> name >> color >> price >> quantity;

		Product* p = new Product(name, color, price);
		productItem.push_back(ProductItem(quantity, p));
	}

	void Read()
	{
		for (size_t i = 0; i < productItem.size(); i++)
			cout << productItem[i] << endl;
	}

	void Update()
	{
		int id;

		cout << "\nEnter { ID }, for updating : ";
		cin >> id;

		for (size_t i = 0; i < productItem.size(); i++)
		{
			if (productItem[i].getId() == id) 
			{
				int newItem;
				cout << "\nUpdate { QUANTITY } : ";
				cin >> newItem;
				productItem[i].quantity = newItem;
			}
		}
	}
};