package com.example.service;

import org.springframework.stereotype.Component;

//被增强的一个类
@Component
public class User {
    public void add(){
        System.out.println("add...");
    }
}
