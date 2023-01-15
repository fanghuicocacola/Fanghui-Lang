package com.example.webflux_functional_programming.service;

import com.example.webflux_functional_programming.entity.User;
import reactor.core.publisher.Flux;
import reactor.core.publisher.Mono;

import java.util.HashMap;
import java.util.Map;

public class UserServiceImpl implements UserService{
    //创建map集合存储数据
    private final Map<Integer,User> users = new HashMap<>();
    public UserServiceImpl(){
        this.users.put(1,new User("lucy","man",20));
        this.users.put(2,new User("marry","woman",22));
        this.users.put(3,new User("jack","man",24));
    }
    //根据id查询
    @Override
    public Mono<User> getUserById(int id) {
        return Mono.justOrEmpty(this.users.get(id));
    }
    //查询多个用户
    @Override
    public Flux<User> getAllUser() {
        return Flux.fromIterable(this.users.values());
    }
    //添加用户
    @Override
    public Mono<Void> saveUserInfo(Mono<User> userMono) {
        return userMono.doOnNext(person->{
            //向map集合里面放值
            int id = users.size();
            users.put(id,person);
        }).thenEmpty(Mono.empty());
    }
}
