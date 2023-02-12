import subprocess
from multiprocessing import Pool
import os
import optuna
from random import sample
from tqdm import tqdm

using_testcase_num = 200
total_testcase_num = 10000
n_trials = 400

def f(args):
    i, a, b = args
    cmd = "problem.exe {} {} in/{:04}.txt".format(a, b, i)
    res = subprocess.run([cmd], universal_newlines=True, shell=True, stdout=subprocess.PIPE)
    return float(res.stdout)

def wrapper(args):
    mean = 0
    using_testcases = sample(list(range(total_testcase_num)), using_testcase_num)
    with Pool() as pool:
        mean = sum(pool.map(f, [[i] + args for i in using_testcases]))
    mean /= using_testcase_num
    return mean

def objective(trial):
    a = trial.suggest_loguniform("a", 1e-8, 1e8)
    b = trial.suggest_loguniform("b", 1e-8, 1e8)
    score = wrapper([a, b])
    print("a: %1.3f, b: %1.3f, score %f" % (a, b, score))
    return score