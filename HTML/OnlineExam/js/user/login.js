// 选择器
/*
let userName_input_selector = "#input-root-div input:first-of-type";
let password_input_selector = "#input-root-div input:last-of-type";
*/

let loginResult_span_selector = "#login-result-div span";
let loginBtn_selector = "#login-btn";

// 标签
/*
let userName_input = document.querySelector(userName_input_selector);
let password_input = document.querySelector(password_input_selector);
*/

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
    var checkCode = document.getElementById("checkCode");
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



// 登录校验
loging_btn.onclick = function (event) {

    userName = document.getElementById("1").value;
    if (!regMatch(userName, REG_USER_NAME)) {
        loginResult_span.parentNode.style.display = "block";
        loginResult_span.innerText = "用户名格式错误";
        return;
    } else {
        loginResult_span.parentNode.style.display = "none";
    }

    password = document.getElementById("2").value;
    if (!regMatch(password, REG_PASSWORD)) {
        loginResult_span.parentNode.style.display = "block";
        loginResult_span.innerText = "密码格式错误";
        return;
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
        return;
    } else {
        loginResult_span.parentNode.style.display = "none";
    }

    var url = base_url + login_url;
    var data = '{"userName":"' + userName + '", "password":' + '"' + password + '"}';
    console.log(data);

    ajax("POST", 
        url, 
        true,
        false, 
        data, 
        null, 
        null,
        function (xmlhttprequest) {
            var rs = xmlhttprequest.responseText;
            // JSON.parse(jsonstr); //可以将json字符串转换成json对象 
            // JSON.stringify(jsonobj); //可以将json对象转换成json对符串 
            var resJson = JSON.parse(rs);
            console.log(resJson.resMsg);

            if(resJson.resCode == 1){
                window.location.href = "pages/main/main.html";
            }
        },
        function (xmlhttprequest) {
        }
    );
}