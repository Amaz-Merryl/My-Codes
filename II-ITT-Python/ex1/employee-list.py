class Employee:
   def __init__(self, name, age, exp, bp):
      self.name = name
      self.age = age
      self.exp = exp
      self.bp = bp
   def calculate_salary(self):
      hra = 0.20 * self.bp
      da = 0.10 * self.bp
      total_salary = self.bp + hra + da
      return hra, da, total_salary
   def display(self):
      hra, da, total_salary = self.calculate_salary()
      print(self.name,"\t\t",self.age,"\t",self.exp,"\t",self.bp,"\t\t",f"{hra:.4f}\t\t{total_salary:.4f}")

employees = []
while True:
   print("\n\t\tM E N U")
   print("\t1. Add Employee")
   print("\t2. Remove Employee")
   print("\t3. Display Employees")
   print("\t4.Search Employee")
   print("\t5.Exit\n")
   ch = int(input("Choice : "))
   if ch == 1:
      name = input("Name : ")
      age = int(input("Age : "))
      exp = int(input("Experience : "))
      bp = float(input("Basic Pay : "))
      while bp<0:
         print("\tInvalid Amount..!")
         bp = float(input("Basic Pay :"))
      des = input("Designation : ")
      while(des == "Manager" and bp<20000):
         bp = float(input("Invalid salary for Manager, enter new Salary (>20000) : "))
      while(des =="employee" and bp<10000):
         bp = float(input("Invalid Salary for employee enter new Salary(>10000) :"))
      emp = Employee(name, age, exp, bp)

      employees.append(emp)
      print("Added")
   elif ch == 2:
      name = input("Employee Name : ")
      for emp in employees:
        if emp.name == name:
           employees.remove(emp)
           print("Removed!")
           break
      print("Not Found..!")
   elif ch == 3:
      if employees:
         print("Name\t\tAge\tExp.\tBasicPay\t\thra\t\t\ttotalSlary\t")
         print("------------------------------------------------------------------------------------")
         for emp in employees:
            emp.display()
         print("\n\tTotal Employees = ",len(employees))
      else:
         print("List is Empty..!")
   elif ch ==4:
      name = input("Name : ")
      found = False
      for emp in employees:
         if name == emp.name:
            print("Name\t\tAge\tExp.\tBasicPay\t\thra\t\t\ttotalSlary\t")
            print("------------------------------------------------------------------------------------")
            emp.display()
            found = True
            break
      if not found:
         print("Employee Not Found ")
   elif ch ==5 :
      print("Exiting program..!")
      print(".\n.\n.\n.\n.\nExited\n")
      break
   else:
      print("Invalid Choice..!\n")
