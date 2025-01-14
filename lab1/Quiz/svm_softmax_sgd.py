import os
import time
import matplotlib.pyplot as plt
import numpy as np

classes = ['Waters', 'Forest', 'CultivatedLand', 'River', 'Highway', 'Pylon', 'SwimmingPool', 'TennisCourt',
           'BasketballCourt', 'FootballField']

def load_data(root):
    # *****START OF YOUR CODE (DO NOT DELETE/MODIFY THIS LINE)*****
    images = []  # 存储图像数据
    labels = []  # 存储标签数据
    #  Load image and label data
    # 遍历指定目录下的文件
    for folder_name in os.listdir(root):
        folder_path = os.path.join(root, folder_name)
        if os.path.isdir(folder_path):
            if folder_name[1:] in classes:
                label = classes.index(folder_name[1:])

                for image_name in os.listdir(folder_path):
                    image_path = os.path.join(folder_path, image_name)
                    if os.path.isfile(image_path) and image_name.lower().endswith(('.jpg')):
                        image = plt.imread(image_path).astype('float32')
                        images.append(image)
                        labels.append(label)
    #  format of images: np.array(n,row,col,b) 
    #  format of labels: np.array(n)
    images = np.array(images)
    labels = np.array(labels)

    #打乱顺序
    permutation = np.random.permutation(len(images))
    images = images[permutation]
    labels = labels[permutation]
    # *****END OF YOUR CODE (DO NOT DELETE/MODIFY THIS LINE)*****
    return images,labels



def visualize_samples(classes, X, Y):
    num_classes = len(classes)  
    samples_per_class = 7
    for y, cls in enumerate(classes): 
        idxs = np.flatnonzero(Y == y)
        idxs = np.random.choice(idxs, samples_per_class, replace=False)

        for i, idx in enumerate(idxs):  
            plt_idx = i * num_classes + y + 1  
            plt.subplot(samples_per_class, num_classes, plt_idx) 
            plt.imshow(X[idx].astype('uint8'))  
            plt.axis('off')
            if i == 0:
                plt.title(cls)  

    plt.show()  # 显示


def data_processing(Xtrain, Xval, Xtest):
    Xtrain = np.reshape(Xtrain, (Xtrain.shape[0], -1))
    Xval = np.reshape(Xval, (Xval.shape[0], -1))
    Xtest = np.reshape(Xtest, (Xtest.shape[0], -1))
    # Preprocessing: subtract the mean image
    
    # first: compute the image mean based on the training data
    mean_image = np.mean(Xtrain, axis=0)
    # print(mean_image[:10]) # print a few of the elements
    '''
    plt.figure(figsize=(4,4))
    plt.imshow(mean_image.reshape((32,32,3)).astype('uint8')) # visualize the mean image
    plt.show()
    '''

    # second: subtract the mean image from train and test data
    Xtrain -= mean_image
    Xval -= mean_image
    Xtest -= mean_image

    # third: append the bias dimension of ones (i.e. bias trick) so that our SVM
    # only has to worry about optimizing a single weight matrix W.
    Xtrain = np.hstack([Xtrain, np.ones((Xtrain.shape[0], 1))])
    Xval = np.hstack([Xval, np.ones((Xval.shape[0], 1))])
    Xtest = np.hstack([Xtest, np.ones((Xtest.shape[0], 1))])

    return Xtrain, Xval, Xtest


