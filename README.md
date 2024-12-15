# **Hotel Booking System**

## **Project Description**
The **Hotel Booking System** is a console-based application developed in **C++** using **Object-Oriented Programming (OOP)** principles. This system simulates the core functionalities of a hotel management system, allowing users to **book rooms**, **manage room details**, and handle **payments**. The project supports both **admin** and **user roles**, offering a streamlined experience for managing bookings and room availability.

This project demonstrates modular design and scalability, making it suitable for learning, enhancements, and real-world applications.

---

## **Features**

### **Admin Features**
- **Add Rooms**: Admin can add new rooms with details like name and price.
- **Delete Rooms**: Remove rooms from the system if no longer needed.
- **Modify Room Details**:
  - Change room prices.
  - Update room availability status.
- **View All Rooms**: List all rooms with their statuses (`Available`, `Pending`, or `Booked`).
- **Search Rooms**:
  - By price range.
  - By availability status (`Available`, `Booked`).
  - By room name or partial match.

### **User Features**
- **Register and Login**:
  - Register as a new user with a username and password.
  - Login using existing credentials to access booking services.
- **Book Rooms**:
  - Users can book available rooms, which will initially have a `Pending` status until payment is made.
- **Payment**:
  - Complete payments for booked rooms to confirm bookings (`Pending` status transitions to `Booked`).
- **View Available Rooms**:
  - Check room details, including price and availability status.

---

## **Technical Details**

### **Core Concepts Used**
- **Object-Oriented Programming (OOP)**:
  - Encapsulation: Private data members with controlled access through public methods.
  - Inheritance: A common `Service` interface implemented by modules like `BookingService`, `AuthenticationService`, etc.
  - Polymorphism: Unified execution of service methods using virtual functions.
- **Room Management with `RoomStatus` Enum**:
  - A `Room` has a `status` (Available, Pending, or Booked) to ensure logical flow during booking and payment.
- **Dynamic Room Management**:
  - Admin can add, delete, or modify rooms dynamically during runtime.
- **Search and Filter**:
  - Advanced search features to filter rooms based on criteria like price, availability, or name.
- **Role-Based Access**:
  - Separate menus for admin and regular users, ensuring role-specific functionality.

---

## **How to Run**

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/hotel-booking-system.git
   cd hotel-booking-system


Usage Guide
Admin Login
Default credentials:
Username: admin
Password: password123
Once logged in as admin, you can:
Add, delete, or modify room details.
View and search for rooms based on criteria.
User Login
Users must register first, then log in using their credentials.
After login, users can:
Book available rooms.
View their pending payments and make payments to confirm bookings.
Project Structure
less
Copy code
hotel-booking-system/
├── main.cpp                // Entry point of the application
├── Room.h                  // Defines the Room class and RoomStatus enum
├── Service.h               // Base class for all services
├── BookingService.h        // Handles room management
├── AuthenticationService.h // Manages user registration and login
├── PaymentService.h        // Simulates payment processing
├── NotificationService.h   // Sends notifications for actions
├── UserInterface.h         // Combines all services into a unified interface
Sample Output
Admin Menu
markdown
Copy code
Admin Menu
1. Add Room
2. Show Available Rooms
3. Delete Room
4. Modify Room Price
5. Modify Room Availability
6. Search Rooms
7. Exit
Enter your choice: 1
Enter the room name: Room 104
Enter the room price: 250
Room Room 104 added successfully with a price of $250.
User Booking and Payment
vbnet
Copy code
Welcome to the Hotel Booking System
Please choose an option:
1. Login
2. Register
Enter your choice: 1
Username: user1
Password: pass123
Login Successful!

Hotel Booking System
1. Show Available Rooms
2. Book a Room
3. Make Payment
4. Exit
Enter your choice: 2
Enter room name to book: Room 101
Room Room 101 is now pending payment.

Hotel Booking System
1. Show Available Rooms
2. Book a Room
3. Make Payment
4. Exit
Enter your choice: 3
Total amount due: $150.00
Do you want to proceed with payment? (yes/no): yes
Payment of $150.00 processed successfully.
Room Room 101 has been successfully booked.
