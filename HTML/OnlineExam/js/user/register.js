let registerResult_span_selector = "#register-result-div span";
let registerBtn_selector = "#register-btn";

let registerResult_span = document.querySelector(registerResult_span_selector);
let register_btn = document.querySelector(registerBtn_selector);

// 创建变量存储输入的数据
let userName, password1, password2, email, address;

/* 密码强度检验 */
/*鼠标移出密码输入框时会显示不同颜色的提示*/
(function () {
    var myinput = document.getElementById("2");
    myinput.addEventListener("mouseout", function () {
      //对输入密码单独处理 - 使用正则表达式
      var tar = document.getElementsByClassName("plex");
      var len = tar.length;
      for (let i = 0; i < len; i++) {
        tar[i].hidden = true; //再次初始化：将html里创建的密码强度提示全部隐藏
        console.log("1");
      }
      var reg2 = /^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)[^]{6,16}$/;
      var reg1 = /^.{6,16}$/;
      if (reg2.test(myinput.value)) { //强，6-16位，必须有大小写字母和数字
        tar[2].hidden = false;//根据密码强度取消隐藏对应提示
        console.log("2");
      }
      else if (reg1.test(myinput.value)) { //中，6-16位
        tar[1].hidden = false;
        console.log("3");
      }
      else { //弱。不足6位
        tar[0].hidden = false;
        console.log("4");
      }
    }
    )
  })();

//  注册校验，创建一个点击事件
register_btn.onclick = function (event) {
    //获取所需要输入框的数据
    userName = document.getElementById("1").value;
    password1 = document.getElementById("2").value;
    password2 = document.getElementById("3").value;
    if (!regMatch(userName, REG_USER_NAME)) {
        // 当格式错误时，显示一个块元素，元素内容为"用户名格式错误"
        registerResult_span.parentNode.style.display = "block";
        registerResult_span.innerText = "用户名格式错误";
        return;
    } else {
        // 不显示块元素
        registerResult_span.parentNode.style.display = "none";
    }
    // 对比两次输入的密码，不一致就以块元素方式显示"密码不一致"
    if (password1 != password2) {
        registerResult_span.parentNode.style.display = "block";
        registerResult_span.innerText = "密码不一致";
        return false;
    }
    else {
        registerResult_span.parentNode.style.display = "none";
        console.log("213213")
    }
    email = document.getElementById("4").value;
    if (!regMatch(email, REG_EMAIL)) {
        registerResult_span.parentNode.style.display = "block";
        registerResult_span.innerText = "邮箱格式错误";
        return false;
    } else {
        registerResult_span.parentNode.style.display = "none";
        console.log("1233")
    }
    address = document.getElementById("5").value;
    if (!regMatch(address, REG_ADDRESS)) {
        registerResult_span.parentNode.style.display = "block";
        registerResult_span.innerText = "地址格式错误";
        return false;
    } else {
        registerResult_span.parentNode.style.display = "none";
        console.log("1111")
    }
    //存储数据，之后负责传给xmlhttprequest（），格式必须为a="xxx"&b="xxx"&c="xxx"
    var data = 'username='
    + userName
    + '&password='
    + password1
    + '&email='
    + email
    + '&address='
    + address;
    //侦听来自id为postForm的提交事件，如果检测到，则执行postForm()函数
    document.getElementById("postForm").addEventListener("submit", postForm);
    function postForm(e) {
        e.preventDefault();
        // 一个异步请求
        let xhr = new XMLHttpRequest();
        xhr.open("POST", "/OnlineExam/php/register.php", true);
        //设置请求头
        xhr.setRequestHeader("Content-type", "application/x-www-form-urlencoded; charset=utf-8");
        xhr.onload = function () {
            console.log(this.responseText);
            if (this.responseText == "注册成功") {
                window.location.href = "/OnlineExam/pages/user/login.html";
            }
            else{
                registerResult_span.parentNode.style.display = "block";
                registerResult_span.innerText = "注册失败";
                return false;
            }
        }
        xhr.send(data);
    }

}
