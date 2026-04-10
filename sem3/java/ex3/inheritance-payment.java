import java.util.*;
class Payment
{
        static int id;
        String payee_name;
        double billamount;
        double gst;
        int date;
        Payment()
        {
                id = 0;
                payee_name = "";
                billamount = 0.0;
                date = 0;
        }
        Payment(int ID,String payee_name,double billamount,int date)
        {
                id = ID;
                this.payee_name = payee_name;
                this.billamount = billamount;
                this.date = date;
                this.gst = 0.12;
        }
   double calculateBill()
        {
                return billamount;
        }
   public void displayBill(double total)
   {
      System.out.println("===========================================================");
      System.out.println("||\tPURCHASE ID\t\t:\t " + this.id );
      System.out.println("||\tPAYEE's NAME\t\t:\t" + this.payee_name );
      System.out.println("||\tBILL AMOUNT\t\t:\t" + total );
      System.out.println("||\tDATE OF PURCHASE\t:\t" + this.date );
      System.out.println("||\tYOUR BILL AMOUNT\t:\t" + this.billamount );
      System.out.println("===========================================================");
   }
}
class Cash extends Payment
{
        public Cash(int id,String payee_name,double billamount,int date)
        {
                super(id,payee_name,billamount,date);
        }
        double calculateBill()
        {
                return (billamount + billamount * gst );
        }
}
class Card extends Payment
{
        long card_no;
        int pin;
        double t_charges;
        public Card()
        {
                card_no = 0;
                pin = 0;
                gst = 0.12;
        }
        public Card(int id,String payee_name,double billamount,int date,long card_no)
        {
                super(id ,payee_name ,billamount ,date );
                this.card_no = card_no;
                this.pin = pin;
        }
}

class DebitCard extends Card
{
        public DebitCard(int id,String payee_name,double billamount,int date, long card_no)
        {
                super( id, payee_name, billamount, date, card_no);
                t_charges = 0.1;
        }
        double calculateBill()
        {
                return ( billamount + ( billamount * gst ) + ( billamount * t_charges )) ;
        }
}

class CreditCard extends Card
{
        int discount;
        public CreditCard(int id,String payee_name,double billamount,int date, long card_no)
        {
                super(id,payee_name,billamount,date,card_no);
                t_charges = 0.05;
                discount = 50;
        }
        double calculateBill()
        {
                return ( billamount + ( billamount * gst ) + (billamount * t_charges ) - discount ) ;
        }
}

public class PaymentMethod
{
        public static void main(String[] args)
        {
      System.out.println("\n<=================== PROCESSING YOUR PAYMENTS ======================>\n");
      Scanner sc = new Scanner(System.in);
      System.out.print("\nENTER THE PURCHASE ID : ");
      int id = sc.nextInt();
      System.out.print("\nENTER THE NAME OF THE PAYEE : ");
      String payee_name = sc.next();
      System.out.print("\nENTER THE BILL AMOUNT :");
      double billamount = sc.nextDouble();
      System.out.print("\nENTER THE PURCHASE DATE : ");
      int date = sc.nextInt();
      System.out.print("\nSELECT YOUR PAYMENT MODE (cash/card) : ");
      String ch = sc.next();
      switch(ch)
      {
         case "cash":
         {
            Cash bill = new Cash( id , payee_name , billamount , date );
            bill.displayBill(bill.calculateBill());
            break;
         }
         case "card":
         {
            System.out.print("\nWHAT WOULD YOU LIKE TO DO (credit / debit) CARD : ");
            String card = sc.next();
            switch(card)
            {
               case "debit":
               {
                  System.out.print("\nENTER THE DEBIT CARD NUMBER : ");
                  long card_no = sc.nextLong();
                  DebitCard bill = new DebitCard( id , payee_name , billamount , date , card_no );
                  bill.displayBill(bill.calculateBill());
                  break;
               }
               case "credit":
               {
                  System.out.print("\nENTER THE CREDIT CARD NUMBER : ");
                  long card_no = sc.nextLong();
                  CreditCard bill = new CreditCard( id , payee_name , billamount , date , card_no );
                  bill.displayBill(bill.calculateBill());
                  break;
               }
               default:
               {
                  System.out.println();
                  long card_no = sc.nextLong();
                  Card bill = new Card( id , payee_name , billamount , date , card_no );
                  bill.displayBill(bill.calculateBill());
                  break;
               }
            }
            break;
         }
         default:
         {
            System.out.println("\nInvalid Choice !\n");
            break;
         }
           }
   }
}
