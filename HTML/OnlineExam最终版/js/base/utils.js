
/**
 * 正则表达式
 * */

function regMatch(param, strRegex) {
    var re = new RegExp(strRegex);
    if (re.test(param)) {
        return true;
    } else {
        return false;
    }
}

/**
 * ajax
 */
function ajax(method, url, isAsync,
    isCache, data, fileKey, file, succFunc, errorFunc) {
        
    let xmlhttprequest = null;
    // 判断是不是IE浏览器
    if (window.ActiveXObject) {
        xmlhttprequest = new ActiveXObject("Microsoft.XMLHTTP");
    } else {
        xmlhttprequest = new XMLHttpRequest();
    }


    // 设置参数
    // xmlhttprequest.onreadystatechange = onResponse(xmlhttprequest,succFunc, errorFunc);
    xmlhttprequest.onreadystatechange = function () {
        onResponse(xmlhttprequest, succFunc, errorFunc);
    }
    xmlhttprequest.open(method, url, isAsync);

    //是否缓存，需要在open后使用
    if (!isCache) {
        xmlhttprequest.setRequestHeader("Cache-Control", "no-cache");//阻止浏览器读取缓存
    }

    //解析数据
    var formData = jsonKeyValue(data);

    // 请求头设置 传输简单数据
    if (file == null) {
        xmlhttprequest.setRequestHeader('content-type',
            'application/x-www-form-urlencoded');

    }
    // 传输文件
    else {
        formData.append(fileKey, file);
    }
    xmlhttprequest.send(formData);
}

/**
 * XMLHttpRequest对象的5种状态：

    0：初始化未完成状态，只是创建了XMLHttpRequest对象，还未调用open()方法；
    1：请求已开始，open()方法已调用，但还没调用send()方法；
    2：请求发送完成状态，send()方法已调用；
    3：开始读取服务器响应；
    4：读取服务器响应结束。 
 */
function onResponse(xmlhttprequest, succFunc, errorFunc) {
    if (xmlhttprequest.readyState == 4) { // XMLHttpRequest的就绪状态码，对象读取响应结束
        if (xmlhttprequest.status == 200) { // http的状态码，服务器响应正常
            succFunc(xmlhttprequest);
        } else {
            errorFunc(xmlhttprequest);
        }
    }
}


/**
 * 解析json的键值对
 */
function jsonKeyValue(data) {
    var jsonObj = JSON.parse(data);
    var formData = new FormData();
    for (var key in jsonObj) {
        formData.append(key, jsonObj[key]);
    }
    return formData;
}


