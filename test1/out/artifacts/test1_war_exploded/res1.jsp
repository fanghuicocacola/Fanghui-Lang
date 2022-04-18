<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%!
    public int jiecheng(int num){
        int s=1;
        for(int i=num;i>=1;i--){
            s*=i;
        }
        return s;
    }
%>
<%
    String a= request.getParameter("num");
    int num =1;
    if(a!=null){
        num = Integer.parseInt(a); }
%>
<body>
<p>请输入一个正整数N:</p>
<form action="#" method="post" name="form">
    <input type="text" name="num">
    <input type="submit" name="submit" value="开始计算">
</form>
<p><%=num%>的阶乘是:<%=jiecheng(num)%> </p>
</body>
</html>
