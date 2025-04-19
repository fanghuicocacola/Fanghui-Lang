package com.example.service;

import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Before;
import org.aspectj.lang.annotation.Pointcut;
import org.springframework.core.annotation.Order;
import org.springframework.stereotype.Component;

@Component
@Aspect
@Order(1)
public class PersonProxy {
    @Pointcut(value = "execution(* com.example.service.User.add())")
    public void pointDemo(){

    }
    @Before(value = "pointDemo()")
    public void before(){
        System.out.println("before_priority...");
    }
}
