from multiprocessing import Pool
import multhreading


def cpu_fun(n):
    print(n)
    return multhreading.wapper_func(n)


if __name__ == '__main__':
    pool = Pool(4)
    pool.map(cpu_fun, range(1000, 1020))