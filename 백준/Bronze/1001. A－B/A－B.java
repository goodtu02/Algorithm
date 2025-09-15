import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] array = new int[2];
        for (int i = 0; i < 2; i++) {
            array[i] = sc.nextInt();
        }
        int sub = array[0];
        sub -= array[1];
        System.out.println(sub);
    }
}