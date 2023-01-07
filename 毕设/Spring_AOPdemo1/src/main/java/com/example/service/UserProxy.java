package com.example.service;

import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.*;
import org.springframework.core.annotation.Order;
import org.springframework.stereotype.Component;

//增强的类
@Component
@Aspect
@Order(3)
public class UserProxy {
    //相同切入点抽取
    @Pointcut(value = "execution(* com.example.service.User.add())")
    public void pointdemo(){

    }
    //作为前置通知
    @Before(value = "pointdemo()")
    public void before(){
        System.out.println("before...");
    }
    @After(value = "execution(* com.example.service.User.add())")
    public void after(){
        System.out.println("after...");
    }
    @AfterReturning(value = "execution(* com.example.service.User.add())")
    public void afterReturn(){
        System.out.println("afterReturn...");
    }
    @AfterThrowing(value = "execution(* com.example.service.User.add())")
    public void afterThrowing(){
        System.out.println("afterThrowing...");
    }
    @Around(value = "execution(* com.example.service.User.add())")
    public void around(ProceedingJoinPoint proceedingJoinPoint) throws Throwable{
        System.out.println("环绕之前");
        //被增强的方法执行
        proceedingJoinPoint.proceed();
        System.out.println("环绕之后");
    }
}
