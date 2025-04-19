package demo3;
import java.io.*;
public class PrintDemo {
    public static void main(String[] args) throws FileNotFoundException {
        File file = new File("D:\\1.txt");
        PrintWriter out = new PrintWriter(file);
        out.println("Hello World!");
        out.close();
    }
    
}
