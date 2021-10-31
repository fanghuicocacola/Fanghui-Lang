let dataTable = document.getElementById("table-wrapper").children[1];
// console.log(dataTable);
let tBody = dataTable.querySelector("#table-wrapper tbody");

var stuArr = ["123456789", "小明", "计算机学院", "网络工程", "191", "1"];
var stuArr2 = ["123123123", "小红", "计算机学院", "网络工程", "192", "2"];
var stuArr3 = ["222222222", "小王", "计算机学院", "计算机科学与技术", "191", "1"];
var stuArr4 = ["333333333", "小芳", "电气学院", "网络工程", "191", "1"];

createData(stuArr);
createData(stuArr2);
createData(stuArr3);
createData(stuArr4);

function createData(stuArr) {
    for (var i = 0; i < 5; i++) {
        var trNode = document.createElement("tr");

        var temp = 0;

        var tdNodeNum = document.createElement("td");
        tdNodeNum.innerText = i;
        trNode.appendChild(tdNodeNum);

        var tdNodeID = document.createElement("td");
        tdNodeID.innerText = stuArr[temp++];
        trNode.appendChild(tdNodeID);

        var tdNodeName = document.createElement("td");
        tdNodeName.innerText = stuArr[temp++];
        trNode.appendChild(tdNodeName);

        var tdNodeDepartment = document.createElement("td");
        tdNodeDepartment.innerText = stuArr[temp++];
        trNode.appendChild(tdNodeDepartment);

        var tdNodeMajor = document.createElement("td");
        tdNodeMajor.innerText = stuArr[temp++];
        trNode.appendChild(tdNodeMajor);

        var tdNodeGrade = document.createElement("td");
        tdNodeGrade.innerText = stuArr[temp++];
        trNode.appendChild(tdNodeGrade);

        var tdNodeClass = document.createElement("td");
        tdNodeClass.innerText = stuArr[temp++];
        trNode.appendChild(tdNodeClass);

        tBody.appendChild(trNode);
    }
}

function filter(event) {
    var inputValue = event.target.value;
    var count = tBody.children.length;

    for (var i = 0; i < count; i++) {
        var text = tBody.children[i].innerText;

        if (text.indexOf(inputValue) == -1) {
            /* 
            *  display: none;
            *  visibility: hidden; 
            */
            tBody.children[i].style.display = "none";
        }else{
            var cssEle = tBody.children[i].style;
            cssEle.removeProperty("display");
        }

        if (inputValue == null || inputValue == "") {
            var cssEle = tBody.children[i].style;
            cssEle.removeProperty("display");
        }

        // console.log(inputValue);
    }
}

function selectText(event) {
    event.target.select();
}