def svm_loss_naive(W, X, y, reg):
    """
    Structured SVM loss function, naive implementation (with loops).

    Inputs have dimension D, there are C classes, and we operate on minibatches
    of N examples.

    Inputs:
    - W: A numpy array of shape (D, C) containing weights.              [3073, 19]
    - X: A numpy array of shape (N, D) containing a minibatch of data.  [64, 3073]
    - y: A numpy array of shape (N,) containing training labels; y[i] = c means [64, 1]
      that X[i] has label c, where 0 <= c < C.
    - reg: (float) regularization strength

    Returns a tuple of:
    - loss as single float
    - gradient with respect to weights W; an array of same shape as W
    """
    # Initialize the loss and gradient to zero.
    loss = 0.0
    dW = np.zeros(W.shape)  # initialize the gradient as zero           [3073, 19]

    # *****START OF YOUR CODE (DO NOT DELETE/MODIFY THIS LINE)*****
    num_train = X.shape[0]
    # compute the loss and the gradient
    #求loss
    scores = np.dot(X,W)
    margins = np.maximum(0, scores - scores[range(num_train),[y]].T + 1)  #scores[range(num_train),[y]].T是n*1的矩阵
    margins[range(num_train),[y]] = 0
    loss = np.sum(margins)

    #求dW
    cur_matrix = (margins > 0).astype('float')  #0和1
    wrong_cnt = np.sum(cur_matrix, axis=1)
    cur_matrix[range(num_train), [y]] -= wrong_cnt
    dW = np.dot(X.T,cur_matrix)
    
    # Right now the loss is a sum over all training examples, but we want it
    # to be an average instead so we divide by num_train.
    loss /= num_train
    dW /= num_train
    # Add regularization to the loss.
    loss += reg * np.sum(W * W)
    dW += 2 * reg * W
    # *****END OF YOUR CODE (DO NOT DELETE/MODIFY THIS LINE)*****

    return loss, dW


def softmax_loss_naive(W, X, y, reg):
    """
    Softmax loss function, naive implementation (with loops)

    Inputs have dimension D, there are C classes, and we operate on minibatches
    of N examples.

    Inputs:
    - W: A numpy array of shape (D, C) containing weights.
    - X: A numpy array of shape (N, D) containing a minibatch of data.
    - y: A numpy array of shape (N,) containing training labels; y[i] = c means
      that X[i] has label c, where 0 <= c < C.
    - reg: (float) regularization strength

    Returns a tuple of:
    - loss as single float
    - gradient with respect to weights W; an array of same shape as W
    """
    # Initialize the loss and gradient to zero.
    loss = 0.0
    dW = np.zeros_like(W)

    #############################################################################
    # Compute the softmax loss and its gradient using explicit loops.           #
    # Store the loss in loss and the gradient in dW. If you are not careful     #
    # here, it is easy to run into numeric instability. Don't forget the        #
    # regularization!                                                           #
    #############################################################################
    # *****START OF YOUR CODE (DO NOT DELETE/MODIFY THIS LINE)*****
    num_train = X.shape[0]

    scores = np.dot(X,W)
    scores_correct = scores[range(num_train), y]

    exp_scores = np.exp(scores)  # 取幂
    sum_scores = np.sum(exp_scores)
    normalize = exp_scores / sum_scores

    loss -= np.sum(np.log(normalize[range(num_train), y]))

    loss /= num_train
    loss += reg * np.sum(W * W)

    temp = exp_scores / np.sum(exp_scores, axis=1, keepdims=True)
    temp[range(num_train), y] -= 1.0

    dW = X.T.dot(temp)

    dW /= num_train
    dW += 2 * reg * W

    # *****END OF YOUR CODE (DO NOT DELETE/MODIFY THIS LINE)*****

    return loss, dW


def svm_grad_check(W, X, Y):
    # Compute the loss and its gradient at W.
    loss, grad = svm_loss_naive(W, X, Y, 0.0)

    # Numerically compute the gradient along several randomly chosen dimensions, and
    # compare them with your analytically computed gradient. The numbers should match
    # almost exactly along all dimensions.
    from gradient_check import grad_check_sparse
    f = lambda w: svm_loss_naive(W, X, Y, 0.0)[0]  # ? 错误，函数应该传入小写w
    grad_numerical = grad_check_sparse(f, W, grad, 10)

    # do the gradient check once again with regularization turned on
    # you didn't forget the regularization gradient did you?
    loss, grad = svm_loss_naive(W, X, Y, 5e1)
    f = lambda w: svm_loss_naive(w, X, Y, 5e1)[0]
    grad_numerical = grad_check_sparse(f, W, grad, 10)


