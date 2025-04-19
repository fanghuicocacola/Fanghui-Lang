package TEST;

import java.util.Random;
import java.util.Scanner;

public class caishu {
    public static void main(String[] args) {
		
		Random ra = new Random();
		int number = ra.nextInt(100) + 1;
		
		Scanner sc = new Scanner(System.in);
		for(int i = 5; i > 0; i--) {
			System.out.println("请输入一个数：");
			int score = sc.nextInt();
			
			if(score > number) {
				System.out.println("猜大了！");
			}
			if(score < number) {
				System.out.println("猜小了！");
			}
			if(score == number) {
				System.out.println("恭喜你猜对了！");
				break;
			}
			if(1 == i) {
				System.out.println("你没有机会了！");
				System.out.println("正确答案是：" + number);
				break;
			} else {
				System.out.println("你还有" + (i-1) + "次机会！");
			}
			
		}
		
	}
}
