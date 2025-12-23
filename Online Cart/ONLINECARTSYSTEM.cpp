#include <iostream> //For the functions of Input and Output to and from console, respectively.
#include <fstream> //For the functions of (Input and Output) and (Write Data and Fetch Data) to and from Files, respectively. //FILE HANDLING TEXT BASED .TXT
#include <string> //For using string based text, for storing whole sentences in the variables known as string data type in C++.
#include <windows.h> //using for creating time delays for a better program view.

using namespace std; // For CIN & COUT

// Class created up for colourful attractive display
class Color {
	public:
	    // Foreground colors
	    static const string BLACK;
	    static const string RED;
	    static const string GREEN;
	    static const string YELLOW;
	    static const string BLUE;
	    static const string MAGENTA;
	    static const string CYAN;
	    // Add ORANGE color (256-color mode)
    	static const string ORANGE;
	    static const string WHITE;
	    
	    // Background colors
	    static const string BG_BLACK;
	    static const string BG_RED;
	    static const string BG_GREEN;
	    static const string BG_YELLOW;
	    static const string BG_BLUE;
	    static const string BG_MAGENTA;
	    static const string BG_CYAN;
	    static const string BG_WHITE;
	    
	    // Text styles defined
	    static const string BOLD;
	    static const string UNDERLINE;
	    static const string ITALIC;
	    static const string BLINK;
	    
	    // Reset all attributes 
	    static const string RESET;
	    
	    // Enable colors on Windows 
	    static void enableColors() {
	        #ifdef _WIN32
	        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	        DWORD dwMode = 0;
	        GetConsoleMode(hOut, &dwMode);
	        dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	        SetConsoleMode(hOut, dwMode);
	        #endif
	    }
};

// Initialize foreground color constants
const string Color::BLACK = "\033[30m";
const string Color::RED = "\033[31m";
const string Color::GREEN = "\033[32m";
const string Color::YELLOW = "\033[33m";
const string Color::BLUE = "\033[34m";
const string Color::MAGENTA = "\033[35m";
const string Color::CYAN = "\033[36m";
const string Color::WHITE = "\033[37m";
// Initialize ORANGE constant
const string Color::ORANGE = "\033[38;5;208m";  // 208 is the color code for orange

// Initialize background color constants
const string Color::BG_BLACK = "\033[40m";
const string Color::BG_RED = "\033[41m";
const string Color::BG_GREEN = "\033[42m";
const string Color::BG_YELLOW = "\033[43m";
const string Color::BG_BLUE = "\033[44m";
const string Color::BG_MAGENTA = "\033[45m";
const string Color::BG_CYAN = "\033[46m";
const string Color::BG_WHITE = "\033[47m";

// Initialize style constants
const string Color::BOLD = "\033[1m";
const string Color::UNDERLINE = "\033[4m";
const string Color::ITALIC = "\033[3m";
const string Color::BLINK = "\033[5m";

