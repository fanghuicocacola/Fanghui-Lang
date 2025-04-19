public class MainTest {
    // Ö÷º¯Êý
    public static void main(String[] args) {
        mysql1 ms = new mysql1();
        ms.MyCon();
        String username = null;

        account at=new account();
        username = at.signIn();
        if(!username.equals("no")){
            atm atm1 = new atm(username);
            atm1.operate();
        }

    }
}
