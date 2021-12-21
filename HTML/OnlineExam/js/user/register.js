// 选择器
/*
let userName_input_selector = "#input-root-div input:nth-of-type(1)";
let password1_input_selector = "#input-root-div input:nth-of-type(2)";
let password2_input_selector = "#input-root-div input:nth-of-type(3)";
let email_input_selector = "#input-root-div input:nth-of-type(4)";
let address_input_selector = "#input-root-div input:nth-of-type(5)";
*/

let registerResult_span_selector = "#register-result-div span";
let registerBtn_selector = "#register-btn";

// 标签
/*
let userName_input = document.querySelector(userName_input_selector);
let password1_input = document.querySelector(password1_input_selector);
let password2_input = document.querySelector(password2_input_selector);
let email_input = document.querySelector(email_input_selector);
let address_input = document.querySelector(address_input_selector);
*/
let registerResult_span = document.querySelector(registerResult_span_selector);
let register_btn = document.querySelector(registerBtn_selector);

// 变量
let userName, password1, password2, email, address;

/* 密码强度检验 */
/*移出时正确绿字or错误红字*/
(function () {
    var myinput = document.getElementById("2");
    myinput.addEventListener("mouseout", function () {
      //单独处理 - 使用正则表达式
      var tar = document.getElementsByClassName("plex");
      var len = tar.length;
      for (let i = 0; i < len; i++) {
        tar[i].hidden = true; //再次初始化：全部隐藏
        console.log("1");
      }
      var reg2 = /^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)[^]{6,16}$/;
      var reg1 = /^.{6,16}$/;
      if (reg2.test(myinput.value)) { //强，6-16位，必须有大小写字母和数字
        tar[2].hidden = false;
        console.log("2");
      }
      else if (reg1.test(myinput.value)) { //中，6-16位
        tar[1].hidden = false;
        console.log("3");
      }
      else { //弱
        tar[0].hidden = false;
        console.log("4");
      }
    }
    )
  })();

// 注册校验
register_btn.onclick = function (event) {

    userName = document.getElementById("1").value;
    password1 = document.getElementById("2").value;
    password2 = document.getElementById("3").value;
    if (!regMatch(userName, REG_USER_NAME)) {
        registerResult_span.parentNode.style.display = "block";
        registerResult_span.innerText = "用户名格式错误";
        return;
    } else {
        registerResult_span.parentNode.style.display = "none";
    }
    /*if (!regMatch(password1, REG_PASSWORD)) {
        registerResult_span.parentNode.style.display = "block";
        registerResult_span.innerText = "密码格式错误";
        return;
    }
    */
    if (password1 != password2) {
        registerResult_span.parentNode.style.display = "block";
        registerResult_span.innerText = "密码不一致";
        return;
    }
    else {
        registerResult_span.parentNode.style.display = "none";
        console.log("213213")
    }
    email = document.getElementById("4").value;
    if (!regMatch(email, REG_EMAIL)) {
        registerResult_span.parentNode.style.display = "block";
        registerResult_span.innerText = "邮箱格式错误";
        return;
    } else {
        registerResult_span.parentNode.style.display = "none";
        console.log("1233")
    }
    address = document.getElementById("5").value;
    if (!regMatch(address, REG_ADDRESS)) {
        registerResult_span.parentNode.style.display = "block";
        registerResult_span.innerText = "地址格式错误";
        return;
    } else {
        registerResult_span.parentNode.style.display = "none";
        console.log("1111")
    }
    var url = base_url + login_url;
    var data = '{"userName":"' + userName + '", "password":' + '"' + password1 + '" + "email":"' + email + '" + "address":"' + address + '"}';
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
            // JSON.stringify(jsonobj); //可以将json对象转换成json字符串 
            var resJson = JSON.parse(rs);
            console.log(resJson.resMsg);

            if (resJson.resCode == 1) {
                window.location.href = "pages/main/main.html";
            }
        },
        function (xmlhttprequest) {
        }
    );
}
// 强密码检验