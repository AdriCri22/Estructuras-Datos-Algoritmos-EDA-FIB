import java.util.Scanner;

class Main {

  public static void main(String[] args) {
    final Scanner sc = new Scanner(System.in);
    while (sc.hasNextInt()) {
      int n = sc.nextInt();
      double[] v = new double[n];
      for (int i = 0; i < n; ++i)
        v[i] = sc.nextDouble();
      int t = sc.nextInt();
      while (t != 0) {
        --t;
        double x = sc.nextDouble();
        int esq = sc.nextInt();
        int dre = sc.nextInt();
        System.out.println(Solution.position(x, v, esq, dre));
      }
    }
  }

}
