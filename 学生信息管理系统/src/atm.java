import java.util.Scanner;

public class atm {
    String username;
    public atm(String username){
        this.username = username;
    }
    mysql1 ms = new mysql1();
    Scanner input = new Scanner(System.in);
    private String quitOption;
    repassworld re = new repassworld();

    //ѡ���� ��ѯ����ȡ��޸����룬�˳�
    public void operate(){
        System.out.println(": \n1 ��ѯ��� \n2��Ǯ \n3 ȡǮ \n4 �޸����� \n5 �˳�");
        System.out.println("��������ţ�");
        int chioce = input.nextInt();
        switch(chioce){
            case 1: //��ѯ���
                balance();
                quitOperate();
                break;
            case 2: //���
                save();
                quitOperate();
                break;
            case 3: //ȡǮ
                withdrawMoney();
                quitOperate();
                break;
            case 4:
                re.repassword(username);
                quitOperate();
                break;
            case 5: //�˳�
                quitOperate();
                break;
            default:   // �������
                System.out.println("�������");
                operate();
                break;
        }
    }
    //��ѯ���
    public void balance(){
        ms.MyCon();
        System.out.println("�������Ϊ"+ms.Selectmy(username));
    }

    //ȡǮ
    public void withdrawMoney() {
        ms.MyCon();
        System.out.println("����������ȡǮ��");
        int a = input.nextInt();// ȡ��ó�����ǧ������Ϊ����������Ϊһ�ٵı���
        if (a % 100 != 0 || a < 0) {
            System.out.println("��������ȷ�Ľ�100Ԫ�ı�������");
        }else if(a > 5000){
            System.out.println("ÿ��ȡ���ܶ�ó���5000Ԫ������");
        } else if(a > ms.Selectmy(username)){
            System.out.println("�������㣺");
        }else {
            System.out.println("ȡǮ�ɹ�,����ȡ����Ϊ��"+a);
            ms.setMoney(username,ms.Selectmy(username)-a);
            balance();
        }
    }

    //��Ǯ
    public void save() {
        ms.MyCon();
        System.out.println("���������Ĵ����");
        int a = input.nextInt();// ��Ǯ����С���㣬����Ϊһ�ٵı���
        if (a % 100 != 0 || a <= 0) {
            System.out.println("��������ȷ�Ľ�100Ԫ�ı�������");
        } else {
            System.out.println("���ɹ�");
            ms.setMoney(username,ms.Selectmy(username)+a);
            balance();
        }
    }

    //�˳�����
    public void quitOperate(){
        System.out.println("������Ҫ����������y/n");
        quitOption = input.next().toLowerCase();
        if(quitOption.equals("y")){
            operate();
        }else if(quitOption.equals("n")){
            System.out.println("�˳��ɹ�");
        }else{
            System.out.println("��������");
            quitOperate();
        }
    }
}