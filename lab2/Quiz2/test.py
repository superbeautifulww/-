from layers import *
from data_loader import *
from two_layer_net import TwoLayerFCNet
from gradient_check import eval_numerical_gradient, eval_numerical_gradient_array
from vis_utils import visualize_grid
import matplotlib.pyplot as plt
import csv

# Test the affine_forward function

num_inputs = 2
input_shape = (4, 5, 6)
output_dim = 3

input_size = num_inputs * np.prod(input_shape)
weight_size = output_dim * np.prod(input_shape)

x = np.linspace(-0.1, 0.5, num=input_size).reshape(num_inputs, *input_shape)
w = np.linspace(-0.2, 0.3, num=weight_size).reshape(np.prod(input_shape), output_dim)
b = np.linspace(-0.3, 0.1, num=output_dim)

out, _ = affine_forward(x, w, b)
correct_out = np.array([[ 1.49834967,  1.70660132,  1.91485297],
                        [ 3.25553199,  3.5141327,   3.77273342]])

# Compare your output with ours. The error should be around e-9 or less.
print('Testing affine_forward function:')
print('difference: ', rel_error(out, correct_out))

# Test the affine_backward function
np.random.seed(231)
x = np.random.randn(10, 2, 3)
w = np.random.randn(6, 5)
b = np.random.randn(5)
dout = np.random.randn(10, 5)

dx_num = eval_numerical_gradient_array(lambda x: affine_forward(x, w, b)[0], x, dout)
dw_num = eval_numerical_gradient_array(lambda w: affine_forward(x, w, b)[0], w, dout)
db_num = eval_numerical_gradient_array(lambda b: affine_forward(x, w, b)[0], b, dout)

_, cache = affine_forward(x, w, b)
dx, dw, db = affine_backward(dout, cache)

# The error should be around e-10 or less
print('Testing affine_backward function:')
print('dx error: ', rel_error(dx_num, dx))
print('dw error: ', rel_error(dw_num, dw))
print('db error: ', rel_error(db_num, db))

# Test the relu_forward function

# Test the leaky_relu_forward function

x = np.linspace(-0.7, 0.8, num=12).reshape(3, 4)

out, _ = leaky_relu_forward(x)
correct_out = np.array([[-0.007,-0.00563636, -0.00427273, -0.00290909],
                        [-0.00154545, -0.00018182,  0.11818182,  0.25454545],
                        [ 0.39090909,  0.52727273,  0.66363636,  0.8]])

# Compare your output with ours. The error should be on the order of e-6
print('Testing leaky_relu_forward function:')
print('difference: ', rel_error(out, correct_out))

# Test the relu_backward function

np.random.seed(231)
x = np.random.randn(10, 10)
dout = np.random.randn(*x.shape)

dx_num = eval_numerical_gradient_array(lambda x: relu_forward(x)[0], x, dout)

_, cache = relu_forward(x)
dx = relu_backward(dout, cache)

# The error should be on the order of e-12
print('Testing relu_backward function:')
print('dx error: ', rel_error(dx_num, dx))

# Test the leaky_relu_forward function

x = np.linspace(-0.7, 0.8, num=12).reshape(3, 4)

out, _ = leaky_relu_forward(x)
correct_out = np.array([[-0.007, -0.00563636, -0.00427273, -0.00290909],
                        [-0.00154545, -0.00018182, 0.11818182, 0.25454545],
                        [0.39090909, 0.52727273, 0.66363636, 0.8]])

# Compare your output with ours. The error should be on the order of e-6
print('Testing leaky_relu_forward function:')
print('difference: ', rel_error(out, correct_out))

# Test the leaky_relu_backward function
np.random.seed(231)
x = np.random.randn(10, 10)
dout = np.random.randn(*x.shape)

dx_num = eval_numerical_gradient_array(lambda x: leaky_relu_forward(x)[0], x, dout)

_, cache = leaky_relu_forward(x)
dx = leaky_relu_backward(dout, cache)

# The error should be on the order of e-12
print('Testing leaky_relu_backward function:')
print('dx error: ', rel_error(dx_num, dx))

# Test the sigmoid_forward function

x = np.linspace(-0.5, 0.5, num=12).reshape(3, 4)

out, _ = sigmoid_forward(x)
correct_out = np.array([[0.37754067, 0.39913012, 0.42111892, 0.44342513],
                        [0.46596182, 0.48863832, 0.51136168, 0.53403818],
                        [0.55657487, 0.57888108, 0.60086988, 0.62245933]])

