package com.example.config;

import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

@Configuration  //作为配置类，替换xml配置文件
@ComponentScan(basePackages = {"com.example"})
public class SpringConfig {

}
