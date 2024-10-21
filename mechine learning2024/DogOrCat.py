import json  
import os  
import cv2  
import numpy as np  
from sklearn.model_selection import train_test_split  
from sklearn.neighbors import KNeighborsClassifier  
from sklearn.metrics import accuracy_score  
  
# 数据目录  
data_dir = 'trians\DogOrCat_trains'  
  
# 初始化特征和标签列表  
X = []  # 存储图像特征  
y = []  # 存储标签  
  
# 遍历数据目录中的JSON文件  
for json_file in os.listdir(data_dir):  
    if json_file.endswith('.json'):  
        json_path = os.path.join(data_dir, json_file)  
        with open(json_path, 'r') as f:  
            data = json.load(f)  
          
        # 提取图像路径和标签  
        image_path = os.path.join(data_dir, data['imagePath'])  
        is_cat = data['flags']['cat']  
        is_dog = data['flags']['dog']  
          
        # 检查标签有效性（这里假设图像要么是猫要么是狗，不会是两者都不是）  
        if not (is_cat or is_dog):  
            continue  # 跳过无效标签的图像  
          
        # 读取和预处理图像  
        image = cv2.imread(image_path)  
        if image is None:  
            continue  # 跳过无法读取的图像  
          
        # 转换为灰度图像并调整大小  
        gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)  
        resized_image = cv2.resize(gray_image, (128, 128))  # 调整为128x128大小  
          
        # 展平图像为一维特征向量  
        flat_features = resized_image.flatten()  
          
        # 将特征添加到列表中  
        X.append(flat_features)  
          
        # 将标签添加到列表中（1表示狗，0表示猫）  
        y.append(1 if is_dog else 0)  
  
# 将特征和标签转换为NumPy数组  
X = np.array(X)  
y = np.array(y)  
  
# 拆分数据集为训练集和测试集  
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)  
  
# 训练KNN模型  
knn = KNeighborsClassifier(n_neighbors=3)  # 可以调整k值  
knn.fit(X_train, y_train)  
  
# 使用测试集进行预测  
y_pred = knn.predict(X_test)  
  
# 计算并打印准确率  
accuracy = accuracy_score(y_test, y_pred)  
print(f'Accuracy: {accuracy * 100:.2f}%')