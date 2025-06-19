#include <iostream> // For the functions of Input and Output to and from console, respectively.
#include <fstream> // For the functions of (Input and Output) and (Write Data and Fetch Data) to and from Files, respectively. //FILE HANDLING TEXT BASED .TXT
#include <string> //For using string based text, for storing whole sentences in the variables known as string data type in C++.

using namespace std; // For CIN & COUT

// Maximum number of products, cart size, and order history size.
const int MAX_PRODUCTS = 50;
const int MAX_CART_SIZE = 10;
const int MAX_ORDERS = 10; // These are Maximum number of orders.

// Product class to manage product details
class Product
{
	private:
	    // Product attributes
		//Product ID
		int id; 
	    //Product Name
	    string name;
		//Product Price
	    double price;
		//Product Quantity
	    // This is the quantity of this specific product available in the inventory.
	    int quantity;
	
	public:
	    // Parameterized Constructor
	    Product(int id = 0, string name = "", double price = 0.0, int quantity = 0) : id(id), name(name), price(price), quantity(quantity) {}
	
	    // Getters 
	    int getId() const { return id; }
	    string getName() const { return name; }
	    double getPrice() const { return price; }
	    int getQuantity() const { return quantity; }
	
	    // Function to display product details
	    void display() const
	    {
	        cout << "ID: " << id << ", Name: " << name << ", Price: $" << price << ", Available Quantity: " << quantity << endl;
	    }
	
	    // Function to save product to file
	    void saveToFile(ofstream& outFile) const
		{
	        outFile << id << "," << name << "," << price << "," << quantity << endl;
	    }
	
	    // Load product from file
	    void loadFromFile(const string& line) 
		{
	        size_t pos = 0; // Position of the comma in the line
	        string token; // Token to hold the split parts of the line
	        int field = 0; // Field index to track which part of the line we are parsing
	
	        // Parse the line
	        string tempLine = line; // Create a mutable copy of the line
	        while ((pos = tempLine.find(',')) != string::npos) // Find the position of the next comma
			{
	            token = tempLine.substr(0, pos); // Extract the token up to the comma
	            // Assign the token to the appropriate field based on the index
	            switch (field) //
				{
	                case 0: id = stoi(token); break; //ID of Product
	                case 1: name = token; break; //Name of Product
	                case 2: price = stod(token); break; //Price 
	                case 3: quantity = stoi(token); break; //Quantity of Product
	            }
	            tempLine.erase(0, pos + 1); // Erase the processed token and comma from the line
	            field++; // Increment the field index to move to the next part of the line
	        }
	        // Handle the last token (quantity) if it exists
	        if (field == 3) // If we have processed three fields, the last one is quantity
			{
	            quantity = stoi(tempLine); // Set quantity from the last token
	        }
	    }
};

// Inventory class to manage products
class Inventory 
{
	private:
	    Product products[MAX_PRODUCTS];
	    int productCount;
	
	public:
	    Inventory() : productCount(0) {}
	
	    // Add product to inventory
	    void addProduct(int id, string name, double price, int quantity) 
		{
	        if (productCount < MAX_PRODUCTS) 
			{
	            products[productCount++] = Product(id, name, price, quantity);
	        }
			else 
			{
	            cout << "Inventory is full! Cannot add more products." << endl;
	        }
	    }
	
	    // Update product details
	    void updateProduct(int id, string name, double price, int quantity) 
		{
	        for (int i = 0; i < productCount; ++i) 
			{
	            if (products[i].getId() == id) 
				{
	                products[i] = Product(id, name, price, quantity);
	                cout << "Product updated successfully." << endl;
	                return;
	            }
	        }
	        cout << "Product not found." << endl;
	    }
	
	    // Update product quantity
	    void updateProductQuantity(int id, int quantity) 
		{
	        for (int i = 0; i < productCount; ++i) 
			{
	            if (products[i].getId() == id) 
				{
	                int newQuantity = products[i].getQuantity() - quantity;
	                if (newQuantity < 0) 
					{
	                    cout << "Not enough stock for product ID: " << id << endl;
	                }
					else 
					{
	                    products[i] = Product(id, products[i].getName(), products[i].getPrice(), newQuantity);
	                    cout << "Updated quantity for product: " << products[i].getName() << " to " << newQuantity << endl;
	                }
	                return; // Exits the function making it sure that it does not work extra
	            }
	        }
	        cout << "Product not found in inventory." << endl;
	    }
	
	    // Delete product from inventory
	    void deleteProduct(int id) 
		{
	        for (int i = 0; i < productCount; ++i) 
			{
	            if (products[i].getId() == id) 
				{
	                for (int j = i; j < productCount - 1; ++j) 
					{
	                    products[j] = products[j + 1]; // Shift products left
	                }
	                productCount--;
	                cout << "Product deleted successfully." << endl;
	                return; // Exits the function making it sure that it does not work extra
	            }
	        }
	        cout << "Product not found." << endl;
	    }
	
