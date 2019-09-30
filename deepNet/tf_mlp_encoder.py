import tensorflow  as tf 
from tensorflow.contrib.layers import fully_connected
from tensorflow.examples.tutorials.mnist import input_data

"""
"""

n_inputs = 28 * 28  # for mnist data
n_hidden1 = 300
n_hidden2 = 150
n_hidden3 = 300
n_outputs = n_inputs

learning_rate = 0.001  # 定义梯度优化学习率参数
l2_reg = 0.01

# 开始构建网络模型: 基于mlp的自编码模型
x = tf.placeholder(tf.float32, shape=(None, n_inputs), name="input_tensor")
with tf.contrib.framework.arg_scope([fully_connected], 
                                    activation_fn=tf.nn.elu, 
                                    weights_initializer=tf.contrib.layers.variance_scaling_initializer(),
                                    weights_regularizer=tf.contrib.layers.l2_regularizer(l2_reg)):
    hidden1 = fully_connected(x, n_hidden1)
    hidden2 = fully_connected(hidden1, n_hidden2)
    hidden3 = fully_connected(hidden2, n_hidden3)
    outputs = fully_connected(hidden3, n_outputs, activation_fn=None)

reconstruction_loss = tf.reduce_mean(tf.square(outputs - x))  # loss function MSE
reg_losses = tf.get_collection(tf.compat.v1.GraphKeys.REGULARIZATION_LOSSES)
loss = tf.add_n([reconstruction_loss] + reg_losses)

optimizer = tf.train.AdamOptimizer(learning_rate)
train_op = optimizer.minimize(loss)
init = tf.global_variables_initializer()

# 开始构建训练的session过程
n_epochs = 5
batch_size = 150

with tf.Session() as sess:
    sess.run(init)  # 对所有的权重变量进行初始化
    mnist = input_data.read_data_sets("/opt/workspace/project/deep-st-nn/data/MNIST_DATA", one_hot=True)
    for epoch in range(n_epochs):
        n_batches = mnist.train.num_examples // batch_size
        for iteration in range(n_batches):
            x_batch, y_batch = mnist.train.next_batch(batch_size)
            sess.run(train_op, feed_dict={x: x_batch})
            if (iteration + 1) % 20 == 0:
                _loss = sess.run(loss, feed_dict={x: x_batch})
                print("The epoch-{:0>2}, iteration-{:0>3}, loss:{}".format(epoch, iteration+1, _loss))