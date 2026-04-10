class QuickSort {
   static int partition(int A[], int low, int high) {
      int pivot = A[low];
      int i = low + 1;
      int j = high;

      while (i <= j) {

         while (i <= high && A[i] <= pivot) i++;
         while (j >= low && A[j] > pivot) j--;

         if (i < j) {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
         }
      }


      A[low] = A[j];
      A[j] = pivot;
      return j;
   }

   static void quickSort(int A[], int low, int high) {
      if (low < high) {
         int pi = partition(A, low, high);


         quickSort(A, low, pi - 1);
         quickSort(A, pi + 1, high);
      }
   }

   public static void main(String[] args) {
      int A[] = {7, 8, 2, 3, 1, 6};

      System.out.println("\nArray Elements :\n");
      for (int ele : A)
         System.out.print(ele + "  ");

      System.out.println("\n\nSorted..!\n");


      quickSort(A, 0, A.length - 1);

      for (int x : A)
         System.out.print(x + "  ");
      System.out.println("\n");
   }
}