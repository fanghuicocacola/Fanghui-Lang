package demo5;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Matcherexp {
    public static void main(String[] args) {
        String input = "小明的电子邮箱是sunwokong@163.com,小红的邮箱是bajie@sina.com.cn";
        String regex = "\\w+@\\w+\\.[a-z]+(\\.[a-z]+)?";
        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(input);
        while(matcher.find()){
            String s = matcher.group();
            System.out.println(s);
        }
    }
}
