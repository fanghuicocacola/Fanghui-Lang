import java.util.Scanner;

public class account {
    // 登录界面，验证账号和密码
    mysql1 ms = new mysql1();

    String inputusername;
    String inputpassworld;

    public String signIn() {
        ms.MyCon();
        System.out.println("欢迎来到登录界面");
        Scanner input = new Scanner(System.in);
        System.out.println("请输入你的账户");
        inputusername = input.next();

        System.out.println("请输入你的密码");
        inputpassworld = input.next();
        if (ms.Selectpw(inputusername).equals(inputpassworld) && ms.Selectun(inputusername).equals(inputusername)) {
            System.out.println("登陆成功");
            return inputusername;
        } else {
            System.out.println("登陆失败");
            return "no" ;
        }
    }
}



