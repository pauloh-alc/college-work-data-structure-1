import numpy as np

def generate_random_numbers_in_file(start, end, size):
    my_list = np.random.randint(start, end, size);

    with open('um_bilhao.txt', 'w+') as file:
        for i in my_list:
            file.write(f'{i}\n')

if __name__ == '__main__':
    generate_random_numbers_in_file(start=0, end=2000000, size=1000000000)
