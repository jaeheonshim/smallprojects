import java.util.*;
 
class PrimeNumbers
{
   public static void main(String args[])
   {
      int status = 1, count, j;
      long num = 3L;
     
      for (count = 2;;)
      {
         for (j = 2; j <= Math.sqrt(num); j++)
         {
            if (num%j == 0)
            {
               status = 0;
               break;
            }
         }
         if (status != 0)
         {
            System.out.println(num);
            count++;
         }
         status = 1;
         num++;
      }        
   }
}