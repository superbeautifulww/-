import matplotlib.pyplot as plt

from svm_softmax_sgd import *

# 加载数据集
root = 'D:/CVML/RS32/all'
X,Y=load_data(root)

#数据集划分
num_train=int(len(X)*0.6)
num_val=int(len(X)*0.1)
num_test=int(len(X)*0.3)
Xtrain=X[:num_train]
Ytrain=Y[:num_train]
Xval=X[num_train:num_train+num_val]
Yval=Y[num_train:num_train+num_val]
Xtest=X[num_train+num_val:]
Ytest=Y[num_train+num_val:]

#记录训练样本均值
temp = np.reshape(Xtrain, (Xtrain.shape[0], -1))
mean_image = np.mean(temp, axis=0)

print('Xtrain.shape:',Xtrain.shape)
print('Ytrain.shape:',Ytrain.shape)
print('Xval.shape:',Xval.shape)
print('Yval.shape:',Yval.shape)
print('Xtest.shape:',Xtest.shape)
print('Ytest.shape:',Ytest.shape)

#数据显示
plt.rcParams['figure.figsize']=(12.0,6.0)
plt.rcParams.update({'font.size': 8})
plt.rcParams['image.interpolation']='nearest'
plt.rcParams['image.cmap']='gray'


visualize_samples(classes,Xtrain,Ytrain)

#数据预处理
Xtrain,Xval,Xtest=data_processing(Xtrain,Xval,Xtest)

print('Xtrain.shape:',Xtrain.shape)
print('Ytrain.shape:',Ytrain.shape)
print('Xval.shape:',Xval.shape)
print('Yval.shape:',Yval.shape)
print('Xtest.shape:',Xtest.shape)
print('Ytest.shape:',Ytest.shape)

#比较数值梯度与解析梯度
W=np.random.randn(Xtrain.shape[1],len(classes))*0.0001
svm_grad_check(W,Xtrain[:100,:],Ytrain[0:100])
softmax_grad_check(W,Xtrain[:100,:],Ytrain[0:100])

#训练简单分类器并比较运行时间
plt.rcParams['figure.figsize']=(10.0,8.0)
plt.rcParams['image.interpolation'] ='nearest'
plt.rcParams['image.cmap']='gray'
svm=train_a_simple_svm(Xtrain,Ytrain)
softmax=train_a_simple_softmax(Xtrain,Ytrain)

#训练并找到最佳精度的SVM和Softmax分类器
best_val,best_svm,best_loss_hist=train_and_get_best_svm(Xtrain,Ytrain,Xval,Yval)
best_val,best_softmax,best_loss_hist=train_and_get_best_softmax(Xtrain,Ytrain,Xval,Yval)
y_svm_pred=best_svm.predict(Xtest)
y_acc_svm=best_svm.eval(Ytest,y_svm_pred)

y_softmax_pred=best_softmax.predict(Xtest)
y_acc_softmax=best_softmax.eval(Ytest,y_softmax_pred)
print("best validation svm scroces %f at test data",np.mean(Ytest==y_svm_pred))
print("best validation softmax scroces %f at test data",np.mean(Ytest==y_softmax_pred))


#权重可视化

plt.rcParams['figure.figsize']=(15.0,8.0)
plt.rcParams['image.interpolation']='nearest'
plt.rcParams['image.cmap']='gray'

visualize_learned_weights(best_svm,classes)

#数据集划分
root = 'D:/CVML/RS32/val'
Xtest,Ytest=load_data(root)


Xtest = np.reshape(Xtest, (Xtest.shape[0], -1))
Xtest -= mean_image
Xtest = np.hstack([Xtest, np.ones((Xtest.shape[0], 1))])

plt.rcParams['figure.figsize']=(15.0,7.0)
plt.rcParams['image.interpolation']='nearest'
plt.rcParams['image.cmap']='gray'
plt.rcParams.update({'font.size': 7})

visualize_predictions(Xtest, Ytest, best_svm,mean_image)
visualize_predictions(Xtest, Ytest, best_softmax,mean_image)