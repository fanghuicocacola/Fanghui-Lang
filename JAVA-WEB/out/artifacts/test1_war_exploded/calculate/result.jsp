<%--
  Created by IntelliJ IDEA.
  User: 黑白灰
  Date: 2022/5/1
  Time: 20:46
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>result</title>
</head>
<body>
<%
    request.setCharacterEncoding("utf-8");
    float op1 = Float.parseFloat(request.getParameter("op1"));
    float op2 = Float.parseFloat(request.getParameter("op2"));
    String op = request.getParameter("op");
    if(op.equals("+")){
        float res  = op1 + op2;
        out.println("<p>两数相加结果是：</p>");
        out.println("<p>"+res+"</p>");
    }
    if(op.equals("-")){
        float res = op1 - op2;
        out.println("<p>两数相减结果是：</p>");
        out.println("<p>"+res+"</p>");
    }
    if(op.equals("*")){
        float res = op1 * op2;
        out.println("<p>两数相乘结果是：</p>");
        out.println("<p>"+res+"</p>");
    }
    if(op.equals("/")){
        if(op2 == 0){
            out.println("<p>分母不能为零，请重新输入</p>");
            response.setHeader("Refresh","1;url=input.jsp");
        }else {
            float res = op1 / op2;
            out.println("<p>两数相乘结果是：</p>");
            out.println("<p>"+res+"</p>");
        }
    }
%>
    </body>
</html>