def softmax_grad_check(W, X, Y):
    # Complete the implementation of softmax_loss_naive and implement a (naive)
    # version of the gradient that uses nested loops.
    loss, grad = softmax_loss_naive(W, X, Y, 0.0)

    # As we did for the SVM, use numeric gradient checking as a debugging tool.
    # The numeric gradient should be close to the analytic gradient.
    from gradient_check import grad_check_sparse
    f = lambda w: softmax_loss_naive(W, X, Y, 0.0)[0]
    grad_numerical = grad_check_sparse(f, W, grad, 10)

    # similar to SVM case, do another gradient check with regularization
    loss, grad = softmax_loss_naive(W, X, Y, 5e1)
    f = lambda w: softmax_loss_naive(W, X, Y, 5e1)[0]
    grad_numerical = grad_check_sparse(f, W, grad, 10)


class LinearClassifier(object):

    def __init__(self):
        self.W = None

    def train(self, X, y, learning_rate=1e-3, reg=1e-5, num_iters=100,
              batch_size=200, verbose=False):
        """
        Train this linear classifier using stochastic gradient descent.

        Inputs:
        - X: A numpy array of shape (N, D) containing training data; there are N
          training samples each of dimension D.
        - y: A numpy array of shape (N,) containing training labels; y[i] = c
          means that X[i] has label 0 <= c < C for C classes.
        - learning_rate: (float) learning rate for optimization.
        - reg: (float) regularization strength.
        - num_iters: (integer) number of steps to take when optimizing
        - batch_size: (integer) number of training examples to use at each step.
        - verbose: (boolean) If true, print progress during optimization.

        Outputs:
        A list containing the value of the loss function at each training iteration.
        """
        num_train, dim = X.shape
        num_classes = np.max(y) + 1  # assume y takes values 0...K-1 where K is number of classes
        if self.W is None:
            # lazily initialize W
            self.W = 0.001 * np.random.randn(dim, num_classes)

        # Run stochastic gradient descent to optimize W
        loss_history = []
        for it in range(num_iters):
            X_batch = None
            y_batch = None

            #########################################################################
            # Sample batch_size elements from the training data and their           #
            # corresponding labels to use in this round of gradient descent.        #
            # Store the data in X_batch and their corresponding labels in           #
            # y_batch; after sampling X_batch should have shape (batch_size, dim)   #
            # and y_batch should have shape (batch_size,)                           #
            #                                                                       #
            # Hint: Use np.random.choice to generate indices. Sampling with         #
            # replacement is faster than sampling without replacement.              #
            #########################################################################
            # *****START OF YOUR CODE (DO NOT DELETE/MODIFY THIS LINE)*****
            #抽取样本
            indices = np.random.choice(num_train, batch_size, replace=True)
            X_batch = X[indices]
            y_batch = y[indices]

            # perform parameter update
            #########################################################################
            # Update the weights using the gradient and the learning rate.          #
            #########################################################################
            # *****START OF YOUR CODE (DO NOT DELETE/MODIFY THIS LINE)*****
            # 计算损失和梯度
            loss, grad = self.loss(X_batch, y_batch, reg)
            # 更新权重
            self.W -= learning_rate * grad
            # 存储损失
            loss_history.append(loss)
            # *****END OF YOUR CODE (DO NOT DELETE/MODIFY THIS LINE)*****

            if verbose and it % 100 == 0:
                print('iteration %d / %d: loss %f' % (it, num_iters, loss))

        return loss_history

    def predict(self, X):
        """
        Use the trained weights of this linear classifier to predict labels for
        data points.

        Inputs:
        - X: A numpy array of shape (N, D) containing training data; there are N
          training samples each of dimension D.

        Returns:
        - y_pred: Predicted labels for the data in X. y_pred is a 1-dimensional
          array of length N, and each element is an integer giving the predicted
          class.
        """
        y_pred = np.zeros(X.shape[0])
        ###########################################################################
        # Implement this method. Store the predicted labels in y_pred.            #
        ###########################################################################
        # *****START OF YOUR CODE (DO NOT DELETE/MODIFY THIS LINE)*****
        # 计算每个样本的分数
        scores = X.dot(self.W)
        # 对于每个样本，选择具有最高分数的类别作为预测类别
        y_pred = np.argmax(scores, axis=1)
        # *****END OF YOUR CODE (DO NOT DELETE/MODIFY THIS LINE)*****
        return y_pred

    def eval(self, Y, y_pred):
        acc = np.mean(Y == y_pred)
        print('training accuracy: %f' % (np.mean(Y == y_pred),))
        return acc

    def loss(self, X_batch, y_batch, reg):
        """
        Compute the loss function and its derivative.
        Subclasses will override this.

        Inputs:
        - X_batch: A numpy array of shape (N, D) containing a minibatch of N
          data points; each point has dimension D.
        - y_batch: A numpy array of shape (N,) containing labels for the minibatch.
        - reg: (float) regularization strength.

        Returns: A tuple containing:
        - loss as a single float
        - gradient with respect to self.W; an array of the same shape as W
        """
        pass


