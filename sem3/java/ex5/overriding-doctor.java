package ex5;

public class Doctor
{
 protected int id;
 protected String name;

 public Doctor(int id, String name)
 {
     this.id = id;
     this.name = name;
 }

 /**
  * Overridden to retrieve the doctor's ID as the hash code.
  * The contract between equals() and hashCode() is maintained:
  * if two doctors are equal (same id), they will have the same hash code.
  * @return The doctor's ID.
  */
 @Override
 public int hashCode()
 {
     return id;
 }

 /**
  * Overridden to compare two Doctor (or Surgeon) objects.
  * Two doctors are considered equal if they have the same ID.
  * @param obj The object to compare against.
  * @return true if the objects have the same ID, false otherwise.
  */
 @Override
 public boolean equals(Object obj)
 {
     // 1. Check if the object is being compared to itself
     if (this == obj)
     {
         return true;
     }
     // 2. Check if the other object is null or not an instance of Doctor
     if (obj == null || !(obj instanceof Doctor))
     {
         return false;
     }
     // 3. Cast the object to a Doctor type and compare the IDs
     Doctor other = (Doctor) obj;
     return this.id == other.id;
 }

 /**
  * A standard toString() for the Doctor class.
  */
 @Override
 public String toString()
 {
     return "ID: " + this.id + ", Name: " + this.name;
 }
}


package ex5;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        try {
            // --- Get Doctor Details from User ---
            System.out.println("--- Enter Details for a Doctor ---");
            System.out.print("Enter Doctor ID: ");
            int docId = scanner.nextInt();
            scanner.nextLine(); // Consume the leftover newline character

            System.out.print("Enter Doctor Name: ");
            String docName = scanner.nextLine();

            // Create the Doctor object with user input
            Doctor doctor = new Doctor(docId, docName);

            // --- Get Surgeon Details from User ---
            System.out.println("\n--- Enter Details for a Surgeon ---");
            System.out.print("Enter Surgeon ID: ");
            int surgId = scanner.nextInt();
            scanner.nextLine(); // Consume the leftover newline character

            System.out.print("Enter Surgeon Name: ");
            String surgName = scanner.nextLine();

            System.out.print("Enter Surgeon's Department: ");
            String surgDept = scanner.nextLine();

            // Create the Surgeon object with user input
            Surgeon surgeon = new Surgeon(surgId, surgName, surgDept);

            // --- Demonstrate the Overridden Methods ---
            System.out.println("\n--- Demonstrating Overridden Methods ---");

            // 1. Test toString()
            System.out.println("\n1. toString() Output:");
            System.out.println("   Doctor Details: " + doctor);  // Calls doctor.toString()
            System.out.println("   Surgeon Details: " + surgeon); // Calls surgeon.toString()

            // 2. Test hashCode()
            System.out.println("\n2. hashCode() Output:");
            System.out.println("   Doctor Hash Code (should be ID): " + doctor.hashCode());
            System.out.println("   Surgeon Hash Code (should be ID): " + surgeon.hashCode());

            // 3. Test equals()
            System.out.println("\n3. equals() Output:");
            boolean areEqual = doctor.equals(surgeon);
            System.out.println("   Does the Doctor equal the Surgeon? " + areEqual);
            if (docId == surgId) {
                System.out.println("   (Result is true because they have the same ID)");
            } else {
                System.out.println("   (Result is false because they have different IDs)");
            }

        } catch (InputMismatchException e) {
            System.err.println("Invalid input. Please enter a number for the ID.");
        } finally {
            scanner.close(); // Always close the scanner
        }
    }
}


package ex5;

public class Surgeon extends Doctor
{
 private String department;

 public Surgeon(int id, String name, String department)
 {
     // Call the constructor of the parent class (Doctor)
     super(id, name);
     this.department = department;
 }

 /**
  * Overridden to print the doctor's name and their department.
  * It uses the 'name' field inherited from the Doctor class.
  * @return A string containing the name and department.
  */
 @Override
 public String toString()
 {
     return "Name: " + this.name + ", Department: " + this.department;
 }
}