//Initializes function of reset
const string Color::RESET = "\033[0m";

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
	    int getId() const { return id; } // This function returns the ID of the product.
	    string getName() const { return name; } // This function returns the Name of the product.
	    double getPrice() const { return price; } // This function returns the Price of the product.
	    int getQuantity() const { return quantity; } // This function returns the Quantity of the product.
	
	    // This Function displays product details
	    void display() const
	    {
			cout << "ID: " << id << ", Name: " << name << ", Price: $" << price << ", Available Quantity: " << quantity << endl;
	    }
	
	    // Function to save product to file
	    void saveToFile(ofstream& outFile) const
		{
	        // Saves the product details in a comma-separated format.
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
	    // Array to hold products
		Product products[MAX_PRODUCTS];
	
		// Current count of products in the inventory
		// This is the current number of products available in the inventory. 
	    int productCount;
	
	public:
	    Inventory() : productCount(0) {} // Constructor initializes productCount to 0
	
	    // This function adds a new product to the inventory.
	    void addProduct(int id, string name, double price, int quantity) 
		{
	        if (productCount < MAX_PRODUCTS) // Check if there is space in the inventory
			{
	            products[productCount++] = Product(id, name, price, quantity);
	        }
			else 
			{	// This part is executed when the inventory is full.
	            // It checks if the inventory is full by comparing the current product count with the maximum allowed
	            // If the inventory is full, it displays a message.
	            // This is to ensure that the inventory does not exceed the maximum limit of products.			
	            cout << "Inventory is full! Cannot add more products." << endl;
	        }
	    }
	
	    // Update product details
	    void updateProduct(int id, string name, double price, int quantity) 
		{
			// This function updates the details of an existing product in the inventory.
	        // It searches for the product by ID and updates its name, price, and quantity.
	        for (int i = 0; i < productCount; ++i) //This loop iterates through the products in the inventory.
			{
	            if (products[i].getId() == id) // Checks if the current product's ID matches the given ID
				{
	                // Updation takes place here.
					products[i] = Product(id, name, price, quantity); 
					// This line creates a new Product object with the updated details and assigns it to the current product in the inventory.
	                // This effectively updates the product's details in the inventory.
	                cout << "Product updated successfully." << endl;
	
	                return; // Exits the function making it sure that it does not execute the rest of the code after this point.
	            }
	        }
	        cout << "Product not found." << endl; // This line is executed when the product with the given ID is not found in the inventory.
	    }
	
	    // Update product quantity
	    void updateProductQuantity(int id, int quantity) 
		{
	        // This function updates the quantity of an existing product in the inventory.
	        // It searches for the product by ID and decreases its quantity by the specified amount.
			for (int i = 0; i < productCount; ++i) // This loop iterates through the products in the inventory.
			{
	            // Checks if the current product's ID matches the given ID
				if (products[i].getId() == id) 
				{
	                // Decrementing the quantity of the product by the specified amount.
					// This line calculates the new quantity by subtracting the specified quantity from the current quantity of the product.
					int newQuantity = products[i].getQuantity() - quantity;
	
					// It checks if the new quantity is less than 0, which means there is not enough stock.
	                if (newQuantity < 0) 
					{
	                    cout << "Not enough stock for product ID: " << id << endl;
	                }
					// If there is enough stock, it updates the product's quantity in the inventory.
					// This line creates a new Product object with the updated quantity and assigns it to the current product in the inventory.
					else 
					{
						// This line updates the product's details in the inventory with the new quantity.
						products[i] = Product(id, products[i].getName(), products[i].getPrice(), newQuantity);
	
						// This line displays a message indicating that the quantity has been updated successfully.
						// It uses the getName() function to retrieve the product's name and displays it.
						// This is to ensure that the product's name is displayed correctly after the update.
	                    cout << "Updated quantity for product: " << products[i].getName() << " to " << newQuantity << endl;
	                }
	
	                return; // Exits the function making it sure that it does not execute the rest of the code after this point.
	            }
	        }
	
			// If the product with the given ID is not found in the inventory, it displays a message indicating that the product was not found.
	        // This is to ensure that the user is informed when they try to update a product that does not exist in the inventory.
	        cout << "Product not found in inventory." << endl;
	    }
	
	    // Delete product from inventory
	    void deleteProduct(int id) 
		{
			// This function deletes a product from the inventory by its searching, matching through the product ID.
	        for (int i = 0; i < productCount; ++i) // This loop iterates through the products in the inventory.
			{
	            if (products[i].getId() == id)
				{
	                for (int j = i; j < productCount - 1; ++j) // This loop shifts the products left to fill the gap created by the deleted product. It starts from the index of the deleted product and goes to the second last product.
					{
	                    products[j] = products[j + 1]; // Shift products left
	                }
	                
					productCount--;	// Decrease the product count by 1 to reflect the deletion.
	                
					// This line displays a message indicating that the product has been deleted successfully.
	                cout << "Product deleted successfully." << endl;
	                
					return; // Exits the function making it sure that it does not execute the rest of the code after this point.
	            }
	        }
	        cout << "Product not found." << endl; // This line is executed when the product with the given ID is not found in the inventory.
	    }
	
	    // Display all products
	    void displayProducts() const // This function is kept const to ensure that it does not modify the inventory.
		{
	        cout << Color::GREEN << Color::BOLD;
			cout << "Available Products:\n";
			cout << Color::RESET;

			cout << Color::GREEN;
			// This loop iterates through all the products in the inventory and displays all of them with their details.
	        for (int i = 0; i < productCount; ++i) 
			{   
				products[i].display(); // This line calls the display function of each product to print its details.
			}
			
			cout << endl; // Used for neatness
			cout << Color::RESET;
			
			cout << Color::BOLD << Color::BLUE;
			system("pause"); //This helps to view the products until unless user presses any key from keyboard.
			cout << Color::RESET;
		}
	    
		// Find product by ID
	    Product* findProduct(int id) // Pointer function to find a product by its ID. Why Pointer? Because it returns the address of the product in the array.
		{
	        for (int i = 0; i < productCount; ++i)  // pre-increment loop to iterate through the products in the inventory.
			{
	            if (products[i].getId() == id) 
				{
	                return &products[i]; // Returns the address of the product if found.
	                // This line returns the address of the product in the array, allowing the caller to access the products with their details.
	            }
	        }
	        return nullptr; // Why nullptr? Because nullptr is used as only value of pointer data type can be returned.
	    }
	
	    // Save products to file
	    void saveToFile(const string& filename) 
		{
			// File is being opened for writing.
	        ofstream outFile(filename); 
	    	
			// Checks if the file is successfully opened for writing.
		    if (outFile.is_open()) 
			{
				// This loop iterates through all the products in the inventory and saves them to the file.
	            for (int i = 0; i < productCount; ++i) //
				{
					// Calls the saveToFile function of each product to write its details to the file.
	                // This line writes the product details in a comma-separated format to the file.
	                products[i].saveToFile(outFile);
	            }
			
				// Closes the file after writing all the products to it.
	            // This line closes the file to ensure that all data is written and resources are now not in use released.
	            outFile.close(); 
	        
			    cout << "Products saved to file." << endl; //
	        } 
			
			// If the file cannot be opened for writing, it displays an error message.
	        // This is to ensure so the user is knows it well that there is an issue with file handling
			else 
			{
	            cout << "Error opening file for writing." << endl;
	        }
	    }
	
	    // Load products from file
	    void loadFromFile(const string& filename) // This function loads products from a file to the program by reading up the file line by line and then added them to the inventory.
		{
	        // File is being opened for reading.
			ifstream inFile(filename); 
	        
	        // Displays the Program Title
//	        cout << "========= Online Shopping Cart Management System =========\n\n";
	        
			// Checks if the file is successfully opened for reading.
	        if (inFile.is_open()) 
			{
	            string line; // Variable to hold each line read from the file
	            
	            // This loop reads each line from the file until the end of the file is reached.
	            while (getline(inFile, line)) // getline reads a line from the file and stores it in the line variable.
				{
					// Create a Product object to hold the product details
	                Product product; 
	            
				    // loadFromFile function is called to parse the line and fill the product object with details.
					product.loadFromFile(line);
				
					// Debug statement to check if the product is loaded correctly
	                // This line prints the product name and quantity to the console for debugging purposes.
//	                cout << "Loaded product: " << product.getName() << " with quantity: " << product.getQuantity() << endl; // Debug statement
	            
				    // Adds the loaded product to the inventory by calling the addProduct function.
					addProduct(product.getId(), product.getName(), product.getPrice(), product.getQuantity());
	            }
				
				// Closes the file after reading all the products from it.
	            // This line closes the file to ensure that all data is read and resources are now not in use released.  
				inFile.close();
				
				// This line displays a message indicating that the products have been loaded from the file successfully.
//	            cout << "Products loaded from file." << endl << endl;
	            
//				system("pause"); //This helps to view the products until unless user presses any key from keyboard.
	            system("cls"); //Cleans up the console for a better neat looking otherwise it seems messy.            	
	        } 
	        
			// If the file is not opened for reading, it displays an error message.
	        // This is to ensure so the user is knows it well that there is an issue with file handling
	        else
			{
				// This line displays a message indicating that no existing product file was found.
	            // It is used to inform the user that the inventory is empty right now with no products in it.
	            cout << "No existing product file found. Starting with an empty inventory." << endl;
	        }
	    }
};

