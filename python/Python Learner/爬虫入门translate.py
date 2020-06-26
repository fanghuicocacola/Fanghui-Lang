import urllib.request
import urllib.parse
import json
text = input("请输入需要翻译的内容：")
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
resp = urllib.request.urlopen(url, date)
html = resp.read().decode('utf-8')
target = json.loads(html)
print('翻译结果: ', target['translateResult'][0][0]['tgt'])