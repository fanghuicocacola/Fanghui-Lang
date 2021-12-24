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
    //function doSave() {
       // var val=$('#v'+testId+' textarea').val();
        //$.ajax({
         // type: "POST",
         // url: "/saveAnswer",
         // contentType: "application/json",
         // data: JSON.stringify({
           // 'testId': testId,
           // 'answer': '<pre>'+val+'</pre>'
         // }),
         // success: function (data) {
           //  console.log("save success");
           //  setTimeout(doSave,60*1000);
         // }
        //});
      
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
//let timeCount = 90 * 60;
//setInterval(function () {
  // timeDown_span.innerText = "距离考试结束，还有" + (--timeCount) + "秒";
   // if (timeCount == 0) {
       // 交卷
   // }
//}, 1000);
//let times = 60 * 60;//剩余时间,单位秒
    //let timeDiv = document.getElementById("time");
  // let timeObj = null;
//function timer(){
       // if(times == 0){
            //倒计时结束，提交表单
           //document.getElementById("frm").submit();
           // window.clearInterval(timeObj);
//return;
       // }
       // let t = Math.floor(times/60) +"分"+times%60+"秒"
       // timeDiv.innerHTML = t;
       // times --;
    //}
   // timeObj = window.setInterval(timer,1000);
