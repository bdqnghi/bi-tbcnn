FROM yijun/fast
RUN apk add -U --no-cache parallel
RUN apk add -U python2
RUN rm /usr/bin/python
RUN ln -s /usr/bin/python2 /usr/bin/python
RUN apk add -U py-protobuf
ADD . /bi-tbcnn
CMD ["sh", "-c", "/bi-tbcnn/run"]
