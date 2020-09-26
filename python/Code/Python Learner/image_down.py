import requests
import time
from lxml import etree
import urllib

headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.25 Safari/537.36 Core/1.70.3756.400 QQBrowser/10.5.4039.400'
}

num = 1000

def geturl(num):

        url = f'http://www.uuhuaku.com/uua/buyrent?id={num}'

        res = requests.get(url, headers=headers, params=None)

        if res.status_code ==200 :

            html = res.content.decode('utf-8')
            html = etree.HTML(html)
            #获取图片url
            image =html.xpath('//*[@id="buyrent-Left-Img-Box"]/img/@src')
            # 获取标题url
            title = html.xpath('//*[@id="buyrent-Right-PaintingName"]/text()')
            #成功获取时，下载
            if len(image) > 0 and len(title) > 0 :
                print(num,'-',title[0],'-',image[0])
                path = title[0]+'.jpg'
                urllib.request.urlretrieve(image[0],path)



for i in range(1,100,2):
    geturl(num+i)