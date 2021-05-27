package demo5.Test;

import java.util.Scanner;

public class ScannerTest {
    public static void main(String[] args) {
        String str = "数学87分，物理76分，英语96分";
        Scanner scanner = new Scanner(str);
        double sum = 0;
        int count = 0;
        scanner.useDelimiter("[^0123456789]+");
        while (scanner.hasNext()) {
            sum += scanner.nextDouble();
            count++;
        }
        scanner.close();
        System.out.println("总成绩: " + sum + "\n平均分: " + sum / count);

    }
}
