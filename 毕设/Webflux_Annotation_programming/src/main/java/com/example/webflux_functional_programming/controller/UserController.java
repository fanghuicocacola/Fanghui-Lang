package com.example.webflux_functional_programming.controller;

import com.example.webflux_functional_programming.entity.User;
import com.example.webflux_functional_programming.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;
import org.springframework.web.bind.annotation.*;
import reactor.core.publisher.Flux;
import reactor.core.publisher.Mono;

@RestController
public class UserController {
    //注入service
    @Autowired
    private UserService userService;

    //id查询
    @GetMapping("/user/{id}")
    public Mono<User> getUserId(@PathVariable int id){
        return userService.getUserById(id);
    }

    //查询所有
    @GetMapping("/user")
    public Flux<User> getUsers(){
        return userService.getAllUser();
    }
    //添加
    @PostMapping("/saver")
    public Mono<Void> saveUser(@RequestBody User user){
        Mono<User> userMono = Mono.just(user);
        return userService.saveUserInfo(userMono);
    }

}
