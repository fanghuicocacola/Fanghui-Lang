package TEST;

import java.util.Arrays;
import java.util.Scanner;

public class paixu {

	public static void main(String[] args) {
		
		int[] a = new int[5];
		System.out.println("请输入五个数：");
		Scanner sc = new Scanner(System.in);
		
		for(int i = 0; i < a.length; i++) {
			a[i] = sc.nextInt();
		}
		
		Arrays.sort(a);
		
		for(int i = 0; i < a.length; i++) {
			System.out.println(a[i]);
		}

	}

}