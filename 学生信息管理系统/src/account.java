import java.util.Scanner;

public class account {
    // ��¼���棬��֤�˺ź�����
    mysql1 ms = new mysql1();

    String inputusername;
    String inputpassworld;

    public String signIn() {
        ms.MyCon();
        System.out.println("��ӭ������¼����");
        Scanner input = new Scanner(System.in);
        System.out.println("����������˻�");
        inputusername = input.next();

        System.out.println("�������������");
        inputpassworld = input.next();
        if (ms.Selectpw(inputusername).equals(inputpassworld) && ms.Selectun(inputusername).equals(inputusername)) {
            System.out.println("��½�ɹ�");
            return inputusername;
        } else {
            System.out.println("��½ʧ��");
            return "no" ;
        }
    }
}