// ShoppingCart class to manage the shopping cart
class ShoppingCart 
{
	// Why firstly we have to define the CartItem structure as public, secondly cart size as privately, then thirdly public again for all functions? 
	// Because we need to access the CartItem structure from outside the class, but we want to keep the cart size private to ensure encapsulation.
	// This is done to ensure that the cart size cannot be modified directly from outside the class.
	public:
		// CartItem structure to hold product and quantity in the cart
		// This structure is used to represent an item in the shopping cart, which consists of a product and its quantity.
		// It is defined as public so that it can be accessed from outside the ShoppingCart
	    struct CartItem 
		{
			// Product being bought
	        Product product;
			
			// Quantity of the product being bought
	        int quantity; 
	    };
	
	private:
		// Array to hold cart items and current size of the cart
		// This array holds the items in the shopping cart, and cartSize keeps track of the number of items in the cart.
	    // This is the maximum size of the cart, which is defined as a constant at the beginning of the code.
	    CartItem cart[MAX_CART_SIZE];
	    int cartSize;
	
	public:
	    ShoppingCart() : cartSize(0) {} // Constructor initializes cartSize to 0, indicating an empty cart.
	
	    // Adds product to cart
	    void addProduct(const Product& product, int quantity) 
		{
	        if (cartSize < MAX_CART_SIZE)  // Check if there is space in the cart
			{
	            // Checks if the product is already in the cart
	            for (int i = 0; i < cartSize; ++i) 
				{
					// If the product is already in the cart, increase its quantity
					// This line checks if the current product in the cart matches the product being added.
	                if (cart[i].product.getId() == product.getId()) 
					{
						// Increase quantity if already in cart
	                    cart[i].quantity += quantity; 
	    				
						// This line displays a message indicating that the quantity of the product has been increased in the cart.
		                cout << "Increased quantity of " << product.getName() << " in cart." << endl;
						
						// Exits the function making it sure that it does not execute the rest of the code after this point.
	                    return; 
	                }
	            }
	            
	            // If not in cart, add new item
	            cart[cartSize++] = {product, quantity};
	            cout << "Product added to cart." << endl; // This line displays a message indicating that the product has been added to the cart.
	        } 
			
			// If the cart is full, it displays a message indicating that the cart cannot hold more products.
			// This is to ensure that the cart does not exceed its maximum size.
			else 
			{
	            cout << "Cart is full! Cannot add more products." << endl;
	        }
	    }
	
