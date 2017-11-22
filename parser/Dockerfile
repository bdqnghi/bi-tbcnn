FROM yijun/fast
RUN apk add -U --no-cache parallel
RUN apk add -U --no-cache bash
RUN apk add -U --no-cache py2-pip
RUN pip install --upgrade protobuf
ADD . /bi-tbcnn
CMD ["sh", "-c", "/bi-tbcnn/run"]
