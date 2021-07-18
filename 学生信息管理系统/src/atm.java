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

    //选择功能 查询余额，存取款，修改密码，退出
    public void operate(){
        System.out.println(": \n1 查询余额 \n2存钱 \n3 取钱 \n4 修改密码 \n5 退出");
        System.out.println("请输入序号：");
        int chioce = input.nextInt();
        switch(chioce){
            case 1: //查询余额
                balance();
                quitOperate();
                break;
            case 2: //存款
                save();
                quitOperate();
                break;
            case 3: //取钱
                withdrawMoney();
                quitOperate();
                break;
            case 4:
                re.repassword(username);
                quitOperate();
                break;
            case 5: //退出
                quitOperate();
                break;
            default:   // 输入错误
                System.out.println("输入错误");
                operate();
                break;
        }
    }
    //查询余额
    public void balance(){
        ms.MyCon();
        System.out.println("您的余额为"+ms.Selectmy(username));
    }

    //取钱
    public void withdrawMoney() {
        ms.MyCon();
        System.out.println("请输入您的取钱金额：");
        int a = input.nextInt();// 取款不得超过五千，不得为负数，必须为一百的倍数
        if (a % 100 != 0 || a < 0) {
            System.out.println("请输入正确的金额（100元的倍数）：");
        }else if(a > 5000){
            System.out.println("每次取款总额不得超过5000元！！！");
        } else if(a > ms.Selectmy(username)){
            System.out.println("您的余额不足：");
        }else {
            System.out.println("取钱成功,您的取款金额为："+a);
            ms.setMoney(username,ms.Selectmy(username)-a);
            balance();
        }
    }

    //存钱
    public void save() {
        ms.MyCon();
        System.out.println("请输入您的存款金额");
        int a = input.nextInt();// 存钱不得小于零，必须为一百的倍数
        if (a % 100 != 0 || a <= 0) {
            System.out.println("请输入正确的金额（100元的倍数）：");
        } else {
            System.out.println("存款成功");
            ms.setMoney(username,ms.Selectmy(username)+a);
            balance();
        }
    }

    //退出操作
    public void quitOperate(){
        System.out.println("您还需要继续操作吗？y/n");
        quitOption = input.next().toLowerCase();
        if(quitOption.equals("y")){
            operate();
        }else if(quitOption.equals("n")){
            System.out.println("退出成功");
        }else{
            System.out.println("输入有误");
            quitOperate();
        }
    }
}