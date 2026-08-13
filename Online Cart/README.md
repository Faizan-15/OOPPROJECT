# Online Shopping Cart Management System

A console-based shopping cart and inventory management application developed in **C++**. The project began in my **second semester** for the **Object-Oriented Programming (OOP)** course and was later during my **third semester** while studying **Data Structures and Algorithms (DSA)** its concepts were integrated as well.

The project combines object-oriented design, fixed-size arrays, searching, deletion by shifting, pointers, text-file persistence, menu-driven interaction, and a colored Windows console interface.

## Project Background

This application was initially created to practically apply the concepts studied in Object-Oriented Programming. After completing the original version, I continued improving the project during the following semester and used it to practise introductory Data Structures and Algorithms concepts.

The project represents a continuing learning journey rather than a one-time submission. Features, validation, organization, and program behavior may continue to improve over time.

## Main Features

### Administrator Portal

- View all products available in the inventory
- Add a new product
- Update an existing product
- Delete a product by its ID
- Save inventory changes to `products.txt`

### Customer Portal

- View available products
- Add products and quantities to the shopping cart
- Increase the quantity when the same product is added again
- Remove products from the cart
- View cart contents
- Calculate the total purchase amount
- Complete checkout
- Reduce inventory quantities after checkout
- View order history during the current program session

### General Features

- For the program passwords and ids are hard-coded
- Menu-driven console interface
- Colored and styled terminal output using ANSI escape sequences
- Product data loaded from a text file at startup
- Updated inventory saved back to the text file
- Separate administrator and customer portals
- Product lookup using product IDs
- Basic stock-availability checking
- Fixed limits for products, cart items, and order history

## OOP Concepts Applied

The project demonstrates the following Object-Oriented Programming concepts:

- **Classes and objects** through `Product`, `Inventory`, `ShoppingCart`, `Order`, `User`, `Admin`, `Customer`, and `Color`
- **Encapsulation** through private and protected data members
- **Constructors** for initializing products, users, carts, orders, and inventory
- **Inheritance** through `Admin` and `Customer`, which inherit from `User`
- **Polymorphism** through the virtual `displayInfo()` function and overriding in derived classes
- **Abstraction** by separating product, inventory, cart, order, user, and display responsibilities
- **Composition** where classes contain objects of other classes
- **References and pointers** for inventory sharing and product lookup
- **Constant member functions** for operations that do not modify object state

## DSA Concepts Practised

The upgraded project also provides practice with introductory Data Structures and Algorithms concepts:

- Fixed-size arrays for inventory, cart items, and order history
- Linear search by product ID
- Traversal of product, cart, and order arrays
- Deletion by shifting array elements to the left
- Index and counter management
- Pointer-based access to a located product
- Parsing comma-separated text records
- Sequential file reading and writing
- Basic time-complexity awareness for search, update, and deletion operations

## Classes

### `Color`

Stores ANSI escape sequences for foreground colors, background colors, and text styles. It also enables virtual-terminal color processing on Windows.

### `Product`

Represents one product with an ID, name, price, and available quantity. It provides getters, display functionality, and text-file serialization and parsing.

### `Inventory`

Maintains the product collection and supports adding, updating, deleting, displaying, finding, loading, and saving products.

### `ShoppingCart`

Stores selected products and their requested quantities. It supports adding items, removing items, displaying the cart, calculating the total, and clearing the cart.

### `Order`

Stores the products, quantities, and total amount of a completed order for the current program session.

### `User`

Acts as the base class for application users and contains the shared username and password members.

### `Admin`

Inherits from `User` and provides administrator-facing inventory operations.

### `Customer`

Inherits from `User` and owns a shopping cart and in-memory order history. It also uses a reference to the shared inventory so product quantities can be updated during checkout.

## Project Structure

```text
Online Cart/
├── ONLINECARTSYSTEM.cpp
├── products.txt
└── README.md
```

- `ONLINECARTSYSTEM.cpp` contains the complete C++ implementation.
- `products.txt` stores product records in comma-separated form.
- `README.md` documents the project.

## Product File Format

Each line in `products.txt` follows this format:

```text
product_id,product_name,price,quantity
```

Example:

```text
1,Jug,6.92,17
2,Fork,2,40
3,Plate,4.14,37
```

The provided data file currently contains 17 sample products.

## Program Workflow

```text
Start program
    |
    v
Load products from products.txt
    |
    v
Display main menu
    |
    +--> Administrator Portal
    |       +--> View products
    |       +--> Add product
    |       +--> Update product
    |       +--> Delete product
    |       +--> Save changes
    |
    +--> Customer Portal
    |       +--> View products
    |       +--> Add to cart
    |       +--> Remove from cart
    |       +--> View cart
    |       +--> Checkout
    |       +--> View order history
    |
    +--> Exit
```

## Requirements

- Windows operating system
- A C++ compiler with C++11 or later support
- MinGW-w64, GCC, or another compatible compiler
- A terminal that supports ANSI escape sequences

The current implementation includes `windows.h`, `Sleep()`, `system("cls")`, and `system("pause")`, so it is primarily designed for Windows.

## Compilation and Execution

Open a terminal in the `Online Cart` folder.

### Compile with MinGW or GCC

```bash
g++ -std=c++11 ONLINECARTSYSTEM.cpp -o OnlineCart
```

### Run on Windows

```bash
OnlineCart.exe
```

Keep `products.txt` in the program's working directory. Otherwise, the application will start with an empty inventory.

## Current Limits

The program currently uses these fixed limits:

```text
Maximum products: 50
Maximum different cart entries: 10
Maximum orders in session history: 10
```

The current version also has these limitations:

- The administrator and customer credentials are initialized in the source code, but the menus do not yet request or verify login credentials.
- Order history exists only while the program is running and is not saved to a file.
- Fixed-size arrays limit the number of records.
- User input validation can be improved for invalid text, negative values, duplicate IDs, and quantities exceeding available stock.
- Product names are currently read as single words through `cin`.
- The program is Windows-specific because of the console-management functions and header file used.

## Suggested Future Improvements

- Implement actual administrator and customer login validation
- Replace fixed-size arrays with `std::vector`
- Use safer and more complete input validation
- Prevent adding quantities greater than available stock
- Prevent duplicate product IDs
- Save and reload order history
- Add customer account management
- Split classes into separate header and source files
- Replace manual CSV parsing with a more robust parser
- Improve exception handling for malformed product records
- Add sorting and binary search for product records
- Add category-based search and filtering
- Make the application cross-platform
- Add automated tests
- Develop a graphical or web-based interface

## Development Journey

This project was originally developed during my **second semester** for the **Object-Oriented Programming course in C++**. The first version focused on classes, objects, constructors, encapsulation, inheritance, polymorphism, composition, and file handling.

I continued upgrading the same project during my **third semester** while studying **Data Structures and Algorithms**. The project then became a practical environment for strengthening array traversal, linear searching, pointer use, element shifting, record parsing, and data-management logic.

The implementation has been primarily hand-coded to improve my understanding of C++ syntax, program logic, class design, debugging, and problem-solving. AI assistance is used only occasionally when a particularly difficult technical error requires explanation or troubleshooting. Any suggested solution is studied, tested, and adapted according to the actual requirements of the project.

## Academic Purpose

This project was created for academic learning, programming practice, and portfolio development. It is not intended to represent a production-ready e-commerce or authentication system.

## Author

**Muhammad Faizan Ashraf**

## Repository

[Faizan-15/OOPPROJECT](https://github.com/Faizan-15/OOPPROJECT)
