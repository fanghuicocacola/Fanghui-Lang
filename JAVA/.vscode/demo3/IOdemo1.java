package demo3;

import java.io.File;
import java.io.IOException;

public class IOdemo1 {
    public static void main(String[] args) throws IOException {
        File f = new File("D:\\1.txt");
        if(f.exists()){
            f.delete();
        }
        else{
            try{
                f.createNewFile();
            }
            catch(Exception e){
                System.out.println(e);
            }
        }
        System.out.println("文件路径"+f.getPath()+"\n"+"文件名"+f.getName()+"文件大小"+f.length()+"Bytes");
    }
}
