<%--
  Created by IntelliJ IDEA.
  User: 黑白灰
  Date: 2022/5/1
  Time: 20:05
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<% request.setCharacterEncoding("utf-8"); %>
<html>
<head>
    <title>welcome</title>
</head>
<body>
    <%
        String name = (String)session.getAttribute("loginUsername");
        if(name == null){
            out.println("<p>请先登录...即将返回登录界面</p>");
            response.setHeader("Refresh","5;url=login.jsp");
        }else {
            out.println("<h2>欢迎你！"+name+"</h2>");
        }
    %>
</body>
</html>
