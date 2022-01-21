let loginResult_span_selector = "#login-result-div span";
let loginBtn_selector = "#login-btn";

let loginResult_span = document.querySelector(loginResult_span_selector);
let loging_btn = document.querySelector(loginBtn_selector);

// 变量
let userName, password, checkCode, inputCode;
//页面加载时，生成随机验证码
window.onload = function () {
    createCode(4);
}

//生成验证码的方法
function createCode(length) {
    var code = "";
    var codeLength = parseInt(length); //验证码的长度
    //获取验证码输入内容
    var checkCode = document.getElementById("checkCode");
    //创建一个数组，存储要用到的随机数
    var codeChars = new Array(0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z');
    //循环组成验证码的字符串
    for (var i = 0; i < codeLength; i++) {
        //获取随机验证码下标
        var charNum = Math.floor(Math.random() * 62);
        //组合成指定字符验证码
        code += codeChars[charNum];
    }
    if (checkCode) {
        //为验证码区域添加样式名
        checkCode.className = "code";
        //将生成验证码赋值到显示区
        checkCode.innerHTML = code;
    }
}



// 登录校验创建一个点击事件
loging_btn.onclick = function (event) {
    //获取所需要输入框的数据
    userName = document.getElementById("username").value;
    if (!regMatch(userName, REG_USER_NAME)) {
        // 当格式错误时，显示一个块元素，元素内容为"用户名格式错误"
        loginResult_span.parentNode.style.display = "block";
        loginResult_span.innerText = "用户名格式错误";
        return false;
    } else {
        // 不显示块元素
        loginResult_span.parentNode.style.display = "none";
    }

    password = document.getElementById("password").value;
    if (!regMatch(password, REG_PASSWORD)) {
        loginResult_span.parentNode.style.display = "block";
        loginResult_span.innerText = "密码格式错误";
        return false;
    } else {
        loginResult_span.parentNode.style.display = "none";
    }

    //获取显示区生成的验证码
    checkCode = document.getElementById("checkCode").innerHTML;
    //获取输入的验证码
    inputCode = document.getElementById("inputCode").value;
    if (checkCode != inputCode) {
        loginResult_span.parentNode.style.display = "block";
        loginResult_span.innerText = "验证码错误";
        return false;
    } else {
        loginResult_span.parentNode.style.display = "none";
    }

    var data = 'userName=' +
        userName +
        '&password=' +
        password;
    //侦听来自id为postForm的提交事件，如果检测到，则执行postForm()函数
    document.getElementById("postForm").addEventListener("submit", postForm);

    function postForm(e) {
        e.preventDefault();
        // 一个异步请求
        let xhr = new XMLHttpRequest();
        xhr.open("POST", "/OnlineExam/php/mysqlconnect.php", true);
        //设置请求头
        xhr.setRequestHeader("Content-type", "application/x-www-form-urlencoded; charset=utf-8");
        xhr.onload = function () {
            console.log(this.responseText);
            if (this.responseText[0] == "1") {
                window.location.href = "/OnlineExam/pages/main/main.html";
            } else {
                loginResult_span.parentNode.style.display = "block";
                loginResult_span.innerText = "账号或密码错误";
                return false;
            }
        }
        xhr.send(data);
    }
}