# Compare your output with ours. The error should be on the order of e-8
print('Testing relu_forward function:')
print('difference: ', rel_error(out, correct_out))

# Test the sigmoid_backward function
np.random.seed(231)
x = np.random.randn(10, 10)
dout = np.random.randn(*x.shape)

dx_num = eval_numerical_gradient_array(lambda x: sigmoid_forward(x)[0], x, dout)

_, cache = sigmoid_forward(x)
dx = sigmoid_backward(dout, _)

# The error should be on the order of e-12
print('Testing relu_backward function:')
print('dx error: ', rel_error(dx_num, dx))

np.random.seed(231)
num_classes, num_inputs = 10, 50
x = 0.001 * np.random.randn(num_inputs, num_classes)
y = np.random.randint(num_classes, size=num_inputs)

dx_num = eval_numerical_gradient(lambda x: svm_loss(x, y)[0], x, verbose=False)

loss, dx = svm_loss(x, y)

# Test svm_loss function. Loss should be around 9 and dx error should be around the order of e-9
print('Testing svm_loss:')
print('loss: ', loss)
print('dx error: ', rel_error(dx_num, dx))

dx_num = eval_numerical_gradient(lambda x: softmax_loss(x, y)[0], x, verbose=False)
loss, dx = softmax_loss(x, y)

# Test softmax_loss function. Loss should be close to 2.3 and dx error should be around e-8
print('Testing softmax_loss:')
print('loss: ', loss)
print('dx error: ', rel_error(dx_num, dx))


np.random.seed(231)
N, D, H, C = 3, 5, 50, 7
X = np.random.randn(N, D)
y = np.random.randint(C, size=N)

std = 1e-3
model = TwoLayerFCNet(input_size=D, hidden_size=H, output_size=C, std=std)

print('Testing initialization ... ')
W1_std = abs(model.params['W1'].std() - std)
b1 = model.params['b1']
W2_std = abs(model.params['W2'].std() - std)
b2 = model.params['b2']
assert W1_std < std, 'First layer weights do not seem right'
assert np.all(b1 == 0), 'First layer biases do not seem right'
assert W2_std < std, 'Second layer weights do not seem right'
assert np.all(b2 == 0), 'Second layer biases do not seem right'

print('Testing test-time forward pass ... ')

model.params['W1'] = np.linspace(-0.7, 0.3, num=D * H).reshape(D, H)
model.params['b1'] = np.linspace(-0.1, 0.9, num=H)
model.params['W2'] = np.linspace(-0.3, 0.4, num=H * C).reshape(H, C)
model.params['b2'] = np.linspace(-0.9, 0.1, num=C)

X = np.linspace(-5.5, 4.5, num=N * D).reshape(D, N).T
scores = model.loss(X)

print('your scores are:\n', scores)
correct_scores = np.asarray(
    [[11.53165108, 12.2917344, 13.05181771, 13.81190102, 14.57198434, 15.33206765, 16.09215096],
     [12.05769098, 12.74614105, 13.43459113, 14.1230412, 14.81149128, 15.49994135, 16.18839143],
     [12.58373087, 13.20054771, 13.81736455, 14.43418138, 15.05099822, 15.66781506, 16.2846319]])
print('correct scores are:\n', correct_scores)
scores_diff = np.abs(scores - correct_scores).sum()
print('Difference between your scores and correct scores:', scores_diff)

print('Testing training loss')
y = np.asarray([0, 5, 1])
loss, grads = model.loss(X, y)
print('training loss (no regularization): ', loss)
correct_loss = 3.4702243556
diff = abs(loss - correct_loss)
print('Difference between your loss and correct loss:', diff)

reg = 1.0
loss, grads = model.loss(X, y, reg)
print('training loss (L2 regularization): ', loss)
correct_loss = 26.5948426952
diff = abs(loss - correct_loss)
print('Difference between your loss and correct loss:', diff)

# Errors should be around e-7 or less
for reg in [0.0, 0.7]:
    print('Running numeric gradient check with reg = ', reg)
    # model.reg = reg
    loss, grads = model.loss(X, y, reg)

    for name in sorted(grads):
        f = lambda _: model.loss(X, y, reg)[0]
        grad_num = eval_numerical_gradient(f, model.params[name], verbose=False)
        print('%s relative error: %.2e' % (name, rel_error(grad_num, grads[name])))

# Train a mini network

net = TwoLayerFCNet(input_size=D, hidden_size=H, output_size=C, std=std)
stats = net.train(X, y, X, y,
                  learning_rate=1e-1, reg=5e-6,
                  num_iters=100, verbose=False)

