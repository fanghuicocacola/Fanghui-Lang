
import java.util.Scanner;

// �޸�����
public class repassworld {
    String regex = "\\d{6}";

    public void repassword(String username){
        mysql1 ms = new mysql1();
        ms.MyCon();
        Scanner input=new Scanner(System.in);

        System.out.println("������ɵ�����");
        String oldPassword=input.next();
        System.out.println("�������µ�����");
        String newPassword=input.next();

        if(newPassword.matches(regex)){
            if(ms.Selectpw(username).equals(oldPassword)){
                ms.setpassword(username,newPassword);
                System.out.println("�����޸ĳɹ�");
            }else{
                System.out.println("�������������");
            }
        }else{
            System.out.println("�����д��󣬽���������6λ����ͬ������");
        }
    }
}
