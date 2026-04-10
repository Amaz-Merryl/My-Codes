class Math:
   def power(self,a,b):
      res = 1
      for i in range(b):
         res *= a
      return res
   def max(self, a[]):
      max = a[0]
      for i in a:
         if max<i :
            max = i
      return max

   def min(self, a[]):
      min = a[0]
      for i in a:
         if max>i :
            max = i
      return max

   def isEmpty(self,a[]):
      res = 0
      for i in a:
         res += 1
      return res

def main():
   m =Math()
   ch = -1;
   while ch != 0:
      ch = int(input("Enter the Choice : "))
      print("Menu")
      print("1. Find Exponential")
      print("2. Find distance between two points")
      if ch == 1:
         a = int(input("Enter the base Value : "))
         b = int(input("Enter the exponential Value : "))
         print(m.Math(a,b))
      elif ch == 0:
         print("Exited..!")


if __name__ == "__main__":
   main()
