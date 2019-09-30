#!/opt/anaconda3/bin/python3
import tensorflow as tf
from sklearn import datasets
from sklearn.model_selection import train_test_split
from tensorflow.contrib.layers import fully_connected

"""对自编码器的理解，通过编码器和解码器实现输入和输出的编码和解码, 对整个过程进行简要的实现, 帮助理解本示例中未使用激活函数, 
且使用的loss函数也是非常简单的MSE
实现了PCA的降维过程:
    输入: n_samples, n_dim
    隐藏层: n_hidden = 2
"""

n_inputs = 4
n_hidden = 2
n_output = n_inputs
learning_rate = 0.01

x = tf.placeholder(tf.float32, shape=(None, n_inputs), name="input_x")
hidden = fully_connected(x, n_hidden, activation_fn=None)
output = fully_connected(hidden, n_output, activation_fn=None)

reconstruction_loss = tf.reduce_mean(tf.square(output-x))  # loss function MSE

optimizer = tf.train.AdamOptimizer(learning_rate)
train_operate = optimizer.minimize(reconstruction_loss)

init = tf.global_variables_initializer()
input_x_array, _ = datasets.load_iris(return_X_y=True)
coding = hidden

train_x, tests_x = train_test_split(input_x_array, train_size=0.7)
with tf.Session() as session:
    session.run(init)  # 允许变量初始化
    for iter_n in range(1000):
        train_operate.run(feed_dict={x: train_x})  # no labels, this net don't need target variable
        if (iter_n+1) % 10 == 0:
            _loss = session.run(reconstruction_loss, feed_dict={x: input_x_array})
            print("The auto encoding net loss: %f." % _loss)

    coding_test_x = session.run(output, feed_dict={x: tests_x})
    for src_test_x, pre_test_x in zip(tests_x, coding_test_x):
        print(src_test_x, pre_test_x)