//变量
const questionsArr = (function () {
    var objArr = new Array();

    let obj1 = new Object();
    obj1.id = 1;
    obj1.stem = "HTML5 之前的 HTML 版本是？";
    var choicesArr1 = new Array();
    choicesArr1[0] = "HTML 4.01";
    choicesArr1[1] = "HTML 4";
    choicesArr1[2] = "HTML 4.1";
    choicesArr1[3] = "HTML 4.9";
    obj1.choices = choicesArr1
    obj1.answer = 1;

    let obj2 = new Object();
    obj2.id = 2;
    obj2.stem = "HTML5 的正确 doctype 是？";
    var choicesArr2 = new Array();
    choicesArr2[0] = "<!DOCTYPE html>";
    choicesArr2[1] = "<!DOCTYPE HTML5>";
    choicesArr2[2] = "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 5.0//EN\" \"http://www.w3.org/TR/html5/strict.dtd\">";
    choicesArr2[3] = "<DOCTYPE HTML5>";
    obj2.choices = choicesArr2
    obj2.answer = 2;

    let obj3 = new Object();
    obj3.id = 3;
    obj3.stem = "在 HTML5 中，哪个元素用于组合标题元素？";
    var choicesArr3 = new Array();
    choicesArr3[0] = "<group>";
    choicesArr3[1] = "<header>";
    choicesArr3[2] = "<headings>";
    choicesArr3[3] = "<hgroup>";
    obj3.choices = choicesArr3
    obj3.answer = 3;

    let obj4 = new Object();
    obj4.id = 4;
    obj4.stem = "下面定义HTML注释正确的是";
    var choicesArr4 = new Array();
    choicesArr3[0] = "<div><!--这里是注释--><\div>";
    choicesArr3[1] = "<div><!--这里是注释--></div>";
    choicesArr3[2] = "<!--<!--这里是注释-->-->";
    choicesArr3[3] = "<div><--这里是注释--></div>";
    obj4.choices = choicesArr4
    obj4.answer = 4;

    let obj5 = new Object();
    obj5.id = 5;
    obj5.stem = "为使输入框自动获得焦点，可以添加属性";
    var choicesArr5 = new Array();
    choicesArr3[0] = "required";
    choicesArr3[1] = "autofocus";
    choicesArr3[2] = "autocomplete";
    choicesArr3[3] = "autoselected";
    obj5.choices = choicesArr5
    obj5.answer = 5;

    let obj6 = new Object();
    obj6.id = 6;
    obj6.stem = "input的type值，不能是以下哪个值";
    var choicesArr6 = new Array();
    choicesArr3[0] = "text";
    choicesArr3[1] = "hidden";
    choicesArr3[2] = "reset";
    choicesArr3[3] = "textarea";
    obj6.choices = choicesArr6
    obj6.answer = 6;

    let obj7 = new Object();
    obj7.id = 7;
    obj7.stem = "表单的enctype属性，上传文件，应该取值为";
    var choicesArr7 = new Array();
    choicesArr3[0] = "application/x-www-form-urlencoded";
    choicesArr3[1] = "multipart/form-data";
    choicesArr3[2] = " text/plain";
    choicesArr3[3] = "text/json ";
    obj7.choices = choicesArr7
    obj7.answer = 7;

    let obj8 = new Object();
    obj8.id = 8;
    obj8.stem = "window对象的方法中，哪个方法是用于弹出确认对话框，可让选择“确定”或“取消”";
    var choicesArr8 = new Array();
    choicesArr3[0] = " open()";
    choicesArr3[1] = " prompt()";
    choicesArr3[2] = " confirm()";
    choicesArr3[3] = "alert() ";
    obj8.choices = choicesArr8
    obj8.answer = 8;

    let obj9 = new Object();
    obj9.id = 9;
    obj9.stem = "在 HTML5 中，哪个元素用于组合标题元素？";
    var choicesArr9 = new Array();
    choicesArr3[0] = "<group>";
    choicesArr3[1] = "<header>";
    choicesArr3[2] = "<headings>";
    choicesArr3[3] = "<hgroup>";
    obj9.choices = choicesArr9
    obj9.answer = 9;

    let obj10 = new Object();
    obj10.id = 10;
    obj10.stem = "JavaScript中，0/0的结果为";
    var choicesArr10 = new Array();
    choicesArr3[0] = "infinity";
    choicesArr3[1] = "-infinity";
    choicesArr3[2] = "NaN";
    choicesArr3[3] = "出错";
    obj10.choices = choicesArr10
    obj10.answer = 10;

    let obj11 = new Object();
    obj11.id = 11;
    obj11.stem = "JavaScript变量声明，不能使用以下哪个关键字";
    var choicesArr11 = new Array();
    choicesArr3[0] = "var";
    choicesArr3[1] = "const";
    choicesArr3[2] = "int";
    choicesArr3[3] = "let";
    obj11.choices = choicesArr11
    obj11.answer = 11;

    for (var i = 0; i < 30; i = i + 3) {
        objArr[i] = obj1;
        objArr[i + 1] = obj2;
        objArr[i + 2] = obj3;
        objArr[i + 3] = obj4;
        objArr[i + 4] = obj5;
        objArr[i + 5] = obj6;
        objArr[i + 6] = obj7;
        objArr[i + 7] = obj8;
        objArr[i + 8] = obj9;
        objArr[i + 9] = obj10;
        objArr[i + 10] = obj11;
    }
    // console.log(objArr);

    return objArr;

})();

//选择器
let question_table_selector = "#singleChoice-questions-table";
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
        //选项A
        var spanChoiceA = document.createElement("span");
        spanChoiceA.innerText = "A. " + arrPager[i].choices[0];
        tdQuestion.appendChild(spanChoiceA);
        tdQuestion.appendChild(document.createElement("br")); //换行
        //选项B
        var spanChoiceB = document.createElement("span");
        spanChoiceB.innerText = "B. " + arrPager[i].choices[1];
        tdQuestion.appendChild(spanChoiceB);
        tdQuestion.appendChild(document.createElement("br")); //换行
        //选项C
        var spanChoiceC = document.createElement("span");
        spanChoiceC.innerText = "C. " + arrPager[i].choices[2];
        tdQuestion.appendChild(spanChoiceC);
        tdQuestion.appendChild(document.createElement("br"));  //换行
        //选项D
        var spanChoiceD = document.createElement("span");
        spanChoiceD.innerText = "D. " + arrPager[i].choices[3];
        tdQuestion.appendChild(spanChoiceD);

        trEle.appendChild(tdQuestion);

        //第2列
        var tdAnswer = document.createElement("td");
        tdAnswer.setAttribute("class", "td-answer");
        var inputEle = document.createElement("input");
        tdAnswer.appendChild(inputEle);
        trEle.appendChild(tdAnswer);

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
