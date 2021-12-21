// alert("来自一个外部JavaScript的简单应用")

var x = 9;
/* 
if(x<10){
    x = 10;
    alert(x);
}
*/
x = null
var name = "123", msg;
// alert(msg);
// alert(x);
msg = "Hello JavaScript";
var s1 = "HELLO";
var s2 = "WORLD";
var s3 = "!";
var len = msg.length;
// alert("Hello JavaScript的长度为：" + len + "\n第三个字符是: " + msg.charAt(2) + "\n其字符代码是: " + msg.charCodeAt(2));
// alert("字符串的连接: " + s1.concat(s2,s3));

// JavaScript 函数的简单应用
function test0(x1, x2) {
    return x1 + x2;
}
function test1() {
    alert("点击被触发,输出x的值: " + test0(3, 4));
}

console.log("控制台输出信息命令：console.log()")
var add = (function () {
    var counter = 0;
    return function () { return counter += 1; }
})();
function myFunction() {
    document.getElementById("demo").innerHTML = add();
}
function welcome() {
    alert("HELLO HTML5");
}

// 闭包
function makeFun(name){
    function displayName(){
        var name2 = "JavaScript";
        alert(name+name2);
    }
    return displayName
}

var fun1 = makeFun("哈喽");
fun1();
