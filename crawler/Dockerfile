FROM gcr.io/tensorflow/tensorflow
RUN apt-get update
RUN apt-get install time
RUN pip install tqdm
RUN pip install requests
RUN pip install requests_cache
ADD . /bi-tbcnn
CMD ["sh", "-c", "/bi-tbcnn/run"]
