package com.example.webflux_functional_programming.service;

import com.example.webflux_functional_programming.handler.UserHandler;
import org.springframework.http.HttpEntity;
import org.springframework.http.MediaType;
import org.springframework.http.server.reactive.ReactorHttpHandlerAdapter;
import org.springframework.web.reactive.function.server.RouterFunction;
import org.springframework.web.reactive.function.server.RouterFunctions;
import org.springframework.web.reactive.function.server.ServerResponse;
import reactor.netty.http.server.HttpServer;

import javax.xml.ws.spi.http.HttpHandler;

import java.io.IOException;

import static org.springframework.web.reactive.function.server.RequestPredicates.GET;
import static org.springframework.web.reactive.function.server.RequestPredicates.accept;
import static org.springframework.web.reactive.function.server.RouterFunctions.toHttpHandler;

public class Server {
    public static void main(String[] args) throws IOException {
        Server server = new Server();
        server.createReactorServer();
        System.out.println("enter to exit");
        System.in.read();
    }
    //1 创建Router路由
    public RouterFunction<ServerResponse> routerFunction(){
        //创建handler对象
        UserService userService = new UserServiceImpl();
        UserHandler handler = new UserHandler(userService);
        //设置路由
        return RouterFunctions.route(GET("/users/{id}").and(accept(MediaType.APPLICATION_JSON)),handler::getUserById).andRoute(GET("/users").and(accept(MediaType.APPLICATION_JSON)),handler::getAllUsers);
    }

    //创建服务器完成适配
    public  void createReactorServer(){
        //路由和handler适配
        RouterFunction<ServerResponse> route = routerFunction();
        HttpHandler httpHandler = (HttpHandler) toHttpHandler(route);
        ReactorHttpHandlerAdapter adapter = new ReactorHttpHandlerAdapter((org.springframework.http.server.reactive.HttpHandler) httpHandler);

        //创建服务器
        HttpServer httpServer = HttpServer.create();
        httpServer.handle(adapter).bindNow();
    }

}