	    // Display all products
	    void displayProducts() const 
		{
	        cout << "\nAvailable Products:\n";
	        for (int i = 0; i < productCount; ++i) 
			{   
				products[i].display();
			}
		}
	    // Find product by ID
	    Product* findProduct(int id) 
		{
	        for (int i = 0; i < productCount; ++i) 
			{
	            if (products[i].getId() == id) 
				{
	                return &products[i];
	            }
	        }
	        return nullptr;
	    }
	
	    // Save products to file
	    void saveToFile(const string& filename) 
		{
	        ofstream outFile(filename);
	        if (outFile.is_open()) 
			{
	            for (int i = 0; i < productCount; ++i) 
				{
	                products[i].saveToFile(outFile);
	            }
	            outFile.close();
	            cout << "Products saved to file." << endl;
	        } 
			else 
			{
	            cout << "Error opening file for writing." << endl;
	        }
	    }
	
	    // Load products from file
	    void loadFromFile(const string& filename) 
		{
	        ifstream inFile(filename);
	        if (inFile.is_open()) 
			{
	            string line;
	            while (getline(inFile, line)) 
				{
	                Product product;
	                product.loadFromFile(line);
	                cout << "Loaded product: " << product.getName() << " with quantity: " << product.getQuantity() << endl; // Debug statement
	                addProduct(product.getId(), product.getName(), product.getPrice(), product.getQuantity());
	            }
	            inFile.close();
	            cout << "Products loaded from file." << endl;
	        } 
	        else
			{
	            cout << "No existing product file found. Starting with an empty inventory." << endl;
	        }
	    }
};

// ShoppingCart class to manage the shopping cart
class ShoppingCart 
{
	public:
	    struct CartItem 
		{
	        Product product;
	        int quantity; // Quantity of the product being bought
	    };
	
	private:
	    CartItem cart[MAX_CART_SIZE];
	    int cartSize;
	
	public:
	    ShoppingCart() : cartSize(0) {}
	
	    // Add product to cart
	    void addProduct(const Product& product, int quantity) 
		{
	        if (cartSize < MAX_CART_SIZE) 
			{
	            // Check if the product is already in the cart
	            for (int i = 0; i < cartSize; ++i) 
				{
	                if (cart[i].product.getId() == product.getId()) 
					{
	                    cart[i].quantity += quantity; // Increase quantity if already in cart
	                    cout << "Increased quantity of " << product.getName() << " in cart." << endl;
	                    return;
	                }
	            }
	            
	            // If not in cart, add new item
	            cart[cartSize++] = {product, quantity};
	            cout << "Product added to cart." << endl;
	        } 
			else 
			{
	            cout << "Cart is full! Cannot add more products." << endl;
	        }
	    }
	
	    // Remove product from cart by ID
	    void removeProduct(int id) 
		{
	        for (int i = 0; i < cartSize; ++i) 
			{
	            if (cart[i].product.getId() == id) 
				{
	                for (int j = i; j < cartSize - 1; ++j) 
					{
	                    cart[j] = cart[j + 1]; // Shift products left
	                }
	                cartSize--;
	                cout << "Product removed from cart." << endl;
	                return;
	            }
	        }
	        cout << "Product not found in cart." << endl;
	    }
	
	    // Display cart contents
	    void displayCart() const 
		{
	        cout << "\nShopping Cart Contents:\n";
	        for (int i = 0; i < cartSize; ++i) 
			{
	            cout << "Product: ";
	            cart[i].product.display();
	            cout << "Quantity: " << cart[i].quantity << endl; // Display quantity being bought
	        }
	    }
	
	    // Calculate total price
	    double calculateTotal() const 
		{
	        double total = 0;
	        for (int i = 0; i < cartSize; ++i) 
			{
	            total += cart[i].product.getPrice() * cart[i].quantity; // Total price based on quantity
	        }
	        return total;
	    }
	
	    // Clear cart
	    void clearCart() 
		{
	        cartSize = 0;
	    }
	
	    // Get products in cart
	    CartItem* getProducts() 
		{
	        return cart;
	    }
	
	    int getCartSize() const 
		{
	        return cartSize;
	    }
};

// Order class to manage order details
class Order 
{
	private:
	    struct OrderItem 
		{
	        Product product;
	        int quantity; // Quantity of the product in the order
	    };
	
	    OrderItem orderItems[MAX_CART_SIZE];
	    int productCount;
	    double total;
	
