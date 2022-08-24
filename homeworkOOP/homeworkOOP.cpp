#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>

using namespace std;

#include "Admin.h"
using namespace myAdmin;

#include "Customer.h"
using namespace myCustomer;

#include "Products.h"
using namespace myProducts;

#include "Database.h"
#include "Main.h"

int main()
{
	Main::Start();

	return EXIT_SUCCESS;
}