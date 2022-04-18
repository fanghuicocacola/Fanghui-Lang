<%--
  Created by IntelliJ IDEA.
  User: 黑白灰
  Date: 2022/4/18
  Time: 14:37
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html; charset=UTF-8" language="java" import="java.sql.*" errorPage=""%>
<%@ page info="一个简单的登录程序" %>
<html>
<head>
    <title>一个简单的登录程序</title>
</head>
<body>
<%--登录界面--%>
<div>
    用户登录
    <hr>
    <form method=get action=login_check.jsp>
        <table>
            <tr>
                <td>Please input your name</td>
                <td><input type=text name=name value=<%=request.getParameter("name")%>> </td>
            </tr>
            <tr>
                <td>Please input password</td>
                <td><input type=password name=password></td>
            </tr>
            <tr colspan=2>
                <td><input type=submit value=login></td>
            </tr>
        </table>
    </form>
</div>
<jsp:include page="footer.jsp"/>
</body>
</html>