	public:
	    // Parameterized Constructor 
	    Order(const ShoppingCart::CartItem* cartItems, int count, double total) : total(total), productCount(count) 
		{
	        for (int i = 0; i < count; ++i) 
			{
	            orderItems[i] = {cartItems[i].product, cartItems[i].quantity}; // Store product and quantity
	        }
	    }
	
	    // Default constructor
	    Order() : productCount(0), total(0) {}
	
	    void displayOrder() const 
		{
	        cout << "Order Details:\n";
	        for (int i = 0; i < productCount; ++i) 
			{
	            orderItems[i].product.display();
	            cout << "Quantity: " << orderItems[i].quantity << endl; // Display quantity in order
	        }
	        cout << "Total Amount: $" << total << endl;
	    }
};

// User class as a base class
class User 
{
	protected:
	    string username;
	    string password;
	
	public:
	    User(string username, string password) : username(username), password(password) {}
	    virtual ~User () {}
	
	    // Virtual function for displaying user information
	    virtual void displayInfo() const 
		{
	        cout << "Username: " << username << endl;
	    }
};

// Admin class to manage inventory
class Admin : public User 
{
	public:
	    Admin(string username, string password) : User(username, password) {}
	
	    void addProduct(Inventory& inventory, int id, string name, double price, int quantity) 
		{
	        inventory.addProduct(id, name, price, quantity);
	    }
	
	    void updateProduct(Inventory& inventory, int id, string name, double price, int quantity) 
		{
	        inventory.updateProduct(id, name, price, quantity);
	    }
	
	    void deleteProduct(Inventory& inventory, int id) 
		{
	        inventory.deleteProduct(id);
	    }
	
	    void displayInfo() const override 
		{
	        cout << "Admin Username: " << username << endl;
	    }
};

// Customer class to manage shopping cart and order history
class Customer : public User 
{
	private:
	    ShoppingCart cart;
	    Order orderHistory[MAX_ORDERS];
	    int orderCount;
	    Inventory& inventory; // Reference to inventory
	
	public:
	    Customer(string username, string password, Inventory& inv) 
	        : User(username, password), orderCount(0), inventory(inv) {}
	
	    void addToCart(Product product, int quantity) 
		{
	        cart.addProduct(product, quantity);
	    }
	
	    void removeFromCart(int id) 
		{
	        cart.removeProduct(id);
	    }
	
	    void viewCart() 
		{
	        cart.displayCart();
	    }
	
	    void checkout() 
		{
	        double total = cart.calculateTotal();
	        if (total > 0) 
			{
	            // Create the order
	            orderHistory[orderCount++] = Order(cart.getProducts(), cart.getCartSize(), total);
	            cout << "Order placed successfully!" << endl;
	
	            // Update inventory based on cart items
	            for (int i = 0; i < cart.getCartSize(); ++i) 
				{
	                int productId = cart.getProducts()[i].product.getId();
	                int quantity = cart.getProducts()[i].quantity;
	                inventory.updateProductQuantity(productId, quantity); // Update inventory
	            }
	            inventory.saveToFile("products.txt");
	
	            cart.clearCart(); // Clear cart after checkout
	        }
			
			else 
			{
	            cout << "Cart is empty!" << endl;
	        }
	    }
	
	    void viewOrderHistory() 
		{
	        cout << "Order History:\n";
	        for (int i = 0; i < orderCount; ++i) 
			{
	            orderHistory[i].displayOrder();
	        }
	    }
	
	    void displayInfo() const override 
		{
	        cout << "Customer Username: " << username << endl;
	    }
};

