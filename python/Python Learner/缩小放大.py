from PIL import Image
import numpy as np
import os
import imageio
image = Image.open('ball.png')
bgh = 500
bgw = 500
path = 'img/'


def image_paste(image):
    ret = Image.new('RGB', (bgh, bgw), (0, 255, 255))
    w = image.size[0]
    h = image.size[1]
    ret.paste(image, (int((bgw-w)/2), int(bgh-h)))
    return ret


def func():
    f_path = 'img'
    imgList = os.listdir(f_path)
    imgList = sorted(imgList, key=lambda x: os.path.getmtime(os.path.join(f_path, x)))
    imgList = [f_path + '/' + img for img in imgList]
    gifList = [imageio.imread(img) for img in imgList]
    imageio.mimwrite('ac.gif', gifList, duration=0.15)

if __name__ == '__main__':
    for i in range(1,30):
        rew = int(image.size[0] * i / 30)
        reh = int(image.size[0] * i / 30)
        img = image.resize((rew,reh))
        img.show()
        img = image_paste(img)
        img.save(path+str(i)+'.png')
        func()
