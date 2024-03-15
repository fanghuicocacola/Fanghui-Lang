<%--
  Created by IntelliJ IDEA.
  User: 黑白灰
  Date: 2022/4/22
  Time: 9:15
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=utf-8" %>
<%@ page import="java.lang.Integer" %>
<%@ page import="java.io.*" %>
<html>
<body>
<%
    String number=request.getParameter("number");
    try {
        int i = Integer.parseInt(number);
        int square=i*i;
        int cube=i*i*i;
        out.print(i+"的平方是"+square+"<br>");
        out.print(i+"的立方是"+cube);
    }
    catch (NumberFormatException e) {
        out.print("请输入纯数字！");
        out.print("即将跳转。。。请重新输入");
        response.setHeader("Refresh","3;URL=inputNumber.jsp");
    }
%>
</body>
</html>
