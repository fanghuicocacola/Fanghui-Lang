<%--
  Created by IntelliJ IDEA.
  User: 黑白灰
  Date: 2022/5/1
  Time: 20:36
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>计算</title>
</head>
<body>
<form method = "post" action = "result.jsp">
    <input name="op1" type="text">
    <select name="op">
        <option value="+">+</option>
        <option value="-">-</option>
        <option value="*">*</option>
        <option value="/">/</option>
    </select>
    <input name="op2" type="text">
    <input type="submit" value="去看看">
    <input id="cancel" type="reset" value="重新输入">
</form>
</body>
</html>
