//变量
const questionsArr = (function () {
    var objArr = new Array();

    let obj1 = new Object();
    obj1.id = 1;
    obj1.stem = "表单的method属性默认值是POST";
    var choicesArr1 = new Array();
    choicesArr1[0] = "正确";
    choicesArr1[1] = "错误";
    obj1.choices = choicesArr1
    obj1.answer = 1;

    let obj2 = new Object();
    obj2.id = 2;
    obj2.stem = "JavaScript语法不用区分大小";
    var choicesArr2 = new Array();
    choicesArr2[0] = "正确";
    choicesArr2[1] = "错误";
    obj2.choices = choicesArr2
    obj2.answer = 2;

    let obj3 = new Object();
    obj3.id = 2;
    obj3.stem = "file类型的input只能实现单文件上传";
    var choicesArr3 = new Array();
    choicesArr3[0] = "正确";
    choicesArr3[1] = "错误";
    obj3.choices = choicesArr3
    obj3.answer = 3;
    for (var i = 0; i < 30; i = i + 3) {
        objArr[i] = obj1;
        objArr[i + 1] = obj2;
        objArr[i + 2] = obj3;
    }
    // console.log(objArr);
    return objArr;
})();

//选择器
let question_table_selector = "#judgment-questions-table";
let footer_span_indicator_selector = "#footer span:first-child";
let footer_span_pre_selector = "#footer>div span:first-of-type";
let footer_span_next_selector = "#footer>div span:last-of-type";
//let timeDown_span_selector = "#timer";

// 标签
let question_table = document.querySelector(question_table_selector);
let spanIndicator = document.querySelector(footer_span_indicator_selector);
let spanPre = document.querySelector(footer_span_pre_selector);
let spanNext = document.querySelector(footer_span_next_selector);
//let timer = document.querySelector(timer_selector);

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
        trEle.appendChild(tdQuestion);
        //第2列
        var mySelect = document.createElement("select");
        mySelect.id = "mySelect"+i;
        document.body.appendChild(mySelect);
        var obj = document.getElementById('mySelect'+i);
        //添加一个选项
        obj.add(new Option(" ", " ")); 
        obj.add(new Option("A", "A"));
        obj.add(new Option("B", "B"));
        trEle.appendChild(mySelect);
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

//地址
var url = base_url + judgment_url;
//保存答案的数组
var selection = new Array();
var j, x;
//将答案实时存入数组
for (var i = 0; i < 30; i++) {
    //题号
    j = i + 1;
    x = document.getElementById("mySelect" + i).Value;
    selection.push({ "testid": j, "input": x });
}
$.ajax({
    url,	//上传URL
    type: "POST", //请求方式
    data: {
        "test": "judgment",
        "selection": JSON.stringify(judgment),//将数组转化成json字符串
        dataType: "JSON", //设置接受到的响应数据的格式
    },
    function(xmlhttprequest) {
        var resJson = JSON.parse(rs);
        console.log(resJson.resMsg);

        if (resJson.resCode == 1) {
            
        }
    },
    function(xmlhttprequest) {
    }
})
