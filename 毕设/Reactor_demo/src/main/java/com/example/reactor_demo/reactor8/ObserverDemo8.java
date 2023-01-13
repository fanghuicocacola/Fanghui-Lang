package com.example.reactor_demo.reactor8;

import java.util.Observable;

public class ObserverDemo8 extends Observable {
    public static void main(String[] args) {
        ObserverDemo8 observer = new ObserverDemo8();
        //添加观察者
        observer.addObserver((o,arg)->{
            System.out.println("发生了变化");
        });
        observer.addObserver((o,arg)->{
            System.out.println("收到了被观察者的通知，准备改变");
        });
        observer.setChanged();//数据变化
        observer.notifyObservers();//通知
    }


}
