import urllib.request
import random
my_headers = ["Mozilla/5.0 (Windows NT 6.3; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/39.0.2171.95 Safari/537.36","Mozilla/5.0 (Macintosh; Intel Mac OS X 10_9_2) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/35.0.1916.153 Safari/537.36","Mozilla/5.0 (Windows NT 6.1; WOW64; rv:30.0) Gecko/20100101 Firefox/30.0""Mozilla/5.0 (Macintosh; Intel Mac OS X 10_9_2) AppleWebKit/537.75.14 (KHTML, like Gecko) Version/7.0.3 Safari/537.75.14","Mozilla/5.0 (compatible; MSIE 10.0; Windows NT 6.2; Win64; x64; Trident/6.0)"]
randdom_header=random.choice(my_headers)
proxy_support = urllib.request.ProxyHandler({'https': '101.254.136.130:443'})
opener = urllib.request.build_opener(proxy_support)
opener.addheaders = [("User-Agent", randdom_header)]
urllib.request.install_opener(opener)
resp = urllib.request.urlopen("https://www.whatismyip.com")
html = resp.read().decode('utf-8')
print(html)
