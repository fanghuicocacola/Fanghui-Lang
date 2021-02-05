package Applet;

import java.applet.*;
import java.awt.*;

public class HelloAppletDemo extends Applet {
    /**
     *
     */
    private static final long serialVersionUID = 1L;
    String myString = "";

    public void paint(Graphics g) {
        g.drawString(myString, 5, 30);
    }

    public void init() {
        myString = myString + "正在初始化……";
        repaint();
    }

    public void start() {
        myString = myString + "正在开始执行程序……";
        repaint();
    }

    public void stop() {
        myString = myString + "正在停止程序";
        repaint();
    }

    public void destory() {
        myString = myString + "正在回收资源";
        repaint();
    }

}
