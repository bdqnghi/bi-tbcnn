"""
This script scrapes files from GitHub with specific algorithm purposes, and
labels them by the algorithm

Labels are:
    bubblesort
    mergesort
    quicksort
    linkedlist
    bfs (breadth first search)
    knapsack
"""

import os
import sys
import codecs
import ast
import logging
import pickle
import requests
import requests_cache
import utils

from collections import defaultdict
from constants import CACHE_DIR, REQUESTS_CACHE

# DATA_URLS = {
#     'bubblesort': 'https://api.github.com/search/code?q=filename:bubblesort.py%20language:python',
#     'mergesort': 'https://api.github.com/search/code?q=filename:mergesort.py%20language:python',
#     'quicksort': 'https://api.github.com/search/code?q=filename:quicksort.py%20language:python',
#     'linkedlist': 'https://api.github.com/search/code?q=filename:linkedlist.py%20language:python',
#     'bfs': 'https://api.github.com/search/code?q=filename:bfs.py%20language:python',
#     'knapsack': 'https://api.github.com/search/code?q=filename:knapsack.py%20language:python'

# }


# DATA_URLS = {
#     'bubblesort': 'https://api.github.com/search/code?q=filename:Bubblesort.java%20language:java',
#     'mergesort': 'https://api.github.com/search/code?q=filename:Mergesort.java%20language:java',
#     'quicksort': 'https://api.github.com/search/code?q=filename:Quicksort.java%20language:java',
#     'linkedlist': 'https://api.github.com/search/code?q=filename:Linkedlist.java%20language:java',
#     'bfs': 'https://api.github.com/search/code?q=filename:Bfs.java%20language:java',
#     'knapsack': 'https://api.github.com/search/code?q=filename:Knapsack.java%20language:java'

# }

DATA_URLS = {
    'bubblesort': 'https://api.github.com/search/code?q=filename:Bubblesort.cpp%20language:cpp',
    'mergesort': 'https://api.github.com/search/code?q=filename:Mergesort.cpp%20language:cpp',
    'quicksort': 'https://api.github.com/search/code?q=filename:Quicksort.cpp%20language:cpp',
    'linkedlist': 'https://api.github.com/search/code?q=filename:Linkedlist.cpp%20language:cpp',
    'bfs': 'https://api.github.com/search/code?q=filename:Bfs.cpp%20language:cpp',
    'knapsack': 'https://api.github.com/search/code?q=filename:Knapsack.cpp%20language:cpp'

}



# DATA_URLS = {
#     'selectionsort': 'https://api.github.com/search/code?q=filename:selectionsort.py%20language:python',
#     'heapsort': 'https://api.github.com/search/code?q=filename:heapsort.py%20language:python'
# }
def fetch_page(url, page=0):
    """Fetch a search results page at the given url."""
    req = requests.get(
        url + '&page=' + str(page),
        hooks=utils.request_hooks,
        auth=utils.request_auth_github
    )
    response = req.json()
    count = response['total_count']
    return response['items'], count

def fetch_scripts(url, page_limit=20):
    """Fetch all the scripts at a given url limited to the number of pages."""
    page, count = fetch_page(url, 0)
    num_pages = min((count // 100), page_limit)

    scripts = extract_scripts(page)

    for (page, _), i in ((fetch_page(url, 1), i) for i in range(num_pages)):
        new_scripts = extract_scripts(page)
        scripts.extend(new_scripts)
        print('Parsed', len(new_scripts), 'from page', i)

    return scripts

def extract_scripts(page):
    """Given a search results page, extract the raw scripts."""
    scripts = []
    for result in page:
        repo_name = result['repository']['full_name']
        file_path = result['path']
        script_url = 'https://raw.githubusercontent.com/'+repo_name+'/master/'+file_path
        req = requests.get(script_url)
        scripts.append(req.text)
    return scripts

def build_tree(script):
    """Builds an AST from a script."""
    return ast.parse(script,mode="exec")

def fetch(outfile):
    """The main function for downloading all scripts from github."""
    if not os.path.exists(REQUESTS_CACHE):
        os.makedirs(REQUESTS_CACHE)

    requests_cache.install_cache(REQUESTS_CACHE)

    result = []

    label_counts = defaultdict(int)

    print('Fetching scripts')
    for label, url in DATA_URLS.items():
        print(url)
        scripts = fetch_scripts(url)
        for script in scripts:
            try:
                result.append({
                    'tree': build_tree(script), 'metadata': {'label': label}
                })
                label_counts[label] += 1
            except Exception as err:
                print(err)

    print('Label counts: ', label_counts)

    print('Dumping scripts')
    with open(outfile, 'wb') as file_handler:
        pickle.dump(result, file_handler)


def fetch2(language):
    """The main function for downloading all scripts from github."""
    if not os.path.exists(REQUESTS_CACHE):
        os.makedirs(REQUESTS_CACHE)

    requests_cache.install_cache(REQUESTS_CACHE)

    result = []

    label_counts = defaultdict(int)

    print('Fetching scripts')
    count = 0
    for label, url in DATA_URLS.items():
        print(url)
        scripts = fetch_scripts(url)
        out_folder = "../crawler/data/new_data/" + label + "/" + language + "/"
        if not os.path.exists(out_folder):
            os.makedirs(out_folder)
        print out_folder
        for script in scripts:
            # try:
            #     print script
            #     print build_tree(script)
            # except Exception as err:
            #     print(err)
            out_file = out_folder + "/" + str(count) + "." + language
            print "out file :" + out_file
            with codecs.open(out_file,"w", encoding="utf-8") as f:
                f.write(script)
            count += 1

    # print('Label counts: ', label_counts)

    # print('Dumping scripts')
    # with open(outfile, 'wb') as file_handler:
    #     pickle.dump(result, file_handler)


fetch2("cpp")