package demo3;

import java.io.*;
class Sender extends Thread{
    private PipedOutputStream out=new PipedOutputStream();
    public PipedOutputStream getOutputStream(){
        return out;
    }
   
    public void run(){
         String s = new String("Receiver 你好！");
         try {
             out.write(s.getBytes());
             out.close();
         } catch (IOException e) {
             //TODO: handle exception
             System.out.println(e.getMessage());
         }
    }

}

class Receiver extends Thread{
    private PipedInputStream in=new PipedInputStream(); 
    public PipedInputStream getInputStream(){
        return in;
    }

    public void run(){
        String s = null;
        byte[] b = new byte[1024];
        try {
            int len = in.read(b);
            s = new String(b,0,len);
            System.out.println("收到了以下信息 :"+s);
        } catch (IOException e) {
            //TODO: handle exception
        }
    }
}
public class PipeStreamDemo {
    public static void main(String[] args) {
        try {
            Sender sender = new Sender();
            Receiver receiver = new Receiver();
            PipedOutputStream out = sender.getOutputStream(); 
            PipedInputStream in = receiver.getInputStream(); 
            out.connect(in); 
            sender.start();
            receiver.start();
        } catch (Exception e) {
            //TODO: handle exception
        }    
    }
}