print('Final training loss: ', stats['loss_history'][-1])

# plot the loss history
plt.plot(stats['loss_history'])
plt.xlabel('iteration')
plt.ylabel('training loss')
plt.title('Training Loss history')
plt.show()



# 加载数据集
root = 'D:/CVML/RS32/all'
X, Y = load_data(root)
num_image = 12000
X = X[:num_image]
Y = Y[:num_image]

# 数据集划分
num_train = int(len(X) * 0.6)
num_val = int(len(X) * 0.1)
num_test = int(len(X) * 0.3)
Xtrain = X[:num_train]
Ytrain = Y[:num_train]
Xval = X[num_train:num_train + num_val]
Yval = Y[num_train:num_train + num_val]
Xtest = X[num_train + num_val:]
Ytest = Y[num_train + num_val:]

# 数据显示

plt.rcParams['figure.figsize'] = (20.0, 20.0)  # set default size of plots
plt.rcParams.update({'font.size': 8})
plt.rcParams['image.interpolation'] = 'nearest'
plt.rcParams['image.cmap'] = 'gray'

#visualize_samples(classes, Xtrain, Ytrain)

# 数据预处理
Xtrain, Xval, Xtest = data_processing(Xtrain, Xval, Xtest)
print('Xtrain.shape:', Xtrain.shape)
print('Ytrain.shape:', Ytrain.shape)
print('Xval.shape:', Xval.shape)
print('Yval.shape:', Yval.shape)
print('Xtest.shape:', Xtest.shape)
print('Xtest.shape:', Ytest.shape)

# 训练全连接网络
# Train a network
input_size = 3 * 32 * 32
hidden_size = 100
output_size = 19
model = TwoLayerFCNet(input_size, hidden_size=16384, output_size=10, std=1e-3)

# Train the network
start_time = time.time()
stats = model.train(Xtrain, Ytrain, Xval, Yval,
                    num_iters=1000, batch_size=200,
                    learning_rate=1e-3, learning_rate_decay=0.95,
                    reg=0.5, verbose=True)

# Predict on the validation set
val_acc = (model.predict(Xval) == Yval).mean()
print('Validation accuracy:', val_acc)
print('consuming:', time.time() - start_time)
test_acc =(model.predict(Xtest)==Ytest).mean()
print('Test accuracy:',test_acc)



'''
# 调试训练
print("调试训练")
# Plot the loss function and train /validation accuracies
plt.subplot(2, 1, 1)
plt.plot(stats['loss_history'])
plt.title('Loss history')
plt.xlabel('Iteration')
plt.ylabel('Loss')

plt.subplot(2, 1, 2)
plt.plot(stats['train_acc_history'], label='train')
plt.plot(stats['val_acc_history'], label='val')
plt.title('Classification accuracy history')
plt.xlabel('Epoch')
plt.ylabel('Classification accuracy')
plt.legend()
plt.tight_layout()  # avoid overlapplt.show()
plt.show()

# Visualize the weights of the network
def show_net_weights(net):
    W1 = net.params['W1']
    W1 = W1.reshape(32, 32, 3, -1).transpose(3, 0, 1, 2)
    plt.imshow(visualize_grid(W1, padding=3).astype('uint8'))
    plt.gca().axis('off')
    plt.show()

show_net_weights(model)

best_model = None
best_val_acc = -1

learning_rates = [1e-3,1e-4,1e-5]
num_iters = [1000]
regs = [0.75]


for learning_rate in learning_rates:
    for num_iter in num_iters:
        for reg in regs:
            model = TwoLayerFCNet(input_size, hidden_size, output_size, std=1e-3)
            model.train(Xtrain, Ytrain, Xval, Yval,
                        num_iters=num_iter, batch_size=200,
                        learning_rate=learning_rate, learning_rate_decay=0.95,
                        reg=reg, verbose=True)

            val_acc = (model.predict(Xval) == Yval).mean()
            if val_acc > best_val_acc:
                best_val_acc = val_acc
                best_model = model
                best_reg = reg
                best_learning_rate=learning_rate
                best_num_iters = num_iters
                print()

print('best_val_acc:', best_val_acc)
print('best_learning_rate:', best_learning_rate)
print('best_reg:', best_reg)
print('num_iters:', best_num_iters)
test_acc =(best_model.predict(Xtest)==Ytest).mean()
print('Test accuracy:',test_acc)
show_net_weights(best_model)

'''


