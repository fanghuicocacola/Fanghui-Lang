package demo6;

import java.util.regex.Matcher;
import java.util.regex.Pattern;
public class zhengze {
    public static void main(String[] args) {
        String s = "I am JAVA";
        String patern = ".*JAVA.*";
        String line = "What I want to see is that 2 = 1 + 1";
        final String ss = "\\bdog\\b";
        final String content = "dog dog dog dogge dog";
        String pattern = "(\\D*)((\\d+)(.*))";// \D表示任意一个非数字，\d表示任意一个数字，*表示零次或多次匹配前面的字符或子表达式。例如，zo* 匹配"z"和"zoo"。* 等效于
                                            // {0,}。
        Pattern p = Pattern.compile(ss);
        Matcher m1 = p.matcher(content);
        boolean isMatch = Pattern.matches(patern, s);
        if (isMatch == true) {
            System.out.println("字符串" + s + "包含字符" + patern);
        }
        Pattern r = Pattern.compile(pattern);

        // 现在创建 matcher 对象
        Matcher m2 = r.matcher(line);
        if (m2.find()) {
            System.out.println("Found value: " + m2.group(0));
            System.out.println("Found value: " + m2.group(1));
            System.out.println("Found value: " + m2.group(2));
            System.out.println("Found value: " + m2.group(3));
            System.out.println("Found value: " + m2.group(4));
        } else {
            System.out.println("NO MATCH");
        }
        int count = 0;
        while(m1.find()) {
            count++;
            System.out.println("Match number "+count);
            System.out.println("start(): "+m1.start());
            System.out.println("end(): "+m1.end());
         }
    }
}
