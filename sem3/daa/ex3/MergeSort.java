class MergeSort
{
   static void merge(int B[], int C[], int A[])
   {
      int i=0,j=0,k=0;
      while(i<B.length && j<C.length)
      {
         if(B[i] <= C[j])
            A[k++] = B[i++];
         else
            A[k++] = C[j++];
      }
      while(i<B.length)
         A[k++] = B[i++];
      while(j<C.length)
         A[k++] = C[j++];
   }
   static void mergeSort(int A[])
   {
      if(A.length <= 1)
         return;
      int mid = A.length/2;
      int B[] = new int[mid];
      int C[] = new int[A.length - mid];
      for(int i=0;i<mid;i++)
         B[i] = A[i];
      for(int i=mid;i<A.length;i++)
         C[i-mid] = A[i];
      mergeSort(B);
      mergeSort(C);
      merge(B,C,A);
   }
   public static void main(String [] args)
   {
      int A[] = {7,8,2,3,1,6};
      //MergeSort m = new MergeSort();
      System.out.println("\nArray Elements :\n");
      for(int ele : A)
         System.out.print(ele+"  ");
      System.out.println("\n\nSorted..!\n");
      mergeSort(A);
      for(int x:A)
         System.out.print(x+"  ");
      System.out.println("\n");
   }
}