class LinearSVM(LinearClassifier):
    """ A subclass that uses the Multiclass SVM loss function """

    def loss(self, X_batch, y_batch, reg):
        return svm_loss_naive(self.W, X_batch, y_batch, reg)


class Softmax(LinearClassifier):
    """ A subclass that uses the Softmax + Cross-entropy loss function """

    def loss(self, X_batch, y_batch, reg):
        return softmax_loss_naive(self.W, X_batch, y_batch, reg)


def train_a_simple_svm(X, Y):
    svm = LinearSVM()
    tic = time.time()
    loss_hist = svm.train(X, Y, learning_rate=1e-7, reg=2.5e4,
                          num_iters=1500, verbose=True)
    toc = time.time()
    print('That took %fs' % (toc - tic))
    y_train_pred = svm.predict(X)
    print('training accuracy: %f' % (np.mean(Y == y_train_pred),))
    visualize_training(loss_hist)
    return svm


def train_a_simple_softmax(X, Y):
    softmax = Softmax()
    tic = time.time()
    loss_hist = softmax.train(X, Y, learning_rate=1e-7, reg=2.5e4,
                              num_iters=1500, verbose=True)
    toc = time.time()
    print('That took %fs' % (toc - tic))
    y_train_pred = softmax.predict(X)
    print('training accuracy: %f' % (np.mean(Y == y_train_pred),))
    visualize_training(loss_hist)
    return softmax


def train_and_get_best_svm(X_train, y_train, X_val, y_val):
    # Use the validation set to tune hyperparameters (regularization strength and
    # learning rate). You should experiment with different ranges for the learning
    # rates and regularization strengths; if you are careful you should be able to
    # get a classification accuracy of about 0.39 on the validation set.

    # Note: you may see runtime/overflow warnings during hyper-parameter search.
    # This may be caused by extreme values, and is not a bug.

    learning_rates = [1e-7, 1e-6]
    regularization_strengths = [2.5e4, 3e4]

    # results is dictionary mapping tuples of the form
    # (learning_rate, regularization_strength) to tuples of the form
    # (training_accuracy, validation_accuracy). The accuracy is simply the fraction
    # of data points that are correctly classified.
    results = {}
    best_val = -1  # The highest validation accuracy that we have seen so far.
    best_svm = None  # The LinearSVM object that achieved the highest validation rate.
    best_loss_hist = None
    print('start tuning best svm')

    # *****START OF YOUR CODE (DO NOT DELETE/MODIFY THIS LINE)*****
    for lr in learning_rates:
        for reg in regularization_strengths:
            svm = LinearSVM()
            loss_hist = svm.train(X_train, y_train, learning_rate=lr, reg=reg, num_iters=1000)
            # 在训练集和验证集上比较
            y_train_pred = svm.predict(X_train)
            train_accuracy = np.mean(y_train == y_train_pred)
            y_val_pred = svm.predict(X_val)
            val_accuracy=np.mean(y_val==y_val_pred)
            # 将结果存储在字典中
            results[(lr, reg)] = (train_accuracy, val_accuracy)
            # 如果精度更高，更新最佳模型
            if val_accuracy > best_val:
                best_val = val_accuracy
                best_svm = svm
                best_loss_hist = loss_hist

    # *****END OF YOUR CODE (DO NOT DELETE/MODIFY THIS LINE)*****

    # Print out results.
    for lr, reg in sorted(results):
        train_accuracy, val_accuracy = results[(lr, reg)]
        print('lr %e reg %e train accuracy: %f val accuracy: %f' % (
            lr, reg, train_accuracy, val_accuracy))

    print('best validation accuracy achieved during cross-validation: %f' % best_val)
    return best_val, best_svm, best_loss_hist


