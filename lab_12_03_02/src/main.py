import ctypes

lib = ctypes.CDLL("./out/libutils.so")

_fill_array_prime = lib.fill_array_prime
_fill_array_prime.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_size_t)
_fill_array_prime.restype = None

_insert_num_after_even = lib.insert_num_after_even
_insert_num_after_even.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.POINTER(ctypes.c_int), ctypes.c_size_t, ctypes.c_int)
_insert_num_after_even.restype = ctypes.c_size_t

def insert_num_after_even(lst, num):
    src = (ctypes.c_int * len(lst))(*lst)
    dst_size = _insert_num_after_even(src, None, len(src), num)
    dst = (ctypes.c_int * dst_size)(0)
    _insert_num_after_even(src, dst, len(src), num)
    return dst


def fill_array_prime(size):
    dst = (ctypes.c_int * size)(0)
    _fill_array_prime(dst, size)
    return dst

from tkinter import *  
  
  
def clicked_arr():  
    arr = in_arr.get()
    num = in_num.get()
    try:
        arr = [int(x) for x in arr.split()]
        num = int(num)
        res = insert_num_after_even(arr, num)
        lettrs_res = [str(x) for x in res]
        s = " ".join(lettrs_res)
        # print(s)
        res_arr.configure(text=s)
    except Exception:
        res_arr.configure(text="Ошибка ввода!")
          
def clicked_prime():
    size = in_size.get()
    try:
        size = int(size)
        if size <= 30:
            res = fill_array_prime(size)
            lettrs_res = [str(x) for x in res]
            s = " ".join(lettrs_res)
            # print(s)
            res_prime.configure(text=s)
        else:
            res_prime.configure(text="Введите число не большее 30:)")
    except Exception:
        res_prime.configure(text="Ошибка ввода!")

  
window = Tk()  
window.title("Program")  
window.geometry('1000x800')  
prompt = Label(window, text="Введите массив")
prompt.grid(column=0, row=0)  
in_arr = Entry(window,width=60)  
propmt_num = Label(window, text="Введите число для вставки")
in_num = Entry(window,width=20)
in_arr.grid(column=1, row=0)  
propmt_num.grid(column=2, row=0)
in_num.grid(column=3, row = 0)
res_arr = Label(window, text="")
res_arr.grid(column=1, row=1)
btn = Button(window, text="Выполнить вставку!", command=clicked_arr)  
btn.grid(column=0, row=1)
prompt_prime = Label(window, text="Введите размер массива")
prompt_prime.grid(column=0, row=3, pady=10)
in_size = Entry(window,width=10)
in_size.grid(column=0, row=4, pady=0)
btn_prime = Button(window, text="Вывести массив пр. чисел", command=clicked_prime)  
btn_prime.grid(column=0, row=5)
res_prime = Label(window, text="")
res_prime.grid(column=1, row=4)
window.mainloop()

# print(*fill_array_prime(100))
# print(*insert_num_after_even([int(x) for x in range(20)], 5))