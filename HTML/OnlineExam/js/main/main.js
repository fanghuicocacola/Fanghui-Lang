// 选择器
let link_singleChoice_selector = "#link-single-choice";
let link_judgment_selector = "#link-judgment";
let link_shortanswer_selector = "#link-shortanswer";

let questions_iframe_selector = "#page iframe";

// 标签
let singleChoice_div = document.querySelector(link_singleChoice_selector);
let judgment_div = document.querySelector(link_judgment_selector);
let shortanswer_div = document.querySelector(link_shortanswer_selector);
let questions_iframe = document.querySelector(questions_iframe_selector);

//变量
var linkArr = [singleChoice_div, judgment_div,shortanswer_div ];

// singleChoice_span.onclick =  goQuestionPage(event);
for (var i = 0; i < linkArr.length; i++) {
    linkArr[i].onclick = function (event) {
        goQuestionPage(event)
    };

    for (var j = 0; j < linkArr[i].children.length; j++) {
        linkArr[i].children[j].onclick = function (event) {
            goQuestionPage(event)
        };
    }
}

//取出的是key
// for (var obj in linkArr) {
//     console.log(obj);
//     obj.onclick = function (event) {
//         goQuestionPage(event)
//     };
// }

function goQuestionPage(event) {
    //处理样式
    var linkDivs = document.querySelectorAll("#slide-links > div");
    for (var i = 0; i < linkDivs.length; i++) {
        // console.log(linkDivs[i]);
        linkDivs[i].removeAttribute("class");
    }

    //跳转
    var url = event.currentTarget.getAttribute("url");
    if (url != null) {

        //不能放在if外，否则子标签也会应用该样式
        event.currentTarget.setAttribute("class", "slide-links-div-clicked");

        console.log(url);
        questions_iframe.src = url;

        //首次onload高度小70px
        questions_iframe.onload = function () {
            setIframeHeight(questions_iframe);

            setTimeout(function(){
                setIframeHeight(questions_iframe);
            },500);
        };
       
    }
}


function setIframeHeight(iframe) {
    if (iframe) {
        var iframeDocument = iframe.contentWindow.document || iframe.contentDocument;
        if (iframeDocument.body) {
            iframe.height = iframeDocument.documentElement.scrollHeight
                || iframeDocument.body.scrollHeight;
        }
    }
    console.log("iframe高度："+iframe.height);
};


// 对iframe无效，在标签上定义有效
// questions_iframe.onload = function () {
//     setIframeHeight(questions_iframe);
// };

// 计时器
let maxtime;
if(window.name==''){ 
 maxtime = 10*60;
 }else{
 maxtime = window.name;
}
  
function CountDown(){
 if(maxtime>=0){
 minutes = Math.floor(maxtime/60);
 seconds = Math.floor(maxtime%60);
 msg = "考试剩余时间："+minutes+"分"+seconds+"秒";
// document.all["timer"].innerHTML = msg;
 document.getElementById("timer").innerHTML = msg;
 if(maxtime == 5*60) alert('注意，还有5分钟!');
 --maxtime;
 window.name = maxtime; 
 }
 else{
 clearInterval(timer);
 alert("考试时间到，结束!");
 }
}
timer = setInterval("CountDown()",1000);

// 交卷
function submitTest(){
    alert("交卷成功");
    window.location.href = "/OnlineExam/pages/user/login.html";
}
