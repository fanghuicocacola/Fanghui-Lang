import pickle
list1 = [1, 2, 3, 4, 'sog']
pickle_f = open('list.txt', 'wb')
pickle.dump(list1, pickle_f)
pickle_f.close()
pickle_f2 = open('list.txt', 'rb')
list2 = pickle.load(pickle_f2)
print(list2)