FROM yijun/fast
RUN apk add -U --no-cache parallel
RUN echo will cite | parallel --citation
RUN apk add -U --no-cache bash
RUN apk add -U --no-cache py2-pip
RUN pip install --upgrade protobuf
