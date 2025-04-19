// 选择器
let userName_input_selector = "#input-root-div input:first-of-type";
let password_input_selector = "#input-root-div input:last-of-type";
let loginResult_span_selector = "#login-result-div span";
let loginBtn_selector = "#login-btn";

// 标签
let userName_input = document.querySelector(userName_input_selector);
let password_input = document.querySelector(password_input_selector);
let loginResult_span = document.querySelector(loginResult_span_selector);
let loging_btn = document.querySelector(loginBtn_selector);

// 变量
let userName, password;

// 登录校验
loging_btn.onclick = function (event) {

    userName = userName_input.value;
    if (!regMatch(userName, REG_USER_NAME)) {
        loginResult_span.parentNode.style.display = "block";
        loginResult_span.innerText = "用户名格式错误";
        return;
    } else {
        loginResult_span.parentNode.style.display = "none";
    }

    password = password_input.value;
    if (!regMatch(password, REG_PASSWORD)) {
        loginResult_span.parentNode.style.display = "block";
        loginResult_span.innerText = "密码格式错误";
        return;
    } else {
        loginResult_span.parentNode.style.display = "none";
    }

    if (regMatch(password, REG_PASSWORD)){
        window.location.href = "pages/main/main.html";
    }
    
    var url = base_url + login_url;
    var data = '{"userName":"' + userName + '", "password":' + '"' + password + '"}';
    console.log(data);

    ajax("POST", url, true, false, data, null, null,
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