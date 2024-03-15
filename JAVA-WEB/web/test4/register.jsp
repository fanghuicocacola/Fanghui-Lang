<%--
  Created by IntelliJ IDEA.
  User: 黑白灰
  Date: 2022/4/22
  Time: 9:50
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>合法性检验</title>
</head>
<body>
<%
    request.setCharacterEncoding("UTF-8");
    String name=request.getParameter("username");
    String pw=request.getParameter("pwd");
    String rpw=request.getParameter("rpw");
    //定义以user为开头的用户名 "^(?!user).*$"
    //String user = "^(?!user).*$";
    if(pw.equals(rpw)) {
        if (name != null && pw != null && pw.equals(rpw)) {
            if (name.equals("admin")) {
                out.println("<h3>欢迎您,管理员</h3>");
            } else if (name.startsWith("user"))//检验用户名是否以user开头
            {
                out.println("<h3>该用户名已被注册,请返回<a href=\"register.html\">登录页面</a>！");
                response.setHeader("Refresh", "5;url=register.html");
            } else {
                out.println("<h3>该用户名已被注册,请返回<a href=\"register.html\">登录页面</a>！");
                response.setHeader("Refresh", "5;url=register.html");
                out.print("<h3>恭喜您, </h3>" + name + "<h3>注册成功 </h3>");
            }
        } else {
            out.println("<h3>请重新输入用户名或者密码<a href=\"register.html\">登录页面</a>！");
            response.setHeader("Refresh", "5;url=register.html");
        }
    }
    else{
        out.print("两次密码不一致");
    }
%>
</body>
</html>