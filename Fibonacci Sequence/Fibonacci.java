class Fibonacci {
  public static void main(String[] args) {
    int i1 = 0, i2 = 1, sum;
    int max = 6090; //The for loop will keep going until the sequence reaches a number that is greater than the integer specified here.

    System.out.println(i1);
    System.out.println(i2);
    do {
      System.out.println(i1 + i2 );
      sum = i1 + i2;
      i1 = i2;
      i2 = sum;
    } while(sum < max);
  }
}