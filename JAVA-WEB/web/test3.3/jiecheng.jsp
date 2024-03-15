<%--
  Created by IntelliJ IDEA.
  User: 黑白灰
  Date: 2022/4/18
  Time: 20:33
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%!
    public int jiecheng(int num){
        int s=1;
        for(int i=num;i>=1;i--){
            s*=i;
        }
        return s;
    }
%>
<html>
<head>
    <title>十以内的阶乘</title>
</head>
<body>
<%for(int i=1;i<=10;i++) {
    out.print("<p>" +i + "的阶乘是:" + jiecheng(i)+"<p>");
}
%>
</body>
</html>
