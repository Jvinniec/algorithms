
import os,sys
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../')

import algorithms.sort.tests.test as test_sort


def run_tests():
    """ Run all Python tests
    """
    tests = [test_sort]

    for test in tests:
        test.run_tests()


if __name__ == '__main__':
    run_tests()