import urllib.request
import os


def url_open(url):
    req = urllib.request.Request(url)
    req.add_header('User-Agent',
                   'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/83.0.4103.116 Safari/537.36 Edg/83.0.478.56')
    resp = urllib.request.urlopen(req)
    html = resp.read()
    return html


def get_page(num):
    num += 1
    return num


def find_imgs(url):
    html = url_open(url).decode('utf-8')
    img_adds = []
    a = html.find('img id=')
    while a != -1:
        b = html.find('.jpg', a, a+255)
        if b != -1:
            img_adds.append(html[a+8, b+4])
        else:
            b = a + 8
        a = html.find('img id=', b)
    return img_adds


def save_imgs(folder, img_adds):
    for each in img_adds:
        file = each.split('/')[-1]
    with open(file, 'wb') as f:
        img = url_open(img_adds)
        f.write(img)


def download_page(folder='arts', pages=10):
    os.mkdir(folder)
    os.chdir(folder)
    url = 'http://www.uuhuaku.com/'
    page_num = int(get_page(x))
    for i in range(pages):
        page_num -= i
        page_url = url + 'uua/buyrent?id=' + str(page_num)
        img_adds = find_imgs(page_url)
        save_imgs(folder, img_adds)


if __name__ == '__main__':
    x = 1000
    get_page(x)
    download_page()
