import urllib.request
import re


def open_url(url):
    req = urllib.request.Request(url)
    req.add_header('User-Agent',
                   'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/83.0.4103.116 Safari/537.36 Edg/83.0.478.56')
    resp = urllib.request.urlopen(req)
    html = resp.read().decode('utf-8')
    return html


def get_img(html):
    p = r'<img class="BDE_Image" height="..." src="([^"]+\.jpg)"'
    imglist = re.findall(p, html)
    for each in imglist:
        print(each)
        filename = each.split('/')[-1]
        urllib.request.urlretrieve(each, filename)


if __name__ == '__main__':
    url = 'https://tieba.baidu.com/p/2555125530'
    get_img(open_url(url))