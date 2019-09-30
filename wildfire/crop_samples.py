# coding: utf-8
import numpy as np


x = np.random.randint(0, 100, 120).reshape((8, 15))


def crop_sub_tensor(input_tenser: np.ndarray, position_2d: tuple, filter_shape: tuple):
    """对某个输入的矩阵(tensor)筛选出某个位置指定周围大小的区域, 边边缘的点通过边缘进行填充.
    :param input_tenser: array, 一个任意大小的二维矩阵.
    :param position_2d: tuple, 裁剪点的位置索引, 必须在输入矩阵index范围内.
    :param filter_shape: tuple, 裁剪周围的大小, 每个维度裁剪的范围.
    :return array, 裁剪后的大小, 2*filter_shape+1
    """
    m, n = input_tenser.shape
    filter_m, filter_n = filter_shape
    if m < filter_m or n < filter_n:
        raise ValueError("The input tensor shape don't match filter shape!")
    if position_2d[0] > m-1 or position_2d[1] > n-1:
        raise ValueError("Giving position out of input tensor shape!")

    input_tenser = np.pad(input_tenser, ((filter_m, filter_m), (filter_n, filter_n)),
                          mode='edge')
    new_position_x = position_2d[0] + filter_m
    new_position_y = position_2d[1] + filter_n
    return input_tenser[new_position_x-filter_m: new_position_x+filter_m+1,
                        new_position_y-filter_n: new_position_y+filter_n+1]
                        
if __name__ == "__main__":
    print(x)
    y = crop_sub_tensor(x, (7, 14), (2, 3))
    print(y)