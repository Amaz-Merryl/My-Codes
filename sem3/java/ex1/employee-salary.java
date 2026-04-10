//import java.io.*;
class EmployeeSalary
{
        String name = "Amaz",gender="Male",department="CSE",city="Tenkasi";
        double basicPay = 200000;
        int age=19,id=20685;

        void totalSalary()
        {
                double hra = 0.1*basicPay;
                double it=0;
                double da = 0.30*basicPay;
                double grossSalary = basicPay + hra + da;
                if (grossSalary>100000)
                {
                        it = 0.1 * grossSalary;
                }

                double netSalary = grossSalary - it;
                displayDetails();
                System.out.println("HRA : "+hra);
                System.out.println("da : "+da);
                System.out.println("Gross Salary : "+grossSalary);
                System.out.println("Income tax : "+it);
                System.out.println("Total Salary : "+netSalary);

        }
        void displayDetails()
        {
                System.out.println("Name : "+name);
                System.out.println("Id : "+id);
                System.out.println("Department : "+department);
                System.out.println("City : "+city);
                System.out.println("Gender : "+gender)  ;
                System.out.println("Age : "+age);
                System.out.println("Basic Pay : "+basicPay);
        }
}
public class Employee
{
        public static void main(String args[])
        {
                EmployeeSalary e1=new EmployeeSalary();
                //System.out.println(e1.totalSalary());
                e1.totalSalary();
        }
}