	    // Remove product from cart by ID
	    void removeProduct(int id) 
		{
			// Searching of product in the cart by ID is being done here.
	        for (int i = 0; i < cartSize; ++i) 
			{
	            if (cart[i].product.getId() == id) // ID matching
				{
	                // This loop shifts the products left to fill the gap created by the removed product.
					for (int j = i; j < cartSize - 1; ++j) 
					{
	                    cart[j] = cart[j + 1]; // Shifts products left
	                }
			
					// Decrease the cart size by 1 to reflect the removal of the product.
	                cartSize--;
			
					// This line displays a message indicating that the product has been removed from the cart successfully.
	                cout << "Product removed from cart." << endl;
	        
			        return; // Exits the function making it sure that it does not execute the rest of the code after this point.
	            }
	        }
			
			// If the product with the given ID is not found in the cart, it displays a message indicating that the product was not found.
	        // This is to ensure that the user is informed when they try to remove a product that does not exist in the cart.
	        cout << "Product not found in cart." << endl;
	    }
	
	    // Display cart contents
	    void displayCart() const 
		{
	        cout << "\nShopping Cart Contents:\n";
			
			// This loop iterates through all the items in the cart and displays their details.
	        for (int i = 0; i < cartSize; ++i) 
			{
				// This line displays the product details and the quantity being bought.
	            cout << "Product: ";
			
				// It uses the display function of the Product class to print the product details.
	            cart[i].product.display();
	        
			    cout << "Quantity: " << cart[i].quantity << endl; // Display quantity being bought
	        }
	    }
	
