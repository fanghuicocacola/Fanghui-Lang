import urllib.request
response = urllib.request.urlopen("http://placekitten.com/g/300/400")
cat_img = response.read()

with open('cat_300_400.jpg','wb') as f:
    f.write(cat_img)
