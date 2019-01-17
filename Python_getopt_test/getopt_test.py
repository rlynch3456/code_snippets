# getopt_test.py
#
# Program to test using getopt for parsing command line arguments

import sys
import getopt

def get_start_and_end_dates():
    start_date = None
    end_date = None

    argv = sys.argv[1:]
    #print(argv)
    
    try:
        opts, args = getopt.getopt(argv, "s:e:h", ["start_date=", "end_date=", "help"])
    except getopt.GetoptError as err:
        print(err)
        opts = []
        sys.exit()

    for opt, arg in opts:
        if opt in ['-s', '--start_date']:
            start_date = arg
        elif opt in ['-e', '--end_date']:
            end_date = arg
        elif opt in ['-h', '--help']:
            print("got to help")
            sys.exit()

    print('start_date: {}'.format(start_date))
    print('end_date: {}'.format(end_date))

get_start_and_end_dates()