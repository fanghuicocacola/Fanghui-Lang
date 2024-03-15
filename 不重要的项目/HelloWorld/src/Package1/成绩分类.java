package Package1;
import java.util.Scanner;
public class 成绩分类 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int grade = in.nextInt();
        switch (grade/10){
            case 10:
            case 9: System.out.println("优秀");break;
            case 8: System.out.println("良好");break;
            case 7: System.out.println("合格");break;
            case 6: System.out.println("及格");break;
            default:System.out.println("不合格");
        }
    }
}
