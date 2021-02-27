package Room;

import java.util.Scanner;

public class HotelMySystem {
    public static void main(String[] args) {
        Hotel hotel = new Hotel();
        System.out.println("欢迎使用酒店管理系统，请认真阅读一下使用说明");
        System.out.println("【1】查看，【2】订房，【3】退房，【0】退出");
        Scanner s = new Scanner(System.in);
        System.out.println("请输入功能编号");
        int i = s.nextInt();
        while(true) {
            if (i == 1) {
                hotel.print();
            } else if (i == 2) {
                System.out.println("请输入房间编号");
                int roomNo = s.nextInt();
                hotel.order(roomNo);
            } else if (i == 3) {
                System.out.println("请输入房间编号");
                int roomNo = s.nextInt();
                hotel.exit(roomNo);
            } else if (i == 0) {
                System.out.println("欢迎下次再来");
                return;
            } else {
                System.out.println("输入有误");
            }
        }
    }
}
