<%--
  Created by IntelliJ IDEA.
  User: 黑白灰
  Date: 2022/4/17
  Time: 8:45
  To change this template use File | Settings | File Templates.
  编写程序newclass2.jsp，学会在声明中定义类student，初始化该类（学号、姓名、成绩）
  用表格形式输出“班号（学号的前4位）、学号、姓名、成绩”。
--%>
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<% request.setCharacterEncoding("utf-8"); %>
<%
    //学生类
    class Student
    {
        private String sno;
        private String name;
        private double score;

        //有参数的构造函数
        public Student(String sno,String name,double score)
        {
            this.sno = sno;
            this.name = name;
            this.score = score;
        }

        //获取学生的学号
        String getSno()
        {
            return sno;
        }
        //获取学生姓名
        String getName()
        {
            return name;
        }
        //获取学生成绩
        double getScore() { return score; }
        //获取学生的班号
        String getCn()
        {
            return sno.substring(0,4);
        }
    }
    //初始化
    Student s01 = new Student("190102","fang",85);
%>
<%!
%>
<html>
<head>
    <title>学生</title>
</head>
<body>
<table border='2'>
    <tr>
        <th>班号</th>
        <th>学号</th>
        <th>姓名</th>
        <th>成绩</th>
    </tr>
    <tr>
        <td><%out.print(s01.getCn());%></td>
        <td><%out.print(s01.getSno());%></td>
        <td><%out.print(s01.getName());%></td>
        <td><%out.print(s01.getScore());%></td>
    </tr>
</table>
</body>
</html>