def train_and_get_best_softmax(X_train, y_train, X_val, y_val):
    learning_rates = [1e-7, 1e-6]
    regularization_strengths = [2.5e4, 3e4]
    results = {}
    best_val = -1  # The highest validation accuracy that we have seen so far.
    best_softmax = None  # The LinearSVM object that achieved the highest validation rate.
    best_loss_hist = None
    print('start tuning best softmax')

    # *****START OF YOUR CODE (DO NOT DELETE/MODIFY THIS LINE)*****
    for lr in learning_rates:
        for reg in regularization_strengths:
            # 创建一个Softmax分类器
            softmax = Softmax()
            loss_hist = softmax.train(X_train, y_train, learning_rate=lr, reg=reg, num_iters=1000)
            # 在训练集和验证集上比较
            y_train_pred = softmax.predict(X_train)
            train_accuracy = np.mean(y_train == y_train_pred)
            y_val_pred = softmax.predict(X_val)
            val_accuracy = np.mean(y_val == y_val_pred)
            # 将结果存储在字典中
            results[(lr, reg)] = (train_accuracy, val_accuracy)
            # 如果精度更高，更新最佳模型
            if val_accuracy > best_val:
                best_val = val_accuracy
                best_softmax = softmax
                best_loss_hist = loss_hist
    # *****END OF YOUR CODE (DO NOT DELETE/MODIFY THIS LINE)*****

    for lr, reg in sorted(results):
        train_accuracy, val_accuracy = results[(lr, reg)]
        print('lr %e reg %e train accuracy: %f val accuracy: %f' % (
            lr, reg, train_accuracy, val_accuracy))
    print('best validation accuracy achieved during cross-validation: %f' % best_val)
    return best_val, best_softmax, best_loss_hist


def visualize_training(loss_hist):
    # A useful debugging strategy is to plot the loss as a function of
    # iteration number:
    plt.plot(loss_hist)
    plt.xlabel('Iteration number')
    plt.ylabel('Loss value')
    plt.show()


def visualize_learned_weights(classifier, classes):
    # Visualize the learned weights for each class.
    # Depending on your choice of learning rate and regularization strength, these may
    # or may not be nice to look at.
    w = classifier.W[:-1, :]  # strip out the bias
    w = w.reshape(32, 32, 3, len(classes))
    w_min, w_max = np.min(w), np.max(w)

    for i in range(len(classes)):
        #plt_idx = i * num_classes + y + 1  # 在子图中所占位置的计算
        plt.subplot(1,len(classes), i + 1)
        # plt.subplot(1, 4, i + 1)

        # Rescale the weights to be between 0 and 255
        wimg = 255.0 * (w[:, :, :, i].squeeze() - w_min) / (w_max - w_min)
        plt.imshow(wimg.astype('uint8'))
        plt.axis('off')
        plt.title(classes[i])
    plt.show()

def visualize_predictions(X_test, y_test, model,mean_image):
    y_pred = model.predict(X_test)  # 使用模型进行预测

    num_classes = len(classes)
    samples_per_class = 4

    for i in range(num_classes):
        class_indices = np.where(y_test == i)[0]
        np.random.shuffle(class_indices)
        class_indices = class_indices[:samples_per_class]

        for j, idx in enumerate(class_indices):
            plt.subplot(samples_per_class, num_classes, j * num_classes + i + 1)
            img = X_test[:, :-1][idx].reshape(32, 32, 3)  # 还原图像形状
            img += mean_image.reshape(32, 32, 3)
            img = np.clip(img, 0, 255).astype('uint8')
            plt.imshow(img)
            plt.axis('off')

            if y_pred[idx] == y_test[idx]:
                color = 'green'  # 预测正确的样本使用绿色标记
            else:
                color = 'red'  # 预测错误的样本使用红色标记

            plt.title(f'True: {classes[y_test[idx]]}\nPred: {classes[y_pred[idx]]}', color=color)
            acc = np.mean(y_test == y_pred)
    print('classifying accuracy: %f' % (np.mean(y_test == y_pred),))

    plt.show()

