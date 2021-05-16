import java.util.Arrays;
import java.util.Scanner;

public class sort1 {
	public static void main(String arg[]) {
		int sum = 1;
		Scanner nums=new Scanner(System.in);
		int a[]=new int[5];
		for (int i = 0; i < 5; i++) {
			a[i] = nums.nextInt();
		}
        nums.close();
		long p1 = System.currentTimeMillis();
        Arrays.sort(a);
		for (int i=0; i<5; i++) {
			System.out.print(a[i] + " ");
		}
		for(int i=0;i<10;i++){
			sum*=i;
		}
		System.out.println(sum);
		long p2 = System.currentTimeMillis();
		System.out.println(p2-p1+"ms");
	}
}
