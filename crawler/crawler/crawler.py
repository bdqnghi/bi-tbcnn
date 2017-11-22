"""
This script scrapes files from GitHub with specific algorithm purposes, and
labels them by the algorithm

Labels are stored in the file 'algorithm.name',
languages and file extensions are stored in the file 'language.name':
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

def fetch():
    """The main function for downloading all scripts from github."""
    if not os.path.exists(REQUESTS_CACHE):
        os.makedirs(REQUESTS_CACHE)

    requests_cache.install_cache(REQUESTS_CACHE)

    result = []

    label_counts = defaultdict(int)

    print('Fetching scripts')
    algorithms = [line.rstrip('\n') for line in open('/input/algorithm.name')]
    languages = [line.rstrip('\n') for line in open('/input/language.name')]
    for line in languages:
       lang = line.split()
       language = lang[0]	
       ext = lang[1]	
       count = 0
       for algorithm in algorithms:
	url = 'https://api.github.com/search/code?q=filename:' + algorithm + ext + '%20language:' + language
        print(url)
        scripts = fetch_scripts(url)
        out_folder = "/code/" + algorithm + "/" + language
        if not os.path.exists(out_folder):
            os.makedirs(out_folder)
        print out_folder
        for script in scripts:
            out_file = out_folder + "/" + str(count) + "." + language
            print "out file :" + out_file
            with codecs.open(out_file,"w", encoding="utf-8") as f:
                f.write(script)
            count += 1
fetch()
