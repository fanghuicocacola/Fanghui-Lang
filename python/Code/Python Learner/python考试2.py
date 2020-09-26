# 打印一个指定容量的进度条
import sys
import time
def ProgressBar(num):
    """
    :param num: 传入进度条总量值
    :return:
    """
    total = 20  # 进度条长度共20个“#”
    if num == 0:
        print('传入参数不可为0，仅接受int类型')
    elif type(num) != int:
        print('传入参数仅接受int类型')
    else:
        for item in range(num + 1):
            test_num = int((item / num) * 100)  # 当前百分比
            step = int(test_num / (100 / total))  # 一个‘#’的在100% 内的占比
            now = r"[ %s%s ]%s" % ("#" * step, ' ' * (total - step), str(test_num))
            sys.stdout.write("\r%s%%" % now)
            sys.stdout.flush()
            time.sleep(0.1)

if __name__ == '__main__':
    ProgressBar(100)