	    // Calculate total price
	    double calculateTotal() const 
		{
	        double total = 0; // Initialize total to 0
			
			// This loop iterates through all the items in the cart and calculates the total price
	        for (int i = 0; i < cartSize; ++i) 
			{
				// This line calculates the total price by multiplying the product price by the quantity being bought.
	            // It uses the getPrice function of the Product class to get the price of the product
	            total += cart[i].product.getPrice() * cart[i].quantity; // Total price based on quantity
	        }
			
			// This line displays the total price of all items in the cart.
	        return total;
	    }
	
	    // Clear cart
	    void clearCart() 
		{
	        // This function clears the cart by resetting the cart size to 0.
	        // It effectively removes all items from the cart.
			cartSize = 0;
	    }
	
	    // Get products in cart
	    CartItem* getProducts() 
		{
	        // This function returns a pointer to the array of CartItem objects in the cart.
	        // It allows access to the products in the cart for further processing.
			return cart; 
	    }
		
		// Get cart size
	    int getCartSize() const 
		{
	        // This function returns the current size of the cart, which indicates how many items are in the cart.
	        // It is defined as const to ensure that it does not modify the cart.
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
    // Load products from file into inventory
	Inventory inventory;
	// This line creates an Inventory object and loads products from a file named "products.txt".
    inventory.loadFromFile("products.txt");

	// Admin Object Creation
	// We have passed the admin Username & Password by default to reduce number of lines of code.
    Admin admin("admin", "admin123"); // We have passed the admin Username & Password by default to reduce number of lines of code.

	// Customer Object Creation
	// We have passed the customer Username & Password by default to reduce number of lines of code.
	// Passed inventory reference as a parameter to the Customer constructor because inventory is needed to update the product quantities during checkout.
    Customer customer("customer", "customer123", inventory); 

	// Main menu for the shopping cart management system
	// This is the main menu of the program which allows the user to choose between Admin and Customer portals or exit the program.
    int choice;
    do 
	{
        system("cls"); //Cleans up the console for a better neat looking otherwise it seems messy.
		cout << Color::BOLD << Color:: ORANGE << "========= Online Shopping Cart Management System =========\n"<< Color::RESET <<endl;
        
        cout << Color::GREEN;
		cout << "1. Login To ADMIN\n";
        cout << "2. Login To Customer\n";
        cout << "3. Exit\n";
        cout << Color::RESET;
        
        cout << Color::BOLD << Color::BLINK << Color::BLUE;
		cout << "\nEnter your choice (1-3): ";
        cin >> choice;
		cout << Color::RESET;

        switch (choice) 
		{
            case 1: {// Enters to Admin Portal for admin controls.
                int optiona;
                do 
				{
                    system("cls"); //Cleans up the console for a better neat looking otherwise it seems messy.
					cout << Color::BOLD << Color:: ORANGE << "========= Online Shopping Cart Management System =========\n"<< Color::RESET <<endl;
					cout << Color::BOLD << Color:: RED << "====================== Admin Portal ======================\n"<< Color::RESET <<endl;
                    
					cout << Color::GREEN;
					cout << "1. View Products\n";
                    cout << "2. Add Product to Inventory\n";
                    cout << "3. Update Product in Inventory\n";
                    cout << "4. Delete Product from Inventory\n";
                    cout << "5. Exit\n";
					cout << Color::RESET;

					cout << Color::BOLD << Color::BLUE << Color::BLINK;
                    cout << "\nEnter your choice (1-5): ";
					cin >> optiona;
					cout << Color::RESET;

                    switch (optiona) 
					{
                        case 1: {
                            system("cls"); //Cleans up the console for a better neat looking otherwise it seems messy.
							cout << Color::BOLD << Color:: ORANGE << "========= Online Shopping Cart Management System =========\n"<< Color::RESET <<endl;
							cout << Color::BOLD << Color:: RED << "====================== Admin Portal ======================\n"<< Color::RESET <<endl;
							cout << Color::BOLD << Color:: CYAN << "==================== Available Products ===================\n"<< Color::RESET <<endl;
				
			            	// Displays all products in the inventory
				
							inventory.displayProducts();
                
				            break;
						}
                
				        case 2: {
                            system("cls"); //Cleans up the console for a better neat looking otherwise it seems messy.
                            cout << Color::BOLD << Color:: ORANGE << "========= Online Shopping Cart Management System =========\n" << Color::RESET <<endl;
							cout << Color::BOLD << Color:: RED << "====================== Admin Portal ======================\n" << Color::RESET <<endl;
							cout << Color::BOLD << Color:: CYAN <<"================== Addition of Products ==================\n" << Color::RESET <<endl;
				
							int id, quantity;
                            string name;
                            double price;
                
							cout << Color::GREEN << Color::BOLD << "Enter Product ID: " << Color::RESET << Color::GREEN;
                            cin >> id;
                            cout << Color::RESET << Color::GREEN << Color::BOLD << "Enter Product Name: "<< Color::RESET << Color::GREEN;
                            cin >> name;
                            cout << Color::RESET << Color::GREEN << Color::BOLD << "Enter Product Price: " << Color::RESET << Color::GREEN;
                            cin >> price;
                            cout << Color::RESET << Color::GREEN << Color::BOLD << "Enter Product Quantity: " << Color::RESET << Color::GREEN;
                            cin >> quantity;
							cout << Color::RESET;
                
				            admin.addProduct(inventory, id, name, price, quantity);
                
				            cout << Color::BOLD << Color::GREEN << endl;
							inventory.saveToFile("products.txt");
							cout << endl << Color::RESET;

							cout << Color::BOLD << Color::BLUE;
							system("pause");
							cout << Color::RESET;
                
				            break;
                        }
                
				        case 3: {
                        	system("cls"); //Cleans up the console for a better neat looking otherwise it seems messy.                        	
                            cout << Color::BOLD << Color:: ORANGE << "========= Online Shopping Cart Management System =========\n" << Color::RESET << endl;
							cout << Color::BOLD << Color:: RED << "====================== Admin Portal ======================\n" << Color::RESET << endl;
							cout << Color::BOLD << Color:: CYAN << "================== Updation of Products ==================\n" << Color::RESET << endl;
				
							int id, quantity;
                            string name;
                            double price;
                
				            cout << Color::GREEN << Color::BOLD << "Enter Product ID: " << Color::RESET << Color::GREEN;
                            cin >> id;
                            cout << Color::RESET << Color::GREEN << Color::BOLD << "Enter New Product Name: "<< Color::RESET << Color::GREEN;
                            cin >> name;
                            cout << Color::RESET << Color::GREEN << Color::BOLD << "Enter New Product Price: " << Color::RESET << Color::GREEN;
                            cin >> price;
                            cout << Color::RESET << Color::GREEN << Color::BOLD << "Enter New Product Quantity: " << Color::RESET << Color::GREEN;
                            cin >> quantity;
							cout << Color::RESET << endl;
                
				            cout << Color::BOLD << Color::GREEN << endl;
							admin.updateProduct(inventory, id, name, price, quantity);
				            
							inventory.saveToFile("products.txt");
							cout << endl << Color::RESET;

							cout << Color::BOLD << Color::BLUE;
							system("pause");
							cout << Color::RESET;
                
				            break;
                        }
                
				        case 4: {
                        	system("cls"); //Cleans up the console for a better neat looking otherwise it seems messy.                        	
                            cout << Color::BOLD << Color:: ORANGE << "========= Online Shopping Cart Management System =========\n"<< Color::RESET << endl;
							cout << Color::BOLD << Color:: RED << "====================== Admin Portal ======================\n"<< Color::RESET << endl;
							cout << Color::BOLD << Color:: CYAN << "================== Deletion of Products ==================\n" << Color::RESET << endl;
				
							int id;
                
				            cout << Color::YELLOW << "Enter Product ID to delete: ";
                            cin >> id;
							cout << Color::RESET;
                
				            admin.deleteProduct(inventory, id);
                
				            inventory.saveToFile("products.txt");
                
				            break;
                        }
                        
                        case 5: {
                        	system("cls"); //Cleans up the console for a better neat looking otherwise it seems messy.
                        	cout << Color::BOLD << Color:: ORANGE << "========= Online Shopping Cart Management System =========\n"<< Color::RESET <<endl;
							cout << Color::BOLD << Color:: RED << "====================== Admin Portal ======================\n"<< Color::RESET <<endl;
                
				            cout << Color::BLINK << "________________ Exiting Admin Portal... _________________" << endl << Color::RESET;
                
				            Sleep(3000); //Creates up a time delay of 3 Seconds.
                
				            break;
						}
							
                        default: {
                        	system("cls"); //Cleans up the console for a better neat looking otherwise it seems messy.
                        	cout << Color::BOLD << Color:: ORANGE << "========= Online Shopping Cart Management System =========\n"<< Color::RESET <<endl;
							cout << Color::BOLD << Color:: RED << "====================== Admin Portal ======================\n"<< Color::RESET <<endl;
                
				            cout << Color::BLINK << "_______________ Invalid option, Try again. _______________" << endl << Color::RESET;
                
				            Sleep(3000); //Creates up a time delay of 3 Seconds.
                
				            break;
						}
                    }
                } while (optiona != 5);
                
				break;
			}
                
            case 2: {// Enters to Customer Portal for Customer controls of Ordering and more...
                system("cls"); //Cleans up the console for a better neat looking otherwise it seems messy.
                
				int optionc;
                
                do {
                    
					system("cls"); //Cleans up the console for a better neat looking otherwise it seems messy.            	
					cout << Color::BOLD << Color::ORANGE << "========= Online Shopping Cart Management System =========\n"<< Color::RESET <<endl;
					cout << Color::BOLD << Color::BLUE << "==================== Customer Portal =====================\n"<< Color::RESET <<endl;
                    cout << Color::GREEN;
					cout << "1. View Products\n";
                    cout << "2. Add Product to Cart\n";
                    cout << "3. Remove Product from Cart\n";
                    cout << "4. View Cart\n";
                    cout << "5. Checkout Now\n";
                    cout << "6. Check Order History\n";
                    cout << "7. Exit\n";
					cout << Color::RESET;
					cout << Color::BLINK << Color::BOLD << Color::BLUE;
                    cout << "\nEnter your choice (1-7): ";
                    cin >> optionc;
					cout << Color::RESET;

                    switch (optionc) 
					{
                        case 1: {
                        	system("cls"); //Cleans up the console for a better neat looking otherwise it seems messy.                        	
                    		cout << "========= Online Shopping Cart Management System =========\n==================== Customer Portal =====================\n================== Display Of Products ===================\n\n";
					        
							inventory.displayProducts();
                            
							break;
						}
                      
					    case 2: {
                        	system("cls"); //Cleans up the console for a better neat looking otherwise it seems messy.                        	
                            cout << "========= Online Shopping Cart Management System =========\n==================== Customer Portal =====================\n====================== Add To Cart =======================\n\n";
							
							int id, quantity;
                            cout << "Enter Product ID to add to cart: ";
                            cin >> id;
                            cout << "Enter Quantity: ";
                            cin >> quantity;
                            
							Product* product = inventory.findProduct(id);
                            
							if(product) 
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
                            cout << "========= Online Shopping Cart Management System =========\n==================== Customer Portal =====================\n==================== Remove From Cart ====================\n\n";
							
							int id;
                            cout << "Enter Product ID to remove from cart: ";
                            cin >> id;
                            
							customer.removeFromCart(id);
                            
                            Sleep(5000); //Creates up a time delay of 5 Seconds.
                            
							break;
                        }
                      
					    case 4: {
                        	system("cls"); //Cleans up the console for a better neat looking otherwise it seems messy.                        
                            cout << "========= Online Shopping Cart Management System =========\n==================== Customer Portal =====================\n======================= View Cart ========================\n\n";
							         
							customer.viewCart();
							cout << endl;
							
							system("pause"); //This helps to view the cart until unless user presses any key from keyboard.
                            
							break;
						}
                      
					    case 5: {
                            system("cls"); //Cleans up the console for a better neat looking otherwise it seems messy.
							cout << "========= Online Shopping Cart Management System =========\n==================== Customer Portal =====================\n======================== Checkout ========================\n\n";
							         
							customer.checkout();
							
							Sleep(5000); //Creates up a time delay of 5 Seconds.
                            
							break;
						}
                      
					    case 6: {
                            system("cls"); //Cleans up the console for a better neat looking otherwise it seems messy.
							cout << "========= Online Shopping Cart Management System =========\n==================== Customer Portal =====================\n===================== Order History ======================\n\n";
							         
							customer.viewOrderHistory();
                            cout << endl;
                            
                            system("pause");
                            														                            
							break;
						}
                      
					    case 7: {
                            system("cls"); //Cleans up the console for a better neat looking otherwise it seems messy.
							cout << "========= Online Shopping Cart Management System =========\n==================== Customer Portal =====================\n\n";
							cout << "_______________ Exiting Customer Portal... _______________" << endl;
							
							Sleep(3000); //Creates up a time delay of 3 Seconds.
                            
							break;
						}
                      
					    default: {
                        	system("cls"); //Cleans up the console for a better neat looking otherwise it seems messy.
                        	cout << "========= Online Shopping Cart Management System =========\n==================== Customer Portal =====================\n\n";
                            cout << "_______________ Invalid option, Try again. _______________" << endl;
                            
							Sleep(3000); //Creates up a time delay of 3 Seconds.
                            
							break;
						}
                    }
                }while(optionc != 7);
                
				break;
			}
            
			case 3: {// At this point Program quits.
                system("cls"); //Cleans up the console for a better neat looking otherwise it seems messy.
                cout << "========= Online Shopping Cart Management System =========\n\n________________ Quitting The Program... _________________\n\n";
                         
				Sleep(3000); //Creates up a time delay of 3 Seconds.
				
                break;
			}
                
            default: {
            	system("cls"); //Cleans up the console for a better neat looking otherwise it seems messy.            	
                cout << "========= Online Shopping Cart Management System =========\n\n_______________ Invalid option, Try again. _______________\n\n";
                
				Sleep(3000); //Creates up a time delay of 3 Seconds.
				
				break;
			}
        }
    } while (choice != 3);
    
    return 0;
}
