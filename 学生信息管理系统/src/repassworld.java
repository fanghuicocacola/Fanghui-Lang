
import java.util.Scanner;

// 修改密码
public class repassworld {
    String regex = "\\d{6}";

    public void repassword(String username){
        mysql1 ms = new mysql1();
        ms.MyCon();
        Scanner input=new Scanner(System.in);

        System.out.println("请输入旧的密码");
        String oldPassword=input.next();
        System.out.println("请输入新的密码");
        String newPassword=input.next();

        if(newPassword.matches(regex)){
            if(ms.Selectpw(username).equals(oldPassword)){
                ms.setpassword(username,newPassword);
                System.out.println("密码修改成功");
            }else{
                System.out.println("旧密码输入错误");
            }
        }else{
            System.out.println("输入有错误，仅允许输入6位非相同的数字");
        }
    }
}
