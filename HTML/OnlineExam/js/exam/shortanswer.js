//变量
const questionsArr = (function () {
    var objArr = new Array();

    let obj1 = new Object();
    obj1.id = 1;
    obj1.stem = "HTML5 之前的 HTML 版本是？";
    obj1.answer = "HTML 4.01";

    let obj2 = new Object();
    obj2.id = 2;
    obj2.stem = "HTML5 的正确 doctype 是？";
    obj2.answer = "<!DOCTYPE HTML5>";

    let obj3 = new Object();
    obj3.id = 2;
    obj3.stem = "在 HTML5 中，哪个元素用于组合标题元素？";
    obj3.answer = "<headings>";

    for (var i = 0; i < 30; i = i + 3) {
        objArr[i] = obj1;
        objArr[i + 1] = obj2;
        objArr[i + 2] = obj3;
    }
    // console.log(objArr);

    return objArr;

})();

//选择器
let question_table_selector = "#shortanswer-questions-table";
let footer_span_indicator_selector = "#footer span:first-child";
let footer_span_pre_selector = "#footer>div span:first-of-type";
let footer_span_next_selector = "#footer>div span:last-of-type";
let timeDown_span_selector = "#timeDown-span";

// 标签
let question_table = document.querySelector(question_table_selector);
let spanIndicator = document.querySelector(footer_span_indicator_selector);
let spanPre = document.querySelector(footer_span_pre_selector);
let spanNext = document.querySelector(footer_span_next_selector);
let timeDown_span = document.querySelector(timeDown_span_selector);

// 变量
let curPage = 0;
let pageSize = 10;
let pageCount = Math.ceil(questionsArr.length * 1.0 / pageSize);

//分页函数
function getQuestionsPager(curPage, pageSize) {
    var startIndex = curPage * pageSize;
    var endIndex = startIndex + pageSize;

    var arrPager = questionsArr.slice(startIndex, endIndex);
    // console.log(arrPager);
    return arrPager;
}

// 生成table内容
function createTable(arrPager) {
    var bodyEle = question_table.querySelector("tbody");

    //分页，先删除之前所有子元素
    bodyEle.innerHTML = "";

    for (var i = 0; i < arrPager.length; i++) {
        var trEle = document.createElement("tr");

        //第1列
        var tdQuestion = document.createElement("td");
        //题干
        var spanStem = document.createElement("span");
        spanStem.innerText = i + 1 + ". " + arrPager[i].stem;
        tdQuestion.appendChild(spanStem);
        tdQuestion.appendChild(document.createElement("br"));  //换行
        

        trEle.appendChild(tdQuestion);

        //第2列
        
        var myText = document.createElement("TEXTAREA");
        myText.style.minWidth = "100%";
        myText.style.maxWidth = "100%";
        myText.style.minHeight = "100px";
        myText.style.maxHeight = "100px";
        myText.style.fontSize = "20px";
        myText.style.overflow = "auto";
        myText.id = "myText"+i;
        document.body.appendChild(myText);
        tdQuestion.appendChild(myText);
        bodyEle.appendChild(trEle);
    }
}

//注册事件
spanPre.onclick = function (event) {
    if (curPage == 0) {
        alert("当前已经是第一页");
        return;
    }
    let arrPager = getQuestionsPager(--curPage, 10);
    createTable(arrPager);

    //滚动回到顶部
    var parentHtml = window.parent.document.querySelector("html");
    parentHtml.scrollTop = 0;

    spanIndicator.innerText = "共" + pageCount + "页，当前是第 " + (curPage + 1) + " 页";

}

spanNext.onclick = function (event) {
    if ((curPage + 1) * pageSize == questionsArr.length) {
        alert("当前已经是最后一页");
        spanNext.setAttribute("class", "switch-page-span-disabled");
        return;
    }
    let arrPager = getQuestionsPager(++curPage, 10);
    createTable(arrPager);

    //滚动回到顶部
    var parentHtml = window.parent.document.querySelector("html");
    parentHtml.scrollTop = 0;

    spanIndicator.innerText = "共" + pageCount + "页，当前是第 " + (curPage + 1) + " 页";
}


//默认加载0-9条数据
let arrPager = getQuestionsPager(curPage, 10);
createTable(arrPager);
spanIndicator.innerText = "共" + pageCount + "页，当前是第 " + (curPage + 1) + " 页";


//倒计时
let timeCount = 90 * 60;
setInterval(function () {
    timeDown_span.innerText = "距离考试结束，还有" + (--timeCount) + "秒";
    if (timeCount == 0) {
        //交卷
    }
}, 1000);
