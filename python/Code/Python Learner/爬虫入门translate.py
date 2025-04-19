import urllib.request
import urllib.parse
import json
import time

head = {}
while True:
    text = input("请输入需要翻译的内容：Q退出：")
    if text == 'Q':
        break
    else:
        url = 'http://fanyi.youdao.com/translate?smartresult=dict&smartresult=rule'
        date = {}
        date['i'] = text
        date['type'] = 'AUTO'
        date['smartresult'] = 'dict'
        date['client'] = 'fanyideskweb'
        date['salt'] = '15931738292459'
        date['sign'] = '976ba7f17a664b448edb5f9d141d7d5a'
        date['ts'] = '1593173829245'
        date['bv'] = '02a6ad4308a3443b3732d855273259bf'
        date['doctype'] = 'json'
        date['version'] = '2.1'
        date['keyfrom'] = 'fanyi.web'
        date['action'] = 'FY_BY_REALTlME'
        date = urllib.parse.urlencode(date).encode('utf-8')
        req = urllib.request.Request(url, date)
        req.add_header('User-Agent', 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/83.0.4103.116 Safari/537.36')
        resp = urllib.request.urlopen(req)
        html = resp.read().decode('utf-8')
        target = json.loads(html)
        print('翻译结果: ', target['translateResult'][0][0]['tgt'])
        time.sleep(2)