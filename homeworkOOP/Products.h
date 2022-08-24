#pragma once

namespace myProducts 
{
	class Product
	{
		static int staticId;
		int id;
		string name, color;
		double price;

	public:

		Product(string name, string color, double price)
			: id(staticId++), name(name), color(color), price(price) {}

		int getId() const { return id; }
		string getName() const { return name; }
		string getColor() const { return color; }
		double getPrice() const { return price; }

		friend ostream& operator<<(ostream& out, const Product p);
	};

	int Product::staticId = 1;

	ostream& operator<<(ostream& out, const Product p)
	{
		out << "Id : " << p.id << endl;
		out << "Name : " << p.name << endl;
		out << "Color : " << p.color << endl;
		out << "Price : " << p.price << endl;

		return out;
	}

	class ProductItem 
	{
		static int staticId;
		int id;
		Product* product;

	public:

		int quantity;

		ProductItem(int quantity, Product* product)
			:id(++staticId), quantity(quantity), product(product) {}

		int getId()const { return id; }
		Product getProduct() { return *product; }
		double TotalPrice() { return product->getPrice() * quantity; }
		int getQuantity()const { return quantity; }
		
		friend ostream& operator<<(ostream& out, const ProductItem& p);
	};

	int ProductItem::staticId = 0;

	ostream& operator<<(ostream& out, const ProductItem& p) 
	{
		out << "\nProduct Item Id : " << p.id << endl;
		out << "Quantity : " << p.quantity << endl;
		out << "Product : " << *p.product << endl;
		
		return out;
	}
}