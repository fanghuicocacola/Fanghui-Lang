<%--
  Created by IntelliJ IDEA.
  User: 黑白灰
  Date: 2022/5/1
  Time: 19:43
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>login</title>
</head>
<body>
    <form action="#" method="post">
        请输入姓名：<input type="text" name="name"><br>
        请输入密码：<input type="password" name="pw"><br>
        <input type="submit" value="登录">
    </form>
    <%
        request.setCharacterEncoding("UTF-8");
        String name = request.getParameter("name");
        String pw = request.getParameter("pw");
        if(name!=null&&pw!=null){
            session.setAttribute("loginUsername",name);
            response.sendRedirect("welcome.jsp");
        }else {
        }
    %>
</body>
</html>
