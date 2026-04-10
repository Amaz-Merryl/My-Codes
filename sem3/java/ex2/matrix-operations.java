import java.util.*;
class Matrix
{
        private int rows,colns;
        private int[][] data;

        public Matrix(int rows,int colns)
        {
                this.rows=rows;
                this.colns=colns;
                data = new int[rows][colns];
        }

        public void display()
        {
                for(int i=0;i<this.rows;i++)
                {
                        for(int j=0;j<this.colns;j++)
                        {
                                System.out.print(data[i][j] + "\t");
                        }
                        System.out.println();
                }
        }

        public void readMatrix(Scanner get)
        {
                System.out.print("Enter the elements of the matrix : ");
                for(int i=0;i<rows;i++)
                {
                        for(int j=0;j<colns;j++)
                        {
                                data[i][j]=get.nextInt();
                        }
                }
        }
        public Matrix multiply(Matrix other)
        {
                Matrix res=new Matrix(rows,colns);
                for(int i=0;i<rows;i++)
                {
                        for(int j=0;j<colns;j++)
                        {
                                for(int k=0;k<colns;k++)
                                {
                                        res.data[i][j] += this.data[i][k] * other.data[k][j];
                                }
                        }
                }
                return res;
        }

        public Matrix transpose()
        {
                Matrix res=new Matrix(rows,colns);
                for(int i=0;i<rows;i++)
                {
                        for(int j=0;j<colns;j++)
                        {
                                res.data[i][j]=this.data[j][i];
                        }
                }
                return res;
        }
}
public class MatrixOperations
{
        public static void main(String[] args)
        {
                Scanner get=new Scanner(System.in);
                System.out.print("Rows  = ");
                int rows=get.nextInt();
                System.out.print("Coloumns      = ");
                int colns=get.nextInt();
                Matrix m1=new Matrix(rows,colns);
                m1.readMatrix(get);
                System.out.println("Elements of Matrix 1 : ");
                m1.display();
                Matrix m2= new Matrix(rows,colns);
                m2.readMatrix(get);
                System.out.println("Elements of Matrix 2 :");
                m2.display();
                Matrix res=new Matrix(rows,colns);
                res=m1.multiply(m2);
                System.out.println("Multiplied : \n");
                res.display();
                System.out.println("Transpose of the resultant Matrix is :\n");
                Matrix t = res.transpose();
                t.display();
        }
}
