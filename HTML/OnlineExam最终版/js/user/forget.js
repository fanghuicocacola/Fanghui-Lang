let forgetResult_span_selector = "#forget-result-div span";
let forgetBtn_selector = "#forget-btn";

let forgetResult_span = document.querySelector(forgetResult_span_selector);
let forget_btn = document.querySelector(forgetBtn_selector);

// 变量
let userName, email;

// 找回密码
forget_btn.onclick = function (event) {
    //获取输入的账号和邮箱
    userName = document.getElementById("username").value;
    email = document.getElementById("email").value;
    var data = 'userName=' +
        userName +
        '&email=' +
        email;
    //侦听来自id = "postForm"的提交事件，如果发生，则执行postForm（）函数
    document.getElementById("postForm").addEventListener("submit", postForm);

    function postForm(e) {
        e.preventDefault();
        let xhr = new XMLHttpRequest();
        xhr.open("POST", "/OnlineExam/php/forgetpass.php", true);
        //设置请求头
        xhr.setRequestHeader("Content-type", "application/x-www-form-urlencoded; charset=utf-8");
        xhr.onload = function () {
            console.log(this.responseText);
            //返回的字符流第一个字符如果为“1”，则说明账号邮箱和数据库匹配成功，代表找回成功
            if (this.responseText[0] == "1") {
                //块元素显示“找回成功”
                forgetResult_span.parentNode.style.display = "block";
                forgetResult_span.innerText = "找回成功";
                alert(this.responseText);
                //跳转到登录界面
                window.location.href = "/OnlineExam/pages/user/login.html";
            } else {
                forgetResult_span.parentNode.style.display = "block";
                forgetResult_span.innerText = "找回失败";
                return false
            }
        }
        xhr.send(data);
    }
}