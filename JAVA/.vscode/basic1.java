public class basic1{
    /**
     *
     */
    private static final char CHAR = '\'';

    public static void main(String[] args){ 
        int num,x = 3;
        num = 3;
        long l = 329852547553L;
        num += num;
        char ch = 'a';
        System.out.print(CHAR+"HELLO WORLD"+CHAR); 
        System.out.print(l+"\n");
        System.out.println("我有"+num+"本书！\n");
        System.out.println((num-x)+"个人\n"+ch+"是\t字符");
        long n1 = Long.MAX_VALUE;
        int n2 = Integer.MAX_VALUE;
        short n3 = Short.MAX_VALUE;
        byte n4 = Byte.MAX_VALUE;
        System.out.println("long的最大值为："+n1+"\nint的最大值为："+n2+"\nshort的最大值为："
        +n3+"\nbyte的最大值为："+n4);
        System.out.println(n2+1);
        System.out.println((long)n2+1);//强制类型转换
    }
}
