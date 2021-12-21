// 选择器
let link_singleChoice_selector = "#link-single-choice";
let link_judgment_selector = "#link-judgment";
let questions_iframe_selector = "#page iframe";

// 标签
let singleChoice_div = document.querySelector(link_singleChoice_selector);
let judgment_div = document.querySelector(link_judgment_selector);
let questions_iframe = document.querySelector(questions_iframe_selector);

//变量
var linkArr = [singleChoice_div, judgment_div];

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
