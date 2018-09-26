FROM yijun/fast
# comment out the following two lines to reset proxy servers
ENV http_proxy http://wwwcache.open.ac.uk:80
ENV https_proxy http://wwwcache.open.ac.uk:80
RUN apk add -U --no-cache parallel
RUN apk add -U python2
RUN rm /usr/bin/python
RUN ln -s /usr/bin/python2 /usr/bin/python
RUN apk add -U py-protobuf
RUN apk add -U py2-pip
RUN pip install --upgrade pip
RUN pip install tqdm
RUN pip install requests
RUN pip install requests_cache
RUN pip install network
