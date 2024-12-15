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
