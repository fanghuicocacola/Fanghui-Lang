<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<% request.setCharacterEncoding("utf-8"); %>
<%--这两行代码可以解决网页展示和传参的乱码问题。--%>
<html>

<head>

    <title>用户注册页面</title>

    <meta http-equiv="content-type" content="text/html;charset=UTF-8">

</head>

<body>

<h2 align="center">用户注册</h2>

<form method="post">

    <table align="center" border="1" width="35%">

        <tr><th width="30%">姓名</th><td><input type="text" name="name"></td></tr>

        <tr><th>密码</th><td><input type="password" name="pw"></td></tr>

        <tr><th>确认密码</th><td><input type="password" name="pw2"></td></tr>

        <tr><th>性别</th><td><input type="radio" name="sex" value="男" checked>男　

            <input type="radio" name="sex" value="女">女</td></tr>

        <tr><th>职业</th>

            <td><select size="1" name="career">

                <option value="教育工作者">教育工作者</option>

                <option value="公司职员" selected>公司职员</option>

                <option value="自由职业者">自由职业者</option>

                <option value="其他">其他</option>

            </select></td></tr>

        <tr><th>电话号码</th><td><input type="text" name="telephone"></td></tr>

        <tr><th>电子邮箱</th><td><input type="text" name="email" size="30"></td></tr>

        <tr><th>兴趣爱好</th><td>

            <input type="checkbox" name="fav" value="体育">体育

            <input type="checkbox" name="fav" value="看书">看书

            <input type="checkbox" name="fav" value="旅游">旅游

            <input type="checkbox" name="fav" value="美食">美食

        </td></tr>

        <tr><th>自我简介</th>

            <td><textarea name="intro" rows="5" cols="30"></textarea></td></tr>

        <tr><td colspan="2" align="center"><input type="submit" value="注册"></td></tr>

    </table>

</form>

</body>

</html>