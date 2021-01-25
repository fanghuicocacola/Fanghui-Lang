public class Test3 {
    // == 比较内存地址，equals 比较内容
    public static void main(String[] args) {
        String a = new String("111");
        String b = new String("111");
        if(a == b){
            System.out.println("a = b");
        }
        else if(a.equals(b))
        {
            System.out.println("a = b"); 
        }
        else 
        {
            System.out.println("a != b");
        }
        
    }

}