// Main function to run the shopping cart management system
int main()
{
    Inventory inventory;
    inventory.loadFromFile("products.txt");

    Admin admin("admin", "admin123"); // We have passed the admin Username & Password by default to reduce number of lines of code.
    Customer customer("customer", "customer123", inventory); // Pass inventory reference

    int choice;
    do 
	{
        cout << "\n========= Online Shopping Cart Management System =========\n";
        cout << "1. Login To ADMIN\n";
        cout << "2. Login To Customer\n";
        cout << "3. Exit\n";
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        switch (choice) 
		{
            case 1: // Enters to Admin Portal for admin controls.
                system("cls"); //Cleans up the console for a better neat looking otherwise it seems messy.
                int optiona;
                do 
				{
                    cout << "========= Online Shopping Cart Management System =========\n====================== Admin Portal ======================\n";
                    cout << "1. View Products\n";
                    cout << "2. Add Product to Inventory\n";
                    cout << "3. Update Product in Inventory\n";
                    cout << "4. Delete Product from Inventory\n";
                    cout << "5. Exit\n";
                    cout << "Enter your choice (1-5): ";
                    cin >> optiona;

                    switch (optiona) 
					{
                        case 1:
                            system("cls"); //Cleans up the console for a better neat looking otherwise it seems messy.
							inventory.displayProducts();
                            break;
                        case 2:{
                            system("cls"); //Cleans up the console for a better neat looking otherwise it seems messy.
							int id, quantity;
                            string name;
                            double price;
                            cout << "Enter Product ID: ";
                            cin >> id;
                            cout << "Enter Product Name: ";
                            cin >> name;
                            cout << "Enter Product Price: ";
                            cin >> price;
                            cout << "Enter Product Quantity: ";
                            cin >> quantity;
                            admin.addProduct(inventory, id, name, price, quantity);
                            inventory.saveToFile("products.txt");
                            break;
                        }
                        case 3: {
                        	system("cls"); //Cleans up the console for a better neat looking otherwise it seems messy.                        	
                            int id, quantity;
                            string name;
                            double price;
                            cout << "Enter Product ID to update: ";
                            cin >> id;
                            cout << "Enter new Product Name: ";
                            cin >> name;
                            cout << "Enter new Product Price: ";
                            cin >> price;
                            cout << "Enter new Product Quantity: ";
                            cin >> quantity;
                            admin.updateProduct(inventory, id, name, price, quantity);
                            inventory.saveToFile("products.txt");
                            break;
                        }
                        case 4: {
                        	system("cls"); //Cleans up the console for a better neat looking otherwise it seems messy.                        	
                            int id;
                            cout << "Enter Product ID to delete: ";
                            cin >> id;
                            admin.deleteProduct(inventory, id);
                            inventory.saveToFile("products.txt");
                            break;
                        }
                        case 5:
                        	system("cls"); //Cleans up the console for a better neat looking otherwise it seems messy.                        	
                            cout << "Exiting program..." << endl;
                            break;
                        default:
                        	system("cls"); //Cleans up the console for a better neat looking otherwise it seems messy.                        	
                            cout << "Invalid option. Try again." << endl;
                    }
                } while (optiona != 5);
                break;
            case 2: // Enters to Customer Portal for Customer controls of Ordering and more...
                system("cls"); //Cleans up the console for a better neat looking otherwise it seems messy.
                int optionc;
                do {
                    cout << "========= Online Shopping Cart Management System =========\n==================== Customer Portal =====================\n";
                    cout << "1. View Products\n";
                    cout << "2. Add Product to Cart\n";
                    cout << "3. Remove Product from Cart\n";
                    cout << "4. View Cart\n";
                    cout << "5. Checkout Now\n";
                    cout << "6. Check Order History\n";
                    cout << "7. Exit\n";
                    cout << "Enter your choice (1-7): ";
                    cin >> optionc;

                    switch (optionc) 
					{
                        case 1:
                        	system("cls"); //Cleans up the console for a better neat looking otherwise it seems messy.                        	
                            inventory.displayProducts();
                            break;
                        case 2:{
                        	system("cls"); //Cleans up the console for a better neat looking otherwise it seems messy.                        	
                            int id, quantity;
                            cout << "Enter Product ID to add to cart: ";
                            cin >> id;
                            cout << "Enter Quantity: ";
                            cin >> quantity;
                            Product* product = inventory.findProduct(id);
                            if (product) 
							{
                                customer.addToCart(*product, quantity);
                            }
							else 
							{
                                cout << "Product not found." << endl;
                            }
                            break;
                        }
                        case 3: {
                        	system("cls"); //Cleans up the console for a better neat looking otherwise it seems messy.                        	
                            int id;
                            cout << "Enter Product ID to remove from cart: ";
                            cin >> id;
                            customer.removeFromCart(id);
                            break;
                        }
                        case 4: 
                        	system("cls"); //Cleans up the console for a better neat looking otherwise it seems messy.                        
                            customer.viewCart();
                            break;
                        case 5:
                            system("cls"); //Cleans up the console for a better neat looking otherwise it seems messy.
							customer.checkout();
                            break;
                        case 6:
                            system("cls"); //Cleans up the console for a better neat looking otherwise it seems messy.
							customer.viewOrderHistory();
                            break;
                        case 7:
                            system("cls"); //Cleans up the console for a better neat looking otherwise it seems messy.
							cout << "Exiting program..." << endl;
                            break;
                        default:
                        	system("cls"); //Cleans up the console for a better neat looking otherwise it seems messy.                        	
                            cout << "Invalid option. Try again." << endl;
                    }
                } while (optionc != 7);
                break;
            case 3: // At this point Program quits.
                system("cls"); //Cleans up the console for a better neat looking otherwise it seems messy.
                cout << "Exiting program..." << endl;
                break;
            default:
            	system("cls"); //Cleans up the console for a better neat looking otherwise it seems messy.            	
                cout << "Invalid option. Try again." << endl;
        }
    } while (choice != 3);
    
    return 0;
}
